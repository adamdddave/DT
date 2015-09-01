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
#include <THStack.h>

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
// TimeIntegratedSystematicsClass::~TimeIntegratedSystematicsClass(){
//   delete theFit;
//   //delete varSigHist;
//   delete varBkgHist;
//   delete sigHist;
//   delete bkgHist;
//   delete wLocal;
//   for(int i=0; i<5;++i){delete sigHistBins[i]; delete bkgHistBins[i];}
// }//destructor
TimeIntegratedSystematicsClass::TimeIntegratedSystematicsClass(TString name,TFile *fin,
							       RooWorkspace* w,
							       TString var2Test, TString var2subtr,
							       TString histoForBins,TString histoForBinsBkg,
							       int binRanges[6],
							       int nbins){
  mName = name;
  nBins = nbins;
  //fin->ls();
  wLocal = new RooWorkspace(*w);
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
    theFit = new massFit(histoForBins+Form("%d",i+1),"j3g",wLocal,"TimeIntegratedSystematics");
    theFit->setData(sigHistBins[i]);
    //fit once to get params, then float the mean and width, and fit again
    theFit->fit();
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
  //finally, if we're doing the 5x5
  else if(var2Test.Contains("pi_pidk") && histoForBins.Contains("pi_pid_k_bin")&&histoForBins.Contains("_k_pid_k_bin")){
    //working with bins in both k pid k and pi pidk
    //an example is RS_dt_hist_pi_pid_k_bin1_k_pid_k_bin2, here, we want the 1
    TString theBin2use = histoForBins;
    theBin2use.ReplaceAll("_k_pid_k_bin","");
    theBin2use.ReplaceAll("RS_dt_hist_pi_pid_k_bin","");
    theAxisLabel = "#pi PID K, bin "+theBin2use;
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
  //finally, draw the D* peaks on top of each other and save them.
  TLegend* leg = new TLegend(0.7,0.6,0.9,0.9);
  int the_colors[5]={kBlue,kGreen+2,kMagenta, kOrange,kRed};
  //sigHistBins[0]->SetLineColor(the_colors[0]);
  //sigHistBins[0]->Draw("l");
  double currMax = sigHistBins[0]->GetMaximum();
  TString the_leg_text;
  THStack *hs = new THStack("hs","");
  for(int i=0; i<5;++i){
    if(i==0){the_leg_text = theAxisLabel+Form("<%.1f",varSigHist->GetBinCenter(bin_ranges[i+1]));}
    else if(i<4){the_leg_text = Form("%.1f#leq",varSigHist->GetBinCenter(bin_ranges[i]))+theAxisLabel+Form("<%.1f",varSigHist->GetBinCenter(bin_ranges[i+1]));}
    else{the_leg_text = theAxisLabel+Form("#geq %.1f",varSigHist->GetBinCenter(bin_ranges[i]));}
    sigHistBins[i]->SetLineColor(the_colors[i]);
    //sigHistBins[i]->Draw("lsame");
    if(sigHistBins[i]->GetMaximum()>currMax){currMax = sigHistBins[i]->GetMaximum();}
    leg->AddEntry(sigHistBins[i],the_leg_text);
    hs->Add(sigHistBins[i],"hist");
  }
  hs->SetTitle(Form(";m(D*)[MeV];Entries/%.2f",sigHistBins[0]->GetBinWidth(1)));
  hs->Draw("nostack");
  leg->Draw();
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+var2Test+"dst_mass_comparison.pdf");
  cc->SetLogy(true);
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+var2Test+"dst_mass_comparison_logy.pdf");
  cc->SetLogy(false);
  cc->Clear();
  //draw the shit normalized to the peak.
  
  for(int i=0; i<5;++i){
    sigHistBins[i]->Scale(1./sigHistBins[i]->GetMaximum());
  }
  hs->Modified();
  hs->Draw("nostack");
  leg->Draw();
    cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+var2Test+"dst_mass_comparison_norm_to_peak.pdf");
  cc->SetLogy(true);
  cc->SaveAs("./SavedFits/TimeIntegratedSystematics/"+var2Test+"dst_mass_comparison_norm_to_peak_logy.pdf");
  cc->SetLogy(false);

  delete leg;
}
