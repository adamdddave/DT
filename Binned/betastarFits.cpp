//external
#include "betastar_plot.h"
//c++
#include <iostream>
#include <cmath>
#include <fstream>
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
#include <TF1.h>
#include <TPaveStats.h>
#include <TBox.h>
#include <TFitResult.h>
#include <TVectorD.h>
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
//#include "PlottingTools.h"
using namespace std;
 // Include files
//supporting method
double err_div(double a, double sa, double b, double sb);//assuming 100% correlation
double err_mult(double a, double sa, double b, double sb);
std::vector<double> PeakingBkgFromSidebands(std::vector<TH1*>lo_hists,std::vector<TH1*>hi_hists,RooWorkspace* w_tmp, TString nameForFit, betastar_plot *b,array<double,4>initPars);

int main(int argc, char* const argv[]){
  cout<<"Testing Mass Fit on External Data"<<endl;
  bool hasWorkspace=  false;
  if(argc<4){
    cout<<"*************************************"<<endl;
    cout<<"Expecting"<<endl;
    cout<<" [1] Signal File"<<endl;
    cout<<" [2] Background File"<<endl;
    cout<<" [3] the workspace with the fit model"<<endl;
    cout<<"Note that the functionality has changed!"<<endl;
    cout<<"*************************************"<<endl;
    return 0;
  }
  if(argc==4){
    cout<<"argv[1]="<<argv[1]<<", argv[2] = "<<argv[2]<<", argv[3] = "<<argv[3]<<endl;
    hasWorkspace = true;
  }
  if(!hasWorkspace){
    cout<<"need a workspace for the fits"<<endl;
    return 0;
  }
  bool isWS = false;
  TString fitName = argv[1];
  TString nameForFit = "rs";
  //make it lower case just to make our lives easier
  fitName.ToLower();
  if(fitName.Contains("ws")){
    isWS = true;
    cout<<"using WS sample"<<endl;
    
    nameForFit = "ws";
    cout<<"nameForFit = "<<nameForFit<<endl; 
  }
  if(isWS){ cout<<"make the compiler shut up"<<endl;}
  //fitName.ToUpper();
  TFile *f1 = TFile::Open(argv[1]);
  //f1->ls();
  TFile *f2 = TFile::Open(argv[2]);
  //f2->ls();
  TFile *f3 = TFile::Open(argv[3]);
  TString channelFromFile = argv[3];
  channelFromFile.ReplaceAll("SavedFits","");
  channelFromFile.ReplaceAll("fitModel.root","");
  channelFromFile.ReplaceAll("/","");
  channelFromFile.ReplaceAll("j3g","");
  channelFromFile.ReplaceAll("_","");
  channelFromFile+="w";
  cout<<"channel from file = "<<channelFromFile<<endl;
  nameForFit.ToUpper();
  
  betastar_plot b(f1,f2,nameForFit);
    
  //cout<<"check after tertiary constructor, name for low bin 1 time bin 1 = "<<b.hmkpisb_cut_range_lo_1_time_bin1->GetName()<<endl;
  RooWorkspace * w = (RooWorkspace*)f3->Get(channelFromFile);
  b.set_local_workspace(w);
  
  b.DrawPlots();
  //if(isWS){
  cout<<"*************************"<<endl;
  cout<<"starting time integrated peaking backgrounds"<<endl;
  cout<<"*************************"<<endl;
  b.FitWSDoubleMisID();
  b.FitWSDoubleMisIDLiang();
  cout<<"*************************"<<endl;
  cout<<"stopping time integrated peaking backgrounds"<<endl;
  cout<<"*************************"<<endl;
  b.FitWSDoubleMisIDTimeDependence();

  //double check this by fitting the things.
  //shift to an independent class.
  //at the end of the day, all we want out is the number of signal in the signal region and error
  
  std::vector<TH1*>lo_hists;
  std::vector<TH1*>hi_hists;
  //
  std::vector<TH1*>lo_hists_pos;
  std::vector<TH1*>hi_hists_pos;
  //
  std::vector<TH1*>lo_hists_neg;
  std::vector<TH1*>hi_hists_neg;

  //mean vals extracted from histogram.
  
  //double sigYield[6];
  //double sigYieldErr[6];
  lo_hists.push_back(b.hmkpisb_cut_range_lo_1);
  lo_hists.push_back(b.hmkpisb_cut_range_lo_2);
  lo_hists.push_back(b.hmkpisb_cut_range_lo_3);
  lo_hists.push_back(b.hmkpisb_cut_range_lo_4);
  lo_hists.push_back(b.hmkpisb_cut_range_lo_5);
  lo_hists.push_back(b.hmkpisb_cut_range_lo_6);

  hi_hists.push_back(b.hmkpisb_cut_range_hi_1);
  hi_hists.push_back(b.hmkpisb_cut_range_hi_2);
  hi_hists.push_back(b.hmkpisb_cut_range_hi_3);
  hi_hists.push_back(b.hmkpisb_cut_range_hi_4);
  hi_hists.push_back(b.hmkpisb_cut_range_hi_5);
  hi_hists.push_back(b.hmkpisb_cut_range_hi_6);
  //
  lo_hists_pos.push_back(b.hmkpisb_pos_cut_range_lo_1);
  lo_hists_pos.push_back(b.hmkpisb_pos_cut_range_lo_2);
  lo_hists_pos.push_back(b.hmkpisb_pos_cut_range_lo_3);
  lo_hists_pos.push_back(b.hmkpisb_pos_cut_range_lo_4);
  lo_hists_pos.push_back(b.hmkpisb_pos_cut_range_lo_5);
  lo_hists_pos.push_back(b.hmkpisb_pos_cut_range_lo_6);

  hi_hists_pos.push_back(b.hmkpisb_pos_cut_range_hi_1);
  hi_hists_pos.push_back(b.hmkpisb_pos_cut_range_hi_2);
  hi_hists_pos.push_back(b.hmkpisb_pos_cut_range_hi_3);
  hi_hists_pos.push_back(b.hmkpisb_pos_cut_range_hi_4);
  hi_hists_pos.push_back(b.hmkpisb_pos_cut_range_hi_5);
  hi_hists_pos.push_back(b.hmkpisb_pos_cut_range_hi_6);
  //
  
  lo_hists_neg.push_back(b.hmkpisb_neg_cut_range_lo_1);
  lo_hists_neg.push_back(b.hmkpisb_neg_cut_range_lo_2);
  lo_hists_neg.push_back(b.hmkpisb_neg_cut_range_lo_3);
  lo_hists_neg.push_back(b.hmkpisb_neg_cut_range_lo_4);
  lo_hists_neg.push_back(b.hmkpisb_neg_cut_range_lo_5);
  lo_hists_neg.push_back(b.hmkpisb_neg_cut_range_lo_6);

  hi_hists_neg.push_back(b.hmkpisb_neg_cut_range_hi_1);
  hi_hists_neg.push_back(b.hmkpisb_neg_cut_range_hi_2);
  hi_hists_neg.push_back(b.hmkpisb_neg_cut_range_hi_3);
  hi_hists_neg.push_back(b.hmkpisb_neg_cut_range_hi_4);
  hi_hists_neg.push_back(b.hmkpisb_neg_cut_range_hi_5);
  hi_hists_neg.push_back(b.hmkpisb_neg_cut_range_hi_6);

  //now the fits
  
  //try rebinning the histograms
  for(auto hist: lo_hists){hist->Rebin();}
  for(auto hist: hi_hists){hist->Rebin();}
  //
  for(auto hist: lo_hists_pos){hist->Rebin();}
  for(auto hist: hi_hists_pos){hist->Rebin();}
  //
  for(auto hist: lo_hists_neg){hist->Rebin();}
  for(auto hist: hi_hists_neg){hist->Rebin();}
  
  //try making a massFit with a single gaussian+bkg to the combined sample.
  TH1D* tot_histo = (TH1D*)lo_hists[0]->Clone("tot_pkg_bkg");
  for(int i=1; i<6;++i){
    tot_histo->Add(lo_hists[i]);
  }
  for(auto hist : hi_hists){
    tot_histo->Add(hist);
  }

  
  massFit tot_bkg_fit(nameForFit,"1g",0,"betastar");
  tot_bkg_fit.initModelValues();
  tot_bkg_fit.setData(tot_histo);
  tot_bkg_fit.fit();
  tot_bkg_fit.savePlots(false,"_bkg_model");
  tot_bkg_fit.saveFinalFit();

  //now that we have a fit model that works, go find it.
  TFile* f_tmp = TFile::Open("./SavedFits/betastar/"+nameForFit+"_1gfitModel.root");
  //f_tmp->ls();
  RooWorkspace *w_tmp = (RooWorkspace*)f_tmp->Get(nameForFit+"w");
  array<double,4> thePars{
    (w_tmp->var("kappa")->getVal()),
      (w_tmp->var("n")->getVal()),
      (w_tmp->var("nbkg")->getVal()),
      (w_tmp->var("nsig")->getVal())};
  cout<<"**************************************"<<endl;
  cout<<"fitting total sample"<<endl;
  cout<<"**************************************"<<endl;
  std::vector<double> tot_result_of_sb_fit = PeakingBkgFromSidebands(lo_hists,hi_hists,w_tmp,nameForFit,&b,thePars);
  //positive
  cout<<"++++++++++++++++++++++++++++++++++++++++"<<endl;
  cout<<"fitting positive sample"<<endl;
  cout<<"++++++++++++++++++++++++++++++++++++++++"<<endl;
  std::vector<double> tot_result_of_sb_fit_pos = PeakingBkgFromSidebands(lo_hists_pos,hi_hists_pos,w_tmp,nameForFit+"_pos",&b,thePars);
  //negative
  cout<<"----------------------------------------"<<endl;
  cout<<"fitting negative sample"<<endl;
  cout<<"----------------------------------------"<<endl;
  std::vector<double> tot_result_of_sb_fit_neg = PeakingBkgFromSidebands(lo_hists_neg,hi_hists_neg,w_tmp,nameForFit+"_neg",&b,thePars);
  cout<<"*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-"<<endl;
  cout<<"processing results"<<endl;
  cout<<"*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-*+-"<<endl;
  //now do time dependence.
  //as from mike.The idea is that the original code which just split everything into bins of decay time is going to be hopeless
  //since there will not be enough statistics. What we can do, however, is take the time integrated Peaking Bkg / RS as a scaling
  //factor and then multiply RS yield in each bin by this scaling factor to extract the expected result. This is dependent
  //on the assumption that the RS/RS ratio is time independent (which it kind of is)
  
  //get the time bins yields from a file.
  cout<<"Now getting from file the RS + and - contributions"<<endl;
  //do both of them
  TString theFilePos= "SavedFits/rs_yields_in_bins_pos.txt";
  TString theFileNeg= "SavedFits/rs_yields_in_bins_neg.txt";

  ifstream rsFilePos(theFilePos.Data());
  string line;
  std::vector<double> RS_vals_pos,RS_errs_pos;
  std::vector<double> RS_vals_neg,RS_errs_neg;
  cout<<"positive"<<endl;
  if (rsFilePos.is_open()){
    getline(rsFilePos,line);//the header
    int bin;
    double val,err;
    while (rsFilePos>>bin>>val>>err){
      cout<<"bin = "<<bin<<"val = "<<val<<" err = "<<err<<endl;
      RS_vals_pos.push_back(val);
      RS_errs_pos.push_back(err);
    }
    rsFilePos.close();
  }
  cout<<"negative"<<endl;
  ifstream rsFileNeg(theFileNeg.Data());
  if (rsFileNeg.is_open()){
    getline(rsFileNeg,line);//the header
    int bin;
    double val,err;
    while (rsFileNeg>>bin>>val>>err){
      cout<<"bin = "<<bin<<"val = "<<val<<" err = "<<err<<endl;
      RS_vals_neg.push_back(val);
      RS_errs_neg.push_back(err);
    }
    rsFileNeg.close();
  }

  //divide the peaking background number by the total number of RS in the positive or negative sample.
  double tot_RS_sig =0;
  double tot_RS_sig_pos =0;
  double tot_RS_sig_neg =0;
  for(auto val:RS_vals_pos){
    tot_RS_sig+=val;
    tot_RS_sig_pos+=val;
  }
  for(auto val:RS_vals_neg){
    tot_RS_sig+=val;
    tot_RS_sig_neg +=val;
  }
  double tot_rs_err = 0;
  double tot_rs_err_pos = 0;
  double tot_rs_err_neg = 0;
  for(auto val: RS_errs_pos){
    tot_rs_err+=TMath::Power(val,2);
    tot_rs_err_pos+=TMath::Power(val,2);
  }
  for(auto val: RS_errs_neg){
    tot_rs_err+=TMath::Power(val,2);
    tot_rs_err_neg+=TMath::Power(val,2);
  }
  tot_rs_err = TMath::Sqrt(tot_rs_err);
  tot_rs_err_pos = TMath::Sqrt(tot_rs_err_pos);
  tot_rs_err_neg = TMath::Sqrt(tot_rs_err_neg);
  //now we have the total yields. Make the previous result a fraction
  std::vector<double>peaking_frac(tot_result_of_sb_fit);
  std::vector<double>peaking_frac_pos(tot_result_of_sb_fit_pos);
  std::vector<double>peaking_frac_neg(tot_result_of_sb_fit_neg);
  peaking_frac[0]/=tot_RS_sig;
  peaking_frac[2]/=tot_RS_sig;

  peaking_frac_pos[0]/=tot_RS_sig_pos;
  peaking_frac_pos[2]/=tot_RS_sig_pos;

  peaking_frac_neg[0]/=tot_RS_sig_neg;
  peaking_frac_neg[2]/=tot_RS_sig_neg;
  
  //now write the new file with the points.

  peaking_frac[1] = err_div(tot_result_of_sb_fit[0],tot_result_of_sb_fit[1],tot_RS_sig,tot_rs_err);
  cout<<"checking peaking fraction error:"<<endl;
  cout<<"a = "<<tot_result_of_sb_fit[0]<<" +/- "<<tot_result_of_sb_fit[1]<<", b = "<<tot_RS_sig<<" +/- "<<tot_rs_err<<endl;
  cout<<"peaking background error associated to this is "<<peaking_frac[1]<<endl;

  peaking_frac[3] = err_div(tot_result_of_sb_fit[2],tot_result_of_sb_fit[3],tot_RS_sig,tot_rs_err);
  //pos
  peaking_frac_pos[1] = err_div(tot_result_of_sb_fit_pos[0],tot_result_of_sb_fit_pos[1],tot_RS_sig_pos,tot_rs_err_pos);
  peaking_frac_pos[3] = err_div(tot_result_of_sb_fit_pos[2],tot_result_of_sb_fit_pos[3],tot_RS_sig_pos,tot_rs_err_pos);
  //neg
  peaking_frac_neg[1] = err_div(tot_result_of_sb_fit_neg[0],tot_result_of_sb_fit_neg[1],tot_RS_sig_neg,tot_rs_err_neg);
  peaking_frac_neg[3] = err_div(tot_result_of_sb_fit_neg[2],tot_result_of_sb_fit_neg[3],tot_RS_sig_neg,tot_rs_err_neg);
  
  cout<<"Checking the peaking background fraction:"<<endl;
  cout<<" integrated linear = "<<peaking_frac[0]<<" +/- "<<peaking_frac[1]<<endl;
  cout<<" integrated parabolic = "<<peaking_frac[2]<<" +/- "<<peaking_frac[3]<<endl;
  //positive
  cout<<"split into positive:"<<endl;
  cout<<" integrated linear = "<<peaking_frac_pos[0]<<" +/- "<<peaking_frac_pos[1]<<endl;
  cout<<" integrated parabolic = "<<peaking_frac_pos[2]<<" +/- "<<peaking_frac_pos[3]<<endl;

  //negative
  cout<<"and negative:"<<endl;
  cout<<" integrated linear = "<<peaking_frac_neg[0]<<" +/- "<<peaking_frac_neg[1]<<endl;
  cout<<" integrated parabolic = "<<peaking_frac_neg[2]<<" +/- "<<peaking_frac_neg[3]<<endl;


  

  //now we have all the information, print out a prettly little table.
  std::vector<double> final_result_pos,final_result_pos_err;
  std::vector<double> final_result_neg,final_result_neg_err;
  cout<<"- - - - - - - - - - - - - - - - - - -  -"<<endl;
  cout<<"Linear fit"<<endl;
  cout<<"- - - - - - - - - - - - - - - - - - -  -"<<endl;
  cout<<"Time bin"<<setw(25)<<"+ PeakingBkg"<<setw(25)<<"error"<<setw(25)<<"- PeakingBkg"<<setw(25)<<"error"<<endl;
  for(int i=0; i<5;++i){
    double the_err_pos = err_mult(RS_vals_pos[i],RS_errs_pos[i], peaking_frac_pos[0],peaking_frac_pos[1]);
    double the_err_neg = err_mult(RS_vals_neg[i],RS_errs_neg[i], peaking_frac_neg[0],peaking_frac_neg[1]);
    cout<<i+1<<setw(25)<<RS_vals_pos[i]*peaking_frac_pos[0]<<setw(25)<<the_err_pos<<setw(25)<<RS_vals_neg[i]*peaking_frac_neg[0]<<setw(25)<<the_err_neg<<endl;
    final_result_pos.push_back(RS_vals_pos[i]*peaking_frac_pos[0]);
    final_result_pos_err.push_back(the_err_pos);
    final_result_neg.push_back(RS_vals_neg[i]*peaking_frac_neg[0]);
    final_result_neg_err.push_back(the_err_neg);
  }
  cout<<"- - - - - - - - - - - - - - - - - - -  -"<<endl;
  cout<<"Parabolic fit"<<endl;
  cout<<"- - - - - - - - - - - - - - - - - - -  -"<<endl;
  //  cout<<"Time bin"<<setw(25)<<"Positive Extracted PeakingBkg"<<setw(25)<<"error"<<setw(25)<<"Negative Extracted PeakingBkg"<<setw(25)<<"error"<<endl;
  cout<<"Time bin"<<setw(25)<<"+ PeakingBkg"<<setw(25)<<"error"<<setw(25)<<"- PeakingBkg"<<setw(25)<<"error"<<endl;
  for(int i=0; i<5;++i){
    double the_err_pos = err_mult(RS_vals_pos[i],RS_errs_pos[i], peaking_frac_pos[2],peaking_frac_pos[3]);
    double the_err_neg = err_mult(RS_vals_neg[i],RS_errs_neg[i], peaking_frac_neg[2],peaking_frac_neg[3]);

    cout<<i+1<<setw(25)<<RS_vals_pos[i]*peaking_frac_pos[2]<<setw(25)<<the_err_pos<<setw(25)<<RS_vals_neg[i]*peaking_frac_neg[2]<<setw(25)<<the_err_neg<<endl;
  }

  f_tmp->Close();
  
  std::ofstream outfile;
  outfile.open("SavedFits/betastar/double_misid_vs_rs_yield.txt");
  outfile<<"Bin \t N(DMID)+ \t error(N(DMID)+)\n";
  for(int i=0; i<5;++i){
    outfile<<i+1<<"\t"<<final_result_pos[i]<<"\t"<<final_result_pos_err[i]<<"\n";
  }
  outfile<<"Bin \t N(DMID)- \t error(N(DMID)-)\n";
  for(int i=0; i<5;++i){
    outfile<<i+1<<"\t"<<final_result_neg[i]<<"\t"<<final_result_neg_err[i]<<"\n";
  }
  outfile.close();
  return 0;
}


