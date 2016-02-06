#ifndef Plotter_cxx
#define Plotter_cxx
#include <TDirectory.h>
#include <TRandom3.h>
#include <TMath.h>
#include <TMinuit.h>
#include <Math/QuantFuncMathCore.h>
#include <TAxis.h>
#include <algorithm>
#include <complex>
#include <TCanvas.h>
#include <TMarker.h>
#include "Plotter.h"
#include <TROOT.h>
Plotter::Plotter(TString name, WSFitter* fitter, int CPVType){
  _Fitter = fitter;
  _cpvType = CPVType;
  _name = name;
  gROOT->ProcessLine(".X /home/davis3a4/private/stye_file/lhcbStyle.C");
}

void Plotter::PlotXYContours(){
  if(_cpvType!=0) return;
  TCanvas cc("cc","cc",800,800);
  //central dot
  TGraph* cont1sig = _Fitter->Contour(2,1);
  TGraph* cont2sig = _Fitter->Contour(2,1,0.9545);
  TGraph* cont3sig = _Fitter->Contour(2,1,0.9973,100);
  cont3sig->SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]");
  cont2sig->SetLineStyle(2);
  cont3sig->SetLineStyle(9);
  cont3sig->Draw();
  cont2sig->Draw("same");
  cont1sig->Draw("same");
  TMarker *m = new TMarker(_Fitter->Parameter(2),_Fitter->Parameter(1),20);
  m->Draw("same");
  cc.SaveAs(_name+"noCPV_xy_contours.pdf");
  cc.SaveAs(_name+"noCPV_xy_contours.C");
  return;
}

void Plotter::PlotCPVContours(){
  //only ok for no DCPV and all CPV
  if(_cpvType==0)return;
  TCanvas cc("cc","cc",800,800);
  TMarker *mplus = new TMarker(_Fitter->Parameter(2),_Fitter->Parameter(1),20);
  TMarker *mmins = new TMarker(_Fitter->Parameter(5),_Fitter->Parameter(4),20);
  TGraph* contPlus = _Fitter->Contour(2,1);
  TGraph* contMins = _Fitter->Contour(5,4);
  contPlus->SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]");
  contPlus->SetLineColor(kBlue);mplus->SetMarkerColor(kBlue);
  contMins->SetLineColor(kRed);mmins->SetMarkerColor(kRed);
  contPlus->Draw();
  contMins->Draw("same");
  mplus->Draw("same");
  mmins->Draw("same");
  TString extraTitle =_cpvType==2? "allcpv":"noDCPV";
  cc.SaveAs(_name+extraTitle+"_xy_contours.pdf");
  cc.SaveAs(_name+extraTitle+"_xy_contours.C");
  return;
}

#endif
