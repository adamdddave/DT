#ifndef COMPLETE_ANALYSIS_BETASTAR_PLOT_H 
#define COMPLETE_ANALYSIS_BETASTAR_PLOT_H 1

// Include files
#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TString.h>
#include <TVectorD.h>
//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include <RooWorkspace.h>

using namespace RooFit ;
/** @class betastar_plot betastar_plot.h complete_analysis/betastar_plot.h
 *  
 *
 *  @author Adam Davis
 *  @date   2015-01-24
 */
class betastar_plot {
public: 
  /// Standard constructor
  betastar_plot(TString name = "" );
  //secondary constructor
  betastar_plot(TFile *f1, TString name);
  //constructor to take out background
  betastar_plot(TFile *f1,TFile* fbkg, TString name);
  ~betastar_plot( ); ///< Destructor
  void DrawPlots();
  void makefitplot(RooWorkspace*w, TH1* h1, TH1* h2);//template for total peaking fit and signal
  void makefitplot(RooWorkspace*w, TH1* h1, int addpol = 0);//template for individual peaking
  std::vector<double> makefitplotretvals(RooWorkspace*w,TH1* h1, int addpol = 0);//template for fitting peaking bkg and return signal values.
  inline void set_local_workspace(RooWorkspace*w){w_local=w;}
  void SavePlots();
  void FitWSDoubleMisID();
  void FitWSDoubleMisIDTimeDependence();
  std::vector<double> extractWSDoubleMisIDLiang(TH1* h,TString extraName="");//to implement
  //void FitForPeakingBkg();
  double getErrorFromPropagation(RooRealVar* x, RooAbsPdf* model, RooFitResult* fr, RooDataHist* data,Double_t xmin, Double_t xmax, Double_t sig_min, Double_t sig_max,bool linearfit=false);
  double ErrorFromTF1(TF1* f1,Int_t npars, double* pars, const double* epars,TMatrixDSym mat,double sb_low_min, double sb_low_max, double sb_hi_min, double sb_hi_max,double sig_min, double sig_max);
  void FitWSDoubleMisIDLiang();
  TH2* h2tot;//total betastar plot
  TH2* h2sig ;
  TH2* h2kpisb ;
  TH2* h2kpisb_hi ;
  TH2* h2kpisb_lo ;
  TH2* h2kksb ;
  TH2* h2pipisb ;
  TH2* h2piksb ;
  TH2* h2rob ;
  TH2* h2kpisb_cut_range ;

  //stuff just for background drawing.
  TH2* h2sig_bkg ;
  TH2* h2tot_bkg ;
  TH2* h2kpisb_bkg ;
  TH2* h2kpisb_hi_bkg ;
  TH2* h2kpisb_lo_bkg ;
  TH2* h2kksb_bkg ;
  TH2* h2pipisb_bkg ;
  TH2* h2piksb_bkg ;
  TH2* h2rob_bkg ;
  
  
  TH2* h2pi_probnnmu_dstar_sideband_high ;
  TH2* h2pi_probnnmu_dstar_sideband_low;
  TH2* h2k_probnnmu_dstar_sideband_high;
  TH2* h2k_probnnmu_dstar_sideband_low;
  TH2* h2pi_probnne_dstar_sideband_high;
  TH2* h2pi_probnne_dstar_sideband_low;
  TH2* h2k_probnne_dstar_sideband_high;
  TH2* h2k_probnne_dstar_sideband_low;
  
  TH1* hmsig ;
  TH1* hmkpisb ;
  TH1* hmkksb ;
  TH1* hmpipisb ;
  TH1* hmpiksb ;
  TH1* hmrob ;
  //these were initially from mike, and I didn't know what was going on.
  // repurposing these to be used as a peaking background check.
  //the ranges of these bins are in d0 mass from 1790 to d0m - 40 MeV (lo)
  //and d0m+40 MeV to 1940 (hi)
  //we by hand exclude the KK and pi pi D0 here.
  //the repurposing comes as we change the number of bins to 6 each from 2
  
  TH1* hmkpisb_cut_range ;
  TH1* hmkpisb_cut_range_hi ;
  TH1* hmkpisb_cut_range_lo ;
  
