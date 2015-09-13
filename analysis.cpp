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
#include <TRandom3.h>
#include <TString.h>
#include <TFile.h>
#include <TObject.h>
#include <TTree.h>
#include <TCut.h>
#include <THStack.h>
#include <TLegend.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TLeaf.h>
#include <TProfile2D.h>
#include <TChain.h>
#include <TPaveStats.h>
#include <TArrow.h>
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

#include "DT_D0_mix_CPV.h"
#include "massFit.h"
#include "WrongB.h"
//#include "PlottingTools.h"
using namespace std;

void getLuminosity(TTree* the_lumi_tree){
  Float_t totLumi = 0.0;
  Float_t totLumiErr = 0.0;

    int entries = the_lumi_tree->GetEntries();
    for(int i=0; i<entries;++i){
      the_lumi_tree->GetEntry(i);
      totLumi+=the_lumi_tree->GetLeaf("IntegratedLuminosity")->GetValue();
      totLumiErr+=the_lumi_tree->GetLeaf("IntegratedLuminosityErr")->GetValue();
    }
    //cout<<"for OS tuple,"<<endl;

  printf(" Total Luminosity      : %.5f pb-1 +/- %.5f pb-1\n", totLumi, totLumiErr);
}



int main(int argc, char* const argv[]){
  cout<<"this is a test"<<endl;

  if(argc<2){
    cout<<"*************************************"<<endl;
    cout<<"Expecting a file or files to process"<<endl;
    cout<<"*************************************"<<endl;
    return 0;
  }
  cout<<"Starting analysis for file "<<argv[1]<<endl;
  TChain* rs_tree = new TChain("RS/DecayTree");
  TChain* rs_ss_tree = new TChain("RS_ss/DecayTree");
  TChain* ws_tree = new TChain("WS/DecayTree");
  TChain* ws_ss_tree = new TChain("WS_ss/DecayTree");
  TChain* lumi_tree = new TChain("GetIntegratedLuminosity/LumiTuple");
  TString  rootfname[argc];
  for(int i=0; i< argc-1; ++i){
    rootfname[i]=argv[i+1];
    rs_tree->Add(rootfname[i]);
    rs_ss_tree->Add(rootfname[i]);
    ws_tree->Add(rootfname[i]);
    ws_ss_tree->Add(rootfname[i]);
    lumi_tree->Add(rootfname[i]);
  }
  getLuminosity(lumi_tree);
  cout<<"rs tree"<<endl;
  DT_D0_mix_CPV rs_looper(rs_tree);
  rs_looper.Loop();
  rs_looper.bs_plot->SavePlots();
  cout<<"rs ss tree"<<endl;
  
  DT_D0_mix_CPV rs_ss_looper(rs_ss_tree);
  rs_ss_looper.Loop();
  rs_ss_looper.bs_plot->SavePlots();
  cout<<"ws tree"<<endl;
  DT_D0_mix_CPV ws_looper(ws_tree);
  ws_looper.Loop();
  ws_looper.bs_plot->SavePlots();
  cout<<"ws ss tree"<<endl;
  
  DT_D0_mix_CPV ws_ss_looper(ws_ss_tree);
  ws_ss_looper.Loop();
  ws_ss_looper.bs_plot->SavePlots();
  
  
  TFile *fout = new TFile("./SavedFits/rs_mass.root","RECREATE");
  fout->cd();
  rs_looper.dstar_mass_plot->Write();
  rs_looper.d0_mass_plot->Write();
  rs_looper.b_mass_plot->Write();
  rs_looper.dstar_pt->Write();
  rs_looper.dstar_p->Write();
  rs_looper.mu_pt->Write();
  rs_looper.mu_p->Write();
  rs_looper.mu_log_ip->Write();
  rs_looper.pis_ghost_prob->Write();
  rs_looper.pis_ghost_prob_pos->Write();
  rs_looper.pis_ghost_prob_neg->Write();
  rs_looper.pis_match_chi2->Write();
  rs_looper.pis_match_chi2_pos->Write();
  rs_looper.pis_match_chi2_neg->Write();
  rs_looper.pis_match_chi2_vs_dstm->Write();
  rs_looper.pis_match_chi2_vs_td0->Write();
  rs_looper.dst_mass_vs_kpidk->Write();
  rs_looper.dst_mass_vs_pipidk->Write();
  rs_looper.dstar_mass_plot_pos->Write();
  rs_looper.dstar_mass_plot_neg->Write();

  
  rs_looper.b_flight_dist_vs_dstm_pos->Write();
  rs_looper.b_corr_mass_vs_dstm_pos->Write();
  rs_looper.dtf_chi2_vs_dstm_pos->Write();
  rs_looper.muIPchi2_vs_dstm_pos->Write();
  rs_looper.muIPchi2_vs_dstm_zoom_pos->Write();
  rs_looper.logmuIPchi2_vs_dstm_pos->Write();
  rs_looper.b_endvertex_chi2_vs_dstm_pos->Write();
  rs_looper.b_fd_chi2_vs_dstm_pos->Write();

  rs_looper.b_flight_dist_vs_td0_pos->Write();
  rs_looper.b_corr_mass_vs_td0_pos->Write();
  rs_looper.dtf_chi2_vs_td0_pos->Write();
  rs_looper.muIPchi2_vs_td0_pos->Write();
  rs_looper.muIPchi2_vs_td0_zoom_pos->Write();
  rs_looper.logmuIPchi2_vs_td0_pos->Write();
  rs_looper.b_endvertex_chi2_vs_td0_pos->Write();
  rs_looper.b_fd_chi2_vs_td0_pos->Write();


  rs_looper.b_flight_dist_vs_dstm_neg->Write();
  rs_looper.b_corr_mass_vs_dstm_neg->Write();
  rs_looper.dtf_chi2_vs_dstm_neg->Write();
  rs_looper.muIPchi2_vs_dstm_neg->Write();
  rs_looper.muIPchi2_vs_dstm_zoom_neg->Write();
  rs_looper.logmuIPchi2_vs_dstm_neg->Write();
  rs_looper.b_endvertex_chi2_vs_dstm_neg->Write();
  rs_looper.b_fd_chi2_vs_dstm_neg->Write();


  rs_looper.b_flight_dist_vs_td0_neg->Write();
  rs_looper.b_corr_mass_vs_td0_neg->Write();
  rs_looper.dtf_chi2_vs_td0_neg->Write();
  rs_looper.muIPchi2_vs_td0_neg->Write();
  rs_looper.muIPchi2_vs_td0_zoom_neg->Write();
  rs_looper.logmuIPchi2_vs_td0_neg->Write();
  rs_looper.b_endvertex_chi2_vs_td0_neg->Write();
  rs_looper.b_fd_chi2_vs_td0_neg->Write();

  
  rs_looper.b_flight_dist->Write();
  rs_looper.b_flight_dist_vs_dstm->Write();
  rs_looper.b_corr_mass_vs_dstm->Write();
  rs_looper.dtf_chi2_vs_dstm->Write();
  rs_looper.b_endvertex_chi2_vs_dstm->Write();
  rs_looper.b_fd_chi2_vs_dstm->Write();


  rs_looper.b_flight_dist_vs_td0->Write();
  rs_looper.b_corr_mass_vs_td0->Write();
  rs_looper.dtf_chi2_vs_td0->Write();
  rs_looper.muIPchi2_vs_td0->Write();
  rs_looper.muIPchi2_vs_td0_zoom->Write();
  rs_looper.logmuIPchi2_vs_td0->Write();
  rs_looper.b_endvertex_chi2_vs_td0->Write();
  rs_looper.b_fd_chi2_vs_td0->Write();

  
  rs_looper.decay_time_distr->Write();
  //switch to a loop on bins.
  for(auto hist: rs_looper.dstar_pt_bins){
    hist->Write();
  }
  for(auto hist: rs_looper.dstar_p_bins){
    hist->Write();
  }
  for(auto hist: rs_looper.mu_pt_bins){
    hist->Write();
  }
  for(auto hist: rs_looper.mu_p_bins){
    hist->Write();
  }
  for(auto hist: rs_looper.mu_log_ip_bins){
    hist->Write();
  }
  
  //pid
  for(auto hist: rs_looper.kpidk_bins){
    hist->Write();
  }
  for(auto hist: rs_looper.pipidk_bins){
    hist->Write();
  }

  for(int i=0; i<20;++i){
    rs_looper.the_ghost_prob_bins[i]->Write();
  }
    
  //5x5 matrix
  for(auto hist: rs_looper.thepidMatrix){
    //guaranteed to be in the right order.
    hist->Write();
  }
  //td0
  rs_looper.td0_bin_neg10_to_neg075->Write();
  rs_looper.td0_bin_neg075_to_neg05->Write();
  //those guys aren't in the vector. the next ones are
  for(auto hist: rs_looper.td0_bins){
    hist->Write();
  }
  
  //pos
  for(auto hist: rs_looper.td0_pos_bins){
    hist->Write();
  }
  //neg
  for(auto hist: rs_looper.td0_neg_bins){
    hist->Write();
  }
  //extra
  rs_looper.d_logIPchi2_vs_dstm->Write();
  rs_looper.d_logIPchi2_vs_td0->Write();
  rs_looper.d_logIPchi2_vs_dstm_pos->Write();
  rs_looper.d_logIPchi2_vs_td0_pos->Write();
  rs_looper.d_logIPchi2_vs_dstm_neg->Write();
  rs_looper.d_logIPchi2_vs_td0_neg->Write();
  rs_looper.muon_vs_slow_pion_OWNPV_X->Write();
  rs_looper.muon_vs_slow_pion_OWNPV_Y->Write();
  rs_looper.muon_vs_slow_pion_OWNPV_Z->Write();

  //ss
  
  rs_ss_looper.dstar_mass_plot->Write();
  rs_ss_looper.d0_mass_plot->Write();
  rs_ss_looper.b_mass_plot->Write();
  rs_ss_looper.decay_time_distr->Write();
  rs_looper.dstar_mass_vs_muIPchi2->Write();
  rs_ss_looper.dstar_mass_vs_muIPchi2->Write();
  rs_ss_looper.dstar_pt->Write();
  rs_ss_looper.dstar_p->Write();
  rs_ss_looper.mu_pt->Write();
  rs_ss_looper.mu_p->Write();
  rs_ss_looper.mu_log_ip->Write();
  rs_ss_looper.pis_ghost_prob->Write();
  rs_ss_looper.pis_ghost_prob_pos->Write();
  rs_ss_looper.pis_ghost_prob_neg->Write();
  rs_ss_looper.pis_match_chi2->Write();
  rs_ss_looper.pis_match_chi2_pos->Write();
  rs_ss_looper.pis_match_chi2_neg->Write();
  rs_ss_looper.pis_match_chi2_vs_dstm->Write();
  rs_ss_looper.pis_match_chi2_vs_td0->Write();
  rs_ss_looper.dst_mass_vs_kpidk->Write();
  rs_ss_looper.dst_mass_vs_pipidk->Write();
  rs_ss_looper.dstar_mass_plot_pos->Write();
  rs_ss_looper.dstar_mass_plot_neg->Write();
  rs_ss_looper.b_flight_dist->Write();
  rs_ss_looper.b_flight_dist_vs_dstm->Write();
  rs_ss_looper.b_corr_mass_vs_dstm->Write();
  rs_ss_looper.dtf_chi2_vs_dstm->Write();
  rs_ss_looper.b_endvertex_chi2_vs_dstm->Write();
  rs_ss_looper.b_fd_chi2_vs_dstm->Write();
  rs_ss_looper.b_flight_dist_vs_dstm_pos->Write();
  rs_ss_looper.b_corr_mass_vs_dstm_pos->Write();
  rs_ss_looper.dtf_chi2_vs_dstm_pos->Write();
  rs_ss_looper.muIPchi2_vs_dstm_pos->Write();
  rs_ss_looper.muIPchi2_vs_dstm_zoom_pos->Write();
  rs_ss_looper.logmuIPchi2_vs_dstm_pos->Write();
  rs_ss_looper.b_endvertex_chi2_vs_dstm_pos->Write();
  rs_ss_looper.b_fd_chi2_vs_dstm_pos->Write();

  rs_ss_looper.b_flight_dist_vs_td0_pos->Write();
  rs_ss_looper.b_corr_mass_vs_td0_pos->Write();
  rs_ss_looper.dtf_chi2_vs_td0_pos->Write();
  rs_ss_looper.muIPchi2_vs_td0_pos->Write();
  rs_ss_looper.muIPchi2_vs_td0_zoom_pos->Write();
  rs_ss_looper.logmuIPchi2_vs_td0_pos->Write();
  rs_ss_looper.b_endvertex_chi2_vs_td0_pos->Write();
  rs_ss_looper.b_fd_chi2_vs_td0_pos->Write();


  rs_ss_looper.b_flight_dist_vs_dstm_neg->Write();
  rs_ss_looper.b_corr_mass_vs_dstm_neg->Write();
  rs_ss_looper.dtf_chi2_vs_dstm_neg->Write();
  rs_ss_looper.muIPchi2_vs_dstm_neg->Write();
  rs_ss_looper.muIPchi2_vs_dstm_zoom_neg->Write();
  rs_ss_looper.logmuIPchi2_vs_dstm_neg->Write();
  rs_ss_looper.b_endvertex_chi2_vs_dstm_neg->Write();
  rs_ss_looper.b_fd_chi2_vs_dstm_neg->Write();


  rs_ss_looper.b_flight_dist_vs_td0_neg->Write();
  rs_ss_looper.b_corr_mass_vs_td0_neg->Write();
  rs_ss_looper.dtf_chi2_vs_td0_neg->Write();
  rs_ss_looper.muIPchi2_vs_td0_neg->Write();
  rs_ss_looper.muIPchi2_vs_td0_zoom_neg->Write();
  rs_ss_looper.logmuIPchi2_vs_td0_neg->Write();
  rs_ss_looper.b_endvertex_chi2_vs_td0_neg->Write();
  rs_ss_looper.b_fd_chi2_vs_td0_neg->Write();

  

  rs_ss_looper.b_flight_dist_vs_td0->Write();
  rs_ss_looper.b_corr_mass_vs_td0->Write();
  rs_ss_looper.dtf_chi2_vs_td0->Write();
  rs_ss_looper.muIPchi2_vs_td0->Write();
  rs_ss_looper.muIPchi2_vs_td0_zoom->Write();
  rs_ss_looper.logmuIPchi2_vs_td0->Write();
  rs_ss_looper.b_endvertex_chi2_vs_td0->Write();
  rs_ss_looper.b_fd_chi2_vs_td0->Write();

  for(auto hist: rs_ss_looper.dstar_pt_bins){
    hist->Write();
  }
  for(auto hist: rs_ss_looper.dstar_p_bins){
    hist->Write();
  }
  for(auto hist: rs_ss_looper.mu_pt_bins){
    hist->Write();
  }
  for(auto hist: rs_ss_looper.mu_p_bins){
    hist->Write();
  }
  for(auto hist: rs_ss_looper.mu_log_ip_bins){
    hist->Write();
  }
  //pid
  for(auto hist: rs_ss_looper.kpidk_bins){
    hist->Write();
  }
  for(auto hist: rs_ss_looper.pipidk_bins){
    hist->Write();
  }
  
  //5x5 matrix
  for(auto hist: rs_ss_looper.thepidMatrix){
    hist->Write();
  }
  rs_ss_looper.td0_bin_neg10_to_neg075->Write();
  rs_ss_looper.td0_bin_neg075_to_neg05->Write();
  for(auto hist: rs_ss_looper.td0_bins){
    hist->Write();
  }
  
  //pos
  for(auto hist: rs_ss_looper.td0_pos_bins){
    hist->Write();
  }
  //neg
  for(auto hist: rs_ss_looper.td0_neg_bins){
    hist->Write();
  }

  for(int i=0; i<20;++i){
    rs_ss_looper.the_ghost_prob_bins[i]->Write();
  }
  rs_ss_looper.d_logIPchi2_vs_dstm->Write();
  rs_ss_looper.d_logIPchi2_vs_td0->Write();
  rs_ss_looper.d_logIPchi2_vs_dstm_pos->Write();
  rs_ss_looper.d_logIPchi2_vs_td0_pos->Write();
  rs_ss_looper.d_logIPchi2_vs_dstm_neg->Write();
  rs_ss_looper.d_logIPchi2_vs_td0_neg->Write();
  rs_ss_looper.muon_vs_slow_pion_OWNPV_X->Write();
  rs_ss_looper.muon_vs_slow_pion_OWNPV_Y->Write();
  rs_ss_looper.muon_vs_slow_pion_OWNPV_Z->Write();

  
  fout->Close();
  WrongB wrongb("wrongb",rs_looper,rs_ss_looper);
  wrongb.MakeMassComparisons();
  wrongb.CompareIPchi2();

  //ws
  TFile *fout2 = new TFile("./SavedFits/ws_mass.root","RECREATE");
  fout2->cd();
  ws_looper.dstar_mass_plot->Write();
  ws_looper.d0_mass_plot->Write();
  ws_looper.b_mass_plot->Write();
  ws_looper.dstar_pt->Write();
  ws_looper.dstar_p->Write();
  ws_looper.mu_pt->Write();
  ws_looper.mu_p->Write();
  ws_looper.mu_log_ip->Write();
  ws_looper.pis_ghost_prob->Write();
  ws_looper.pis_ghost_prob_pos->Write();
  ws_looper.pis_ghost_prob_neg->Write();
  ws_looper.pis_match_chi2->Write();
  ws_looper.pis_match_chi2_pos->Write();
  ws_looper.pis_match_chi2_neg->Write();
  ws_looper.pis_match_chi2_vs_dstm->Write();
  ws_looper.pis_match_chi2_vs_td0->Write();
  ws_looper.dstar_mass_plot_pos->Write();
  ws_looper.dstar_mass_plot_neg->Write();
  ws_looper.b_flight_dist->Write();
  ws_looper.b_flight_dist_vs_dstm->Write();
  ws_looper.b_corr_mass_vs_dstm->Write();
  ws_looper.dtf_chi2_vs_dstm->Write();
  ws_looper.b_endvertex_chi2_vs_dstm->Write();
  ws_looper.b_fd_chi2_vs_dstm->Write();

  ws_looper.b_flight_dist_vs_dstm_pos->Write();
  ws_looper.b_corr_mass_vs_dstm_pos->Write();
  ws_looper.dtf_chi2_vs_dstm_pos->Write();
  ws_looper.muIPchi2_vs_dstm_pos->Write();
  ws_looper.muIPchi2_vs_dstm_zoom_pos->Write();
  ws_looper.logmuIPchi2_vs_dstm_pos->Write();
  ws_looper.b_endvertex_chi2_vs_dstm_pos->Write();
  ws_looper.b_fd_chi2_vs_dstm_pos->Write();

  ws_looper.b_flight_dist_vs_td0_pos->Write();
  ws_looper.b_corr_mass_vs_td0_pos->Write();
  ws_looper.dtf_chi2_vs_td0_pos->Write();
  ws_looper.muIPchi2_vs_td0_pos->Write();
  ws_looper.muIPchi2_vs_td0_zoom_pos->Write();
  ws_looper.logmuIPchi2_vs_td0_pos->Write();
  ws_looper.b_endvertex_chi2_vs_td0_pos->Write();
  ws_looper.b_fd_chi2_vs_td0_pos->Write();


  ws_looper.b_flight_dist_vs_dstm_neg->Write();
  ws_looper.b_corr_mass_vs_dstm_neg->Write();
  ws_looper.dtf_chi2_vs_dstm_neg->Write();
  ws_looper.muIPchi2_vs_dstm_neg->Write();
  ws_looper.muIPchi2_vs_dstm_zoom_neg->Write();
  ws_looper.logmuIPchi2_vs_dstm_neg->Write();
  ws_looper.b_endvertex_chi2_vs_dstm_neg->Write();
  ws_looper.b_fd_chi2_vs_dstm_neg->Write();


  ws_looper.b_flight_dist_vs_td0_neg->Write();
  ws_looper.b_corr_mass_vs_td0_neg->Write();
  ws_looper.dtf_chi2_vs_td0_neg->Write();
  ws_looper.muIPchi2_vs_td0_neg->Write();
  ws_looper.muIPchi2_vs_td0_zoom_neg->Write();
  ws_looper.logmuIPchi2_vs_td0_neg->Write();
  ws_looper.b_endvertex_chi2_vs_td0_neg->Write();
  ws_looper.b_fd_chi2_vs_td0_neg->Write();

  

  ws_looper.b_flight_dist_vs_td0->Write();
  ws_looper.b_corr_mass_vs_td0->Write();
  ws_looper.dtf_chi2_vs_td0->Write();
  ws_looper.muIPchi2_vs_td0->Write();
  ws_looper.muIPchi2_vs_td0_zoom->Write();
  ws_looper.logmuIPchi2_vs_td0->Write();
  ws_looper.b_endvertex_chi2_vs_td0->Write();
  ws_looper.b_fd_chi2_vs_td0->Write();

  ws_looper.dst_mass_vs_kpidk->Write();
  ws_looper.dst_mass_vs_pipidk->Write();
  ws_looper.decay_time_distr->Write();

  for(auto hist: ws_looper.dstar_pt_bins){
    hist->Write();
  }
  for(auto hist: ws_looper.dstar_p_bins){
    hist->Write();
  }
  for(auto hist: ws_looper.mu_pt_bins){
    hist->Write();
  }
  for(auto hist: ws_looper.mu_p_bins){
    hist->Write();
  }
  for(auto hist: ws_looper.mu_log_ip_bins){
    hist->Write();
  }
  //pid
  for(auto hist: ws_looper.kpidk_bins){
    hist->Write();
  }
  for(auto hist: ws_looper.pipidk_bins){
    hist->Write();
  }
  
  //5x5 matrix
  for(auto hist: ws_looper.thepidMatrix){
    hist->Write();
  }

  ws_looper.td0_bin_neg10_to_neg075->Write();
  ws_looper.td0_bin_neg075_to_neg05->Write();
  for(auto hist: ws_looper.td0_bins){
    hist->Write();
  }
  for(auto hist:ws_looper.td0_pos_bins){
    hist->Write();
  }
  for(auto hist: ws_looper.td0_neg_bins){
    hist->Write();
  }
  for(int i=0; i<20;++i){
    ws_looper.the_ghost_prob_bins[i]->Write();
  }
  ws_looper.d_logIPchi2_vs_dstm->Write();
  ws_looper.d_logIPchi2_vs_td0->Write();
  ws_looper.d_logIPchi2_vs_dstm_pos->Write();
  ws_looper.d_logIPchi2_vs_td0_pos->Write();
  ws_looper.d_logIPchi2_vs_dstm_neg->Write();
  ws_looper.d_logIPchi2_vs_td0_neg->Write();
  ws_looper.muon_vs_slow_pion_OWNPV_X->Write();
  ws_looper.muon_vs_slow_pion_OWNPV_Y->Write();
  ws_looper.muon_vs_slow_pion_OWNPV_Z->Write();


  //ss
  ws_ss_looper.dstar_mass_plot->Write();
  ws_ss_looper.d0_mass_plot->Write();
  ws_ss_looper.b_mass_plot->Write();
  ws_ss_looper.decay_time_distr->Write();
  ws_ss_looper.dstar_mass_vs_muIPchi2->Write();
  ws_ss_looper.dstar_mass_vs_muIPchi2->Write();
  ws_ss_looper.dstar_pt->Write();
  ws_ss_looper.dstar_p->Write();
  ws_ss_looper.mu_pt->Write();
  ws_ss_looper.mu_p->Write();
  ws_ss_looper.mu_log_ip->Write();
  ws_ss_looper.pis_ghost_prob->Write();
  ws_ss_looper.pis_ghost_prob_pos->Write();
  ws_ss_looper.pis_ghost_prob_neg->Write();
  ws_ss_looper.pis_match_chi2->Write();
  ws_ss_looper.pis_match_chi2_pos->Write();
  ws_ss_looper.pis_match_chi2_neg->Write();
  ws_ss_looper.pis_match_chi2_vs_dstm->Write();
  ws_ss_looper.pis_match_chi2_vs_td0->Write();
  ws_ss_looper.dst_mass_vs_kpidk->Write();
  ws_ss_looper.dst_mass_vs_pipidk->Write();
  ws_ss_looper.dstar_mass_plot_pos->Write();
  ws_ss_looper.dstar_mass_plot_neg->Write();
  ws_ss_looper.b_flight_dist->Write();
  ws_ss_looper.b_flight_dist_vs_dstm->Write();
  ws_ss_looper.b_corr_mass_vs_dstm->Write();
  ws_ss_looper.dtf_chi2_vs_dstm->Write();
  ws_ss_looper.b_endvertex_chi2_vs_dstm->Write();
  ws_ss_looper.b_fd_chi2_vs_dstm->Write();

  ws_ss_looper.b_flight_dist_vs_dstm_pos->Write();
  ws_ss_looper.b_corr_mass_vs_dstm_pos->Write();
  ws_ss_looper.dtf_chi2_vs_dstm_pos->Write();
  ws_ss_looper.muIPchi2_vs_dstm_pos->Write();
  ws_ss_looper.muIPchi2_vs_dstm_zoom_pos->Write();
  ws_ss_looper.logmuIPchi2_vs_dstm_pos->Write();
  ws_ss_looper.b_endvertex_chi2_vs_dstm_pos->Write();
  ws_ss_looper.b_fd_chi2_vs_dstm_pos->Write();

  ws_ss_looper.b_flight_dist_vs_td0_pos->Write();
  ws_ss_looper.b_corr_mass_vs_td0_pos->Write();
  ws_ss_looper.dtf_chi2_vs_td0_pos->Write();
  ws_ss_looper.muIPchi2_vs_td0_pos->Write();
  ws_ss_looper.muIPchi2_vs_td0_zoom_pos->Write();
  ws_ss_looper.logmuIPchi2_vs_td0_pos->Write();
  ws_ss_looper.b_endvertex_chi2_vs_td0_pos->Write();
  ws_ss_looper.b_fd_chi2_vs_td0_pos->Write();


  ws_ss_looper.b_flight_dist_vs_dstm_neg->Write();
  ws_ss_looper.b_corr_mass_vs_dstm_neg->Write();
  ws_ss_looper.dtf_chi2_vs_dstm_neg->Write();
  ws_ss_looper.muIPchi2_vs_dstm_neg->Write();
  ws_ss_looper.muIPchi2_vs_dstm_zoom_neg->Write();
  ws_ss_looper.logmuIPchi2_vs_dstm_neg->Write();
  ws_ss_looper.b_endvertex_chi2_vs_dstm_neg->Write();
  ws_ss_looper.b_fd_chi2_vs_dstm_neg->Write();


  ws_ss_looper.b_flight_dist_vs_td0_neg->Write();
  ws_ss_looper.b_corr_mass_vs_td0_neg->Write();
  ws_ss_looper.dtf_chi2_vs_td0_neg->Write();
  ws_ss_looper.muIPchi2_vs_td0_neg->Write();
  ws_ss_looper.muIPchi2_vs_td0_zoom_neg->Write();
  ws_ss_looper.logmuIPchi2_vs_td0_neg->Write();
  ws_ss_looper.b_endvertex_chi2_vs_td0_neg->Write();
  ws_ss_looper.b_fd_chi2_vs_td0_neg->Write();  

  ws_ss_looper.b_flight_dist_vs_td0->Write();
  ws_ss_looper.b_corr_mass_vs_td0->Write();
  ws_ss_looper.dtf_chi2_vs_td0->Write();
  ws_ss_looper.muIPchi2_vs_td0->Write();
  ws_ss_looper.muIPchi2_vs_td0_zoom->Write();
  ws_ss_looper.logmuIPchi2_vs_td0->Write();
  ws_ss_looper.b_endvertex_chi2_vs_td0->Write();
  ws_ss_looper.b_fd_chi2_vs_td0->Write();

  for(auto hist: ws_ss_looper.dstar_pt_bins){
    hist->Write();
  }
  for(auto hist: ws_ss_looper.dstar_p_bins){
    hist->Write();
  }
  for(auto hist: ws_ss_looper.mu_pt_bins){
    hist->Write();
  }
  for(auto hist: ws_ss_looper.mu_p_bins){
    hist->Write();
  }
  for(auto hist: ws_ss_looper.mu_log_ip_bins){
    hist->Write();
  }
  
  //pid
  for(auto hist: ws_ss_looper.kpidk_bins){
    hist->Write();
  }
  for(auto hist: ws_ss_looper.pipidk_bins){
    hist->Write();
  }
  //5x5 matrix
  for(auto hist: ws_ss_looper.thepidMatrix){
    hist->Write();
  }

  ws_ss_looper.td0_bin_neg10_to_neg075->Write();
  ws_ss_looper.td0_bin_neg075_to_neg05->Write();
  for(auto hist: ws_ss_looper.td0_bins){
    hist->Write();
  }
  //pos
  for(auto hist: ws_ss_looper.td0_pos_bins){
    hist->Write();
  }
  for(auto hist: ws_ss_looper.td0_neg_bins){
    hist->Write();
  }
  for(int i=0; i<20;++i){
    ws_ss_looper.the_ghost_prob_bins[i]->Write();
  }
  
  ws_ss_looper.d_logIPchi2_vs_dstm->Write();
  ws_ss_looper.d_logIPchi2_vs_td0->Write();
  ws_ss_looper.d_logIPchi2_vs_dstm_pos->Write();
  ws_ss_looper.d_logIPchi2_vs_td0_pos->Write();
  ws_ss_looper.d_logIPchi2_vs_dstm_neg->Write();
  ws_ss_looper.d_logIPchi2_vs_td0_neg->Write();

  ws_ss_looper.muon_vs_slow_pion_OWNPV_X->Write();
  ws_ss_looper.muon_vs_slow_pion_OWNPV_Y->Write();
  ws_ss_looper.muon_vs_slow_pion_OWNPV_Z->Write();

  
  fout2->Close();
  WrongB wrongbws("wrongbws",ws_looper,ws_ss_looper);
  wrongbws.MakeMassComparisons();
  wrongbws.CompareIPchi2();

  
  /*
    
  massFit fit("rs","rbw");
  fit.initModelValues();
  fit.setData(rs_looper.dstar_mass_plot);
  fit.fit();
  
  fit.saveFinalFit();
  */
  return 0;
}
