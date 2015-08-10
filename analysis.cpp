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
  cout<<"ws tree"<<endl;
  DT_D0_mix_CPV ws_looper(ws_tree);
  ws_looper.Loop();
  ws_looper.bs_plot->SavePlots();
  cout<<"ws ss tree"<<endl;
  
  DT_D0_mix_CPV ws_ss_looper(ws_ss_tree);
  ws_ss_looper.Loop();
  
  
  TFile *fout = new TFile("./SavedFits/rs_mass.root","RECREATE");
  fout->cd();
  rs_looper.dstar_mass_plot->Write();
  rs_looper.b_mass_plot->Write();
  rs_looper.dstar_pt->Write();
  rs_looper.dstar_p->Write();
  rs_looper.mu_pt->Write();
  rs_looper.mu_p->Write();
  rs_looper.mu_log_ip->Write();
  rs_looper.pis_ghost_prob->Write();
  rs_looper.dst_mass_vs_kpidk->Write();
  rs_looper.dst_mass_vs_pipidk->Write();
  rs_looper.dstar_mass_plot_pos->Write();
  rs_looper.dstar_mass_plot_neg->Write();

  rs_looper.b_flight_dist_vs_dstm_pos->Write();
  rs_looper.b_corr_mass_vs_dstm_pos->Write();
  rs_looper.dtf_chi2_vs_dstm_pos->Write();
  rs_looper.muIPchi2_vs_dstm_pos->Write();//already done
  rs_looper.b_endvertex_chi2_vs_dstm_pos->Write();
  rs_looper.b_fd_chi2_vs_dstm_pos->Write();

  rs_looper.b_flight_dist_vs_td0_pos->Write();
  rs_looper.b_corr_mass_vs_td0_pos->Write();
  rs_looper.dtf_chi2_vs_td0_pos->Write();
  rs_looper.muIPchi2_vs_td0_pos->Write();
  rs_looper.b_endvertex_chi2_vs_td0_pos->Write();
  rs_looper.b_fd_chi2_vs_td0_pos->Write();


  rs_looper.b_flight_dist_vs_dstm_neg->Write();
  rs_looper.b_corr_mass_vs_dstm_neg->Write();
  rs_looper.dtf_chi2_vs_dstm_neg->Write();
  rs_looper.muIPchi2_vs_dstm_neg->Write();//already done
  rs_looper.b_endvertex_chi2_vs_dstm_neg->Write();
  rs_looper.b_fd_chi2_vs_dstm_neg->Write();


  rs_looper.b_flight_dist_vs_td0_neg->Write();
  rs_looper.b_corr_mass_vs_td0_neg->Write();
  rs_looper.dtf_chi2_vs_td0_neg->Write();
  rs_looper.muIPchi2_vs_td0_neg->Write();
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
  rs_looper.b_endvertex_chi2_vs_td0->Write();
  rs_looper.b_fd_chi2_vs_td0->Write();

  
  rs_looper.decay_time_distr->Write();
  rs_looper.dstar_mass_pt_bin1->Write();
  rs_looper.dstar_mass_pt_bin2->Write();
  rs_looper.dstar_mass_pt_bin3->Write();
  rs_looper.dstar_mass_pt_bin4->Write();
  rs_looper.dstar_mass_pt_bin5->Write();
  rs_looper.dstar_mass_p_bin1->Write();
  rs_looper.dstar_mass_p_bin2->Write();
  rs_looper.dstar_mass_p_bin3->Write();
  rs_looper.dstar_mass_p_bin4->Write();
  rs_looper.dstar_mass_p_bin5->Write();

  rs_looper.mu_mass_pt_bin1->Write();
  rs_looper.mu_mass_pt_bin2->Write();
  rs_looper.mu_mass_pt_bin3->Write();
  rs_looper.mu_mass_pt_bin4->Write();
  rs_looper.mu_mass_pt_bin5->Write();
  rs_looper.mu_mass_p_bin1->Write();
  rs_looper.mu_mass_p_bin2->Write();
  rs_looper.mu_mass_p_bin3->Write();
  rs_looper.mu_mass_p_bin4->Write();
  rs_looper.mu_mass_p_bin5->Write();

  rs_looper.mu_log_ip_bin1->Write();
  rs_looper.mu_log_ip_bin2->Write();
  rs_looper.mu_log_ip_bin3->Write();
  rs_looper.mu_log_ip_bin4->Write();
  rs_looper.mu_log_ip_bin5->Write();
  //pid
  rs_looper.k_pid_k_bin1->Write();
  rs_looper.k_pid_k_bin2->Write();
  rs_looper.k_pid_k_bin3->Write();
  rs_looper.k_pid_k_bin4->Write();
  rs_looper.k_pid_k_bin5->Write();

  rs_looper.pi_pid_k_bin1->Write();
  rs_looper.pi_pid_k_bin2->Write();
  rs_looper.pi_pid_k_bin3->Write();
  rs_looper.pi_pid_k_bin4->Write();
  rs_looper.pi_pid_k_bin5->Write();

  for(int i=0; i<20;++i){
    rs_looper.the_ghost_prob_bins[i]->Write();
  }
  
  
  //5x5 matrix
  rs_looper.pi_pid_k_bin1_k_pid_k_bin1->Write();
  rs_looper.pi_pid_k_bin1_k_pid_k_bin2->Write();
  rs_looper.pi_pid_k_bin1_k_pid_k_bin3->Write();
  rs_looper.pi_pid_k_bin1_k_pid_k_bin4->Write();
  rs_looper.pi_pid_k_bin1_k_pid_k_bin5->Write();

  rs_looper.pi_pid_k_bin2_k_pid_k_bin1->Write();
  rs_looper.pi_pid_k_bin2_k_pid_k_bin2->Write();
  rs_looper.pi_pid_k_bin2_k_pid_k_bin3->Write();
  rs_looper.pi_pid_k_bin2_k_pid_k_bin4->Write();
  rs_looper.pi_pid_k_bin2_k_pid_k_bin5->Write();

  rs_looper.pi_pid_k_bin3_k_pid_k_bin1->Write();
  rs_looper.pi_pid_k_bin3_k_pid_k_bin2->Write();
  rs_looper.pi_pid_k_bin3_k_pid_k_bin3->Write();
  rs_looper.pi_pid_k_bin3_k_pid_k_bin4->Write();
  rs_looper.pi_pid_k_bin3_k_pid_k_bin5->Write();

  rs_looper.pi_pid_k_bin4_k_pid_k_bin1->Write();
  rs_looper.pi_pid_k_bin4_k_pid_k_bin2->Write();
  rs_looper.pi_pid_k_bin4_k_pid_k_bin3->Write();
  rs_looper.pi_pid_k_bin4_k_pid_k_bin4->Write();
  rs_looper.pi_pid_k_bin4_k_pid_k_bin5->Write();

  rs_looper.pi_pid_k_bin5_k_pid_k_bin1->Write();
  rs_looper.pi_pid_k_bin5_k_pid_k_bin2->Write();
  rs_looper.pi_pid_k_bin5_k_pid_k_bin3->Write();
  rs_looper.pi_pid_k_bin5_k_pid_k_bin4->Write();
  rs_looper.pi_pid_k_bin5_k_pid_k_bin5->Write();

  rs_looper.td0_bin_neg10_to_neg075->Write();
  rs_looper.td0_bin_neg075_to_neg05->Write();
  rs_looper.td0_bin1->Write();
  rs_looper.td0_bin2->Write();
  rs_looper.td0_bin3->Write();
  rs_looper.td0_bin4->Write();
  rs_looper.td0_bin5->Write();

  //pos
  rs_looper.td0_pos_bin1->Write();
  rs_looper.td0_pos_bin2->Write();
  rs_looper.td0_pos_bin3->Write();
  rs_looper.td0_pos_bin4->Write();
  rs_looper.td0_pos_bin5->Write();
  //neg
  rs_looper.td0_neg_bin1->Write();
  rs_looper.td0_neg_bin2->Write();
  rs_looper.td0_neg_bin3->Write();
  rs_looper.td0_neg_bin4->Write();
  rs_looper.td0_neg_bin5->Write();

  
  //ss
  
  rs_ss_looper.dstar_mass_plot->Write();
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
  rs_ss_looper.muIPchi2_vs_dstm_pos->Write();//already done
  rs_ss_looper.b_endvertex_chi2_vs_dstm_pos->Write();
  rs_ss_looper.b_fd_chi2_vs_dstm_pos->Write();

  rs_ss_looper.b_flight_dist_vs_td0_pos->Write();
  rs_ss_looper.b_corr_mass_vs_td0_pos->Write();
  rs_ss_looper.dtf_chi2_vs_td0_pos->Write();
  rs_ss_looper.muIPchi2_vs_td0_pos->Write();
  rs_ss_looper.b_endvertex_chi2_vs_td0_pos->Write();
  rs_ss_looper.b_fd_chi2_vs_td0_pos->Write();


  rs_ss_looper.b_flight_dist_vs_dstm_neg->Write();
  rs_ss_looper.b_corr_mass_vs_dstm_neg->Write();
  rs_ss_looper.dtf_chi2_vs_dstm_neg->Write();
  rs_ss_looper.muIPchi2_vs_dstm_neg->Write();//already done
  rs_ss_looper.b_endvertex_chi2_vs_dstm_neg->Write();
  rs_ss_looper.b_fd_chi2_vs_dstm_neg->Write();


  rs_ss_looper.b_flight_dist_vs_td0_neg->Write();
  rs_ss_looper.b_corr_mass_vs_td0_neg->Write();
  rs_ss_looper.dtf_chi2_vs_td0_neg->Write();
  rs_ss_looper.muIPchi2_vs_td0_neg->Write();
  rs_ss_looper.b_endvertex_chi2_vs_td0_neg->Write();
  rs_ss_looper.b_fd_chi2_vs_td0_neg->Write();

  

  rs_ss_looper.b_flight_dist_vs_td0->Write();
  rs_ss_looper.b_corr_mass_vs_td0->Write();
  rs_ss_looper.dtf_chi2_vs_td0->Write();
  rs_ss_looper.muIPchi2_vs_td0->Write();
  rs_ss_looper.b_endvertex_chi2_vs_td0->Write();
  rs_ss_looper.b_fd_chi2_vs_td0->Write();

  
  rs_ss_looper.dstar_mass_pt_bin1->Write();
  rs_ss_looper.dstar_mass_pt_bin2->Write();
  rs_ss_looper.dstar_mass_pt_bin3->Write();
  rs_ss_looper.dstar_mass_pt_bin4->Write();
  rs_ss_looper.dstar_mass_pt_bin5->Write();
  rs_ss_looper.dstar_mass_p_bin1->Write();
  rs_ss_looper.dstar_mass_p_bin2->Write();
  rs_ss_looper.dstar_mass_p_bin3->Write();
  rs_ss_looper.dstar_mass_p_bin4->Write();
  rs_ss_looper.dstar_mass_p_bin5->Write();

  rs_ss_looper.mu_mass_pt_bin1->Write();
  rs_ss_looper.mu_mass_pt_bin2->Write();
  rs_ss_looper.mu_mass_pt_bin3->Write();
  rs_ss_looper.mu_mass_pt_bin4->Write();
  rs_ss_looper.mu_mass_pt_bin5->Write();
  rs_ss_looper.mu_mass_p_bin1->Write();
  rs_ss_looper.mu_mass_p_bin2->Write();
  rs_ss_looper.mu_mass_p_bin3->Write();
  rs_ss_looper.mu_mass_p_bin4->Write();
  rs_ss_looper.mu_mass_p_bin5->Write();

  
  rs_ss_looper.mu_log_ip_bin1->Write();
  rs_ss_looper.mu_log_ip_bin2->Write();
  rs_ss_looper.mu_log_ip_bin3->Write();
  rs_ss_looper.mu_log_ip_bin4->Write();
  rs_ss_looper.mu_log_ip_bin5->Write();

    //pid
  rs_ss_looper.k_pid_k_bin1->Write();
  rs_ss_looper.k_pid_k_bin2->Write();
  rs_ss_looper.k_pid_k_bin3->Write();
  rs_ss_looper.k_pid_k_bin4->Write();
  rs_ss_looper.k_pid_k_bin5->Write();

  rs_ss_looper.pi_pid_k_bin1->Write();
  rs_ss_looper.pi_pid_k_bin2->Write();
  rs_ss_looper.pi_pid_k_bin3->Write();
  rs_ss_looper.pi_pid_k_bin4->Write();
  rs_ss_looper.pi_pid_k_bin5->Write();
  
  //5x5 matrix
  rs_ss_looper.pi_pid_k_bin1_k_pid_k_bin1->Write();
  rs_ss_looper.pi_pid_k_bin1_k_pid_k_bin2->Write();
  rs_ss_looper.pi_pid_k_bin1_k_pid_k_bin3->Write();
  rs_ss_looper.pi_pid_k_bin1_k_pid_k_bin4->Write();
  rs_ss_looper.pi_pid_k_bin1_k_pid_k_bin5->Write();

  rs_ss_looper.pi_pid_k_bin2_k_pid_k_bin1->Write();
  rs_ss_looper.pi_pid_k_bin2_k_pid_k_bin2->Write();
  rs_ss_looper.pi_pid_k_bin2_k_pid_k_bin3->Write();
  rs_ss_looper.pi_pid_k_bin2_k_pid_k_bin4->Write();
  rs_ss_looper.pi_pid_k_bin2_k_pid_k_bin5->Write();

  rs_ss_looper.pi_pid_k_bin3_k_pid_k_bin1->Write();
  rs_ss_looper.pi_pid_k_bin3_k_pid_k_bin2->Write();
  rs_ss_looper.pi_pid_k_bin3_k_pid_k_bin3->Write();
  rs_ss_looper.pi_pid_k_bin3_k_pid_k_bin4->Write();
  rs_ss_looper.pi_pid_k_bin3_k_pid_k_bin5->Write();

  rs_ss_looper.pi_pid_k_bin4_k_pid_k_bin1->Write();
  rs_ss_looper.pi_pid_k_bin4_k_pid_k_bin2->Write();
  rs_ss_looper.pi_pid_k_bin4_k_pid_k_bin3->Write();
  rs_ss_looper.pi_pid_k_bin4_k_pid_k_bin4->Write();
  rs_ss_looper.pi_pid_k_bin4_k_pid_k_bin5->Write();

  rs_ss_looper.pi_pid_k_bin5_k_pid_k_bin1->Write();
  rs_ss_looper.pi_pid_k_bin5_k_pid_k_bin2->Write();
  rs_ss_looper.pi_pid_k_bin5_k_pid_k_bin3->Write();
  rs_ss_looper.pi_pid_k_bin5_k_pid_k_bin4->Write();
  rs_ss_looper.pi_pid_k_bin5_k_pid_k_bin5->Write();

  rs_ss_looper.td0_bin_neg10_to_neg075->Write();
  rs_ss_looper.td0_bin_neg075_to_neg05->Write();
  rs_ss_looper.td0_bin1->Write();
  rs_ss_looper.td0_bin2->Write();
  rs_ss_looper.td0_bin3->Write();
  rs_ss_looper.td0_bin4->Write();
  rs_ss_looper.td0_bin5->Write();
  //pos
  rs_ss_looper.td0_pos_bin1->Write();
  rs_ss_looper.td0_pos_bin2->Write();
  rs_ss_looper.td0_pos_bin3->Write();
  rs_ss_looper.td0_pos_bin4->Write();
  rs_ss_looper.td0_pos_bin5->Write();
  //neg
  rs_ss_looper.td0_neg_bin1->Write();
  rs_ss_looper.td0_neg_bin2->Write();
  rs_ss_looper.td0_neg_bin3->Write();
  rs_ss_looper.td0_neg_bin4->Write();
  rs_ss_looper.td0_neg_bin5->Write();

  for(int i=0; i<20;++i){
    rs_ss_looper.the_ghost_prob_bins[i]->Write();
  }

  
  fout->Close();
  WrongB wrongb("wrongb",rs_looper,rs_ss_looper);
  wrongb.MakeMassComparisons();
  wrongb.CompareIPchi2();

  //ws
  TFile *fout2 = new TFile("./SavedFits/ws_mass.root","RECREATE");
  fout2->cd();
  ws_looper.dstar_mass_plot->Write();
  ws_looper.b_mass_plot->Write();
  ws_looper.dstar_pt->Write();
  ws_looper.dstar_p->Write();
  ws_looper.mu_pt->Write();
  ws_looper.mu_p->Write();
  ws_looper.mu_log_ip->Write();
  ws_looper.pis_ghost_prob->Write();
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
  ws_looper.muIPchi2_vs_dstm_pos->Write();//already done
  ws_looper.b_endvertex_chi2_vs_dstm_pos->Write();
  ws_looper.b_fd_chi2_vs_dstm_pos->Write();

  ws_looper.b_flight_dist_vs_td0_pos->Write();
  ws_looper.b_corr_mass_vs_td0_pos->Write();
  ws_looper.dtf_chi2_vs_td0_pos->Write();
  ws_looper.muIPchi2_vs_td0_pos->Write();
  ws_looper.b_endvertex_chi2_vs_td0_pos->Write();
  ws_looper.b_fd_chi2_vs_td0_pos->Write();


  ws_looper.b_flight_dist_vs_dstm_neg->Write();
  ws_looper.b_corr_mass_vs_dstm_neg->Write();
  ws_looper.dtf_chi2_vs_dstm_neg->Write();
  ws_looper.muIPchi2_vs_dstm_neg->Write();//already done
  ws_looper.b_endvertex_chi2_vs_dstm_neg->Write();
  ws_looper.b_fd_chi2_vs_dstm_neg->Write();


  ws_looper.b_flight_dist_vs_td0_neg->Write();
  ws_looper.b_corr_mass_vs_td0_neg->Write();
  ws_looper.dtf_chi2_vs_td0_neg->Write();
  ws_looper.muIPchi2_vs_td0_neg->Write();
  ws_looper.b_endvertex_chi2_vs_td0_neg->Write();
  ws_looper.b_fd_chi2_vs_td0_neg->Write();

  

  ws_looper.b_flight_dist_vs_td0->Write();
  ws_looper.b_corr_mass_vs_td0->Write();
  ws_looper.dtf_chi2_vs_td0->Write();
  ws_looper.muIPchi2_vs_td0->Write();
  ws_looper.b_endvertex_chi2_vs_td0->Write();
  ws_looper.b_fd_chi2_vs_td0->Write();

  ws_looper.dst_mass_vs_kpidk->Write();
  ws_looper.dst_mass_vs_pipidk->Write();
  ws_looper.decay_time_distr->Write();
 
  ws_looper.dstar_mass_pt_bin1->Write();
  ws_looper.dstar_mass_pt_bin2->Write();
  ws_looper.dstar_mass_pt_bin3->Write();
  ws_looper.dstar_mass_pt_bin4->Write();
  ws_looper.dstar_mass_pt_bin5->Write();
  ws_looper.dstar_mass_p_bin1->Write();
  ws_looper.dstar_mass_p_bin2->Write();
  ws_looper.dstar_mass_p_bin3->Write();
  ws_looper.dstar_mass_p_bin4->Write();
  ws_looper.dstar_mass_p_bin5->Write();

  ws_looper.mu_mass_pt_bin1->Write();
  ws_looper.mu_mass_pt_bin2->Write();
  ws_looper.mu_mass_pt_bin3->Write();
  ws_looper.mu_mass_pt_bin4->Write();
  ws_looper.mu_mass_pt_bin5->Write();
  ws_looper.mu_mass_p_bin1->Write();
  ws_looper.mu_mass_p_bin2->Write();
  ws_looper.mu_mass_p_bin3->Write();
  ws_looper.mu_mass_p_bin4->Write();
  ws_looper.mu_mass_p_bin5->Write();
  
  ws_looper.mu_log_ip_bin1->Write();
  ws_looper.mu_log_ip_bin2->Write();
  ws_looper.mu_log_ip_bin3->Write();
  ws_looper.mu_log_ip_bin4->Write();
  ws_looper.mu_log_ip_bin5->Write();

  //pid
  ws_looper.k_pid_k_bin1->Write();
  ws_looper.k_pid_k_bin2->Write();
  ws_looper.k_pid_k_bin3->Write();
  ws_looper.k_pid_k_bin4->Write();
  ws_looper.k_pid_k_bin5->Write();

  ws_looper.pi_pid_k_bin1->Write();
  ws_looper.pi_pid_k_bin2->Write();
  ws_looper.pi_pid_k_bin3->Write();
  ws_looper.pi_pid_k_bin4->Write();
  ws_looper.pi_pid_k_bin5->Write();
  
  //5x5 matrix
  ws_looper.pi_pid_k_bin1_k_pid_k_bin1->Write();
  ws_looper.pi_pid_k_bin1_k_pid_k_bin2->Write();
  ws_looper.pi_pid_k_bin1_k_pid_k_bin3->Write();
  ws_looper.pi_pid_k_bin1_k_pid_k_bin4->Write();
  ws_looper.pi_pid_k_bin1_k_pid_k_bin5->Write();

  ws_looper.pi_pid_k_bin2_k_pid_k_bin1->Write();
  ws_looper.pi_pid_k_bin2_k_pid_k_bin2->Write();
  ws_looper.pi_pid_k_bin2_k_pid_k_bin3->Write();
  ws_looper.pi_pid_k_bin2_k_pid_k_bin4->Write();
  ws_looper.pi_pid_k_bin2_k_pid_k_bin5->Write();

  ws_looper.pi_pid_k_bin3_k_pid_k_bin1->Write();
  ws_looper.pi_pid_k_bin3_k_pid_k_bin2->Write();
  ws_looper.pi_pid_k_bin3_k_pid_k_bin3->Write();
  ws_looper.pi_pid_k_bin3_k_pid_k_bin4->Write();
  ws_looper.pi_pid_k_bin3_k_pid_k_bin5->Write();

  ws_looper.pi_pid_k_bin4_k_pid_k_bin1->Write();
  ws_looper.pi_pid_k_bin4_k_pid_k_bin2->Write();
  ws_looper.pi_pid_k_bin4_k_pid_k_bin3->Write();
  ws_looper.pi_pid_k_bin4_k_pid_k_bin4->Write();
  ws_looper.pi_pid_k_bin4_k_pid_k_bin5->Write();

  ws_looper.pi_pid_k_bin5_k_pid_k_bin1->Write();
  ws_looper.pi_pid_k_bin5_k_pid_k_bin2->Write();
  ws_looper.pi_pid_k_bin5_k_pid_k_bin3->Write();
  ws_looper.pi_pid_k_bin5_k_pid_k_bin4->Write();
  ws_looper.pi_pid_k_bin5_k_pid_k_bin5->Write();

  ws_looper.td0_bin_neg10_to_neg075->Write();
  ws_looper.td0_bin_neg075_to_neg05->Write();
  ws_looper.td0_bin1->Write();
  ws_looper.td0_bin2->Write();
  ws_looper.td0_bin3->Write();
  ws_looper.td0_bin4->Write();
  ws_looper.td0_bin5->Write();

  for(int i=0; i<20;++i){
    ws_looper.the_ghost_prob_bins[i]->Write();
  }
  

  //ss
  ws_ss_looper.dstar_mass_plot->Write();
  ws_ss_looper.b_mass_plot->Write();
  ws_ss_looper.decay_time_distr->Write();
  ws_looper.dstar_mass_vs_muIPchi2->Write();
  ws_ss_looper.dstar_mass_vs_muIPchi2->Write();
  ws_ss_looper.dstar_pt->Write();
  ws_ss_looper.dstar_p->Write();
  ws_ss_looper.mu_pt->Write();
  ws_ss_looper.mu_p->Write();
  ws_ss_looper.mu_log_ip->Write();
  ws_ss_looper.pis_ghost_prob->Write();
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
  ws_ss_looper.muIPchi2_vs_dstm_pos->Write();//already done
  ws_ss_looper.b_endvertex_chi2_vs_dstm_pos->Write();
  ws_ss_looper.b_fd_chi2_vs_dstm_pos->Write();

  ws_ss_looper.b_flight_dist_vs_td0_pos->Write();
  ws_ss_looper.b_corr_mass_vs_td0_pos->Write();
  ws_ss_looper.dtf_chi2_vs_td0_pos->Write();
  ws_ss_looper.muIPchi2_vs_td0_pos->Write();
  ws_ss_looper.b_endvertex_chi2_vs_td0_pos->Write();
  ws_ss_looper.b_fd_chi2_vs_td0_pos->Write();


  ws_ss_looper.b_flight_dist_vs_dstm_neg->Write();
  ws_ss_looper.b_corr_mass_vs_dstm_neg->Write();
  ws_ss_looper.dtf_chi2_vs_dstm_neg->Write();
  ws_ss_looper.muIPchi2_vs_dstm_neg->Write();//already done
  ws_ss_looper.b_endvertex_chi2_vs_dstm_neg->Write();
  ws_ss_looper.b_fd_chi2_vs_dstm_neg->Write();


  ws_ss_looper.b_flight_dist_vs_td0_neg->Write();
  ws_ss_looper.b_corr_mass_vs_td0_neg->Write();
  ws_ss_looper.dtf_chi2_vs_td0_neg->Write();
  ws_ss_looper.muIPchi2_vs_td0_neg->Write();
  ws_ss_looper.b_endvertex_chi2_vs_td0_neg->Write();
  ws_ss_looper.b_fd_chi2_vs_td0_neg->Write();

  

  ws_ss_looper.b_flight_dist_vs_td0->Write();
  ws_ss_looper.b_corr_mass_vs_td0->Write();
  ws_ss_looper.dtf_chi2_vs_td0->Write();
  ws_ss_looper.muIPchi2_vs_td0->Write();
  ws_ss_looper.b_endvertex_chi2_vs_td0->Write();
  ws_ss_looper.b_fd_chi2_vs_td0->Write();

  ws_ss_looper.dstar_mass_pt_bin1->Write();
  ws_ss_looper.dstar_mass_pt_bin2->Write();
  ws_ss_looper.dstar_mass_pt_bin3->Write();
  ws_ss_looper.dstar_mass_pt_bin4->Write();
  ws_ss_looper.dstar_mass_pt_bin5->Write();
  ws_ss_looper.dstar_mass_p_bin1->Write();
  ws_ss_looper.dstar_mass_p_bin2->Write();
  ws_ss_looper.dstar_mass_p_bin3->Write();
  ws_ss_looper.dstar_mass_p_bin4->Write();
  ws_ss_looper.dstar_mass_p_bin5->Write();

  ws_ss_looper.mu_mass_pt_bin1->Write();
  ws_ss_looper.mu_mass_pt_bin2->Write();
  ws_ss_looper.mu_mass_pt_bin3->Write();
  ws_ss_looper.mu_mass_pt_bin4->Write();
  ws_ss_looper.mu_mass_pt_bin5->Write();
  ws_ss_looper.mu_mass_p_bin1->Write();
  ws_ss_looper.mu_mass_p_bin2->Write();
  ws_ss_looper.mu_mass_p_bin3->Write();
  ws_ss_looper.mu_mass_p_bin4->Write();
  ws_ss_looper.mu_mass_p_bin5->Write();

  ws_ss_looper.mu_log_ip_bin1->Write();
  ws_ss_looper.mu_log_ip_bin2->Write();
  ws_ss_looper.mu_log_ip_bin3->Write();
  ws_ss_looper.mu_log_ip_bin4->Write();
  ws_ss_looper.mu_log_ip_bin5->Write();

    //pid
  ws_ss_looper.k_pid_k_bin1->Write();
  ws_ss_looper.k_pid_k_bin2->Write();
  ws_ss_looper.k_pid_k_bin3->Write();
  ws_ss_looper.k_pid_k_bin4->Write();
  ws_ss_looper.k_pid_k_bin5->Write();

  ws_ss_looper.pi_pid_k_bin1->Write();
  ws_ss_looper.pi_pid_k_bin2->Write();
  ws_ss_looper.pi_pid_k_bin3->Write();
  ws_ss_looper.pi_pid_k_bin4->Write();
  ws_ss_looper.pi_pid_k_bin5->Write();

  //5x5 matrix
  ws_ss_looper.pi_pid_k_bin1_k_pid_k_bin1->Write();
  ws_ss_looper.pi_pid_k_bin1_k_pid_k_bin2->Write();
  ws_ss_looper.pi_pid_k_bin1_k_pid_k_bin3->Write();
  ws_ss_looper.pi_pid_k_bin1_k_pid_k_bin4->Write();
  ws_ss_looper.pi_pid_k_bin1_k_pid_k_bin5->Write();

  ws_ss_looper.pi_pid_k_bin2_k_pid_k_bin1->Write();
  ws_ss_looper.pi_pid_k_bin2_k_pid_k_bin2->Write();
  ws_ss_looper.pi_pid_k_bin2_k_pid_k_bin3->Write();
  ws_ss_looper.pi_pid_k_bin2_k_pid_k_bin4->Write();
  ws_ss_looper.pi_pid_k_bin2_k_pid_k_bin5->Write();

  ws_ss_looper.pi_pid_k_bin3_k_pid_k_bin1->Write();
  ws_ss_looper.pi_pid_k_bin3_k_pid_k_bin2->Write();
  ws_ss_looper.pi_pid_k_bin3_k_pid_k_bin3->Write();
  ws_ss_looper.pi_pid_k_bin3_k_pid_k_bin4->Write();
  ws_ss_looper.pi_pid_k_bin3_k_pid_k_bin5->Write();

  ws_ss_looper.pi_pid_k_bin4_k_pid_k_bin1->Write();
  ws_ss_looper.pi_pid_k_bin4_k_pid_k_bin2->Write();
  ws_ss_looper.pi_pid_k_bin4_k_pid_k_bin3->Write();
  ws_ss_looper.pi_pid_k_bin4_k_pid_k_bin4->Write();
  ws_ss_looper.pi_pid_k_bin4_k_pid_k_bin5->Write();

  ws_ss_looper.pi_pid_k_bin5_k_pid_k_bin1->Write();
  ws_ss_looper.pi_pid_k_bin5_k_pid_k_bin2->Write();
  ws_ss_looper.pi_pid_k_bin5_k_pid_k_bin3->Write();
  ws_ss_looper.pi_pid_k_bin5_k_pid_k_bin4->Write();
  ws_ss_looper.pi_pid_k_bin5_k_pid_k_bin5->Write();

  ws_ss_looper.td0_bin_neg10_to_neg075->Write();
  ws_ss_looper.td0_bin_neg075_to_neg05->Write();
  ws_ss_looper.td0_bin1->Write();
  ws_ss_looper.td0_bin2->Write();
  ws_ss_looper.td0_bin3->Write();
  ws_ss_looper.td0_bin4->Write();
  ws_ss_looper.td0_bin5->Write();
  for(int i=0; i<20;++i){
    ws_ss_looper.the_ghost_prob_bins[i]->Write();
  }
  
  
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
