// Include files 
// local
#include "massFit.h"

//C++
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <assert.h>
#include <string>
#include <sys/stat.h>//mkdir
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
#include <TPaveText.h>
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
// Implementation file for class : massFit
//
// 2015-02-06 : Adam Davis
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
massFit::massFit(TString Channel,TString modelname,RooWorkspace* w, TString localDir,bool addsigbox) {

  addSigBox = addsigbox;
  channel = Channel;
  setFitModel(modelname);
  theLocalDir = localDir;
  //make a local directory in case we have one
  if(theLocalDir!=""){
    TString d2make = "./SavedFits/"+localDir;
    umask(0);
    mkdir(d2make.Data(),0755);
  }
  //stuff we'll need
  //pion_mass_pdg = 139.57018;
  //  d0_mass_pdg =1864.86;
  //  xmin = pion_mass_pdg+d0_mass_pdg;//try adding an offset.
  //  xmax = 2025;
  use_existing_fit = false;
  if(w!=0){
    existing_fit = w;
    use_existing_fit=true;
    
    cout<<"Using existing fit models from workspace"<<endl;
    mass = (existing_fit->var("dstarM"));
    //mass->setRange(xmin+0.1,xmax);
    //mass->Print("v");
    dmean = (existing_fit->var("dmean"));
    rsigma= (existing_fit->var("rsigma"));
    nsig = (existing_fit->var("nsig"));
    //import and fix the signal shape.
    //sigpdf = (existing_fit->pdf("sigpdf"));
    //existing_fit->var("endpt")->setConstant(0);
    model = (existing_fit->pdf("model"));
    bkg_arg = (RooArgusBG*)(existing_fit->pdf("bkg"));
    sigpdf = (existing_fit->pdf("sigpdf"));
    nbkg = (existing_fit->var("nbkg"));
    model->Print("v");
    kappa = (existing_fit->var("kappa"));
    n = (existing_fit->var("n"));
    if(modelName== "j2g"){
      //fm0=existing_fit->var("fm0")->setConstant(1);
      existing_fit->var("m0")->setConstant(1);
      existing_fit->var("delta")->setConstant(1);
      existing_fit->var("sigma")->setConstant(1);
      existing_fit->var("mean1")->setConstant(1);
      existing_fit->var("mean2")->setConstant(1);      
      existing_fit->var("width1")->setConstant(1);
      existing_fit->var("width2")->setConstant(1);
      existing_fit->var("frac1")->setConstant(1);
      existing_fit->var("frac2")->setConstant(1);
      sig_john = (RooJohnsonSU*)existing_fit->pdf("sig_john");
      g1 = (RooGaussian*)existing_fit->pdf("g1");
      g2 = (RooGaussian*)existing_fit->pdf("g2");
      //g3 = (RooGaussian*)existing_fit->pdf("g3");
 
    }    
    else if(modelName== "cb2g"){
      existing_fit->var("mean1")->setConstant(1);
      existing_fit->var("mean2")->setConstant(1);
      existing_fit->var("width1")->setConstant(1);
      existing_fit->var("width2")->setConstant(1);
      existing_fit->var("cb1_m0")->setConstant(1);
      existing_fit->var("cb1_sigma")->setConstant(1);
      existing_fit->var("cb1_alpha")->setConstant(1);
      existing_fit->var("cb1_n")->setConstant(1);
      existing_fit->var("frac1")->setConstant(1);
      existing_fit->var("frac2")->setConstant(1);
      
    }
    
    else if(modelName== "2cb"){
      existing_fit->var("cb1_m0")->setConstant(1);
      existing_fit->var("cb1_sigma")->setConstant(1);
      existing_fit->var("cb1_alpha")->setConstant(1);
      existing_fit->var("cb1_n")->setConstant(1);
      existing_fit->var("cb2_m0")->setConstant(1);
      existing_fit->var("cb2_sigma")->setConstant(1);
      existing_fit->var("cb2_alpha")->setConstant(1);
      existing_fit->var("cb2_n")->setConstant(1);
      existing_fit->var("frac1")->setConstant(1);
    }
    
    else if(modelName=="3g"){
      existing_fit->var("mean1")->setConstant(1);
      existing_fit->var("mean2")->setConstant(1);
      existing_fit->var("mean3")->setConstant(1);
      
      existing_fit->var("width1")->setConstant(1);
      existing_fit->var("width2")->setConstant(1);
      existing_fit->var("width3")->setConstant(1);
      existing_fit->var("frac1")->setConstant(1);
      existing_fit->var("frac2")->setConstant(1);
      
    }
    else if(modelName=="rbw"){
      existing_fit->var("rbw_m0")->setConstant(1);
      existing_fit->var("rbw_sigma")->setConstant(1);
      existing_fit->var("rbw_width")->setConstant(1);
      existing_fit->var("eps_mean")->setConstant(1);
      existing_fit->var("eps_width")->setConstant(1);
      existing_fit->var("res_mean1")->setConstant(1);
      existing_fit->var("res_mean2")->setConstant(1);
      existing_fit->var("res_mean3")->setConstant(1);
      existing_fit->var("res_width1")->setConstant(1);
      existing_fit->var("res_width2")->setConstant(1);
      existing_fit->var("res_width3")->setConstant(1);
      existing_fit->var("res_frac1")->setConstant(1);
      existing_fit->var("res_frac2")->setConstant(1);
      existing_fit->var("frac1")->setConstant(1);
      existing_fit->var("frac2")->setConstant(1);
      
    }
    
    else if (modelName=="rcp3"){
      existing_fit->var("rbw_m0")->setConstant(1);
      existing_fit->var("rbw_sigma")->setConstant(1);
      existing_fit->var("rbw_width")->setConstant(1);
      existing_fit->var("eps_mean")->setConstant(1);
      existing_fit->var("eps_width")->setConstant(1);
      existing_fit->var("res_mean1")->setConstant(1);
      existing_fit->var("res_mean2")->setConstant(1);
      existing_fit->var("res_mean3")->setConstant(1);
      existing_fit->var("res_width1")->setConstant(1);
      existing_fit->var("res_width2")->setConstant(1);
      existing_fit->var("res_width3")->setConstant(1);
      existing_fit->var("res_frac1")->setConstant(1);
      existing_fit->var("res_frac2")->setConstant(1);
      existing_fit->var("frac1")->setConstant(1);
      existing_fit->var("frac2")->setConstant(1);
      existing_fit->var("frac3")->setConstant(1);

    }
    else if (modelName=="2g"){//for background studes
      existing_fit->var("mean1")->setConstant(1);
      existing_fit->var("mean2")->setConstant(1);
      existing_fit->var("width1")->setConstant(1);
      existing_fit->var("width2")->setConstant(1);
      existing_fit->var("frac1")->setConstant(1);
      g1 = (RooGaussian*)existing_fit->pdf("g1");
      g2 = (RooGaussian*)existing_fit->pdf("g2");
    }
    else if (modelName=="1g"){//for background studes
      existing_fit->var("mean1")->setConstant(1);
      existing_fit->var("width1")->setConstant(1);
      g2 = (RooGaussian*)existing_fit->pdf("g2");
    }
    else
    {
      //existing_fit->var("fm0")->setConstant(1);
      existing_fit->var("m0")->setConstant(1);
      existing_fit->var("delta")->setConstant(1);
      existing_fit->var("sigma")->setConstant(1);
      existing_fit->var("gamma")->setConstant(1);
      existing_fit->var("mean1")->setConstant(1);
      existing_fit->var("mean2")->setConstant(1);
      existing_fit->var("mean3")->setConstant(1);
      existing_fit->var("width1")->setConstant(1);
      existing_fit->var("width2")->setConstant(1);
      existing_fit->var("width3")->setConstant(1);
      existing_fit->var("frac1")->setConstant(1);
      existing_fit->var("frac2")->setConstant(1);
      existing_fit->var("frac3")->setConstant(1);
      sig_john = (RooJohnsonSU*)existing_fit->pdf("sig_john");
      g1 = (RooGaussian*)existing_fit->pdf("g1");
      g2 = (RooGaussian*)existing_fit->pdf("g2");
      g3 = (RooGaussian*)existing_fit->pdf("g3");
      
    }

    
  }
  else{
    //initialize all the variables
    
    mass = new  RooRealVar("dstarM","M(D^{0}#pi_{s})",2000,xmax,"MeV");//mass to fit
    //mass = new  RooRealVar("dstarM","M(D^{0}#pi_{s})",-100.,2050.,"MeV");//mass to fit
    
    //mass->setRange(xmin,xmax);
    dmean= new RooRealVar("dmean","dmean",0,-1,1);//allowed variation for dstar mean value
    rsigma= new RooRealVar("rsigma","rsigma",0,-20,20);//allowed variation for dstar width val
    //johnson parameters
    //m0= new RooRealVar("m0","m0",2010.,2009.,2011.);
    double m0_liang = 2.00935381450188277*1e3;
    m0= new RooRealVar("m0","m0",m0_liang,m0_liang*(0.95),m0_liang*(1.05));//constant from liang's fit
    fm0= new RooFormulaVar("fm0", "@0+@1", RooArgList(*m0, *dmean));

    //delta= new RooRealVar("delta","delta",9.57168e-01,0.2,2);
    double delta_liang = 1.92116578346114197;
    delta= new RooRealVar("delta","delta",delta_liang,0.40*delta_liang,1.80*delta_liang);
    //sigma= new RooRealVar("sigma","sigma",1,2e-1,10);
    double sigma_liang = 2.49952200109722269e-03*1e3;
    sigma= new RooRealVar("sigma","sigma",sigma_liang,0.40*sigma_liang,1.80*sigma_liang);
    fsigma= new RooFormulaVar("fsigma", "@0*(1+@1)", RooArgList(*sigma, *rsigma));
    //gamma= new RooRealVar("gamma","gamma",-1.80272e-01, -2,2);
    double gamma_liang = -8.64089594146807194e-01;
    gamma= new RooRealVar("gamma","gamma",gamma_liang, 1.80*gamma_liang,0.40*gamma_liang);//flopped since negative.
    //m0->setConstant(1);
    //    delta->setConstant(1);
    //gamma->setConstant(1);
    //    sigma->setConstant(1);
    sig_john= new RooJohnsonSU("sig_john","sig_john",*mass,*fm0,*fsigma,*gamma,*delta);
    //mean1= new RooRealVar("mean1","mean1",2010.,2009,2011);
    double mean1_liang = 2.01032477109741325*1e3;
    mean1= new RooRealVar("mean1","mean1",mean1_liang,0.40*mean1_liang,1.80*mean1_liang);
    //for offsets
    fgau1mean= new RooFormulaVar("fgau1mean", "@0+@1", RooArgList(*mean1, *dmean));
    //mean2= new RooRealVar("mean2","mean2",2010.,2008,2011);
    double mean2_liang = 2.01028445885560236*1e3;
    mean2= new RooRealVar("mean2","mean2",mean2_liang,0.40*mean2_liang,1.80*mean2_liang);
    fgau2mean= new RooFormulaVar("fgau2mean", "@0+@1", RooArgList(*mean2, *dmean));
    //mean3= new RooRealVar("mean3","mean3",2010.,2007,2013);
    double mean3_liang = 2.01027349064504390*1e3;
    mean3= new RooRealVar("mean3","mean3",mean3_liang,0.40*mean3_liang,1.80*mean3_liang);
    fgau3mean= new RooFormulaVar("fgau3mean", "@0+@1", RooArgList(*mean3, *dmean));
  
    //width1= new RooRealVar("width1","width1",1,0.01,10);
    double width1_liang = 5.81409441017281033e-01;
    width1= new RooRealVar("width1","width1",width1_liang,0.40*width1_liang,1.80*width1_liang);
    fgau1sigma= new RooFormulaVar("fgau1sigma", "@0*(1+@1)", RooArgList(*width1, *rsigma));
    //width2= new RooRealVar("width2","width2",1,0.01,10);
    double width2_liang =3.11715962949287427e-01;
    width2= new RooRealVar("width2","width2",width2_liang,0.40*width2_liang,1.80*width2_liang);
    fgau2sigma= new RooFormulaVar("fgau2sigma", "@0*(1+@1)", RooArgList(*width2, *rsigma));
    //width3= new RooRealVar("width3","width3",1,0.01,10);
    double width3_liang = 1.95072497687380828e-01;
    width3= new RooRealVar("width3","width3",width3_liang,0.40*width3_liang,1.80*width3_liang);
    fgau3sigma= new RooFormulaVar("fgau3sigma", "@0*(1+@1)", RooArgList(*width3, *rsigma));
  
  
    g1= new  RooGaussian("g1","g1",*mass,*fgau1mean,*fgau1sigma);
    g2= new  RooGaussian("g2","g2",*mass,*fgau2mean,*fgau2sigma);
    g3= new  RooGaussian("g3","g3",*mass,*fgau3mean,*fgau3sigma);
  
    //crystal balls
    cb1_m0= new RooRealVar("cb1_m0","cb1_m0",2010.,2009.9,2010.9);
    cb1_sigma= new RooRealVar("cb1_sigma","cb1_sigma",1,0.01,10);
    cb1_alpha= new RooRealVar("cb1_alpha","cb1_alpha",-0.2, -10.,0.);//tail on the right
    cb1_n= new RooRealVar("cb1_n","cb1_n",1,0.,10.);
    CBall1= new RooCBShape("CBall1","Crystal Ball 1",*mass,*cb1_m0,*cb1_sigma,*cb1_alpha,*cb1_n);
  
    cb2_m0= new RooRealVar("cb2_m0","cb2_m0",2010.,2009.9,2010.9);
    cb2_sigma= new RooRealVar("cb2_sigma","cb2_sigma",0.6,0.1,1.4);
    cb2_alpha= new RooRealVar("cb2_alpha","cb2_alpha",1,0.,10.);//tail on the left
    cb2_n= new RooRealVar("cb2_n","cb2_n",1,0.,10.);
    CBall2= new RooCBShape("CBall2","Crystal Ball 2",*mass,*cb2_m0,*cb2_sigma,*cb2_alpha,*cb2_n);

    //RBW
    rbw_m0= new RooRealVar("rbw_m0","",2010,2009,2012);
    rbw_sigma= new RooRealVar("rbw_sigma","",3,0.01,10);
    rbw_width = new RooRealVar("rbw_width","",83.3e-3);//MeV
    rbw= new RooRBW("rbw","",*mass,*rbw_m0,*rbw_width);
    eps_width=new RooRealVar ("eps_width","",0,-0.3,0.3);
    eps_mean=new RooRealVar ("eps_mean","",0,-3,3);
    res_mean1 = new RooRealVar("res_mean1","gaus resolution mean1",-0.00414);
    res_mean2 = new RooRealVar("res_mean2","gaus resolution mean2",-0.054);
    res_mean3 = new RooRealVar("res_mean3","gaus resolution mean3",-0.01306);
    res_width1 = new RooRealVar("res_width1","gaus resolution width1",0.2813/*,0.1,2.*/);
    res_width2 = new RooRealVar("res_width2","gaus resolution width2",0.6320/*,0.1,3.*/);
    res_width3 = new RooRealVar("res_width3","gaus resolution width3",0.157/*,0.1,4.*/);
    mean1sh = new RooFormulaVar("mean1sh","@0+@1",RooArgList(*res_mean1,*eps_mean));
    mean2sh= new RooFormulaVar("mean2sh","@0+@1",RooArgList(*res_mean2,*eps_mean));
    mean3sh= new RooFormulaVar("mean3sh","@0+@1",RooArgList(*res_mean3,*eps_mean));
    
    width1sh= new RooFormulaVar("width1sh","@0*(1+@1)",RooArgList(*res_width1,*eps_width));
    width2sh= new RooFormulaVar("width2sh","@0*(1+@1)",RooArgList(*res_width2,*eps_width));
    width3sh= new RooFormulaVar("width3sh","@0*(1+@1)",RooArgList(*res_width3,*eps_width));

    res_gau_1 = new RooGaussian("res_gau_1","",*mass,*mean1sh,*width1sh);
    res_gau_2 = new RooGaussian("res_gau_2","",*mass,*mean2sh,*width2sh);
    res_gau_3 = new RooGaussian("res_gau_3","",*mass,*mean3sh,*width3sh);

    res_frac1 = new RooRealVar("res_frac1","",0.594);
    res_frac2 = new RooRealVar("res_frac2","",0.405);
    
    //Zach's RBW (X) Gaussian
    Rcp1 = new RooCarolP3("Rcp1","",*mass,*rbw_m0,*rbw_width,*mean1sh,*width1sh);
    Rcp2 = new RooCarolP3("Rcp2","",*mass,*rbw_m0,*rbw_width,*mean2sh,*width2sh);
    Rcp3 = new RooCarolP3("Rcp3","",*mass,*rbw_m0,*rbw_width,*mean3sh,*width3sh);
    //rcp3_mean= new RooRealVar("rcp3_mean","",2010,xmin,2015);
    //rcp3_width= new RooRealVar("rcp3_width","",1,0.1,10);
    //rcp3_gmean= new RooRealVar("rcp3_gmean","",2010,xmin,2015);
    //rcp3_gsigma= new RooRealVar("rcp3_gsigma","",1,0.1,10);
    
    //Rcp3 = new RooCarolP3("Rcp3","",*mass,*rcp3_mean,*rcp3_width,*rcp3_gmean,*rcp3_gsigma);
    //decay in flight shape
    decay_in_flight_kappa = new RooRealVar("decay_in_flight_kappa","decay in flight kappa", -3.0189e02);
    decay_in_flight_n = new RooRealVar("decay_in_flight_n","decay in flight n",1.3477);
    decay_in_flight_endpt = new RooRealVar("decay_in_flight_endpt","endpoint for decay in flight",(d0_mass_pdg+pion_mass_pdg));
    frac_dif = new RooRealVar("frac_dif","fraction of decay in flight candidates",0.00256345, 0.00256345-0.0005,0.00256345+0.0005);//taken from mc.
    cout<<"constructing new workspace for fits"<<endl;
    new_fit = new RooWorkspace(channel+"w",channel+"workspace");
 
    // ---Make Background variables ---
    //Empirical \delta m function
    xscale= new RooRealVar("xscale","xscale",1);
    endpt= new RooRealVar("endpt","argpar2",(d0_mass_pdg+pion_mass_pdg),xmin-0.2,xmin+0.2);
    minusDM= new RooFormulaVar("minusDM", "@2-@1*(@0-@2)", RooArgList(*mass, *xscale, *endpt));
    kappa= new RooRealVar("kappa", "argpar1", -3.8935e+01, -100, 20);
    n= new RooRealVar("n", "", 0.5, 0.4, 0.9);
    //n->setConstant(kTRUE);
    bkg_arg= new RooArgusBG("bkg", "argus_bkg",* minusDM, *endpt, *kappa, *n);
    nsig= new RooRealVar("nsig", "nsig", 9e6, 0, 1e10);
    frac1= new RooRealVar("frac1", "frac1", .6,0.,1);
    frac2= new RooRealVar("frac2", "frac2", .1,0,1);
    frac3= new RooRealVar("frac3", "frac3", .1,0,1);
    nbkg= new RooRealVar("nbkg", "", 1e3,0, 1e8);
    //minus dm is now defined. We can do the other argus for decay in flight 
    decay_in_flight_shape = new RooArgusBG("decay_in_flight_shape","decay in flight shape",*minusDM,*decay_in_flight_endpt,*decay_in_flight_kappa,*decay_in_flight_n);
   
  } 

}
//=============================================================================
// Destructor
//=============================================================================
// massFit::~massFit(){
//   //delete existing_fit;
  
