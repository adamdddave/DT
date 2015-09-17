#ifndef COMPLETE_ANALYSIS_SLOWPIONSTUDY_H
#define COMPLETE_ANALYSIS_SLOWPIONSTUDY_H 1

//include files
#include <iostream>
#include <vector>
#include <TH1.h>
#include <TString.h>
#include <TGraphErrors.h>
//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include <RooWorkspace.h>

using namespace RooFit ;
class slowPionStudy {
 public:
  void makeProbNNghostPlots();
  void setHistogramsPositive(std::vector<TH1D*>the_hists_pass,std::vector<TH1D*>the_hists_fail);
  void setHistogramsNegative(std::vector<TH1D*>the_hists_pass,std::vector<TH1D*>the_hists_fail);
  void drawPlot();
  inline void setPlotDir(TString dir="./"){theDir = dir;}
  double eff_err(double num, double denom);
  //constructor
  slowPionStudy(TString name, RooWorkspace* w=0);
  //destructor
  ~slowPionStudy();
  
 private:
  TString mName;
  TString theDir;
  RooWorkspace* wLocal;
  std::vector<TH1D*> hists_pos_pass;
  std::vector<TH1D*> hists_neg_pass;
  std::vector<TH1D*> hists_pos_fail;
  std::vector<TH1D*> hists_neg_fail;
  std::vector<double> nsig_pos_pass;
  std::vector<double> nsig_neg_pass;
  std::vector<double> nsig_pos_fail;
  std::vector<double> nsig_neg_fail;

  std::vector<double> nsigErr_pos_pass;
  std::vector<double> nsigErr_neg_pass;
  std::vector<double> nsigErr_pos_fail;
  std::vector<double> nsigErr_neg_fail;
  TGraphErrors* the_eff_plot_pos;
  TGraphErrors* the_bkg_rej_plot_pos;
  TGraphErrors* the_eff_plot_neg;
  TGraphErrors* the_bkg_rej_plot_neg;
};

#endif
