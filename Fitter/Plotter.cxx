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
#include <TMultiGraph.h>
#include <TGraphErrors.h>
#include <TFile.h>
Plotter::Plotter(TString name, WSFitter* fitter, int CPVType){
  _Fitter = fitter;
  _cpvType = CPVType;
  _name = name;
  _titleName = name;
  _titleName.ReplaceAll("/","_");
  gROOT->ProcessLine(".X /home/davis3a4/private/stye_file/lhcbStyle.C");
}

void Plotter::PlotXYContours(){
  if(_cpvType!=0) return;
  TCanvas cc("cc","cc",800,800);
  //central dot
  TMarker *m = new TMarker(_Fitter->Parameter(2),_Fitter->Parameter(1),20);
  TGraph* cont1sig = _Fitter->Contour(2,1);
  TGraph* cont2sig = _Fitter->Contour(2,1,0.9545);
  TGraph* cont3sig = _Fitter->Contour(2,1,0.9973,100);
  
  cont1sig->SetName(_titleName+"_1sigma_nocpv_contour");
  cont2sig->SetName(_titleName+"_2sigma_nocpv_contour");
  cont3sig->SetName(_titleName+"_3sigma_nocpv_contour");
  cont3sig->SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]");
  cont2sig->SetLineStyle(2);
  cont3sig->SetLineStyle(9);
  cont3sig->Draw("al");
  cont2sig->Draw("l same");
  cont1sig->Draw("l same");
  m->Draw("same");
  cc.SaveAs(_name+"noCPV_xy_contours.pdf");
  cc.SaveAs(_name+"noCPV_xy_contours.C");
  //cc.SaveAs(_name+"noCPV_xy_contours.root");
  TFile fout(_name+"noCPV_xy_contours.root","RECREATE");
  fout.cd();
  cont1sig->Write();
  cont2sig->Write();
  cont3sig->Write();
  m->Write();
  fout.Close();
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
  contPlus->SetName(_titleName+Form("_type%d_1sigma_plus_contour",_cpvType));
  contMins->SetName(_titleName+Form("_type%d_1sigma_minus_contour",_cpvType));
  contPlus->SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]");
  contPlus->SetLineColor(kBlue);mplus->SetMarkerColor(kBlue);
  contMins->SetLineColor(kRed);mmins->SetMarkerColor(kRed);
  //  contPlus->Draw();
  //  contMins->Draw("same");
  TMultiGraph *mg = new TMultiGraph();
  mg->Add(contPlus,"l");
  mg->Add(contMins,"l");
  mg->Draw("a");
  mg->SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]");
  cc.Update();
  mplus->Draw("same");
  mmins->Draw("same");
  cc.SaveAs(_name+"_xy_contours.pdf");
  cc.SaveAs(_name+"_xy_contours.C");
  //cc.SaveAs(_name+"_xy_contours.root");
  TFile fout(_name+"_xy_contours.root","RECREATE");
  fout.cd();
  contPlus->Write();
  contMins->Write();
  mplus->Write();
  mmins->Write();
  fout.Close();
  return;
}