//   //delete new_fit;
//   delete mass;
//   delete dmean;
//   delete rsigma;

//   delete m0;
//   delete fm0;
//   delete delta;
//   delete sigma;
//   delete fsigma;
//   delete gamma;
//   delete sig_john;
//   delete mean1;

//   delete fgau1mean;
//   delete mean2;
//   delete fgau2mean;
//   delete mean3;
//   delete fgau3mean;
  
//   delete width1;
//   delete fgau1sigma;
//   delete width2;
//   delete fgau2sigma;
//   delete width3;
//   delete fgau3sigma;
  
  
//   delete g1;
//   delete g2;
//   delete g3;
  

//   delete cb1_m0;
//   delete cb1_sigma;
//   delete cb1_alpha;
//   delete cb1_n;
//   delete CBall1;
  
//   delete cb2_m0;
//   delete cb2_sigma;
//   delete cb2_alpha;
//   delete cb2_n;
//   delete CBall2;

//   delete rbw_m0;
//   delete rbw_sigma;
//   delete rbw_width;
//   delete res_mean1;
//   delete res_mean2;
//   delete res_mean3;
//   delete res_width1;
//   delete res_width2;
//   delete res_width3;
//   delete res_frac1;
//   delete res_frac2;
//   delete eps_width;
//   delete eps_mean;
//   delete res_gau_1;
//   delete res_gau_2;
//   delete res_gau_3;
//   delete rbw;
//   delete mean1sh;
//   delete mean2sh;
//   delete mean3sh;
//   delete width1sh;
//   delete width2sh;
//   delete width3sh;

