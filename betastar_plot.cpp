// Include files 
#include <iostream>
#include <TCanvas.h>
#include <TPad.h>
#include <TFile.h>
#include <TStyle.h>
#include <TPaveText.h>
#include <TF1.h>
// local
#include "betastar_plot.h"
//root
#include <TBox.h>
//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
#include "RooCFunction1Binding.h"
#include "RooCFunction3Binding.h"
#endif
#include <RooFitResult.h>
#include <RooProduct.h>
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
#include <TFitResult.h>
#include <TVectorD.h>
#include <RooPlot.h>
#include <RooHist.h>
#include <RooDataHist.h>
#include <RooExponential.h>
#include <RooBinning.h>
#include <RooDstD0BG.h>
#include <RooNLLVar.h>
#include <RooChebychev.h>
#include <RooPolynomial.h>
#include <RooExtendPdf.h>
#include <RooWorkspace.h>
#include <RooTFnBinding.h>

#include <PlottingTools.h>
using namespace RooFit ;

//-----------------------------------------------------------------------------
// Implementation file for class : betastar_plot
//
// 2015-01-24 : Adam Davis
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
betastar_plot::betastar_plot(TString name  ) {
  m_name =name.ReplaceAll("/DecayTree","");
  std::cout<<"constructin betastar_plot with name "<<m_name<<std::endl;
  
  h2sig = new TH2D(name+"_h2sig","",200,-1.,1.,200,1.2,2.0);
  h2tot = new TH2D(name+"_h2tot","",200,-1.,1.,200,1.2,2.0);
   h2kpisb = (TH2*)h2sig->Clone(name+"_h2kpisb");
  
   h2kpisb_hi = (TH2*)h2sig->Clone(name+"_h2kpisb_hi");
   h2kpisb_lo = (TH2*)h2sig->Clone(name+"_h2kpisb_lo");
  
   h2kksb = (TH2*)h2sig->Clone(name+"_h2kksb");
   h2pipisb = (TH2*)h2sig->Clone(name+"_h2pipisb");
   h2piksb = (TH2*)h2sig->Clone(name+"_h2piksb");
   h2rob = (TH2*)h2sig->Clone(name+"_h2rob");
   h2kpisb_cut_range = (TH2*)h2sig->Clone(name+"_h2kpisb_cut_range");
  
   h2pi_probnnmu_dstar_sideband_high = new TH2D(name+"_h2pi_probnnmu_dstar_sideband_high","",1000,0,1,250,2000,2025);
   h2pi_probnnmu_dstar_sideband_low=new TH2D(name+"_h2pi_probnnmu_dstar_sideband_low","",1000,0,1,250,2000,2025);
    
   h2k_probnnmu_dstar_sideband_high=new TH2D(name+"_h2k_probnnmu_dstar_sideband_high","",1000,0,1,250,2000,2025);
   h2k_probnnmu_dstar_sideband_low=new TH2D(name+"_h2k_probnnmu_dstar_sideband_low","",1000,0,1,250,2000,2025);    
  
   h2pi_probnne_dstar_sideband_high=new TH2D(name+"_h2pi_probnne_dstar_sideband_high","",1000,0,1,250,2000,2025);
   h2pi_probnne_dstar_sideband_low=new TH2D(name+"_h2pi_probnne_dstar_sideband_low","",1000,0,1,250,2000,2025);
  
   h2k_probnne_dstar_sideband_high=new TH2D(name+"_h2k_probnne_dstar_sideband_high","",1000,0,1,250,2000,2025);
   h2k_probnne_dstar_sideband_low=new TH2D(name+"_h2k_probnne_dstar_sideband_low","",1000,0,1,250,2000,2025);    
  
   hmsig = new TH1D(name+"_hmsig","", 250, 2000, 2025);
   hmkpisb = (TH1*)hmsig->Clone(name+"_hmkpisb");
   hmkksb = (TH1*)hmsig->Clone(name+"_hmkksb");
   hmpipisb =(TH1*) hmsig->Clone(name+"_hmpipisb");
   hmpiksb = (TH1*)hmsig->Clone(name+"_hmpiksb");
   hmrob = (TH1*)hmsig->Clone(name+"_hmrob");

   hmkpisb_cut_range = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range");
   hmkpisb_cut_range_hi = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_hi");
   hmkpisb_cut_range_lo = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_lo");

   hmkpisb_cut_range_hi_1 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_hi_1");
   hmkpisb_cut_range_hi_2 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_hi_2");
   hmkpisb_cut_range_hi_3 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_hi_3");
   hmkpisb_cut_range_hi_4 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_hi_4");
   hmkpisb_cut_range_hi_5 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_hi_5");
   hmkpisb_cut_range_hi_6 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_hi_6");

   
   hmkpisb_cut_range_lo_1 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_lo_1");
   hmkpisb_cut_range_lo_2 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_lo_2");
   hmkpisb_cut_range_lo_3 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_lo_3");
   hmkpisb_cut_range_lo_4 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_lo_4");
   hmkpisb_cut_range_lo_5 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_lo_5");
   hmkpisb_cut_range_lo_6 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_lo_6");

    
    
   hmD0_pik_sig = new TH1D(name+"_hmD0_pik_sig","D^{0}->#pi K mass, #Delta M signal range; m(#pi K)[MeV];",200, 1700,2100);
   hmD0_pik_sb = new TH1D(name+"_hmD0_pik_sb","D^{0}->#pi K mass, #Delta M sideband; m(#pi K)[MeV];",200, 1700,2100);
   hmD0_pik_tot = new TH1D(name+"_hmD0_pik","D^{0}->#pi K mass, #Delta M unaltered; m(#pi K)[MeV];",200, 1700,2100);

   double_misid_dmass_dst_sig_region = new TH1D(name+"_double_misid_dmass_dst_sig_region","",200,1700,2100);
   double_misid_dmass_dst_sideband_region = new TH1D(name+"_double_misid_dmass_dst_sideband_region","",200,1700,2100);
   //clone these histograms in 5 bins of decay time.
   double_misid_dmass_dst_sig_region_bin1 = (TH1*)double_misid_dmass_dst_sig_region->Clone(name+"_double_misid_dmass_dst_sig_region_bin1");
   double_misid_dmass_dst_sideband_region_bin1 = (TH1*)double_misid_dmass_dst_sideband_region->Clone(name+"_double_misid_dmass_dst_sideband_region_bin1");

   double_misid_dmass_dst_sig_region_bin2 = (TH1*)double_misid_dmass_dst_sig_region->Clone(name+"_double_misid_dmass_dst_sig_region_bin2");
   double_misid_dmass_dst_sideband_region_bin2 = (TH1*)double_misid_dmass_dst_sideband_region->Clone(name+"_double_misid_dmass_dst_sideband_region_bin2");

   double_misid_dmass_dst_sig_region_bin3 = (TH1*)double_misid_dmass_dst_sig_region->Clone(name+"_double_misid_dmass_dst_sig_region_bin3");
   double_misid_dmass_dst_sideband_region_bin3 = (TH1*)double_misid_dmass_dst_sideband_region->Clone(name+"_double_misid_dmass_dst_sideband_region_bin3");
   
   double_misid_dmass_dst_sig_region_bin4 = (TH1*)double_misid_dmass_dst_sig_region->Clone(name+"_double_misid_dmass_dst_sig_region_bin4");
   double_misid_dmass_dst_sideband_region_bin4 = (TH1*)double_misid_dmass_dst_sideband_region->Clone(name+"_double_misid_dmass_dst_sideband_region_bin4");

   double_misid_dmass_dst_sig_region_bin5 = (TH1*)double_misid_dmass_dst_sig_region->Clone(name+"_double_misid_dmass_dst_sig_region_bin5");
   double_misid_dmass_dst_sideband_region_bin5 = (TH1*)double_misid_dmass_dst_sideband_region->Clone(name+"_double_misid_dmass_dst_sideband_region_bin5");

}
//=============================================================================
// Secondary constructor from root file
//=============================================================================

