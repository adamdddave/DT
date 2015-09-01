#ifndef COMPLETE_ANALYSIS_TIMEINTEGRATEDSYSTEMATICSCLASS_H
#define COMPLETE_ANALYSIS_TIMEINTEGRATEDSYSTEMATICSCLASS_H 1

//external
#include "massFit.h"

//include files
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <string>
//root
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TString.h>
#include <TFile.h>
#include <TLegend.h>
#include <TGraph.h>
#include <TGraphErrors.h>
//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include <RooFitResult.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooGaussian.h>
#include <RooChebychev.h>
#include <RooArgusBG.h>
#include <RooAddPdf.h>
#include <RooCBShape.h>
#include <RooGenericPdf.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <RooPlot.h>
#include <RooHist.h>
#include <RooDataHist.h>
#include <RooExponential.h>
#include <RooBinning.h>
#include <RooDstD0BG.h>
#include <RooNLLVar.h>
#include "RooJohnson.h"
#include "RooJohnsonSU.h"
#include "RooRBW.h"
#include "RooCarolP3.h"
#include "RooWorkspace.h"
using namespace RooFit ;
using namespace std;

class TimeIntegratedSystematicsClass {
 public:
  TimeIntegratedSystematicsClass(TString name,TFile *fin,RooWorkspace* w,TString var2Test,TString var2subtr,TString histoForBins,TString histoForBinsBkg,int binRanges[6],int nbins=5);//constructor
  virtual ~TimeIntegratedSystematicsClass(){};
  //void doFit;
  inline std::vector<double>GetSignalPoint(){return SigAndErr;}
  
 protected:

 private:
  TString mName;
  RooWorkspace* wLocal;
  int nBins;//number of bins of the variable in question
  massFit* theFit;//the fitter
  TH1D* varSigHist;//the RS histogram of the variable in question
  TH1D* varBkgHist;//the RS ss histogram of the variable in question
  TH1D* sigHist;//the Dstar mass histogram for RS
  TH1D* bkgHist;//the Dstar mass histogram for RS ss
  TH1D* sigHistBins[5];//the dstar mass histogram for RS in bins of variable
  TH1D* bkgHistBins[5];//the dstar mass histogram for RS ss in bins of variable
  //TH1D* dstarMassBins[5];//unused.
  double mean_positions_of_variable[5];//the mean position of the variable in each bin.
  int bin_ranges[5+1];
  std::vector<TH1D*> dst_hist_in_bins;
  double dMeans[5];
  double dMeansErr[5];
  double rSigmas[5];
  double rSigmasErr[5];
  double xError_low[5];//for finding the center of the bins for the dmean and rsigma plots
  double xError_hi[5];
  double sigYield[5];
  double sigYieldErr[5];
  TGraphAsymmErrors* dmeanGraph;
  TGraphAsymmErrors* rsigmaGraph;
  std::vector<double> SigAndErr;
  TString theAxisLabel;
};
#endif //  COMPLETE_ANALYSIS_TIMEINTEGRATEDSYSTEMATICSCLASS_H
