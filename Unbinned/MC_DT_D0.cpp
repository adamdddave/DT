#define MC_DT_D0_cxx
#include "MC_DT_D0.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <iostream>
//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include <RooFitResult.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooGaussian.h>
#include <RooHist.h>
#include <RooDataHist.h>

using namespace RooFit ;
using namespace std;

void MC_DT_D0::Loop()
{
//   In a ROOT session, you can do:
//      root> .L MC_DT_D0.C
//      root> MC_DT_D0 t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
     if(jentry % 10000 ==0){cout<<"Processed "<<jentry<<" MC events"<<endl;}
     
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(!(
           K_PIDK>kpidk_cut&&
           Pd_PIDK<pi_dau_pidk_cut &&
           Ps_PIDe<pi_slow_pide_cut &&
           Ps_ProbNNghost < pi_slow_probnnghost_cut &&
           //         TMath::Abs(B_VFit_D0_M-pdg_d0_m)<dmass_cut &&//this also comes after Beta* plots
           Mu_L0MuonDecision_TOS==1&&
           Mu_Hlt1TrackMuonDecision_TOS==1&&
           (B_Hlt2TopoMu2BodyBBDTDecision_TOS==1||
            B_Hlt2TopoMu3BodyBBDTDecision_TOS==1||
            B_Hlt2TopoMu4BodyBBDTDecision_TOS==1)&&
           Mu_isMuon &&
           Mu_MC12TuneV2_ProbNNmu > mu_probnnmu_cut&&         
           B_VFit_M[0] < bmass_cut_hi &&
           B_VFit_M[0] > bmass_cut_low
           //&&Mu_MC12TuneV3_ProbNNmu > mu_probnnmu_cut
           
           )) continue;
      pi_daughter_as_k.SetXYZM(B_VFit_piplus_0_PX[0]/1e3,
                               B_VFit_piplus_0_PY[0]/1e3,
                               B_VFit_piplus_0_PZ[0]/1e3,
                               pdg_kplus_m/1e3);//GeV

      k_daughter_as_pi.SetXYZM(B_VFit_Kplus_PX[0]/1e3,
                               B_VFit_Kplus_PY[0]/1e3,
                               B_VFit_Kplus_PZ[0]/1e3,
                               pdg_piplus_m/1e3);//GeV
      pi_daughter.SetXYZM(B_VFit_piplus_0_PX[0]/1e3,
                          B_VFit_piplus_0_PY[0]/1e3,
                          B_VFit_piplus_0_PZ[0]/1e3,
                          pdg_piplus_m/1e3);//GeV
      k_daughter.SetXYZM(B_VFit_Kplus_PX[0]/1e3,
                         B_VFit_Kplus_PY[0]/1e3,
                         B_VFit_Kplus_PZ[0]/1e3,
                         pdg_kplus_m/1e3);//GeV
      slow_pion_vec.SetXYZM(B_VFit_piplus_PX[0]/1e3,
                            B_VFit_piplus_PY[0]/1e3,
                            B_VFit_piplus_PZ[0]/1e3,
                            139.57018/1e3);
      d0_vector.SetXYZM((k_daughter+pi_daughter).Px(),
                        (k_daughter+pi_daughter).Py(),
                        (k_daughter+pi_daughter).Pz(),
                        1864.84/1e3);//GeV
      //cout<<"pi_daugter.E ="<<pi_daughter.E()<<endl;
    
      Double_t dstm = (d0_vector+slow_pion_vec).M()*1e3;
      if(!(
           TMath::Abs((k_daughter + pi_daughter).M()*1e3 - pdg_d0_m)<24 &&
           TMath::Abs((pi_daughter_as_k+k_daughter).M()-pdg_d0_m)>40 &&
           TMath::Abs((k_daughter_as_pi+pi_daughter).M()-pdg_d0_m)>40
           ))continue;
      TLorentzVector truedst;
      truedst.SetPxPyPzE(Dstar_TRUEP_X,Dstar_TRUEP_Y,Dstar_TRUEP_Z,Dstar_TRUEP_E);
      
      dstar_mass_resolution_plot->Fill(dstm - truedst.M());
      dstar_mass_resolution_zoom->Fill(dstm - truedst.M());
      
   }
}

