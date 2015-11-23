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
  PlottingTools::setLHCbcanvas();
  //int nSysts = 5;
  cout<<"**************"<<endl;
  cout<<"Code for processing mike's time integrated systematics"<<endl;
  cout<<"   for the loosest PID bins"<<endl;
  cout<<"(In short, skip the PID)"<<endl;
  cout<<"**************"<<endl;
  if(argc<2){
    cout<<"Please pass a RS datafile and fit model to process!"<<endl;
    return 0;
  }
  if(argc<3){
    cout<<"please also pass a saved fit model!"<<endl;
    return 0;
  }
  // bool doPIDstudies = true;
  // if(argc==4){
  //   cout<<argv[3]<<endl;
  //   cout<<"turning off PID K studies"<<endl;
  // }

  cout<<"Now processing "<<argv[1]<<endl;
  TFile * f1 = TFile::Open(argv[1]);
  TFile *f2 = TFile::Open(argv[2]);
  //  f2->ls();
  TString channelFromFile = argv[2];
  channelFromFile.ToLower();
  // channelFromFile.ReplaceAll("SavedFits","");
  // channelFromFile.ReplaceAll("fitModel.root","");
  // channelFromFile.ReplaceAll("/","");
  // channelFromFile.ReplaceAll("j3g","");
  // channelFromFile.ReplaceAll("_","");
  if(channelFromFile.Contains("rs")){
    channelFromFile="rs";
  }
  channelFromFile+="w";
  cout<<"channel from file = "<<channelFromFile<<endl;  
  RooWorkspace * w = (RooWorkspace*)f2->Get(channelFromFile);

  //get the values from the workspace.
  array<double,4> thePars{
    (w->var("kappa")->getVal()),
      (w->var("n")->getVal()),
      (w->var("nbkg")->getVal()),
      (w->var("nsig")->getVal())};
  //binned twice  
  //and the rest.  
  int bins_dst_pt[]  ={1,107,148,196,274,((TH1D*)f1->Get("RS_dstar_pt"))->GetNbinsX()};
  TimeIntegratedSystematicsClass dst_pt("dst_pt",f1,w,"RS_dstar_pt","RS_ss_dstar_pt","RS_dt_hist_dstar_m_pt_bin","RS_ss_dt_hist_dstar_m_pt_bin",bins_dst_pt,5,thePars);
  std::vector<double>point_dst_pt ( dst_pt.GetSignalPoint());
  
  int bins_dst_p[] = {1,179,230,294,400,((TH1D*)f1->Get("RS_dstar_p"))->GetNbinsX()};
  TimeIntegratedSystematicsClass dst_p("dst_p",f1,w,"RS_dstar_p","RS_ss_dstar_p","RS_dt_hist_dstar_m_p_bin","RS_ss_dt_hist_dstar_m_p_bin",bins_dst_p,5,thePars);
  std::vector<double>point_dst_p ( dst_p.GetSignalPoint());

  int bins_mu_pt[]  ={1,104,132,166,223,((TH1D*)f1->Get("RS_mu_pt"))->GetNbinsX()};
  TimeIntegratedSystematicsClass mu_pt("mu_pt",f1,w,"RS_mu_pt","RS_ss_mu_pt","RS_dt_hist_mu_m_pt_bin","RS_ss_dt_hist_mu_m_pt_bin",bins_mu_pt,5,thePars);
  std::vector<double>point_mu_pt ( mu_pt.GetSignalPoint());

  int bins_mu_p[] = {1,99,150,216,326,((TH1D*)f1->Get("RS_mu_p"))->GetNbinsX()};
  TimeIntegratedSystematicsClass mu_p("mu_p",f1,w,"RS_mu_p","RS_ss_mu_p","RS_dt_hist_mu_m_p_bin","RS_ss_dt_hist_mu_m_p_bin",bins_mu_p,5,thePars);
  std::vector<double>point_mu_p ( mu_p.GetSignalPoint());

  int bins_mu_log_ip[]  ={1,342,389,432,482,((TH1D*)f1->Get("RS_mu_log_ip"))->GetNbinsX()};
  TimeIntegratedSystematicsClass mu_log_ip("mu_log_ip",f1,w,"RS_mu_log_ip","RS_ss_mu_log_ip","RS_dt_hist_mu_log_ip_bin","RS_ss_dt_hist_mu_log_ip_bin",bins_mu_log_ip,5,thePars);
  std::vector<double>point_mu_log_ip ( mu_log_ip.GetSignalPoint());

      //now do the same for the 5x5 matrix in pids
  //we have stuff that looks like RS_dt_hist_pi_pid_k_bin1_k_pid_k_bin2
  //we want do only use the thing up to the last bin, and do it 5 times.
  //but we'll use the kpid k bins for each pi pid k bin.
    
  //return 0;

  //return 0;
  //final check for time independent.
  //split by charge of slow pion for RS sample
  //easier just to do the two histograms by hand.
  TH1D* d0_hist = (TH1D*)f1->Get("RS_dt_hist_dstar_m_pos");
  d0_hist->Sumw2();
  d0_hist->Add((TH1D*)f1->Get("RS_ss_dt_hist_dstar_m_pos"),-1);

  TH1D* d0bar_hist = (TH1D*)f1->Get("RS_dt_hist_dstar_m_neg");
  d0bar_hist->Sumw2();
  d0bar_hist->Add((TH1D*)f1->Get("RS_ss_dt_hist_dstar_m_neg"),-1);
  massFit d0validation(channelFromFile+"d0_separated_validation","j3g",w,"TimeIntegratedSystematics");
  d0validation.setData(d0_hist);
  d0validation.FloatMeanWidth();
  d0validation.fit();
  std::vector<double> d0_point;d0_point.push_back(d0validation.getNsig());d0_point.push_back(d0validation.getNsigErr()*d0validation.getNsigErr());
  double d0_dmean = d0validation.getDMean();
  double d0_dmeanErr = d0validation.getDMeanErr();
  double d0_rsigma = d0validation.getrSigma();
  double d0_rsigmaErr = d0validation.getrSigmaErr();
  d0validation.savePlots(true,"RS_d0");
  d0validation.Reset();
  //
  massFit d0barvalidation(channelFromFile+"d0bar_separated_validation","j3g",w,"TimeIntegratedSystematics");
  d0barvalidation.setData(d0bar_hist);
  d0barvalidation.FloatMeanWidth();
  d0barvalidation.fit();
  std::vector<double> d0bar_point;d0bar_point.push_back(d0barvalidation.getNsig());d0bar_point.push_back(d0barvalidation.getNsigErr()*d0barvalidation.getNsigErr());
  double d0bar_dmean = d0barvalidation.getDMean();
  double d0bar_dmeanErr = d0barvalidation.getDMeanErr();
  double d0bar_rsigma = d0barvalidation.getrSigma();
  double d0bar_rsigmaErr = d0barvalidation.getrSigmaErr();
  d0barvalidation.savePlots(true,"RS_d0bar");
  d0barvalidation.Reset();
  
  std::vector<double> qpis_point;
  qpis_point.push_back(d0_point[0]+d0bar_point[0]);
  qpis_point.push_back(TMath::Sqrt(d0_point[1]+d0bar_point[1]));
  
  double points [6] ={point_dst_p[0],point_dst_pt[0],point_mu_p[0],point_mu_pt[0],point_mu_log_ip[0],qpis_point[0]} ;
  double points_err [6] ={point_dst_p[1],point_dst_pt[1],point_mu_p[1],point_mu_pt[1],point_mu_log_ip[1],qpis_point[1]} ;
  //validation fit.
  massFit tot_validation(channelFromFile+"_validation_for_time_int","j3g",w);
  TH1D* tot_mass = (TH1D*)f1->Get("RS_dt_hist_dstar_m");
  tot_mass->Sumw2();
  tot_mass->Add((TH1D*)f1->Get("RS_ss_dt_hist_dstar_m"),-1);
  tot_validation.setData(tot_mass);
  tot_validation.fit();
  TH1D* the_final_comp = new TH1D("the_final_comp","; ;N Signal (D*)",6,0.5,6.5);
  TLine *centr_val = new TLine(the_final_comp->GetXaxis()->GetXmin(),tot_validation.getNsig(),the_final_comp->GetXaxis()->GetXmax(),tot_validation.getNsig());
  centr_val->SetLineColor(kGreen+2);

  for(int i=0; i<6;++i){
    
    the_final_comp->SetBinContent(i+1,points[i]);
    the_final_comp->SetBinError(i+1,points_err[i]);
  }
 
  
  TString the_labels[6] ={"p(D*)","p_{T}(D*)","p(#mu)","p_{T}(#mu)","log(IP(#mu))","q(#pi_{s})"};
  for(int i=0; i<6;++i){
    the_final_comp->GetXaxis()->SetBinLabel(i+1,the_labels[i]);
  }
  TCanvas*cc = new TCanvas();
  gStyle->SetOptStat(0);
  the_final_comp->Draw("e");
  centr_val->Draw();
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_new_total_yield_systematic_check.pdf");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_new_total_yield_systematic_check.C");


  f1->Close();
  f2->Close();
  
  cout<<"************************************************"<<endl;
  cout<<"For the result of splitting by slow pion charge"<<endl;
  cout<<"************************************************"<<endl;
  cout<<"       Dmean"<<setw(15)<<"rSigma"<<endl;
  cout<<"D0"<<d0_dmean<<"+/-"<<d0_dmeanErr<<setw(15)<<d0_rsigma<<"+/-"<<d0_rsigmaErr<<endl;
  cout<<"D0bar"<<d0bar_dmean<<"+/-"<<d0bar_dmeanErr<<setw(15)<<d0bar_rsigma<<"+/-"<<d0bar_rsigmaErr<<endl;
  cout<<"************************************************"<<endl;

  return 0;
}
