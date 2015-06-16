// Include files 
#include <iostream>
#include <TCanvas.h>
#include <TPad.h>
#include <TFile.h>
#include <TStyle.h>
#include <TPaveText.h>
// local
#include "betastar_plot.h"
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
#include <RooWorkspace.h>
using namespace RooFit ;

//-----------------------------------------------------------------------------
// Implementation file for class : betastar_plot
//
// 2015-01-24 : Adam Davis
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
betastar_plot::betastar_plot(TString name  ) {
  m_name =name.ReplaceAll("/DecayTree","");
  std::cout<<"constructin betastar_plot with name "<<m_name<<std::endl;
  
   h2sig = new TH2D(name+"h2sig","",200,-1.,1.,200,1.2,2.0);
   h2kpisb = (TH2*)h2sig->Clone(name+"h2kpisb");
  
   h2kpisb_hi = (TH2*)h2sig->Clone(name+"h2kpisb_hi");
   h2kpisb_lo = (TH2*)h2sig->Clone(name+"h2kpisb_lo");
  
   h2kksb = (TH2*)h2sig->Clone(name+"h2kksb");
   h2pipisb = (TH2*)h2sig->Clone(name+"h2pipisb");
   h2piksb = (TH2*)h2sig->Clone(name+"h2piksb");
   h2rob = (TH2*)h2sig->Clone(name+"h2rob");
   h2kpisb_cut_range = (TH2*)h2sig->Clone(name+"h2kpisb_cut_range");
  
   h2pi_probnnmu_dstar_sideband_high = new TH2D(name+"h2pi_probnnmu_dstar_sideband_high","",100,0,1,250,2000,2025);
   h2pi_probnnmu_dstar_sideband_low=new TH2D(name+"h2pi_probnnmu_dstar_sideband_low","",100,0,1,250,2000,2025);
    
   h2k_probnnmu_dstar_sideband_high=new TH2D(name+"h2k_probnnmu_dstar_sideband_high","",100,0,1,250,2000,2025);
   h2k_probnnmu_dstar_sideband_low=new TH2D(name+"h2k_probnnmu_dstar_sideband_low","",100,0,1,250,2000,2025);    
  
   h2pi_probnne_dstar_sideband_high=new TH2D(name+"h2pi_probnne_dstar_sideband_high","",100,0,1,250,2000,2025);
   h2pi_probnne_dstar_sideband_low=new TH2D(name+"h2pi_probnne_dstar_sideband_low","",100,0,1,250,2000,2025);
  
   h2k_probnne_dstar_sideband_high=new TH2D(name+"h2k_probnne_dstar_sideband_high","",100,0,1,250,2000,2025);
   h2k_probnne_dstar_sideband_low=new TH2D(name+"h2k_probnne_dstar_sideband_low","",100,0,1,250,2000,2025);    
  
   hmsig = new TH1D(name+"hmsig","", 250, 2000, 2025);
   hmkpisb = (TH1*)hmsig->Clone(name+"hmkpisb");
   hmkksb = (TH1*)hmsig->Clone(name+"hmkksb");
   hmpipisb =(TH1*) hmsig->Clone(name+"hmpipisb");
   hmpiksb = (TH1*)hmsig->Clone(name+"hmpiksb");
   hmrob = (TH1*)hmsig->Clone(name+"hmrob");

   hmkpisb_cut_range = (TH1*)hmsig->Clone(name+"hmkpisb_cut_range");
   hmkpisb_cut_range_hi = (TH1*)hmsig->Clone(name+"hmkpisb_cut_range_hi");
   hmkpisb_cut_range_lo = (TH1*)hmsig->Clone(name+"hmkpisb_cut_range_lo");

   hmkpisb_cut_range_hi_1 = (TH1*)hmsig->Clone(name+"hmkpisb_cut_range_hi_1");//40-52
   hmkpisb_cut_range_lo_1 = (TH1*)hmsig->Clone(name+"hmkpisb_cut_range_lo_1");//40-52

   hmkpisb_cut_range_hi_2 = (TH1*)hmsig->Clone(name+"hmkpisb_cut_range_hi_2");//52-64
   hmkpisb_cut_range_lo_2 = (TH1*)hmsig->Clone(name+"hmkpisb_cut_range_lo_2");//52-64

    
    
   hmD0_pik_sig = new TH1D(name+"hmD0_pik_sig","D^{0}->#pi K mass, #Delta M signal range; m(#pi K)[MeV];",200, 1700,2100);
   hmD0_pik_sb = new TH1D(name+"hmD0_pik_sb","D^{0}->#pi K mass, #Delta M sideband; m(#pi K)[MeV];",200, 1700,2100);
   hmD0_pik_tot = new TH1D(name+"hmD0_pik","D^{0}->#pi K mass, #Delta M unaltered; m(#pi K)[MeV];",200, 1700,2100);

}
//=============================================================================
// Destructor
//=============================================================================
betastar_plot::~betastar_plot() {} 

