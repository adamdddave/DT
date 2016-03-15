//c++
#include <iostream>
#include <sys/stat.h>//mkdir
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
  cout<<"Extracting file for RS time dependent stuff"<<endl;
  if(argc<3){
    cout<<"********************************************"<<endl;
    cout<<"Extracts the file. needs inputs"<<endl;
    cout<<"[1] The rs file"<<endl;
    cout<<"[2] the fit model"<<endl;
    cout<<"[3] Optional: boolean of whether to use time dep SS subtraction"<<endl;
    cout<<"[4] Optional: boolean of whether to produce RS templates"<<endl;
    cout<<"       as a function of decay time of the D0"<<endl;
    cout<<"********************************************"<<endl;
    return 0;
  }
  cout<<"using rs file"<<argv[1]<<endl;
  cout<<"using fit model "<<argv[2]<<endl;
  TFile *f1 =TFile::Open(argv[1]);
  TFile *f2 = TFile::Open(argv[2]);
  bool useTimeDepSS = false;
  if(argc>=4){ useTimeDepSS = atoi(argv[3]);
    cout<<"Using Time dependent subtraction!"<<endl;}
  bool genNewModels = false;
  if(argc==5){ genNewModels = atoi(argv[4]);
    cout<<"generating fit models for each bin seperately"<<endl;}
  cout<<"genNewModels = "<<genNewModels<<endl;
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
  //first thing, get the scaling factor from the file  
  double the_scaling_factor;//for scaling SS to OS
  std::ifstream sf_file("./theScalingFactor.txt");
  while(sf_file>>the_scaling_factor){cout<<"reading scaling factor from file"<<endl;}
  cout<<"read scaling factor "<<the_scaling_factor<<endl;
  if(!the_scaling_factor){cout<<"something terribly wrong here"<<endl;return 0;}
  
  sf_file.close();
  //add some code to possibly change this to be time dependent as well.
  //DONE
  double the_scaling_factor_timeDep[5];
  std::ifstream sftd_file("./theScalingFactorTimeDependence.txt");
  int dum;
  double dumerr;
  if (sftd_file.is_open()){
    for(int i=0; i<5;++i){
      sftd_file>>dum>>the_scaling_factor_timeDep[i]>>dumerr;
      cout<<"read in "<<the_scaling_factor_timeDep[i]<<endl;
    }
  }
  std::vector<TH1D*>pos_bins,neg_bins;
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
  }

  for(int i=0; i<nbins;++i){
    double sf = useTimeDepSS? the_scaling_factor_timeDep[i]:the_scaling_factor;
    cout<<"using scaling factor sf = "<<sf<<endl;
    if(sf == the_scaling_factor_timeDep[i]){cout<<"using time dependent SS"<<endl;}
    pos_bins[i]->Add((TH1D*)f1->Get(Form("RS_ss_dst_mass_td0_pos_bin%d",i+1)),-sf);
    neg_bins[i]->Add((TH1D*)f1->Get(Form("RS_ss_dst_mass_td0_neg_bin%d",i+1)),-sf);
  }//commented out to try raw asymmetry
  double the_sig_pos[nbins],the_sig_pos_err[nbins];
  double the_sig_neg[nbins],the_sig_neg_err[nbins];

  for(int i=0;i<nbins;++i){
    massFit* theFitspos = new massFit(Form("RS_dst_mass_pos_bin%d",i+1),"j3g",w,Form("RS_Extraction_bin%dpos",i));
    //make sure the directory exists if making new models
    theFitspos->setData(pos_bins[i]);
    cout<<"we are now in bin "<<i<<endl;
    cout<<"the data has been set to "<<pos_bins[i]->GetName()<<endl;
    bool cont = true;
    //cout<<"continue??"<<endl;
    //cin>>cont;
    
    theFitspos->initValsByHand(thePars);
    if(genNewModels){theFitspos->FloatMeanWidth();}
    //theFitspos->FloatMeanWidth();
    theFitspos->fit();
    theFitspos->savePlots(true,Form("RS_dst_mass_pos_bin%d",i+1));
    if(genNewModels){theFitspos->saveUpdatedFinalFit();}
    the_sig_pos[i]=theFitspos->getNsig()*2;//prescale
    the_sig_pos_err[i]=theFitspos->getNsigErr()*2;//prescale
    theFitspos->Reset();
  }

  
  for(int i=0;i<nbins;++i){
    massFit* theFitsneg = new massFit(Form("RS_dst_mass_neg_bin%d",i+1),"j3g",w,Form("RS_Extraction_bin%dneg",i));
    theFitsneg->setData(neg_bins[i]);
    theFitsneg->initValsByHand(thePars);
    if(genNewModels){theFitsneg->FloatMeanWidth();}
    theFitsneg->fit();
    theFitsneg->savePlots(true,Form("RS_dst_mass_neg_bin%d",i+1));
    if(genNewModels){theFitsneg->saveUpdatedFinalFit();}
    the_sig_neg[i]=theFitsneg->getNsig()*2;//prescale
    the_sig_neg_err[i]=theFitsneg->getNsigErr()*2;//prescale

    theFitsneg->Reset();
  }
  //print the file.
  std::ofstream outfile;
  outfile.open("./SavedFits/rs_yields_in_bins_pos.txt");
  outfile<<"Bin \t N RS+ \t error(N RS+) \n";
  for(int i=0; i<nbins;++i){
    outfile<<i+1<<"\t"<<the_sig_pos[i]<<"\t"<<the_sig_pos_err[i]<<"\n";
  }
  outfile.close();
  outfile.open("./SavedFits/rs_yields_in_bins_neg.txt");
  //outfile<<"\n\n";
  outfile<<"Bin \t N RS- \t error(N RS-) \n";
  for(int i=0; i<nbins;++i){
    outfile<<i+1<<"\t"<<the_sig_neg[i]<<"\t"<<the_sig_neg_err[i]<<"\n";
  }
  outfile.close();

  return 0;

}
