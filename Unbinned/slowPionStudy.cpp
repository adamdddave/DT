// Include files 
#include <iostream>
// local
#include "slowPionStudy.h"
//root
#include <TBox.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TFile.h>
#include <TStyle.h>
#include <TPaveText.h>
#include <TF1.h>
#include <TMultiGraph.h>

//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
#include "RooCFunction1Binding.h"
#include "RooCFunction3Binding.h"
#endif
#include <RooFitResult.h>
#include <RooProduct.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooGaussian.h>
#include <RooChebychev.h>
#include <RooArgusBG.h>
#include <RooAddPdf.h>
#include <RooCBShape.h>
#include <RooGenericPdf.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <TFitResult.h>
#include <TVectorD.h>
#include <RooPlot.h>
#include <RooHist.h>
#include <RooDataHist.h>
#include <RooExponential.h>
#include <RooBinning.h>
#include <RooDstD0BG.h>
#include <RooNLLVar.h>
#include <RooChebychev.h>
#include <RooPolynomial.h>
#include <RooExtendPdf.h>
#include <RooWorkspace.h>
#include <RooTFnBinding.h>

#include <PlottingTools.h>
#include "massFit.h"
using namespace RooFit ;
using namespace std;

//class to look at possible charge asymmetry of slow pion ghost prob cut

//constuctor
slowPionStudy::slowPionStudy(TString name,RooWorkspace* w){
  mName = name;
  wLocal = w;
}
void slowPionStudy::setHistogramsPositive(std::vector<TH1D*>the_hists_pass,std::vector<TH1D*>the_hists_fail){
  hists_pos_pass = the_hists_pass;
  hists_pos_fail = the_hists_fail;
}


void slowPionStudy::setHistogramsNegative(std::vector<TH1D*>the_hists_pass,std::vector<TH1D*>the_hists_fail){
  hists_neg_pass = the_hists_pass;
  hists_neg_fail = the_hists_fail;
}