//   delete Rcp1;
//   delete Rcp2;
//   delete Rcp3;

//   delete decay_in_flight_kappa;
//   delete decay_in_flight_n;
//   delete decay_in_flight_endpt;
//   delete decay_in_flight_shape;
//   delete frac_dif;

//   delete xscale;
//   delete endpt;
//   delete minusDM;
//   delete kappa;
//   delete n;
//   delete bkg_arg;
//   delete nsig;
//   delete frac1;
//   delete frac2;
//   delete frac3;
//   delete nbkg;

//   delete sigpdf;
//   delete data;
//   delete model;

// }


//=============================================================================

void massFit::setData(TH1*data_hist){
  data = new RooDataHist("dm_data",channel+"dm_data",*mass,data_hist);
  return;
}
void massFit::initModelValues(){
  if(!use_existing_fit){
    cout<<"No existing fit, making fit model"<<endl;
    
    dmean->setConstant(1);
    rsigma->setConstant(1);//set as fixed by default, to unsed, use FloatMeanWidth
    endpt->setConstant(1);
    cout<<"endpt->getVal() = "<<endpt->getVal()<<endl;
    
    kappa->setVal(-2.3090e+01);
    //n->setConstant(1);
    bkg_arg->forceNumInt(kTRUE);
    //now make the signal and total models.
    if(modelName== "j2g")
      sigpdf = new RooAddPdf("sigpdf","",RooArgList(*sig_john,*g1,*g2),
                             RooArgList(*frac1,*frac2),kTRUE);//recursive fraction
    else if(modelName== "cb2g")
      sigpdf= new RooAddPdf("sigpdf","",RooArgList(*CBall1,*g1,*g2),
                            RooArgList(*frac1,*frac2),kTRUE);
    else if(modelName== "2cb")
      sigpdf =new RooAddPdf("sigpdf","",RooArgList(*CBall1,*CBall2),
                            RooArgList(*frac1),kTRUE);
    else if(modelName=="3g")
      sigpdf = new RooAddPdf("sigpdf","",RooArgList(*g1,*g2,*g3),
                             RooArgList(*frac1,*frac2),kTRUE);    
    else if(modelName=="rbw"){
      RooAbsPdf* res_model = new RooAddPdf("res_model","",RooArgList(*res_gau_1,*res_gau_2,*res_gau_3),
					   RooArgList(*res_frac1,*res_frac2),kTRUE);
      sigpdf = new RooFFTConvPdf("sigpdf","",*mass,*rbw,*res_model);
      //sigpdf = (RooAbsPdf*)rbw;
      
      //sigpdf->Print("v");
    }
    else if (modelName=="rcp3"){
      //sigpdf=Rcp3;
      //triple gaussian convolved with RBW= sum of gaus(x)rbw
      //with decay in flight component.
      //RooAbsPdf* sig_convolution = new RooAddPdf("sig_convolution","",RooArgList(*Rcp1,*Rcp2,*Rcp3),RooArgList(*res_frac1,*res_frac2),kTRUE);
      //sigpdf = new RooAddPdf("sigpdf","",RooArgList(*decay_in_flight_shape,*sig_convolution),RooArgList(*frac_dif));
      sigpdf = new RooAddPdf("sigpdf","",RooArgList(*Rcp1,*Rcp2,*Rcp3),RooArgList(*res_frac1,*res_frac2),kTRUE);

    }

    else if(modelName=="2g")
      sigpdf = new RooAddPdf("sigpdf","",RooArgList(*g1,*g2),
                             RooArgList(*frac1));
    else if(modelName=="1g")
      sigpdf = g1;
    //			  RooArgList(frac1),kTR);
    else
      sigpdf=new RooAddPdf("sigpdf","",RooArgList(*sig_john,*g1,*g2,*g3),
                           RooArgList(*frac1,*frac2,*frac3),kTRUE);//3g+j
   
    //draw the signal pdf alone to make sure things look reasonable.

    /*RooAbsPdf* */ model=new RooAddPdf("model","",RooArgList(*sigpdf,*bkg_arg),RooArgList(*nsig,*nbkg));
    
    model->Print("v");
    if(modelName=="rbw"){
      TCanvas *ctemp = new TCanvas();
      mass->setRange(-10,10);
	  
      RooPlot *temp = mass->frame();
      res_gau_1->plotOn(temp,LineColor(kRed));
      res_gau_2->plotOn(temp,LineColor(kOrange+1));
      res_gau_3->plotOn(temp,LineColor(kGreen+2));
      /*
	model->plotOn(temp);
	model->plotOn(temp,Components(*rbw),LineColor(kGreen+2),LineStyle(kDashed));
	model->plotOn(temp,Components(*res_gau_1),LineColor(kRed),LineStyle(kDashed));
	model->plotOn(temp,Components(*res_gau_2),LineColor(kOrange+1),LineStyle(kDashed));
	model->plotOn(temp,Components(*res_gau_3),LineColor(kGreen+2),LineStyle(kDashed));
      */
      temp->Draw();
      /*    ctemp->SaveAs("./SavedFits/RBW_conv_3gau_model.pdf");
	    ctemp->SetLogy(true);
	    ctemp->SaveAs("./SavedFits/RBW_conv_3gau_model_logy.pdf");
	    ctemp->SetLogy(false);*/
      ctemp->SaveAs("./SavedFits"+theLocalDir+"/resolution_function.pdf");
      ctemp->SetLogy(true);
      ctemp->SaveAs("./SavedFits/"+theLocalDir+"resolution_function_logy.pdf");
      ctemp->SetLogy(false);
      mass->setRange(xmin,2050);
      temp = mass->frame();
      rbw->plotOn(temp);
      temp->Draw();
      ctemp->SaveAs("./SavedFits/"+theLocalDir+"RBW.pdf");
      ctemp->SetLogy(true);
      ctemp->SaveAs("./SavedFits/"+theLocalDir+"RBW_logy.pdf");
      ctemp->SetLogy(false);
      delete ctemp;
      delete temp;
      //    assert(0);

    }
    if(modelName=="rcp3"){
      TCanvas *ctemp = new TCanvas();
      RooPlot *temp = mass->frame();
      
      model->plotOn(temp);
      //model->plotOn(temp,Components(*decay_in_flight_shape),LineColor(kMagenta+2),LineStyle(kDotted));
      model->plotOn(temp,Components(*Rcp1),LineColor(kGreen+2),LineStyle(kDashed));
      model->plotOn(temp,Components(*Rcp2),LineColor(kRed),LineStyle(kDashed));
      model->plotOn(temp,Components(*Rcp3),LineColor(kOrange+1),LineStyle(kDashed));

      //model->plotOn(temp,Components(*res_gau_3),LineColor(kGreen+2),LineStyle(kDashed));
      
      temp->Draw();
      ctemp->SaveAs("./SavedFits/"+theLocalDir+"Rcp3_conv_3gau_model.pdf");
      ctemp->SetLogy(true);
      ctemp->SaveAs("./SavedFits/"+theLocalDir+"Rcp3_conv_3gau_model_logy.pdf");
      ctemp->SetLogy(false);
      delete ctemp;
      delete temp;
      //assert(0);

    }
    
   
  }
  else{
    //get all the variables from the existing fit. and make sure to fix the signal components.
    cout<<"Using values from existing fit and fixing the values"<<endl;
    
    //TODO: Implement this.
  }
  
  return;
}

