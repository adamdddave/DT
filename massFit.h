#ifndef COMPLETE_ANALYSIS_MASSFIT_H 
#define COMPLETE_ANALYSIS_MASSFIT_H 1

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
using namespace RooFit ;
using namespace std;

/** @class massFit massFit.h complete_analysis/massFit.h
 *  
 * class for fitting the mass histogram.
 *  @author Adam Davis
 *  @date   2015-02-06
 */
class massFit {
public: 
  /// Standard constructor
  
  massFit(TString Channel,TString modelname,RooWorkspace* w=0, TString localDir = "");
  ~massFit();
  void fit();
  void saveWorkspace();
  //setters
  void setFitModel(TString modelname){modelName = modelname;}
  void setData(TH1* data_hist);
  void initModelValues();//set things like the argus parameters which are constant.
  void FloatMeanWidth();
  void Reset();
  //getters
  //RooWorkspace* getFinalFit();///so we can fit the RS model once, then reuse the fit.
  void saveFinalFit();
  TString getFitModel(){return modelName;}
  void savePlots(bool doPullPlots = false,TString extraName = "");
  void saveSignalRegionZoom();
  inline double getNsig(){return nsig->getVal();}
  inline double getNbkg(){return nbkg->getVal();}
  inline double getNsigErr(){return nsig->getError();}
  inline double getNbkgErr(){return nbkg->getError();}
  inline double getrSigma(){return rsigma->getVal();}
  inline double getrSigmaErr(){return rsigma->getError();}
  inline double getDMean(){return dmean->getVal();}
  inline double getDMeanErr(){return dmean->getError();}
  //virtual ~massFit( ); ///< Destructor

protected:

private:
  const double pion_mass_pdg = 139.57018;
  const double d0_mass_pdg =1864.86;
  const Double_t xmin = pion_mass_pdg+d0_mass_pdg;
  const Double_t xmax = 2025;
  TString channel;//rs,ws,rs_ss,ws_ss
  TString modelName;
  TString theLocalDir;
  RooWorkspace* existing_fit;//if we already have a fit model that works, put it here.
  bool use_existing_fit;
  RooWorkspace* new_fit;
  RooRealVar* mass;//("dstarM","M(D^{0}#pi_{s})",1990.,2050.,"MeV");//mass to fit
  RooRealVar* dmean;//("dmean","dmean",0,-1,1);//allowed variation for dstar mean value
  RooRealVar* rsigma;//("rsigma","rsigma",0,-50,50);//allowed variation for dstar width val
  //johnson parameters
  RooRealVar* m0;//("m0","m0",2010.,2009.,2011.);
  RooFormulaVar* fm0;//("fm0", "@0+@1", RooArgList(m0, dmean));
  RooRealVar* delta;//("delta","delta",9.57168e-01,0.2,2);
  RooRealVar* sigma;//("sigma","sigma",1,2e-1,10);
  RooFormulaVar* fsigma;//("fsigma", "@0*(1+@1)", RooArgList(sigma, rsigma));
  RooRealVar* gamma;//("gamma","gamma",-1.20272e-01, -2,2);
  RooJohnsonSU* sig_john;//("sig_john","sig_john",mass,fm0,fsigma,gamma,delta);
  RooRealVar* mean1;//("mean1","mean1",2010.,2009,2011);
  //for offsets
  RooFormulaVar* fgau1mean;//("fgau1mean", "@0+@1", RooArgList(mean1, dmean));
  RooRealVar* mean2;//("mean2","mean2",2010.,2009,2012);
  RooFormulaVar* fgau2mean;//("fgau2mean", "@0+@1", RooArgList(mean2, dmean));
  RooRealVar* mean3;//("mean3","mean3",2010.,2009,2011);
  RooFormulaVar* fgau3mean;//("fgau3mean", "@0+@1", RooArgList(mean3, dmean));
  
  RooRealVar* width1;//("width1","width1",1,0.01,10);
  RooFormulaVar* fgau1sigma;//("fgau1sigma", "@0*(1+@1)", RooArgList(width1, rsigma));
  RooRealVar* width2;//("width2","width2",1,0.01,10);
  RooFormulaVar* fgau2sigma;//("fgau2sigma", "@0*(1+@1)", RooArgList(width2, rsigma));
  RooRealVar* width3;//("width3","width3",1,0.01,10);
  RooFormulaVar* fgau3sigma;//("fgau3sigma", "@0*(1+@1)", RooArgList(width3, rsigma));
  
  
  RooGaussian* g1;//("g1","g1",mass,fgau1mean,fgau1sigma);
  RooGaussian* g2;//("g2","g2",mass,fgau2mean,fgau2sigma);
  RooGaussian* g3;//("g3","g3",mass,fgau3mean,fgau3sigma);
  
