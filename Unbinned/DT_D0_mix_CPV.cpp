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
#include <TLeaf.h>
#include <algorithm>
#include <fstream>
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
    if(res == true)continue;
    res = matchElement(el,val);
    if(res==true){
      //cout<<"matched to"<<endl;
      //cout<<"\t"<<val.eventNumber<<"\t"<<val.runNumber<<"\t"<<val.kpx<<"\t"<<val.kpy<<"\t"<<val.kpz<<"\t"<<val.pipx<<"\t"<<val.pipy<<"\t"<<val.pipz<<"\t"<<val.pispx<<"\t"<<val.pispy<<"\t"<<val.pispz<<endl;
      //cout<<"before, val.toBeRemoved = "<<val.toBeRemoved<<endl;
      val.toBeRemoved = 1;
      //cout<<"set val.toBeRemoved to "<<val.toBeRemoved<<endl;
      //erase the element
      matchedToPrompt.erase(it);
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
  TString  tmpName = TString(fChain->GetName());
  tmpName.ReplaceAll("/DecayTree","");
  std::cout<<"tmpName = "<<tmpName<<std::endl;
  TFile* treeFile = new TFile(tmpName+"_treeFile.root","RECREATE");
  treeFile->cd();
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
	 K_PIDK>kpidk_cut&&//tight K
	 //K_PIDK>5.&&K_PIDK<=8.&&//loose K, changed from 2
	 Pd_PIDK<pi_dau_pidk_cut &&//tight pi
	 //Pd_PIDK<-2 && Pd_PIDK>=-5 &&//loose pi, changed from +2
	 
         Ps_PIDe<pi_slow_pide_cut &&
         Ps_ProbNNghost<pi_slow_probnnghost_cut &&
         Mu_L0MuonDecision_TOS==1&&
	 //Mu_L0MuonDecision_TIS==1&&
         Mu_Hlt1TrackMuonDecision_TOS==1&&
         (B_Hlt2TopoMu2BodyBBDTDecision_TOS==1 ||
	  B_Hlt2TopoMu3BodyBBDTDecision_TOS==1||
	  B_Hlt2TopoMu4BodyBBDTDecision_TOS==1)&&
         Mu_isMuon &&
         Mu_MC12TuneV2_ProbNNmu > mu_probnnmu_cut&&
         !Ps_isMuon &&
	 Ps_MC12TuneV2_ProbNNghost< pis_ghost_prob_cut&&
	 B_VFit_chi2[0]/B_VFit_nDOF[0]<dtf_chi2_ndf_cut
	 //&& Ps_PT > pis_pt_cut
	 //&&Ps_MC12TuneV2_ProbNNp<pis_probnnp_cut
	 //&& Mu_IPCHI2_OWNPV > mu_ip_chi2_cut
         //&&Mu_MC12TuneV3_ProbNNmu > mu_probnnmu_cut
         
         )) continue;
    //now do a truthmatching
    bool isMC = false;
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
    
    Double_t dstm = (d0_vector+slow_pion_vec).M()*1e3;
    Double_t Pis_CHARGE = Ps_ID/211.;
    Double_t Pi_CHARGE = Pd_ID/211.;
    newPiScharge = (int)Pis_CHARGE;
    newDstM = dstm;
    newBmass = B_VFit_M[0];    
    newD0M = (k_daughter+pi_daughter).M()*1e3;
    newDecayTime = (B_VFit_D0_ctau[0]/ d0_pdg_ct);
    newD0ipChi2 = D_IPCHI2_OWNPV;

    //add another tlorentz vector for the original kaon
    TLorentzVector origK;
    origK.SetXYZM(K_PX,K_PY,K_PZ,pdg_kplus_m);
    newKeta = origK.PseudoRapidity();
    Double_t beta = Pis_CHARGE*Pi_CHARGE*(pi_daughter.P()-k_daughter_as_pi.P())/(k_daughter_as_pi.P()+pi_daughter.P());
    
    if(!(
         TMath::Abs((k_daughter + pi_daughter).M()*1e3 - pdg_d0_m)<24 &&
         TMath::Abs((pi_daughter_as_k+k_daughter).M()*1e3-pdg_d0_m)>40 &&
         TMath::Abs((k_daughter_as_pi+pi_daughter).M()*1e3-pdg_d0_m)>40
         ))continue;
    //fill the mass histogram
    //cout<<"filling with dstm = "<<dstm<<endl;
    double dstpt=(d0_vector+slow_pion_vec).Pt()*1e3;
    double dstp = (d0_vector+slow_pion_vec).P()*1e3;
    double mup = mu_from_b.P()*1e3;
    double mupt = mu_from_b.Pt()*1e3;
    newTree->Fill();
    
  }//loop on events
  newTree->Write();
  //  treeFile->Write();
}
