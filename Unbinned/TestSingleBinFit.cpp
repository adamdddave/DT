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
  cout<<"******************************"<<endl;
  cout<<"Test a single fit for a bin"<<endl;
  cout<<"******************************"<<endl;
  if(argc<5){
    cout<<"Please pass"<<endl;
    cout<<"[1] The total file to process"<<endl;
    cout<<"[2] the root file with the fit model"<<endl;
    cout<<"[3] the name of the histogram to get and fit"<<endl;
    cout<<"[4] the name of the corresponding ss histogram to subtract"<<endl;
    return 0;
  }

  cout<<"Now processing "<<argv[1]<<endl;
  TFile * f1 = TFile::Open(argv[1]);
  cout<<"Looking for file"<<argv[3]<<endl;
  TH1D* the_plot = (TH1D*)f1->Get(argv[3]);
  the_plot->Sumw2();
  if(!the_plot){
    cout<<"couldn't fine a plot corresponding to "<<argv[3]<<endl;
    return 0;
  }
  TH1D* the_plot_ss = (TH1D*)f1->Get(argv[4]);
  if(!the_plot_ss){
    cout<<"couldn't fine a plot corresponding to "<<argv[4]<<endl;
    return 0;
  }
  the_plot->Add(the_plot_ss,-1);
  //now do the fit.
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
  //assert0);
  massFit fit(channelFromFile+"_single_bin_fit_"+argv[3],"j3g", w);

    //fit.initModelValues();
  fit.setData(the_plot);
  fit.FloatMeanWidth();
  fit.fit();
  
  fit.savePlots(true,channelFromFile+"workspaceFit");
  cout<<"That's it!!"<<endl;


  return 0;
}
