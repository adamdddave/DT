// Include files 
#include <iostream>
#include <TCanvas.h>
#include <TPad.h>
#include <TFile.h>
#include <TStyle.h>
#include <TPaveText.h>
#include <TF1.h>
// local
#include "betastar_plot.h"
//root
#include <TBox.h>
//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
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

#include <PlottingTools.h>
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
  
   h2sig = new TH2D(name+"_h2sig","",200,-1.,1.,200,1.2,2.0);
   h2kpisb = (TH2*)h2sig->Clone(name+"_h2kpisb");
  
   h2kpisb_hi = (TH2*)h2sig->Clone(name+"_h2kpisb_hi");
   h2kpisb_lo = (TH2*)h2sig->Clone(name+"_h2kpisb_lo");
  
   h2kksb = (TH2*)h2sig->Clone(name+"_h2kksb");
   h2pipisb = (TH2*)h2sig->Clone(name+"_h2pipisb");
   h2piksb = (TH2*)h2sig->Clone(name+"_h2piksb");
   h2rob = (TH2*)h2sig->Clone(name+"_h2rob");
   h2kpisb_cut_range = (TH2*)h2sig->Clone(name+"_h2kpisb_cut_range");
  
   h2pi_probnnmu_dstar_sideband_high = new TH2D(name+"_h2pi_probnnmu_dstar_sideband_high","",100,0,1,250,2000,2025);
   h2pi_probnnmu_dstar_sideband_low=new TH2D(name+"_h2pi_probnnmu_dstar_sideband_low","",100,0,1,250,2000,2025);
    
   h2k_probnnmu_dstar_sideband_high=new TH2D(name+"_h2k_probnnmu_dstar_sideband_high","",100,0,1,250,2000,2025);
   h2k_probnnmu_dstar_sideband_low=new TH2D(name+"_h2k_probnnmu_dstar_sideband_low","",100,0,1,250,2000,2025);    
  
   h2pi_probnne_dstar_sideband_high=new TH2D(name+"_h2pi_probnne_dstar_sideband_high","",100,0,1,250,2000,2025);
   h2pi_probnne_dstar_sideband_low=new TH2D(name+"_h2pi_probnne_dstar_sideband_low","",100,0,1,250,2000,2025);
  
   h2k_probnne_dstar_sideband_high=new TH2D(name+"_h2k_probnne_dstar_sideband_high","",100,0,1,250,2000,2025);
   h2k_probnne_dstar_sideband_low=new TH2D(name+"_h2k_probnne_dstar_sideband_low","",100,0,1,250,2000,2025);    
  
   hmsig = new TH1D(name+"_hmsig","", 250, 2000, 2025);
   hmkpisb = (TH1*)hmsig->Clone(name+"_hmkpisb");
   hmkksb = (TH1*)hmsig->Clone(name+"_hmkksb");
   hmpipisb =(TH1*) hmsig->Clone(name+"_hmpipisb");
   hmpiksb = (TH1*)hmsig->Clone(name+"_hmpiksb");
   hmrob = (TH1*)hmsig->Clone(name+"_hmrob");

   hmkpisb_cut_range = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range");
   hmkpisb_cut_range_hi = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_hi");
   hmkpisb_cut_range_lo = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_lo");

   hmkpisb_cut_range_hi_1 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_hi_1");//40-52
   hmkpisb_cut_range_lo_1 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_lo_1");//40-52

   hmkpisb_cut_range_hi_2 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_hi_2");//52-64
   hmkpisb_cut_range_lo_2 = (TH1*)hmsig->Clone(name+"_hmkpisb_cut_range_lo_2");//52-64

    
    
   hmD0_pik_sig = new TH1D(name+"_hmD0_pik_sig","D^{0}->#pi K mass, #Delta M signal range; m(#pi K)[MeV];",200, 1700,2100);
   hmD0_pik_sb = new TH1D(name+"_hmD0_pik_sb","D^{0}->#pi K mass, #Delta M sideband; m(#pi K)[MeV];",200, 1700,2100);
   hmD0_pik_tot = new TH1D(name+"_hmD0_pik","D^{0}->#pi K mass, #Delta M unaltered; m(#pi K)[MeV];",200, 1700,2100);

   double_misid_dmass_dst_sig_region = new TH1D(name+"_double_misid_dmass_dst_sig_region","",200,1700,2100);
   double_misid_dmass_dst_sideband_region = new TH1D(name+"_double_misid_dmass_dst_sideband_region","",200,1700,2100);
}
//=============================================================================
// Secondary constructor from root file
//=============================================================================

