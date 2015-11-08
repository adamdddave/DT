//c++
#include <iostream>
#include <cmath>
//root
#include <TH1.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TMath.h>
#include <TFile.h>
#include <TObject.h>
#include <TTree.h>
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
using namespace std;
 // Include files 


int main(int argc, char* const argv[]){
  cout<<"Testing Mass Fit on External Data"<<endl;
  bool hasWorkspace=  false;
  cout<<"Interface for fitting the blinded WS/RS ratio"<<endl;
  if(argc<2){
    cout<<"*************************************"<<endl;
    cout<<"Expecting: "<<endl;
    cout<<"[1] The prompt datafile"<<endl;
    cout<<"[2] the DT RS datafile"<<endl;
    cout<<"[3] the DT WS datafile"<<endl;
    cout<<"[4] the RS fit model"<<endl;
    cout<<"*************************************"<<endl;
    return 0;
  }
  if(argc==3){
    cout<<"argv[1]="<<argv[1]<<", argv[2] = "<<argv[2]<<endl;
    hasWorkspace = true;
    //return 0;
  }
