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
  if(argc<2){
    cout<<"*************************************"<<endl;
    cout<<"Expecting an external file to process"<<endl;
    cout<<" and the workspace with the fit model"<<endl;
    cout<<"*************************************"<<endl;
    return 0;
  }
  if(argc==3){
    cout<<"argv[1]="<<argv[1]<<", argv[2] = "<<argv[2]<<endl;
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
  //fitName.ToUpper();
  TFile *f1 = TFile::Open(argv[1]);
  f1->ls();
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
  nameForFit.ToUpper();
  betastar_plot b(f1,nameForFit);
  RooWorkspace * w = (RooWorkspace*)f2->Get(channelFromFile);
  b.set_local_workspace(w);
  b.DrawPlots();
  //if(isWS){
  b.FitWSDoubleMisID();
      //}
  return 0;
}
