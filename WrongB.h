#ifndef COMPLETE_ANALYSIS_WRONGB_H 
#define COMPLETE_ANALYSIS_WRONGB_H 1

// Include files
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
#include "RooWorkspace.h"
//external
#include "DT_D0_mix_CPV.h"
using namespace RooFit ;
using namespace std;

/* @ class WrongB WrongB.h complete_analysis/WrongB.h
 *
 * class to explore the effect of the wrong b on the D* shape
 * and try to emeliorate it.
 * @author Adam Davis
 * @date 2015-06-16
 */
class WrongB {


 public:
  //standard constructor
  WrongB(TString name, DT_D0_mix_CPV loop_rs, DT_D0_mix_CPV loop_rs_ss);
  //destructor
  virtual ~WrongB(){ }
  void MakeMassComparisons();
  void CompareIPchi2();
 protected:
  
 private:
  TString m_name;
  TH1D* rs_bmass;
  TH1D* rs_ss_bmass;
  TH1D* rs_dstar_mass;
  TH1D* rs_ss_dstar_mass;
  TH2D* dstarm_vs_muIPchi2;
  TH2D* dstarm_ss_vs_muIPchi2;
  TH2D* bmass_vs_muIPchi2;
  TH2D* bmass_ss_vs_muIPChi2;
};

#endif //COMPLETE_ANALYSIS_WRONGB_H