betastar_plot::betastar_plot(TFile *file, TString name) {
  m_name = name;
  std::cout<<"Looking for file "<<m_name<<"_h2sig"<<std::endl;
  h2sig=(TH2*)file->Get(m_name+"_h2sig");
  h2kpisb=(TH2*)file->Get(m_name+"_h2kpisb");
  h2kpisb_hi=(TH2*)file->Get(m_name+"_h2kpisb_hi");
  h2kpisb_lo=(TH2*)file->Get(m_name+"_h2kpisb_lo");
  h2kksb=(TH2*)file->Get(m_name+"_h2kksb");
  h2pipisb=(TH2*)file->Get(m_name+"_h2pipisb");
  h2piksb=(TH2*)file->Get(m_name+"_h2piksb");
  h2rob=(TH2*)file->Get(m_name+"_h2rob");
  h2kpisb_cut_range=(TH2*)file->Get(m_name+"_h2kpisb_cut_range");
  h2pi_probnnmu_dstar_sideband_high=(TH2*)file->Get(m_name+"_h2pi_probnnmu_dstar_sideband_high");
  h2pi_probnnmu_dstar_sideband_low=(TH2*)file->Get(m_name+"_h2pi_probnnmu_dstar_sideband_low");
  h2k_probnnmu_dstar_sideband_high=(TH2*)file->Get(m_name+"_h2k_probnnmu_dstar_sideband_high");
  h2k_probnnmu_dstar_sideband_low=(TH2*)file->Get(m_name+"_h2k_probnnmu_dstar_sideband_low");
  h2pi_probnne_dstar_sideband_high=(TH2*)file->Get(m_name+"_h2pi_probnne_dstar_sideband_high");
  h2pi_probnne_dstar_sideband_low=(TH2*)file->Get(m_name+"_h2pi_probnne_dstar_sideband_low");
  h2k_probnne_dstar_sideband_high=(TH2*)file->Get(m_name+"_h2k_probnne_dstar_sideband_high");
  h2k_probnne_dstar_sideband_low=(TH2*)file->Get(m_name+"_h2k_probnne_dstar_sideband_low");
  
  hmsig=(TH1*)file->Get(m_name+"_hmsig");
  hmkpisb=(TH1*)file->Get(m_name+"_hmkpisb");
  hmkksb=(TH1*)file->Get(m_name+"_hmkksb");
  hmpipisb=(TH1*)file->Get(m_name+"_hmpipisb");
  hmpiksb=(TH1*)file->Get(m_name+"_hmpiksb");
  hmrob=(TH1*)file->Get(m_name+"_hmrob");

  hmkpisb_cut_range=(TH1*)file->Get(m_name+"_hmkpisb_cut_range");
  hmkpisb_cut_range_hi=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_hi");
  hmkpisb_cut_range_lo=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_lo");
  hmkpisb_cut_range_hi_1=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_hi_1");
  hmkpisb_cut_range_lo_1=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_lo_1");
  hmkpisb_cut_range_hi_2=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_hi_2");
  hmkpisb_cut_range_lo_2=(TH1*)file->Get(m_name+"_hmkpisb_cut_range_lo_2");
  hmD0_pik_sig=(TH1*)file->Get(m_name+"_hmD0_pik_sig");
  hmD0_pik_sb=(TH1*)file->Get(m_name+"_hmD0_pik_sb");
  hmD0_pik_tot=(TH1*)file->Get(m_name+"_hmD0_pik");

   double_misid_dmass_dst_sig_region = (TH1*)file->Get(name+"_double_misid_dmass_dst_sig_region");
   double_misid_dmass_dst_sideband_region = (TH1*)file->Get(name+"_double_misid_dmass_dst_sideband_region");
}
//=============================================================================
// Destructor
//=============================================================================
betastar_plot::~betastar_plot() {} 

