//c++
#include <iostream>

#include <cmath>
#include <stdlib.h>//chmod for read/write/ex. protecting the output so we can't unblind.
#include <unistd.h> //redirect output.
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
  setLHCbcanvas();
  bool blind=true;
  cout<<"Extracting RS and WS time dependece and writing to file"<<endl;
  if(argc<4){
    cout<<"********************************************"<<endl;
    cout<<"Extracts the file. needs inputs"<<endl;
    cout<<"[1] The rs file"<<endl;
    cout<<"[2] the fit model"<<endl;
    cout<<"[3] the WS file"<<endl;
    cout<<"********************************************"<<endl;
    return 0;
  }
  cout<<"using rs file"<<argv[1]<<endl;
  cout<<"using fit model "<<argv[2]<<endl;
  cout<<"using ws file "<<argv[3]<<endl;
  TFile *f1 =TFile::Open(argv[1]);
  TFile *f2 = TFile::Open(argv[2]);
  TFile *f3 = TFile::Open(argv[3]);
  f2->ls();
  TString channelFromFile = argv[2];
  cout<<"before, channelFromFile = "<<channelFromFile<<endl;
  channelFromFile.ToLower();
  if(channelFromFile.Contains("rs")){
    channelFromFile = "rsw";
  }
  else{
    cout<<"No WS!"<<endl;
    return 0;
  }
  cout<<"getting channel "<<channelFromFile<<endl;
  //Get the time histogram to to <t> and <t^2>
  //have to do separately for + and -
  TH1D* rs_time_histo_pos = (TH1D*)f1->Get("RS_dt_d0_decay_time_distr_pos");
  TH1D* rs_ss_time_histo_pos = (TH1D*)f1->Get("RS_ss_dt_d0_decay_time_distr_pos");
  TH1D* rs_time_histo_neg = (TH1D*)f1->Get("RS_dt_d0_decay_time_distr_neg");
  TH1D* rs_ss_time_histo_neg = (TH1D*)f1->Get("RS_ss_dt_d0_decay_time_distr_neg");

  rs_time_histo_pos->Sumw2();
  rs_ss_time_histo_pos->Sumw2();
  rs_time_histo_pos->Add(rs_ss_time_histo_pos,-1);

  rs_time_histo_neg->Sumw2();
  rs_ss_time_histo_neg->Sumw2();
  rs_time_histo_neg->Add(rs_ss_time_histo_neg,-1);

  std::vector<TH1D*> rs_timesq_histo_pos;
  rs_timesq_histo_pos.push_back((TH1D*)f1->Get("RS_dt_d0_decay_time_squared_distr_pos_bin1"));
  rs_timesq_histo_pos.push_back((TH1D*)f1->Get("RS_dt_d0_decay_time_squared_distr_pos_bin2"));
  rs_timesq_histo_pos.push_back((TH1D*)f1->Get("RS_dt_d0_decay_time_squared_distr_pos_bin3"));
  rs_timesq_histo_pos.push_back((TH1D*)f1->Get("RS_dt_d0_decay_time_squared_distr_pos_bin4"));
  rs_timesq_histo_pos.push_back((TH1D*)f1->Get("RS_dt_d0_decay_time_squared_distr_pos_bin5"));
  for(auto hist: rs_timesq_histo_pos){
    hist->Sumw2();
  }
  rs_timesq_histo_pos[0]->Add((TH1D*)f1->Get("RS_ss_dt_d0_decay_time_squared_distr_pos_bin1"),-1);
  rs_timesq_histo_pos[1]->Add((TH1D*)f1->Get("RS_ss_dt_d0_decay_time_squared_distr_pos_bin2"),-1);
  rs_timesq_histo_pos[2]->Add((TH1D*)f1->Get("RS_ss_dt_d0_decay_time_squared_distr_pos_bin3"),-1);
  rs_timesq_histo_pos[3]->Add((TH1D*)f1->Get("RS_ss_dt_d0_decay_time_squared_distr_pos_bin4"),-1);
  rs_timesq_histo_pos[4]->Add((TH1D*)f1->Get("RS_ss_dt_d0_decay_time_squared_distr_pos_bin5"),-1);
  std::vector<TH1D*> rs_timesq_histo_neg;
  rs_timesq_histo_neg.push_back((TH1D*)f1->Get("RS_dt_d0_decay_time_squared_distr_neg_bin1"));
  rs_timesq_histo_neg.push_back((TH1D*)f1->Get("RS_dt_d0_decay_time_squared_distr_neg_bin2"));
  rs_timesq_histo_neg.push_back((TH1D*)f1->Get("RS_dt_d0_decay_time_squared_distr_neg_bin3"));
  rs_timesq_histo_neg.push_back((TH1D*)f1->Get("RS_dt_d0_decay_time_squared_distr_neg_bin4"));
  rs_timesq_histo_neg.push_back((TH1D*)f1->Get("RS_dt_d0_decay_time_squared_distr_neg_bin5"));
  for(auto hist: rs_timesq_histo_neg){
    hist->Sumw2();
  }
  rs_timesq_histo_neg[0]->Add((TH1D*)f1->Get("RS_ss_dt_d0_decay_time_squared_distr_neg_bin1"),-1);
  rs_timesq_histo_neg[1]->Add((TH1D*)f1->Get("RS_ss_dt_d0_decay_time_squared_distr_neg_bin2"),-1);
  rs_timesq_histo_neg[2]->Add((TH1D*)f1->Get("RS_ss_dt_d0_decay_time_squared_distr_neg_bin3"),-1);
  rs_timesq_histo_neg[3]->Add((TH1D*)f1->Get("RS_ss_dt_d0_decay_time_squared_distr_neg_bin4"),-1);
  rs_timesq_histo_neg[4]->Add((TH1D*)f1->Get("RS_ss_dt_d0_decay_time_squared_distr_neg_bin5"),-1);
  std::vector<double> mean_t_pos, mean_t2_pos, mean_t_neg,mean_t2_neg;
  int bins_td []= {46,53,56,60,66,rs_time_histo_pos->GetNbinsX()};//bin boundaries
  for(int i=0;i<5;++i){
    rs_time_histo_pos->GetXaxis()->SetRange(bins_td[i],bins_td[i+1]);
    mean_t_pos.push_back( rs_time_histo_pos->GetMean());
    rs_time_histo_pos->GetXaxis()->SetRange();

    rs_time_histo_neg->GetXaxis()->SetRange(bins_td[i],bins_td[i+1]);
    mean_t_neg.push_back( rs_time_histo_neg->GetMean());
    rs_time_histo_neg->GetXaxis()->SetRange();
  }  
  for(int i=0; i<5;++i){
    mean_t2_pos.push_back(rs_timesq_histo_pos[i]->GetMean());
    mean_t2_neg.push_back(rs_timesq_histo_neg[i]->GetMean());
  }
  std::vector<TH1D*>pos_bins,neg_bins;
  std::vector<TH1D*>pos_binsWS,neg_binsWS;
  RooWorkspace * w = (RooWorkspace*)f2->Get(channelFromFile);
  w->Print("V");
  //in order to avoid feed through from fits, get the initial values
  array<double,4> thePars{
    (w->var("kappa")->getVal()),
      (w->var("n")->getVal()),
      (w->var("nbkg")->getVal()),
      (w->var("nsig")->getVal())};

  int nbins = 5;
  for(int i=0;i<nbins;++i){
    pos_bins.push_back((TH1D*)f1->Get(Form("RS_dst_mass_td0_pos_bin%d",i+1)));
    pos_bins[i]->Sumw2();
    neg_bins.push_back((TH1D*)f1->Get(Form("RS_dst_mass_td0_neg_bin%d",i+1)));
    neg_bins[i]->Sumw2();
    //WS
    pos_binsWS.push_back((TH1D*)f3->Get(Form("WS_dst_mass_td0_pos_bin%d",i+1)));
    pos_binsWS[i]->Sumw2();
    neg_binsWS.push_back((TH1D*)f3->Get(Form("WS_dst_mass_td0_neg_bin%d",i+1)));
    neg_binsWS[i]->Sumw2();
  }

  for(int i=0; i<nbins;++i){
    pos_bins[i]->Add((TH1D*)f1->Get(Form("RS_ss_dst_mass_td0_pos_bin%d",i+1)),-1);
    neg_bins[i]->Add((TH1D*)f1->Get(Form("RS_ss_dst_mass_td0_neg_bin%d",i+1)),-1);
    //WS
    pos_binsWS[i]->Add((TH1D*)f3->Get(Form("WS_ss_dst_mass_td0_pos_bin%d",i+1)),-1);
    neg_binsWS[i]->Add((TH1D*)f3->Get(Form("WS_ss_dst_mass_td0_neg_bin%d",i+1)),-1);
  }//commented out to try raw asymmetry
  massFit* theFitspos;
  massFit* theFitsneg;

  massFit* theFitsposWS;
  massFit* theFitsnegWS;
  
  double the_sig_pos[nbins],the_sig_pos_err[nbins];
  double the_sig_neg[nbins],the_sig_neg_err[nbins];

  double the_sig_posWS[nbins],the_sig_posWS_err[nbins];
  double the_sig_negWS[nbins],the_sig_negWS_err[nbins];

  for(int i=0;i<nbins;++i){
    theFitspos = new massFit(Form("RS_dst_mass_pos_bin%d",i+1),"j3g",w,"FinalExtraction");
    theFitspos->setData(pos_bins[i]);
    // if(i==0){
    //   theFitspos->FloatMeanWidth();
    // }
    theFitspos->initValsByHand(thePars);
    //theFitspos->FloatMeanWidth();
    theFitspos->fit();
    theFitspos->savePlots(true,Form("RS_dst_mass_pos_bin%d",i+1));
    the_sig_pos[i]=theFitspos->getNsig()*2;//prescale
    the_sig_pos_err[i]=theFitspos->getNsigErr()*2;//prescale
    theFitspos->Reset();
  }

  
  for(int i=0;i<nbins;++i){
    theFitsneg = new massFit(Form("RS_dst_mass_neg_bin%d",i+1),"j3g",w,"FinalExtraction");
    theFitsneg->setData(neg_bins[i]);
    // if(i==0){
    //   theFitsneg->FloatMeanWidth();
    // }

    theFitsneg->initValsByHand(thePars);
    //    theFitsneg->FloatMeanWidth();
    theFitsneg->fit();
    theFitsneg->savePlots(true,Form("RS_dst_mass_neg_bin%d",i+1));
    the_sig_neg[i]=theFitsneg->getNsig()*2;//prescale
    the_sig_neg_err[i]=theFitsneg->getNsigErr()*2;//prescale

    theFitsneg->Reset();
  }

  //WS
  //redirect the output so we can't see it.
  int stdout_fd = dup(STDOUT_FILENO);
  if(blind){//start blinding
    freopen("blind_the_stuff.out", "w", stdout);
  }

  
  for(int i=0;i<nbins;++i){
    theFitsposWS = new massFit(Form("WS_dst_mass_pos_bin%d",i+1),"j3g",w,"FinalExtraction");
    theFitsposWS->setData(pos_bins[i]);
    // if(i==0){
    //   theFitsposWS->FloatMeanWidth();
    // }
    theFitsposWS->initValsByHand(thePars);
    //theFitsposWS->FloatMeanWidth();
    theFitsposWS->fit();
    theFitsposWS->savePlots(true,Form("WS_dst_mass_pos_bin%d",i+1));
    the_sig_posWS[i]=theFitsposWS->getNsig()*2;//prescale
    the_sig_posWS_err[i]=theFitsposWS->getNsigErr()*2;//prescale
    theFitsposWS->Reset();
  }

  
  for(int i=0;i<nbins;++i){
    theFitsnegWS = new massFit(Form("WS_dst_mass_neg_bin%d",i+1),"j3g",w,"FinalExtraction");
    theFitsnegWS->setData(neg_bins[i]);
    // if(i==0){
    //   theFitsnegWS->FloatMeanWidth();
    // }

    theFitsnegWS->initValsByHand(thePars);
    //    theFitsnegWS->FloatMeanWidth();
    theFitsnegWS->fit();
    theFitsnegWS->savePlots(true,Form("WS_dst_mass_neg_bin%d",i+1));
    the_sig_negWS[i]=theFitsnegWS->getNsig()*2;//prescale
    the_sig_negWS_err[i]=theFitsnegWS->getNsigErr()*2;//prescale

    theFitsnegWS->Reset();
  }
  
  if(blind){//end blinding
    fclose(stdout);
    dup2(stdout_fd, STDOUT_FILENO);
    stdout = fdopen(STDOUT_FILENO, "w");
    close(stdout_fd);
    std::remove("blind_the_stuff.out");
  }

  //print the file.
  std::ofstream outfile;
  std::cout<<"writing the files"<<endl;
  outfile.open("./SavedFits/final_yields_in_bins_pos.txt");
  outfile<<"Bin"<<std::setw(15)<<" <t>"<<std::setw(15)<<"<t^2>"<<std::setw(15)<<"N_RS"<<std::setw(15)<<"error_N_RS"<<"\n";
  for(int i=0; i<nbins;++i){
    outfile<<i+1<<std::setw(15)<<mean_t_pos[i]<<std::setw(15)<<mean_t2_pos[i]<<std::setw(15)
	   <<the_sig_pos[i]<<std::setw(15)<<the_sig_pos_err[i]
	   <<the_sig_posWS[i]<<std::setw(15)<<the_sig_posWS_err[i]
	   <<"\n";
  }
  outfile.close();
  outfile.open("./SavedFits/final_yields_in_bins_neg.txt");
  //outfile<<"\n\n";
  outfile<<"Bin \t <t> \t <t^2>\t N_RS \t error_N_RS \n";

  for(int i=0; i<nbins;++i){
    outfile<<i+1<<std::setw(15)<<mean_t_neg[i]<<std::setw(15)<<mean_t2_neg[i]<<std::setw(15)
	   <<the_sig_neg[i]<<std::setw(15)<<the_sig_neg_err[i]
	   <<the_sig_negWS[i]<<std::setw(15)<<the_sig_negWS_err[i]
	   <<"\n";
  }
  outfile.close();
  //  //change the permissions to do all the shiz
  //  system("chmod u=rw ./SavedFits/final_yields_in_bins_pos.txt");  

  delete theFitspos;
  delete theFitsneg;
  delete theFitsposWS;
  delete theFitsnegWS;
  return 0;

}