std::vector<double> PeakingBkgFromSidebands(std::vector<TH1*>lo_hists, std::vector<TH1*>hi_hists, RooWorkspace* w_tmp, TString nameForFit,betastar_plot* b, array<double,4> initPars){
  double sig_vals[12];
  double sig_errs[12];
  double meansRS_lo[6]={1.792983e+03,1.798521e+03,1.804496e+03,1.810549e+03,1.816545e+03,1.822059e+03};
  double meansWS_lo[6]={1.792922e+03,1.798483e+03,1.804465e+03,1.810468e+03,1.816577e+03,1.821967e+03};

  double meansRS_hi[6]={1.907833e+03,1.913940e+03,1.919455e+03,1.925523e+03,1.931450e+03,1.937406e+03};
  double meansWS_hi[6]={1.907934e+03,1.913844e+03,1.919426e+03,1.925560e+03,1.931533e+03,1.937479e+03};

  double meansRS[12];
  double meansWS[12];
  for(int i=0;i<6;++i){
    meansRS[i]=meansRS_lo[i];
    meansRS[i+6]=meansRS_hi[i];
    meansWS[i]=meansWS_lo[i];
    meansWS[i+6]=meansWS_hi[i];
  }
  double D0_bin_edges_lo[7]={1790.,1795.8,1801.6,1807.4,1813.2,1819.,1824.84};
  double D0_bin_edges_hi[7]={1904.84,1911.,1916.8,1922.6,1928.4,1934.2,1940.};
  double x_errs_lo_down_RS[6];
  double x_errs_lo_up_RS[6];
  double x_errs_hi_down_RS[6];
  double x_errs_hi_up_RS[6];

  double x_errs_lo_down_WS[6];
  double x_errs_lo_up_WS[6];
  double x_errs_hi_down_WS[6];
  double x_errs_hi_up_WS[6];

  double x_errs_RS_up[12];
  double x_errs_RS_down[12];
  double x_errs_WS_up[12];
  double x_errs_WS_down[12];


  for(int i=0; i<6;++i){
    x_errs_lo_down_RS[i]= meansRS_lo[i]-D0_bin_edges_lo[i];
    x_errs_lo_up_RS[i]=D0_bin_edges_lo[i+1]-meansRS_lo[i];

    x_errs_hi_down_RS[i]= meansRS_hi[i]-D0_bin_edges_hi[i];
    x_errs_hi_up_RS[i]=D0_bin_edges_hi[i+1]-meansRS_hi[i];

    x_errs_lo_down_WS[i]= meansWS_lo[i]-D0_bin_edges_lo[i];
    x_errs_lo_up_WS[i]=D0_bin_edges_lo[i+1]-meansWS_lo[i];

    x_errs_hi_down_WS[i]= meansWS_hi[i]-D0_bin_edges_hi[i];
    x_errs_hi_up_WS[i]=D0_bin_edges_hi[i+1]-meansWS_hi[i];
    //the big array.
    x_errs_RS_down[i]=x_errs_lo_down_RS[i];
    x_errs_RS_down[i+6]=x_errs_hi_down_RS[i];
    x_errs_WS_down[i]=x_errs_lo_down_WS[i];
    x_errs_WS_down[i+6]=x_errs_hi_down_WS[i];
    //up
    x_errs_RS_up[i]=x_errs_lo_up_RS[i];
    x_errs_RS_up[i+6]=x_errs_hi_up_RS[i];
    x_errs_WS_up[i]=x_errs_lo_up_WS[i];
    x_errs_WS_up[i+6]=x_errs_hi_up_WS[i];
  }
  
  for(int i=0; i<6;++i){
    lo_hists[i]->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / %.2f MeV",lo_hists[i]->GetBinWidth(1)));
    massFit fit_lo(nameForFit+Form("_pkg_bkg_lo_%d",i+1),"1g",w_tmp,"betastar");
    fit_lo.setData(lo_hists[i]);
    fit_lo.initValsByHand(initPars);//added to stop variation from initial fit
    fit_lo.fit();
    fit_lo.savePlots(false,"_sideband_fit_");
    sig_vals[i]=fit_lo.getNsig();
    sig_errs[i]=fit_lo.getNsigErr();
    
    fit_lo.Reset();
    //cc->Clear();
  }

  for(int i=0; i<6;++i){
    hi_hists[i]->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / %.2f MeV",hi_hists[i]->GetBinWidth(1)));
    massFit fit_hi(nameForFit+Form("_pkg_bkg_hi_%d",i+1),"1g",w_tmp,"betastar");
    fit_hi.setData(hi_hists[i]);
    fit_hi.initValsByHand(initPars);//added to stop variation from initial fit
    fit_hi.fit();
    fit_hi.savePlots(false,"_sideband_fit_");
    sig_vals[i+6]=fit_hi.getNsig();
    sig_errs[i+6]=fit_hi.getNsigErr();
    fit_hi.Reset();
    //    cc->Clear();
  }
  double sig_errs_up[12],sig_errs_down[12];
  for(int i=0;i<12;++i){
    sig_errs_up[i]=sig_errs[i];
    /*if(sig_vals[i]-sig_errs[i]<0){
      sig_errs_down[i]=sig_vals[i];
    }
    else{*/
    sig_errs_down[i]=sig_errs[i];
    //}
  }
  //f_tmp->Close();
  //double zeros[5]={0.,0.,0.,0.,0.};
  TCanvas* cnv = new TCanvas();
  cnv->Clear();

  //decide if it's WS or RS
  TGraphAsymmErrors* the_graph;
  cout<<"name for fit = "<<nameForFit<<endl;
  if(nameForFit.Contains("RS")){
    the_graph = new TGraphAsymmErrors(12,meansRS,sig_vals,x_errs_RS_down,x_errs_RS_up,sig_errs_down,sig_errs_up);
  }
  else if(nameForFit.Contains("WS")){
    the_graph = new TGraphAsymmErrors(12,meansWS,sig_vals,x_errs_WS_down,x_errs_WS_up,sig_errs_down,sig_errs_up);
  }
  the_graph->SetTitle(";m(K#pi)[MeV];N(Signal)");
  the_graph->SetMarkerStyle(20);
  the_graph->SetMarkerColor(kBlack);
  //the_graph->GetYaxis()->SetRangeUser(0.,the_graph->GetYaxis()->GetXmax());
  the_graph->Draw("ap");
  cnv->Modified();
  cnv->Update();
  cnv->SaveAs("./SavedFits/betastar/"+nameForFit+"peaking_bkg_sidebands_from_fit.pdf");
  cnv->SaveAs("./SavedFits/betastar/"+nameForFit+"peaking_bkg_sidebands_from_fit.root");

  TBox sigreg(1864.84-24,0,1864.84+24,the_graph->GetYaxis()->GetXmax());
  sigreg.SetFillColor(kGreen+2);
  sigreg.SetFillColorAlpha(kGreen+2,0.5);
  sigreg.Draw();
  //now fit this graph with a polynomial shape
  TF1* mf =  new TF1("mf","pol2(0)",the_graph->GetXaxis()->GetXmin(),the_graph->GetXaxis()->GetXmax());
  //change to a different fit model, to allow for fixing of shape parameters, but overall normalization change.
  //TF1* mf =  new TF1("mf","[0]*([1]+[2]*x + [3]*x*x)",the_graph->GetXaxis()->GetXmin(),the_graph->GetXaxis()->GetXmax());
  //mf->SetParameters(-8000.,8000.-0.001);
  //  mf->SetParameters(-370,3,-1e3);
  //  mf->SetRange(1790.,1940.);
  //mf->FixParameter(0,-3.69408e3);
  //  mf->FixParameter(1,3.95435);
  //  mf->FixParameter(2,-1.05638e-3);
  /*  mf->SetParLimits(0,-700,-100);
  mf->SetParLimits(1,-1,8);
  mf->SetParLimits(2,-10,10);*/
  
  //try fixing parameters
  
    /*
      ///result from fitting by hand
    Info in <CheckGraphFitOptions>: I (use function integral) is an invalid option when fitting a graph. It is ignored
     FCN=11.3637 FROM MIGRAD    STATUS=CONVERGED     153 CALLS         154 TOTAL
                         EDM=7.61426e-07    STRATEGY= 1      ERROR MATRIX ACCURATE
      EXT PARAMETER                                   STEP         FIRST
      NO.   NAME      VALUE            ERROR          SIZE      DERIVATIVE
       1  p0          -3.69408e+03   3.09568e+01   1.76148e-03   9.15204e-04
       2  p1           3.95435e+00   2.92829e-02   1.88558e-06   1.73546e+00
       3  p2          -1.05638e-03   8.31697e-06   5.03723e-10   3.29150e+03
    */
  TFitResultPtr r =the_graph->Fit("mf", "S");
  gStyle->SetOptFit(1111);
  //acnvess to the fit function
  //move the stats box
  TPaveStats* ps = (TPaveStats *)the_graph->GetListOfFunctions()->FindObject("stats");
  ps->SetX1NDC(0.15);
  ps->SetX2NDC(0.55);
  cnv->Modified();
  cnv->Update();
  cnv->SaveAs("./SavedFits/betastar/"+nameForFit+"peaking_bkg_sidebands_from_fit_fitted_polynomial.pdf");
  cnv->Clear();
  //now integrate the curve in the signal region
  double sb_integral = mf->Integral(D0_bin_edges_lo[0],D0_bin_edges_lo[6])+ mf->Integral(D0_bin_edges_hi[0],D0_bin_edges_hi[6]);
  double sig_reg_integral = mf->Integral(1864.84-24,1864.84,+24);
  double tot_sb_sig =0;
  double tot_sb_sig_err = 0;
  //find error in the integral
  
  TMatrixDSym mat = r->GetCorrelationMatrix();
  TF1* mf_tester =mf;//copy constructor
  Int_t npars = mf->GetNpar();
  double* pars = mf->GetParameters();
  const double* epars = mf->GetParErrors();
  double err_Rat = b->ErrorFromTF1(mf_tester,npars,pars,epars,mat,D0_bin_edges_lo[0],D0_bin_edges_lo[6],D0_bin_edges_hi[0],D0_bin_edges_hi[6],1864.84-24,1864.84+24);
  //fix everything by the y intercept
  //  mf->FixParameter(1);
  //mf->FixParameter(2,pars[2]);
  for(auto val : sig_vals){
    tot_sb_sig+=val;
  }
  for(auto val: sig_errs){
    tot_sb_sig_err+= val*val;
  }
  //Double_t errFrac = sig_reg_integral/sb_integral*(err_Num/sig_reg_integral-err_Den/sb_integral);
  Double_t errNsig_sigreg = (tot_sb_sig*sig_reg_integral/sb_integral)*TMath::Sqrt(tot_sb_sig_err/(tot_sb_sig*tot_sb_sig)+err_Rat*err_Rat/(sig_reg_integral*sig_reg_integral/(sb_integral*sb_integral)));

  //now do the same thing for a linear fit.
  TF1* mf_lin =  new TF1("mf_lin","pol1(0)",the_graph->GetXaxis()->GetXmin(),the_graph->GetXaxis()->GetXmax());
  the_graph->GetFunction("mf")->Delete();//remove the polynomial fit
  the_graph->Draw("ap");
  TFitResultPtr rl = the_graph->Fit("mf_lin","S");
  TPaveStats* psl = (TPaveStats*)the_graph->GetListOfFunctions()->FindObject("stats");
  psl->SetX1NDC(0.15);
  psl->SetX2NDC(0.55);
  cnv->Modified();
  cnv->Update();
  cnv->SaveAs("./SavedFits/betastar/"+nameForFit+"peaking_bkg_sidebands_from_fit_fitted_linear.pdf");
  cnv->Clear();
  double sb_integral_lin = mf_lin->Integral(D0_bin_edges_lo[0],D0_bin_edges_lo[6])+ mf_lin->Integral(D0_bin_edges_hi[0],D0_bin_edges_hi[6]);
  double sig_reg_integral_lin = mf_lin->Integral(1864.84-24,1864.84,+24);
  TMatrixDSym mat2 = rl->GetCorrelationMatrix();
  TF1* mf_lintest =mf_lin;//copy constructor
  Int_t npars2 = mf_lin->GetNpar();
  double* pars2 = mf_lin->GetParameters();
  const double* epars2 = mf_lin->GetParErrors();
  double err_Rat2 = b->ErrorFromTF1(mf_lintest,npars2,pars2,epars2,mat2,D0_bin_edges_lo[0],D0_bin_edges_lo[6],D0_bin_edges_hi[0],D0_bin_edges_hi[6],1864.84-24,1864.84+24);
  Double_t errNsig_sigreg2 = (tot_sb_sig*sig_reg_integral_lin/sb_integral_lin)*TMath::Sqrt(tot_sb_sig_err/(tot_sb_sig*tot_sb_sig)+err_Rat2*err_Rat2/(sig_reg_integral_lin*sig_reg_integral_lin/(sb_integral_lin*sb_integral_lin)));


  cout<<"Number of events in sideband times ratio of signal to sideband = "<< tot_sb_sig * sig_reg_integral/sb_integral<<" +/- "
      <<errNsig_sigreg<<endl;
  cout<<"Same for linear fit = "<< tot_sb_sig * sig_reg_integral_lin/sb_integral_lin<<" +/- "
      <<errNsig_sigreg2<<endl;
  std::vector<double>ret;
  ret.push_back(tot_sb_sig*sig_reg_integral_lin/sb_integral_lin);//central linear value
  ret.push_back(errNsig_sigreg2);//error on linear
  ret.push_back(tot_sb_sig*sig_reg_integral/sb_integral);//parabolic central value
  ret.push_back(errNsig_sigreg);//error on parab.
  return ret;
}


double err_div(double a, double sa, double b, double sb){
  return a/b*sqrt((sa/a)*(sa/a) + (sb/b)*(sb/b)/* - 2* (sa*sb)/(a*b)*/);
}

double err_mult(double a, double sa, double b, double sb){
  return a*b*sqrt((sa/a)*(sa/a) + (sb/b)*(sb/b) /*+ 2 *(sa*sb)/(a*b)*/);
}