void Plotter::PlotRatios(){
  // plot the time dependent ratio.
  TGraphErrors * thePosGraph = new TGraphErrors(5);
  TGraphErrors * theNegGraph = new TGraphErrors(5);  

  for(int i=0; i<5;++i){
    thePosGraph->SetPoint(i,_Fitter->Point(i,+1,true)->t,
			  _Fitter->Point(i,+1,true)->r()*1.e3);
    thePosGraph->SetPointError(i,0,_Fitter->Point(i,+1,true)->sr()*1e3);
						  
    theNegGraph->SetPoint(i,_Fitter->Point(i,-1,true)->t,
			  _Fitter->Point(i,-1,true)->r()*1e3);
    theNegGraph->SetPointError(i,0,_Fitter->Point(i,-1,true)->sr()*1e3);

  }
  //make variable bin width histograms for fit

  double theBinBoundaries[6]  = {-0.5,0.2,0.5,0.9,1.5,10};
  TH1D* theFitPos = new TH1D(_titleName+"theFitPos",_titleName+" Fit Pos",5,theBinBoundaries);
  TH1D* theFitNeg = new TH1D(_titleName+"theFitNeg",_titleName+" Fit Neg",5,theBinBoundaries);
  for(int i=0; i<5; ++i){
    //extract the fitted value.
    double RD_plus = _Fitter->Parameter(0)/1e3;
    double yprime_plus = _Fitter->Parameter(1)/1e3;
    double xprime2_plus = _Fitter->Parameter(2)/1e3;
    double RD_minus = RD_plus;
    if(_cpvType==2){ RD_minus=_Fitter->Parameter(3)/1e3;}
    double yprime_minus=yprime_plus;//
    if(_cpvType==1 || _cpvType==2){yprime_minus=_Fitter->Parameter(4)/1e3;}
    double xprime2_minus = xprime2_plus;
    if(_cpvType==1 || _cpvType==2){xprime2_minus= _Fitter->Parameter(5)/1e3;}
    //other shiz
    double eps_DT = (1.+_Fitter->Parameter(60))/(1.-_Fitter->Parameter(60));
    double fb = _Fitter->Parameter(61+i);
    double fp = _Fitter->Parameter(66);
    //plus or minus
    double tp = _Fitter->Point(i,+1,true)->t;
    double tp2 = _Fitter->Point(i,+1,true)->t2;
    double tm = _Fitter->Point(i,-1,true)->t;
    double tm2 = _Fitter->Point(i,-1,true)->t2;
    double Rp = RD_plus+sqrt(RD_plus)*yprime_plus*tp+(xprime2_plus+yprime_plus*yprime_plus)/4.*tp2;
    double deltaBp = fb*(1.-RD_plus/Rp);
    double funcp   = eps_DT*Rp*(1.-deltaBp)+fp;
    
    theFitPos->SetBinContent(i+1,funcp*1e3);

    double Rm = RD_minus+sqrt(RD_minus)*yprime_minus*tm+(xprime2_minus+yprime_minus*yprime_minus)/4.*tm2;
    double deltaBm = fb*(1.-RD_minus/Rm);
    double funcm   = Rm*(1.-deltaBm)/eps_DT+fp;
    
    theFitNeg->SetBinContent(i+1,funcm*1e3);
  }

  //
  theFitPos->SetLineColor(kBlue);
  theFitNeg->SetLineColor(kBlue);
  TCanvas cc("cc","cc",800,1200);
  thePosGraph->SetMarkerStyle(20);
  thePosGraph->SetMarkerColor(kBlack);
  thePosGraph->SetLineColor(kBlack);
  thePosGraph->SetTitle(";t/#tau;R^{+}[10^{-3}]");
  thePosGraph->SetName(_titleName+"r_plus_graph");
  thePosGraph->GetXaxis()->SetLimits(-0.5,10);
  
  theNegGraph->SetMarkerStyle(20);
  theNegGraph->SetMarkerColor(kBlack);
  theNegGraph->SetLineColor(kBlack);
  theNegGraph->SetTitle(";t/#tau;R^{-}[10^{-3}]");
  theNegGraph->SetName(_titleName+"r_mins_graph");
  theNegGraph->GetXaxis()->SetLimits(-0.5,10);
  cc.Divide(1,2);
  cc.cd(1);
  thePosGraph->Draw("ap");
  theFitPos->Draw("same");
  cc.cd(2);
  theNegGraph->Draw("ap");
  theFitNeg->Draw("same");
  cc.SaveAs(_name+"plus_and_mins_graph.pdf");
  TFile fout(_name+"plus_and_mins_graph.root", "RECREATE");
  fout.cd();
  thePosGraph->Write();
  theNegGraph->Write();
  theFitPos->Write();
  theFitNeg->Write();
  fout.Close();
  return;
    
}

#endif
