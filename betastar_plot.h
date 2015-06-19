#ifndef COMPLETE_ANALYSIS_BETASTAR_PLOT_H 
#define COMPLETE_ANALYSIS_BETASTAR_PLOT_H 1

// Include files
#include <iostream>
#include <TH1.h>
#include <TH2.h>
#include <TString.h>
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

  virtual ~betastar_plot( ); ///< Destructor
  void DrawPlots();
  void makefitplot(RooWorkspace*w, TH1* h1, TH1* h2);//template for total peaking fit and signal
  void makefitplot(RooWorkspace*w, TH1* h1, int addpol = 0);//template for individual peaking
  inline void set_local_workspace(RooWorkspace*w){w_local=w;}
  
    
  TH2* h2sig ;
  TH2* h2kpisb ;
  TH2* h2kpisb_hi ;
  TH2* h2kpisb_lo ;
  TH2* h2kksb ;
  TH2* h2pipisb ;
  TH2* h2piksb ;
  TH2* h2rob ;
  TH2* h2kpisb_cut_range ;
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

  TH1* hmkpisb_cut_range ;
  TH1* hmkpisb_cut_range_hi ;
  TH1* hmkpisb_cut_range_lo ;
  TH1* hmkpisb_cut_range_hi_1 ;
  TH1* hmkpisb_cut_range_lo_1 ;
  TH1* hmkpisb_cut_range_hi_2 ;
  TH1* hmkpisb_cut_range_lo_2 ;
  TH1* hmD0_pik_sig ;
  TH1* hmD0_pik_sb ;
  TH1* hmD0_pik_tot ;

  TH1* double_misid_dmass_dst_sig_region;
  TH1* double_misid_dmass_dst_sideband_region;
  
protected:

private:
  RooWorkspace *w_local;
  TString m_name;

};
#endif // COMPLETE_ANALYSIS_BETASTAR_PLOT_H