betastar_plot::betastar_plot(TFile *file, TString name) {
  m_name = name;
  std::cout<<"Looking for file "<<m_name<<"_h2sig"<<std::endl;
  h2sig=(TH2*)file->Get(m_name+"_h2sig");
  h2tot=(TH2*)file->Get(m_name+"_h2tot");
  h2kpisb=(TH2*)file->Get(m_name+"_h2kpisb");
  h2kpisb_hi=(TH2*)file->Get(m_name+"_h2kpisb_hi");
  h2kpisb_lo=(TH2*)file->Get(m_name+"_h2kpisb_lo");
  h2kksb=(TH2*)file->Get(m_name+"_h2kksb");
  h2pipisb=(TH2*)file->Get(m_name+"_h2pipisb");
  h2piksb=(TH2*)file->Get(m_name+"_h2piksb");
  h2rob=(TH2*)file->Get(m_name+"_h2rob");
  h2kpisb_cut_range=(TH2*)file->Get(m_name+"_h2kpisb_cut_range");
  h2pi_probnnmu_dstar_sideband_high=(TH2*)file->Get(m_name+"_h2pi_probnnmu_dstar_sideband_high");
  h2pi_probnnmu_dstar_sideband_low=(TH2*)file->Get(m_name+"_h2pi_probnnmu_dstar_sideband_low");
  h2k_probnnmu_dstar_sideband_high=(TH2*)file->Get(m_name+"_h2k_probnnmu_dstar_sideband_high");
  h2k_probnnmu_dstar_sideband_low=(TH2*)file->Get(m_name+"_h2k_probnnmu_dstar_sideband_low");
  h2pi_probnne_dstar_sideband_high=(TH2*)file->Get(m_name+"_h2pi_probnne_dstar_sideband_high");
  h2pi_probnne_dstar_sideband_low=(TH2*)file->Get(m_name+"_h2pi_probnne_dstar_sideband_low");
  h2k_probnne_dstar_sideband_high=(TH2*)file->Get(m_name+"_h2k_probnne_dstar_sideband_high");
  h2k_probnne_dstar_sideband_low=(TH2*)file->Get(m_name+"_h2k_probnne_dstar_sideband_low");
  
  hmsig=(TH1*)file->Get(m_name+"_hmsig");
  hmkpisb=(TH1*)file->Get(m_name+"_hmkpisb");
  hmkksb=(TH1*)file->Get(m_name+"_hmkksb");
  hmpipisb=(TH1*)file->Get(m_name+"_hmpipisb");
  hmpiksb=(TH1*)file->Get(m_name+"_hmpiksb");
  hmrob=(TH1*)file->Get(m_name+"_hmrob");

  hmkpisb_cut_range=(TH1*)file->Get(m_name+"_hmkpisb_cut_range");
  hmkpisb_cut_range_hi=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_hi");
  hmkpisb_cut_range_lo=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_lo");
  hmkpisb_cut_range_hi_1=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_hi_1");
  hmkpisb_cut_range_hi_2=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_hi_2");
  hmkpisb_cut_range_hi_3=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_hi_3");
  hmkpisb_cut_range_hi_4=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_hi_4");
  hmkpisb_cut_range_hi_5=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_hi_5");
  hmkpisb_cut_range_hi_6=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_hi_6");
  
  hmkpisb_cut_range_lo_1=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_lo_1");
  hmkpisb_cut_range_lo_2=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_lo_2");
  hmkpisb_cut_range_lo_3=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_lo_3");
  hmkpisb_cut_range_lo_4=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_lo_4");
  hmkpisb_cut_range_lo_5=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_lo_5");
  hmkpisb_cut_range_lo_6=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_lo_6");
  
  hmD0_pik_sig=(TH1*)file->Get(m_name+"_hmD0_pik_sig");
  hmD0_pik_sb=(TH1*)file->Get(m_name+"_hmD0_pik_sb");
  hmD0_pik_tot=(TH1*)file->Get(m_name+"_hmD0_pik");

  double_misid_dmass_dst_sig_region = (TH1*)file->Get(name+"_double_misid_dmass_dst_sig_region");
  double_misid_dmass_dst_sideband_region = (TH1*)file->Get(name+"_double_misid_dmass_dst_sideband_region");

  double_misid_dmass_dst_sig_region_bin1 = (TH1*)file->Get(name+"_double_misid_dmass_dst_sig_region_bin1");
  double_misid_dmass_dst_sig_region_bin2 = (TH1*)file->Get(name+"_double_misid_dmass_dst_sig_region_bin2");
  double_misid_dmass_dst_sig_region_bin3 = (TH1*)file->Get(name+"_double_misid_dmass_dst_sig_region_bin3");
  double_misid_dmass_dst_sig_region_bin4 = (TH1*)file->Get(name+"_double_misid_dmass_dst_sig_region_bin4");
  double_misid_dmass_dst_sig_region_bin5 = (TH1*)file->Get(name+"_double_misid_dmass_dst_sig_region_bin5");

  double_misid_dmass_dst_sideband_region_bin1 = (TH1*)file->Get(name+"_double_misid_dmass_dst_sideband_region_bin1");
  double_misid_dmass_dst_sideband_region_bin2 = (TH1*)file->Get(name+"_double_misid_dmass_dst_sideband_region_bin2");
  double_misid_dmass_dst_sideband_region_bin3 = (TH1*)file->Get(name+"_double_misid_dmass_dst_sideband_region_bin3");
  double_misid_dmass_dst_sideband_region_bin4 = (TH1*)file->Get(name+"_double_misid_dmass_dst_sideband_region_bin4");
  double_misid_dmass_dst_sideband_region_bin5 = (TH1*)file->Get(name+"_double_misid_dmass_dst_sideband_region_bin5");
}
//
//=============================================================================
// tertiary constructor from root file for signal and background
//=============================================================================

