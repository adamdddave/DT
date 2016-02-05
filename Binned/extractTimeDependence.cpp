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

//get the second moment of the binned time histogram
double secondMoment(TH1* hist, int lowBin, int highBin){
  double ret = 0;
  for(int i=lowBin; i<=highBin;++i){
    //sum_i PDF_i *t^2_i = sum_i BinContent_i *t^2 / integral(over bins in i)
    ret+= hist->GetBinContent(i)*hist->GetBinCenter(i)*hist->GetBinCenter(i);
  }
  ret/=hist->Integral(lowBin,highBin);
  cout<<"using second moment "<<ret<<endl;
  return ret;
}

double mymean(TH1* hist, int lowBin, int highBin){
  double ret = 0;
  for(int i=lowBin; i<=highBin;++i){
    //sum_i PDF_i *t^2_i = sum_i BinContent_i *t^2 / integral(over bins in i)
    ret+= hist->GetBinContent(i)*hist->GetBinCenter(i);
  }
  ret/=hist->Integral(lowBin,highBin);
  cout<<"using second moment "<<ret<<endl;
  return ret;
}
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
  
  setLHCbcanvas();
  bool blind=true;
  // New 1-23-16. Use the blinding on the dataset instead of the fitter. Read Augusto's seed here.
  int _BlindingSeed;
  system("chmod u+r /home/davis3a4/private/analysis/SEEDFORBLINDING.txt");
  std::ifstream file("/home/davis3a4/private/analysis/SEEDFORBLINDING.txt");
  while ( file>>_BlindingSeed ){std::cout<<"reading Eduardo's seed"<<std::endl;}
  system("chmod u-r /home/davis3a4/private/analysis/SEEDFORBLINDING.txt");
  TRandom3 donram(_BlindingSeed);
  /*  double xp2_plus_blind = donram.Gaus(0.,0.00038);
  double xp2_mins_blind = donram.Gaus(0.,0.00038);
  double yp_plus_blind = donram.Gaus(0.,0.0015);
  double yp_mins_blind = donram.Gaus(0.,0.0015);
  double rd_plus_blind = donram.Gaus(0.,0.0005);
  double rd_mins_blind = donram.Gaus(0.,0.0005);*/
  //blinding went unphysical. Fall back to what we had before.
  double xp2_plus_blind = donram.Gaus(0.,0.00008);
  double xp2_mins_blind = donram.Gaus(0.,0.00008);
  double yp_plus_blind = donram.Gaus(0.,0.00015);
  double yp_mins_blind = donram.Gaus(0.,0.00015);
  double rd_plus_blind = donram.Gaus(0.,0.00035);
  double rd_mins_blind = donram.Gaus(0.,0.00035);
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
    cout<<"[4] option to use SS time dep scaling"<<endl;
    cout<<"********************************************"<<endl;
    return 0;
  }
  cout<<"using rs file"<<argv[1]<<endl;
  cout<<"using fit model "<<argv[2]<<endl;
  cout<<"using ws file "<<argv[3]<<endl;
  TFile *f1 =TFile::Open(argv[1]);
  TFile *f2 = TFile::Open(argv[2]);
  TFile *f3 = TFile::Open(argv[3]);
  bool useTimeDepSS = atoi(argv[4]);
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
  rs_time_histo_pos->Add(rs_ss_time_histo_pos,-the_scaling_factor);

  rs_time_histo_neg->Sumw2();
  rs_ss_time_histo_neg->Sumw2();
  rs_time_histo_neg->Add(rs_ss_time_histo_neg,-the_scaling_factor);
  std::vector<double> mean_t_pos, mean_t2_pos, mean_t_neg,mean_t2_neg;
  //the time squared calculation is not what we want. We want the second moment of t.
  int bins_td []= {451,521,551,591,651,rs_time_histo_pos->GetNbinsX()};//bin boundaries
  for(int i=0;i<5;++i){
    rs_time_histo_pos->GetXaxis()->SetRange(bins_td[i],bins_td[i+1]-1);//no overlap!!
    mean_t_pos.push_back( rs_time_histo_pos->GetMean());
    cout<<"using mean "<<rs_time_histo_pos->GetMean()<<endl;
    cout<<"checking with my mean "<<mymean(rs_time_histo_pos,bins_td[i],bins_td[i+1]-1)<<endl;
    mean_t2_pos.push_back(secondMoment(rs_time_histo_pos,bins_td[i],bins_td[i+1]-1));
    rs_time_histo_pos->GetXaxis()->SetRange();

			 
    rs_time_histo_neg->GetXaxis()->SetRange(bins_td[i],bins_td[i+1]-1);//no overlap!!
    mean_t_neg.push_back( rs_time_histo_neg->GetMean());
    cout<<"using mean "<<rs_time_histo_neg->GetMean()<<endl;
    cout<<"checking with my mean "<<mymean(rs_time_histo_neg,bins_td[i],bins_td[i+1]-1)<<endl;
    mean_t2_neg.push_back(secondMoment(rs_time_histo_neg,bins_td[i],bins_td[i+1]-1));
    rs_time_histo_neg->GetXaxis()->SetRange();

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
    double sf = useTimeDepSS? the_scaling_factor_timeDep[i]:the_scaling_factor;
    if(sf == the_scaling_factor_timeDep[i]){cout<<"using time dependent SS"<<endl;}
    pos_bins[i]->Add((TH1D*)f1->Get(Form("RS_ss_dst_mass_td0_pos_bin%d",i+1)),-sf);
    neg_bins[i]->Add((TH1D*)f1->Get(Form("RS_ss_dst_mass_td0_neg_bin%d",i+1)),-sf);
    //WS
    pos_binsWS[i]->Add((TH1D*)f3->Get(Form("WS_ss_dst_mass_td0_pos_bin%d",i+1)),-sf);
    neg_binsWS[i]->Add((TH1D*)f3->Get(Form("WS_ss_dst_mass_td0_neg_bin%d",i+1)),-sf);
  }//commented out to try raw asymmetry
  massFit* theFitspos[nbins];
  massFit* theFitsneg[nbins];

  massFit* theFitsposWS[nbins];
  massFit* theFitsnegWS[nbins];
  
  double the_sig_pos[nbins],the_sig_pos_err[nbins];
  double the_sig_neg[nbins],the_sig_neg_err[nbins];

  double the_sig_posWS[nbins],the_sig_posWS_err[nbins];
  double the_sig_negWS[nbins],the_sig_negWS_err[nbins];

  double the_sig_posWSBlind[nbins],the_sig_posWSBlind_err[nbins];
  double the_sig_negWSBlind[nbins],the_sig_negWSBlind_err[nbins];

  for(int i=0;i<nbins;++i){
    theFitspos[i] = new massFit(Form("RS_dst_mass_pos_bin%d",i+1),"j3g",w,"FinalExtraction");
    theFitspos[i]->setData(pos_bins[i]);
    theFitspos[i]->initValsByHand(thePars);
    theFitspos[i]->fit();
    theFitspos[i]->savePlots(true,Form("RS_dst_mass_pos_bin%d",i+1));
    the_sig_pos[i]=theFitspos[i]->getNsig()*2;//prescale
    the_sig_pos_err[i]=theFitspos[i]->getNsigErr()*2;//prescale
    theFitspos[i]->Reset();
  }

  
  for(int i=0;i<nbins;++i){
    theFitsneg[i] = new massFit(Form("RS_dst_mass_neg_bin%d",i+1),"j3g",w,"FinalExtraction");
    theFitsneg[i]->setData(neg_bins[i]);
    theFitsneg[i]->initValsByHand(thePars);
    theFitsneg[i]->fit();
    theFitsneg[i]->savePlots(true,Form("RS_dst_mass_neg_bin%d",i+1));
    the_sig_neg[i]=theFitsneg[i]->getNsig()*2;//prescale
    the_sig_neg_err[i]=theFitsneg[i]->getNsigErr()*2;//prescale

    theFitsneg[i]->Reset();
  }

  //WS
  //redirect the output so we can't see it.
  int stdout_fd = dup(STDOUT_FILENO);
  if(blind){//start blinding
    freopen("blind_the_stuff.out", "w", stdout);
  }

  
  for(int i=0;i<nbins;++i){
    theFitsposWS[i] = new massFit(Form("WS_dst_mass_pos_bin%d",i+1),"j3g",w,"FinalExtraction");
    theFitsposWS[i]->setData(pos_binsWS[i]);
    theFitsposWS[i]->initValsByHand(thePars);
    theFitsposWS[i]->fit();
    theFitsposWS[i]->savePlots(true,Form("WS_dst_mass_pos_bin%d",i+1),true);
    the_sig_posWS[i]=theFitsposWS[i]->getNsig();
    the_sig_posWS_err[i]=theFitsposWS[i]->getNsigErr();
    theFitsposWS[i]->Reset();
  }

  
  for(int i=0;i<nbins;++i){
    theFitsnegWS[i] = new massFit(Form("WS_dst_mass_neg_bin%d",i+1),"j3g",w,"FinalExtraction");
    theFitsnegWS[i]->setData(neg_binsWS[i]);
    theFitsnegWS[i]->initValsByHand(thePars);
    theFitsnegWS[i]->fit();
    theFitsnegWS[i]->savePlots(true,Form("WS_dst_mass_neg_bin%d",i+1),true);
    the_sig_negWS[i]=theFitsnegWS[i]->getNsig();
    the_sig_negWS_err[i]=theFitsnegWS[i]->getNsigErr();

    theFitsnegWS[i]->Reset();
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
  outfile<<"Bin"<<std::setw(15)<<"<t>"<<std::setw(15)<<"<t^2>"<<std::setw(15)<<"N_RS"<<std::setw(15)<<"error_N_RS"<<std::setw(15)<<"N_WS"<<std::setw(15)<<"error_N_WS\n";

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
  system("chmod -rx ./SavedFits/final_yields_in_bins_*.txt");
  

  // delete theFitspos;
  // delete theFitsneg;
  // delete theFitsposWS;
  // delete theFitsnegWS;
  return 0;

}