//=============================================================================
//Draw the plots and save them.
//=============================================================================
void betastar_plot::DrawPlots(){
  
  //    TCanvas * cc = new TCanvas();
    // hmsig->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_signal_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_signal_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb_cut_range->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_cut_range.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_cut_range_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();


    // hmkksb->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kk_signal_kpi_sideband_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kk_signal_kpi_sideband_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();


    // hmpipisb->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"pipi_signal_kpi_sideband_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"pipi_signal_kpi_sideband_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();
            

    // hmpiksb->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"pik_signal_kpi_sideband_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"pik_signal_kpi_sideband_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmrob->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_not_signal_region.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_not_signal_region_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();
    
    // //if(doD0plots){
    //   hmD0_pik_tot->Draw();
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_total.pdf");
    //   cc->SetLogy(true);
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_total_logy.pdf");
    //   cc->SetLogy(false);
    //   cc->Clear();
      
    //   hmD0_pik_sig->Draw();
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_signal_dstar.pdf");
    //   cc->SetLogy(true);
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_signal_dstar_logy.pdf");
    //   cc->SetLogy(false);
    //   cc->Clear();
      
      
    //   hmD0_pik_sb->Draw();
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_sideband_dstar.pdf");
    //   cc->SetLogy(true);
    //   cc->SaveAs("./SavedFits/betastar/"+m_name+"pi_k_d0mass_sideband_dstar_logy.pdf");
    //   cc->SetLogy(false);
    //   cc->Clear();
    //   //}
    
    // hmkpisb_cut_range_hi->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb_cut_range_lo->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb_cut_range_hi_1->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi_1.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi_1_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb_cut_range_hi_2->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi_2.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_hi_2_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();
    

    // hmkpisb_cut_range_lo_1->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo_1.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo_1_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();

    // hmkpisb_cut_range_lo_2->Draw();
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo_2.pdf");
    // cc->SetLogy(true);
    // cc->SaveAs("./SavedFits/betastar/"+m_name+"kpi_sideband_region_lo_2_logy.pdf");
    // cc->SetLogy(false);
    // cc->Clear();    

    //delete cc;

    // TFile *the_outfile = new TFile("./betastar_sidebands.root","RECREATE");
    // the_outfile->cd();
    // h2sig->Write();
    // h2kpisb->Write();
    // h2kksb->Write();
    // h2pipisb->Write();
    // h2piksb->Write();
    // h2rob->Write();
    // h2kpisb_cut_range->Write();
    // h2pi_probnnmu_dstar_sideband_high->Write();
    // h2pi_probnnmu_dstar_sideband_low->Write();
    // h2k_probnnmu_dstar_sideband_high->Write();
    // h2k_probnnmu_dstar_sideband_low->Write();
    // h2pi_probnne_dstar_sideband_high->Write();
    // h2pi_probnne_dstar_sideband_low->Write();
    // h2k_probnne_dstar_sideband_high->Write();
    // h2k_probnne_dstar_sideband_low->Write();
    // h2kpisb_hi->Write();
    // h2kpisb_lo->Write();
    
    
    
    // hmsig->Write();
    // hmkpisb->Write();
    // hmkksb->Write();
    // hmpipisb->Write();
    // hmpiksb->Write();
    // hmrob->Write();
    // hmkpisb_cut_range->Write();
    // hmD0_pik_tot->Write();
    // hmD0_pik_sig->Write();
    // hmD0_pik_sb->Write();
    // hmkpisb_cut_range_hi->Write();
    // hmkpisb_cut_range_lo->Write();
    // hmkpisb_cut_range_hi_1->Write();
    // hmkpisb_cut_range_lo_1->Write();
    // hmkpisb_cut_range_hi_2->Write();
    // hmkpisb_cut_range_lo_2->Write();
    

    // the_outfile->Close();
    

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

    cv->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_figure.pdf");
    cv->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_figure.C");
    
    return;

    
}

