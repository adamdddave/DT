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
#include <TF1.h>
#include <TPaveStats.h>
#include <TBox.h>
#include <TFitResult.h>
#include <TVectorD.h>
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
//supporting method

std::vector<double> PeakingBkgFromSidebands(std::vector<TH1*>lo_hists,std::vector<TH1*>hi_hists,RooWorkspace* w_tmp, TString nameForFit, betastar_plot *b,array<double,4>initPars);

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
    
  cout<<"check after tertiary constructor, name for low bin 1 time bin 1 = "<<b.hmkpisb_cut_range_lo_1_time_bin1->GetName()<<endl;
  RooWorkspace * w = (RooWorkspace*)f3->Get(channelFromFile);
  b.set_local_workspace(w);
  
  b.DrawPlots();
  //if(isWS){
  cout<<"*************************"<<endl;
  cout<<"starting time integrated peaking backgrounds"<<endl;
  cout<<"*************************"<<endl;
  b.FitWSDoubleMisID();
  b.FitWSDoubleMisIDLiang();
  cout<<"*************************"<<endl;
  cout<<"stopping time integrated peaking backgrounds"<<endl;
  cout<<"*************************"<<endl;
  b.FitWSDoubleMisIDTimeDependence();

  //double check this by fitting the things.
  //shift to an independent class.
  //at the end of the day, all we want out is the number of signal in the signal region and error
  
  std::vector<TH1*>lo_hists,lo_hists_bkg;
  std::vector<TH1*>hi_hists,hi_hists_bkg;
  //mean vals extracted from histogram.
  
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
  //time bins here
  std::vector<TH1*>lo_hists_time_bin1,lo_hists_time_bin2,lo_hists_time_bin3,lo_hists_time_bin4,lo_hists_time_bin5;
  std::vector<TH1*>hi_hists_time_bin1,hi_hists_time_bin2,hi_hists_time_bin3,hi_hists_time_bin4,hi_hists_time_bin5;
  // //positive
  // std::vector<TH1*>lo_hists_pos_time_bin1,lo_hists_pos_time_bin2,lo_hists_pos_time_bin3,lo_hists_pos_time_bin4,lo_hists_pos_time_bin5;
  // std::vector<TH1*>hi_hists_pos_time_bin1,hi_hists_pos_time_bin2,hi_hists_pos_time_bin3,hi_hists_pos_time_bin4,hi_hists_pos_time_bin5;
  // //negative
  // std::vector<TH1*>lo_hists_neg_time_bin1,lo_hists_neg_time_bin2,lo_hists_neg_time_bin3,lo_hists_neg_time_bin4,lo_hists_neg_time_bin5;
  // std::vector<TH1*>hi_hists_neg_time_bin1,hi_hists_neg_time_bin2,hi_hists_neg_time_bin3,hi_hists_neg_time_bin4,hi_hists_neg_time_bin5;
  //mean vals extracted from histogram.

  //double sigYield[6];
  //double sigYieldErr[6];
  lo_hists_time_bin1.push_back(b.hmkpisb_cut_range_lo_1_time_bin1);
  lo_hists_time_bin1.push_back(b.hmkpisb_cut_range_lo_2_time_bin1);
  lo_hists_time_bin1.push_back(b.hmkpisb_cut_range_lo_3_time_bin1);
  lo_hists_time_bin1.push_back(b.hmkpisb_cut_range_lo_4_time_bin1);
  lo_hists_time_bin1.push_back(b.hmkpisb_cut_range_lo_5_time_bin1);
  lo_hists_time_bin1.push_back(b.hmkpisb_cut_range_lo_6_time_bin1);

  hi_hists_time_bin1.push_back(b.hmkpisb_cut_range_hi_1_time_bin1);
  hi_hists_time_bin1.push_back(b.hmkpisb_cut_range_hi_2_time_bin1);
  hi_hists_time_bin1.push_back(b.hmkpisb_cut_range_hi_3_time_bin1);
  hi_hists_time_bin1.push_back(b.hmkpisb_cut_range_hi_4_time_bin1);
  hi_hists_time_bin1.push_back(b.hmkpisb_cut_range_hi_5_time_bin1);
  hi_hists_time_bin1.push_back(b.hmkpisb_cut_range_hi_6_time_bin1);
  //
  lo_hists_time_bin2.push_back(b.hmkpisb_cut_range_lo_1_time_bin2);
  lo_hists_time_bin2.push_back(b.hmkpisb_cut_range_lo_2_time_bin2);
  lo_hists_time_bin2.push_back(b.hmkpisb_cut_range_lo_3_time_bin2);
  lo_hists_time_bin2.push_back(b.hmkpisb_cut_range_lo_4_time_bin2);
  lo_hists_time_bin2.push_back(b.hmkpisb_cut_range_lo_5_time_bin2);
  lo_hists_time_bin2.push_back(b.hmkpisb_cut_range_lo_6_time_bin2);

  hi_hists_time_bin2.push_back(b.hmkpisb_cut_range_hi_1_time_bin2);
  hi_hists_time_bin2.push_back(b.hmkpisb_cut_range_hi_2_time_bin2);
  hi_hists_time_bin2.push_back(b.hmkpisb_cut_range_hi_3_time_bin2);
  hi_hists_time_bin2.push_back(b.hmkpisb_cut_range_hi_4_time_bin2);
  hi_hists_time_bin2.push_back(b.hmkpisb_cut_range_hi_5_time_bin2);
  hi_hists_time_bin2.push_back(b.hmkpisb_cut_range_hi_6_time_bin2);
  //
  lo_hists_time_bin3.push_back(b.hmkpisb_cut_range_lo_1_time_bin3);
  lo_hists_time_bin3.push_back(b.hmkpisb_cut_range_lo_2_time_bin3);
  lo_hists_time_bin3.push_back(b.hmkpisb_cut_range_lo_3_time_bin3);
  lo_hists_time_bin3.push_back(b.hmkpisb_cut_range_lo_4_time_bin3);
  lo_hists_time_bin3.push_back(b.hmkpisb_cut_range_lo_5_time_bin3);
  lo_hists_time_bin3.push_back(b.hmkpisb_cut_range_lo_6_time_bin3);

  hi_hists_time_bin3.push_back(b.hmkpisb_cut_range_hi_1_time_bin3);
  hi_hists_time_bin3.push_back(b.hmkpisb_cut_range_hi_2_time_bin3);
  hi_hists_time_bin3.push_back(b.hmkpisb_cut_range_hi_3_time_bin3);
  hi_hists_time_bin3.push_back(b.hmkpisb_cut_range_hi_4_time_bin3);
  hi_hists_time_bin3.push_back(b.hmkpisb_cut_range_hi_5_time_bin3);
  hi_hists_time_bin3.push_back(b.hmkpisb_cut_range_hi_6_time_bin3);
  //
  lo_hists_time_bin4.push_back(b.hmkpisb_cut_range_lo_1_time_bin4);
  lo_hists_time_bin4.push_back(b.hmkpisb_cut_range_lo_2_time_bin4);
  lo_hists_time_bin4.push_back(b.hmkpisb_cut_range_lo_3_time_bin4);
  lo_hists_time_bin4.push_back(b.hmkpisb_cut_range_lo_4_time_bin4);
  lo_hists_time_bin4.push_back(b.hmkpisb_cut_range_lo_5_time_bin4);
  lo_hists_time_bin4.push_back(b.hmkpisb_cut_range_lo_6_time_bin4);

  hi_hists_time_bin4.push_back(b.hmkpisb_cut_range_hi_1_time_bin4);
  hi_hists_time_bin4.push_back(b.hmkpisb_cut_range_hi_2_time_bin4);
  hi_hists_time_bin4.push_back(b.hmkpisb_cut_range_hi_3_time_bin4);
  hi_hists_time_bin4.push_back(b.hmkpisb_cut_range_hi_4_time_bin4);
  hi_hists_time_bin4.push_back(b.hmkpisb_cut_range_hi_5_time_bin4);
  hi_hists_time_bin4.push_back(b.hmkpisb_cut_range_hi_6_time_bin4);
  //
  lo_hists_time_bin5.push_back(b.hmkpisb_cut_range_lo_1_time_bin5);
  lo_hists_time_bin5.push_back(b.hmkpisb_cut_range_lo_2_time_bin5);
  lo_hists_time_bin5.push_back(b.hmkpisb_cut_range_lo_3_time_bin5);
  lo_hists_time_bin5.push_back(b.hmkpisb_cut_range_lo_4_time_bin5);
  lo_hists_time_bin5.push_back(b.hmkpisb_cut_range_lo_5_time_bin5);
  lo_hists_time_bin5.push_back(b.hmkpisb_cut_range_lo_6_time_bin5);

  hi_hists_time_bin5.push_back(b.hmkpisb_cut_range_hi_1_time_bin5);
  hi_hists_time_bin5.push_back(b.hmkpisb_cut_range_hi_2_time_bin5);
  hi_hists_time_bin5.push_back(b.hmkpisb_cut_range_hi_3_time_bin5);
  hi_hists_time_bin5.push_back(b.hmkpisb_cut_range_hi_4_time_bin5);
  hi_hists_time_bin5.push_back(b.hmkpisb_cut_range_hi_5_time_bin5);
  hi_hists_time_bin5.push_back(b.hmkpisb_cut_range_hi_6_time_bin5);
  // //positive
  // lo_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_lo_1_time_bin1);
  // lo_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_lo_2_time_bin1);
  // lo_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_lo_3_time_bin1);
  // lo_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_lo_4_time_bin1);
  // lo_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_lo_5_time_bin1);
  // lo_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_lo_6_time_bin1);

  // hi_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_hi_1_time_bin1);
  // hi_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_hi_2_time_bin1);
  // hi_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_hi_3_time_bin1);
  // hi_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_hi_4_time_bin1);
  // hi_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_hi_5_time_bin1);
  // hi_hists_pos_time_bin1.push_back(b.hmkpisb_pos_cut_range_hi_6_time_bin1);
  // //
  // lo_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_lo_1_time_bin2);
  // lo_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_lo_2_time_bin2);
  // lo_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_lo_3_time_bin2);
  // lo_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_lo_4_time_bin2);
  // lo_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_lo_5_time_bin2);
  // lo_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_lo_6_time_bin2);

  // hi_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_hi_1_time_bin2);
  // hi_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_hi_2_time_bin2);
  // hi_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_hi_3_time_bin2);
  // hi_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_hi_4_time_bin2);
  // hi_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_hi_5_time_bin2);
  // hi_hists_pos_time_bin2.push_back(b.hmkpisb_pos_cut_range_hi_6_time_bin2);
  // //
  // lo_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_lo_1_time_bin3);
  // lo_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_lo_2_time_bin3);
  // lo_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_lo_3_time_bin3);
  // lo_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_lo_4_time_bin3);
  // lo_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_lo_5_time_bin3);
  // lo_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_lo_6_time_bin3);

  // hi_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_hi_1_time_bin3);
  // hi_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_hi_2_time_bin3);
  // hi_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_hi_3_time_bin3);
  // hi_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_hi_4_time_bin3);
  // hi_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_hi_5_time_bin3);
  // hi_hists_pos_time_bin3.push_back(b.hmkpisb_pos_cut_range_hi_6_time_bin3);
  // //
  // lo_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_lo_1_time_bin4);
  // lo_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_lo_2_time_bin4);
  // lo_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_lo_3_time_bin4);
  // lo_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_lo_4_time_bin4);
  // lo_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_lo_5_time_bin4);
  // lo_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_lo_6_time_bin4);

  // hi_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_hi_1_time_bin4);
  // hi_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_hi_2_time_bin4);
  // hi_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_hi_3_time_bin4);
  // hi_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_hi_4_time_bin4);
  // hi_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_hi_5_time_bin4);
  // hi_hists_pos_time_bin4.push_back(b.hmkpisb_pos_cut_range_hi_6_time_bin4);
  // //
  // lo_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_lo_1_time_bin5);
  // lo_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_lo_2_time_bin5);
  // lo_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_lo_3_time_bin5);
  // lo_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_lo_4_time_bin5);
  // lo_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_lo_5_time_bin5);
  // lo_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_lo_6_time_bin5);

  // hi_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_hi_1_time_bin5);
  // hi_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_hi_2_time_bin5);
  // hi_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_hi_3_time_bin5);
  // hi_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_hi_4_time_bin5);
  // hi_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_hi_5_time_bin5);
  // hi_hists_pos_time_bin5.push_back(b.hmkpisb_pos_cut_range_hi_6_time_bin5);

  // //negative
  // lo_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_lo_1_time_bin1);
  // lo_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_lo_2_time_bin1);
  // lo_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_lo_3_time_bin1);
  // lo_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_lo_4_time_bin1);
  // lo_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_lo_5_time_bin1);
  // lo_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_lo_6_time_bin1);

  // hi_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_hi_1_time_bin1);
  // hi_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_hi_2_time_bin1);
  // hi_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_hi_3_time_bin1);
  // hi_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_hi_4_time_bin1);
  // hi_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_hi_5_time_bin1);
  // hi_hists_neg_time_bin1.push_back(b.hmkpisb_neg_cut_range_hi_6_time_bin1);
  // //
  // lo_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_lo_1_time_bin2);
  // lo_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_lo_2_time_bin2);
  // lo_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_lo_3_time_bin2);
  // lo_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_lo_4_time_bin2);
  // lo_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_lo_5_time_bin2);
  // lo_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_lo_6_time_bin2);

  // hi_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_hi_1_time_bin2);
  // hi_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_hi_2_time_bin2);
  // hi_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_hi_3_time_bin2);
  // hi_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_hi_4_time_bin2);
  // hi_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_hi_5_time_bin2);
  // hi_hists_neg_time_bin2.push_back(b.hmkpisb_neg_cut_range_hi_6_time_bin2);
  // //
  // lo_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_lo_1_time_bin3);
  // lo_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_lo_2_time_bin3);
  // lo_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_lo_3_time_bin3);
  // lo_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_lo_4_time_bin3);
  // lo_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_lo_5_time_bin3);
  // lo_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_lo_6_time_bin3);

  // hi_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_hi_1_time_bin3);
  // hi_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_hi_2_time_bin3);
  // hi_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_hi_3_time_bin3);
  // hi_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_hi_4_time_bin3);
  // hi_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_hi_5_time_bin3);
  // hi_hists_neg_time_bin3.push_back(b.hmkpisb_neg_cut_range_hi_6_time_bin3);
  // //
  // lo_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_lo_1_time_bin4);
  // lo_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_lo_2_time_bin4);
  // lo_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_lo_3_time_bin4);
  // lo_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_lo_4_time_bin4);
  // lo_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_lo_5_time_bin4);
  // lo_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_lo_6_time_bin4);

  // hi_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_hi_1_time_bin4);
  // hi_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_hi_2_time_bin4);
  // hi_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_hi_3_time_bin4);
  // hi_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_hi_4_time_bin4);
  // hi_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_hi_5_time_bin4);
  // hi_hists_neg_time_bin4.push_back(b.hmkpisb_neg_cut_range_hi_6_time_bin4);
  // //
  // lo_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_lo_1_time_bin5);
  // lo_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_lo_2_time_bin5);
  // lo_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_lo_3_time_bin5);
  // lo_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_lo_4_time_bin5);
  // lo_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_lo_5_time_bin5);
  // lo_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_lo_6_time_bin5);

  // hi_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_hi_1_time_bin5);
  // hi_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_hi_2_time_bin5);
  // hi_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_hi_3_time_bin5);
  // hi_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_hi_4_time_bin5);
  // hi_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_hi_5_time_bin5);
  // hi_hists_neg_time_bin5.push_back(b.hmkpisb_neg_cut_range_hi_6_time_bin5);
  //now the fits
  cout<<"testing low hist 0 name from betastarplot, name = "<<b.hmkpisb_cut_range_lo_1_time_bin1->GetName()<<endl;
  cout<<"testing lo_hists_time_bins, bin1->GetName() = "<<lo_hists_time_bin1[0]->GetName()<<endl;
    //try rebinning the histograms
  for(auto hist: lo_hists){hist->Rebin();}
  for(auto hist: hi_hists){hist->Rebin();}
  //time bins
  for(auto hist: lo_hists_time_bin1){hist->Rebin();}
  for(auto hist: lo_hists_time_bin2){hist->Rebin();}
  for(auto hist: lo_hists_time_bin3){hist->Rebin();}
  for(auto hist: lo_hists_time_bin4){hist->Rebin();}
  for(auto hist: lo_hists_time_bin5){hist->Rebin();}
  
  for(auto hist: hi_hists_time_bin1){hist->Rebin();}
  for(auto hist: hi_hists_time_bin2){hist->Rebin();}
  for(auto hist: hi_hists_time_bin3){hist->Rebin();}
  for(auto hist: hi_hists_time_bin4){hist->Rebin();}
  for(auto hist: hi_hists_time_bin5){hist->Rebin();}
  // //positive
  // for(auto hist: lo_hists_pos_time_bin1){hist->Rebin();}
  // for(auto hist: lo_hists_pos_time_bin2){hist->Rebin();}
  // for(auto hist: lo_hists_pos_time_bin3){hist->Rebin();}
  // for(auto hist: lo_hists_pos_time_bin4){hist->Rebin();}
  // for(auto hist: lo_hists_pos_time_bin5){hist->Rebin();}
  
  // for(auto hist: hi_hists_pos_time_bin1){hist->Rebin();}
  // for(auto hist: hi_hists_pos_time_bin2){hist->Rebin();}
  // for(auto hist: hi_hists_pos_time_bin3){hist->Rebin();}
  // for(auto hist: hi_hists_pos_time_bin4){hist->Rebin();}
  // for(auto hist: hi_hists_pos_time_bin5){hist->Rebin();}
  // //negative
  // for(auto hist: lo_hists_neg_time_bin1){hist->Rebin();}
  // for(auto hist: lo_hists_neg_time_bin2){hist->Rebin();}
  // for(auto hist: lo_hists_neg_time_bin3){hist->Rebin();}
  // for(auto hist: lo_hists_neg_time_bin4){hist->Rebin();}
  // for(auto hist: lo_hists_neg_time_bin5){hist->Rebin();}
  
  // for(auto hist: hi_hists_neg_time_bin1){hist->Rebin();}
  // for(auto hist: hi_hists_neg_time_bin2){hist->Rebin();}
  // for(auto hist: hi_hists_neg_time_bin3){hist->Rebin();}
  // for(auto hist: hi_hists_neg_time_bin4){hist->Rebin();}
  // for(auto hist: hi_hists_neg_time_bin5){hist->Rebin();}
  //try making a massFit with a single gaussian+bkg to the combined sample.
  TH1D* tot_histo = (TH1D*)lo_hists[0]->Clone("tot_pkg_bkg");
  for(int i=1; i<6;++i){
    tot_histo->Add(lo_hists[i]);
  }
  for(auto hist : hi_hists){
    tot_histo->Add(hist);
  }

  
  massFit tot_bkg_fit(nameForFit,"1g",0,"betastar");
  tot_bkg_fit.initModelValues();
  tot_bkg_fit.setData(tot_histo);
  tot_bkg_fit.fit();
  tot_bkg_fit.savePlots(false,"_bkg_model");
  tot_bkg_fit.saveFinalFit();

  //now that we have a fit model that works, go find it.
  TFile* f_tmp = TFile::Open("./SavedFits/betastar/"+nameForFit+"_1gfitModel.root");
  //f_tmp->ls();
  RooWorkspace *w_tmp = (RooWorkspace*)f_tmp->Get(nameForFit+"w");
  array<double,4> thePars{
    (w_tmp->var("kappa")->getVal()),
      (w_tmp->var("n")->getVal()),
      (w_tmp->var("nbkg")->getVal()),
      (w_tmp->var("nsig")->getVal())};
  std::vector<double> tot_result_of_sb_fit = PeakingBkgFromSidebands(lo_hists,hi_hists,w_tmp,nameForFit,&b,thePars);
  //now do time dependence.
  //as from mike.The idea is that the original code which just split everything into bins of decay time is going to be hopeless
  //since there will not be enough statistics. What we can do, however, is take the time integrated Peaking Bkg / RS as a scaling
  //factor and then multiply RS yield in each bin by this scaling factor to extract the expected result. This is dependent
  //on the assumption that the RS/RS ratio is time independent (which it kind of is)

  //get the time bins yields from a file.
  
  
  return 0;//for now, stop here
  //  std::vector< std::vector<double> > res_sb_time_dependence;
  //  std::vector< std::vector<double> > res_sb_time_dependence_pos;
  //std::vector< std::vector<double> > res_sb_time_dependence_neg;

  
  // res_sb_time_dependence.push_back(PeakingBkgFromSidebands(lo_hists_time_bin1,hi_hists_time_bin1,w_tmp,nameForFit+"_time_bin1",&b,thePars));
  // res_sb_time_dependence.push_back(PeakingBkgFromSidebands(lo_hists_time_bin2,hi_hists_time_bin2,w_tmp,nameForFit+"_time_bin2",&b,thePars));
  // res_sb_time_dependence.push_back(PeakingBkgFromSidebands(lo_hists_time_bin3,hi_hists_time_bin3,w_tmp,nameForFit+"_time_bin3",&b,thePars));
  //res_sb_time_dependence.push_back(PeakingBkgFromSidebands(lo_hists_time_bin4,hi_hists_time_bin4,w_tmp,nameForFit+"_time_bin4",&b,thePars));
  //res_sb_time_dependence.push_back(PeakingBkgFromSidebands(lo_hists_time_bin5,hi_hists_time_bin5,w_tmp,nameForFit+"_time_bin5",&b,thePars));
  //positive
  // res_sb_time_dependence_pos.push_back(PeakingBkgFromSidebands(lo_hists_pos_time_bin1,hi_hists_pos_time_bin1,w_tmp,nameForFit+"_time_bin1",&b,thePars));
  // res_sb_time_dependence_pos.push_back(PeakingBkgFromSidebands(lo_hists_pos_time_bin2,hi_hists_pos_time_bin2,w_tmp,nameForFit+"_time_bin2",&b,thePars));
  // res_sb_time_dependence_pos.push_back(PeakingBkgFromSidebands(lo_hists_pos_time_bin3,hi_hists_pos_time_bin3,w_tmp,nameForFit+"_time_bin3",&b,thePars));
  // res_sb_time_dependence_pos.push_back(PeakingBkgFromSidebands(lo_hists_pos_time_bin4,hi_hists_pos_time_bin4,w_tmp,nameForFit+"_time_bin4",&b,thePars));
  // res_sb_time_dependence_pos.push_back(PeakingBkgFromSidebands(lo_hists_pos_time_bin5,hi_hists_pos_time_bin5,w_tmp,nameForFit+"_time_bin5",&b,thePars));
  // //negative
  // res_sb_time_dependence_neg.push_back(PeakingBkgFromSidebands(lo_hists_neg_time_bin1,hi_hists_neg_time_bin1,w_tmp,nameForFit+"_time_bin1",&b,thePars));
  // res_sb_time_dependence_neg.push_back(PeakingBkgFromSidebands(lo_hists_neg_time_bin2,hi_hists_neg_time_bin2,w_tmp,nameForFit+"_time_bin2",&b,thePars));
  // res_sb_time_dependence_neg.push_back(PeakingBkgFromSidebands(lo_hists_neg_time_bin3,hi_hists_neg_time_bin3,w_tmp,nameForFit+"_time_bin3",&b,thePars));
  // res_sb_time_dependence_neg.push_back(PeakingBkgFromSidebands(lo_hists_neg_time_bin4,hi_hists_neg_time_bin4,w_tmp,nameForFit+"_time_bin4",&b,thePars));
  // res_sb_time_dependence_neg.push_back(PeakingBkgFromSidebands(lo_hists_neg_time_bin5,hi_hists_neg_time_bin5,w_tmp,nameForFit+"_time_bin5",&b,thePars));
  //std::vector<double> res_sb_time_dependence = PeakingBkgFromSidebands(lo_hists_time_bin1,hi_hists_time_bin1,w_tmp,nameForFit+"_time_bin1",&b);
  //now we have all the information, print out a prettly little table.
  //
  // cout<<"- - - - - - - - - - - - - - - - - - -  -"<<endl;
  // cout<<"Linear fit"<<endl;
  // cout<<"- - - - - - - - - - - - - - - - - - -  -"<<endl;
  // cout<<"Time bin"<<setw(25)<<"Extracted PeakingBkg"<<setw(25)<<"error"<<endl;
  // int counter = 0;
  // for(auto res:res_sb_time_dependence){
  //   counter++;
  //   cout<<counter<<setw(25)<<res[0]<<setw(25)<<res[1]<<endl;
  // }
  // cout<<"- - - - - - - - - - - - - - - - - - -  -"<<endl;
  // cout<<"Parabolic fit"<<endl;
  // cout<<"- - - - - - - - - - - - - - - - - - -  -"<<endl;
  // cout<<"Time bin"<<setw(25)<<"Extracted PeakingBkg"<<setw(25)<<"error"<<endl;
  // counter = 0;
  // for(auto res:res_sb_time_dependence){
  //   counter++;
  //   cout<<counter<<setw(25)<<res[2]<<setw(25)<<res[3]<<endl;

  //print the positive and negative results
  f_tmp->Close();
  
  return 0;
}


