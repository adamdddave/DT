#ifndef COMPLETE_ANALYSIS_TIMEDEPENDENT2D_H
#define COMPLETE_ANALYSIS_TIMEDEPENDENT2D_H 1

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

using namespace std;

class TimeDependent2D{
 public:
  TimeDependent2D(TString histName,TFile *f1,TString saveName,std::vector<int> slices);
  virtual ~TimeDependent2D(){ }
 protected:
  
 private:
  TString mName;
  TString mSaveName;
  const int td0_bin_boundaries[6]={451,521,551,591,651,1500};//finer time binning!
  int theSliceBins[6];
  TH2D* theHist_vs_time;
  TH2D* theHist_vs_mass;
};

#endif