void MC_DT_D0::fitResolution(){
  //RooRealVar *dmass = new RooRealVar("dmass","delta m(D*)",-5.,5., "MeV");
  RooRealVar *dmass = new RooRealVar("dmass","delta m(D*)",-1.8,1.8, "MeV");
  dmass->setRange("r1",-1.8,1.8);
  RooRealVar *mean1 = new RooRealVar("mean1","mean1",0.,-10,10);
  RooRealVar *mean2 = new RooRealVar("mean2","mean2",0.,-1,1);
  RooRealVar *mean3 = new RooRealVar("mean3","mean3",0.,-1,1);
  RooRealVar *width1 = new RooRealVar("width1","width1",2, 0.0001,3);
  RooRealVar *width2 = new RooRealVar("width2","width2",5, 0.001,5);
  RooRealVar *width3 = new RooRealVar("width3","width3",5, 0.001,7);
  RooGaussian *g1 = new RooGaussian("g1","g1",*dmass,*mean1,*width1);
  RooGaussian *g2 = new RooGaussian("g2","g2",*dmass,*mean2,*width2);
  RooGaussian *g3 = new RooGaussian("g3","g3",*dmass,*mean3,*width3);
  /*  RooGaussian *g1 = new RooGaussian("g1","g1",*dmass,*mean1,*width1);
  RooGaussian *g2 = new RooGaussian("g2","g2",*dmass,*mean1,*width2);
  RooGaussian *g3 = new RooGaussian("g3","g3",*dmass,*mean1,*width3);*/
  RooRealVar *frac1 = new RooRealVar("frac1","frac1",0.6,0.3,1.);
  RooRealVar *frac2 = new RooRealVar("frac2","frac2", 0.3,0.1,1.);
  
  RooAbsPdf *model= new RooAddPdf("model","",RooArgList(*g1,*g2,*g3),RooArgList(*frac1,*frac2),kTRUE);
  //RooAbsPdf *model= new RooAddPdf("model","",RooArgList(*g1,*g2),RooArgList(*frac1));
  RooDataHist* data = new RooDataHist("data","data",*dmass, dstar_mass_resolution_zoom);
  
  
  TCanvas* cc = new TCanvas();
  model->fitTo(*data,Range("r1"));
  //g1->fitTo(*data);
  RooPlot* frame = dmass->frame();
  data->plotOn(frame);
  model->plotOn(frame);
  //g1->plotOn(frame);
  model->plotOn(frame,Components(*g1),LineColor(kRed),LineStyle(kDashed));
  model->plotOn(frame,Components(*g2),LineColor(kOrange+1),LineStyle(kDashed));
  model->plotOn(frame,Components(*g3),LineColor(kMagenta+1),LineStyle(kDashed));
  model->paramOn(frame);
  frame->Draw();
  
  cc->SaveAs("./SavedFits/MC_resolution/MC_mass_resolution_fit.C");
  cc->SaveAs("./SavedFits/MC_resolution/MC_mass_resolution_fit.pdf");
  cc->SetLogy(true);
  cc->SaveAs("./SavedFits/MC_resolution/MC_mass_resolution_fit_logy.pdf");
  cc->SetLogy(false);
  //fix all the params
  mean1->setConstant(1);
  mean2->setConstant(1);
  mean3->setConstant(1);
  width1->setConstant(1);
  width2->setConstant(1);
  width3->setConstant(1);
  frac1->setConstant(1);
  frac2->setConstant(1);
  
  dmass->setRange(-5.,5.);
  
  RooDataHist* data2 = new RooDataHist("data2","data, take2",*dmass, dstar_mass_resolution_zoom);
  RooPlot* frame2 = dmass->frame();
  data2->plotOn(frame2);
  model->plotOn(frame2,Range(-5,5));
  frame2->Draw();
  
    
  //cc->Clear();

  //delete cc;
}