void massFit::FloatMeanWidth(){
  dmean->setConstant(0);
  rsigma->setConstant(0);
}

void massFit::fit(){
  
  RooFitResult* res = model->fitTo(*data,Save(),Minos(1),Extended(1),NumCPU(20));
  res->Print("v");
  /*
  cout<<"res->covQual() = "<<res->covQual()<<endl;
  cout<<"res->status() = "<<res->status()<<endl;
  cout<<"number of statuses to check = "<<res->numStatusHistory()<<endl;
  for(int i=0; i<res->numStatusHistory();++i){
    cout<<"for step "<<i<<", "<<res->statusLabelHistory(i)<<" returns "<<res->statusCodeHistory(i)<<endl;
    if(!res->statusCodeHistory(i)==0){
      //assert(0);
    };//make sure things have returned normally
  }
  */
  
  //ensure convergence and good covariance matrix.
  
  return;
  
}

void massFit::saveFinalFit(){
  new_fit->import(*model);
  new_fit->saveSnapshot(channel+modelName+"Snapshot",* (model->getParameters(*mass)),kTRUE);
  new_fit->writeToFile("./SavedFits/"+theLocalDir+"/"+channel+"_"+modelName+"fitModel.root");
}

void massFit::saveUpdatedFinalFit(){
  cout<<"updating final fit!"<<endl;
  dmean->setConstant(1);
  rsigma->setConstant(1);
  new_fit = new RooWorkspace(channel+"w",channel+"Updatedworkspace");
  new_fit->import(*model);
  new_fit->saveSnapshot(channel+modelName+"Snapshot",* (model->getParameters(*mass)),kTRUE);
  new_fit->writeToFile("./SavedFits/"+theLocalDir+"/"+channel+"_"+modelName+"UpdatedfitModel.root");
}


