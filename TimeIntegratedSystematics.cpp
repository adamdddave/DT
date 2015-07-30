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
#include "PlottingTools.h"
using namespace std;
using namespace PlottingTools;

int main(int argc, char* const argv[]){
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
  f1->ls();
  TH1D* dst_pt_tot = (TH1D*)f1->Get("RS_dstar_pt");
  TH1D* dst_p_tot = (TH1D*)f1->Get("RS_dstar_p");

  TH1D* mu_pt_tot = (TH1D*)f1->Get("RS_mu_pt");
  TH1D* mu_p_tot = (TH1D*)f1->Get("RS_mu_p");


  dst_pt_tot->Sumw2();
  dst_p_tot->Sumw2();

  mu_pt_tot->Sumw2();
  mu_p_tot->Sumw2();

  TH1D* dst_ss_pt_tot = (TH1D*)f1->Get("RS_dstar_pt");
  TH1D* dst_ss_p_tot = (TH1D*)f1->Get("RS_dstar_p");

  TH1D* mu_ss_pt_tot = (TH1D*)f1->Get("RS_ss_mu_pt");
  TH1D* mu_ss_p_tot = (TH1D*)f1->Get("RS_ss_mu_p");

  dst_pt_tot->Add(dst_ss_pt_tot,-1);
  dst_p_tot->Add(dst_ss_p_tot,-1);
  mu_pt_tot->Add(mu_ss_pt_tot,-1);
  mu_p_tot->Add(mu_ss_p_tot,-1);
  //now, get the means in the bin ranges.
  double dst_pt_mean_dstar_mass_pos[5];
  double dst_p_mean_dstar_mass_pos[5];
  double mu_pt_mean_dstar_mass_pos[5];
  double mu_p_mean_dstar_mass_pos[5];


  
  //dstar
  int dst_pt_bin_range[6]={1,107,148,196,274,dst_pt_tot->GetNbinsX()};
  dst_pt_tot->GetXaxis()->SetRange(1,107);
  dst_pt_mean_dstar_mass_pos[0]=dst_pt_tot->GetMean();
  dst_pt_tot->GetXaxis()->SetRange();
  
  dst_pt_tot->GetXaxis()->SetRange(107,148);
  dst_pt_mean_dstar_mass_pos[1]=dst_pt_tot->GetMean();
  dst_pt_tot->GetXaxis()->SetRange();

  dst_pt_tot->GetXaxis()->SetRange(148,196);
  dst_pt_mean_dstar_mass_pos[2]=dst_pt_tot->GetMean();
  dst_pt_tot->GetXaxis()->SetRange();

  dst_pt_tot->GetXaxis()->SetRange(196,274);
  dst_pt_mean_dstar_mass_pos[3]=dst_pt_tot->GetMean();
  dst_pt_tot->GetXaxis()->SetRange();

  dst_pt_tot->GetXaxis()->SetRange(274,dst_pt_tot->GetNbinsX());
  dst_pt_mean_dstar_mass_pos[4]=dst_pt_tot->GetMean();
  dst_pt_tot->GetXaxis()->SetRange();

    int dst_p_bin_range[6]={1,179,230,294,400,dst_p_tot->GetNbinsX()};
  dst_p_tot->GetXaxis()->SetRange(1,179);
  dst_p_mean_dstar_mass_pos[0]=dst_p_tot->GetMean();
  dst_p_tot->GetXaxis()->SetRange();
  
  dst_p_tot->GetXaxis()->SetRange(179,230);
  dst_p_mean_dstar_mass_pos[1]=dst_p_tot->GetMean();
  dst_p_tot->GetXaxis()->SetRange();

  dst_p_tot->GetXaxis()->SetRange(230,294);
  dst_p_mean_dstar_mass_pos[2]=dst_p_tot->GetMean();
  dst_p_tot->GetXaxis()->SetRange();

  dst_p_tot->GetXaxis()->SetRange(294,400);
  dst_p_mean_dstar_mass_pos[3]=dst_p_tot->GetMean();
  dst_p_tot->GetXaxis()->SetRange();

  dst_p_tot->GetXaxis()->SetRange(400,dst_p_tot->GetNbinsX());
  dst_p_mean_dstar_mass_pos[4]=dst_p_tot->GetMean();
  dst_p_tot->GetXaxis()->SetRange();
  //muon
  int mu_pt_bin_range[6]={1,104,132,166,223,mu_pt_tot->GetNbinsX()};
  mu_pt_tot->GetXaxis()->SetRange(1,104);
  mu_pt_mean_dstar_mass_pos[0]=mu_pt_tot->GetMean();
  mu_pt_tot->GetXaxis()->SetRange();
  
  mu_pt_tot->GetXaxis()->SetRange(104,132);
  mu_pt_mean_dstar_mass_pos[1]=mu_pt_tot->GetMean();
  mu_pt_tot->GetXaxis()->SetRange();

  mu_pt_tot->GetXaxis()->SetRange(132,166);
  mu_pt_mean_dstar_mass_pos[2]=mu_pt_tot->GetMean();
  mu_pt_tot->GetXaxis()->SetRange();

  mu_pt_tot->GetXaxis()->SetRange(166,223);
  mu_pt_mean_dstar_mass_pos[3]=mu_pt_tot->GetMean();
  mu_pt_tot->GetXaxis()->SetRange();

  mu_pt_tot->GetXaxis()->SetRange(223,mu_pt_tot->GetNbinsX());
  mu_pt_mean_dstar_mass_pos[4]=mu_pt_tot->GetMean();
  mu_pt_tot->GetXaxis()->SetRange();
  
  int mu_p_bin_range[6]={1,99,150,216,326,mu_p_tot->GetNbinsX()};
  mu_p_tot->GetXaxis()->SetRange(1,99);
  mu_p_mean_dstar_mass_pos[0]=mu_p_tot->GetMean();
  mu_p_tot->GetXaxis()->SetRange();
  
  mu_p_tot->GetXaxis()->SetRange(99,150);
  mu_p_mean_dstar_mass_pos[1]=mu_p_tot->GetMean();
  mu_p_tot->GetXaxis()->SetRange();

  mu_p_tot->GetXaxis()->SetRange(150,216);
  mu_p_mean_dstar_mass_pos[2]=mu_p_tot->GetMean();
  mu_p_tot->GetXaxis()->SetRange();

  mu_p_tot->GetXaxis()->SetRange(216,326);
  mu_p_mean_dstar_mass_pos[3]=mu_p_tot->GetMean();
  mu_p_tot->GetXaxis()->SetRange();

  mu_p_tot->GetXaxis()->SetRange(326,mu_p_tot->GetNbinsX());
  mu_p_mean_dstar_mass_pos[4]=mu_p_tot->GetMean();
  mu_p_tot->GetXaxis()->SetRange();
  //first, get the distributions
  //  return 0;
  std::vector<TH1D*> rs_dst_pt_bins, rs_dst_p_bins,rs_mu_pt_bins,rs_mu_p_bins;
  std::vector<TH1D*> rs_ss_dst_pt_bins, rs_ss_dst_p_bins,rs_ss_mu_pt_bins,rs_ss_mu_p_bins;
  double dst_pt_dmeans[5];
  double dst_pt_dmeans_err[5];
  double dst_p_dmeans[5];
  double dst_p_dmeans_err[5];

  double mu_pt_dmeans[5];
  double mu_pt_dmeans_err[5];
  double mu_p_dmeans[5];
  double mu_p_dmeans_err[5];

  double dst_pt_rwidths[5];
  double dst_pt_rwidths_err[5];
  double dst_p_rwidths[5];
  double dst_p_rwidths_err[5];

  double mu_pt_rwidths[5];
  double mu_pt_rwidths_err[5];
  double mu_p_rwidths[5];
  double mu_p_rwidths_err[5];


  
  for(int i=1;i<6;++i){
    cout<<"pushing back bin "<<i<<endl;
    rs_dst_pt_bins.push_back((TH1D*)((TH1D*)f1->Get(Form("RS_dt_hist_dstar_m_pt_bin%d",i)))->Clone(Form("rs_dst_pt_bin%d",i)));
    rs_dst_p_bins.push_back((TH1D*)((TH1D*)f1->Get(Form("RS_dt_hist_dstar_m_p_bin%d",i)))->Clone(Form("rs_dst_p_bin%d",i)));
    rs_mu_pt_bins.push_back((TH1D*)((TH1D*)f1->Get(Form("RS_dt_hist_mu_m_pt_bin%d",i)))->Clone(Form("rs_mu_pt_bin%d",i)));
    rs_mu_p_bins.push_back((TH1D*)((TH1D*)f1->Get(Form("RS_dt_hist_mu_m_p_bin%d",i)))->Clone(Form("rs_mu_p_bin%d",i)));

    rs_ss_dst_pt_bins.push_back((TH1D*)((TH1D*)f1->Get(Form("RS_ss_dt_hist_dstar_m_pt_bin%d",i)))->Clone(Form("rs_ss_dst_pt_bin%d",i)));
    rs_ss_dst_p_bins.push_back((TH1D*)((TH1D*)f1->Get(Form("RS_ss_dt_hist_dstar_m_p_bin%d",i)))->Clone(Form("rs_ss_dst_p_bin%d",i)));
    rs_ss_mu_pt_bins.push_back((TH1D*)((TH1D*)f1->Get(Form("RS_ss_dt_hist_mu_m_pt_bin%d",i)))->Clone(Form("rs_ss_mu_pt_bin%d",i)));
    rs_ss_mu_p_bins.push_back((TH1D*)((TH1D*)f1->Get(Form("RS_ss_dt_hist_mu_m_p_bin%d",i)))->Clone(Form("rs_ss_mu_p_bin%d",i)));
    
  }
  cout<<"double check, rs_dst_pt_bins[0]->Integral()="<<rs_dst_pt_bins[0]->Integral()<<endl;
  cout<<"double check, rs_dst_p_bins[0]->Integral()="<<rs_dst_p_bins[0]->Integral()<<endl;
  cout<<"double check, rs_mu_pt_bins[0]->Integral()="<<rs_mu_pt_bins[0]->Integral()<<endl;
  cout<<"double check, rs_mu_p_bins[0]->Integral()="<<rs_mu_p_bins[0]->Integral()<<endl;

  cout<<"double check, rs_ss_dst_pt_bins[0]->Integral()="<<rs_ss_dst_pt_bins[0]->Integral()<<endl;
  cout<<"double check, rs_ss_dst_p_bins[0]->Integral()="<<rs_ss_dst_p_bins[0]->Integral()<<endl;
  cout<<"double check, rs_ss_mu_pt_bins[0]->Integral()="<<rs_ss_mu_pt_bins[0]->Integral()<<endl;
  cout<<"double check, rs_ss_mu_p_bins[0]->Integral()="<<rs_ss_mu_p_bins[0]->Integral()<<endl;
  //now subtract the SS from the OS
  for(int i=0; i<5;++i){
    rs_dst_pt_bins[i]->Sumw2();
    rs_dst_p_bins[i]->Sumw2();
    rs_mu_pt_bins[i]->Sumw2();
    rs_mu_p_bins[i]->Sumw2();
    //
    rs_dst_pt_bins[i]->Add(rs_ss_dst_pt_bins[i],-1);
    rs_dst_p_bins[i]->Add(rs_ss_dst_p_bins[i],-1);
    rs_mu_pt_bins[i]->Add(rs_ss_mu_pt_bins[i],-1);
    rs_mu_p_bins[i]->Add(rs_ss_mu_p_bins[i],-1);
  }
  //now do the fits.
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

  massFit* fits_dst_pt[5];
  massFit* fits_dst_p[5];
  massFit* fits_mu_pt[5];
  massFit* fits_mu_p[5];

  double errXlow_mean_dst_pt[5],errXhi_mean_dst_pt[5];
  double errXlow_mean_dst_p[5],errXhi_mean_dst_p[5];
  double errXlow_mean_mu_pt[5],errXhi_mean_mu_pt[5];
  double errXlow_mean_mu_p[5],errXhi_mean_mu_p[5];
  double dst_p_yield[5];
  double dst_pt_yield[5];
  double mu_p_yield[5];
  double mu_pt_yield[5];
  double dst_p_yield_err[5];
  double dst_pt_yield_err[5];
  double mu_p_yield_err[5];
  double mu_pt_yield_err[5];

  
  for(int i=0; i<5;++i){
    //dst pt
    cout<<"==========================="<<endl;
    cout<<"dst pt bin "<<i+1<<endl;
    cout<<"==========================="<<endl;
    fits_dst_pt[i] = new massFit(Form("rs_dst_pt_bin%d",i+1),"j3g",w);
    fits_dst_pt[i]->setData(rs_dst_pt_bins[i]);
    fits_dst_pt[i]->FloatMeanWidth();
    fits_dst_pt[i]->fit();
    fits_dst_pt[i]->savePlots(true,channelFromFile+Form("dst_pt_bin%d",i+1));
    
    dst_pt_dmeans[i]=fits_dst_pt[i]->getDMean();
    dst_pt_dmeans_err[i]=fits_dst_pt[i]->getDMeanErr();
    
    dst_pt_rwidths[i]=fits_dst_pt[i]->getrSigma()*100.;
    dst_pt_rwidths_err[i]=fits_dst_pt[i]->getrSigmaErr()*100.;

    errXlow_mean_dst_pt[i]=dst_pt_mean_dstar_mass_pos[i] - dst_pt_tot->GetBinCenter(dst_pt_bin_range[i]);// mean- low bin edge
    errXhi_mean_dst_pt[i]=dst_pt_tot->GetBinCenter(dst_pt_bin_range[i+1])-dst_pt_mean_dstar_mass_pos[i] ;//  hi bin edge - mean

    dst_pt_yield[i] = fits_dst_pt[i]->getNsig();
    dst_pt_yield_err[i] = fits_dst_pt[i]->getNsigErr(); 
    //dst p
    cout<<"==========================="<<endl;
    cout<<"dst p bin "<<i+1<<endl;
    cout<<"==========================="<<endl;
    fits_dst_p[i] = new massFit(Form("rs_dst_p_bin%d",i+1),"j3g",w);
    fits_dst_p[i]->setData(rs_dst_p_bins[i]);
    fits_dst_p[i]->fit();
    fits_dst_p[i]->savePlots(true,channelFromFile+Form("dst_p_bin%d",i+1));
    
    dst_p_dmeans[i]=fits_dst_p[i]->getDMean();
    dst_p_dmeans_err[i]=fits_dst_p[i]->getDMeanErr();
    
    dst_p_rwidths[i]=fits_dst_p[i]->getrSigma()*100.;
    dst_p_rwidths_err[i]=fits_dst_p[i]->getrSigmaErr()*100.;

    errXlow_mean_dst_p[i]=dst_p_mean_dstar_mass_pos[i] - dst_p_tot->GetBinCenter(dst_p_bin_range[i]);// mean- low bin edge
    errXhi_mean_dst_p[i]=dst_p_tot->GetBinCenter(dst_p_bin_range[i+1])-dst_p_mean_dstar_mass_pos[i] ;//  hi bin edge - mean

    dst_p_yield[i] = fits_dst_p[i]->getNsig();
    dst_p_yield_err[i] = fits_dst_p[i]->getNsigErr(); 
    //mu pt
    cout<<"==========================="<<endl;
    cout<<"mu pt bin "<<i+1<<endl;
    cout<<"==========================="<<endl;
    fits_mu_pt[i] = new massFit(Form("rs_mu_pt_bin%d",i+1),"j3g",w);
    fits_mu_pt[i]->setData(rs_mu_pt_bins[i]);
    fits_mu_pt[i]->FloatMeanWidth();
    fits_mu_pt[i]->fit();
    fits_mu_pt[i]->savePlots(true,channelFromFile+Form("mu_pt_bin%d",i+1));
    
    mu_pt_dmeans[i]=fits_mu_pt[i]->getDMean();
    mu_pt_dmeans_err[i]=fits_mu_pt[i]->getDMeanErr();
    
    mu_pt_rwidths[i]=fits_mu_pt[i]->getrSigma()*100.;
    mu_pt_rwidths_err[i]=fits_mu_pt[i]->getrSigmaErr()*100.;

    errXlow_mean_mu_pt[i]=dst_pt_mean_dstar_mass_pos[i] - mu_pt_tot->GetBinCenter(mu_pt_bin_range[i]);// mean- low bin edge
    errXhi_mean_mu_pt[i]=mu_pt_tot->GetBinCenter(mu_pt_bin_range[i+1])-mu_pt_mean_dstar_mass_pos[i] ;//  hi bin edge - mean
    mu_pt_yield[i] = fits_mu_pt[i]->getNsig();
    mu_pt_yield_err[i] = fits_mu_pt[i]->getNsigErr(); 
    //mu p
    cout<<"==========================="<<endl;
    cout<<"mu p bin "<<i+1<<endl;
    cout<<"==========================="<<endl;
    fits_mu_p[i] = new massFit(Form("rs_mu_p_bin%d",i+1),"j3g",w);
    fits_mu_p[i]->setData(rs_mu_p_bins[i]);
    fits_mu_p[i]->FloatMeanWidth();
    fits_mu_p[i]->fit();
    fits_mu_p[i]->savePlots(true,channelFromFile+Form("mu_p_bin%d",i+1));
    
    mu_p_dmeans[i]=fits_mu_p[i]->getDMean();
    mu_p_dmeans_err[i]=fits_mu_p[i]->getDMeanErr();
    
    mu_p_rwidths[i]=fits_mu_p[i]->getrSigma()*100.;
    mu_p_rwidths_err[i]=fits_mu_p[i]->getrSigmaErr()*100.;

    errXlow_mean_mu_p[i]=mu_p_mean_dstar_mass_pos[i] - mu_p_tot->GetBinCenter(mu_p_bin_range[i]);// mean- low bin edge
    errXhi_mean_mu_p[i]=mu_p_tot->GetBinCenter(mu_p_bin_range[i+1])-mu_p_mean_dstar_mass_pos[i] ;//  hi bin edge - mean
    mu_p_yield[i] = fits_mu_p[i]->getNsig();
    mu_p_yield_err[i] = fits_mu_p[i]->getNsigErr(); 
  }
  //now make a TGraphErrs out of the bins.
  TGraphAsymmErrors dst_dmean_vs_pt_graph(5,dst_pt_mean_dstar_mass_pos,dst_pt_dmeans,errXlow_mean_dst_pt,errXhi_mean_dst_pt,dst_pt_dmeans_err,dst_pt_dmeans_err);
  dst_dmean_vs_pt_graph.SetTitle(";p_{T}(D^{*})[MeV]; #delta #mu(D^{*}) fit [MeV]");
  dst_dmean_vs_pt_graph.SetMarkerStyle(22);
  dst_dmean_vs_pt_graph.SetMarkerColor(kGreen+2);
  dst_dmean_vs_pt_graph.SetLineColor(kGreen+2);
  TCanvas * cc = new TCanvas();
  dst_dmean_vs_pt_graph.Draw("ap");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_dmean_vs_dstar_pt_graph.pdf");
  //rsigma
    TGraphAsymmErrors dst_rsigma_vs_pt_graph(5,dst_pt_mean_dstar_mass_pos,dst_pt_rwidths,errXlow_mean_dst_pt,errXhi_mean_dst_pt,dst_pt_rwidths_err,dst_pt_rwidths_err);
  dst_rsigma_vs_pt_graph.SetTitle(";p_{T}(D^{*})[MeV]; #delta #sigma(D^{*}) fit [%%]");
  dst_rsigma_vs_pt_graph.SetMarkerStyle(22);
  dst_rsigma_vs_pt_graph.SetMarkerColor(kGreen+2);
  dst_rsigma_vs_pt_graph.SetLineColor(kGreen+2);
  cc->Clear();
  dst_rsigma_vs_pt_graph.Draw("ap");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_rsigma_vs_dstar_pt_graph.pdf");
  //p
  //make the errors for the dmeans 5% as large
  //dst_p_dmeans_err[4]*=0.01;
  TGraphAsymmErrors dst_dmean_vs_p_graph(5,dst_p_mean_dstar_mass_pos,dst_p_dmeans,errXlow_mean_dst_p,errXhi_mean_dst_p,dst_p_dmeans_err,dst_p_dmeans_err);
  dst_dmean_vs_p_graph.SetTitle(";p(D^{*})[MeV]; #delta #mu(D^{*}) fit [MeV]");
  dst_dmean_vs_p_graph.SetMarkerStyle(22);
  dst_dmean_vs_p_graph.SetMarkerColor(kGreen+2);
  dst_dmean_vs_p_graph.SetLineColor(kGreen+2);
  cc->Clear();
  dst_dmean_vs_p_graph.Draw("ap");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_dmean_vs_dstar_p_graph.pdf");
  //rsigma
    TGraphAsymmErrors dst_rsigma_vs_p_graph(5,dst_p_mean_dstar_mass_pos,dst_p_rwidths,errXlow_mean_dst_p,errXhi_mean_dst_p,dst_p_rwidths_err,dst_p_rwidths_err);
  dst_rsigma_vs_p_graph.SetTitle(";p(D^{*})[MeV]; #delta #sigma(D^{*}) fit [%%]");
  dst_rsigma_vs_p_graph.SetMarkerStyle(22);
  dst_rsigma_vs_p_graph.SetMarkerColor(kGreen+2);
  dst_rsigma_vs_p_graph.SetLineColor(kGreen+2);
  cc->Clear();
  dst_rsigma_vs_p_graph.Draw("ap");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_rsigma_vs_dstar_p_graph.pdf");
  //mu
    TGraphAsymmErrors mu_dmean_vs_pt_graph(5,mu_pt_mean_dstar_mass_pos,mu_pt_dmeans,errXlow_mean_mu_pt,errXhi_mean_mu_pt,mu_pt_dmeans_err,mu_pt_dmeans_err);
  mu_dmean_vs_pt_graph.SetTitle(";p_{T}(#mu)[MeV]; #delta #mu(#mu) fit [MeV]");
  mu_dmean_vs_pt_graph.SetMarkerStyle(22);
  mu_dmean_vs_pt_graph.SetMarkerColor(kGreen+2);
  mu_dmean_vs_pt_graph.SetLineColor(kGreen+2);
  cc->Clear();
  mu_dmean_vs_pt_graph.Draw("ap");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_dmean_vs_mu_pt_graph.pdf");
  //rsigma
    TGraphAsymmErrors mu_rsigma_vs_pt_graph(5,mu_pt_mean_dstar_mass_pos,mu_pt_rwidths,errXlow_mean_mu_pt,errXhi_mean_mu_pt,mu_pt_rwidths_err,mu_pt_rwidths_err);
  mu_rsigma_vs_pt_graph.SetTitle(";p_{T}(#mu)[MeV]; #delta #sigma(#mu) fit [%%]");
  mu_rsigma_vs_pt_graph.SetMarkerStyle(22);
  mu_rsigma_vs_pt_graph.SetMarkerColor(kGreen+2);
  mu_rsigma_vs_pt_graph.SetLineColor(kGreen+2);
  cc->Clear();
  mu_rsigma_vs_pt_graph.Draw("ap");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_rsigma_vs_mu_pt_graph.pdf");
  //p
  TGraphAsymmErrors mu_dmean_vs_p_graph(5,mu_p_mean_dstar_mass_pos,mu_p_dmeans,errXlow_mean_mu_p,errXhi_mean_mu_p,mu_p_dmeans_err,mu_p_dmeans_err);
  mu_dmean_vs_p_graph.SetTitle(";p(#mu)[MeV]; #delta #mu(#mu) fit [MeV]");
  mu_dmean_vs_p_graph.SetMarkerStyle(22);
  mu_dmean_vs_p_graph.SetMarkerColor(kGreen+2);
  mu_dmean_vs_p_graph.SetLineColor(kGreen+2);
  cc->Clear();
  mu_dmean_vs_p_graph.Draw("ap");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_dmean_vs_mu_p_graph.pdf");
  //rsigma
    TGraphAsymmErrors mu_rsigma_vs_p_graph(5,mu_p_mean_dstar_mass_pos,mu_p_rwidths,errXlow_mean_mu_p,errXhi_mean_mu_p,mu_p_rwidths_err,mu_p_rwidths_err);
  mu_rsigma_vs_p_graph.SetTitle(";p(#mu)[MeV]; #delta #sigma(#mu) fit [%%]");
  mu_rsigma_vs_p_graph.SetMarkerStyle(22);
  mu_rsigma_vs_p_graph.SetMarkerColor(kGreen+2);
  mu_rsigma_vs_p_graph.SetLineColor(kGreen+2);
  cc->Clear();
  mu_rsigma_vs_p_graph.Draw("ap");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_rsigma_vs_mu_p_graph.pdf");


  //now draw the bins all on top of each other.
  rs_dst_pt_bins[0]->SetLineColor(kBlue);
  rs_dst_pt_bins[1]->SetLineColor(kGreen+2);
  rs_dst_pt_bins[2]->SetLineColor(kMagenta);
  rs_dst_pt_bins[3]->SetLineColor(kOrange);
  rs_dst_pt_bins[4]->SetLineColor(kRed);
  //p
  rs_dst_p_bins[0]->SetLineColor(kBlue);
  rs_dst_p_bins[1]->SetLineColor(kGreen+2);
  rs_dst_p_bins[2]->SetLineColor(kMagenta);
  rs_dst_p_bins[3]->SetLineColor(kOrange);
  rs_dst_p_bins[4]->SetLineColor(kRed);
  //mu pt
  rs_mu_pt_bins[0]->SetLineColor(kBlue);
  rs_mu_pt_bins[1]->SetLineColor(kGreen+2);
  rs_mu_pt_bins[2]->SetLineColor(kMagenta);
  rs_mu_pt_bins[3]->SetLineColor(kOrange);
  rs_mu_pt_bins[4]->SetLineColor(kRed);
  //p
  rs_mu_p_bins[0]->SetLineColor(kBlue);
  rs_mu_p_bins[1]->SetLineColor(kGreen+2);
  rs_mu_p_bins[2]->SetLineColor(kMagenta);
  rs_mu_p_bins[3]->SetLineColor(kOrange);
  rs_mu_p_bins[4]->SetLineColor(kRed);

  //make the legend;
  TLegend * leg_dst_p = new TLegend(0.7,0.6,0.9,0.9);
  TLegend * leg_dst_pt = new TLegend(0.7,0.6,0.9,0.9);
  TLegend * leg_mu_p = new TLegend(0.7,0.6,0.9,0.9);
  TLegend * leg_mu_pt = new TLegend(0.7,0.6,0.9,0.9);
  //
  leg_dst_pt->AddEntry(rs_dst_pt_bins[0],Form("p_{T}(D*)<%.1f",2.13e3));
  leg_dst_pt->AddEntry(rs_dst_pt_bins[1],Form("%.1f#leq p_{T}(D*)<%.1f",2.13e3,2.95e3));
  leg_dst_pt->AddEntry(rs_dst_pt_bins[2],Form("%.1f#leq p_{T}(D*)<%.1f",2.95e3,3.91e3));
  leg_dst_pt->AddEntry(rs_dst_pt_bins[3],Form("%.1f#leq p_{T}(D*)<%.1f",3.91e3,5.47e3));
  leg_dst_pt->AddEntry(rs_dst_pt_bins[4],Form("p_{T}(D*)#geq %.1f",5.47e3));
  cc->Clear();
  rs_dst_pt_bins[0]->Draw();
  for(int i=1;i<5;++i){
    rs_dst_pt_bins[i]->Draw("same");
  }
  leg_dst_pt->Draw();
  cc->SetLogy(true);
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_mass_dst_pt_bins.pdf");

  cc->Clear();
  leg_dst_p->AddEntry(rs_dst_p_bins[0],Form("p(D*)<%.1f",3.57e4));
  leg_dst_p->AddEntry(rs_dst_p_bins[1],Form("%.1f#leq p(D*)<%.1f",3.57e4,4.59e4));
  leg_dst_p->AddEntry(rs_dst_p_bins[2],Form("%.1f#leq p(D*)<%.1f",4.59e4,5.87e4));
  leg_dst_p->AddEntry(rs_dst_p_bins[3],Form("%.1f#leq p(D*)<%.1f",5.87e4,7.99e4));
  leg_dst_p->AddEntry(rs_dst_p_bins[4],Form("p(D*)#geq %.1f",7.99e4));
  cc->Clear();
  rs_dst_p_bins[0]->Draw();
  for(int i=1;i<5;++i){
    rs_dst_p_bins[i]->Draw("same");
  }
  leg_dst_p->Draw();
  cc->SetLogy(true);
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_mass_dst_p_bins.pdf");
  cc->Clear();

  //mu
  leg_mu_pt->AddEntry(rs_mu_pt_bins[0],Form("p_{T}(#mu)<%.1f",2.13e3));
  leg_mu_pt->AddEntry(rs_mu_pt_bins[1],Form("%.1f#leq p_{T}(#mu)<%.1f",2.13e3,2.95e3));
  leg_mu_pt->AddEntry(rs_mu_pt_bins[2],Form("%.1f#leq p_{T}(#mu)<%.1f",2.95e3,3.91e3));
  leg_mu_pt->AddEntry(rs_mu_pt_bins[3],Form("%.1f#leq p_{T}(#mu)<%.1f",3.91e3,5.47e3));
  leg_mu_pt->AddEntry(rs_mu_pt_bins[4],Form("p_{T}(#mu)#geq %.1f",5.47e3));
  cc->Clear();
  rs_mu_pt_bins[0]->Draw();
  for(int i=1;i<5;++i){
    rs_mu_pt_bins[i]->Draw("same");
  }
  leg_mu_pt->Draw();
  cc->SetLogy(true);
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_mass_mu_pt_bins.pdf");

  cc->Clear();
  leg_mu_p->AddEntry(rs_mu_p_bins[0],Form("p(#mu)<%.1f",3.57e4));
  leg_mu_p->AddEntry(rs_mu_p_bins[1],Form("%.1f#leq p(#mu)<%.1f",3.57e4,4.59e4));
  leg_mu_p->AddEntry(rs_mu_p_bins[2],Form("%.1f#leq p(#mu)<%.1f",4.59e4,5.87e4));
  leg_mu_p->AddEntry(rs_mu_p_bins[3],Form("%.1f#leq p(#mu)<%.1f",5.87e4,7.99e4));
  leg_mu_p->AddEntry(rs_mu_p_bins[4],Form("p(#mu)#geq %.1f",7.99e4));
  cc->Clear();
  rs_mu_p_bins[0]->Draw();
  for(int i=1;i<5;++i){
    rs_mu_p_bins[i]->Draw("same");
  }
  leg_mu_p->Draw();
  cc->SetLogy(true);
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_dstar_mass_mu_p_bins.pdf");
  cc->Clear();


  //now, take the results of the fits and combine them to see if the yields are insensitive to changes

  double points[4] = {0,0,0,0};
  double points_err[4] = {0,0,0,0};
  cout<<"------------------------------------------"<<endl;
  cout<<"------------------------------------------"<<endl;
  cout<<"------------------------------------------"<<endl;
  cout<<"bin"<<setw(10)<<"D p"<<setw(10)<<"D pt"<<setw(10)<<"mu p"<<setw(10)<<"mu pt"<<endl;
  for(int i=0; i<5;++i){
    points[0] += dst_p_yield[i];
    points_err[0]+=dst_p_yield_err[i]*dst_p_yield_err[i];
    points[1] += dst_pt_yield[i];
    points_err[1]+=dst_pt_yield_err[i]*dst_pt_yield_err[i];
    points[2] += mu_p_yield[i];
    points_err[2]+=mu_p_yield_err[i]*mu_p_yield_err[i];
    points[3] += mu_pt_yield[i];
    points_err[3]+=mu_pt_yield_err[i]*mu_pt_yield_err[i];
    cout<<i<<setw(10)<<dst_p_yield[i]<<setw(10)<<dst_pt_yield[i]<<setw(10)<<mu_p_yield[i]<<setw(10)<<mu_pt_yield[i]<<endl;
  }
  cout<<"------------------------------------------"<<endl;
  cout<<"------------------------------------------"<<endl;
  cout<<"------------------------------------------"<<endl;
  TH1D* the_final_comp = new TH1D("the_final_comp","; ;m(D^*)[MeV] ",4,0.5,4.5);
  for(int i=0; i<4;++i){
    cout<<"points["<<i<<"] = "<<points[i]<< endl;
    points_err[i] = TMath::Sqrt(points_err[i]);
    cout<<"points_err["<<i<<"] = "<<points_err[i]<<endl;
    cout<<"setting bin content to "<<points[i]<<endl;
    the_final_comp->SetBinContent(i+1,points[i]);
    the_final_comp->SetBinError(i+1,points_err[i]);
  }

  
  TString the_labels[4] ={"p(D*)","p_{T}(D*)","p(#mu)","p_{T}(#mu)"};
  for(int i=0; i<4;++i){
    the_final_comp->GetXaxis()->SetBinLabel(i+1,the_labels[i]);
   }
  //get the fit from the total sample.
  massFit tot_validation(channelFromFile+"_validation_for_time_int","j3g",w);
  TH1D* tot_mass = (TH1D*)f1->Get("RS_dt_hist_dstar_m");
  tot_mass->Add((TH1D*)f1->Get("RS_ss_dt_hist_dstar_m"),-1);
  tot_validation.setData(tot_mass);
  tot_validation.fit();
  TLine *centr_val = new TLine(the_final_comp->GetXaxis()->GetXmin(),tot_validation.getNsig(),the_final_comp->GetXaxis()->GetXmax(),tot_validation.getNsig());
  TLine *centr_val_hi = new TLine(the_final_comp->GetXaxis()->GetXmin(),tot_validation.getNsig()+tot_validation.getNsigErr(),the_final_comp->GetXaxis()->GetXmax(),tot_validation.getNsig()+tot_validation.getNsigErr());
  TLine *centr_val_lo = new TLine(the_final_comp->GetXaxis()->GetXmin(),tot_validation.getNsig()-tot_validation.getNsigErr(),the_final_comp->GetXaxis()->GetXmax(),tot_validation.getNsig()-tot_validation.getNsigErr());
  centr_val->SetLineColor(kGreen+2);
  centr_val_hi->SetLineColor(kRed);
  centr_val_lo->SetLineColor(kRed);
  TGraph *shade = new TGraph(4);
  shade->SetPoint(0,the_final_comp->GetXaxis()->GetXmin(),tot_validation.getNsig()+tot_validation.getNsigErr());
  shade->SetPoint(1,the_final_comp->GetXaxis()->GetXmax(),tot_validation.getNsig()+tot_validation.getNsigErr());
  shade->SetPoint(2,the_final_comp->GetXaxis()->GetXmax(),tot_validation.getNsig()-tot_validation.getNsigErr());
  shade->SetPoint(3,the_final_comp->GetXaxis()->GetXmin(),tot_validation.getNsig()-tot_validation.getNsigErr());
  shade->SetFillColor(kRed);
  shade->SetFillStyle(3005);
  
  cc->Clear();
  gStyle->SetOptStat(0);
  cc->SetLogy(false);
  //  the_final_comp->SetMarkerSize(3);
  //the_final_comp->SetMarkerStyle(20);
  the_final_comp->GetYaxis()->SetRangeUser(2.4e6,2.6e6);
  the_final_comp->Draw("e");
  shade->Draw("fsame");
  centr_val->Draw();
  centr_val_hi->Draw();
  centr_val_lo->Draw();
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+channelFromFile+"_total_yield_systematic_check.pdf");
  f1->Close();
  f2->Close();
  return 0;
}