void slowPionStudy::makeProbNNghostPlots(){
  //the workhorse
  //first fit each individual sample.
  int counter=0;
  
  for(auto hist: hists_pos_pass){
    counter++;
    massFit fit(Form("ProbNNghostPlot%d",counter),"j3g",wLocal,"SlowPionGhostProbStudy");
    fit.setData(hist);
    fit.fit();
    fit.savePlots(false,"_positive_pass_");
    nsig_pos_pass.push_back(fit.getNsig());
    nsigErr_pos_pass.push_back(fit.getNsigErr());
    cout<<"fit.getNbkg() = "<<fit.getNbkg()<<endl;
    nbkg_pos_pass.push_back(fit.getNbkg());
    nbkgErr_pos_pass.push_back(fit.getNbkgErr());
    fit.Reset();
  }
  counter = 0;
  for(auto hist: hists_neg_pass){
    counter++;
    massFit fit(Form("ProbNNghostPlot%d",counter),"j3g",wLocal,"SlowPionGhostProbStudy");
    fit.setData(hist);
    fit.fit();
    fit.savePlots(false,"_negative_pass_");
    nsig_neg_pass.push_back(fit.getNsig());
    nsigErr_neg_pass.push_back(fit.getNsigErr());

    nbkg_neg_pass.push_back(fit.getNbkg());
    nbkgErr_neg_pass.push_back(fit.getNbkgErr());
    fit.Reset();
  }
  counter=0;
  //fail
    for(auto hist: hists_pos_fail){
    counter++;
    massFit fit(Form("ProbNNghostPlot%d",counter),"j3g",wLocal,"SlowPionGhostProbStudy");
    fit.setData(hist);
    fit.fit();
    fit.savePlots(false,"_positive_fail_");
    nsig_pos_fail.push_back(fit.getNsig());
    nsigErr_pos_fail.push_back(fit.getNsigErr());

    nbkg_pos_fail.push_back(fit.getNbkg());
    nbkgErr_pos_fail.push_back(fit.getNbkgErr());
    fit.Reset();
  }
  counter=0;
  for(auto hist: hists_neg_fail){
    counter++;
    massFit fit(Form("ProbNNghostPlot%d",counter),"j3g",wLocal,"SlowPionGhostProbStudy");
    fit.setData(hist);
    fit.fit();
    fit.savePlots(false,"_negative_fail_");
    nsig_neg_fail.push_back(fit.getNsig());
    nsigErr_neg_fail.push_back(fit.getNsigErr());

    nbkg_neg_fail.push_back(fit.getNbkg());
    nbkgErr_neg_fail.push_back(fit.getNbkgErr());

    fit.Reset();
  }
  
  double xvals[] = {0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5};
  double zeros[] = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  double eff_pos[10],eff_neg[10],bkg_rej_pos[10],bkg_rej_neg[10];
  double eff_err_pos[10],eff_err_neg[10],bkg_rej_err_pos[10],bkg_rej_err_neg[10];
  for(int i=0; i<10;++i){
    eff_pos[i]=nsig_pos_pass[i]/(nsig_pos_pass[i]+nsig_pos_fail[i]);
    eff_err_pos[i]=eff_err(nsig_pos_pass[i],nsig_pos_pass[i]+nsig_pos_fail[i]);

    eff_neg[i]=nsig_neg_pass[i]/(nsig_neg_pass[i]+nsig_neg_fail[i]);
    eff_err_neg[i]=eff_err(nsig_neg_pass[i],nsig_neg_pass[i]+nsig_neg_fail[i]);

    bkg_rej_pos[i]=1-nbkg_pos_pass[i]/(nbkg_pos_pass[i]+nbkg_pos_fail[i]);
    bkg_rej_err_pos[i]=eff_err(nbkg_pos_pass[i],nbkg_pos_pass[i]+nbkg_pos_fail[i]);

    bkg_rej_neg[i]=1- nbkg_neg_pass[i]/(nbkg_neg_pass[i]+nbkg_neg_fail[i]);
    bkg_rej_err_neg[i]=eff_err(nbkg_neg_pass[i],nbkg_neg_pass[i]+nbkg_neg_fail[i]);
  }
  the_eff_plot_pos = new TGraphErrors(10,xvals,eff_pos,zeros,eff_err_pos);
  the_eff_plot_neg = new TGraphErrors(10,xvals,eff_neg,zeros,eff_err_neg);

  the_bkg_rej_plot_pos = new TGraphErrors(10,xvals,bkg_rej_pos,zeros,bkg_rej_err_pos);
  the_bkg_rej_plot_neg = new TGraphErrors(10,xvals,bkg_rej_neg,zeros,bkg_rej_err_neg);

  the_eff_plot_pos->SetMarkerColor(kBlue);
  the_bkg_rej_plot_pos->SetMarkerColor(kBlue);

  the_eff_plot_neg->SetMarkerColor(kRed);
  the_bkg_rej_plot_neg->SetMarkerColor(kRed);
  
  the_eff_plot_pos->SetMarkerStyle(29);
  the_eff_plot_neg->SetMarkerStyle(29);

  the_bkg_rej_plot_pos->SetMarkerStyle(21);
  the_bkg_rej_plot_neg->SetMarkerStyle(21);
  /*cout<<"     nsig_pass           nsig_fail"<<endl;
  cout<<"pos"<<endl;
  for(int i=0; i<nsig_pos_pass.size();++i){
    cout<<nsig_pos_pass[i]<<"       "<<nsig_pos_fail[i]<<endl;
  }
  cout<<"neg"<<endl;
  for(int i=0; i<nsig_neg_pass.size();++i){
    cout<<nsig_neg_pass[i]<<"       "<<nsig_neg_fail[i]<<endl;
    }*/
  cout<<"Difference in efficinecy per cut bin for ghost prob cut (plus - minus) in %= "<<endl;
  for(int i=0; i<9;++i){
    cout<<"bin "<<i<<setw(15)<<(eff_pos[i]-eff_neg[i])*100<<endl;
  }
  
}

void slowPionStudy::drawPlot(){
  TCanvas* cc = new TCanvas();
  TMultiGraph* mg = new TMultiGraph();
  mg->Add(the_eff_plot_pos);
  mg->Add(the_eff_plot_neg);
  mg->SetTitle(";#pi_{S} ProbNNghost Cut; #epsilon");
  mg->Draw("ap");
  TLegend leg(0.7,0.3,0.9,0.5);
  leg.AddEntry(the_eff_plot_pos,"#pi_{S}^{+}","lpe");
  leg.AddEntry(the_eff_plot_neg,"#pi_{S}^{-}","lpe");
  leg.Draw();
  cc->SaveAs(theDir+mName+"SlowPionEfficiencyPlot.pdf");
  cc->Clear();
  TMultiGraph* mg2 = new TMultiGraph();
  mg2->Add(the_bkg_rej_plot_pos);
  mg2->Add(the_bkg_rej_plot_neg);
  mg2->SetTitle(";#pi_{S} ProbNNghost Cut;Background Rejection");
  mg2->Draw("ap");
  TLegend leg2(0.7,0.7,0.9,0.9);
  leg2.AddEntry(the_eff_plot_pos,"#pi_{S}^{+}","lpe");
  leg2.AddEntry(the_eff_plot_neg,"#pi_{S}^{-}","lpe");
  leg2.Draw();
  cc->SaveAs(theDir+mName+"SlowPionBkgRejPlot.pdf");
  cc->Clear();
}

slowPionStudy::~slowPionStudy(){
  delete the_eff_plot_pos;
  delete the_eff_plot_neg;

  delete the_bkg_rej_plot_pos;
  delete the_bkg_rej_plot_neg;
}
double slowPionStudy::eff_err(double num, double denom){
  double eff = num/denom;
  double err = TMath::Sqrt((eff*(1-eff))/denom);
  return err;
}
