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
#include <fstream>
#include <TLeaf.h>
#include <algorithm>
#include <TTreeFormula.h>
using namespace std;
bool DT_D0_mix_CPV::matchElement (matchelement_t i, matchelement_t j) {
  double tol =0.1;
  bool ret=
    ((i.eventNumber==j.eventNumber)&&
     (i.runNumber==j.runNumber)&&
     (i.kpx==j.kpx)&&
     (i.kpy==j.kpy)&&
     (i.kpz==j.kpz)&&
     (i.pipx==j.pipx)&&
     (i.pipy==j.pipy)&&
     fabs((i.pipz-j.pipz))<tol&&
     fabs((i.pispx-j.pispx))<tol&&
     fabs((i.pispy-j.pispy))<tol&&
     fabs((i.pispz-j.pispz))<tol
     );
  
  // if(ret==true){
  //   cout<<"testing the remaining fields"<<endl;
  //   cout<<"d pi pz = "<<i.pipz-j.pipz<<endl;
  // }
  return ret;
}


bool DT_D0_mix_CPV::foundMatch(matchelement_t el){
  bool res = false;
  //for(auto val : matchedToPrompt){
  
  for( std::vector<matchelement_t>::iterator it = matchedToPrompt.begin(); it!= matchedToPrompt.end();++it){
    matchelement_t val = (*it);//want the iterator to erase after.
    if(res == true)return 1;
    res = matchElement(el,val/*(*it)*/);
    if(res==true){
      //      cout<<"matched to"<<endl;
      //cout<<"\t"<<val.eventNumber<<"\t"<<val.runNumber<<"\t"<<val.kpx<<"\t"<<val.kpy<<"\t"<<val.kpz<<"\t"<<val.pipx<<"\t"<<val.pipy<<"\t"<<val.pipz<<"\t"<<val.pispx<<"\t"<<val.pispy<<"\t"<<val.pispz<<endl;
      //      cout<<"orig was"<<endl;
      //      cout<<"\t"<<el.eventNumber<<"\t"<<el.runNumber<<"\t"<<el.kpx<<"\t"<<el.kpy<<"\t"<<el.kpz<<"\t"<<el.pipx<<"\t"<<el.pipy<<"\t"<<el.pipz<<"\t"<<el.pispx<<"\t"<<el.pispy<<"\t"<<el.pispz<<endl;
      //cout<<"before, val.toBeRemoved = "<<val.toBeRemoved<<endl;
      val.toBeRemoved = 1;
      //cout<<"set val.toBeRemoved to "<<val.toBeRemoved<<endl;
      //erase the element
      matchedToPrompt.erase(it);
      //cout<<"matchedToPrompt.size() = "<<matchedToPrompt.size()<<endl;
    }
   
  }
  return res;
}

void DT_D0_mix_CPV::setRejectionFile(TString path_to_file){
  //read a file from the path, then set the rejection vector accordingly.
  matchelement_t elem;
  ifstream infile(path_to_file.Data());
  std::string line;
  if(infile.is_open()){
    std::cout<<"reading file "<<path_to_file<<std::endl;
    getline(infile,line);//skip the header
    double kpx,kpy,kpz,pipx,pipy,pipz,pispx,pispy,pispz;
    UInt_t runNum;
    ULong64_t evNum;
    std::cout<<"Testing read"<<std::endl;
    while(infile>>evNum>>runNum>>kpx>>kpy>>kpz>>pipx>>pipy>>pipz>>pispx>>pispy>>pispz){
      elem.eventNumber = evNum;
      elem.runNumber =runNum;
      elem.kpx = kpx;
      elem.kpy = kpy;
      elem.kpz = kpz;
      elem.pipx = pipx;
      elem.pipy = pipy;
      elem.pipz = pipz;
      elem.pispx = pispx;
      elem.pispy = pispy;
      elem.pispz = pispz;
      elem.toBeRemoved = false;
      matchedToPrompt.push_back(elem);
    }    
    //now sort by event number    
    cout<<"done reading file, length of matchedToPrompt = "<<matchedToPrompt.size()<<endl;
    //sort by event number.
    std::sort(matchedToPrompt.begin(),matchedToPrompt.end(),sorter);
  }
  else{
    std::cout<<"Cannot read the input file! This will fail!"<<std::endl;
    //assert(0);
  }
  return;
}