betastar_plot::betastar_plot(TFile *f1, TFile* fbkg,TString name) {
  m_name = name;
  std::cout<<"Looking for file "<<m_name<<"_h2sig"<<std::endl;
  h2sig=(TH2*)f1->Get(m_name+"_h2sig");
  h2tot=(TH2*)f1->Get(m_name+"_h2tot");
  h2kpisb=(TH2*)f1->Get(m_name+"_h2kpisb");
  h2kpisb_hi=(TH2*)f1->Get(m_name+"_h2kpisb_hi");
  h2kpisb_lo=(TH2*)f1->Get(m_name+"_h2kpisb_lo");
  h2kksb=(TH2*)f1->Get(m_name+"_h2kksb");
  h2pipisb=(TH2*)f1->Get(m_name+"_h2pipisb");
  h2piksb=(TH2*)f1->Get(m_name+"_h2piksb");
  h2rob=(TH2*)f1->Get(m_name+"_h2rob");
  h2kpisb_cut_range=(TH2*)f1->Get(m_name+"_h2kpisb_cut_range");
  h2pi_probnnmu_dstar_sideband_high=(TH2*)f1->Get(m_name+"_h2pi_probnnmu_dstar_sideband_high");
  h2pi_probnnmu_dstar_sideband_low=(TH2*)f1->Get(m_name+"_h2pi_probnnmu_dstar_sideband_low");
  h2k_probnnmu_dstar_sideband_high=(TH2*)f1->Get(m_name+"_h2k_probnnmu_dstar_sideband_high");
  h2k_probnnmu_dstar_sideband_low=(TH2*)f1->Get(m_name+"_h2k_probnnmu_dstar_sideband_low");
  h2pi_probnne_dstar_sideband_high=(TH2*)f1->Get(m_name+"_h2pi_probnne_dstar_sideband_high");
  h2pi_probnne_dstar_sideband_low=(TH2*)f1->Get(m_name+"_h2pi_probnne_dstar_sideband_low");
  h2k_probnne_dstar_sideband_high=(TH2*)f1->Get(m_name+"_h2k_probnne_dstar_sideband_high");
  h2k_probnne_dstar_sideband_low=(TH2*)f1->Get(m_name+"_h2k_probnne_dstar_sideband_low");
  
  hmsig=(TH1*)f1->Get(m_name+"_hmsig");
  hmkpisb=(TH1*)f1->Get(m_name+"_hmkpisb");
  hmkksb=(TH1*)f1->Get(m_name+"_hmkksb");
  hmpipisb=(TH1*)f1->Get(m_name+"_hmpipisb");
  hmpiksb=(TH1*)f1->Get(m_name+"_hmpiksb");
  hmrob=(TH1*)f1->Get(m_name+"_hmrob");

  hmkpisb_cut_range=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range");
  hmkpisb_cut_range_hi=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_hi");
  hmkpisb_cut_range_lo=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_lo");
  hmkpisb_cut_range_hi_1=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_hi_1");
  hmkpisb_cut_range_hi_2=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_hi_2");
  hmkpisb_cut_range_hi_3=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_hi_3");
  hmkpisb_cut_range_hi_4=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_hi_4");
  hmkpisb_cut_range_hi_5=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_hi_5");
  hmkpisb_cut_range_hi_6=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_hi_6");
  
  hmkpisb_cut_range_lo_1=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_lo_1");
  hmkpisb_cut_range_lo_2=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_lo_2");
  hmkpisb_cut_range_lo_3=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_lo_3");
  hmkpisb_cut_range_lo_4=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_lo_4");
  hmkpisb_cut_range_lo_5=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_lo_5");
  hmkpisb_cut_range_lo_6=(TH1*)f1->Get(m_name+"_hmkpisb_cut_range_lo_6");
  
  hmD0_pik_sig=(TH1*)f1->Get(m_name+"_hmD0_pik_sig");
  hmD0_pik_sb=(TH1*)f1->Get(m_name+"_hmD0_pik_sb");
  hmD0_pik_tot=(TH1*)f1->Get(m_name+"_hmD0_pik");

  double_misid_dmass_dst_sig_region = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sig_region");
  double_misid_dmass_dst_sideband_region = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sideband_region");

  double_misid_dmass_dst_sig_region_bin1 = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sig_region_bin1");
  double_misid_dmass_dst_sig_region_bin2 = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sig_region_bin2");
  double_misid_dmass_dst_sig_region_bin3 = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sig_region_bin3");
  double_misid_dmass_dst_sig_region_bin4 = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sig_region_bin4");
  double_misid_dmass_dst_sig_region_bin5 = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sig_region_bin5");

  double_misid_dmass_dst_sideband_region_bin1 = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sideband_region_bin1");
  double_misid_dmass_dst_sideband_region_bin2 = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sideband_region_bin2");
  double_misid_dmass_dst_sideband_region_bin3 = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sideband_region_bin3");
  double_misid_dmass_dst_sideband_region_bin4 = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sideband_region_bin4");
  double_misid_dmass_dst_sideband_region_bin5 = (TH1*)f1->Get(m_name+"_double_misid_dmass_dst_sideband_region_bin5");
  cout<<"looking for background"<<endl;
  TString m_name_ss = m_name+"_ss";
  h2sig_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2sig");
  h2tot_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2tot");
  h2kpisb_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2kpisb");
  h2kpisb_hi_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2kpisb_hi");
  h2kpisb_lo_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2kpisb_lo");
  h2kksb_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2kksb");
  h2pipisb_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2pipisb");
  h2piksb_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2piksb");
  h2rob_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2rob");
  /*h2kpisb_cut_range_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2kpisb_cut_range");
  h2pi_probnnmu_dstar_sideband_high_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2pi_probnnmu_dstar_sideband_high");
  TH2* h2pi_probnnmu_dstar_sideband_low_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2pi_probnnmu_dstar_sideband_low");
  TH2* h2k_probnnmu_dstar_sideband_high_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2k_probnnmu_dstar_sideband_high");
  TH2* h2k_probnnmu_dstar_sideband_low_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2k_probnnmu_dstar_sideband_low");
  TH2* h2pi_probnne_dstar_sideband_high_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2pi_probnne_dstar_sideband_high");
  TH2* h2pi_probnne_dstar_sideband_low_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2pi_probnne_dstar_sideband_low");
  TH2* h2k_probnne_dstar_sideband_high_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2k_probnne_dstar_sideband_high");
  TH2* h2k_probnne_dstar_sideband_low_bkg=(TH2*)fbkg->Get(m_name_ss+"_h2k_probnne_dstar_sideband_low");
  */
  TH1* hmsig_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmsig");
  TH1* hmkpisb_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb");
  TH1* hmkksb_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkksb");
  TH1* hmpipisb_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmpipisb");
  TH1* hmpiksb_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmpiksb");
  TH1* hmrob_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmrob");

  TH1* hmkpisb_cut_range_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range");
  TH1* hmkpisb_cut_range_hi_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_hi");
  TH1* hmkpisb_cut_range_lo_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_lo");
  TH1* hmkpisb_cut_range_hi_1_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_hi_1");
  TH1* hmkpisb_cut_range_hi_2_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_hi_2");
  TH1* hmkpisb_cut_range_hi_3_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_hi_3");
  TH1* hmkpisb_cut_range_hi_4_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_hi_4");
  TH1* hmkpisb_cut_range_hi_5_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_hi_5");
  TH1* hmkpisb_cut_range_hi_6_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_hi_6");
  
  TH1* hmkpisb_cut_range_lo_1_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_lo_1");
  TH1* hmkpisb_cut_range_lo_2_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_lo_2");
  TH1* hmkpisb_cut_range_lo_3_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_lo_3");
  TH1* hmkpisb_cut_range_lo_4_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_lo_4");
  TH1* hmkpisb_cut_range_lo_5_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_lo_5");
  TH1* hmkpisb_cut_range_lo_6_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmkpisb_cut_range_lo_6");
  
  TH1* hmD0_pik_sig_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmD0_pik_sig");
  TH1* hmD0_pik_sb_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmD0_pik_sb");
  TH1* hmD0_pik_tot_bkg=(TH1*)fbkg->Get(m_name_ss+"_hmD0_pik");

  TH1* double_misid_dmass_dst_sig_region_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sig_region");
  TH1* double_misid_dmass_dst_sideband_region_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sideband_region");

  TH1* double_misid_dmass_dst_sig_region_bin1_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sig_region_bin1");
  TH1* double_misid_dmass_dst_sig_region_bin2_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sig_region_bin2");
  TH1* double_misid_dmass_dst_sig_region_bin3_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sig_region_bin3");
  TH1* double_misid_dmass_dst_sig_region_bin4_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sig_region_bin4");
  TH1* double_misid_dmass_dst_sig_region_bin5_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sig_region_bin5");

  TH1* double_misid_dmass_dst_sideband_region_bin1_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sideband_region_bin1");
  TH1* double_misid_dmass_dst_sideband_region_bin2_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sideband_region_bin2");
  TH1* double_misid_dmass_dst_sideband_region_bin3_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sideband_region_bin3");
  TH1* double_misid_dmass_dst_sideband_region_bin4_bkg= (TH1*)fbkg->Get(m_name_ss+"_double_misid_dmass_dst_sideband_region_bin4");
  TH1* double_misid_dmass_dst_sideband_region_bin5_bkg= (TH1*)fbkg->Get(m_name+"_double_misid_dmass_dst_sideband_region_bin5");
  //do bkg subtraction
  /*
  h2sig->Add(h2sig_bkg,-1);
  h2kpisb->Add(h2kpisb_bkg,-1);
  h2kpisb_hi->Add(h2kpisb_hi_bkg,-1);
  h2kpisb_lo->Add(h2kpisb_lo_bkg,-1);
  h2kksb->Add(h2kksb_bkg,-1);
  h2pipisb->Add(h2pipisb_bkg,-1);
  h2piksb->Add(h2piksb_bkg,-1);
  h2rob->Add(h2rob_bkg,-1);
  h2kpisb_cut_range->Add(h2kpisb_cut_range_bkg,-1);
  h2pi_probnnmu_dstar_sideband_high->Add(h2pi_probnnmu_dstar_sideband_high_bkg,-1);
  h2pi_probnnmu_dstar_sideband_low->Add(h2pi_probnnmu_dstar_sideband_low_bkg,-1);
  h2k_probnnmu_dstar_sideband_high->Add(h2k_probnnmu_dstar_sideband_high_bkg,-1);
  h2k_probnnmu_dstar_sideband_low->Add(h2k_probnnmu_dstar_sideband_low_bkg,-1);
  h2pi_probnne_dstar_sideband_high->Add(h2pi_probnne_dstar_sideband_high_bkg,-1);
  h2pi_probnne_dstar_sideband_low->Add(h2pi_probnne_dstar_sideband_low_bkg,-1);
  h2k_probnne_dstar_sideband_high->Add(h2k_probnne_dstar_sideband_high_bkg,-1);
  h2k_probnne_dstar_sideband_low->Add(h2k_probnne_dstar_sideband_low_bkg,-1);
  */
  hmsig->Add(hmsig_bkg,-1);
  hmkpisb->Add(hmkpisb_bkg,-1);
  hmkksb->Add(hmkksb_bkg,-1);
  hmpipisb->Add(hmpipisb_bkg,-1);
  hmpiksb->Add(hmpiksb_bkg,-1);
  hmrob->Add(hmrob_bkg,-1);

  hmkpisb_cut_range->Add(hmkpisb_cut_range_bkg,-1);
  hmkpisb_cut_range_hi->Add(hmkpisb_cut_range_hi_bkg,-1);
  hmkpisb_cut_range_lo->Add(hmkpisb_cut_range_lo_bkg,-1);
  hmkpisb_cut_range_hi_1->Add(hmkpisb_cut_range_hi_1_bkg,-1);
  hmkpisb_cut_range_hi_2->Add(hmkpisb_cut_range_hi_2_bkg,-1);
  hmkpisb_cut_range_hi_3->Add(hmkpisb_cut_range_hi_3_bkg,-1);
  hmkpisb_cut_range_hi_4->Add(hmkpisb_cut_range_hi_4_bkg,-1);
  hmkpisb_cut_range_hi_5->Add(hmkpisb_cut_range_hi_5_bkg,-1);
  hmkpisb_cut_range_hi_6->Add(hmkpisb_cut_range_hi_6_bkg,-1);
  
  hmkpisb_cut_range_lo_1->Add(hmkpisb_cut_range_lo_1_bkg,-1);
  hmkpisb_cut_range_lo_2->Add(hmkpisb_cut_range_lo_2_bkg,-1);
  hmkpisb_cut_range_lo_3->Add(hmkpisb_cut_range_lo_3_bkg,-1);
  hmkpisb_cut_range_lo_4->Add(hmkpisb_cut_range_lo_4_bkg,-1);
  hmkpisb_cut_range_lo_5->Add(hmkpisb_cut_range_lo_5_bkg,-1);
  hmkpisb_cut_range_lo_6->Add(hmkpisb_cut_range_lo_6_bkg,-1);
  
  hmD0_pik_sig->Add(hmD0_pik_sig_bkg,-1);
  hmD0_pik_sb->Add(hmD0_pik_sb_bkg,-1);
  hmD0_pik_tot->Add(hmD0_pik_tot_bkg,-1);

  double_misid_dmass_dst_sig_region->Add(double_misid_dmass_dst_sig_region_bkg,-1);
  double_misid_dmass_dst_sideband_region->Add(double_misid_dmass_dst_sideband_region_bkg,-1);

  double_misid_dmass_dst_sig_region_bin1->Add(double_misid_dmass_dst_sig_region_bin1_bkg,-1);
  double_misid_dmass_dst_sig_region_bin2->Add(double_misid_dmass_dst_sig_region_bin2_bkg,-1);
  double_misid_dmass_dst_sig_region_bin3->Add(double_misid_dmass_dst_sig_region_bin3_bkg,-1);
  double_misid_dmass_dst_sig_region_bin4->Add(double_misid_dmass_dst_sig_region_bin4_bkg,-1);
  double_misid_dmass_dst_sig_region_bin5->Add(double_misid_dmass_dst_sig_region_bin5_bkg,-1);

  double_misid_dmass_dst_sideband_region_bin1->Add(double_misid_dmass_dst_sideband_region_bin1_bkg,-1);
  double_misid_dmass_dst_sideband_region_bin2->Add(double_misid_dmass_dst_sideband_region_bin2_bkg,-1);
  double_misid_dmass_dst_sideband_region_bin3->Add(double_misid_dmass_dst_sideband_region_bin3_bkg,-1);
  double_misid_dmass_dst_sideband_region_bin4->Add(double_misid_dmass_dst_sideband_region_bin4_bkg,-1);
  double_misid_dmass_dst_sideband_region_bin5->Add(double_misid_dmass_dst_sideband_region_bin5_bkg,-1);
}
//=============================================================================
// Destructor
//=============================================================================
betastar_plot::~betastar_plot() {
  delete h2sig ;
  delete h2tot;
  delete h2kpisb ;
  delete h2kpisb_hi ;
  delete h2kpisb_lo ;
  delete h2kksb ;
  delete h2pipisb ;
  delete h2piksb ;
  delete h2rob ;
  delete h2kpisb_cut_range ;
  delete h2pi_probnnmu_dstar_sideband_high ;
  delete h2pi_probnnmu_dstar_sideband_low;
  delete h2k_probnnmu_dstar_sideband_high;
  delete h2k_probnnmu_dstar_sideband_low;
  delete h2pi_probnne_dstar_sideband_high;
  delete h2pi_probnne_dstar_sideband_low;
  delete h2k_probnne_dstar_sideband_high;
  delete h2k_probnne_dstar_sideband_low;
  
  delete hmsig ;
  delete hmkpisb ;
  delete hmkksb ;
  delete hmpipisb ;
  delete hmpiksb ;
  delete hmrob ;

  delete hmkpisb_cut_range ;
  delete hmkpisb_cut_range_hi ;
  delete hmkpisb_cut_range_lo ;
  delete hmkpisb_cut_range_hi_1 ;
  delete hmkpisb_cut_range_hi_2 ;
  delete hmkpisb_cut_range_hi_3 ;
  delete hmkpisb_cut_range_hi_4 ;
  delete hmkpisb_cut_range_hi_5 ;
  delete hmkpisb_cut_range_hi_6 ;
  delete hmkpisb_cut_range_lo_1 ;
  delete hmkpisb_cut_range_lo_2 ;
  delete hmkpisb_cut_range_lo_3 ;
  delete hmkpisb_cut_range_lo_4 ;
  delete hmkpisb_cut_range_lo_5 ;
  delete hmkpisb_cut_range_lo_6 ;
  delete hmD0_pik_sig ;
  delete hmD0_pik_sb ;
  delete hmD0_pik_tot ;

  delete double_misid_dmass_dst_sig_region;
  delete double_misid_dmass_dst_sideband_region;
  delete double_misid_subtr;//final subtracted result.


} 