void massFit::savePlots(bool doPullPlots, TString extraName, bool normalized){
  TCanvas *cc = new TCanvas();
  RooPlot* frame = mass->frame();
  mass->setRange("r1",xmin,xmax);
  data->plotOn(frame);
  frame->Draw();
  model->plotOn(frame,Range("r1"));
  model->plotOn(frame,Components(*bkg_arg),LineStyle(kDashed),Range("r1"));
  //model->plotOn(frame,Components("bkg"),LineStyle(kDashed));
   
   if(modelName=="j2g")
     {
       model->plotOn(frame,Components(*sig_john),LineColor(kGreen+2),LineStyle(kDashed),Range("r1"));
       model->plotOn(frame,Components(*g1),LineColor(kRed),LineStyle(kDashed),Range("r1"));
       model->plotOn(frame,Components(*g2),LineColor(kOrange+1),LineStyle(kDashed),Range("r1"));
     }
   else if(modelName=="cb2g"){
     model->plotOn(frame,Components(*CBall1),LineColor(kGreen+2),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*g1),LineColor(kRed),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*g2),LineColor(kOrange+1),LineStyle(kDashed),Range("r1"));
   }
   
   else if(modelName=="2cb"){
     model->plotOn(frame,Components(*CBall1),LineColor(kGreen+2),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*CBall2),LineColor(kRed),LineStyle(kDashed),Range("r1"));
     
   }
   else if(modelName=="3g"){
       model->plotOn(frame,Components(*g1),LineColor(kRed),LineStyle(kDashed),Range("r1"));
       model->plotOn(frame,Components(*g2),LineColor(kOrange+1),LineStyle(kDashed),Range("r1"));
       model->plotOn(frame,Components(*g3),LineColor(kGreen+2),LineStyle(kDashed),Range("r1"));
   }
   else if(modelName=="2g"){
       model->plotOn(frame,Components(*g1),LineColor(kRed),LineStyle(kDashed),Range("r1"));
       model->plotOn(frame,Components(*g2),LineColor(kOrange+1),LineStyle(kDashed),Range("r1"));
   }
   else if(modelName=="1g"){
     model->plotOn(frame,LineColor(kRed),LineStyle(kDashed),Range("r1"));
   }
   else if(modelName=="rbw"){
     model->plotOn(frame,Components(*rbw),LineColor(kGreen+2),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*res_gau_1),LineColor(kRed),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*res_gau_2),LineColor(kOrange+1),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*res_gau_3),LineColor(kGreen+2),LineStyle(kDashed),Range("r1"));
     //model->plotOn(frame,Components(*g1),LineColor(kRed),LineStyle(kDashed),Range("r1"));
   }   
   else if(modelName=="rcp3"){
     model->plotOn(frame,Components(*Rcp1),LineColor(kGreen+2),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*Rcp2),LineColor(kRed),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*Rcp3),LineColor(kOrange+1),LineStyle(kDashed),Range("r1"));
     
     //model->plotOn(frame,Components(*Rcp3),LineColor(kGreen+2),LineStyle(kDashed),Range("r1"));
     //     model->plotOn(frame,Components(g1),LineColor(kRed),LineStyle(kDashed),Range("r1"));
   }
   else{
     model->plotOn(frame,Components(*sig_john),LineColor(kGreen+2),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*g1),LineColor(kRed),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*g2),LineColor(kOrange+1),LineStyle(kDashed),Range("r1"));
     model->plotOn(frame,Components(*g3),LineColor(kMagenta+1),LineStyle(kDashed),Range("r1"));
   }
   //frame->GetYaxis()->SetRangeUser(0,250);
   frame->Draw();
   //frame->GetYaxis()->SetTitleOffset(1.4);
   TPaveText *txt;
   if(addSigBox){
     txt = new TPaveText(0.7, 0.8, 0.98, 0.98, "ndc");
     txt->SetTextAlign(12);
     txt->AddText(Form("N_{Signal} = %d #pm %d",(int)nsig->getVal(),(int)nsig->getError()));
     txt->Draw();
   }
   cc->SaveAs("./SavedFits/"+theLocalDir+"/"+channel+extraName+modelName+"_fit.pdf");
   cc->SetLogy(true);
   frame->GetYaxis()->SetRangeUser(1, frame->GetMaximum()*1.5);
   frame->Draw();
   if(addSigBox){txt->Draw();}
   cc->SaveAs("./SavedFits/"+theLocalDir+"/"+channel+extraName+modelName+"_fit_logy.pdf");
   cc->SetLogy(false);
   cc->Clear();
   if(doPullPlots){
     
     TString liang_save_name = "./SavedFits/"+theLocalDir+"/RS_fit_pulls"+extraName+channel;
     PlottingTools::makeResidualPlotsLiang(frame,*mass,*data, model,liang_save_name.Data(),2000./*pion_mass_pdg+d0_mass_pdg*/,2025,normalized
					   
					   );
     //TString nameforshow = "./SavedFits/"+theLocalDir+"/"+extraName+channel+modelName+"pulls_other_method";
     //PlottingTools::showPlot(*mass,*data,model,nameforshow.Data(),"m(D^{0}#pi_{S}");
   }
   return;
}

