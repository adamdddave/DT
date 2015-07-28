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
  if(argc<2){
    cout<<"*************************************"<<endl;
    cout<<"Expecting an external file to process"<<endl;
    cout<<" and possibly a workspace"<<endl;
    cout<<"*************************************"<<endl;
    return 0;
  }
  if(argc==3){
    cout<<"argv[1]="<<argv[1]<<", argv[2] = "<<argv[2]<<endl;
    hasWorkspace = true;
    //return 0;
  }
  bool isWS = false;
  TString fitName = argv[1];
  TString histName = "_dt_hist_dstar_m";
  TString histSSName = "_ss_dt_hist_dstar_m";
  TString nameForFit = "rs";
  //make it lower case just to make our lives easier
  fitName.ToLower();
  if(fitName.Contains("ws")){
    isWS = true;
    histName="WS"+histName;
    histSSName = "WS"+histSSName;
    cout<<"using WS sample"<<endl;
    if(!hasWorkspace){
      cout<<"fitting ws model without a workspace! break!"<<endl;
      return 0;
    }
    nameForFit = "ws";
    cout<<"nameForFit = "<<nameForFit<<endl;
    
  }
  else{
    histName="RS"+histName;
    histSSName = "RS"+histSSName;
  }
  
  TFile *f1 = TFile::Open(argv[1]);
  f1->ls();
  TH1D* mass = (TH1D*)f1->Get(histName);
  TH1D* ss_mass = (TH1D*)f1->Get(histSSName);
  TH1D* hist = (TH1D*)mass->Clone("mass");
  hist->Add(ss_mass,-1);//try to subtract the peaking bkg from the wrong b.
  //f1->Close();
  
  if(!hist){
    cout<<"can't get histogram, try again."<<endl;
    return 0;
  }
  if(!hasWorkspace && !isWS){
    //  massFit fit("rs","rcp3");
    massFit fit(nameForFit,"j3g");
    fit.initModelValues();
    fit.setData(hist);
    fit.fit();
    fit.savePlots(true);
    fit.saveFinalFit();
  }
  else{
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
    //assert0);
    massFit fit(nameForFit,"j3g", w);
    //return 0;
    //fit.initModelValues();
    fit.setData(hist);
    fit.fit();
    
    fit.savePlots(true,channelFromFile+"workspaceFit");
    fit.saveSignalRegionZoom();
  }
  return 0;
}

