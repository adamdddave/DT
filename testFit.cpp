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

// local
#include "massFit.h"
//#include "PlottingTools.h"
using namespace std;
 // Include files 


int main(int argc, char* const argv[]){
  cout<<"Testing Mass Fit on External Data"<<endl;
  if(argc<2){
    cout<<"*************************************"<<endl;
    cout<<"Expecting an external file to process"<<endl;
    cout<<"*************************************"<<endl;
    return 0;
  }
  TFile *f1 = TFile::Open(argv[1]);
  TH1D* hist = (TH1D*)f1->Get("dt_hist_dstar_m");
  if(!hist){
    cout<<"can't get histogram, try again."<<endl;
    return 0;
  }
  
  massFit fit("rs","rcp3");
  //massFit fit("rs","j3g");
  fit.initModelValues();
  fit.setData(hist);
  fit.fit();
  fit.savePlots(true);
  
  return 0;
}