void betastar_plot::makefitplot(RooWorkspace*w, TH1* h1, TH1* h2){
  RooRealVar *mass = w->var("dstarM"); 
  RooRealVar *nsig = w->var("nsig");
  RooRealVar *kappa = w->var("kappa");
  w->var("m0")->setConstant(1);
  w->var("delta")->setConstant(1);
  w->var("sigma")->setConstant(1);
  w->var("gamma")->setConstant(1);
  w->var("mean1")->setConstant(1);
  w->var("mean2")->setConstant(1);
  w->var("mean3")->setConstant(1);
  w->var("width1")->setConstant(1);
  w->var("width2")->setConstant(1);
  w->var("width3")->setConstant(1);
  w->var("frac1")->setConstant(1);
  w->var("frac2")->setConstant(1);
  w->var("frac3")->setConstant(1);
  
  kappa->setConstant(0);
  //RooRealVar *pn = w->var("n");
  //pn->setConstant(1);
  RooRealVar *endpt = w->var("endpt");
  RooRealVar *dmean = w->var("dmean");
  RooRealVar *rsigma = w->var("rsigma");
  dmean->setConstant(1); rsigma->setConstant(1);
  RooAbsPdf* allpdf = w->pdf("model");
 
  TString rhname("r_"); rhname += h1->GetName();
  RooDataHist *rhist = new RooDataHist(rhname.Data(), "", *mass, h1);
  RooFitResult *res = allpdf->fitTo(*rhist, RooFit::Save(),Extended(1));
  res->Print("v");
  RooAbsPdf* allpdf2 = NULL;
  RooDataHist* rhist2 = NULL;
  RooRealVar gmean("fmean", "", 2.01*1e3, 2.009*1e3,2.011*1e3);
  RooRealVar gsigma("gsigma", "", 0.001*1e3, 1e-5*1e3,1e-2*1e3);
  RooGaussian gau("gau", "", *mass, gmean, gsigma);
  RooRealVar gmean2("gmean2","",2010,2009,2011);
  RooRealVar gsigma2("gsigma2","",0.5,1e-3,1);
  RooGaussian gau2("gau2", "", *mass, gmean2, gsigma2);
  //make a crystal ball to try
  /*RooRealVar cbm0("cbm0","cbm0",2010,2009,2011);
  RooRealVar cbsigma("cbsigma","cbsigma",0.5,0.1,10);
  RooRealVar cbalpha("cbalpha","cbalpha",-0.2,-3,0.);//tail on the right
  RooRealVar cbn("cbn","cbn",1,0,3);
  RooCBShape cball("cball","cball",*mass,cbm0,cbsigma,cbalpha,cbn);*/
  RooRealVar fracGauPeak("fracGauPeak","",0.5,0.3,1.);
  RooRealVar xscale("xscale", "", 1, 1e-2, 10);
  xscale.setConstant(1);
  RooFormulaVar minusDM("minusDM", "@2-@1*(@0-@2)", RooArgList(*mass, xscale, *endpt));
  RooRealVar kappa2("kappa2", "argpar1", -3.8935e+01, -200., 0.);
  RooRealVar n("n", "", 0.5);
  RooArgusBG arg("bkg", "argus", minusDM, *endpt, kappa2, n);
  arg.forceNumInt(kTRUE);
  RooAbsPdf *gauAdd = new RooAddPdf("gauAdd","",RooArgList(gau,gau2),RooArgList(fracGauPeak));
  ///RooAbsPdf *gauAdd = new RooAddPdf("gauAdd","",RooArgList(gau,cball),RooArgList(fracGauPeak));
  RooRealVar nsig2("nsig2", "", 3e4, 0, 1e8);
  RooRealVar nbkg2("nbkg2", "", 1e3,0, 1e8);
  //allpdf2 = new RooAddPdf("allpdf2", "", RooArgList(gau,arg), RooArgList(nsig2,nbkg2));
  allpdf2 = new RooAddPdf("allpdf2", "", RooArgList(*gauAdd,arg), RooArgList(nsig2,nbkg2));
  
  rhname = "r_"; rhname += h2->GetName();
  rhist2 = new RooDataHist(rhname.Data(), "", *mass, h2);
  res = allpdf2->fitTo(*rhist2, RooFit::Save(),Extended(1));
  res->Print("v");
  //make pull plots just for good riddance
  // RooPlot* frame2 = mass->frame();
  // rhist2->plotOn(frame2);
  // allpdf2->plotOn(frame2);
  // PlottingTools::makeResidualPlotsLiang(frame2,*mass,*rhist2,allpdf2,"./SavedFits/betastar/peakingBkgFit",2000,2025);

  RooPlot *frame = mass->frame(RooFit::Range(h1->GetBinLowEdge(1), h1->GetBinLowEdge(h1->GetNbinsX()+1)));
  frame->SetTitle("");
  frame->SetXTitle(h1->GetXaxis()->GetTitle());
  frame->SetYTitle(h1->GetYaxis()->GetTitle());
  rhist->plotOn(frame);
  allpdf->plotOn(frame, RooFit::LineWidth(2), RooFit::LineColor(h1->GetLineColor()));
  allpdf->plotOn(frame, RooFit::Components("bkg"),RooFit::LineWidth(2), RooFit::LineStyle(kDashed), 
                 RooFit::LineColor(h1->GetLineColor()));
  rhist2->plotOn(frame);
  allpdf2->plotOn(frame, RooFit::LineWidth(2), RooFit::LineColor(h2->GetLineColor()));
  allpdf2->plotOn(frame, RooFit::Components("bkg"),RooFit::LineWidth(2), RooFit::LineStyle(kDashed), 
                  RooFit::LineColor(h2->GetLineColor()));
  allpdf2->plotOn(frame, RooFit::Components("gau"),RooFit::LineWidth(2), RooFit::LineStyle(kDotted), 
                  RooFit::LineColor(h2->GetLineColor()));
  allpdf2->plotOn(frame,RooFit::Components("gau2"),RooFit::LineColor(h2->GetLineColor()), RooFit::LineStyle(4));
  //allpdf2->plotOn(frame,RooFit::Components("cball"),RooFit::LineColor(kGreen+2));
  frame->Draw();
  //frame->GetYaxis()->SetRangeUser(frame->GetYaxis()->GetXmin()/10, frame->GetYaxis()->GetXmax());
  TPaveText *txt = new TPaveText(0.7, 0.7, 0.98, 0.98, "ndc");
  txt->SetTextAlign(12);
  txt->AddText(TString::Format("N_{sig}: %d #pm %d", (int)nsig->getVal(), (int)nsig->getError()));
  txt->AddText(TString::Format("N_{peak}: %d #pm %d", (int)nsig2.getVal(), (int)nsig2.getError()));
  txt->Draw();


}

