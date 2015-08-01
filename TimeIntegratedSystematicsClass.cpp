//include files
#include "TimeIntegratedSystematicsClass.h"
//C++
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


//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include <RooFitResult.h>
#include "RooWorkspace.h"
//external
#include "PlottingTools.h"///for pull plots.
using namespace RooFit ;
using namespace std;

//----------
//Implementation for TimeIntegratedSystematicsClass
//
//2015-1-8 : Adam Davis
//-----------
TimeIntegratedSystematicsClass::TimeIntegratedSystematicsClass(TString name,TFile *fin,
							       RooWorkspace* w,
							       TString var2Test, TString var2subtr,
							       TString histoForBins,TString histoForBinsBkg,
							       int binRanges[6],
							       int nbins){
  mName = name;
  nBins = nbins;
  fin->ls();
  //Get the data to use from the file.
  if(!(var2Test.Contains("pidk"))){
    //first the distribution of the variable we're binning in
    cout<<"Getting Histogram "<<var2Test<<endl;
    varSigHist = (TH1D*)fin->Get(var2Test);//eg "RS_dstar_p"
    varSigHist->Sumw2();
    varBkgHist = (TH1D*)fin->Get(var2subtr);//eg "RS_ss_dstar_p"
    varBkgHist->Sumw2();   
  }
  else{
    TH2D* tmpSig = (TH2D*)fin->Get(var2Test);
    varSigHist =(TH1D*)tmpSig->ProjectionX();
    varSigHist->Sumw2();
    TH2D* tmpBkg = (TH2D*)fin->Get(var2subtr);
    varBkgHist = (TH1D*)tmpBkg->ProjectionX();
    varBkgHist->Sumw2();
  }
  //do the background subtractions
  varSigHist->Add(varBkgHist,-1);
  //now get the bin positions.
  //bin_ranges = binRanges;
  for(int i=0;i<6;++i){
    bin_ranges[i] = binRanges[i];
  }
  for(int i=0; i<nBins;++i){
    cout<<"for varSigHist "<<varSigHist->GetName()<<", testing bin ranges"<<bin_ranges[i]<<" to "<<bin_ranges[i+1]<<endl;
    varSigHist->GetXaxis()->SetRange(bin_ranges[i],bin_ranges[i+1]);
    mean_positions_of_variable[i] = varSigHist->GetMean();
    varSigHist->GetXaxis()->SetRange();
  }
  //get the dst mass in bins of whatever
  for(int i=0; i<nBins;++i){
    cout<<"===================="<<endl;
    cout<<histoForBins<<" bin "<<i+1<<endl;
    cout<<"===================="<<endl;
    sigHistBins[i] = (TH1D*)fin->Get(histoForBins+Form("%d",i+1));
    sigHistBins[i]->Sumw2();
    bkgHistBins[i] = (TH1D*)fin->Get(histoForBinsBkg+Form("%d",i+1));
    bkgHistBins[i]->Sumw2();
    sigHistBins[i]->Add(bkgHistBins[i],-1);    
    cout<<"Double check, "<<histoForBins+Form("%d",i+1)<<"->Integral()="<<sigHistBins[i]->Integral()<<endl;
    theFit = new massFit(histoForBins+Form("%d",i+1),"j3g",w);
    theFit->setData(sigHistBins[i]);
    theFit->FloatMeanWidth();
    theFit->fit();
    theFit->savePlots(true,histoForBins+Form("%d",i+1));
    dMeans[i] = theFit->getDMean();
    dMeansErr[i]=theFit->getDMeanErr();
    rSigmas[i] = theFit->getrSigma()*100.;
    rSigmasErr[i] = theFit->getrSigmaErr()*100.;
    sigYield[i] = theFit->getNsig();
    sigYieldErr[i] = theFit->getNsigErr();
    theFit->Reset();
    xError_low[i] = mean_positions_of_variable[i] - varSigHist->GetBinCenter(bin_ranges[i]);
    xError_hi[i] =  varSigHist->GetBinCenter(bin_ranges[i+1])-mean_positions_of_variable[i];
  }
  TCanvas * cc = new TCanvas();
  //make the axis label from theinput name.
  if(var2Test.Contains("dstar_pt")){
    theAxisLabel = "p_{T}(D*)[MeV]";
  }
  else if(var2Test.Contains("dstar_p")&& !(var2Test.Contains("pt"))){
    theAxisLabel = "p(D*)[MeV]";
  }
  else if(var2Test.Contains("mu_pt")){
    theAxisLabel = "p_{T}(#mu)[MeV]";
  }
  else if(var2Test.Contains("mu_p")&& !(var2Test.Contains("pt"))){
    theAxisLabel  ="p(#mu)[MeV]";
  }

  else if(var2Test.Contains("log_ip")){
    theAxisLabel  ="log IP(#mu)";
  }
  else if(var2Test.Contains("k_pidk")){
    theAxisLabel = "K PID K";
  }
  else if(var2Test.Contains("pi_pidk")){
    theAxisLabel = "#pi PID K";
  }
  dmeanGraph = new TGraphAsymmErrors(nBins,
				     mean_positions_of_variable,dMeans,
				     xError_low,xError_hi,
				     dMeansErr,dMeansErr);
  dmeanGraph->SetTitle(";"+theAxisLabel+";#delta #mu(D*) fit [MeV]");
  dmeanGraph->SetMarkerStyle(22);
  dmeanGraph->SetMarkerColor(kGreen+2);
  dmeanGraph->SetLineColor(kGreen+2);
  dmeanGraph->Draw("ap");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+var2Test+"dst_dmean_graph.pdf");
  cc->Clear();
  
  rsigmaGraph = new TGraphAsymmErrors(nBins,mean_positions_of_variable,rSigmas,xError_low,xError_hi,rSigmasErr,rSigmasErr);
  rsigmaGraph->SetTitle(";"+theAxisLabel+";#delta #sigma(D*) fit [%]");
  rsigmaGraph->SetMarkerStyle(22);
  rsigmaGraph->SetMarkerColor(kGreen+2);
  rsigmaGraph->SetLineColor(kGreen+2);
  rsigmaGraph->Draw("ap");
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+var2Test+"dst_rsigma_graph.pdf");
  cc->Clear();
  double tot_sig = 0;
  double tot_sig_err = 0;
  for(int i=0; i<nBins;++i){
    tot_sig+=sigYield[i];
    tot_sig_err+=sigYieldErr[i]*sigYieldErr[i];
  }
  SigAndErr.push_back(tot_sig);
  SigAndErr.push_back(TMath::Sqrt(tot_sig_err));
}