//=============================================================================
//Draw the plots and save them.
//=============================================================================
void betastar_plot::DrawPlots(){
  
  //    TCanvas * cc = new TCanvas();
    // hmsig->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_signal_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_signal_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb_cut_range->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_cut_range.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_cut_range_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();


    // hmkksb->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kk_signal_kpi_sideband_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kk_signal_kpi_sideband_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();


    // hmpipisb->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"pipi_signal_kpi_sideband_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"pipi_signal_kpi_sideband_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();
            

    // hmpiksb->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"pik_signal_kpi_sideband_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"pik_signal_kpi_sideband_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmrob->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_not_signal_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_not_signal_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();
    
    // //if(doD0plots){
    //   hmD0_pik_tot->Draw();
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_total.pdf");
    //   cc->SetLogy(true);
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_total_logy.pdf");
    //   cc->SetLogy(false);
    //   cc->Clear();
      
    //   hmD0_pik_sig->Draw();
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_signal_dstar.pdf");
    //   cc->SetLogy(true);
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_signal_dstar_logy.pdf");
    //   cc->SetLogy(false);
    //   cc->Clear();
      
      
    //   hmD0_pik_sb->Draw();
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_sideband_dstar.pdf");
    //   cc->SetLogy(true);
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_sideband_dstar_logy.pdf");
    //   cc->SetLogy(false);
    //   cc->Clear();
    //   //}
    
    // hmkpisb_cut_range_hi->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb_cut_range_lo->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb_cut_range_hi_1->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi_1.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi_1_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb_cut_range_hi_2->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi_2.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi_2_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();
    

    // hmkpisb_cut_range_lo_1->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo_1.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo_1_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb_cut_range_lo_2->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo_2.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo_2_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();    

    //delete cc;

    // TFile *the_outfile = new TFile("./betastar_sidebands.root","RECREATE");
    // the_outfile->cd();
    // h2sig->Write();
    // h2kpisb->Write();
    // h2kksb->Write();
    // h2pipisb->Write();
    // h2piksb->Write();
    // h2rob->Write();
    // h2kpisb_cut_range->Write();
    // h2pi_probnnmu_dstar_sideband_high->Write();
    // h2pi_probnnmu_dstar_sideband_low->Write();
    // h2k_probnnmu_dstar_sideband_high->Write();
    // h2k_probnnmu_dstar_sideband_low->Write();
    // h2pi_probnne_dstar_sideband_high->Write();
    // h2pi_probnne_dstar_sideband_low->Write();
    // h2k_probnne_dstar_sideband_high->Write();
    // h2k_probnne_dstar_sideband_low->Write();
    // h2kpisb_hi->Write();
    // h2kpisb_lo->Write();
    
    
    
    // hmsig->Write();
    // hmkpisb->Write();
    // hmkksb->Write();
    // hmpipisb->Write();
    // hmpiksb->Write();
    // hmrob->Write();
    // hmkpisb_cut_range->Write();
    // hmD0_pik_tot->Write();
    // hmD0_pik_sig->Write();
    // hmD0_pik_sb->Write();
    // hmkpisb_cut_range_hi->Write();
    // hmkpisb_cut_range_lo->Write();
    // hmkpisb_cut_range_hi_1->Write();
    // hmkpisb_cut_range_lo_1->Write();
    // hmkpisb_cut_range_hi_2->Write();
    // hmkpisb_cut_range_lo_2->Write();
    

    // the_outfile->Close();
    

    h2sig->SetMarkerColor(kGreen+2);
    h2kpisb->SetMarkerColor(kRed);
    h2kksb->SetMarkerColor(kYellow+1);
    h2pipisb->SetMarkerColor(kBlue);
    h2piksb->SetMarkerColor(kMagenta);
    hmsig->SetLineColor(kGreen+2);
    hmkpisb->SetLineColor(kRed);
    hmkksb->SetLineColor(kYellow+1);
    hmpipisb->SetLineColor(kBlue);
    hmpiksb->SetLineColor(kMagenta);
    hmkpisb->SetLineColor(kRed);
    //
    /*h2sig_bkg->SetMarkerColor(kGreen+2);
    h2kpisb_bkg->SetMarkerColor(kRed);
    h2kksb_bkg->SetMarkerColor(kYellow+1);
    h2pipisb_bkg->SetMarkerColor(kBlue);
    h2piksb_bkg->SetMarkerColor(kMagenta);*/
    /*    hmsig_bkg->SetLineColor(kGreen+2);
    hmkpisb_bkg->SetLineColor(kRed);
    hmkksb_bkg->SetLineColor(kYellow+1);
    hmpipisb_bkg->SetLineColor(kBlue);
    hmpiksb_bkg->SetLineColor(kMagenta);
    hmkpisb_bkg->SetLineColor(kRed);
    */
    
    /*    hmkksb->SetLineColor(kYellow+1);
    hmpipisb->SetLineColor(kBlue);
    hmpiksb->SetLineColor(kMagenta);*/
    //setcanvas();
    TCanvas *cc_bg = new TCanvas();
    gStyle->SetOptStat(00);
    gStyle->SetTitleOffset(1.4,"y");
    h2tot->SetTitle(";#beta*; m(#pi#pi)[GeV]");
    h2tot->Draw("colz");
    cc_bg->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_tot_colz.pdf");
    cc_bg->SetLogz(true);
    cc_bg->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_tot_colz_logz.pdf");
    cc_bg->SetLogz(false);
    cc_bg->Clear();
    h2tot_bkg->SetTitle(";#beta*; m(#pi#pi)[GeV]");
    h2tot_bkg->Draw("colz");
    cc_bg->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_ss_bkg_tot_colz.pdf");
    cc_bg->SetLogz(true);
    cc_bg->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_ss_bkg_tot_colz_logz.pdf");
    cc_bg->SetLogz(false);
    cc_bg->Clear();
    /*
    h2sig_bkg->Draw();
    h2rob_bkg->Draw("same");
    h2kpisb->Draw("same");
    cc_bg->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_bkg_sig_sideband.pdf");
    cc_bg->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_bkg_sig_sideband.C");
    cc_bg->Clear();
    h2sig_bkg->Draw();
    h2rob_bkg->Draw("same");
    h2kksb_bkg->Draw("same");
    h2pipisb_bkg0>Draw("same");
    h2piksb->Draw("same");
    cc_bg->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_bkg_indiv_sb.pdf");
    cc_bg->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_bkg_indiv_sb.C");*/
    delete cc_bg;
    gStyle->SetOptStat(00);
    gStyle->SetTitleOffset(1.4,"y");
    TCanvas *cv = new TCanvas("cv", "", 1200, 400*3);
    cv->Divide(2,3);
    cv->cd(1);
    h2sig->SetTitle(";#beta*;m(#pi#pi)[GeV]");
    h2sig->Draw();
    h2rob->Draw("same");
    h2kpisb->Draw("same");
    cv->cd(2);
    h2sig->Draw();
    h2rob->Draw("same");
    h2kksb->Draw("same");
    h2pipisb->Draw("same");
    h2piksb->Draw("same");
    hmsig->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / .2%f MeV",hmsig->GetBinWidth(1)));
    TPad* pad = (TPad*)cv->cd(3);
    pad->SetLogy(1);
    if(w_local!=NULL){makefitplot(w_local, hmsig, hmkpisb);}
    else{  
      hmsig->Draw("e");
      hmkpisb->Draw("esame");
    }
    hmpiksb->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / .2%f",hmpiksb->GetBinWidth(1)));
    cv->cd(4);
    if(w_local!=NULL){makefitplot(w_local, hmpiksb);}
    else{hmpiksb->Draw("e");}
    //
    cv->cd(5);
    hmkksb->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / .2%f",hmkksb->GetBinWidth(1)));
    if(w_local!=NULL){makefitplot(w_local, hmkksb,1);}
    else{hmkksb->Draw("e");}
    //
    cv->cd(6);
    hmpipisb->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / .2%f",hmpipisb->GetBinWidth(1)));
    if(w_local!=NULL){makefitplot(w_local, hmpipisb,1);}
    else{hmpipisb->Draw("e");}
    
    //

    cv->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_figure.pdf");
    cv->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_figure.C");
    
    return;

    
}

