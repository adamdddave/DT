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
#include <TRandom3.h>
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
//some supporting shiz from toy mc
double theBlindingFunctionPos(double tval, double tsqval, double nRS,
			      double yPrimePlus,double xPrimePlus,double r_sub_d,
			      double rdblind, double yprimePblind,double xp2Pblind){
  //this is the code which returns the value to be added to the WS + yields
  //you pass the blinded values.
  //also pass the generated values to ease coverage tests
  double r_sub_d_prime = r_sub_d+rdblind;
  double yPrimePlus_prime = yPrimePlus+yprimePblind;
  double xPrime2_prime= pow(xPrimePlus,2)+xp2Pblind;
  
  //generate the value
  double Rblind = r_sub_d_prime
    + sqrt(r_sub_d_prime)*tval*yPrimePlus_prime
    + 0.25*(xPrime2_prime+pow(yPrimePlus_prime,2))*tsqval;
  double Rreg = r_sub_d
    + sqrt(r_sub_d)*tval*yPrimePlus
    + 0.25*(pow(xPrimePlus,2)+pow(yPrimePlus,2))*tsqval;
  double diff = nRS*(Rblind-Rreg);
  return diff;
}
double theBlindingFunctionNeg(double tval, double tsqval, double nRS,
			      double yPrimeMins,double xPrimeMins,double r_d_bar,
			      double rdbarblind, double yprimeMblind,double xp2Mblind){
  //this is the code which returns the value to be added to the WS + yields
  //you pass the blinded values.
  //copied from above
  //end copying
  double r_d_bar_prime = r_d_bar+rdbarblind;
  double yPrimeMins_prime = yPrimeMins+yprimeMblind;
  double xPrime2_prime= pow(xPrimeMins,2)+xp2Mblind;
  
  //generate the value
  double Rblind = r_d_bar_prime
    + sqrt(r_d_bar_prime)*tval*yPrimeMins_prime
    + 0.25*(xPrime2_prime+pow(yPrimeMins_prime,2))*tsqval;
  double Rreg = r_d_bar
    + sqrt(r_d_bar)*tval*yPrimeMins
    + 0.25*(pow(xPrimeMins,2)+pow(yPrimeMins,2))*tsqval;
  double diff = nRS*(Rblind-Rreg);
  return diff;
}

//and the main