void DT_D0_mix_CPV::Loop()
{
  cout<<"using extra cut "<<ExtraCut<<endl;
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

  TTreeFormula extraCutFormula(Form("%s_extra_cut",fChain->GetName()),ExtraCut,fChain);
  extraCutFormula.GetNdata();
  fChain->SetNotify(&extraCutFormula);//let the chain know about the formula.

  Long64_t nentries = fChain->GetEntriesFast();
  matchelement_t currElem;
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
    if(jentry%100000==0)std::cout<<"processed "<<jentry<<" events"<<std::endl;

    //make the match for prompt sample
    currElem.eventNumber = eventNumber;
    currElem.runNumber = runNumber;
    currElem.kpx = K_PX;
    currElem.kpy = K_PY;
    currElem.kpz = K_PZ;
    currElem.pipx =Pd_PX;
    currElem.pipy =Pd_PY;
    currElem.pipz =Pd_PZ;
    currElem.pispx =Ps_PX;
    currElem.pispy =Ps_PY;
    currElem.pispz =Ps_PZ;
    //cout<<"testing "<<currElem.eventNumber<<endl;
    if(foundMatch(currElem)){
      //cout<<"new vector length = "<<matchedToPrompt.size()<<endl;
      cout<<"removing prompt event"<<endl;
      continue;
    }
    
    //cuts
    if(!(
         B_VFit_status[0]==0 &&
	 //combined pid samples
	 // ((K_PIDK>kpidk_cut&&Pd_PIDK<pi_dau_pidk_cut)//tight tight
	 //  ||(K_PIDK>kpidk_cut&&Pd_PIDK<2 && Pd_PIDK>=-5)//tight loose
	 //  ||(K_PIDK>2.&&K_PIDK<=8.&&Pd_PIDK<pi_dau_pidk_cut)//loose tight
	 //  )&&
	 //take2
	 // ((K_PIDK>kpidk_cut&&Pd_PIDK<pi_dau_pidk_cut)//tight tight
	 //  ||(K_PIDK>kpidk_cut&&Pd_PIDK<-2 && Pd_PIDK>=-5)//tight loose
	 //  ||(K_PIDK>5.&&K_PIDK<=8.&&Pd_PIDK<pi_dau_pidk_cut)//loose tight
	 //  )&&
	 K_PIDK>kpidk_cut&&//tight K
	 //K_PIDK>5.&&K_PIDK<=8.&&//loose K, changed from 2
	 Pd_PIDK<pi_dau_pidk_cut &&//tight pi
	 //Pd_PIDK<-2 && Pd_PIDK>=-5 &&//loose pi//changed from +2
	 
         Ps_PIDe<pi_slow_pide_cut &&
         //Ps_ProbNNghost<pi_slow_probnnghost_cut &&//bullshit leftovers
         Mu_L0MuonDecision_TOS==1&&
	 //Mu_L0MuonDecision_TIS==1&&
         Mu_Hlt1TrackMuonDecision_TOS==1&&
         (B_Hlt2TopoMu2BodyBBDTDecision_TOS==1 ||
	  B_Hlt2TopoMu3BodyBBDTDecision_TOS==1||
	  B_Hlt2TopoMu4BodyBBDTDecision_TOS==1)&&
         Mu_isMuon &&
         Mu_MC12TuneV2_ProbNNmu > mu_probnnmu_cut&&
         !Ps_isMuon &&
	 Ps_MC12TuneV2_ProbNNghost< pis_ghost_prob_cut &&
	 //TMath::Log(Mu_IPCHI2_OWNPV)>mu_log_ip_chi2_cut &&
	 //Mu_IPCHI2_OWNPV>mu_ip_chi2_cut&&
	 B_VFit_chi2[0]/B_VFit_nDOF[0]<dtf_chi2_ndf_cut
	 
	 //B_FDCHI2_OWNPV > b_fd_cut
	 //&& Ps_PT > pis_pt_cut
	 //&&Ps_MC12TuneV2_ProbNNp<pis_probnnp_cut
	 //&& Mu_IPCHI2_OWNPV > mu_ip_chi2_cut
         //&&Mu_MC12TuneV3_ProbNNmu > mu_probnnmu_cut
         
         )) continue;
    if(!extraCutFormula.EvalInstance()){//add extra cut from command line
      //cout<<"didn't pass extra cut"<<endl;
      continue;
    }
    //decay time cut
    if((B_VFit_D0_ctau[0]/ d0_pdg_ct)<d0_td0_bin_boundary1 )continue;
    //now do a truthmatching
    
    if(isMC){
      Int_t Pd_TRUEID = fChain->GetLeaf("Pd_TRUEID")->GetValue();
      Int_t Ps_TRUEID = fChain->GetLeaf("Ps_TRUEID")->GetValue();
      Int_t K_TRUEID = fChain->GetLeaf("K_TRUEID")->GetValue();
      Int_t D_TRUEID = fChain->GetLeaf("D_TRUEID")->GetValue();
      Int_t Dstar_TRUEID = fChain->GetLeaf("Dstar_TRUEID")->GetValue();
      Int_t Mu_TRUEID = fChain->GetLeaf("Mu_TRUEID")->GetValue();
      Int_t B_TRUEID = fChain->GetLeaf("B_TRUEID")->GetValue();
      Int_t Pd_MC_MOTHER_ID = fChain->GetLeaf("Pd_MC_MOTHER_ID")->GetValue();
      Int_t K_MC_MOTHER_ID = fChain->GetLeaf("K_MC_MOTHER_ID")->GetValue();
      Int_t D_MC_MOTHER_ID = fChain->GetLeaf("D_MC_MOTHER_ID")->GetValue();
      Int_t Ps_MC_MOTHER_ID = fChain->GetLeaf("Ps_MC_MOTHER_ID")->GetValue();
      Int_t Dstar_MC_MOTHER_ID = fChain->GetLeaf("Dstar_MC_MOTHER_ID")->GetValue();
      Int_t Mu_MC_MOTHER_ID = fChain->GetLeaf("Mu_MC_MOTHER_ID")->GetValue();
      Int_t Pd_MC_GD_MOTHER_ID = fChain->GetLeaf("Pd_MC_GD_MOTHER_ID")->GetValue();
      Int_t K_MC_GD_MOTHER_ID = fChain->GetLeaf("K_MC_GD_MOTHER_ID")->GetValue();
      Int_t D_MC_GD_MOTHER_ID = fChain->GetLeaf("D_MC_GD_MOTHER_ID")->GetValue();
      Int_t Dstar_MC_GD_MOTHER_ID = fChain->GetLeaf("Dstar_MC_GD_MOTHER_ID")->GetValue();
      Int_t Dstar_MC_GD_GD_MOTHER_ID = fChain->GetLeaf("Dstar_MC_GD_GD_MOTHER_ID")->GetValue();
      //Int_t Mu_MC_GD_MOTHER_ID = fChain->GetLeaf("Mu_MC_GD_MOTHER_ID")->GetValue();

      Int_t Pd_MC_MOTHER_KEY = fChain->GetLeaf("Pd_MC_MOTHER_KEY")->GetValue();
      Int_t K_MC_MOTHER_KEY = fChain->GetLeaf("K_MC_MOTHER_KEY")->GetValue();
      Int_t D_MC_MOTHER_KEY = fChain->GetLeaf("D_MC_MOTHER_KEY")->GetValue();
      Int_t Ps_MC_MOTHER_KEY = fChain->GetLeaf("Ps_MC_MOTHER_KEY")->GetValue();
      Int_t Dstar_MC_MOTHER_KEY = fChain->GetLeaf("Dstar_MC_MOTHER_KEY")->GetValue();
      Int_t Mu_MC_MOTHER_KEY = fChain->GetLeaf("Mu_MC_MOTHER_KEY")->GetValue();
      Int_t Pd_MC_GD_MOTHER_KEY = fChain->GetLeaf("Pd_MC_GD_MOTHER_KEY")->GetValue();
      Int_t K_MC_GD_MOTHER_KEY = fChain->GetLeaf("K_MC_GD_MOTHER_KEY")->GetValue();
      Int_t D_MC_GD_MOTHER_KEY = fChain->GetLeaf("D_MC_GD_MOTHER_KEY")->GetValue();
      Int_t Dstar_MC_GD_MOTHER_KEY = fChain->GetLeaf("Dstar_MC_GD_MOTHER_KEY")->GetValue();
      Int_t Dstar_MC_GD_GD_MOTHER_KEY = fChain->GetLeaf("Dstar_MC_GD_GD_MOTHER_KEY")->GetValue();
      //Int_t Mu_MC_GD_MOTHER_KEY = fChain->GetLeaf("Mu_MC_GD_MOTHER_KEY")->GetValue();
      
      bool idMatch = TMath::Abs(Pd_TRUEID)==211 && TMath::Abs(Ps_TRUEID)==211 && TMath::Abs(K_TRUEID)==321 && TMath::Abs(D_TRUEID)==421 && TMath::Abs(Dstar_TRUEID)==413 && TMath::Abs(Mu_TRUEID)==13 && TMath::Abs(B_TRUEID)==511;
      bool d0match = Pd_MC_MOTHER_ID ==K_MC_MOTHER_ID && Pd_MC_MOTHER_ID== D_TRUEID;//pion and kaon are matched to D0
      bool dstarmatch = Dstar_TRUEID==D_MC_MOTHER_ID && D_MC_MOTHER_ID==Ps_MC_MOTHER_ID && Pd_MC_GD_MOTHER_ID==D_MC_MOTHER_ID && K_MC_GD_MOTHER_ID==D_MC_MOTHER_ID;//pi daughter, k, slow pion and D are matched to dstar;
      bool bmatch = (Dstar_MC_MOTHER_ID==Mu_MC_MOTHER_ID || Dstar_MC_GD_MOTHER_ID == Mu_MC_MOTHER_ID || Dstar_MC_GD_GD_MOTHER_ID==Mu_MC_MOTHER_ID);//match the D* or higher resonance to the muon
      bool bmatch2= Dstar_MC_MOTHER_ID==B_TRUEID && D_MC_GD_MOTHER_ID == B_TRUEID && D_MC_GD_MOTHER_ID == Dstar_MC_MOTHER_ID;
      bool truth_match_ids = idMatch+d0match+dstarmatch+bmatch+bmatch2 &&Dstar_MC_MOTHER_ID!=0;

      //match keys as well
      bool d0KeyMatch = Pd_MC_MOTHER_KEY ==K_MC_MOTHER_KEY;//pion and kaon are matched to D0
      bool dstarKeyMatch =  D_MC_MOTHER_KEY==Ps_MC_MOTHER_KEY && Pd_MC_GD_MOTHER_KEY==D_MC_MOTHER_KEY && K_MC_GD_MOTHER_KEY==D_MC_MOTHER_KEY;//pi daughter, k, slow pion and D are matched to dstar;
      bool bKeyMatch = (Dstar_MC_MOTHER_KEY==Mu_MC_MOTHER_KEY || Dstar_MC_GD_MOTHER_KEY == Mu_MC_MOTHER_KEY || Dstar_MC_GD_GD_MOTHER_KEY==Mu_MC_MOTHER_KEY);//match the D* or higher resonance to the muon
      bool bKeyMatch2= (D_MC_GD_MOTHER_KEY==Dstar_MC_MOTHER_KEY);
      bool truth_match_keys = d0KeyMatch+dstarKeyMatch+bKeyMatch+bKeyMatch2;

      //bool promptDstars = idMatch&&d0match&&dstarmatch&&!Dstar_MC_MOTHER_ID==Mu_MC_MOTHER_ID && !Dstar_MC_GD_MOTHER_ID &&!Mu_MC_MOTHER_ID && !Dstar_MC_GD_GD_MOTHER_ID==Mu_MC_MOTHER_ID;
      //bool promptDstars2= d0KeyMatch&&dstarKeyMatch&&!Dstar_MC_MOTHER_KEY==Mu_MC_MOTHER_KEY && !Dstar_MC_GD_MOTHER_KEY == Mu_MC_MOTHER_KEY && !Dstar_MC_GD_GD_MOTHER_KEY==Mu_MC_MOTHER_KEY;
      bool Dstar_MC_ISPROMPT;
      if(isPromptMC){Dstar_MC_ISPROMPT = fChain->GetLeaf("Dstar_MC_ISPROMPT")->GetValue();
	if(!Dstar_MC_ISPROMPT) continue;
      }
      bool totalTruthMatch = truth_match_ids&&truth_match_keys;//+&&+d0Econs+&&+d0PxCons+&&+d0PyCons+&&+d0PzCons; 
      if(! totalTruthMatch)continue;
    }
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
    mu_from_b.SetXYZM(B_VFit_muminus_PX[0]/1e3,
		       B_VFit_muminus_PY[0]/1e3,
		       B_VFit_muminus_PZ[0]/1e3,
		       105.6583715/1e3);
    //cout<<"pi_daugter.E ="<<pi_daughter.E()<<endl;
    //cut on dstar pt
    //if((d0_vector+slow_pion_vec).Pt()/*GeV*/<1/*GeV*/)continue;
    Double_t dstm = (d0_vector+slow_pion_vec).M()*1e3;
    Double_t Pis_CHARGE = Ps_ID/211.;
    Double_t Pi_CHARGE = Pd_ID/211.;
    Double_t beta = Pis_CHARGE*Pi_CHARGE*(pi_daughter.P()-k_daughter_as_pi.P())/(k_daughter_as_pi.P()+pi_daughter.P());
    //fill the d0 mass plot without any cuts on delta M to show the cut range
    d0_mass_plot->Fill((k_daughter+pi_daughter).M()*1e3);
    //fill this cutting on dstar M!
    if(fabs(dstm-pdg_dstar_m)<dstar_mass_cut){
      d0_mass_plot_sig_rej->Fill((k_daughter+pi_daughter).M()*1e3);
    }
    
    //add the d mass cuts too for the b mass plots.
    if(TMath::Abs((k_daughter + pi_daughter).M()*1e3 - pdg_d0_m)<24 &&
       TMath::Abs((pi_daughter_as_k+k_daughter).M()*1e3-pdg_d0_m)>40 &&
       TMath::Abs((k_daughter_as_pi+pi_daughter).M()*1e3-pdg_d0_m)>40)
    {
      
      b_mass_plot->Fill(B_VFit_M[0]);
      //deltaBmass->Fill((mu_from_b+slow_pion_vec+d0_vector).M()-(slow_pion_vec+d0_vector).M());
      //decay times.
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2){b_mass_plot_time_bin1->Fill(B_VFit_M[0]);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3){b_mass_plot_time_bin2->Fill(B_VFit_M[0]);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4){b_mass_plot_time_bin3->Fill(B_VFit_M[0]);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5){b_mass_plot_time_bin4->Fill(B_VFit_M[0]);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5){b_mass_plot_time_bin5->Fill(B_VFit_M[0]);}
    }

    //fill bmass cuts now, so that we have everything ok.
    if(!(B_VFit_M[0] < bmass_cut_hi &&B_VFit_M[0] > bmass_cut_low))continue;

    bs_plot->h2tot->Fill(beta,(k_daughter_as_pi+pi_daughter).M());
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
      //consistent with being in the signal region of the swapped kpi mass, fill the d0 plots
      
      
      if(dstm>2015 && dstm <2025){//background region
	bs_plot->double_misid_dmass_dst_sideband_region->Fill((k_daughter+pi_daughter).M()*1e3);
	if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2){bs_plot->double_misid_dmass_dst_sideband_region_bin1->Fill((k_daughter+pi_daughter).M()*1e3);}
	if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3){bs_plot->double_misid_dmass_dst_sideband_region_bin2->Fill((k_daughter+pi_daughter).M()*1e3);}
	if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4){bs_plot->double_misid_dmass_dst_sideband_region_bin3->Fill((k_daughter+pi_daughter).M()*1e3);}
	if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5){bs_plot->double_misid_dmass_dst_sideband_region_bin4->Fill((k_daughter+pi_daughter).M()*1e3);}
	if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5){bs_plot->double_misid_dmass_dst_sideband_region_bin5->Fill((k_daughter+pi_daughter).M()*1e3);}
      }
      if(fabs(dstm - pdg_dstar_m)<dstar_mass_cut){
	bs_plot->double_misid_dmass_dst_sig_region->Fill((k_daughter+pi_daughter).M()*1e3);
		if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2){bs_plot->double_misid_dmass_dst_sig_region_bin1->Fill((k_daughter+pi_daughter).M()*1e3);}
	if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3){bs_plot->double_misid_dmass_dst_sig_region_bin2->Fill((k_daughter+pi_daughter).M()*1e3);}
	if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4){bs_plot->double_misid_dmass_dst_sig_region_bin3->Fill((k_daughter+pi_daughter).M()*1e3);}
	if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5){bs_plot->double_misid_dmass_dst_sig_region_bin4->Fill((k_daughter+pi_daughter).M()*1e3);}
	if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5){bs_plot->double_misid_dmass_dst_sig_region_bin5->Fill((k_daughter+pi_daughter).M()*1e3);}
      }
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
    //exclude the kk and pi pi by hand
    if(TMath::Abs((pi_daughter_as_k+k_daughter).M()*1e3-pdg_d0_m)>40 &&
       TMath::Abs((k_daughter_as_pi+pi_daughter).M()*1e3-pdg_d0_m)>40){
      //ranges are 1790+(5.8*n)-(1790+5.8*(n+1))
      //so
      //1790-1795.8
      //1795.8 - 1801.6
      //1801.6 - 1807.4
      //1807.4 - 1813.2
      //1813.2 - 1819
      //1819 - 1824.84
      //lo sideband
      if((k_daughter+pi_daughter).M()*1e3>1790 && (k_daughter+pi_daughter).M()*1e3<=1795.8){
	bs_plot->hmkpisb_cut_range_lo_1->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_lo_1->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_lo_1->Fill(dstm);}//negative
      }
      if((k_daughter+pi_daughter).M()*1e3>1795.8 && (k_daughter+pi_daughter).M()*1e3<=1801.6){
	bs_plot->hmkpisb_cut_range_lo_2->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_lo_2->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_lo_2->Fill(dstm);}//negative
      }
      if((k_daughter+pi_daughter).M()*1e3>1801.6 && (k_daughter+pi_daughter).M()*1e3<=1807.4){
	bs_plot->hmkpisb_cut_range_lo_3->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_lo_3->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_lo_3->Fill(dstm);}//negative
      }
      if((k_daughter+pi_daughter).M()*1e3>1807.4 && (k_daughter+pi_daughter).M()*1e3<=1813.2){
	bs_plot->hmkpisb_cut_range_lo_4->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_lo_4->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_lo_4->Fill(dstm);}//negative
      }
      if((k_daughter+pi_daughter).M()*1e3>1813.2 && (k_daughter+pi_daughter).M()*1e3<=1819.){
	bs_plot->hmkpisb_cut_range_lo_5->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_lo_5->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_lo_5->Fill(dstm);}//negative
      }
      if((k_daughter+pi_daughter).M()*1e3>1819. && (k_daughter+pi_daughter).M()*1e3<=(pdg_d0_m-40)){
	bs_plot->hmkpisb_cut_range_lo_6->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_lo_6->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_lo_6->Fill(dstm);}//negative
      }
      //hi sideband
      //here we have
      //1904.84 - 1911.
      //1911. - 1916.8
      //1916.8 - 1922.6
      //1922.6 - 1928.4
      //1928.4 - 1934.2
      //1934.2 - 1940
      //give the closest bins to the blinded region a bit more statistics
      if((k_daughter+pi_daughter).M()*1e3>(pdg_d0_m+40) && (k_daughter+pi_daughter).M()*1e3<=1911.){
	bs_plot->hmkpisb_cut_range_hi_1->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_hi_1->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_hi_1->Fill(dstm);}//negative
      }
      if((k_daughter+pi_daughter).M()*1e3>1911. && (k_daughter+pi_daughter).M()*1e3<=1916.8){
	bs_plot->hmkpisb_cut_range_hi_2->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_hi_2->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_hi_2->Fill(dstm);}//negative
      }
      if((k_daughter+pi_daughter).M()*1e3>1916.8 && (k_daughter+pi_daughter).M()*1e3<=1922.6){
	bs_plot->hmkpisb_cut_range_hi_3->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_hi_3->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_hi_3->Fill(dstm);}//negative
      }
      if((k_daughter+pi_daughter).M()*1e3>1922.6 && (k_daughter+pi_daughter).M()*1e3<=1928.4){
	bs_plot->hmkpisb_cut_range_hi_4->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_hi_4->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_hi_4->Fill(dstm);}//negative
      }
      if((k_daughter+pi_daughter).M()*1e3>1928.4 && (k_daughter+pi_daughter).M()*1e3<=1934.2){
	bs_plot->hmkpisb_cut_range_hi_5->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_hi_5->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_hi_5->Fill(dstm);}//negative
      }
      if((k_daughter+pi_daughter).M()*1e3>1934.2 && (k_daughter+pi_daughter).M()*1e3<=1940.){
	bs_plot->hmkpisb_cut_range_hi_6->Fill(dstm);
	if(Pis_CHARGE>0){bs_plot->hmkpisb_pos_cut_range_hi_6->Fill(dstm);}//positive
	if(Pis_CHARGE<0){bs_plot->hmkpisb_neg_cut_range_hi_6->Fill(dstm);}//negative
      }
    }
    //END OF TIME BINS
    
    //if(!doD0plots)continue;
    //fill the d0 mass histograms too
    //if WS, blind the signal region
    //cout<<"(k_daughter + pi_daughter).M() = "<<(k_daughter + pi_daughter).M()<<endl;
    
    if(!(fabs((k_daughter+pi_daughter).M()*1e3-1864.84)<dmass_cut)){ //continue;
      bs_plot->hmD0_pik_tot->Fill((pi_daughter_as_k+k_daughter_as_pi).M()*1e3);
      if(fabs(dstm - 2010.26)<0.9){
	bs_plot->hmD0_pik_sig->Fill((pi_daughter_as_k+k_daughter_as_pi).M()*1e3);
      }
      if((fabs(dstm - 2010.26)>3)){
	bs_plot->hmD0_pik_sb->Fill((pi_daughter_as_k+k_daughter_as_pi).M()*1e3);
      }
    }
    //now the whole thing again for positive and negative
    
    //now that the beta star plots are filled, we can make the rest of the plots
    //rest of analysis cuts.
    
    
    if(!(
         TMath::Abs((k_daughter + pi_daughter).M()*1e3 - pdg_d0_m)<24 &&
         TMath::Abs((pi_daughter_as_k+k_daughter).M()*1e3-pdg_d0_m)>40 &&
         TMath::Abs((k_daughter_as_pi+pi_daughter).M()*1e3-pdg_d0_m)>40
         ))continue;
    //fill the mass histogram
    //cout<<"filling with dstm = "<<dstm<<endl;
    decay_time_distr->Fill(B_VFit_D0_ctau[0]/ d0_pdg_ct);
    //pos neg
    if(Pis_CHARGE>0){decay_time_distr_pos->Fill(B_VFit_D0_ctau[0]/ d0_pdg_ct);}
    else{decay_time_distr_neg->Fill(B_VFit_D0_ctau[0]/ d0_pdg_ct);}
    //
    dstar_mass_plot->Fill(dstm);
    if(Ps_ID/TMath::Abs(Ps_ID)>0)dstar_mass_plot_pos->Fill(dstm);
    else dstar_mass_plot_neg->Fill(dstm);
    dstar_mass_vs_muIPchi2->Fill(TMath::Log(Mu_IPCHI2_OWNPV),dstm);
    double dstpt=(d0_vector+slow_pion_vec).Pt()*1e3;
    double dstp = (d0_vector+slow_pion_vec).P()*1e3;
    
    dstar_pt->Fill(dstpt);
    dstar_p->Fill(dstp);
    double mup = mu_from_b.P()*1e3;
    double mupt = mu_from_b.Pt()*1e3;
    mu_pt->Fill(mupt);
    mu_p->Fill(mup);
    mu_log_ip->Fill(log(Mu_IP_OWNPV));
    pis_ghost_prob->Fill(Ps_MC12TuneV2_ProbNNghost);
    if(Pis_CHARGE>0){pis_ghost_prob_pos->Fill(Ps_MC12TuneV2_ProbNNghost);}
    if(Pis_CHARGE<0){pis_ghost_prob_neg->Fill(Ps_MC12TuneV2_ProbNNghost);}
      
    pis_match_chi2->Fill(Ps_TRACK_MatchCHI2);
    if(Pis_CHARGE>0){pis_match_chi2_pos->Fill(Ps_TRACK_MatchCHI2);}
    if(Pis_CHARGE<0){pis_match_chi2_neg->Fill(Ps_TRACK_MatchCHI2);}
    pis_match_chi2_vs_dstm->Fill(dstm,Ps_TRACK_MatchCHI2);
    pis_match_chi2_vs_td0->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),Ps_TRACK_MatchCHI2);
    //pid stuff
    dst_mass_vs_kpidk->Fill(K_PIDK,dstm);
    dst_mass_vs_pipidk->Fill(Pd_PIDK,dstm);
    b_flight_dist->Fill(B_FD_OWNPV);
    //dstar pt
    if(dstpt<dst_pt_bin_boundary1){dstar_mass_pt_bin1->Fill(dstm);}
    else if(dstpt>=dst_pt_bin_boundary1 && dstpt < dst_pt_bin_boundary2){dstar_mass_pt_bin2->Fill(dstm);}
    else if(dstpt>=dst_pt_bin_boundary2 && dstpt < dst_pt_bin_boundary3){dstar_mass_pt_bin3->Fill(dstm);}
    else if(dstpt>=dst_pt_bin_boundary3 && dstpt < dst_pt_bin_boundary4){dstar_mass_pt_bin4->Fill(dstm);}
    else{dstar_mass_pt_bin5->Fill(dstm);}
    //p
    if(dstp<dst_p_bin_boundary1){dstar_mass_p_bin1->Fill(dstm);}
    else if(dstp>=dst_p_bin_boundary1 && dstp < dst_p_bin_boundary2){dstar_mass_p_bin2->Fill(dstm);}
    else if(dstp>=dst_p_bin_boundary2 && dstp < dst_p_bin_boundary3){dstar_mass_p_bin3->Fill(dstm);}
    else if(dstp>=dst_p_bin_boundary3 && dstp < dst_p_bin_boundary4){dstar_mass_p_bin4->Fill(dstm);}
    else{dstar_mass_p_bin5->Fill(dstm);}

    
    //mu pt
    if(mupt<mu_pt_bin_boundary1){mu_mass_pt_bin1->Fill(dstm);}
    else if(mupt>=mu_pt_bin_boundary1 && mupt < mu_pt_bin_boundary2){mu_mass_pt_bin2->Fill(dstm);}
    else if(mupt>=mu_pt_bin_boundary2 && mupt < mu_pt_bin_boundary3){mu_mass_pt_bin3->Fill(dstm);}
    else if(mupt>=mu_pt_bin_boundary3 && mupt < mu_pt_bin_boundary4){mu_mass_pt_bin4->Fill(dstm);}
    else{mu_mass_pt_bin5->Fill(dstm);}
    //p
    if(mup<mu_p_bin_boundary1){mu_mass_p_bin1->Fill(dstm);}
    else if(mup>=mu_p_bin_boundary1 && mup < mu_p_bin_boundary2){mu_mass_p_bin2->Fill(dstm);}
    else if(mup>=mu_p_bin_boundary2 && mup < mu_p_bin_boundary3){mu_mass_p_bin3->Fill(dstm);}
    else if(mup>=mu_p_bin_boundary3 && mup < mu_p_bin_boundary4){mu_mass_p_bin4->Fill(dstm);}
    else{mu_mass_p_bin5->Fill(dstm);}
    //log ip
    if(log(Mu_IP_OWNPV)<mu_log_ip_bin_boundary1){mu_log_ip_bin1->Fill(dstm);}
    else if(log(Mu_IP_OWNPV)>=mu_log_ip_bin_boundary1 && log(Mu_IP_OWNPV) < mu_log_ip_bin_boundary2){mu_log_ip_bin2->Fill(dstm);}
    else if(log(Mu_IP_OWNPV)>=mu_log_ip_bin_boundary2 && log(Mu_IP_OWNPV) < mu_log_ip_bin_boundary3){mu_log_ip_bin3->Fill(dstm);}
    else if(log(Mu_IP_OWNPV)>=mu_log_ip_bin_boundary3 && log(Mu_IP_OWNPV) < mu_log_ip_bin_boundary4){mu_log_ip_bin4->Fill(dstm);}
    else{mu_log_ip_bin5->Fill(dstm);}

    //kpidk alone
    
    if(K_PIDK<k_pid_k_bin_boundary1){k_pid_k_bin1->Fill(dstm);}
    else if(K_PIDK>=k_pid_k_bin_boundary1 && K_PIDK < k_pid_k_bin_boundary2){k_pid_k_bin2->Fill(dstm);}
    else if(K_PIDK>=k_pid_k_bin_boundary2 && K_PIDK < k_pid_k_bin_boundary3){k_pid_k_bin3->Fill(dstm);}
    else if(K_PIDK>=k_pid_k_bin_boundary3 && K_PIDK < k_pid_k_bin_boundary4){k_pid_k_bin4->Fill(dstm);}
    else{k_pid_k_bin5->Fill(dstm);}

    //pi pid k alone
    
    if(Pd_PIDK<pi_pid_k_bin_boundary1){pi_pid_k_bin1->Fill(dstm);}
    else if(Pd_PIDK>=pi_pid_k_bin_boundary1 && Pd_PIDK < pi_pid_k_bin_boundary2){pi_pid_k_bin2->Fill(dstm);}
    else if(Pd_PIDK>=pi_pid_k_bin_boundary2 && Pd_PIDK < pi_pid_k_bin_boundary3){pi_pid_k_bin3->Fill(dstm);}
    else if(Pd_PIDK>=pi_pid_k_bin_boundary3 && Pd_PIDK < pi_pid_k_bin_boundary4){pi_pid_k_bin4->Fill(dstm);}
    else{pi_pid_k_bin5->Fill(dstm);}
    
    std::vector<bool>kpid_bins,pipid_bins;
    kpid_bins.push_back(K_PIDK<k_pid_k_bin_boundary1);
    kpid_bins.push_back(K_PIDK>=k_pid_k_bin_boundary1 && K_PIDK < k_pid_k_bin_boundary2);
    kpid_bins.push_back(K_PIDK>=k_pid_k_bin_boundary2 && K_PIDK < k_pid_k_bin_boundary3);
    kpid_bins.push_back(K_PIDK>=k_pid_k_bin_boundary3 && K_PIDK < k_pid_k_bin_boundary4);
    kpid_bins.push_back(K_PIDK >=k_pid_k_bin_boundary4);
    
    pipid_bins.push_back(Pd_PIDK<pi_pid_k_bin_boundary1);
    pipid_bins.push_back(Pd_PIDK>=pi_pid_k_bin_boundary1 && Pd_PIDK < pi_pid_k_bin_boundary2);
    pipid_bins.push_back(Pd_PIDK>=pi_pid_k_bin_boundary2 && Pd_PIDK < pi_pid_k_bin_boundary3);
    pipid_bins.push_back(Pd_PIDK>=pi_pid_k_bin_boundary3 && Pd_PIDK < pi_pid_k_bin_boundary4);
    pipid_bins.push_back(Pd_PIDK >=pi_pid_k_bin_boundary4);
    
    TH1D* the_pid_bins[5][5]={{pi_pid_k_bin1_k_pid_k_bin1,
			       pi_pid_k_bin1_k_pid_k_bin2,
			       pi_pid_k_bin1_k_pid_k_bin3,
			       pi_pid_k_bin1_k_pid_k_bin4,
			       pi_pid_k_bin1_k_pid_k_bin5},
			      {pi_pid_k_bin2_k_pid_k_bin1,
			       pi_pid_k_bin2_k_pid_k_bin2,
			       pi_pid_k_bin2_k_pid_k_bin3,
			       pi_pid_k_bin2_k_pid_k_bin4,
			       pi_pid_k_bin2_k_pid_k_bin5},
			      {pi_pid_k_bin3_k_pid_k_bin1,
			       pi_pid_k_bin3_k_pid_k_bin2,
			       pi_pid_k_bin3_k_pid_k_bin3,
			       pi_pid_k_bin3_k_pid_k_bin4,
			       pi_pid_k_bin3_k_pid_k_bin5},
			      {pi_pid_k_bin4_k_pid_k_bin1,
			       pi_pid_k_bin4_k_pid_k_bin2,
			       pi_pid_k_bin4_k_pid_k_bin3,
			       pi_pid_k_bin4_k_pid_k_bin4,
			       pi_pid_k_bin4_k_pid_k_bin5},
			      {pi_pid_k_bin5_k_pid_k_bin1,
			       pi_pid_k_bin5_k_pid_k_bin2,
			       pi_pid_k_bin5_k_pid_k_bin3,
			       pi_pid_k_bin5_k_pid_k_bin4,
			       pi_pid_k_bin5_k_pid_k_bin5}};
			       
    //now the fun part. divide into the 5x5 matrix.
    for(unsigned int i_kpid =0; i_kpid<kpid_bins.size();++i_kpid){
      for(unsigned int j_pipid=0;j_pipid<pipid_bins.size();++j_pipid){
	//fill the binned things.
	if(kpid_bins[i_kpid] && pipid_bins[j_pipid]){
	  the_pid_bins[j_pipid][i_kpid]->Fill(dstm);
	}
      }
    }
    //decay time distr
    {
    if((B_VFit_D0_ctau[0]/ d0_pdg_ct)<-0.75){ td0_bin_neg10_to_neg075->Fill(dstm);}
    if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=-0.75&& (B_VFit_D0_ctau[0]/ d0_pdg_ct)<-0.5){ td0_bin_neg075_to_neg05->Fill(dstm);}
    if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2){
      td0_bin1->Fill(dstm);
    }
    if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3){td0_bin2->Fill(dstm);
    }
    if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4){
      td0_bin3->Fill(dstm);
    }
    if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5){
      td0_bin4->Fill(dstm);
    }
    if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5){td0_bin5->Fill(dstm);}
    }
    //check with more bins
    /*if((B_VFit_D0_ctau[0]/ d0_pdg_ct)<-0.75){ td0_bin_neg10_to_neg075->Fill(dstm);}
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=-0.75&& (B_VFit_D0_ctau[0]/ d0_pdg_ct)<-0.5){ td0_bin_neg075_to_neg05->Fill(dstm);}
        
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary1a){td0_bin1->Fill(dstm);}
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2){td0_bin2->Fill(dstm);}
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2a){td0_bin3->Fill(dstm);}
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3){td0_bin4->Fill(dstm);}
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3a){td0_bin5->Fill(dstm);}
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4){td0_bin6->Fill(dstm);}
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4a){td0_bin7->Fill(dstm);}
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5){td0_bin8->Fill(dstm);}
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5a){td0_bin9->Fill(dstm);}
    else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5a){td0_bin10->Fill(dstm);}*/
    //split by charge
    //pos
    if(Ps_ID/TMath::Abs(Ps_ID)>0){
      
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2){td0_pos_bin1->Fill(dstm);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3){td0_pos_bin2->Fill(dstm);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4){td0_pos_bin3->Fill(dstm);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5){td0_pos_bin4->Fill(dstm);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5){td0_pos_bin5->Fill(dstm);}
      
      /*
      
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary1a){td0_pos_bin1->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2){td0_pos_bin2->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2a){td0_pos_bin3->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3){td0_pos_bin4->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3a){td0_pos_bin5->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4){td0_pos_bin6->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4a){td0_pos_bin7->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5){td0_pos_bin8->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5a){td0_pos_bin9->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5a){td0_pos_bin10->Fill(dstm);}*/
    }else{
      
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2){td0_neg_bin1->Fill(dstm);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3){td0_neg_bin2->Fill(dstm);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4){td0_neg_bin3->Fill(dstm);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5){td0_neg_bin4->Fill(dstm);}
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5){td0_neg_bin5->Fill(dstm);}
      
      /*
      if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary1a){td0_neg_bin1->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary1a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2){td0_neg_bin2->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary2a){td0_neg_bin3->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary2a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3){td0_neg_bin4->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary3a){td0_neg_bin5->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary3a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4){td0_neg_bin6->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary4a){td0_neg_bin7->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary4a && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5){td0_neg_bin8->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5 && (B_VFit_D0_ctau[0]/ d0_pdg_ct) < d0_td0_bin_boundary5a){td0_neg_bin9->Fill(dstm);}
      else if((B_VFit_D0_ctau[0]/ d0_pdg_ct)>=d0_td0_bin_boundary5a){td0_neg_bin10->Fill(dstm);}*/
    }

    //slow pion boundaries.
    if(Ps_MC12TuneV2_ProbNNghost<the_pis_ghost_prob_bin_boundaries[0]){
      if(Pis_CHARGE>0){
	the_ghost_prob_bins_pos[0]->Fill(dstm);}
      else{the_ghost_prob_bins_neg[0]->Fill(dstm);}
    }
    for(int i=1; i<19;++i){
      if(Ps_MC12TuneV2_ProbNNghost>=the_pis_ghost_prob_bin_boundaries[i] && Ps_MC12TuneV2_ProbNNghost<the_pis_ghost_prob_bin_boundaries[i+1]){
	if(Pis_CHARGE>0){
	the_ghost_prob_bins_pos[i]->Fill(dstm);}
	else{the_ghost_prob_bins_neg[i]->Fill(dstm);}
      }
    }
    if(Ps_MC12TuneV2_ProbNNghost>=the_pis_ghost_prob_bin_boundaries[19]){
      if(Pis_CHARGE>0){
	the_ghost_prob_bins_pos[19]->Fill(dstm);}
      else{
	the_ghost_prob_bins_neg[19]->Fill(dstm);}
    }

    //efficiency,bkg rej plots for the same thing
    for(int i_gp=0; i_gp<10;++i_gp){
      if(Ps_MC12TuneV2_ProbNNghost<pis_gp_pf_vals[i_gp]){
	if(Pis_CHARGE>0){pis_gp_pass_pos[i_gp]->Fill(dstm);}
	else{pis_gp_pass_neg[i_gp]->Fill(dstm);}
      }else{
	if(Pis_CHARGE>0){pis_gp_fail_pos[i_gp]->Fill(dstm);}
	else{pis_gp_fail_neg[i_gp]->Fill(dstm);}
      }
    }
    
    //2D VS DSTM and td0
    
    b_flight_dist_vs_dstm->Fill(dstm,B_FD_OWNPV);
    b_corr_mass_vs_dstm->Fill(dstm,B_CORR_M);
    dtf_chi2_vs_dstm->Fill(dstm,B_VFit_chi2[0]);
    //muIPchi2_vs_dstm;
    b_endvertex_chi2_vs_dstm->Fill(dstm,B_ENDVERTEX_CHI2);
    b_fd_chi2_vs_dstm->Fill(dstm,B_FDCHI2_OWNPV);
    d_logIPchi2_vs_dstm->Fill(dstm,log(D_IPCHI2_OWNPV));
    
    b_flight_dist_vs_td0->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_FD_OWNPV);
    b_corr_mass_vs_td0->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_CORR_M);
    dtf_chi2_vs_td0->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_VFit_chi2[0]);
    muIPchi2_vs_td0->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),Mu_IPCHI2_OWNPV);
    muIPchi2_vs_td0_zoom->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),Mu_IPCHI2_OWNPV);
    logmuIPchi2_vs_td0->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),log(Mu_IPCHI2_OWNPV));
    b_endvertex_chi2_vs_td0->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_ENDVERTEX_CHI2);
    b_fd_chi2_vs_td0->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_FDCHI2_OWNPV);
    d_logIPchi2_vs_td0->Fill((B_VFit_D0_ctau[0]/d0_pdg_ct),log(D_IPCHI2_OWNPV));
    
    muon_vs_slow_pion_OWNPV_X->Fill(Ps_OWNPV_X,Mu_OWNPV_X);
    muon_vs_slow_pion_OWNPV_Y->Fill(Ps_OWNPV_Y,Mu_OWNPV_Y);
    muon_vs_slow_pion_OWNPV_Z->Fill(Ps_OWNPV_Z,Mu_OWNPV_Z);
    //angle between d0 and muon vectors
    //    cos_muon_d0_angle->Fill(TMath::Cos(d0_vector.Angle(mu_from_b.Vect())));
    cos_muon_d0_angle->Fill(((D_PX*Mu_PX)+(D_PY*Mu_PY))/(D_PT*Mu_PT));//Solve the dot product by hand, only for xy plane
    //pos
    if(Ps_ID/TMath::Abs(Ps_ID)>0){
      b_flight_dist_vs_dstm_pos->Fill(dstm,B_FD_OWNPV);
      b_corr_mass_vs_dstm_pos->Fill(dstm,B_CORR_M);
      dtf_chi2_vs_dstm_pos->Fill(dstm,B_VFit_chi2[0]);
      muIPchi2_vs_dstm_pos->Fill(dstm,Mu_IPCHI2_OWNPV);
      muIPchi2_vs_dstm_zoom_pos->Fill(dstm,Mu_IPCHI2_OWNPV);
      logmuIPchi2_vs_dstm_pos->Fill(dstm,log(Mu_IPCHI2_OWNPV));
      b_endvertex_chi2_vs_dstm_pos->Fill(dstm,B_ENDVERTEX_CHI2);
      b_fd_chi2_vs_dstm_pos->Fill(dstm,B_FDCHI2_OWNPV);
      d_logIPchi2_vs_dstm_pos->Fill(dstm,log(D_IPCHI2_OWNPV));    
      
      b_flight_dist_vs_td0_pos->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_FD_OWNPV);
      b_corr_mass_vs_td0_pos->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_CORR_M);
      dtf_chi2_vs_td0_pos->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_VFit_chi2[0]);
      muIPchi2_vs_td0_pos->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),Mu_IPCHI2_OWNPV);
      muIPchi2_vs_td0_zoom_pos->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),Mu_IPCHI2_OWNPV);
      logmuIPchi2_vs_td0_pos->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),log(Mu_IPCHI2_OWNPV));
      b_endvertex_chi2_vs_td0_pos->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_ENDVERTEX_CHI2);
      b_fd_chi2_vs_td0_pos->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_FDCHI2_OWNPV);
      d_logIPchi2_vs_td0_pos->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),log(D_IPCHI2_OWNPV));    
    }else if(Ps_ID/TMath::Abs(Ps_ID)<0){
      b_flight_dist_vs_dstm_neg->Fill(dstm,B_FD_OWNPV);
      b_corr_mass_vs_dstm_neg->Fill(dstm,B_CORR_M);
      dtf_chi2_vs_dstm_neg->Fill(dstm,B_VFit_chi2[0]);
      muIPchi2_vs_dstm_neg->Fill(dstm,Mu_IPCHI2_OWNPV);
      muIPchi2_vs_dstm_zoom_neg->Fill(dstm,Mu_IPCHI2_OWNPV);
      logmuIPchi2_vs_dstm_neg->Fill(dstm,log(Mu_IPCHI2_OWNPV));
      b_endvertex_chi2_vs_dstm_neg->Fill(dstm,B_ENDVERTEX_CHI2);
      b_fd_chi2_vs_dstm_neg->Fill(dstm,B_FDCHI2_OWNPV);
      d_logIPchi2_vs_dstm_neg->Fill(dstm,log(D_IPCHI2_OWNPV));    
    
      b_flight_dist_vs_td0_neg->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_FD_OWNPV);
      b_corr_mass_vs_td0_neg->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_CORR_M);
      dtf_chi2_vs_td0_neg->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_VFit_chi2[0]);
      muIPchi2_vs_td0_neg->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),Mu_IPCHI2_OWNPV);
      muIPchi2_vs_td0_zoom_neg->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),Mu_IPCHI2_OWNPV);
      logmuIPchi2_vs_td0_neg->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),log(Mu_IPCHI2_OWNPV));
      b_endvertex_chi2_vs_td0_neg->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_ENDVERTEX_CHI2);
      b_fd_chi2_vs_td0_neg->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),B_FDCHI2_OWNPV);
      d_logIPchi2_vs_td0_neg->Fill((B_VFit_D0_ctau[0]/ d0_pdg_ct),log(D_IPCHI2_OWNPV));
    }
      
    
  }//loop on events
  
}