void betastar_plot::makefitplot(RooWorkspace*w, TH1* h1, TH1* h2){
  RooRealVar *mass = w->var("dstarM"); 
  RooRealVar *nsig = w->var("nsig");
  RooRealVar *kappa = w->var("kappa");
  w->var("m0")->setConstant(1);
  w->var("delta")->setConstant(1);
  w->var("sigma")->setConstant(1);
  w->var("gamma")->setConstant(1);
  w->var("mean1")->setConstant(1);
  w->var("mean2")->setConstant(1);
  w->var("mean3")->setConstant(1);
  w->var("width1")->setConstant(1);
  w->var("width2")->setConstant(1);
  w->var("width3")->setConstant(1);
  w->var("frac1")->setConstant(1);
  w->var("frac2")->setConstant(1);
  w->var("frac3")->setConstant(1);
  
  kappa->setConstant(0);
  //RooRealVar *pn = w->var("n");
  //pn->setConstant(1);
  RooRealVar *endpt = w->var("endpt");
  RooRealVar *dmean = w->var("dmean");
  RooRealVar *rsigma = w->var("rsigma");
  dmean->setConstant(1); rsigma->setConstant(1);
  RooAbsPdf* allpdf = w->pdf("model");
 
  TString rhname("r_"); rhname += h1->GetName();
  RooDataHist *rhist = new RooDataHist(rhname.Data(), "", *mass, h1);
  RooFitResult *res = allpdf->fitTo(*rhist, RooFit::Save(),Extended(1));
  res->Print("v");
  RooAbsPdf* allpdf2 = NULL;
  RooDataHist* rhist2 = NULL;
  RooRealVar gmean("fmean", "", 2.01*1e3, 2.009*1e3,2.011*1e3);
  RooRealVar gsigma("gsigma", "", 0.001*1e3, 1e-5*1e3,1e-2*1e3);
  RooGaussian gau("gau", "", *mass, gmean, gsigma);
  RooRealVar gmean2("gmean2","",2010,2009,2011);
  RooRealVar gsigma2("gsigma2","",0.5,1e-3,1);
  RooGaussian gau2("gau2", "", *mass, gmean2, gsigma2);
  //make a crystal ball to try
  /*RooRealVar cbm0("cbm0","cbm0",2010,2009,2011);
  RooRealVar cbsigma("cbsigma","cbsigma",0.5,0.1,10);
  RooRealVar cbalpha("cbalpha","cbalpha",-0.2,-3,0.);//tail on the right
  RooRealVar cbn("cbn","cbn",1,0,3);
  RooCBShape cball("cball","cball",*mass,cbm0,cbsigma,cbalpha,cbn);*/
  RooRealVar fracGauPeak("fracGauPeak","",0.5,0.3,1.);
  RooRealVar xscale("xscale", "", 1, 1e-2, 10);
  xscale.setConstant(1);
  RooFormulaVar minusDM("minusDM", "@2-@1*(@0-@2)", RooArgList(*mass, xscale, *endpt));
  RooRealVar kappa2("kappa2", "argpar1", -3.8935e+01, -200., 0.);
  RooRealVar n("n", "", 0.5);
  RooArgusBG arg("bkg", "argus", minusDM, *endpt, kappa2, n);
  arg.forceNumInt(kTRUE);
  RooAbsPdf *gauAdd = new RooAddPdf("gauAdd","",RooArgList(gau,gau2),RooArgList(fracGauPeak));
  ///RooAbsPdf *gauAdd = new RooAddPdf("gauAdd","",RooArgList(gau,cball),RooArgList(fracGauPeak));
  RooRealVar nsig2("nsig2", "", 3e4, 0, 1e8);
  RooRealVar nbkg2("nbkg2", "", 1e3,0, 1e8);
  //allpdf2 = new RooAddPdf("allpdf2", "", RooArgList(gau,arg), RooArgList(nsig2,nbkg2));
  allpdf2 = new RooAddPdf("allpdf2", "", RooArgList(*gauAdd,arg), RooArgList(nsig2,nbkg2));
  
  rhname = "r_"; rhname += h2->GetName();
  rhist2 = new RooDataHist(rhname.Data(), "", *mass, h2);
  res = allpdf2->fitTo(*rhist2, RooFit::Save(),Extended(1));
  res->Print("v");
  //make pull plots just for good riddance
  // RooPlot* frame2 = mass->frame();
  // rhist2->plotOn(frame2);
  // allpdf2->plotOn(frame2);
  // PlottingTools::makeResidualPlotsLiang(frame2,*mass,*rhist2,allpdf2,"./SavedFits/betastar/peakingBkgFit",2000,2025);

  RooPlot *frame = mass->frame(RooFit::Range(h1->GetBinLowEdge(1), h1->GetBinLowEdge(h1->GetNbinsX()+1)));
  frame->SetTitle("");
  frame->SetXTitle(h1->GetXaxis()->GetTitle());
  frame->SetYTitle(h1->GetYaxis()->GetTitle());
  rhist->plotOn(frame);
  allpdf->plotOn(frame, RooFit::LineWidth(2), RooFit::LineColor(h1->GetLineColor()));
  allpdf->plotOn(frame, RooFit::Components("bkg"),RooFit::LineWidth(2), RooFit::LineStyle(kDashed), 
                 RooFit::LineColor(h1->GetLineColor()));
  rhist2->plotOn(frame);
  allpdf2->plotOn(frame, RooFit::LineWidth(2), RooFit::LineColor(h2->GetLineColor()));
  allpdf2->plotOn(frame, RooFit::Components("bkg"),RooFit::LineWidth(2), RooFit::LineStyle(kDashed), 
                  RooFit::LineColor(h2->GetLineColor()));
  allpdf2->plotOn(frame, RooFit::Components("gau"),RooFit::LineWidth(2), RooFit::LineStyle(kDotted), 
                  RooFit::LineColor(h2->GetLineColor()));
  allpdf2->plotOn(frame,RooFit::Components("gau2"),RooFit::LineColor(h2->GetLineColor()), RooFit::LineStyle(4));
  //allpdf2->plotOn(frame,RooFit::Components("cball"),RooFit::LineColor(kGreen+2));
  //frame->GetYaxis()->SetRangeUser(frame->GetYaxis()->GetXmin()/10, frame->GetYaxis()->GetXmax());
  frame->GetYaxis()->SetRangeUser(0.1,h1->GetMaximum()*1.5);
  //frame->GetYaxis()->SetRangeUser(h1->GetMinimum(),h1->GetMaximum());
  frame->Draw();

  TPaveText *txt = new TPaveText(0.7, 0.7, 0.98, 0.98, "ndc");
  txt->SetTextAlign(12);
  txt->AddText(TString::Format("N_{sig}: %d #pm %d", (int)nsig->getVal(), (int)nsig->getError()));
  txt->AddText(TString::Format("N_{peak}: %d #pm %d", (int)nsig2.getVal(), (int)nsig2.getError()));
  txt->Draw();


}

void betastar_plot::makefitplot(RooWorkspace*w, TH1* h1, int addpol){
  RooRealVar *mass = w->var("dstarM"); 
  RooRealVar *nsig = w->var("nsig");
  RooRealVar *kappa = w->var("kappa");
  kappa->setConstant(0);
  RooAbsPdf *arg = w->pdf("bkg");
  RooAbsPdf* allpdf = NULL;
  RooDataHist* rhist = NULL;
  RooRealVar gmean("fmean", "", 2.01*1e3, 2.009*1e3,2.011*1e3);
  RooRealVar gsigma("gsigma", "", 0.001*1e3, 1e-5*1e3,1e-2*1e3);
  RooGaussian gau("gau", "", *mass, gmean, gsigma);
  RooRealVar gmean2("fmean2", "", 2.01*1e3, 2.009*1e3,2.011*1e3);
  RooRealVar gsigma2("gsigma2", "", 0.001*1e3, 1e-5*1e3,1e-2*1e3);
  RooFormulaVar fgsigma("fgsigma", "@0+@1", RooArgList(gsigma, gsigma2));
  RooGaussian gau2("gau2", "", *mass, gmean2, fgsigma);
  RooRealVar *nbkg = w->var("nbkg");
  RooRealVar nbkg2("nbkg2", "", 1e3,0, 1e8);
  if (!addpol){
    //allpdf = new RooAddPdf("allpdf", "", RooArgList(gau,*arg), RooArgList(*nsig,*nbkg)); nbkg2.setVal(0);}
    allpdf = w->pdf("model");
    nbkg2.setVal(0);
    w->var("rsigma")->setConstant(0);
    w->var("dmean")->setConstant(0);
  }
  else allpdf = new RooAddPdf("allpdf", "", RooArgList(gau,*arg, gau2), RooArgList(*nsig,*nbkg, nbkg2));
  
  
  TString rhname = "r_"; rhname += h1->GetName();
  rhist = new RooDataHist(rhname.Data(), "", *mass, h1);
  allpdf->fitTo(*rhist, RooFit::Save(), RooFit::Minos());
  RooFitResult* res = allpdf->fitTo(*rhist, RooFit::Save(),Extended(1));
  res->Print("v");
  RooPlot *frame = mass->frame(RooFit::Range(h1->GetBinLowEdge(1), h1->GetBinLowEdge(h1->GetNbinsX()+1)));
  frame->SetTitle("");
  frame->SetXTitle(h1->GetXaxis()->GetTitle());
  frame->SetYTitle(h1->GetYaxis()->GetTitle());
  rhist->plotOn(frame);
  allpdf->plotOn(frame, RooFit::LineWidth(2), RooFit::LineColor(h1->GetLineColor()));
  allpdf->plotOn(frame, RooFit::Components("bkg"),RooFit::LineWidth(2), RooFit::LineStyle(kDashed), 
                 RooFit::LineColor(h1->GetLineColor()));
  if (addpol) allpdf->plotOn(frame, RooFit::Components("bkg,gau2"),RooFit::LineWidth(2), RooFit::LineStyle(kDotted), 
                             RooFit::LineColor(h1->GetLineColor()));
  frame->GetYaxis()->SetRangeUser(h1->GetMinimum(),h1->GetMaximum()*1.5);
  frame->Draw();
  TPaveText *txt = new TPaveText(0.7, 0.8, 0.98, 0.98, "ndc");
  txt->SetTextAlign(12);
  txt->AddText(TString::Format("N_{peak}: %d #pm %d", (int)(nsig->getVal()+nbkg2.getVal()), 
                               (int)sqrt(nsig->getError()*nsig->getError()+nbkg2.getError()*nbkg2.getError())));
  txt->Draw();
  if(!addpol){
    //integrate the two regions for the background, and print them out. Save the ratio in the class.
    //first,normalize
    RooArgSet nset(*mass) ;
    std::cout << "normalized integral = " << mass->getVal(&nset) << std::endl ;
    RooAbsReal* tot_int_bkg = arg->createIntegral(*mass,NormSet(*mass));
    mass->setRange("peak",2010.26-0.9,2010.26+0.9);
    RooAbsReal* peak_int_bkg = arg->createIntegral(*mass,NormSet(*mass),Range("peak"));
    RooAbsReal* tot_int_bkg2 = arg->createIntegral(*mass,NormSet(*mass));
    std::cout<<"to shut up the compiler, tot_int_bkg2->getVal() = "<<tot_int_bkg2->getVal()<<std::endl;
    mass->setRange("sideband",2015,2025);
    RooAbsReal* sideband_int_bkg = arg->createIntegral(*mass,NormSet(*mass),Range("sideband"));
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"For h1 = "<<h1->GetName()<<std::endl;
    std::cout<<"Total integral of background = "<<tot_int_bkg->getVal()<<std::endl;
    std::cout<<"integral of background in signal region = "<<peak_int_bkg->getVal()<<std::endl;
    std::cout<<"integral of background in sideband region = "<<sideband_int_bkg->getVal()<<std::endl;
    pik_background_subtraction_ratio_result = peak_int_bkg->getVal()/sideband_int_bkg->getVal();
    std::cout<<"int(sig)/int(bkg) = "<<pik_background_subtraction_ratio_result<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    //PlottingTools::makeResidualPlotsLiang(frame,*mass,*rhist,allpdf,"./SavedFits/betastar/RSpeakingBkgFit_pik_fit",2000,2025);
  }
}