  //crystal balls
  RooRealVar* cb1_m0;//("cb1_m0","cb1_m0",2010.,2009.9,2010.9);
  RooRealVar* cb1_sigma;//("cb1_sigma","cb1_sigma",1,0.01,10);
  RooRealVar* cb1_alpha;//("cb1_alpha","cb1_alpha",-0.2, -10.,0.);//tail on the right
  RooRealVar* cb1_n;//("cb1_n","cb1_n",1,0.,10.);
  RooCBShape* CBall1;//("CBall1","Crystal Ball 1",mass,cb1_m0,cb1_sigma,cb1_alpha,cb1_n);
  
  RooRealVar* cb2_m0;//("cb2_m0","cb2_m0",2010.,2009.9,2010.9);
  RooRealVar* cb2_sigma;//("cb2_sigma","cb2_sigma",0.6,0.1,1.4);
  RooRealVar* cb2_alpha;//("cb2_alpha","cb2_alpha",1,0.,10.);//tail on the left
  RooRealVar* cb2_n;//("cb2_n","cb2_n",1,0.,10.);
  RooCBShape* CBall2;//("CBall2","Crystal Ball 2",mass,cb2_m0,cb2_sigma,cb2_alpha,cb2_n);

  //RBW
  RooRealVar* rbw_m0;//("rbw_m0","",2010,2009,2011);
  RooRealVar* rbw_sigma;//("rbw_sigma","",1,2e-1,10);
  RooRealVar* rbw_width;
  RooRealVar* res_mean1;
  RooRealVar* res_mean2;
  RooRealVar* res_mean3;
  RooRealVar* res_width1;
  RooRealVar* res_width2;
  RooRealVar* res_width3;
  RooRealVar* res_frac1;
  RooRealVar* res_frac2;
  RooRealVar* eps_width;
  RooRealVar* eps_mean;
  RooGaussian* res_gau_1;
  RooGaussian* res_gau_2;
  RooGaussian* res_gau_3;
  RooRBW* rbw;//("rbw","",mass,rbw_m0,rbw_sigma);
  RooFormulaVar* mean1sh;
  RooFormulaVar* mean2sh;
  RooFormulaVar* mean3sh;
  RooFormulaVar* width1sh;
  RooFormulaVar* width2sh;
  RooFormulaVar* width3sh;

  //Zach's RBW (X) Gaussian
  //RooRealVar* rcp3_gmean;//("rcp3_gmean","",2010,xmin,2015);
  //RooRealVar* rcp3_gsigma;//("rcp3_gsigma","",1,0.1,10);
  //use the scaled widths and shifted means from above.
  RooCarolP3 *Rcp1;//("Rcp3","",mass,rcp3_mean,rcp3_width,rcp3_gmean,rcp3_gsigma);
  RooCarolP3 *Rcp2;//("Rcp3","",mass,rcp3_mean,rcp3_width,rcp3_gmean,rcp3_gsigma);
  RooCarolP3 *Rcp3;//("Rcp3","",mass,rcp3_mean,rcp3_width,rcp3_gmean,rcp3_gsigma);
  // add the decay in flight shape.
  /*
  Floating Parameter  InitialValue    FinalValue (+HiError,-LoError)    GblCorr.
  --------------------  ------------  ----------------------------------  --------
                  frac    5.0000e-01    3.6122e-01 (+2.40e-02,-2.39e-02)  <none>
                 kappa    1.0000e+01   -3.0189e+02 (+2.50e+01,-2.60e+01)  <none>
                     n    5.0000e-01    1.3477e+00 (+1.70e-01,-1.62e-01)  <none>

  */
  RooRealVar* decay_in_flight_kappa;
  RooRealVar* decay_in_flight_n;
  RooRealVar* decay_in_flight_endpt;
  RooArgusBG* decay_in_flight_shape;
  RooRealVar* frac_dif;
  // ---Make Background variables ---
  
  //Empirical \delta m function
  RooRealVar* xscale;//("xscale","xscale",1);
  RooRealVar* endpt;//("endpt","argpar2",(d0_mass_pdg+pion_mass_pdg),xmin-0.1,xmin+0.1);
  RooFormulaVar* minusDM;//("minusDM", "@2-@1*(@0-@2)", RooArgList(mass, xscale, endpt));
  RooRealVar* kappa;//("kappa", "argpar1", -3.8935e+01, -100, 20);
  RooRealVar* n;//("n", "", 0.5, 0.4, 0.9);
  RooArgusBG* bkg_arg;//("bkg", "argus_bkg", minusDM, endpt, kappa, n);
  RooRealVar* nsig;//("nsig", "nsig", 9e6, 0, 1e10);
  RooRealVar* frac1;//("frac1", "frac1", .1,0,1);
  RooRealVar* frac2;//("frac2", "frac2", .1,0,1);
  RooRealVar* frac3;//("frac3", "frac3", .1,0,1);
  RooRealVar* nbkg;//("nbkg", "", 1e3,0, 1e8);
  //
  RooAbsPdf *sigpdf;
  RooDataHist* data;
  RooAbsPdf *model;
  
};
#endif // COMPLETE_ANALYSIS_MASSFIT_H
