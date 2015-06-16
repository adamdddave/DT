//TODO, make the b mass cuts on the beta star plots, then after those, fill the b mas
//histogram. After this is filled, cut on the B mass.
#define DT_D0_mix_CPV_cxx
#include "DT_D0_mix_CPV.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TLorentzVector.h>
#include <iostream>
using namespace std;

void DT_D0_mix_CPV::Loop()
{
  //   In a ROOT session, you can do:
  //      Root > .L DT_D0_mix_CPV.C
  //      Root > DT_D0_mix_CPV t
  //      Root > t.GetEntry(12); // Fill t data members with entry number 12
  //      Root > t.Show();       // Show values of entry 12
  //      Root > t.Show(16);     // Read and show values of entry 16
  //      Root > t.Loop();       // Loop on all entries
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
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    if(jentry%100000==0)std::cout<<"processed "<<jentry<<" events"<<std::endl;
    
    //cuts
    if(!(
         B_VFit_status[0]==0 &&
         K_PIDK>kpidk_cut&&
         Pd_PIDK<pi_dau_pidk_cut &&
         Ps_PIDe<pi_slow_pide_cut &&
         Ps_ProbNNghost<pi_slow_probnnghost_cut &&
         //         TMath::Abs(B_VFit_D0_M-pdg_d0_m)<dmass_cut &&//this also comes after Beta* plots
         Mu_L0MuonDecision_TOS==1&&
         Mu_Hlt1TrackMuonDecision_TOS==1&&
         (B_Hlt2TopoMu2BodyBBDTDecision_TOS==1||
          B_Hlt2TopoMu3BodyBBDTDecision_TOS==1||
          B_Hlt2TopoMu4BodyBBDTDecision_TOS==1)&&
         Mu_isMuon &&
         Mu_MC12TuneV2_ProbNNmu > mu_probnnmu_cut&&
         !Ps_isMuon
         //&&Mu_MC12TuneV3_ProbNNmu > mu_probnnmu_cut
         
         )) continue;
    
    //there's only 1 pv per event.
    //for(int j_npv = 0; j_npv<B_VFit_nPV;++j_npv)    {
      
    //fill beta star plot, then veto the KK and pipi peaks
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
    Double_t Pis_CHARGE = Ps_ID/211.;
    Double_t Pi_CHARGE = Pd_ID/211.;
    Double_t beta = Pis_CHARGE*Pi_CHARGE*(pi_daughter.P()-k_daughter_as_pi.P())/(k_daughter_as_pi.P()+pi_daughter.P());

    //add the d mass cuts too for the b mass plots.
    if(TMath::Abs((k_daughter + pi_daughter).M()*1e3 - pdg_d0_m)<24 &&
       TMath::Abs((pi_daughter_as_k+k_daughter).M()-pdg_d0_m)>40 &&
       TMath::Abs((k_daughter_as_pi+pi_daughter).M()-pdg_d0_m)>40)
    {
      
      b_mass_plot->Fill(B_VFit_M[0]);
    }

    //fill bmass cuts now, so that we have everything ok.
    if(!(B_VFit_M[0] < bmass_cut_hi &&B_VFit_M[0] > bmass_cut_low))continue;

    if(fabs((k_daughter + pi_daughter).M()*1e3-1864.84)<24 
       && fabs((pi_daughter_as_k+k_daughter).M()-(1864.84/1e3))>5*8./1e3 
       && fabs((k_daughter_as_pi+pi_daughter).M()-(1864.84/1e3))>5*8./1e3)
    {
      bs_plot->h2sig->Fill(beta,(k_daughter_as_pi+pi_daughter).M());
      bs_plot->hmsig->Fill(dstm);
    }
    if(fabs((k_daughter + pi_daughter).M()*1e3-1864.84)>5*8.)
    {
      bs_plot->h2kpisb->Fill(beta,(k_daughter_as_pi+pi_daughter).M());
      bs_plot->hmkpisb->Fill(dstm);
    }
    if(fabs((k_daughter+pi_daughter_as_k).M()-1.86484)<3*0.008)
    {
      bs_plot->h2kksb->Fill(beta,(k_daughter_as_pi+pi_daughter).M());
      bs_plot->hmkksb->Fill(dstm);
    }
    if(fabs((pi_daughter+k_daughter_as_pi).M()-1.86484)<3*0.008){
      bs_plot->h2pipisb->Fill(beta,(k_daughter_as_pi+pi_daughter).M());
      bs_plot->hmpipisb->Fill(dstm);
    }
    if(fabs((pi_daughter_as_k+k_daughter_as_pi).M()-1.86484)<3*0.008&&fabs((k_daughter + pi_daughter).M()*1e3/1.e3-1.86484)>5*0.008)
    {
      bs_plot->h2piksb->Fill(beta,(k_daughter_as_pi+pi_daughter).M());
      bs_plot->hmpiksb->Fill(dstm);
    }
    if(!(fabs((k_daughter + pi_daughter).M()*1e3-1864.84)<24 
         && fabs((pi_daughter_as_k+k_daughter).M()-(1864.84/1e3))>5*8./1e3 
         && fabs((k_daughter_as_pi+pi_daughter).M()-(1864.84/1e3))>5*8./1e3))
    {
      bs_plot->h2rob->Fill(beta,(k_daughter_as_pi+pi_daughter).M());
      bs_plot->hmrob->Fill(dstm);
    }
    if(fabs((k_daughter + pi_daughter).M()*1e3-1864.84)>5*8. && fabs((k_daughter + pi_daughter).M()*1e3-1864.84)<8*8.){
      //peaking bkg, range of +/- 24 in the sideband
      bs_plot->h2kpisb_cut_range->Fill(beta,(k_daughter_as_pi+pi_daughter).M());
      bs_plot->hmkpisb_cut_range->Fill(dstm);
    }
    //split the range itself.
    if(((k_daughter + pi_daughter).M()*1e3-1864.84) >5*8 &&((k_daughter + pi_daughter).M()*1e3-1864.84)<8*8.){//hi side
      bs_plot->h2k_probnnmu_dstar_sideband_high->Fill(K_ProbNNmu,dstm);
      bs_plot->h2k_probnne_dstar_sideband_high->Fill(K_ProbNNe,dstm);

      bs_plot->h2pi_probnnmu_dstar_sideband_high->Fill(Pd_ProbNNmu,dstm);
      bs_plot->h2pi_probnne_dstar_sideband_high->Fill(Pd_ProbNNe,dstm);

      bs_plot->h2kpisb_hi->Fill(beta,(k_daughter_as_pi+pi_daughter).M());
      bs_plot->hmkpisb_cut_range_hi->Fill(dstm);
    }

    if(((k_daughter + pi_daughter).M()*1e3-1864.84) <-5*8 &&((k_daughter + pi_daughter).M()*1e3-1864.84)>-8*8.){//lo side
      bs_plot->h2k_probnnmu_dstar_sideband_low->Fill(K_ProbNNmu,dstm);
      bs_plot->h2k_probnne_dstar_sideband_low->Fill(K_ProbNNe,dstm);
      bs_plot->h2pi_probnnmu_dstar_sideband_low->Fill(Pd_ProbNNmu,dstm);
      bs_plot->h2pi_probnne_dstar_sideband_low->Fill(Pd_ProbNNe,dstm);
        
      bs_plot->h2kpisb_lo->Fill(beta,(k_daughter_as_pi+pi_daughter).M());
      bs_plot->hmkpisb_cut_range_lo->Fill(dstm);
    }
    if(((k_daughter + pi_daughter).M()*1e3-1864.84) >5*8 && ((k_daughter + pi_daughter).M()*1e3-1864.84)<=52){//high side, region 1
      bs_plot->hmkpisb_cut_range_hi_1->Fill(dstm);
    }
    if(((k_daughter + pi_daughter).M()*1e3-1864.84) >52 && ((k_daughter + pi_daughter).M()*1e3-1864.84)<64){//high side, region 2
      bs_plot->hmkpisb_cut_range_hi_2->Fill(dstm);
    }

    if(((k_daughter + pi_daughter).M()*1e3-1864.84) <-5*8 && ((k_daughter + pi_daughter).M()*1e3-1864.84)>=-52){//low side, region 1
      bs_plot->hmkpisb_cut_range_lo_1->Fill(dstm);
    }
    if(((k_daughter + pi_daughter).M()*1e3-1864.84)<-52 && ((k_daughter + pi_daughter).M()*1e3-1864.84)>-64){//low side, region 2
      bs_plot->hmkpisb_cut_range_lo_2->Fill(dstm);
    }
      
      
    //if(!doD0plots)continue;
    //fill the d0 mass histograms too
    //if WS, blind the signal region
    //cout<<"(k_daughter + pi_daughter).M() = "<<(k_daughter + pi_daughter).M()<<endl;
    
    if(!(fabs((k_daughter+pi_daughter).M()*1e3-1864.84)<dmass_cut)){ //continue;
    bs_plot->hmD0_pik_tot->Fill((pi_daughter_as_k+k_daughter_as_pi).M()*1e3);
    if(fabs(dstm - 2010.26)<0.9){
      bs_plot->hmD0_pik_sig->Fill((pi_daughter_as_k+k_daughter_as_pi).M()*1e3);
    }
    else if((fabs(dstm - 2010.26)>3)){
      bs_plot->hmD0_pik_sb->Fill((pi_daughter_as_k+k_daughter_as_pi).M()*1e3);
    }
    }
    
    //now that the beta star plots are filled, we can make the rest of the plots
    //rest of analysis cuts.
    
    
    if(!(
         TMath::Abs((k_daughter + pi_daughter).M()*1e3 - pdg_d0_m)<24 &&
         TMath::Abs((pi_daughter_as_k+k_daughter).M()-pdg_d0_m)>40 &&
         TMath::Abs((k_daughter_as_pi+pi_daughter).M()-pdg_d0_m)>40
         ))continue;
    //fill the mass histogram
    //cout<<"filling with dstm = "<<dstm<<endl;
    
    dstar_mass_plot->Fill(dstm);
  }//loop on events
  
}