//
std::vector<double> betastar_plot::makefitplotretvals(RooWorkspace*w, TH1* h1, int addpol){
  std::vector<double> ret;
  RooRealVar *mass = w->var("dstarM"); 
  RooRealVar *nsig = w->var("nsig");
  RooRealVar *kappa = w->var("kappa");
  kappa->setConstant(0);
  RooAbsPdf *arg = w->pdf("bkg");
  RooAbsPdf* allpdf = NULL;
  RooDataHist* rhist = NULL;
  RooRealVar gmean("fmean", "", 2.01*1e3, 2.009*1e3,2.011*1e3);
  RooRealVar gsigma("gsigma", "", 0.001*1e3, 1e-5*1e3,1e-2*1e3);
  RooGaussian gau("gau", "", *mass, gmean, gsigma);
  RooRealVar gmean2("fmean2", "", 2.01*1e3, 2.009*1e3,2.011*1e3);
  RooRealVar gsigma2("gsigma2", "", 0.001*1e3, 1e-5*1e3,1e-2*1e3);
  RooFormulaVar fgsigma("fgsigma", "@0+@1", RooArgList(gsigma, gsigma2));
  RooGaussian gau2("gau2", "", *mass, gmean2, fgsigma);
  RooRealVar *nbkg = w->var("nbkg");
  RooRealVar nbkg2("nbkg2", "", 1e3,0, 1e8);
  if (!addpol){
    //allpdf = new RooAddPdf("allpdf", "", RooArgList(gau,*arg), RooArgList(*nsig,*nbkg)); nbkg2.setVal(0);}
    allpdf = w->pdf("model");
    nbkg2.setVal(0);
    w->var("rsigma")->setConstant(0);
    w->var("dmean")->setConstant(0);
  }
  else allpdf = new RooAddPdf("allpdf", "", RooArgList(gau,*arg, gau2), RooArgList(*nsig,*nbkg, nbkg2));
  
  
  TString rhname = "r_"; rhname += h1->GetName();
  rhist = new RooDataHist(rhname.Data(), "", *mass, h1);
  allpdf->fitTo(*rhist, RooFit::Save(), RooFit::Minos());
  RooFitResult* res = allpdf->fitTo(*rhist, RooFit::Save(),Extended(1));
  res->Print("v");
  RooPlot *frame = mass->frame(RooFit::Range(h1->GetBinLowEdge(1), h1->GetBinLowEdge(h1->GetNbinsX()+1)));
  frame->SetTitle("");
  frame->SetXTitle(h1->GetXaxis()->GetTitle());
  frame->SetYTitle(h1->GetYaxis()->GetTitle());
  rhist->plotOn(frame);
  allpdf->plotOn(frame, RooFit::LineWidth(2), RooFit::LineColor(h1->GetLineColor()));
  allpdf->plotOn(frame, RooFit::Components("bkg"),RooFit::LineWidth(2), RooFit::LineStyle(kDashed), 
                 RooFit::LineColor(h1->GetLineColor()));
  if (addpol) allpdf->plotOn(frame, RooFit::Components("bkg,gau2"),RooFit::LineWidth(2), RooFit::LineStyle(kDotted), 
                             RooFit::LineColor(h1->GetLineColor()));
  frame->GetYaxis()->SetRangeUser(h1->GetMinimum(),h1->GetMaximum()*1.5);
  frame->Draw();
  TPaveText *txt = new TPaveText(0.7, 0.8, 0.98, 0.98, "ndc");
  txt->SetTextAlign(12);
  txt->AddText(TString::Format("N_{peak}: %d #pm %d", (int)(nsig->getVal()+nbkg2.getVal()), 
                               (int)TMath::Sqrt(nsig->getError()*nsig->getError()+nbkg2.getError()*nbkg2.getError())));
  ret.push_back(nsig->getVal()+nbkg2.getVal());
  ret.push_back(TMath::Sqrt(nsig->getError()*nsig->getError()+nbkg2.getError()*nbkg2.getError()));
   
  txt->Draw();
  if(!addpol){
    //integrate the two regions for the background, and print them out. Save the ratio in the class.
    //first,normalize
    RooArgSet nset(*mass) ;
    std::cout << "normalized integral = " << mass->getVal(&nset) << std::endl ;
    RooAbsReal* tot_int_bkg = arg->createIntegral(*mass,NormSet(*mass));
    mass->setRange("peak",2010.26-0.9,2010.26+0.9);
    RooAbsReal* peak_int_bkg = arg->createIntegral(*mass,NormSet(*mass),Range("peak"));
    RooAbsReal* tot_int_bkg2 = arg->createIntegral(*mass,NormSet(*mass));
    std::cout<<"to shut up the compiler, tot_int_bkg2->getVal() = "<<tot_int_bkg2->getVal()<<std::endl;
    mass->setRange("sideband",2015,2025);
    RooAbsReal* sideband_int_bkg = arg->createIntegral(*mass,NormSet(*mass),Range("sideband"));
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"For h1 = "<<h1->GetName()<<std::endl;
    std::cout<<"Total integral of background = "<<tot_int_bkg->getVal()<<std::endl;
    std::cout<<"integral of background in signal region = "<<peak_int_bkg->getVal()<<std::endl;
    std::cout<<"integral of background in sideband region = "<<sideband_int_bkg->getVal()<<std::endl;
    pik_background_subtraction_ratio_result = peak_int_bkg->getVal()/sideband_int_bkg->getVal();
    std::cout<<"int(sig)/int(bkg) = "<<pik_background_subtraction_ratio_result<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    //PlottingTools::makeResidualPlotsLiang(frame,*mass,*rhist,allpdf,"./SavedFits/betastar/RSpeakingBkgFit_pik_fit",2000,2025);
   
  }
  return ret;
}

void betastar_plot::SavePlots(){
  TFile fout("./SavedFits/betastar/"+m_name+"_betastar_plots.root","RECREATE");
  fout.cd();
  h2sig->Write();
  h2tot->Write();
  h2kpisb->Write();
  h2kpisb_hi->Write();
  h2kpisb_lo->Write();
  h2kksb->Write();
  h2pipisb->Write();
  h2piksb->Write();
  h2rob->Write();
  h2kpisb_cut_range->Write();
  h2pi_probnnmu_dstar_sideband_high->Write();
  h2pi_probnnmu_dstar_sideband_low->Write();
  h2k_probnnmu_dstar_sideband_high->Write();
  h2k_probnnmu_dstar_sideband_low->Write();
  h2pi_probnne_dstar_sideband_high->Write();
  h2pi_probnne_dstar_sideband_low->Write();
  h2k_probnne_dstar_sideband_high->Write();
  h2k_probnne_dstar_sideband_low->Write();
  
  hmsig->Write();
  hmkpisb->Write();
  hmkksb->Write();
  hmpipisb->Write();
  hmpiksb->Write();
  hmrob->Write();

  hmkpisb_cut_range->Write();
  hmkpisb_cut_range_hi->Write();
  hmkpisb_cut_range_lo->Write();
  hmkpisb_cut_range_hi_1->Write();
  hmkpisb_cut_range_hi_2->Write();
  hmkpisb_cut_range_hi_3->Write();
  hmkpisb_cut_range_hi_4->Write();
  hmkpisb_cut_range_hi_5->Write();
  hmkpisb_cut_range_hi_6->Write();
  
  hmkpisb_cut_range_lo_1->Write();
  hmkpisb_cut_range_lo_2->Write();
  hmkpisb_cut_range_lo_3->Write();
  hmkpisb_cut_range_lo_4->Write();
  hmkpisb_cut_range_lo_5->Write();
  hmkpisb_cut_range_lo_6->Write();
  hmD0_pik_sig->Write();
  hmD0_pik_sb->Write();
  hmD0_pik_tot->Write();

  double_misid_dmass_dst_sig_region->Write();
  double_misid_dmass_dst_sideband_region->Write();

  double_misid_dmass_dst_sig_region_bin1->Write();
  double_misid_dmass_dst_sideband_region_bin1->Write();
  double_misid_dmass_dst_sig_region_bin2->Write();
  double_misid_dmass_dst_sideband_region_bin2->Write();
  double_misid_dmass_dst_sig_region_bin3->Write();
  double_misid_dmass_dst_sideband_region_bin3->Write();
  double_misid_dmass_dst_sig_region_bin4->Write();
  double_misid_dmass_dst_sideband_region_bin4->Write();
  double_misid_dmass_dst_sig_region_bin5->Write();
  double_misid_dmass_dst_sideband_region_bin5->Write();
  
  
  fout.Close();


}

