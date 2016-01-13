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
const double d0_mass_pdg =1864.84;
int main(int argc, char* const argv[]){
  PlottingTools::setLHCbcanvas();
  cout<<"Fitting D0 mass distribution"<<endl;
  if(argc<2){
    cout<<"*************************************"<<endl;
    cout<<"Expecting an external file to process"<<endl;
    cout<<"*************************************"<<endl;
    return 0;
  }

  cout<<"argv[1]="<<argv[1]<<endl;
  cout<<"making directory."<<endl;
  TFile f1(argv[1]);
  //  TH1D* d0m = (TH1D*)f1.Get("RS_dt_d0_m_sig_rej");
  //TH1D* d0mb = (TH1D*)f1.Get("RS_ss_dt_d0_m_sig_rej");
  TH1D* d0m = (TH1D*)f1.Get("RS_dt_d0_m");
  TH1D* d0mb = (TH1D*)f1.Get("RS_ss_dt_d0_m");
  d0m->Sumw2();
  d0mb->Sumw2();
  d0m->Add(d0mb,-1);
  TString localDir = "D0MassFits/";
  TString d2make = "./SavedFits/"+localDir;
  umask(0);
  mkdir(d2make.Data(),0755);
  //draw the d0 ranges for betastar
  TLine l1(1790,0,1790,d0m->GetMaximum()*1.02);
  TLine l2(1795.8,0,1795.8,d0m->GetMaximum()*1.02);
  TLine l3(1801.6,0,1801.6,d0m->GetMaximum()*1.02);
  TLine l4(1807.4,0,1807.4,d0m->GetMaximum()*1.02);
  TLine l5(1813.2,0,1813.2,d0m->GetMaximum()*1.02);
  TLine l6(1819,0,1819,d0m->GetMaximum()*1.02);
  TLine l7(1824.84,0,1824.84,d0m->GetMaximum()*1.02);

  TLine l8(1904.84,0,1904.84,d0m->GetMaximum()*1.02);
  TLine l9(1911.,0.,1911.,d0m->GetMaximum()*1.02);
  TLine l10(1916.8,0.,1916.8,d0m->GetMaximum()*1.02);
  TLine l11(1922.6,0,1922.6,d0m->GetMaximum()*1.02);
  TLine l12(1928.4,0,1928.4,d0m->GetMaximum()*1.02);
  TLine l13(1934.2,0,1934.2,d0m->GetMaximum()*1.02);
  TLine l14(1940,0,1940,d0m->GetMaximum()*1.02);
  std::vector<TLine>lines;
  lines.push_back(l1);
  lines.push_back(l2);
  lines.push_back(l3);
  lines.push_back(l4);
  lines.push_back(l5);
  lines.push_back(l6);
  lines.push_back(l7);
  lines.push_back(l8);
  lines.push_back(l9);
  lines.push_back(l10);
  lines.push_back(l11);
  lines.push_back(l12);
  lines.push_back(l13);
  lines.push_back(l14);
  TCanvas *can = new TCanvas();
  d0m->Draw();
  for(unsigned int i=0; i<lines.size();++i){
    lines[i].SetLineColor(kRed);
    lines[i].SetLineStyle(kDashed);
    //line[i].SetLineWidth(2);
    lines[i].Draw("same");
  }
  can->SaveAs("./SavedFits/D0MassFits/d0_sidebands_def.pdf");
  can->SetLogy(true);
  can->SaveAs("./SavedFits/D0MassFits/d0_sidebands_def_logy.pdf");
  can->SetLogy(false);
  delete can;
  //build model. double gaussian + exponential
  RooRealVar mass("d0m","m(K#pi)", d0_mass_pdg-100,d0_mass_pdg+100,"MeV");
  mass.setRange("r1",d0_mass_pdg-75,d0_mass_pdg+75);
  //a guess
  /*
  EXT PARAMETER                  PARABOLIC         MINOS ERRORS        
  NO.   NAME      VALUE            ERROR      NEGATIVE      POSITIVE   
   1  c           -1.55464e-02   3.54365e-04  -3.50254e-04   3.44812e-04
   2  frac         8.50459e-01   3.31785e-03  -3.42377e-03   3.23592e-03
   3  frac_sig     9.76056e-01   4.01464e-04  -4.05642e-04   3.94849e-04
   4  mean1        1.86643e+03   1.01258e-02  -1.09272e-02   1.10587e-02
   5  mean2        1.86347e+03   8.91896e-02  -8.92859e-02   8.96278e-02
   6  width1       7.25918e+00   1.65679e-02  -1.71181e-02   1.65032e-02
   7  width2       1.50891e+01   1.26680e-01  -1.27577e-01   1.25227e-01
   */
  RooRealVar mean1("mean1","mean1",1864.84,d0_mass_pdg-10,d0_mass_pdg+10);
  RooRealVar mean2("mean2","mean2",1864.84,d0_mass_pdg-10,d0_mass_pdg+10);
  RooRealVar mean3("mean3","mean3",1864.84,d0_mass_pdg-10,d0_mass_pdg+10);
  RooRealVar width1("width1","width1",5.,0.1,14.);
  RooRealVar width2("width2","width2",8.,0.1,20.);
  RooRealVar width3("width3","width3",8.,0.1,25.);
  RooGaussian g1("g1","g1",mass,mean1,width1);
  RooGaussian g2("g2","g2",mass,mean2,width2);
  RooGaussian g3("g3","g3",mass,mean3,width3);
  RooRealVar frac("frac","frac",0.5,0.,1.);
  RooRealVar frac2("frac2","frac2",0.2,0.,1.);
  RooAbsPdf *sig= new RooAddPdf("sig","",RooArgList(g1,g2,g3),RooArgList(frac,frac2));
  RooRealVar c("c","c",-0.5,-1.,-0.001);
  RooExponential *exp = new RooExponential("exp","exp",mass,c);
  RooRealVar frac_sig("frac_sig","frac_sig",0.5,0.1,1.);
  RooAbsPdf *model = new RooAddPdf("model","",RooArgList(*sig,*exp),RooArgList(frac_sig));
  RooDataHist *data = new RooDataHist("d0data","d0data",mass,d0m);
  //fit!
  RooFitResult* res = model->fitTo(*data,Range("r1"),Minos(1),Save());
  res->Print("V");
  //g1.fitTo(*data,Save(),Range(1864.84-70,1864.84+70));
  RooPlot* frame = mass.frame();
  
  TCanvas* cc = new TCanvas();
  data->plotOn(frame);
  model->plotOn(frame,Range("r1"));
  model->plotOn(frame,Components("g1"),LineColor(kRed),LineStyle(kDashed),Range("r1"));
  model->plotOn(frame,Components("g2"),LineColor(kMagenta),LineStyle(kDashed),Range("r1"));
  model->plotOn(frame,Components("g3"),LineColor(kGreen+2),LineStyle(kDashed),Range("r1"));
  model->plotOn(frame,Components("exp"),LineColor(kCyan+3),LineStyle(kDashed));
  frame->Draw();
  cc->SaveAs("./SavedFits/D0MassFits/fitted_d0_mass_distribution.pdf");
  cc->SetLogy(true);
  frame->GetYaxis()->SetRangeUser(1,1e5);
  gPad->Modified();
  gPad->Update();
  cc->SaveAs("./SavedFits/D0MassFits/fitted_d0_mass_distribution_logy.pdf");
  cc->SetLogy(false);
  //now that we have a fit that works, integrate the background in the sidebands and the signal.
  //This gives the overall scaling for the betastar plots.
  RooAbsReal* tot_bkg_int = exp->createIntegral(mass,NormSet(mass));
  mass.setRange("sb1",1790,1824.24);
  mass.setRange("sb2",1904.84,1940);
  mass.setRange("sig",1864.84-24,1864.84+24);
  RooAbsReal* sb_int = exp->createIntegral(mass,NormSet(mass),Range("sb1,sb2"));
  RooAbsReal* sig_int = exp->createIntegral(mass,NormSet(mass),Range("sig"));
  cout<<"ratio of signal to sidebands of background = "<<sig_int->getVal()/sb_int->getVal()<<endl;
  cout<<"total background integral = "<<tot_bkg_int->getVal();
  
  return 0;
}