void betastar_plot::makefitplot(RooWorkspace*w, TH1* h1, int addpol){
  RooRealVar *mass = w->var("dstarM"); 
  RooRealVar *nsig = w->var("nsig");
  RooRealVar *kappa = w->var("kappa");
  kappa->setConstant(0);
  RooAbsPdf *arg = w->pdf("bkg");
  RooAbsPdf* allpdf = NULL;
  RooDataHist* rhist = NULL;
  RooRealVar gmean("fmean", "", 2.01*1e3, 2.009*1e3,2.011*1e3);
  RooRealVar gsigma("gsigma", "", 0.001*1e3, 1e-5*1e3,1e-2*1e3);
  RooGaussian gau("gau", "", *mass, gmean, gsigma);
  RooRealVar gmean2("fmean2", "", 2.01*1e3, 2.009*1e3,2.011*1e3);
  RooRealVar gsigma2("gsigma2", "", 0.001*1e3, 1e-5*1e3,1e-2*1e3);
  RooFormulaVar fgsigma("fgsigma", "@0+@1", RooArgList(gsigma, gsigma2));
  RooGaussian gau2("gau2", "", *mass, gmean2, fgsigma);
  RooRealVar *nbkg = w->var("nbkg");
  RooRealVar nbkg2("nbkg2", "", 1e3,0, 1e8);
  if (!addpol){
    //allpdf = new RooAddPdf("allpdf", "", RooArgList(gau,*arg), RooArgList(*nsig,*nbkg)); nbkg2.setVal(0);}
    allpdf = w->pdf("model");
    nbkg2.setVal(0);
    w->var("rsigma")->setConstant(0);
    w->var("dmean")->setConstant(0);
  }
  else allpdf = new RooAddPdf("allpdf", "", RooArgList(gau,*arg, gau2), RooArgList(*nsig,*nbkg, nbkg2));
  
  
  TString rhname = "r_"; rhname += h1->GetName();
  rhist = new RooDataHist(rhname.Data(), "", *mass, h1);
  allpdf->fitTo(*rhist, RooFit::Save(), RooFit::Minos());
  RooFitResult* res = allpdf->fitTo(*rhist, RooFit::Save(),Extended(1));
  res->Print("v");
  RooPlot *frame = mass->frame(RooFit::Range(h1->GetBinLowEdge(1), h1->GetBinLowEdge(h1->GetNbinsX()+1)));
  frame->SetTitle("");
  frame->SetXTitle(h1->GetXaxis()->GetTitle());
  frame->SetYTitle(h1->GetYaxis()->GetTitle());
  rhist->plotOn(frame);
  allpdf->plotOn(frame, RooFit::LineWidth(2), RooFit::LineColor(h1->GetLineColor()));
  allpdf->plotOn(frame, RooFit::Components("bkg"),RooFit::LineWidth(2), RooFit::LineStyle(kDashed), 
                 RooFit::LineColor(h1->GetLineColor()));
  if (addpol) allpdf->plotOn(frame, RooFit::Components("bkg,gau2"),RooFit::LineWidth(2), RooFit::LineStyle(kDotted), 
                             RooFit::LineColor(h1->GetLineColor()));
  frame->Draw();
  TPaveText *txt = new TPaveText(0.7, 0.8, 0.98, 0.98, "ndc");
  txt->SetTextAlign(12);
  txt->AddText(TString::Format("N_{peak}: %d #pm %d", (int)(nsig->getVal()+nbkg2.getVal()), 
                               (int)sqrt(nsig->getError()*nsig->getError()+nbkg2.getError()*nbkg2.getError())));
  txt->Draw();
  if(!addpol){
    //integrate the two regions for the background, and print them out. Save the ratio in the class.
    //first,normalize
    RooArgSet nset(*mass) ;
    std::cout << "normalized integral = " << mass->getVal(&nset) << std::endl ;
    RooAbsReal* tot_int_bkg = arg->createIntegral(*mass,NormSet(*mass));
    mass->setRange("peak",2010.26-0.9,2010.26+0.9);
    RooAbsReal* peak_int_bkg = arg->createIntegral(*mass,NormSet(*mass),Range("peak"));
    RooAbsReal* tot_int_bkg2 = arg->createIntegral(*mass,NormSet(*mass));
    mass->setRange("sideband",2015,2025);
    RooAbsReal* sideband_int_bkg = arg->createIntegral(*mass,NormSet(*mass),Range("sideband"));
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"For h1 = "<<h1->GetName()<<std::endl;
    std::cout<<"Total integral of background = "<<tot_int_bkg->getVal()<<std::endl;
    std::cout<<"integral of background in signal region = "<<peak_int_bkg->getVal()<<std::endl;
    std::cout<<"integral of background in sideband region = "<<sideband_int_bkg->getVal()<<std::endl;
    pik_background_subtraction_ratio_result = peak_int_bkg->getVal()/sideband_int_bkg->getVal();
    std::cout<<"int(sig)/int(bkg) = "<<pik_background_subtraction_ratio_result<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    std::cout<<"******************************************************"<<std::endl;
    //PlottingTools::makeResidualPlotsLiang(frame,*mass,*rhist,allpdf,"./SavedFits/betastar/RSpeakingBkgFit_pik_fit",2000,2025);
  }
}

