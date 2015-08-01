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
#include <TString.h>
#include <TFile.h>
#include <TObject.h>
#include <TTree.h>
#include <TLegend.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TText.h>
#include <TLine.h>
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
#include "TimeIntegratedSystematicsClass.h"
#include "PlottingTools.h"
using namespace std;
using namespace PlottingTools;

int main(int argc, char* const argv[]){
  //int nSysts = 5;
  cout<<"**************"<<endl;
  cout<<"Code for processing mike's time integrated systematics"<<endl;
  cout<<"**************"<<endl;
  if(argc<2){
    cout<<"Please pass a RS datafile and fit model to process!"<<endl;
    return 0;
  }
  if(argc<3){
    cout<<"please also pass a saved fit model!"<<endl;
    return 0;
  }

  cout<<"Now processing "<<argv[1]<<endl;
  TFile * f1 = TFile::Open(argv[1]);
  TFile *f2 = TFile::Open(argv[2]);
  f2->ls();
  TString channelFromFile = argv[2];
  channelFromFile.ReplaceAll("SavedFits","");
  channelFromFile.ReplaceAll("fitModel.root","");
  channelFromFile.ReplaceAll("/","");
  channelFromFile.ReplaceAll("j3g","");
  channelFromFile.ReplaceAll("_","");
  channelFromFile+="w";
  cout<<"channel from file = "<<channelFromFile<<endl;  
  RooWorkspace * w = (RooWorkspace*)f2->Get(channelFromFile);

  int bins_dst_pt[]  ={1,107,148,196,274,((TH1D*)f1->Get("RS_dstar_pt"))->GetNbinsX()};
  TimeIntegratedSystematicsClass dst_pt("dst_pt",f1,w,"RS_dstar_pt","RS_ss_dstar_pt","RS_dt_hist_dstar_m_pt_bin","RS_ss_dt_hist_dstar_m_pt_bin",bins_dst_pt);
  std::vector<double>point_dst_pt = dst_pt.GetSignalPoint();

  int bins_dst_p[] = {1,179,230,294,400,((TH1D*)f1->Get("RS_dstar_p"))->GetNbinsX()};
  TimeIntegratedSystematicsClass dst_p("dst_p",f1,w,"RS_dstar_p","RS_ss_dstar_p","RS_dt_hist_dstar_m_p_bin","RS_ss_dt_hist_dstar_m_p_bin",bins_dst_p);
  std::vector<double>point_dst_p = dst_p.GetSignalPoint();

  int bins_mu_pt[]  ={1,107,148,196,274,((TH1D*)f1->Get("RS_mu_pt"))->GetNbinsX()};
  TimeIntegratedSystematicsClass mu_pt("mu_pt",f1,w,"RS_mu_pt","RS_ss_mu_pt","RS_dt_hist_mu_m_pt_bin","RS_ss_dt_hist_mu_m_pt_bin",bins_mu_pt);
  std::vector<double>point_mu_pt = mu_pt.GetSignalPoint();

  int bins_mu_p[] = {1,179,230,294,400,((TH1D*)f1->Get("RS_mu_p"))->GetNbinsX()};
  TimeIntegratedSystematicsClass mu_p("mu_p",f1,w,"RS_mu_p","RS_ss_mu_p","RS_dt_hist_mu_m_p_bin","RS_ss_dt_hist_mu_m_p_bin",bins_mu_p);
  std::vector<double>point_mu_p = mu_p.GetSignalPoint();

  int bins_mu_log_ip[]  ={1,99,150,216,326,((TH1D*)f1->Get("RS_mu_log_ip"))->GetNbinsX()};
  TimeIntegratedSystematicsClass mu_log_ip("mu_log_ip",f1,w,"RS_mu_log_ip","RS_ss_mu_log_ip","RS_dt_hist_mu_log_ip_bin","RS_ss_dt_hist_mu_log_ip_bin",bins_mu_log_ip);
  std::vector<double>point_mu_log_ip = mu_log_ip.GetSignalPoint();
  

  int bins_k_pidk[]  ={1,11,19,26,37,((TH1D*)f1->Get("RS_dst_mass_vs_k_pidk"))->GetNbinsX()};
  TimeIntegratedSystematicsClass k_pidk("k_pidk",f1,w,"RS_dst_mass_vs_k_pidk","RS_ss_dst_mass_vs_k_pidk","RS_dt_hist_k_pid_k_bin","RS_ss_dt_hist_k_pid_k_bin",bins_k_pidk);
  std::vector<double>point_k_pidk = k_pidk.GetSignalPoint();

  int bins_pi_pidk[]  ={1,150,165,176,185,((TH1D*)f1->Get("RS_dst_mass_vs_pi_pidk"))->GetNbinsX()};
  TimeIntegratedSystematicsClass pi_pidk("pi_pidk",f1,w,"RS_dst_mass_vs_pi_pidk","RS_ss_dst_mass_vs_pi_pidk","RS_dt_hist_pi_pid_k_bin","RS_ss_dt_hist_pi_pid_k_bin",bins_pi_pidk);
  std::vector<double>point_pi_pidk = pi_pidk.GetSignalPoint();
  
  double points [7] ={point_dst_p[0],point_dst_pt[0],point_mu_p[0],point_mu_pt[0],point_mu_log_ip[0],point_k_pidk[0],point_pi_pidk[0]} ;
  double points_err [7] ={point_dst_p[1],point_dst_pt[1],point_mu_p[1],point_mu_pt[1],point_mu_log_ip[1],point_k_pidk[1],point_pi_pidk[1]} ;
  //validation fit.
  massFit tot_validation(channelFromFile+"_validation_for_time_int","j3g",w);
  TH1D* tot_mass = (TH1D*)f1->Get("RS_dt_hist_dstar_m");
  tot_mass->Sumw2();
  tot_mass->Add((TH1D*)f1->Get("RS_ss_dt_hist_dstar_m"),-1);
  tot_validation.setData(tot_mass);
  tot_validation.fit();
  TH1D* the_final_comp = new TH1D("the_final_comp","; ;N Signal (D^*)",7,0.5,7.5);
  TLine *centr_val = new TLine(the_final_comp->GetXaxis()->GetXmin(),tot_validation.getNsig(),the_final_comp->GetXaxis()->GetXmax(),tot_validation.getNsig());
  centr_val->SetLineColor(kGreen+2);

  for(int i=0; i<7;++i){
    
    the_final_comp->SetBinContent(i+1,points[i]);
    the_final_comp->SetBinError(i+1,points_err[i]);
  }
 
  
  TString the_labels[7] ={"p(D*)","p_{T}(D*)","p(#mu)","p_{T}(#mu)","log(IP(#mu))","K PID K","#pi PID K"};
  for(int i=0; i<7;++i){
    the_final_comp->GetXaxis()->SetBinLabel(i+1,the_labels[i]);
  }
  TCanvas*cc = new TCanvas();
  gStyle->SetOptStat(0);
  the_final_comp->Draw("e");
  centr_val->Draw();
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_new_total_yield_systematic_check.pdf");
  f1->Close();
  f2->Close();
  return 0;
}