void betastar_plot::FitWSDoubleMisID(){
  //do the background subtraction.
  //first, sumw2 on the histograms.
  double_misid_subtr = (TH1*)double_misid_dmass_dst_sig_region->Clone("double_misid_subtr");
  double_misid_subtr->Sumw2();
  TH1* double_misid_sideband_scaled = (TH1*)double_misid_dmass_dst_sideband_region->Clone("double_misid_sideband_scaled");
  double_misid_sideband_scaled->Sumw2();
  double_misid_sideband_scaled->Scale(pik_background_subtraction_ratio_result);
  double_misid_subtr->Add(double_misid_sideband_scaled,-1);
  //now we have the histogram, fit it with a second order polynomial.
  RooRealVar* x = new RooRealVar("x","m(K #pi)",1700,2100,"MeV");
  x->setRange("lo",1780+4,(1.86484 - 5*0.008)*1e3 -4);
  x->setRange("hi",(1.86484 + 5*0.008)*1e3+4,1944-4);
  x->setRange("sig",1864.84-24,1864.84+24);
  RooRealVar a0("a0","a0",-0.1,-50,50);
  RooRealVar a1("a1","a1",0.004,-100,100);
  RooChebychev pol("pol","pol",*x,RooArgSet(a0,a1));
  /*  RooRealVar a0("a0","a0",1) ;
  RooRealVar a1("a1","a1",0,-20,20) ;
  RooRealVar a2("a2","a2",-1,-100,100) ;
  RooPolynomial pol("pol","pol",*x,RooArgList(a0,a1,a2),0) ;*/
  RooRealVar nsig("nsig","nsig",200,5,10000);
  RooDataHist* data = new RooDataHist((m_name+"double_misid_subtracted_data").Data(),"",*x,double_misid_subtr);
  RooExtendPdf model("model","model",pol,nsig);
  RooFitResult* res_pol = model.fitTo(*data,Range("lo,hi"),RooFit::Save(),Extended(1),SumW2Error(kFALSE));
  res_pol->Print("v");
  TCanvas* cpol = new TCanvas();
  RooPlot* frame = x->frame();
  frame->SetTitle("");
  data->plotOn(frame);
  
  model.plotOn(frame,LineColor(kMagenta),Range(1780,2100));
  frame->Draw();
  TBox sigreg(1864.84-24,0,1864.84+24,frame->GetMaximum());
  sigreg.SetFillColor(kGreen+2);
  sigreg.SetFillColorAlpha(kGreen+2,0.5);
  sigreg.Draw();
  cpol->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_double_misid_d0_sideband_subtracted_fit.pdf");
  //create the integral.
  RooAbsReal* tot_int_double_misid = model.createIntegral(*x,NormSet(*x));
  std::cout<<"nsig before = "<<nsig.getVal()*tot_int_double_misid->getVal()<<std::endl;
  RooAbsReal* sig_int = model.createIntegral(*x,NormSet(*x),Range("sig"));
  cout<<"nsig after = "<<nsig.getVal()<<endl;
  std::cout<<"nsig*I after = "<<nsig.getVal()*sig_int->getVal()<<std::endl;
  std::vector<double>poly_fit;
  poly_fit.push_back(nsig.getVal()*sig_int->getVal());//central value
  //poly_fit.push_back(getErrorFromPropagation(x,&model,res_pol,data,1700,2100,1864.84-24,1864.84+24));
  poly_fit.push_back(1);
    
  //now construct secondary fit with linear shape.

  RooRealVar b0("b0","b0",100.,0.,2000.);
  RooRealVar nsig2("nsig2","nsig2",200,5,10000);
  RooPolynomial lin("lin","lin",*x,RooArgSet(b0));
  //RooPolynomial lin("lin","lin",*x,RooArgSet(b0));
  RooExtendPdf model2("model2","model2",lin,nsig2);
  RooFitResult* res_lin = model2.fitTo(*data,Range("hi,lo"),RooFit::Save(),Extended(1),SumW2Error(kFALSE));

  res_lin->Print("v");
  TCanvas* clin = new TCanvas();
  frame = frame->emptyClone("linframe");
  frame->SetTitle("");
  data->plotOn(frame);
  
  model2.plotOn(frame,LineColor(kMagenta),Range(1780,1950));
  frame->Draw();
  
  sigreg.Draw();
  clin->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_double_misid_d0_sideband_subtracted_fit_linear.pdf");
  //create the integral.
  RooAbsReal* tot_int2_double_misid = model2.createIntegral(*x,NormSet(*x));
  std::cout<<"nsig2 before = "<<nsig2.getVal()*tot_int2_double_misid->getVal()<<std::endl;
  RooAbsReal* sig_int2 = model2.createIntegral(*x,NormSet(*x),Range("sig"));
  cout<<"nsig2 after = "<<nsig2.getVal()<<endl;
  std::cout<<"nsig2*I after = "<<nsig2.getVal()*sig_int2->getVal()<<std::endl;
  std::vector<double>liny_fit;
  liny_fit.push_back(nsig2.getVal()*sig_int2->getVal());//central value
  //liny_fit.push_back(getErrorFromPropagation(x,&model2,res_lin,data,1700,2100,1864.84-24,1864.84+24,true));
  liny_fit.push_back(1);

  std::cout<<"Result of the fit"<<std::endl;
  std::cout<<"Linear Fit: "<<liny_fit[0]<<" +/- "<<liny_fit[1]<<std::endl;
  std::cout<<"Polynomial Fit: "<<poly_fit[0]<<" +/- "<<poly_fit[1]<<std::endl;
  liny_fit.clear();
  poly_fit.clear();
  return;
}

double betastar_plot::getErrorFromPropagation(RooRealVar* x,RooAbsPdf* model, RooFitResult* fr,RooDataHist* data,Double_t xmin, Double_t xmax, Double_t sig_min, Double_t sig_max,bool linearfit){
  //taken from example at https://root.cern.ch/phpBB3/viewtopic.php?t=12949
  RooArgList pars(* model->getParameters(RooArgSet(*x) ) );
  RooArgSet prodSet(*model); //prodSet.add(nsig);
  RooProduct unNormPdf("fitted Function", "fitted Function", prodSet);
  TF1 * f2 = unNormPdf.asTF(RooArgList(*x), pars);
  //cross check: make sure we can get the info from the fit result
  float nsig1,dnsig1;
  if(linearfit){
    nsig1 = ((RooRealVar*)pars.find("nsig2"))->getVal();
    dnsig1 = ((RooRealVar*)pars.find("nsig2"))->getError();
  }
  else{
    nsig1 = ((RooRealVar*) pars.find("nsig"))->getVal();
    dnsig1 = ((RooRealVar*) pars.find("nsig"))->getError();
  }
  /*
  float par1 = ((RooRealVar*) pars.find("a0"))->getVal();
  float dpar1 = ((RooRealVar*) pars.find("a0"))->getError();
  float par2 = ((RooRealVar*) pars.find("a1"))->getVal();
  float dpar2 = ((RooRealVar*) pars.find("a1"))->getError();*/
  cout<<"sanity check"<<endl;
  cout << " nsig = " << nsig1 << " +- " << dnsig1 << endl;
  //cout << " par1 = " << par1 << " +- " << dpar1 << endl;
  //cout << " par2 = " << par2 << " +- " << dpar2 << endl;
  //that makes sense, let's do the rest

  Double_t integ2_full= f2->Integral(xmin,xmax);
  Double_t integ2 = nsig1*f2->Integral(sig_min, sig_max, 0)/integ2_full;
  cout<<"ratio of integrals = "<<f2->Integral(sig_min,sig_max,0)/integ2_full<<endl;
  cout<<"integ2_full = "<<integ2_full<<endl;
  cout<<"integ2 ="<<integ2<<endl;
  Double_t dinteg = nsig1*f2->IntegralError(sig_min,sig_max,0,fr->covarianceMatrix().GetMatrixArray())/integ2_full;
  Double_t dnumber = dnsig1*f2->Integral(sig_min, sig_max, 0)/integ2_full;
  cout<<"error from prop = "<<TMath::Sqrt(dinteg*dinteg + dnumber*dnumber)<<endl;
  return TMath::Sqrt(dinteg*dinteg + dnumber*dnumber);
  
  
}

