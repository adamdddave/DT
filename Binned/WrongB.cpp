//include
//local
#include "WrongB.h"

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
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector3.h>
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
#include <RooArgusBG.h>
#include <RooAddPdf.h>
#include <RooCBShape.h>
#include <RooGenericPdf.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <RooPlot.h>
#include <RooHist.h>
#include <RooDataHist.h>
#include <RooExponential.h>
#include <RooBinning.h>
#include <RooDstD0BG.h>
#include <RooNLLVar.h>
#include "RooJohnson.h"
#include "RooJohnsonSU.h"
#include "RooRBW.h"
#include "RooCarolP3.h"
#include "RooNumConvPdf.h"
#include "RooFFTConvPdf.h"
#include "RooWorkspace.h"
//external
#include "PlottingTools.h"///for pull plots.
using namespace RooFit ;
using namespace std;



//-----------------------------------------------------------------------------
// Implementation file for class : WrongB
//
// 2015-02-06 : Adam Davis
//-----------------------------------------------------------------------------
WrongB::WrongB(TString name,DT_D0_mix_CPV loop_rs, DT_D0_mix_CPV loop_rs_ss){
  m_name = name;
  rs_bmass =(TH1D*) loop_rs.b_mass_plot->Clone("rs_bmass");
  rs_ss_bmass = (TH1D*)loop_rs_ss.b_mass_plot->Clone("rs_ss_bmass");
  cout<<"Initialized WrongB "<<name<<endl;
  
}

void WrongB::MakeMassComparisons(){
  
  //scale the rs_ss and rs histograms to the same integral at the high side
  TFile f("WrongBrates"+m_name+".root","recreate");
  f.cd();
  rs_bmass->Write();
  rs_ss_bmass->Write();
  f.Close();
  rs_ss_bmass->SetLineColor(kRed);
  //rs_ss_bmass->Scale(rs_bmass->Integral(310,400)/rs_ss_bmass->Integral(310,400));//bin goes from 5600 to 
  TCanvas* cc = new TCanvas();
  rs_bmass->SetTitle(";m(D*#mu);Entries / 10 MeV");
  TLine low(3100,0.1,3100,rs_bmass->GetMaximum()*1.2);
  TLine high(5100,0.1,5100,rs_bmass->GetMaximum()*1.2);
  low.SetLineColor(kOrange+3);
  high.SetLineColor(kOrange+3);
  low.SetLineStyle(kDashed);
  high.SetLineStyle(kDashed);
  rs_bmass->Draw();
  rs_ss_bmass->Draw("same");
  low.Draw();
  high.Draw();
  cc->SaveAs("./SavedFits/"+m_name+"bmass_regions_ss_os_scaled_to_high_sideband.pdf");
  cc->SetLogy(true);
  cc->SaveAs("./SavedFits/"+m_name+"bmass_regions_ss_os_scaled_to_high_sideband_logy.pdf");
  cc->SetLogy(false);
  //find the scaling factor to make the SS the same as the OS.
 
  //now integrate in signal region.
  //the bin width is (6500-2500)/4000=10
  //the min bin that we want is 3100, so (3100-2500)/10 = 60
  //the max bin is 5100, so (5100-2500)/10=260.
  the_scaling_factor = rs_bmass->Integral(rs_bmass->FindBin(5600.),rs_bmass->FindBin(6000.))/rs_ss_bmass->Integral(rs_ss_bmass->FindBin(5600.),rs_ss_bmass->FindBin(6000.));
  double rs_ss_int_sig = rs_ss_bmass->Integral(rs_ss_bmass->FindBin(3100),rs_ss_bmass->FindBin(5100));
  double rs_int_sig = rs_bmass->Integral(rs_bmass->FindBin(3100),rs_bmass->FindBin(5100));
  cout<<"integral of SS in signal region of bmass = "<<rs_ss_int_sig<<endl;
  cout<<"integral of OS in signal region of bmass = "<<rs_int_sig<<endl;
  cout<<"ratio of SS over OS two = "<<rs_ss_int_sig/rs_int_sig<<endl;
  cout<<"multiplying by scale factor = "<<rs_ss_int_sig*the_scaling_factor/rs_int_sig<<endl;
  
}

void WrongB::WriteScaleFactor(){
  cout<<"Now writing the high sideband scaling factor,"<<the_scaling_factor<<" to file"<<endl;
  std::ofstream outfile;
  outfile.open("./theScalingFactor.txt");
  outfile<<the_scaling_factor;
  outfile.close();
}

void WrongB::CompareIPchi2(){
  return;
}
WrongB::~WrongB(){
  delete rs_bmass;
  delete rs_ss_bmass;
  delete rs_dstar_mass;
  delete rs_ss_dstar_mass;
  delete dstarm_vs_muIPchi2;
  delete dstarm_ss_vs_muIPchi2;
  delete bmass_vs_muIPchi2;
  delete bmass_ss_vs_muIPChi2;
}