std::vector<double> PeakingBkgFromSidebands(std::vector<TH1*>lo_hists, std::vector<TH1*>hi_hists, RooWorkspace* w_tmp, TString nameForFit,betastar_plot* b, array<double,4> initPars){
  double sig_vals[12];
  double sig_errs[12];
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
  
  for(int i=0; i<6;++i){
    lo_hists[i]->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / %.2f MeV",lo_hists[i]->GetBinWidth(1)));
    massFit fit_lo(nameForFit+Form("_pkg_bkg_lo_%d",i+1),"1g",w_tmp,"betastar");
    fit_lo.setData(lo_hists[i]);
    fit_lo.initValsByHand(initPars);//added to stop variation from initial fit
    fit_lo.fit();
    fit_lo.savePlots(false,"_sideband_fit_");
    sig_vals[i]=fit_lo.getNsig();
    sig_errs[i]=fit_lo.getNsigErr();
    
    fit_lo.Reset();
    //cc->Clear();
  }

  for(int i=0; i<6;++i){
    hi_hists[i]->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / %.2f MeV",hi_hists[i]->GetBinWidth(1)));
    massFit fit_hi(nameForFit+Form("_pkg_bkg_hi_%d",i+1),"1g",w_tmp,"betastar");
    fit_hi.setData(hi_hists[i]);
    fit_hi.initValsByHand(initPars);//added to stop variation from initial fit
    fit_hi.fit();
    fit_hi.savePlots(false,"_sideband_fit_");
    sig_vals[i+6]=fit_hi.getNsig();
    sig_errs[i+6]=fit_hi.getNsigErr();
    fit_hi.Reset();
    //    cc->Clear();
  }
  double sig_errs_up[12],sig_errs_down[12];
  for(int i=0;i<12;++i){
    sig_errs_up[i]=sig_errs[i];
    /*if(sig_vals[i]-sig_errs[i]<0){
      sig_errs_down[i]=sig_vals[i];
    }
    else{*/
    sig_errs_down[i]=sig_errs[i];
    //}
  }
  //f_tmp->Close();
  //double zeros[5]={0.,0.,0.,0.,0.};
  TCanvas* cnv = new TCanvas();
  cnv->Clear();

  //decide if it's WS or RS
  TGraphAsymmErrors* the_graph;
  cout<<"name for fit = "<<nameForFit<<endl;
  if(nameForFit.Contains("RS")){
    the_graph = new TGraphAsymmErrors(12,meansRS,sig_vals,x_errs_RS_down,x_errs_RS_up,sig_errs_down,sig_errs_up);
  }
  else if(nameForFit.Contains("WS")){
    the_graph = new TGraphAsymmErrors(12,meansWS,sig_vals,x_errs_WS_down,x_errs_WS_up,sig_errs_down,sig_errs_up);
  }
  the_graph->SetTitle(";m(K#pi)[MeV];N(Signal)");
  the_graph->SetMarkerStyle(20);
  the_graph->SetMarkerColor(kBlack);
  //the_graph->GetYaxis()->SetRangeUser(0.,the_graph->GetYaxis()->GetXmax());
  the_graph->Draw("ap");
  cnv->Modified();
  cnv->Update();
  cnv->SaveAs("./SavedFits/betastar/"+nameForFit+"peaking_bkg_sidebands_from_fit.pdf");
  cnv->SaveAs("./SavedFits/betastar/"+nameForFit+"peaking_bkg_sidebands_from_fit.root");

  TBox sigreg(1864.84-24,0,1864.84+24,the_graph->GetYaxis()->GetXmax());
  sigreg.SetFillColor(kGreen+2);
  sigreg.SetFillColorAlpha(kGreen+2,0.5);
  sigreg.Draw();
  //now fit this graph with a polynomial shape
  TF1* mf =  new TF1("mf","pol2(0)",the_graph->GetXaxis()->GetXmin(),the_graph->GetXaxis()->GetXmax());
  //change to a different fit model, to allow for fixing of shape parameters, but overall normalization change.
  //TF1* mf =  new TF1("mf","[0]*([1]+[2]*x + [3]*x*x)",the_graph->GetXaxis()->GetXmin(),the_graph->GetXaxis()->GetXmax());
  //mf->SetParameters(-8000.,8000.-0.001);
  //  mf->SetParameters(-370,3,-1e3);
  //  mf->SetRange(1790.,1940.);
  //mf->FixParameter(0,-3.69408e3);
  //  mf->FixParameter(1,3.95435);
  //  mf->FixParameter(2,-1.05638e-3);
  /*  mf->SetParLimits(0,-700,-100);
  mf->SetParLimits(1,-1,8);
  mf->SetParLimits(2,-10,10);*/
  
  //try fixing parameters
  
    /*
      ///result from fitting by hand
    Info in <CheckGraphFitOptions>: I (use function integral) is an invalid option when fitting a graph. It is ignored
     FCN=11.3637 FROM MIGRAD    STATUS=CONVERGED     153 CALLS         154 TOTAL
                         EDM=7.61426e-07    STRATEGY= 1      ERROR MATRIX ACCURATE
      EXT PARAMETER                                   STEP         FIRST
      NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE
       1  p0          -3.69408e+03   3.09568e+01   1.76148e-03   9.15204e-04
       2  p1           3.95435e+00   2.92829e-02   1.88558e-06   1.73546e+00
       3  p2          -1.05638e-03   8.31697e-06   5.03723e-10   3.29150e+03
    */
  TFitResultPtr r =the_graph->Fit("mf", "S");
  gStyle->SetOptFit(1111);
  //acnvess to the fit function
  //move the stats box
  TPaveStats* ps = (TPaveStats *)the_graph->GetListOfFunctions()->FindObject("stats");
  ps->SetX1NDC(0.15);
  ps->SetX2NDC(0.55);
  cnv->Modified();
  cnv->Update();
  cnv->SaveAs("./SavedFits/betastar/"+nameForFit+"peaking_bkg_sidebands_from_fit_fitted_polynomial.pdf");
  cnv->Clear();
  //now integrate the curve in the signal region
  double sb_integral = mf->Integral(D0_bin_edges_lo[0],D0_bin_edges_lo[6])+ mf->Integral(D0_bin_edges_hi[0],D0_bin_edges_hi[6]);
  double sig_reg_integral = mf->Integral(1864.84-24,1864.84,+24);
  double tot_sb_sig =0;
  double tot_sb_sig_err = 0;
  //find error in the integral
  
  TMatrixDSym mat = r->GetCorrelationMatrix();
  TF1* mf_tester =mf;//copy constructor
  Int_t npars = mf->GetNpar();
  double* pars = mf->GetParameters();
  const double* epars = mf->GetParErrors();
  double err_Rat = b->ErrorFromTF1(mf_tester,npars,pars,epars,mat,D0_bin_edges_lo[0],D0_bin_edges_lo[6],D0_bin_edges_hi[0],D0_bin_edges_hi[6],1864.84-24,1864.84+24);
  //fix everything by the y intercept
  //  mf->FixParameter(1);
  //mf->FixParameter(2,pars[2]);
  for(auto val : sig_vals){
    tot_sb_sig+=val;
  }
  for(auto val: sig_errs){
    tot_sb_sig_err+= val*val;
  }
  //Double_t errFrac = sig_reg_integral/sb_integral*(err_Num/sig_reg_integral-err_Den/sb_integral);
  Double_t errNsig_sigreg = (tot_sb_sig*sig_reg_integral/sb_integral)*TMath::Sqrt(tot_sb_sig_err/(tot_sb_sig*tot_sb_sig)+err_Rat*err_Rat/(sig_reg_integral*sig_reg_integral/(sb_integral*sb_integral)));

  //now do the same thing for a linear fit.
  TF1* mf_lin =  new TF1("mf_lin","pol1(0)",the_graph->GetXaxis()->GetXmin(),the_graph->GetXaxis()->GetXmax());
  the_graph->GetFunction("mf")->Delete();//remove the polynomial fit
  the_graph->Draw("ap");
  TFitResultPtr rl = the_graph->Fit("mf_lin","S");
  TPaveStats* psl = (TPaveStats*)the_graph->GetListOfFunctions()->FindObject("stats");
  psl->SetX1NDC(0.15);
  psl->SetX2NDC(0.55);
  cnv->Modified();
  cnv->Update();
  cnv->SaveAs("./SavedFits/betastar/"+nameForFit+"peaking_bkg_sidebands_from_fit_fitted_linear.pdf");
  cnv->Clear();
  double sb_integral_lin = mf_lin->Integral(D0_bin_edges_lo[0],D0_bin_edges_lo[6])+ mf_lin->Integral(D0_bin_edges_hi[0],D0_bin_edges_hi[6]);
  double sig_reg_integral_lin = mf_lin->Integral(1864.84-24,1864.84,+24);
  TMatrixDSym mat2 = rl->GetCorrelationMatrix();
  TF1* mf_lintest =mf_lin;//copy constructor
  Int_t npars2 = mf_lin->GetNpar();
  double* pars2 = mf_lin->GetParameters();
  const double* epars2 = mf_lin->GetParErrors();
  double err_Rat2 = b->ErrorFromTF1(mf_lintest,npars2,pars2,epars2,mat2,D0_bin_edges_lo[0],D0_bin_edges_lo[6],D0_bin_edges_hi[0],D0_bin_edges_hi[6],1864.84-24,1864.84+24);
  Double_t errNsig_sigreg2 = (tot_sb_sig*sig_reg_integral_lin/sb_integral_lin)*TMath::Sqrt(tot_sb_sig_err/(tot_sb_sig*tot_sb_sig)+err_Rat2*err_Rat2/(sig_reg_integral_lin*sig_reg_integral_lin/(sb_integral_lin*sb_integral_lin)));


  cout<<"Number of events in sideband times ratio of signal to sideband = "<< tot_sb_sig * sig_reg_integral/sb_integral<<" +/- "
      <<errNsig_sigreg<<endl;
  cout<<"Same for linear fit = "<< tot_sb_sig * sig_reg_integral_lin/sb_integral_lin<<" +/- "
      <<errNsig_sigreg2<<endl;
  std::vector<double>ret;
  ret.push_back(tot_sb_sig*sig_reg_integral_lin/sb_integral_lin);//central linear value
  ret.push_back(errNsig_sigreg2);//error on linear
  ret.push_back(tot_sb_sig*sig_reg_integral/sb_integral);//parabolic central value
  ret.push_back(errNsig_sigreg);//error on parab.
  return ret;
}
