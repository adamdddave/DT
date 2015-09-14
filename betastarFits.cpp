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
#include <TGraphAsymmErrors.h>
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
  //mean vals extracted from histogram.
  double meansRS_lo[6]={1.792983e+03,1.798521e+03,1.804496e+03,1.810549e+03,1.816545e+03,1.822059e+03};
  double meansWS_lo[6]={1.792922e+03,1.798483e+03,1.804465e+03,1.810468e+03,1.816577e+03,1.821967e+03};

  double meansRS_hi[6]={1.907833e+03,1.913940e+03,1.919455e+03,1.925523e+03,1.931450e+03,1.937406e+03};
  double meansWS_hi[6]={1.907934e+03,1.913844e+03,1.919426e+03,1.925560e+03,1.931533e+03,1.937479e+03};

  double meansRS[12];
  double meansWS[12];
  for(int i=0;i<6;++i){
    meansRS[i]=meansRS_lo[i];
    meansRS[i+6]=meansRS_hi[i];
    meansWS[i]=meansWS_lo[i];
    meansWS[i+6]=meansWS_hi[i];
  }
  double D0_bin_edges_lo[7]={1790.,1795.8,1801.6,1807.4,1813.2,1819.,1824.84};
  double D0_bin_edges_hi[7]={1904.84,1911.,1916.8,1922.6,1928.4,1934.2,1940.};
  double x_errs_lo_down_RS[6];
  double x_errs_lo_up_RS[6];
  double x_errs_hi_down_RS[6];
  double x_errs_hi_up_RS[6];

  double x_errs_lo_down_WS[6];
  double x_errs_lo_up_WS[6];
  double x_errs_hi_down_WS[6];
  double x_errs_hi_up_WS[6];

  double x_errs_RS_up[12];
  double x_errs_RS_down[12];
  double x_errs_WS_up[12];
  double x_errs_WS_down[12];


  for(int i=0; i<6;++i){
    x_errs_lo_down_RS[i]= meansRS_lo[i]-D0_bin_edges_lo[i];
    x_errs_lo_up_RS[i]=D0_bin_edges_lo[i+1]-meansRS_lo[i];

    x_errs_hi_down_RS[i]= meansRS_hi[i]-D0_bin_edges_hi[i];
    x_errs_hi_up_RS[i]=D0_bin_edges_hi[i+1]-meansRS_hi[i];

    x_errs_lo_down_WS[i]= meansWS_lo[i]-D0_bin_edges_lo[i];
    x_errs_lo_up_WS[i]=D0_bin_edges_lo[i+1]-meansWS_lo[i];

    x_errs_hi_down_WS[i]= meansWS_hi[i]-D0_bin_edges_hi[i];
    x_errs_hi_up_WS[i]=D0_bin_edges_hi[i+1]-meansWS_hi[i];
    //the big array.
    x_errs_RS_down[i]=x_errs_lo_down_RS[i];
    x_errs_RS_down[i+6]=x_errs_hi_down_RS[i];
    x_errs_WS_down[i]=x_errs_lo_down_WS[i];
    x_errs_WS_down[i+6]=x_errs_hi_down_WS[i];
    //up
    x_errs_RS_up[i]=x_errs_lo_up_RS[i];
    x_errs_RS_up[i+6]=x_errs_hi_up_RS[i];
    x_errs_WS_up[i]=x_errs_lo_up_WS[i];
    x_errs_WS_up[i+6]=x_errs_hi_up_WS[i];
  }
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
  double sig_vals[12];
  double sig_errs[12];
  //  double hi_sig_vals[12];
  //double hi_sig_errs[5];
  std::vector<double>tmp;
  TCanvas* cc = new TCanvas();
  for(int i=0; i<6;++i){
    lo_hists[i]->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / %.2f MeV",lo_hists[i]->GetBinWidth(1)));
    tmp=b.makefitplotretvals(w,lo_hists[i]);
    cc->SaveAs("./SavedFits/betastar/"+nameForFit+Form("fit_pkg_bkg_lo_sb_%d.pdf",i+1));
    cc->SetLogy(true);
    cc->SaveAs("./SavedFits/betastar/"+nameForFit+Form("fit_pkg_bkg_lo_sb_%d_logy.pdf",i+1));
    cc->SetLogy(false);
    sig_vals[i]=tmp[0];
    sig_errs[i]=tmp[1];
    tmp.clear();
    cc->Clear();
  }

  for(int i=0; i<6;++i){
    hi_hists[i]->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / %.2f MeV",hi_hists[i]->GetBinWidth(1)));
    tmp=b.makefitplotretvals(w,hi_hists[i]);
    cc->SaveAs("./SavedFits/betastar/"+nameForFit+Form("fit_pkg_bkg_hi_sb_%d.pdf",i+1));
    cc->SetLogy(true);
    cc->SaveAs("./SavedFits/betastar/"+nameForFit+Form("fit_pkg_bkg_hi_sb_%d_logy.pdf",i+1));
    cc->SetLogy(false);
    sig_vals[i+6]=tmp[0];
    sig_errs[i+6]=tmp[1];
    tmp.clear();
    cc->Clear();
  }
  
  //double zeros[5]={0.,0.,0.,0.,0.};
  //decide if it's WS or RS
  TGraphAsymmErrors* the_graph;
  cout<<"name for fit = "<<nameForFit<<endl;
  if(nameForFit.Contains("RS")){
    the_graph = new TGraphAsymmErrors(12,meansRS,sig_vals,x_errs_RS_down,x_errs_RS_up,sig_errs,sig_errs);
  }
  else if(nameForFit.Contains("WS")){
    the_graph = new TGraphAsymmErrors(12,meansWS,sig_vals,x_errs_WS_down,x_errs_WS_up,sig_errs,sig_errs);
  }
  the_graph->SetTitle(";m(K#pi)[MeV];N(Signal)");
  the_graph->SetMarkerStyle(20);
  the_graph->SetMarkerColor(kBlack);
  the_graph->Draw("ap");
  cc->SaveAs("./SavedFits/betastar/"+nameForFit+"peaking_bkg_sidebands_from_fit.pdf");
  cc->SaveAs("./SavedFits/betastar/"+nameForFit+"peaking_bkg_sidebands_from_fit.root");
  //now fit this graph with a polynomial shape
  the_graph->Fit("pol2", "FERS");
  //access to the fit function
  TF1 *fpol = the_graph->GetFunction("pol2");
  //massFit *fit_low;
  //massFit *fit_hi;
  //low sideband
  // for(int i=0; i<6;++i){
    

  // }
  return 0;
}
