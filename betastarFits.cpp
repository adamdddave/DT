//external
#include "betastar_plot.h"
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
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TText.h>

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
//#include "PlottingTools.h"
using namespace std;
 // Include files 


int main(int argc, char* const argv[]){
  cout<<"Testing Mass Fit on External Data"<<endl;
  bool hasWorkspace=  false;
  if(argc<4){
    cout<<"*************************************"<<endl;
    cout<<"Expecting"<<endl;
    cout<<" [1] Signal File"<<endl;
    cout<<" [2] Background File"<<endl;
    cout<<" [3] the workspace with the fit model"<<endl;
    cout<<"Note that the functionality has changed!"<<endl;
    cout<<"*************************************"<<endl;
    return 0;
  }
  if(argc==4){
    cout<<"argv[1]="<<argv[1]<<", argv[2] = "<<argv[2]<<", argv[3] = "<<argv[3]<<endl;
    hasWorkspace = true;
  }
  if(!hasWorkspace){
    cout<<"need a workspace for the fits"<<endl;
    return 0;
  }
  bool isWS = false;
  TString fitName = argv[1];
  TString nameForFit = "rs";
  //make it lower case just to make our lives easier
  fitName.ToLower();
  if(fitName.Contains("ws")){
    isWS = true;
    cout<<"using WS sample"<<endl;
    
    nameForFit = "ws";
    cout<<"nameForFit = "<<nameForFit<<endl; 
  }
  if(isWS){ cout<<"make the compiler shut up"<<endl;}
  //fitName.ToUpper();
  TFile *f1 = TFile::Open(argv[1]);
  //f1->ls();
  TFile *f2 = TFile::Open(argv[2]);
  //f2->ls();
  TFile *f3 = TFile::Open(argv[3]);
  TString channelFromFile = argv[3];
  channelFromFile.ReplaceAll("SavedFits","");
  channelFromFile.ReplaceAll("fitModel.root","");
  channelFromFile.ReplaceAll("/","");
  channelFromFile.ReplaceAll("j3g","");
  channelFromFile.ReplaceAll("_","");
  channelFromFile+="w";
  cout<<"channel from file = "<<channelFromFile<<endl;
  nameForFit.ToUpper();
  betastar_plot b(f1,f2,nameForFit);
  
  
  RooWorkspace * w = (RooWorkspace*)f3->Get(channelFromFile);
  b.set_local_workspace(w);
  
  b.DrawPlots();
  //if(isWS){
  //b.FitWSDoubleMisID();
  b.FitWSDoubleMisIDLiang();
  //b.FitWSDoubleMisIDTimeDependence();
  //double check this by fitting the things.
  
  std::vector<TH1*>lo_hists,lo_hists_bkg;
  std::vector<TH1*>hi_hists,hi_hists_bkg;
  //double sigYield[6];
  //double sigYieldErr[6];
  lo_hists.push_back(b.hmkpisb_cut_range_lo_1);
  lo_hists.push_back(b.hmkpisb_cut_range_lo_2);
  lo_hists.push_back(b.hmkpisb_cut_range_lo_3);
  lo_hists.push_back(b.hmkpisb_cut_range_lo_4);
  lo_hists.push_back(b.hmkpisb_cut_range_lo_5);
  lo_hists.push_back(b.hmkpisb_cut_range_lo_6);

  hi_hists.push_back(b.hmkpisb_cut_range_hi_1);
  hi_hists.push_back(b.hmkpisb_cut_range_hi_2);
  hi_hists.push_back(b.hmkpisb_cut_range_hi_3);
  hi_hists.push_back(b.hmkpisb_cut_range_hi_4);
  hi_hists.push_back(b.hmkpisb_cut_range_hi_5);
  hi_hists.push_back(b.hmkpisb_cut_range_hi_6);
  double lo_sig_vals[5];
  double lo_sig_errs[5];
  double hi_sig_vals[5];
  double hi_sig_errs[5];
  std::vector<double>tmp;
  TCanvas* cc = new TCanvas();
  for(int i=0; i<5;++i){
    lo_hists[i]->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / %.2f MeV",lo_hists[i]->GetBinWidth(1)));
    tmp=b.makefitplotretvals(w,lo_hists[i]);
    cc->SaveAs("./SavedFits/betastar/"+nameForFit+Form("fit_pkg_bkg_lo_sb_%d.pdf",i+1));
    cc->SetLogy(true);
    cc->SaveAs("./SavedFits/betastar/"+nameForFit+Form("fit_pkg_bkg_lo_sb_%d_logy.pdf",i+1));
    cc->SetLogy(false);
    lo_sig_vals[i]=tmp[0];
    lo_sig_errs[i]=tmp[1];
    tmp.clear();
    cc->Clear();
  }

  for(int i=0; i<5;++i){
    hi_hists[i]->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / %.2f MeV",hi_hists[i]->GetBinWidth(1)));
    tmp=b.makefitplotretvals(w,hi_hists[i]);
    cc->SaveAs("./SavedFits/betastar/"+nameForFit+Form("fit_pkg_bkg_hi_sb_%d.pdf",i+1));
    cc->SetLogy(true);
    cc->SaveAs("./SavedFits/betastar/"+nameForFit+Form("fit_pkg_bkg_hi_sb_%d_logy.pdf",i+1));
    cc->SetLogy(false);
    hi_sig_vals[i]=tmp[0];
    hi_sig_errs[i]=tmp[1];
    tmp.clear();
    cc->Clear();
  }
  
  double zeros[5]={0.,0.,0.,0.,0.};
  
  
  //cc->SaveAs("tmp.png");
  //massFit *fit_low;
  //massFit *fit_hi;
  //low sideband
  // for(int i=0; i<6;++i){
    

  // }
  return 0;
}
