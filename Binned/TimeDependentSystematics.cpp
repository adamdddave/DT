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
#include "TimeDependent2D.h"
using namespace std;
using namespace PlottingTools;


int main(int argc, char* const argv[]){
  //first thing, get the scaling factor from the file
  double the_scaling_factor_timeDep[5];
  std::ifstream sftd_file("./theScalingFactorTimeDependence.txt");
  int dum;
  double dumerr;
  if (sftd_file.is_open()){
    for(int i=0; i<5;++i){
      sftd_file>>dum>>the_scaling_factor_timeDep[i]>>dumerr;
    }
  }
  cout<<"read in time dependent scaling factors"<<endl;
  for(auto thing: the_scaling_factor_timeDep)  cout<<thing<<endl;
  double the_scaling_factor;
  std::ifstream sf_file("./theScalingFactor.txt");
  while(sf_file>>the_scaling_factor){cout<<"reading scaling factor from file"<<endl;}
  cout<<"read scaling factor "<<the_scaling_factor<<endl;
  if(!the_scaling_factor){cout<<"something terribly wrong here"<<endl;return 0;}
  sf_file.close();

  setLHCbcanvas();
  cout<<"Code for doing Time Dependent Systematics"<<endl;
  if(argc<3){
    cout<<"++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"Need a rootfile with time dependent things!"<<endl;
    cout<<"and the fit model!!!"<<endl;
    cout<<"Optional: Use time dependent SS background subtraction (bool)"<<endl;
    cout<<"++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    return 0;
  }
  TFile *f1 =TFile::Open(argv[1]);
  TFile *f2 = TFile::Open(argv[2]);
  bool useTimeDepSS = false;
  if(argc==4) useTimeDepSS = atoi(argv[3]);
  //f2->ls();
  TString channelFromFile = argv[2];
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
  RooWorkspace * w = (RooWorkspace*)f2->Get(channelFromFile);
  std::vector<double> dm_p, dme_p, rs_p,rse_p,dm_n,dme_n,rs_n,rse_n;
  //do 2d checks first
  std::vector<int>sl;
  std::vector<int>zoomBins;zoomBins.push_back(1);zoomBins.push_back(136);zoomBins.push_back(198);zoomBins.push_back(260);zoomBins.push_back(327);zoomBins.push_back(410);
  TimeDependent2D v_muipchi2_pos("mu_ipchi2_vs_td0_pos",f1,"_positive_muon_ipchi2",sl);
  TimeDependent2D v_muipchi2_zoom_pos("mu_ipchi2_vs_td0_zoom_pos",f1,"_positive_muon_ipchi2_zoom",zoomBins);
  TimeDependent2D v_log_muipchi2_pos("log_mu_ipchi2_vs_td0_pos",f1,"_positive_muon_log_ipchi2",sl);
  //  return 0;
  TimeDependent2D v_muipchi2_neg("mu_ipchi2_vs_td0_neg",f1,"_negative_muon_ipchi2",sl);
  TimeDependent2D v_muipchi2_zoom_neg("mu_ipchi2_vs_td0_zoom_neg",f1,"_negative_muon_ipchi2_zoom",zoomBins);
  TimeDependent2D v_log_muipchi2_neg("log_mu_ipchi2_vs_td0_neg",f1,"_negative_muon_log_ipchi2",sl);
  TimeDependent2D v_b_corr_mass_pos("b_corr_mass_vs_td0_pos",f1,"_positive_b_corr_m",sl);
  TimeDependent2D v_b_corr_mass_neg("b_corr_mass_vs_td0_neg",f1,"_negative_b_corr_m",sl);
  TimeDependent2D v_dtf_chi2_pos("dtf_chi2_vs_td0_pos",f1,"_positive_dtf_chi2",sl);
  TimeDependent2D v_dtf_chi2_neg("dtf_chi2_vs_td0_neg",f1,"_negative_dtf_chi2",sl);
  TimeDependent2D v_d_logipchi2_pos("d_log_ip_chi2_vs_td0_pos",f1,"_positive_d0ipchi2",sl);
  TimeDependent2D v_d_logipchi2_neg("d_log_ip_chi2_vs_td0_neg",f1,"_negative_d0ipchi2",sl);
  TimeDependent2D v_pis_matchchi2("pis_match_chi2_vs_td0",f1,"_pis_match_chi2",sl);
  //
  //  return 0;
  
  //get the bins.
  std::vector<TH1D*>pos_bins,neg_bins;
  int nbins = 5;
  for(int i=0;i<nbins;++i){
    pos_bins.push_back((TH1D*)f1->Get(Form("RS_dst_mass_td0_pos_bin%d",i+1)));
    pos_bins[i]->Sumw2();
    neg_bins.push_back((TH1D*)f1->Get(Form("RS_dst_mass_td0_neg_bin%d",i+1)));
    neg_bins[i]->Sumw2();
  }

  for(int i=0; i<nbins;++i){
    double sf = useTimeDepSS? the_scaling_factor_timeDep[i]:the_scaling_factor;
    pos_bins[i]->Add((TH1D*)f1->Get(Form("RS_ss_dst_mass_td0_pos_bin%d",i+1)),-sf);
    neg_bins[i]->Add((TH1D*)f1->Get(Form("RS_ss_dst_mass_td0_neg_bin%d",i+1)),-sf);
  }//commented out to try raw asymmetry
  //now fit each one.
  massFit* theFitspos;
  massFit* theFitsneg;
  double the_sig_pos[nbins],the_sig_pos_err[nbins];
  double the_sig_neg[nbins],the_sig_neg_err[nbins];

  for(int i=0;i<nbins;++i){
    theFitspos = new massFit(Form("RS_dst_mass_pos_bin%d",i+1),"j3g",w,"TimeDependentSystematics");
    theFitspos->setData(pos_bins[i]);
    //theFitspos->FloatMeanWidth();
    theFitspos->fit();
    theFitspos->savePlots(true,Form("RS_dst_mass_pos_bin%d",i+1));
    the_sig_pos[i]=theFitspos->getNsig()*2;//prescale
    the_sig_pos_err[i]=theFitspos->getNsigErr()*2;//prescale
    dm_p.push_back(theFitspos->getDMean());
    dme_p.push_back(theFitspos->getDMeanErr());
    rs_p.push_back(theFitspos->getrSigma());
    rse_p.push_back(theFitspos->getrSigmaErr());
    theFitspos->Reset();
  }

  
  for(int i=0;i<nbins;++i){
    theFitsneg = new massFit(Form("RS_dst_mass_neg_bin%d",i+1),"j3g",w,"TimeDependentSystematics");
    theFitsneg->setData(neg_bins[i]);
    //    theFitsneg->FloatMeanWidth();
    theFitsneg->fit();
    theFitsneg->savePlots(true,Form("RS_dst_mass_neg_bin%d",i+1));
    the_sig_neg[i]=theFitsneg->getNsig()*2;//prescale
    the_sig_neg_err[i]=theFitsneg->getNsigErr()*2;//prescale
    dm_n.push_back(theFitsneg->getDMean());
    dme_n.push_back(theFitsneg->getDMeanErr());
    rs_n.push_back(theFitsneg->getrSigma());
    rse_n.push_back(theFitsneg->getrSigmaErr());
    theFitsneg->Reset();
  }

  double binVal[nbins],binValErr[nbins];
  for(int i=0; i<nbins;++i){
    binVal[i]=the_sig_neg[i]/the_sig_pos[i];
    binValErr[i]=TMath::Sqrt((binVal[i]*binVal[i])*(TMath::Power(the_sig_pos_err[i]/the_sig_pos[i],2)+TMath::Power(the_sig_neg_err[i]/the_sig_neg[i],2)));
    //double error;
    /*    error = the_sig_neg[i]/TMath::Power(the_sig_pos[i],2);
    error+=TMath::Power(the_sig_neg[i],2)/TMath::Power(the_sig_pos[i],3);
    error = TMath::Sqrt(error);
    binValErr[i]=error;*/
  }
  //now make a tgraph out of it and we're done!
  TH1D* the_td_distr  = (TH1D*)f1->Get("RS_dt_d0_decay_time_distr");
  TH1D* the_td_distr_ss  = (TH1D*)f1->Get("RS_ss_dt_d0_decay_time_distr");
  the_td_distr->Sumw2();
  the_td_distr_ss->Sumw2();
  the_td_distr->Add(the_td_distr_ss,-the_scaling_factor);
  int bins_td []= {451,521,551,591,651,the_td_distr->GetNbinsX()};
  //int bins_td []= {46,52,53,55,56,58,60,63,66,108,the_td_distr->GetNbinsX()};

  double mean_td_pos[nbins];
  double xLow[nbins],xHi[nbins];
  for(int i=0;i<nbins;++i){
    the_td_distr->GetXaxis()->SetRange(bins_td[i],bins_td[i+1]);
    mean_td_pos[i] = the_td_distr->GetMean();
    the_td_distr->GetXaxis()->SetRange();
    xLow[i]=mean_td_pos[i] - the_td_distr->GetBinCenter(bins_td[i]);
    xHi[i]=the_td_distr->GetBinCenter(bins_td[i+1])-mean_td_pos[i];
  }
  TGraphAsymmErrors *thePlot = new TGraphAsymmErrors(nbins,mean_td_pos,binVal,xLow,xHi,binValErr,binValErr);
  thePlot->SetMarkerSize(1.5);
  thePlot->SetMarkerColor(kBlack);
  thePlot->SetLineColor(kBlack);
  thePlot->SetTitle(";D^{0}t/#tau;N(D*^{-})/N(D*^{+})");
  thePlot->SetName("rs_over_rs_ratio");


  //add asymmetry plot
  double asymm [5];
  double asymmErr[5];
  for(int i=0; i<5;++i){
    asymm[i] = (the_sig_neg[i]-the_sig_pos[i])/(the_sig_neg[i]+the_sig_pos[i]);
    asymmErr[i] =TMath::Power((1-asymm[i])*the_sig_neg_err[i],2.)+TMath::Power((1+asymm[i])*the_sig_pos_err[i],2.);
    asymmErr[i] = asymmErr[i]/TMath::Power(the_sig_pos[i]+the_sig_neg[i],2.);
    asymmErr[i] = TMath::Sqrt(asymmErr[i]);
  }
  TGraphAsymmErrors *theAsymm = new TGraphAsymmErrors(nbins,mean_td_pos,asymm,xLow,xHi,asymmErr,asymmErr);
  theAsymm->SetMarkerSize(1.5);
  theAsymm->SetMarkerColor(kBlack);
  theAsymm->SetLineColor(kBlack);
  theAsymm->SetTitle(";D^{0}t/#tau;A_{D^{*}} = #frac{N(D^{*-})-N(D^{*+})}{N(D^{*-})+N(D^{*+})}");
  theAsymm->SetName("rs_asymm");
  TFile *fout = new TFile("SavedFits/TimeDependentSystematics/rs_over_rs_ratio.root","RECREATE");
  fout->cd();
  thePlot->Write();
  theAsymm->Write();
  fout->Close();
  f1->Close();
  f2->Close();
  
  TCanvas* cc=new TCanvas();
  thePlot->Draw("ap");
  cc->SaveAs("SavedFits/TimeDependentSystematics/rs_d0_over_d0bar_graph.pdf");
  // TFile fout_timedep("rs_d0_over_d0_bar_graph.root","RECREATE");
  // fout_timedep.cd();
  // thePlot->Write();
  // fout_timedep.Close();
  cc->Clear();
  theAsymm->Draw("ap");
  cc->SaveAs("SavedFits/TimeDependentSystematics/rs_d0_asymm_graph.pdf");
  //print out a table of the dmeans and rsigmas
  cout<<"dmeans"<<endl;
  cout<<"positive"<<endl;
  for(unsigned int i=0;i<dm_p.size();++i){
    cout<<dm_p[i]<<"  +-  "<<dme_p[i]<<endl;
  }
  cout<<"negative"<<endl;
  for(unsigned int i=0;i<dm_n.size();++i){
    cout<<dm_n[i]<<"  +-  "<<dme_n[i]<<endl;
  }
  cout<<"rsigmas"<<endl;
  cout<<"positive"<<endl;
  for(unsigned int i=0;i<rs_p.size();++i){
    cout<<rs_p[i]<<"  +-  "<<rse_p[i]<<endl;
  }
  cout<<"negative"<<endl;
  for(unsigned int i=0;i<rs_n.size();++i){
    cout<<rs_n[i]<<"  +-  "<<rse_n[i]<<endl;
  }
  cout<<"positive"<<endl;
  for(auto val : the_sig_pos){
    cout<<"val = "<<val<<endl;
  }

    cout<<"negitive"<<endl;
  for(auto val : the_sig_neg){
    cout<<"val = "<<val<<endl;
  }
//now do the 2d studies for mike.
  
  return 0;
}