//=============================================================================
//Draw the plots and save them.
//=============================================================================
void betastar_plot::DrawPlots(){
  
    TCanvas * cc = new TCanvas();
    hmsig->Draw();
    cc->SaveAs("kpi_signal_region.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kpi_signal_region_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();

    hmkpisb->Draw();
    cc->SaveAs("kpi_sideband_region.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kpi_sideband_region_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();

    hmkpisb_cut_range->Draw();
    cc->SaveAs("kpi_sideband_region_cut_range.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kpi_sideband_region_cut_range_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();


    hmkksb->Draw();
    cc->SaveAs("kk_signal_kpi_sideband_region.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kk_signal_kpi_sideband_region_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();


    hmpipisb->Draw();
    cc->SaveAs("pipi_signal_kpi_sideband_region.pdf");
    cc->SetLogy(true);
    cc->SaveAs("pipi_signal_kpi_sideband_region_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();
            

    hmpiksb->Draw();
    cc->SaveAs("pik_signal_kpi_sideband_region.pdf");
    cc->SetLogy(true);
    cc->SaveAs("pik_signal_kpi_sideband_region_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();

    hmrob->Draw();
    cc->SaveAs("kpi_not_signal_region.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kpi_not_signal_region_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();
    
    //if(doD0plots){
      hmD0_pik_tot->Draw();
      cc->SaveAs("pi_k_d0mass_total.pdf");
      cc->SetLogy(true);
      cc->SaveAs("pi_k_d0mass_total_logy.pdf");
      cc->SetLogy(false);
      cc->Clear();
      
      hmD0_pik_sig->Draw();
      cc->SaveAs("pi_k_d0mass_signal_dstar.pdf");
      cc->SetLogy(true);
      cc->SaveAs("pi_k_d0mass_signal_dstar_logy.pdf");
      cc->SetLogy(false);
      cc->Clear();
      
      
      hmD0_pik_sb->Draw();
      cc->SaveAs("pi_k_d0mass_sideband_dstar.pdf");
      cc->SetLogy(true);
      cc->SaveAs("pi_k_d0mass_sideband_dstar_logy.pdf");
      cc->SetLogy(false);
      cc->Clear();
      //}
    
    hmkpisb_cut_range_hi->Draw();
    cc->SaveAs("kpi_sideband_region_hi.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kpi_sideband_region_hi_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();

    hmkpisb_cut_range_lo->Draw();
    cc->SaveAs("kpi_sideband_region_lo.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kpi_sideband_region_lo_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();

    hmkpisb_cut_range_hi_1->Draw();
    cc->SaveAs("kpi_sideband_region_hi_1.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kpi_sideband_region_hi_1_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();

    hmkpisb_cut_range_hi_2->Draw();
    cc->SaveAs("kpi_sideband_region_hi_2.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kpi_sideband_region_hi_2_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();
    

    hmkpisb_cut_range_lo_1->Draw();
    cc->SaveAs("kpi_sideband_region_lo_1.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kpi_sideband_region_lo_1_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();

    hmkpisb_cut_range_lo_2->Draw();
    cc->SaveAs("kpi_sideband_region_lo_2.pdf");
    cc->SetLogy(true);
    cc->SaveAs("kpi_sideband_region_lo_2_logy.pdf");
    cc->SetLogy(false);
    cc->Clear();    

    delete cc;

    TFile *the_outfile = new TFile("./betastar_sidebands.root","RECREATE");
    the_outfile->cd();
    h2sig->Write();
    h2kpisb->Write();
    h2kksb->Write();
    h2pipisb->Write();
    h2piksb->Write();
    h2rob->Write();
    h2kpisb_cut_range->Write();
    h2pi_probnnmu_dstar_sideband_high->Write();
    h2pi_probnnmu_dstar_sideband_low->Write();
    h2k_probnnmu_dstar_sideband_high->Write();
    h2k_probnnmu_dstar_sideband_low->Write();
    h2pi_probnne_dstar_sideband_high->Write();
    h2pi_probnne_dstar_sideband_low->Write();
    h2k_probnne_dstar_sideband_high->Write();
    h2k_probnne_dstar_sideband_low->Write();
    h2kpisb_hi->Write();
    h2kpisb_lo->Write();
    
    
    
    hmsig->Write();
    hmkpisb->Write();
    hmkksb->Write();
    hmpipisb->Write();
    hmpiksb->Write();
    hmrob->Write();
    hmkpisb_cut_range->Write();
    hmD0_pik_tot->Write();
    hmD0_pik_sig->Write();
    hmD0_pik_sb->Write();
    hmkpisb_cut_range_hi->Write();
    hmkpisb_cut_range_lo->Write();
    hmkpisb_cut_range_hi_1->Write();
    hmkpisb_cut_range_lo_1->Write();
    hmkpisb_cut_range_hi_2->Write();
    hmkpisb_cut_range_lo_2->Write();
    

    the_outfile->Close();
    

    h2sig->SetMarkerColor(kGreen+2);
    h2kpisb->SetMarkerColor(kRed);
    h2kksb->SetMarkerColor(kYellow+1);
    h2pipisb->SetMarkerColor(kBlue);
    h2piksb->SetMarkerColor(kMagenta);
    hmsig->SetLineColor(kGreen+2);
    hmkpisb->SetLineColor(kRed);
    hmkksb->SetLineColor(kYellow+1);
    hmpipisb->SetLineColor(kBlue);
    hmpiksb->SetLineColor(kMagenta);
    hmkpisb->SetLineColor(kRed);
    /*    hmkksb->SetLineColor(kYellow+1);
    hmpipisb->SetLineColor(kBlue);
    hmpiksb->SetLineColor(kMagenta);*/
    //setcanvas();
    gStyle->SetOptStat(00);
    gStyle->SetTitleOffset(1.4,"y");
    TCanvas *cv = new TCanvas("cv", "", 1200, 400*3);
    cv->Divide(2,3);
    cv->cd(1);
    h2sig->Draw();
    h2rob->Draw("same");
    h2kpisb->Draw("same");
    cv->cd(2);
    h2sig->Draw();
    h2rob->Draw("same");
    h2kksb->Draw("same");
    h2pipisb->Draw("same");
    h2piksb->Draw("same");
    
    TPad* pad = (TPad*)cv->cd(3);
    pad->SetLogy(1);
    if(w_local!=NULL){makefitplot(w_local, hmsig, hmkpisb);}
    else{  
      hmsig->Draw("e");
      hmkpisb->Draw("esame");
    }
    cv->cd(4);
    if(w_local!=NULL){makefitplot(w_local, hmpiksb);}
    else{hmpiksb->Draw("e");}
    //
    cv->cd(5);
    if(w_local!=NULL){makefitplot(w_local, hmkksb,1);}
    else{hmkksb->Draw("e");}
    //
    cv->cd(6);
    if(w_local!=NULL){makefitplot(w_local, hmpipisb,1);}
    else{hmpipisb->Draw("e");}
    
    //

    cv->SaveAs("rs_betastar_figure.pdf");
    
    return;

    
}

void betastar_plot::makefitplot(RooWorkspace*w, TH1* h1, TH1* h2){
  RooRealVar *mass = w->var("mass"); 
  RooRealVar *nsig = w->var("nsig");
  RooRealVar *kappa = w->var("kappa");
  kappa->setConstant(0);
  RooRealVar *pn = w->var("n");
  pn->setConstant(1);
  RooRealVar *endpt = w->var("endpt");
  RooRealVar *dmean = w->var("dmean");
  RooRealVar *rsigma = w->var("rsigma");
  dmean->setConstant(1); rsigma->setConstant(1);
  RooAbsPdf* allpdf = w->pdf("model");
  TString rhname("r_"); rhname += h1->GetName();
  RooDataHist *rhist = new RooDataHist(rhname.Data(), "", *mass, h1);
  RooFitResult *res = allpdf->fitTo(*rhist, RooFit::Save());
  res->Print("v");
  RooAbsPdf* allpdf2 = NULL;
  RooDataHist* rhist2 = NULL;
  RooRealVar gmean("fmean", "", 2.01, 2.009,2.011);
  RooRealVar gsigma("gsigma", "", 0.001, 1e-5,1e-2);
  RooGaussian gau("gau", "", *mass, gmean, gsigma);
  RooRealVar xscale("xscale", "", 1, 1e-2, 10);
  xscale.setConstant(1);
  RooFormulaVar minusDM("minusDM", "endpt-xscale*(mass-endpt)", RooArgList(*mass, xscale, *endpt));
  RooRealVar kappa2("kappa2", "argpar1", -3.8935e+01, -200., 0.);
  RooRealVar n("n", "", 0.5);
  RooArgusBG arg("arg", "argus", minusDM, *endpt, kappa2, n);
  arg.forceNumInt(kTRUE);
  RooRealVar nsig2("nsig2", "", 3e4, 0, 1e6);
  RooRealVar nbkg2("nbkg2", "", 1e3,0, 1e8);
  allpdf2 = new RooAddPdf("allpdf2", "", RooArgList(gau,arg), RooArgList(nsig2,nbkg2));
  
  rhname = "r_"; rhname += h2->GetName();
  rhist2 = new RooDataHist(rhname.Data(), "", *mass, h2);
  res = allpdf2->fitTo(*rhist2, RooFit::Save());
  res->Print("v");
  RooPlot *frame = mass->frame(RooFit::Range(h1->GetBinLowEdge(1), h1->GetBinLowEdge(h1->GetNbinsX()+1)));
  frame->SetTitle("");
  frame->SetXTitle(h1->GetXaxis()->GetTitle());
  frame->SetYTitle(h1->GetYaxis()->GetTitle());
  rhist->plotOn(frame);
  allpdf->plotOn(frame, RooFit::LineWidth(2), RooFit::LineColor(h1->GetLineColor()));
  allpdf->plotOn(frame, RooFit::Components("arg"),RooFit::LineWidth(2), RooFit::LineStyle(kDashed), 
                 RooFit::LineColor(h1->GetLineColor()));
  rhist2->plotOn(frame);
  allpdf2->plotOn(frame, RooFit::LineWidth(2), RooFit::LineColor(h2->GetLineColor()));
  allpdf2->plotOn(frame, RooFit::Components("arg"),RooFit::LineWidth(2), RooFit::LineStyle(kDashed), 
                  RooFit::LineColor(h2->GetLineColor()));
  frame->Draw();
  //frame->GetYaxis()->SetRangeUser(frame->GetYaxis()->GetXmin()/10, frame->GetYaxis()->GetXmax());
  TPaveText *txt = new TPaveText(0.7, 0.7, 0.98, 0.98, "ndc");
  txt->SetTextAlign(12);
  txt->AddText(TString::Format("N_{sig}: %d #pm %d", (int)nsig->getVal(), (int)nsig->getError()));
  txt->AddText(TString::Format("N_{peak}: %d #pm %d", (int)nsig2.getVal(), (int)nsig2.getError()));
  txt->Draw(); 
}

void betastar_plot::makefitplot(RooWorkspace*w, TH1* h1, int addpol){
  RooRealVar *mass = w->var("mass"); 
  RooRealVar *nsig = w->var("nsig");
  RooRealVar *kappa = w->var("kappa");
  kappa->setConstant(0);
  RooAbsPdf *arg = w->pdf("arg");
  RooAbsPdf* allpdf = NULL;
  RooDataHist* rhist = NULL;
  RooRealVar gmean("fmean", "", 2.01, 2.009,2.011);
  RooRealVar gsigma("gsigma", "", 0.001, 1e-5,1e-2);
  RooGaussian gau("gau", "", *mass, gmean, gsigma);
  RooRealVar gmean2("fmean2", "", 2.01, 2.009,2.011);
  RooRealVar gsigma2("gsigma2", "", 0.001, 1e-5,1e-2);
  RooFormulaVar fgsigma("fgsigma", "@0+@1", RooArgList(gsigma, gsigma2));
  RooGaussian gau2("gau2", "", *mass, gmean2, fgsigma);
  RooRealVar *nbkg = w->var("nbkg");
  RooRealVar nbkg2("nbkg2", "", 1e3,0, 1e8);
  if (!addpol){
    //allpdf = new RooAddPdf("allpdf", "", RooArgList(gau,*arg), RooArgList(*nsig,*nbkg)); nbkg2.setVal(0);}
    allpdf = w->pdf("model"); nbkg2.setVal(0);}
  else allpdf = new RooAddPdf("allpdf", "", RooArgList(gau,*arg, gau2), RooArgList(*nsig,*nbkg, nbkg2));
  
  TString rhname = "r_"; rhname += h1->GetName();
  rhist = new RooDataHist(rhname.Data(), "", *mass, h1);
  allpdf->fitTo(*rhist, RooFit::Save(), RooFit::Minos());
  RooFitResult* res = allpdf->fitTo(*rhist, RooFit::Save());
  res->Print("v");
  RooPlot *frame = mass->frame(RooFit::Range(h1->GetBinLowEdge(1), h1->GetBinLowEdge(h1->GetNbinsX()+1)));
  frame->SetTitle("");
  frame->SetXTitle(h1->GetXaxis()->GetTitle());
  frame->SetYTitle(h1->GetYaxis()->GetTitle());
  rhist->plotOn(frame);
  allpdf->plotOn(frame, RooFit::LineWidth(2), RooFit::LineColor(h1->GetLineColor()));
  allpdf->plotOn(frame, RooFit::Components("arg"),RooFit::LineWidth(2), RooFit::LineStyle(kDashed), 
                 RooFit::LineColor(h1->GetLineColor()));
  if (addpol) allpdf->plotOn(frame, RooFit::Components("arg,gau2"),RooFit::LineWidth(2), RooFit::LineStyle(kDotted), 
                             RooFit::LineColor(h1->GetLineColor()));
  frame->Draw();
  TPaveText *txt = new TPaveText(0.7, 0.8, 0.98, 0.98, "ndc");
  txt->SetTextAlign(12);
  txt->AddText(TString::Format("N_{peak}: %d #pm %d", (int)(nsig->getVal()+nbkg2.getVal()), 
                               (int)sqrt(nsig->getError()*nsig->getError()+nbkg2.getError()*nbkg2.getError())));
  txt->Draw();
}