int main(int argc, char* const argv[]){
  setLHCbcanvas();
  bool blind=true;
  // New 1-23-16. Use the blinding on the dataset instead of the fitter. Read Augusto's seed here.
  int _BlindingSeed;
  system("chmod u+r /path_to/WSFitter-1.2/augusto_seed.txt");
  std::ifstream file("/path_to/WSFitter-1.2/augusto_seed.txt");
  while ( file>>_BlindingSeed ){std::cout<<"reading augusto's seed"<<std::endl;}
  system("chmod u-r /path_to/WSFitter-1.2/augusto_seed.txt");
  TRandom3 donram(_BlindingSeed);
  double xp2_plus_blind = donram.Gaus(0.,0.00038);
  double xp2_mins_blind = donram.Gaus(0.,0.00038);
  double yp_plus_blind = donram.Gaus(0.,0.0015);
  double yp_mins_blind = donram.Gaus(0.,0.0015);
  double rd_plus_blind = donram.Gaus(0.,0.0005);
  double rd_mins_blind = donram.Gaus(0.,0.0005);
  double yPrimePlus = 0.00478;
  double yPrimeMins = 0.00483;
  double xPrimePlus = 0.007;
  double xPrimeMins = 0.00774;
  double r_sub_d = 3.545e-03;
  double r_d_bar = 3.591e-03;
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

  double the_sig_posWSBlind[nbins],the_sig_posWSBlind_err[nbins];
  double the_sig_negWSBlind[nbins],the_sig_negWSBlind_err[nbins];

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
    the_sig_posWS[i]=theFitsposWS->getNsig();
    the_sig_posWS_err[i]=theFitsposWS->getNsigErr();
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
    the_sig_negWS[i]=theFitsnegWS->getNsig();
    the_sig_negWS_err[i]=theFitsnegWS->getNsigErr();

    theFitsnegWS->Reset();
  }

  //now blind the shiz
  for(int i=0; i<nbins;++i){
    the_sig_posWSBlind[i] = the_sig_posWS[i]+theBlindingFunctionPos(mean_t_pos[i],mean_t2_pos[i],
								    the_sig_pos[i],
								    yPrimePlus,xPrimePlus,r_sub_d,
								    rd_plus_blind,yp_plus_blind,xp2_plus_blind);
    the_sig_negWSBlind[i] = the_sig_negWS[i]+theBlindingFunctionNeg(mean_t_neg[i],mean_t2_neg[i],
								    the_sig_neg[i],
								    yPrimeMins,xPrimeMins,r_d_bar,
								    rd_mins_blind,yp_mins_blind,xp2_mins_blind);
    the_sig_posWSBlind_err[i] = the_sig_posWS_err[i];
    the_sig_negWSBlind_err[i] = the_sig_negWS_err[i];
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
  outfile<<"Bin"<<std::setw(15)<<" <t>"<<std::setw(15)<<"<t^2>"<<std::setw(15)<<"N_RS"<<std::setw(15)<<"error_N_RS"<<std::setw(15)<<"N_WS"<<std::setw(15)<<"error_N_WS\n";
  for(int i=0; i<nbins;++i){
    outfile<<i+1<<std::setw(15)
	   <<mean_t_pos[i]<<std::setw(15)
	   <<mean_t2_pos[i]<<std::setw(15)
	   <<the_sig_pos[i]<<std::setw(15)
	   <<the_sig_pos_err[i]<<std::setw(15)
	   <<the_sig_posWS[i]<<std::setw(15)
	   <<the_sig_posWS_err[i]
	   <<"\n";
  }
  outfile.close();
  outfile.open("./SavedFits/final_yields_in_bins_neg.txt");
  //outfile<<"\n\n";
  outfile<<"Bin"<<std::setw(15)<<" <t>"<<std::setw(15)<<"<t^2>"<<std::setw(15)<<"N_RS"<<std::setw(15)<<"error_N_RS"<<std::setw(15)<<"N_WS"<<std::setw(15)<<"error_N_WS\n";

  for(int i=0; i<nbins;++i){
    outfile<<i+1<<std::setw(15)
	   <<mean_t_neg[i]<<std::setw(15)
	   <<mean_t2_neg[i]<<std::setw(15)
	   <<the_sig_neg[i]<<std::setw(15)
	   <<the_sig_neg_err[i]<<std::setw(15)
	   <<the_sig_negWS[i]<<std::setw(15)
	   <<the_sig_negWS_err[i]
	   <<"\n";
  }
  outfile.close();
  //now do the same with the blinded file
  
  //print the file.
  
  std::cout<<"writing the files"<<endl;
  outfile.open("./SavedFits/final_blinded_yields_in_bins_pos.txt");
  outfile<<"Bin"<<std::setw(15)<<" <t>"<<std::setw(15)<<"<t^2>"<<std::setw(15)<<"N_RS"<<std::setw(15)<<"error_N_RS"<<std::setw(15)<<"N_WS"<<std::setw(15)<<"error_N_WS\n";
  for(int i=0; i<nbins;++i){
    outfile<<i+1<<std::setw(15)
	   <<mean_t_pos[i]<<std::setw(15)
	   <<mean_t2_pos[i]<<std::setw(15)
	   <<the_sig_pos[i]<<std::setw(15)
	   <<the_sig_pos_err[i]<<std::setw(15)
	   <<the_sig_posWSBlind[i]<<std::setw(15)
	   <<the_sig_posWSBlind_err[i]
	   <<"\n";
  }
  outfile.close();
  outfile.open("./SavedFits/final_blinded_yields_in_bins_neg.txt");
  //outfile<<"\n\n";
  outfile<<"Bin"<<std::setw(15)<<" <t>"<<std::setw(15)<<"<t^2>"<<std::setw(15)<<"N_RS"<<std::setw(15)<<"error_N_RS"<<std::setw(15)<<"N_WS"<<std::setw(15)<<"error_N_WS\n";

  for(int i=0; i<nbins;++i){
    outfile<<i+1<<std::setw(15)
	   <<mean_t_neg[i]<<std::setw(15)
	   <<mean_t2_neg[i]<<std::setw(15)
	   <<the_sig_neg[i]<<std::setw(15)
	   <<the_sig_neg_err[i]<<std::setw(15)
	   <<the_sig_negWSBlind[i]<<std::setw(15)
	   <<the_sig_negWSBlind_err[i]
	   <<"\n";
  }
  outfile.close();

  //  //change the permissions to do all the shiz
  //system("chmod u=rw ./SavedFits/final_yields_in_bins_pos.txt");
  

  delete theFitspos;
  delete theFitsneg;
  delete theFitsposWS;
  delete theFitsnegWS;
  return 0;

}
