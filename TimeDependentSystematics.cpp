//c++
#include <iostream>
#include <cmath>
//root

#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TMath.h>
#include <TLine.h>
#include <TVector3.h>
#include <TPaveText.h>
#include <TString.h>
#include <TFile.h>
#include <TObject.h>
#include <TTree.h>
#include <TLegend.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TText.h>
#include <TLine.h>
//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include <RooFitResult.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooGaussian.h>
#include <RooChebychev.h>
#include <RooPolynomial.h>
#include <RooArgusBG.h>
#include <RooAddPdf.h>
#include <RooPlot.h>
#include <RooHist.h>
#include <RooDataHist.h>
#include <RooExponential.h>
#include <RooBinning.h>
#include <RooDstD0BG.h>
#include <RooNLLVar.h>
#include <RooWorkspace.h>
// local
#include "massFit.h"
#include "TimeIntegratedSystematicsClass.h"
#include "PlottingTools.h"
using namespace std;
using namespace PlottingTools;

int main(int argc, char* const argv[]){
  cout<<"Code for doing Time Dependent Systematics"<<endl;
  if(argc<3){
    cout<<"++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"Need a rootfile with time dependent things!"<<endl;
    cout<<"and the fit model!!!"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    return 0;
  }
  TFile *f1 =TFile::Open(argv[1]);
  TFile *f2 = TFile::Open(argv[2]);
  f2->ls();
  TString channelFromFile = argv[2];
  channelFromFile.ReplaceAll("SavedFits","");
  channelFromFile.ReplaceAll("fitModel.root","");
  channelFromFile.ReplaceAll("/","");
  channelFromFile.ReplaceAll("j3g","");
  channelFromFile.ReplaceAll("_","");
  channelFromFile+="w";
  cout<<"channel from file = "<<channelFromFile<<endl;  
  RooWorkspace * w = (RooWorkspace*)f2->Get(channelFromFile);

  //get the bins.
  std::vector<TH1D*>pos_bins,neg_bins;
  for(int i=0;i<5;++i){
    pos_bins.push_back((TH1D*)f1->Get(Form("RS_dst_mass_td0_pos_bin%d",i+1)));
    pos_bins[i]->Sumw2();
    neg_bins.push_back((TH1D*)f1->Get(Form("RS_dst_mass_td0_neg_bin%d",i+1)));
    neg_bins[i]->Sumw2();
  }
  for(int i=0; i<5;++i){
    pos_bins[i]->Add((TH1D*)f1->Get(Form("RS_ss_dst_mass_td0_pos_bin%d",i+1)),-1);
    neg_bins[i]->Add((TH1D*)f1->Get(Form("RS_ss_dst_mass_td0_neg_bin%d",i+1)),-1);
  }
  //now fit each one.
  massFit* theFitspos;
  massFit* theFitsneg;
  double the_sig_pos[5],the_sig_pos_err[5];
  double the_sig_neg[5],the_sig_neg_err[5];

  for(int i=0;i<5;++i){
    theFitspos = new massFit(Form("RS_dst_mass_pos_bin%d",i+1),"j3g",w);
    theFitspos->setData(pos_bins[i]);
    //theFitspos->FloatMeanWidth();
    theFitspos->fit();
    theFitspos->savePlots(true,Form("RS_dst_mass_pos_bin%d",i+1));
    the_sig_pos[i]=theFitspos->getNsig();
    the_sig_pos_err[i]=theFitspos->getNsigErr();
    theFitspos->Reset();
  }

  
  for(int i=0;i<5;++i){
    theFitsneg = new massFit(Form("RS_dst_mass_neg_bin%d",i+1),"j3g",w);
    theFitsneg->setData(neg_bins[i]);
    //theFitsneg->FloatMeanWidth();
    theFitsneg->fit();
    theFitsneg->savePlots(true,Form("RS_dst_mass_neg_bin%d",i+1));
    the_sig_neg[i]=theFitsneg->getNsig();
    the_sig_neg_err[i]=theFitsneg->getNsigErr();
    theFitsneg->Reset();
  }

  double binVal[5],binValErr[5];
  for(int i=0; i<5;++i){
    binVal[i]=the_sig_neg[i]/the_sig_pos[i];
    binValErr[i]=TMath::Sqrt((binVal[i]*binVal[i])*(TMath::Power(the_sig_pos_err[i]/the_sig_pos[i],2)+TMath::Power(the_sig_neg_err[i]/the_sig_neg[i],2)));
  }
  //now make a tgraph out of it and we're done!
  TH1D* the_td_distr  = (TH1D*)f1->Get("RS_dt_d0_decay_time_distr");
  TH1D* the_td_distr_ss  = (TH1D*)f1->Get("RS_ss_dt_d0_decay_time_distr");
  the_td_distr->Sumw2();
  the_td_distr_ss->Sumw2();
  the_td_distr->Add(the_td_distr_ss,-1);
  int bins_td []= {46,53,56,60,66,the_td_distr->GetNbinsX()};
  double mean_td_pos[5];
  double xLow[5],xHi[5];
  for(int i=0;i<5;++i){
    the_td_distr->GetXaxis()->SetRange(bins_td[i],bins_td[i+1]);
    mean_td_pos[i] = the_td_distr->GetMean();
    the_td_distr->GetXaxis()->SetRange();
    xLow[i]=mean_td_pos[i] - the_td_distr->GetBinCenter(bins_td[i]);
    xHi[i]=the_td_distr->GetBinCenter(bins_td[i+1])-mean_td_pos[i];
  }
  TGraphAsymmErrors *thePlot = new TGraphAsymmErrors(5,mean_td_pos,binVal,xLow,xHi,binValErr,binValErr);
  thePlot->SetMarkerSize(1.5);
  thePlot->SetMarkerColor(kBlack);
  thePlot->SetLineColor(kBlack);
  thePlot->SetTitle(";D^{0}t/#tau;N(D*^{-})/N(D*^{+})");
  TFile *fout = new TFile("SavedFits/TimeDependentSystematics/rs_over_rs_ratio.root","RECREATE");
  fout->cd();
  thePlot->Write();
  fout->Close();
  f1->Close();
  f2->Close();
  
  TCanvas* cc=new TCanvas();
  thePlot->Draw("ap");
  cc->SaveAs("SavedFits/TimeDependentSystematics/rs_d0_over_d0bar_graph.pdf");
  return 0;
}