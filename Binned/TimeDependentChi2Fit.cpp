//local
#include "TimeDependentChi2Fit.h"
//c++
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <assert.h>
#include <string>
//root
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TMath.h>
#include <TString.h>
#include <TFile.h>
#include <TLegend.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TGraphAsymmErrors.h>
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TMinuit.h>

//external
#include "PlottingTools.h"///for style, etc
using namespace std;

TimeDependentChi2Fit::TimeDependentChi2Fit(TString name){
  m_name = name;
  minuit = new TMinuit(1);
  astart = 1.05;
  amin = 1.0;
  amax = 1.1;
  astep = 0.001;
  minuit->DefineParameter(0,"a",astart,astep,amin,amax);
  ndf = /*5*/ 15-1;
  minuit->SetFCN(my_fcn);
}


void TimeDependentChi2Fit::fit(){
  minuit->Command("MIGRAD 10000 0.1");
  minuit->Command("HESSE 10000");
  
  cout<<"Chi2 = "<<chi2_val_glob<<endl;
  cout<<"Prob = "<<TMath::Prob(chi2_val_glob,ndf)<<endl;
}

void TimeDependentChi2Fit::SetData(TGraphAsymmErrors theGraph, TGraphAsymmErrors g2, TGraphAsymmErrors g3){

  for(int i=0; i<5;++i){//first file
    double dummy;
    theGraph.GetPoint(i,dummy,central_val[i]);
    error[i] = theGraph.GetErrorYlow(i);
    central_val_global[i]=central_val[i];
    error_global[i] = error[i];
    cout<<"point "<<i<<" getting central val"<<central_val[i]<<" and error "<<error[i]<<endl;
  }

  for(int i=0; i<5;++i){//second file
    double dummy;
    g2.GetPoint(i,dummy,central_val[i+5]);
    error[i+5] = g2.GetErrorYlow(i);
    central_val_global[i+5]=central_val[i+5];
    error_global[i+5] = error[i+5];
    cout<<"point "<<i<<" getting central val"<<central_val[i+5]<<" and error "<<error[i+5]<<endl;
  }

  for(int i=0; i<5;++i){//third file
    double dummy;
    g3.GetPoint(i,dummy,central_val[i+10]);
    error[i+10] = g3.GetErrorYlow(i);
    central_val_global[i+10]=central_val[i+10];
    error_global[i+10] = error[i+10];
    cout<<"point "<<i<<" getting central val"<<central_val[i+10]<<" and error "<<error[i+10]<<endl;
  }

}

int main(int argc, char* const argv[]){
  if(argc<4){
    cout<<"no datafile to process!!"<<endl;
    return 0;
  }
  cout<<"computing chi2 for a flat line from "<<argv[1]<<endl;
  TFile* f1 = TFile::Open(argv[1]);
  TFile* f2 = TFile::Open(argv[2]);
  TFile* f3 = TFile::Open(argv[3]);
  TGraphAsymmErrors* gr = (TGraphAsymmErrors*)f1->Get("rs_over_rs_ratio");
  TGraphAsymmErrors* gr2 = (TGraphAsymmErrors*)f2->Get("rs_over_rs_ratio");
  TGraphAsymmErrors* gr3 = (TGraphAsymmErrors*)f3->Get("rs_over_rs_ratio");
  TimeDependentChi2Fit fit("fit");
  fit.SetData(*gr,*gr2,*gr3);
  fit.fit();
  return 0;
}