void betastar_plot::FitWSDoubleMisIDLiang(){
  double_misid_subtr = (TH1*)double_misid_dmass_dst_sig_region->Clone("double_misid_subtr");
  double_misid_subtr->Sumw2();
  TH1* double_misid_sideband_scaled = (TH1*)double_misid_dmass_dst_sideband_region->Clone("double_misid_sideband_scaled");
  double_misid_sideband_scaled->Sumw2();
  double_misid_sideband_scaled->Scale(pik_background_subtraction_ratio_result);
  double_misid_subtr->Add(double_misid_sideband_scaled,-1);
  for(int bin =1; bin<=double_misid_subtr->GetNbinsX();++bin){
    if(double_misid_subtr->GetBinContent(bin)<0){double_misid_subtr->SetBinContent(bin,0);}
  }
  //TF1* f1 = new TF1("f1", "[0]*([1]-x)*(x-[2])",1700,2100);
  TF1* f1 = new TF1("f1", "[0]*([1]+x)",1740,2100);
  //f1->SetParLimits(0, 1e-4, 1e5);
  //\f1->SetParLimits(1, 1.86484*1e3,3000*1e3);
  //f1->SetParLimits(2, 0, 1.86484*1e3);
  f1->SetParameter(0,0.1);
  f1->SetParameter(1,-200);
		   
  TFitResultPtr r = double_misid_subtr->Fit("f1", "ES","",1780+4,1940);
  TMatrixDSym mat = r->GetCorrelationMatrix();
  const double x1[2] = {1.758*1e3, (1.86484-5*0.008)*1e3};
  const double x2[2] = {(1.86484+5*0.008)*1e3, (2.07)*1e3};
  const double x0[2] = {(1.86484-3*0.008)*1e3, (1.86484+3*0.008)*1e3};
  const double x_full[2]={1784,1940};
  double_misid_subtr->GetYaxis()->SetRangeUser(0,1.1*double_misid_subtr->GetMaximum());
  TCanvas *ctemp = new TCanvas();
  double_misid_subtr->Draw();
  f1->SetLineColor(kMagenta);
  f1->Draw("psame");
  TBox *box = new TBox(x0[0], 0, x0[1], double_misid_subtr->GetMaximum());
  box->SetFillColor(kGreen+2);
  box->SetFillColorAlpha(kGreen+2,0.5);
  box->Draw();
  ctemp->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_double_misid_d0_sideband_subtracted_fit_liang.pdf");
  double* pars = f1->GetParameters();
  const Double_t* epars = f1->GetParErrors();
  //double int1, int2, int0;
  const Int_t npars = f1->GetNpar();
  //Double_t d0ratio  = (intf(x0[1], pars, npars) - intf(x0[0], pars, npars))/(intf(x1[1], pars, npars) - intf(x1[0], pars, npars)+intf(x2[1], pars, npars) - intf(x2[0], pars, npars));
  
  Double_t d0ratio  = (int2f(x0[1], pars, npars) - int2f(x0[0], pars, npars))/(int2f(x1[1], pars, npars) - int2f(x1[0], pars, npars)+int2f(x2[1], pars, npars) - int2f(x2[0], pars, npars));
  double sideband_int = (int2f(x1[1], pars, npars) - int2f(x1[0], pars, npars)+int2f(x2[1], pars, npars) - int2f(x2[0], pars, npars));
  double sigint = (int2f(x0[1], pars, npars) - int2f(x0[0], pars, npars));
  double intfull= (int2f(x_full[1],pars,npars)-int2f(x_full[0],pars,npars));
  Double_t ratio_full = sigint/intfull;//to get the error right with roofit.
  TVectorD vF(npars);
  TVectorD vFfull(npars);
  
  double* newpars = new double[npars];
  for (int j=0;j<npars;j++){
    for (int k=0;k<npars;k++) newpars[k] = pars[k];
    newpars[j] = pars[j]+epars[j];
    //    Double_t yhigh = (intf(x0[1], newpars, npars) - intf(x0[0], newpars, npars))/(intf(x1[1], newpars, npars) - intf(x1[0], newpars, npars)+intf(x2[1], newpars, npars) - intf(x2[0], newpars, npars));
    //newpars[j] = pars[j]-epars[j];
    //Double_t ylow = (intf(x0[1], newpars, npars) - intf(x0[0], newpars, npars))/(intf(x1[1], newpars, npars) - intf(x1[0], newpars, npars)+intf(x2[1], newpars, npars) - intf(x2[0], newpars, npars));
    
    Double_t yhigh = (int2f(x0[1], newpars, npars) - int2f(x0[0], newpars, npars))/(int2f(x1[1], newpars, npars) - int2f(x1[0], newpars, npars)+int2f(x2[1], newpars, npars) - int2f(x2[0], newpars, npars));
    Double_t yhighfull = (int2f(x0[1], newpars, npars) - int2f(x0[0], newpars, npars))/(int2f(x_full[1], newpars, npars) - int2f(x_full[0], newpars, npars));
    newpars[j] = pars[j]-epars[j];
    Double_t ylow = (int2f(x0[1], newpars, npars) - int2f(x0[0], newpars, npars))/(int2f(x1[1], newpars, npars) - int2f(x1[0], newpars, npars)+int2f(x2[1], newpars, npars) - int2f(x2[0], newpars, npars));
    Double_t ylowfull = (int2f(x0[1], newpars, npars) - int2f(x0[0], newpars, npars))/(int2f(x_full[1], newpars, npars) - int2f(x_full[0], newpars, npars));
    vF[j] = 0.5*(yhigh-ylow);
    vFfull[j]=0.5*(yhighfull-ylowfull);
  }
  Double_t error = TMath::Sqrt(vF*(mat*vF));
  Double_t errorFull = TMath::Sqrt(vFfull*(mat*vFfull));
  cout<<"Ratio: "<<d0ratio<<" +/- "<<error<<endl;
  cout<<"Ratio of signal to full integral = "<<ratio_full<<"+/-"<<errorFull<<endl;
  cout<<"pars[0]="<<pars[0]<<endl;
  //we know that the function fits, so now let's bind a PDF to roofit and get the number of signal events.
  RooRealVar x("x","x",1700,2100);
  RooRealVar par1("par1","par1",pars[0]);
  RooRealVar par2("par2","par2",pars[1]);
  RooRealVar nsig("nsig","nsig",100,5,2e5);
  //RooAbsReal *lineVal = bindFunction(f1,x,RooArgList(par1,par2));

  //make a PDF out of this
  RooGenericPdf *line=new RooGenericPdf("line","line","par1* (par2+x)",RooArgSet(x,par1,par2));
  RooExtendPdf mod("mod","mod",*line,nsig);
  RooDataHist* data = new RooDataHist((m_name+"double_misid_subtracted_data").Data(),"",x,double_misid_subtr);
  x.setRange("lo",x1[0],x1[1]);
  x.setRange("hi",x2[0],x2[1]);
  x.setRange("sig",x0[0],x0[1]);
  RooFitResult* res =mod.fitTo(*data,Extended(1),Range("lo,hi"),SumW2Error(kFALSE),Save(1));
  res->Print("v");
  RooPlot* frame = x.frame();
  frame->SetTitle(";m(K#pi)[MeV];Entries/ 2 MeV");
  data->plotOn(frame);
  mod.plotOn(frame,Range(1780,1950));
  TCanvas* cc = new TCanvas();
  frame->Draw();
  cc->SaveAs("SavedFits/betastar/"+m_name+"double_misid_from_generic_pdf.pdf");
  //now double check that the integral in the range is correct.
  //RooMsgService::instance().getStream(1).removeTopic(Eval) ;
  /*  
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  gErrorIgnoreLevel = kBreak;
  RooMsgService::instance().setStreamStatus(0,false);
  RooMsgService::instance().setStreamStatus(1,false);
  
  */
  RooAbsReal* intTot = mod.createIntegral(x,NormSet(x));
  /*
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  gErrorIgnoreLevel = kBreak;
  RooMsgService::instance().setStreamStatus(0,false);
  RooMsgService::instance().setStreamStatus(1,false);
  */
  RooAbsReal* intBand = mod.createIntegral(x,NormSet(x),Range("lo,hi"));
  /*
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  gErrorIgnoreLevel = kBreak;
  RooMsgService::instance().setStreamStatus(0,false);
  RooMsgService::instance().setStreamStatus(1,false);
  */
  RooAbsReal* intSig = mod.createIntegral(x,NormSet(x),Range("sig"));
  /*
  RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
  gErrorIgnoreLevel = kBreak;
  RooMsgService::instance().setStreamStatus(0,false);
  RooMsgService::instance().setStreamStatus(1,false);
  */
  double intTotVal = intTot->getVal();

  double intBandVal = intBand->getVal();
  double intSigVal = intSig->getVal();
  cout<<"intTot = "<<intTotVal<<endl;
  cout<<"intBand = "<<intBandVal<<endl;
  cout<<"intSig = "<<intSigVal<<endl;
  cout<<"-----"<<endl;
  cout<<"from orig fit"<<endl;
  cout<<"d0ratio = "<<d0ratio<<endl;
  cout<<"sideband_int = "<<sideband_int<<endl;
  cout<<"sigiint = "<<sigint<<endl;
  cout<<"from roofit, d0ratio = "<<sigint/sideband_int<<endl;
  double totError = nsig.getVal()*intSigVal*nsig.getVal()*intSigVal;
  totError*=TMath::Power(nsig.getError()/nsig.getVal(),2)+TMath::Power(error/d0ratio,2);
  totError=TMath::Sqrt(totError);
  cout<<"number of peaking d0 = "<<nsig.getVal()*intSigVal<<" +/- "<<totError<<endl;
  //now that this is varified, we can extract the number of signal events and the error.
  
  //
}


double betastar_plot::intf(double x, double p[], int n){
  Double_t* p2 = new Double_t[n];
  p2[0] = -p[0]*p[1]*p[2];
  p2[1] = p[0]*(p[1]+p[2]);
  p2[2] = -p[0];
  double r =0 ; double xmx = x;
  for (int i=0;i<n;i++) {
    r += p2[i]*xmx/(i+1);
    xmx *= x;}
  delete p2;
  return r;
}


double betastar_plot::int2f(double x, double p[], int n){
  Double_t* p2 = new Double_t[n];
  p2[0] = p[0]*p[1];
  //p2[1] = p[0]*(p[1]+p[2]);
  p2[1] = p[0];
  double r =0 ; double xmx = x;
  for (int i=0;i<n;i++) {
    r += p2[i]*xmx/(i+1);
    xmx *= x;}
  delete p2;
  return r;
}

void betastar_plot::FitWSDoubleMisIDTimeDependence(){
  //get the histograms.
  TH1D* the_hists[5];
  TH1D* the_bkgs[5];
  the_hists[0]=(TH1D*)double_misid_dmass_dst_sig_region_bin1->Clone("h1");
  the_hists[1]=(TH1D*)double_misid_dmass_dst_sig_region_bin2->Clone("h2");
  the_hists[2]=(TH1D*)double_misid_dmass_dst_sig_region_bin3->Clone("h3");
  the_hists[3]=(TH1D*)double_misid_dmass_dst_sig_region_bin4->Clone("h4");
  the_hists[4]=(TH1D*)double_misid_dmass_dst_sig_region_bin5->Clone("h5");

  the_bkgs[0]=(TH1D*)double_misid_dmass_dst_sideband_region_bin1->Clone("bg1");
  the_bkgs[1]=(TH1D*)double_misid_dmass_dst_sideband_region_bin2->Clone("bg2");
  the_bkgs[2]=(TH1D*)double_misid_dmass_dst_sideband_region_bin3->Clone("bg3");
  the_bkgs[3]=(TH1D*)double_misid_dmass_dst_sideband_region_bin4->Clone("bg4");
  the_bkgs[4]=(TH1D*)double_misid_dmass_dst_sideband_region_bin5->Clone("bg5");
  //subtract the background.
  for(int i=0; i<5;++i){
    the_hists[i]->Sumw2();
    the_bkgs[i]->Sumw2();
    the_hists[i]->Add(the_bkgs[i],-1);
  }
  //now do the fit as with liang's shiz
  TF1* f1 = new TF1("f1", "[0]*([1]+x)",1740,2100);
  f1->SetParameter(0,0.1);
  f1->SetParameter(1,-200);
  f1->SetLineColor(kMagenta);
  TFitResultPtr r[5];
  //const double x1[2] = {1.758*1e3, (1.86484-5*0.008)*1e3};
  //const double x2[2] = {(1.86484+5*0.008)*1e3, (2.07)*1e3};
  const double x0[2] = {(1.86484-3*0.008)*1e3, (1.86484+3*0.008)*1e3};
  //const double x_full[2]={1784,1940};
  TCanvas *ct = new TCanvas();
  TBox *box = new TBox(x0[0], 0, x0[1], double_misid_subtr->GetMaximum());
  box->SetFillColor(kGreen+2);
  box->SetFillColorAlpha(kGreen+2,0.5);
  
  for(int i=0;i<5;++i){
    the_hists[i]->GetYaxis()->SetRangeUser(0,1.1*double_misid_subtr->GetMaximum());
    r[i] = the_hists[i]->Fit("f1","ES","",1784,1940);
    TMatrixDSym mat = r[i]->GetCorrelationMatrix();
    the_hists[i]->Draw();
    
    f1->Draw("psame");
    box->Draw();
    ct->SaveAs("./SavedFits/betastar/"+m_name+Form("_betastar_double_misid_d0_sideband_subtr_bin%d.pdf",i+i));
  }
}

//check the peaking background from fitting.
