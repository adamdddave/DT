#ifndef COMPLETE_ANALYSIS_TIMEDEPENDENTCHI2FIT_H 
#define COMPLETE_ANALYSIS_TIMEDEPENDENTCHI2FIT_H 1

// Include files
//C++
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <assert.h>
#include <string>
//root
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TMath.h>
#include <TString.h>
#include <TFile.h>
#include <TLegend.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TMinuit.h>

using namespace std;

class TimeDependentChi2Fit {
 public:
  TimeDependentChi2Fit(TString name);
  ~TimeDependentChi2Fit(){ delete minuit;};
  void SetData(TGraphAsymmErrors theGraph);
  void fit();
  //void initParams();
  double pValue();
  double chi2();

 protected:

 private:
  TString m_name;
  //void my_fcn(int& npar, double* deriv, double& func, double param[], int flag);
  TMinuit *minuit;
  double central_val[5];
  double error[5];
  double astart,amin,amax,astep;
  double chi2_val;
  int ndf;
};

#endif // COMPLETE_ANALYSIS_TIMEDEPENDENTCHI2FIT_H
double central_val_global[5];
double error_global[5];
double chi2_val_glob;
void my_fcn(int& npar, double* deriv, double& func, double param[], int flag){
  //chi2 fit to a flat line
  double a = param[0];
  double ret = 0;
  for(int i=0; i<5;++i){//loop over bins
    double exp = a;
    double obs = central_val_global[i];
    double err = error_global[i];
    ret+=pow((obs-exp)/err,2.);
  }
  chi2_val_glob = ret;
  func = ret;
}