void massFit::saveSignalRegionZoom(){
  mass->setRange("sig",2009.5,2010.9);
  RooPlot *framesig = mass->frame();
  data->plotOn(framesig,Range("sig"));
  model->plotOn(framesig,Range("sig"));
  framesig->GetXaxis()->SetRangeUser(2009.5,2010.9);
  TCanvas* cc2 = new TCanvas();
  framesig->Draw();
  cc2->SaveAs("SavedFits/"+theLocalDir+"/Augusto_SigCheck.pdf");
  cc2->SetLogy(true);
  cc2->SaveAs("SavedFits/"+theLocalDir+"/Augusto_SigCheck_logy.pdf");
  cc2->SetLogy(false);
  
}
void massFit::Reset(){
  data = NULL;
  model = NULL;
  dmean = NULL;
  rsigma= NULL;
  nsig = NULL;
  sigpdf = NULL;
  bkg_arg=  NULL;
  existing_fit = NULL;
}

void massFit::initValsByHand(array<double,4> thePars){
  /*
NO.   NAME      VALUE            ERROR       STEP SIZE       VALUE
   1  dmean        2.55303e-03   8.90426e-04   1.88402e-04   2.55303e-03
   2  kappa       -2.73131e+01   1.87980e+00   5.21041e-04   2.13057e-01
   3  n            6.90967e-01   1.46323e-02   8.52096e-04   3.08074e-01
   4  nbkg         8.37522e+04   3.26489e+02   4.56050e-06  -1.51291e+00
   5  nsig         1.63165e+05   4.31284e+02   2.19935e-06  -1.56272e+00
   6  rsigma       7.27422e-02   3.16079e-03   6.38629e-06   3.63712e-03
   */
  dmean->setVal(0.);
  cout<<"Setting Kappa to "<<thePars[0]<<endl;
  kappa->setVal(thePars[0]);
  cout<<"setting n to "<<thePars[1]<<endl;
  n->setVal(thePars[1]);
  nbkg->setVal(thePars[2]);
  nsig->setVal(thePars[3]);
  rsigma->setVal(0.);

}