void betastar_plot::SavePlots(){
  TFile fout("./SavedFits/betastar/"+m_name+"_betastar_plots.root","RECREATE");
  fout.cd();
  h2sig->Write();
  h2kpisb->Write();
  h2kpisb_hi->Write();
  h2kpisb_lo->Write();
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
  
  hmsig->Write();
  hmkpisb->Write();
  hmkksb->Write();
  hmpipisb->Write();
  hmpiksb->Write();
  hmrob->Write();

  hmkpisb_cut_range->Write();
  hmkpisb_cut_range_hi->Write();
  hmkpisb_cut_range_lo->Write();
  hmkpisb_cut_range_hi_1->Write();
  hmkpisb_cut_range_lo_1->Write();
  hmkpisb_cut_range_hi_2->Write();
  hmkpisb_cut_range_lo_2->Write();
  hmD0_pik_sig->Write();
  hmD0_pik_sb->Write();
  hmD0_pik_tot->Write();

  double_misid_dmass_dst_sig_region->Write();
  double_misid_dmass_dst_sideband_region->Write();

  
  fout.Close();


}

void betastar_plot::FitWSDoubleMisID(){
  //do the background subtraction.
  //first, sumw2 on the histograms.
  double_misid_subtr = (TH1*)double_misid_dmass_dst_sig_region->Clone("double_misid_subtr");
  double_misid_subtr->Sumw2();
  TH1* double_misid_sideband_scaled = (TH1*)double_misid_dmass_dst_sideband_region->Clone("double_misid_sideband_scaled");
  double_misid_sideband_scaled->Sumw2();
  double_misid_sideband_scaled->Scale(pik_background_subtraction_ratio_result);
  double_misid_subtr->Add(double_misid_sideband_scaled,-1);
  //now we have the histogram, fit it with a second order polynomial.
  RooRealVar* x = new RooRealVar("x","m(K #pi)",1700,2100,"MeV");
  x->setRange("lo",1780,(1.86484 - 5*0.008)*1e3);
  x->setRange("hi",(1.86484 + 5*0.008)*1e3,1950);
  x->setRange("sig",1864.84-24,1864.84+24);
  RooRealVar a0("a0","a0",-0.1,-50,50);
  RooRealVar a1("a1","a1",0.004,-100,100);
  RooChebychev pol("pol","pol",*x,RooArgSet(a0,a1));
  /*  RooRealVar a0("a0","a0",1) ;
  RooRealVar a1("a1","a1",0,-20,20) ;
  RooRealVar a2("a2","a2",-1,-100,100) ;
  RooPolynomial pol("pol","pol",*x,RooArgList(a0,a1,a2),0) ;*/
  RooRealVar nsig("nsig","nsig",200,5,10000);
  RooDataHist* data = new RooDataHist((m_name+"double_misid_subtracted_data").Data(),"",*x,double_misid_subtr);
  RooExtendPdf model("model","model",pol,nsig);
  RooFitResult* res_pol = model.fitTo(*data,Range("lo,hi"),RooFit::Save(),Extended(1));
  res_pol->Print("v");
  TCanvas* cpol = new TCanvas();
  RooPlot* frame = x->frame();
  frame->SetTitle("");
  data->plotOn(frame);
  
  model.plotOn(frame,LineColor(kMagenta),Range(1780,2100));
  frame->Draw();
  TBox sigreg(1864.84-24,0,1864.84+24,frame->GetMaximum());
  sigreg.SetFillColor(kGreen+2);
  sigreg.SetFillColorAlpha(kGreen+2,0.5);
  sigreg.Draw();
  cpol->SaveAs("./SavedFits/betastar/"+m_name+"_betastar_double_misid_d0_sideband_subtracted_fit.pdf");
  //create the integral.
  RooAbsReal* tot_int_double_misid = model.createIntegral(*x,NormSet(*x));
  std::cout<<"nsig before = "<<nsig.getVal()*tot_int_double_misid->getVal()<<std::endl;
  RooAbsReal* sig_int = model.createIntegral(*x,NormSet(*x),Range("sig"));
  cout<<"nsig after = "<<nsig.getVal()<<endl;
  std::cout<<"nsig*I after = "<<nsig.getVal()*sig_int->getVal()<<std::endl;
  std::vector<double>poly_fit;
  poly_fit.push_back(nsig.getVal()*sig_int->getVal());//central value
  poly_fit.push_back(sig_int->getPropagatedError(*res_pol)*nsig.getVal());//propagated error
  
  std::cout<<"tot number of doubly misID in signal region for polynomial fit = "<<sig_int->getVal()*nsig.getVal()<<"+/-"<<sig_int->getPropagatedError(*res_pol)*nsig.getVal()<<std::endl;
  std::cout<<"error propagated from the fit = "<<getErrorFromPropagation(x,&model,res_pol,data,1700,2100,1864.84-24,1864.84+24)<<std::endl;
  //now construct secondary fit with linear shape.
  return;
}