  TH1* hmkpisb_cut_range_hi_1 ;
  TH1* hmkpisb_cut_range_hi_2 ;
  TH1* hmkpisb_cut_range_hi_3 ;
  TH1* hmkpisb_cut_range_hi_4 ;
  TH1* hmkpisb_cut_range_hi_5 ;
  TH1* hmkpisb_cut_range_hi_6 ;

  TH1* hmkpisb_cut_range_lo_1 ;
  TH1* hmkpisb_cut_range_lo_2 ;
  TH1* hmkpisb_cut_range_lo_3 ;
  TH1* hmkpisb_cut_range_lo_4 ;
  TH1* hmkpisb_cut_range_lo_5 ;
  TH1* hmkpisb_cut_range_lo_6 ;
  //do the same split by charge
  TH1* hmkpisb_pos_cut_range_hi_1 ;
  TH1* hmkpisb_pos_cut_range_hi_2 ;
  TH1* hmkpisb_pos_cut_range_hi_3 ;
  TH1* hmkpisb_pos_cut_range_hi_4 ;
  TH1* hmkpisb_pos_cut_range_hi_5 ;
  TH1* hmkpisb_pos_cut_range_hi_6 ;

  TH1* hmkpisb_pos_cut_range_lo_1 ;
  TH1* hmkpisb_pos_cut_range_lo_2 ;
  TH1* hmkpisb_pos_cut_range_lo_3 ;
  TH1* hmkpisb_pos_cut_range_lo_4 ;
  TH1* hmkpisb_pos_cut_range_lo_5 ;
  TH1* hmkpisb_pos_cut_range_lo_6 ;
  //
  TH1* hmkpisb_neg_cut_range_hi_1 ;
  TH1* hmkpisb_neg_cut_range_hi_2 ;
  TH1* hmkpisb_neg_cut_range_hi_3 ;
  TH1* hmkpisb_neg_cut_range_hi_4 ;
  TH1* hmkpisb_neg_cut_range_hi_5 ;
  TH1* hmkpisb_neg_cut_range_hi_6 ;

  TH1* hmkpisb_neg_cut_range_lo_1 ;
  TH1* hmkpisb_neg_cut_range_lo_2 ;
  TH1* hmkpisb_neg_cut_range_lo_3 ;
  TH1* hmkpisb_neg_cut_range_lo_4 ;
  TH1* hmkpisb_neg_cut_range_lo_5 ;
  TH1* hmkpisb_neg_cut_range_lo_6 ;
  //time bins
    
  TH1* hmD0_pik_sig ;
  TH1* hmD0_pik_sb ;
  TH1* hmD0_pik_tot ;

  TH1* double_misid_dmass_dst_sig_region;
  TH1* double_misid_dmass_dst_sideband_region;
  TH1* double_misid_subtr;//final subtracted result.
  //time bins
  TH1* double_misid_dmass_dst_sig_region_bin1;
  TH1* double_misid_dmass_dst_sideband_region_bin1;
  TH1* double_misid_subtr_bin1;//final subtracted result.
  
  TH1* double_misid_dmass_dst_sig_region_bin2;
  TH1* double_misid_dmass_dst_sideband_region_bin2;
  TH1* double_misid_subtr_bin2;//final subtracted result.

  TH1* double_misid_dmass_dst_sig_region_bin3;
  TH1* double_misid_dmass_dst_sideband_region_bin3;
  TH1* double_misid_subtr_bin3;//final subtracted result.

  TH1* double_misid_dmass_dst_sig_region_bin4;
  TH1* double_misid_dmass_dst_sideband_region_bin4;
  TH1* double_misid_subtr_bin4;//final subtracted result.

  TH1* double_misid_dmass_dst_sig_region_bin5;
  TH1* double_misid_dmass_dst_sideband_region_bin5;
  TH1* double_misid_subtr_bin5;//final subtracted result.

  double  pik_background_subtraction_ratio_result;
protected:

private:
  RooWorkspace *w_local;
  TString m_name;
  double intf(double x, double p[],int n);
  double int2f(double x, double p[],int n);
};
#endif // COMPLETE_ANALYSIS_BETASTAR_PLOT_H
