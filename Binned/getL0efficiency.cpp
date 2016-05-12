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
#include <RooWorkspace.h>
// local
#include "massFit.h"
#include "PlottingTools.h"
using namespace std;
double eff_err(double num, double num_err, double denom, double denom_err){
  double eff = num/denom;
  double err = eff*eff*(TMath::Power(num_err/num,2.)+TMath::Power(denom_err/denom,2));
  return TMath::Sqrt(err);
}
double asymm_err(double a,double a_err, double b, double b_err){
  double err2 = 4*(TMath::Power(a_err*b,2.)+TMath::Power(b_err*a,2.))/TMath::Power(a+b,4.);
  return sqrt(err2);
}
int main(int argc, char* const argv[]){
  PlottingTools::setLHCbcanvas();
  cout<<"Code to calculate the L0 muon asymmetry for A(Kpi)"<<endl;
  if(argc<4){
    cout<<"***********************************"<<endl;
    cout<<"Please give the expected files"<<endl;
    cout<<"[1] The fit model file"<<endl;
    cout<<"[2] the file for the numerator (l0tos&tis)"<<endl;
    cout<<"[3] the file for the denominator(l0tis)"<<endl;
    cout<<"***********************************"<<endl;
    return 0;
  }
    //first thing, get the scaling factor from the file  
  double the_scaling_factor;
  std::ifstream sf_file("./theScalingFactor.txt");
  while(sf_file>>the_scaling_factor){cout<<"reading scaling factor from file"<<endl;}
  cout<<"read scaling factor "<<the_scaling_factor<<endl;
  if(!the_scaling_factor){cout<<"something terribly wrong here"<<endl;return 0;}
  sf_file.close();


  double the_scaling_factor_timeDep[5];
  std::ifstream sftd_file("./theScalingFactorTimeDependence.txt");
  int dum;
  double dumerr;
  if (sftd_file.is_open()){
    for(int i=0; i<5;++i){
      sftd_file>>dum>>the_scaling_factor_timeDep[i]>>dumerr;
    }
  }
  
  TString fitName = argv[1];
  TString histName = "RS_dt_hist_dstar_m";
  TString histSSName = "RS_ss_dt_hist_dstar_m";
  TString nameForFit = "rs";
  fitName.ToLower();
  if(fitName.Contains("ws")){ 
    cout<<"fitting ws! break!"<<endl;
    return 0;
  }
  //get the fit model
  TFile *f1 = TFile::Open(argv[1]);
  //f1->ls();
  TString channelFromFile = argv[1];
  channelFromFile.ToLower();
  if(channelFromFile.Contains("rs")){
    channelFromFile = "rs";
  }
  else{
    cout<<"wtf kind of a fit model file is that??"<<endl;
    return 0;
  }
  channelFromFile+="w";
  cout<<"channel from file = "<<channelFromFile<<endl;
    
  RooWorkspace * w = (RooWorkspace*)f1->Get(channelFromFile);
  //get init vals just in case
  array<double,4> thePars{
    (w->var("kappa")->getVal()),
      (w->var("n")->getVal()),
      (w->var("nbkg")->getVal()),
      (w->var("nsig")->getVal())};
  
  //now get the data to fit.
  TFile *fnum = TFile::Open(argv[2]);
  TFile *fdenom = TFile::Open(argv[3]);

  TH1D* d0_num_hist = (TH1D*)fnum->Get("RS_dt_hist_dstar_m_pos");
  TH1D* d0_num_hist_bkg = (TH1D*)fnum->Get("RS_ss_dt_hist_dstar_m_pos");
  TH1D* d0_denom_hist = (TH1D*)fdenom->Get("RS_dt_hist_dstar_m_pos");
  TH1D* d0_denom_hist_bkg = (TH1D*)fdenom->Get("RS_ss_dt_hist_dstar_m_pos");
  
  TH1D* d0bar_num_hist = (TH1D*)fnum->Get("RS_dt_hist_dstar_m_neg");
  TH1D* d0bar_num_hist_bkg = (TH1D*)fnum->Get("RS_ss_dt_hist_dstar_m_neg");
  TH1D* d0bar_denom_hist = (TH1D*)fdenom->Get("RS_dt_hist_dstar_m_neg");
  TH1D* d0bar_denom_hist_bkg = (TH1D*)fdenom->Get("RS_ss_dt_hist_dstar_m_neg");

  //also get by decay time bin
  TH1D* d0_num_hist_decay_time[5];
  TH1D* d0_num_hist_bkg_decay_time[5];
  TH1D* d0_denom_hist_decay_time[5];
  TH1D* d0_denom_hist_bkg_decay_time[5];

  TH1D* d0bar_num_hist_decay_time[5];
  TH1D* d0bar_num_hist_bkg_decay_time[5];
  TH1D* d0bar_denom_hist_decay_time[5];
  TH1D* d0bar_denom_hist_bkg_decay_time[5];

  for(int i=0; i<5;++i){
    d0_num_hist_decay_time[i] = (TH1D*)fnum->Get(Form("RS_dst_mass_td0_pos_bin%d",i+1));
    d0_num_hist_bkg_decay_time[i] = (TH1D*)fnum->Get(Form("RS_ss_dst_mass_td0_pos_bin%d",i+1));
    d0_denom_hist_decay_time[i] = (TH1D*)fdenom->Get(Form("RS_dst_mass_td0_pos_bin%d",i+1));
    d0_denom_hist_bkg_decay_time[i] = (TH1D*)fdenom->Get(Form("RS_ss_dst_mass_td0_pos_bin%d",i+1));
    //
    d0bar_num_hist_decay_time[i] = (TH1D*)fnum->Get(Form("RS_dst_mass_td0_neg_bin%d",i+1));
    d0bar_num_hist_bkg_decay_time[i] = (TH1D*)fnum->Get(Form("RS_ss_dst_mass_td0_neg_bin%d",i+1));
    d0bar_denom_hist_decay_time[i] = (TH1D*)fdenom->Get(Form("RS_dst_mass_td0_neg_bin%d",i+1));
    d0bar_denom_hist_bkg_decay_time[i] = (TH1D*)fdenom->Get(Form("RS_ss_dst_mass_td0_neg_bin%d",i+1));
  }
  //
  d0_num_hist->Sumw2();
  d0_num_hist_bkg->Sumw2();
  d0_denom_hist->Sumw2();
  d0_denom_hist_bkg->Sumw2();
  
  d0bar_num_hist->Sumw2();
  d0bar_num_hist_bkg->Sumw2();
  d0bar_denom_hist->Sumw2();
  d0bar_denom_hist_bkg->Sumw2();
  
  d0_num_hist->Add(d0_num_hist_bkg,-the_scaling_factor);
  d0_denom_hist->Add(d0_denom_hist_bkg,-the_scaling_factor);
  d0bar_num_hist->Add(d0bar_num_hist_bkg,-the_scaling_factor);
  d0bar_denom_hist->Add(d0bar_denom_hist_bkg,-the_scaling_factor);

  for(int i=0; i<5;++i){
    d0_num_hist_decay_time[i]->Sumw2();
    d0_num_hist_bkg_decay_time[i]->Sumw2();
    d0_denom_hist_decay_time[i]->Sumw2();
    d0_denom_hist_bkg_decay_time[i]->Sumw2();

    d0_num_hist_decay_time[i]->Add(d0_num_hist_bkg_decay_time[i],-the_scaling_factor_timeDep[i]);
    d0_denom_hist_decay_time[i]->Add(d0_denom_hist_bkg_decay_time[i],-the_scaling_factor_timeDep[i]);
    //
    d0bar_num_hist_decay_time[i]->Sumw2();
    d0bar_num_hist_bkg_decay_time[i]->Sumw2();
    d0bar_denom_hist_decay_time[i]->Sumw2();
    d0bar_denom_hist_bkg_decay_time[i]->Sumw2();

    d0bar_num_hist_decay_time[i]->Add(d0bar_num_hist_bkg_decay_time[i],-the_scaling_factor_timeDep[i]);
    d0bar_denom_hist_decay_time[i]->Add(d0bar_denom_hist_bkg_decay_time[i],-the_scaling_factor_timeDep[i]);
  }
  //now the mass fits.
  massFit fit_num_d0(channelFromFile+"L0eff_d0_kpi_numerator","j3g",w,"L0muonAsymmetry");
  fit_num_d0.setData(d0_num_hist);
  fit_num_d0.initValsByHand(thePars);
  fit_num_d0.fit();
  fit_num_d0.savePlots(true,"L0muonAsymmetry");
  double signal_d0_num = fit_num_d0.getNsig();
  double signal_d0_num_err = fit_num_d0.getNsigErr();
  //denom
  massFit fit_denom_d0(channelFromFile+"L0eff_d0_kpi_denomenator","j3g",w,"L0muonAsymmetry");
  fit_denom_d0.setData(d0_denom_hist);
  fit_denom_d0.initValsByHand(thePars);
  fit_denom_d0.fit();
  fit_denom_d0.savePlots(true,"L0muonAsymmetry");
  double signal_d0_denom = fit_denom_d0.getNsig();
  double signal_d0_denom_err = fit_denom_d0.getNsigErr();

  //d0bar
  massFit fit_num_d0bar(channelFromFile+"L0eff_d0bar_kpi_numerator","j3g",w,"L0muonAsymmetry");
  fit_num_d0bar.setData(d0bar_num_hist);
  fit_num_d0bar.initValsByHand(thePars);
  fit_num_d0bar.fit();
  fit_num_d0bar.savePlots(true,"L0muonAsymmetry");
  double signal_d0bar_num = fit_num_d0bar.getNsig();
  double signal_d0bar_num_err = fit_num_d0bar.getNsigErr();
  //denom
  massFit fit_denom_d0bar(channelFromFile+"L0eff_d0bar_kpi_denomenator","j3g",w,"L0muonAsymmetry");
  fit_denom_d0bar.setData(d0bar_denom_hist);
  fit_denom_d0bar.initValsByHand(thePars);
  fit_denom_d0bar.fit();
  fit_denom_d0bar.savePlots(true,"L0muonAsymmetry");
  double signal_d0bar_denom = fit_denom_d0bar.getNsig();
  double signal_d0bar_denom_err = fit_denom_d0bar.getNsigErr();
  double epsd0 = signal_d0_num/signal_d0_denom*100.;//in percent
  double epsd0_err  = eff_err(signal_d0_num,signal_d0_num_err,signal_d0_denom,signal_d0_denom_err)*100.;
  double epsd0bar = signal_d0bar_num/signal_d0bar_denom*100.;
  double epsd0bar_err = eff_err(signal_d0bar_num,signal_d0bar_num_err,signal_d0bar_denom,signal_d0bar_denom_err)*100.;

  std::vector<double>signal_d0_num_td0_bins,
    signal_d0bar_num_td0_bins,
    signal_d0_denom_td0_bins,
    signal_d0bar_denom_td0_bins;
  std::vector<double>signal_d0_num_err_td0_bins,
    signal_d0_denom_err_td0_bins,
    signal_d0bar_num_err_td0_bins,
    signal_d0bar_denom_err_td0_bins;
  
  //decay time bins
  for(int i=0; i<5;++i){
    massFit fit_bins_num_d0(channelFromFile+"L0eff_d0_kpi_numerator","j3g",w,Form("L0muonAsymmetry_td0_bin%d",i+1));
    fit_bins_num_d0.setData(d0_num_hist_decay_time[i]);
    fit_bins_num_d0.initValsByHand(thePars);
    fit_bins_num_d0.fit();
    fit_bins_num_d0.savePlots(true,"L0muonAsymmetry");
    signal_d0_num_td0_bins.push_back(fit_bins_num_d0.getNsig());
    signal_d0_num_err_td0_bins.push_back(fit_bins_num_d0.getNsigErr());
    //denom
    massFit fit_bins_denom_d0(channelFromFile+"L0eff_d0_kpi_denomenator","j3g",w,Form("L0muonAsymmetry_td0_bin%d",i+1));
    fit_bins_denom_d0.setData(d0_denom_hist_decay_time[i]);
    fit_bins_denom_d0.initValsByHand(thePars);
    fit_bins_denom_d0.fit();
    fit_bins_denom_d0.savePlots(true,"L0muonAsymmetry");
    signal_d0_denom_td0_bins.push_back(fit_bins_denom_d0.getNsig());
    signal_d0_denom_err_td0_bins.push_back(fit_bins_denom_d0.getNsigErr());

    //d0bar
    massFit fit_bins_num_d0bar(channelFromFile+"L0eff_d0bar_kpi_numerator","j3g",w,Form("L0muonAsymmetry_td0_bin%d",i+1));
    fit_bins_num_d0bar.setData(d0bar_num_hist_decay_time[i]);
    fit_bins_num_d0bar.initValsByHand(thePars);
    fit_bins_num_d0bar.fit();
    fit_bins_num_d0bar.savePlots(true,"L0muonAsymmetry");
    signal_d0bar_num_td0_bins.push_back(fit_bins_num_d0bar.getNsig());
    signal_d0bar_num_err_td0_bins.push_back(fit_bins_num_d0bar.getNsigErr());
    //denom
    massFit fit_bins_denom_d0bar(channelFromFile+"L0eff_d0bar_kpi_denomenator","j3g",w,Form("L0muonAsymmetry_td0_bin%d",i+1));
    fit_bins_denom_d0bar.setData(d0bar_denom_hist_decay_time[i]);
    fit_bins_denom_d0bar.initValsByHand(thePars);
    fit_bins_denom_d0bar.fit();
    fit_bins_denom_d0bar.savePlots(true,"L0muonAsymmetry");
    signal_d0bar_denom_td0_bins.push_back(fit_bins_denom_d0bar.getNsig());
    signal_d0bar_denom_err_td0_bins.push_back(fit_bins_denom_d0bar.getNsigErr());
  }
  std::vector<double> epsd0_bins;
  std::vector<double> epsd0_err_bins;
  std::vector<double> epsd0bar_bins;
  std::vector<double> epsd0bar_err_bins;
  for(int i=0; i<5; ++i){
    epsd0_bins.push_back(signal_d0_num_td0_bins.at(i)/signal_d0_denom_td0_bins.at(i)*100.);//in percent
    epsd0_err_bins.push_back(eff_err(signal_d0_num_td0_bins.at(i),signal_d0_num_err_td0_bins.at(i),signal_d0_denom_td0_bins.at(i),signal_d0_denom_err_td0_bins.at(i))*100.);
    epsd0bar_bins.push_back(signal_d0bar_num_td0_bins.at(i)/signal_d0bar_denom_td0_bins.at(i)*100.);
    epsd0bar_err_bins.push_back(eff_err(signal_d0bar_num_td0_bins.at(i),signal_d0bar_num_err_td0_bins.at(i),signal_d0bar_denom_td0_bins.at(i),signal_d0bar_denom_err_td0_bins.at(i))*100.);
  }
  cout<<"\\begin{tabular}{ccc}"<<endl;
  cout<<"\\\\hline"<<endl;
  cout<<"$#epsilon_\\text{L0muon}(D^0)$ & $#epsilon_\\text{L0muon}(\\overline{D}^0)$ & A(L0 Muon)\\\\ \\hline"<<endl;
  cout<<"$"<<epsd0<<"\\pm"<<epsd0_err<<"$ & $"<<epsd0bar<<"\\pm"<<epsd0bar_err<<"$ & $"<<(epsd0bar-epsd0)/(epsd0bar+epsd0)<<"\\pm"<< asymm_err(epsd0bar,epsd0bar_err,epsd0,epsd0_err)<<"$\\\\ \\hline"<<endl;
  cout<<"\\end{tabular}"<<endl;
  cout<<endl;
  cout<<"\\begin{tabular}{cccc}"<<endl;
  cout<<"\\\\hline"<<endl;
  cout<<"Time Bin & $#epsilon_\\text{L0muon}(D^0)$ & $#epsilon_\\text{L0muon}(\\overline{D}^0)$ & A(L0 Muon)\\\\ \\hline"<<endl;
  for(int i=0; i<5;++i){
    cout<<i+1<<"& $"<<epsd0_bins.at(i)<<"\\pm"<<epsd0_err_bins.at(i)<<"$ & $"<<epsd0bar_bins.at(i)<<"\\pm"<<epsd0bar_err_bins.at(i)<<"$ & $"<<(epsd0bar_bins.at(i)-epsd0_bins.at(i))/(epsd0bar_bins.at(i)+epsd0_bins.at(i))<<"\\pm"<< asymm_err(epsd0bar_bins.at(i),epsd0bar_err_bins.at(i),epsd0_bins.at(i),epsd0_err_bins.at(i))<<"$\\\\ \\hline"<<endl;
  }
  cout<<"\\\\hline"<<endl;
  cout<<"\\\\hline"<<endl;
  cout<<"\\end{tabular}"<<endl;

  return 0;
}