double betastar_plot::getErrorFromPropagation(RooRealVar* x,RooAbsPdf* model, RooFitResult* fr,RooDataHist* data,Double_t xmin, Double_t xmax, Double_t sig_min, Double_t sig_max){
  // //taken from example at https://root.cern.ch/phpBB3/viewtopic.php?t=12949
  // RooArgList pars(*(model->getParameters(RooArgSet(*x) ) ));
  // Double_t nsig = ((RooRealVar*)pars.find("nsig"))->getVal();
  // std::cout<<"Getting Nsignal, =  "<<nsig<<std::endl;
  // RooArgSet prodSet(*model);
  // RooProduct unNormPdf("fitted Function", "fitted Function", prodSet);
  // //create at TF1 from the values given
  // TF1 * f2 = unNormPdf.asTF(RooArgList(*x), pars);
  // Double_t integ2_full = f2->Integral(xmin, xmax);
  // Double_t integ2 = nsig*f2->Integral(sig_min, sig_max,0)/integ2_full;
  // // LM: for drawing need to clone
  // // new TCanvas(); f2->DrawClone();
  // std::cout<<"from the propagation, the ratio of integrals = "<<integ2<<std::endl;
  // Double_t dinteg2 = nsig*f2->IntegralError(sig_min, sig_max, 0, fr->covarianceMatrix().GetMatrixArray())/integ2_full;
  // //the idea here is that we 
  // return dinteg2;
  return 0;  
}
