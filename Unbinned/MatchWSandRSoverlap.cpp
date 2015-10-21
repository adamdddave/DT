//c++//c++
#include <iostream>
#include <cmath>
//root

#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TStyle.h>
#include <TLatex.h>
#include <TCanvas.h>
#include <TPad.h>
#include <TMath.h>
#include <TLine.h>
#include <TVector3.h>
#include <TPaveText.h>
#include <TString.h>
#include <TFile.h>
#include <TObject.h>
#include <TTree.h>
#include <TLegend.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TText.h>
//local
#include "DT_D0_mix_CPV.h"

using namespace std;

int main(int argc, char* const argv[]){
  cout<<"Finding the overlapping events in the WS and RS candidates"<<endl;
  cout<<"For the sake of your time and afs token, I certainly hope"<<endl;
  cout<<"you're not using the whole 2011 MD dataset, for example."<<endl;
  if(argc<2){
    cout<<"you didn't pass a file to output!!"<<endl;
    return 0;
  }
  const double pdg_d0_m = 1864.84;// MeV
  //const double pdg_dstar_m = 2010.26;// MeV
  const double pdg_kplus_m = 493.677;// MeV
  const double pdg_piplus_m = 139.57018;//MeV

  TChain* rs_tree = new TChain("RS/DecayTree");
  TChain* ws_tree = new TChain("WS/DecayTree");
  TString fname = argv[1];
  double diff = 1e-3;
  rs_tree->Add(fname);
  ws_tree->Add(fname);
  cout<<"now searching file "<<argv[1]<<endl;
  DT_D0_mix_CPV rsLooper(rs_tree);
  DT_D0_mix_CPV wsLooper(ws_tree);
  //now we have the two classes. We will loop over events in the RS tree, then look for event sin the WS tree which
  //match the k and pi momentum to the level of 1e-3. from there, we will write out the event information.
  Long64_t nentries_rs = rsLooper.fChain->GetEntriesFast();
  Long64_t nbytes_rs=0,nb_rs=0;
  Long64_t nentries_ws = wsLooper.fChain->GetEntriesFast();
  Long64_t nbytes_ws=0,nb_ws=0;
  for(Long64_t jentry_rs = 0;jentry_rs<nentries_rs;++jentry_rs){
    Long64_t ientry_rs = rsLooper.LoadTree(jentry_rs);
    if(ientry_rs<0)break;
    nb_rs = rsLooper.fChain->GetEntry(jentry_rs); nbytes_rs+=nb_rs;
    if(!rsLooper.passCuts())continue;
    //ws loop
    for(Long64_t jentry_ws = 0;jentry_ws<nentries_ws;++jentry_ws){
      Long64_t ientry_ws = wsLooper.LoadTree(jentry_ws);
      if(ientry_ws<0)break;
      nb_ws = wsLooper.fChain->GetEntry(jentry_ws); nbytes_ws+=nb_ws;
      if(!wsLooper.passCuts())continue;
      if(fabs(rsLooper.B_VFit_Kplus_PX[0]-wsLooper.B_VFit_Kplus_PX[0])>diff)continue;
      if(fabs(rsLooper.B_VFit_Kplus_PY[0]-wsLooper.B_VFit_Kplus_PY[0])>diff)continue;
      if(fabs(rsLooper.B_VFit_Kplus_PZ[0]-wsLooper.B_VFit_Kplus_PZ[0])>diff)continue;
      if(fabs(rsLooper.B_VFit_piplus_0_PX[0]-wsLooper.B_VFit_piplus_0_PX[0])>diff)continue;
      if(fabs(rsLooper.B_VFit_piplus_0_PY[0]-wsLooper.B_VFit_piplus_0_PY[0])>diff)continue;
      if(fabs(rsLooper.B_VFit_piplus_0_PZ[0]-wsLooper.B_VFit_piplus_0_PZ[0])>diff)continue;
      //the k and pi match at the level of 10-3 for the momentum print out the information
      TLorentzVector kdau,pidau,pis,d0;
      kdau.SetXYZM(wsLooper.B_VFit_Kplus_PX[0],
		   wsLooper.B_VFit_Kplus_PY[0],
		   wsLooper.B_VFit_Kplus_PZ[0],
		   pdg_kplus_m);
      pidau.SetXYZM(wsLooper.B_VFit_piplus_0_PX[0],
		   wsLooper.B_VFit_piplus_0_PY[0],
		   wsLooper.B_VFit_piplus_0_PZ[0],
		   pdg_piplus_m);
      pis.SetXYZM(wsLooper.B_VFit_piplus_PX[0],
		  wsLooper.B_VFit_piplus_PY[0],
		  wsLooper.B_VFit_piplus_PZ[0],
		  pdg_piplus_m);
      d0.SetXYZM((kdau+pidau).Px(),
		 (kdau+pidau).Py(),
		 (kdau+pidau).Pz(),
		 pdg_d0_m);
      
      cout<<"Found a matching hit candidate. DstM("<<(d0+pis).M()<<"),KPX("<<kdau.Px()<<"),KPY("<<kdau.Py()<<"),KPZ("<<kdau.Pz()<<"),PiPX("<<pidau.Px()<<"),PiPY("<<pidau.Py()<<"),PiPZ("<<pidau.Pz()<<"),EvtNum("<<wsLooper.eventNumber<<"),runNumber("<<wsLooper.runNumber<<")"<<endl;
    }//ws loop
  }//rs loop
  return 0;
}
  
