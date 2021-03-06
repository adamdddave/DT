
////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Jan 22 21:25:43 2015 by ROOT version 5.34/25
// from TTree DecayTree/DecayTree
// found on file: 
// DT_2012md_root5.root
//////////////////////////////////////////////////////////

#ifndef DT_D0_mix_CPV_h
#define DT_D0_mix_CPV_h

#include <iostream>
#include <vector>

#include <TH1.h>
#include <TH2.h>
#include <TLorentzVector.h>

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TNtuple.h>//for unbinned
//other classes
//#include "betastar_plot.h"
// Header file for the classes stored in the TTree if any.
//struct for removing the prompt/DT matched candidates
struct matchelement_t{
  UInt_t          runNumber;
  ULong64_t       eventNumber;
  Double_t kpx,kpy,kpz,pipx,pipy,pipz,pispx,pispy,pispz;
  bool toBeRemoved;//ok to delete?
};

// Fixed size dimensions of array or collections stored in the TTree if any.
const Int_t kMaxB_ENDVERTEX_COV = 1;
const Int_t kMaxB_OWNPV_COV = 1;
const Int_t kMaxDstar_ENDVERTEX_COV = 1;
const Int_t kMaxDstar_OWNPV_COV = 1;
const Int_t kMaxDstar_ORIVX_COV = 1;
const Int_t kMaxD_ENDVERTEX_COV = 1;
const Int_t kMaxD_OWNPV_COV = 1;
const Int_t kMaxD_ORIVX_COV = 1;
const Int_t kMaxK_OWNPV_COV = 1;
const Int_t kMaxK_ORIVX_COV = 1;
const Int_t kMaxPd_OWNPV_COV = 1;
const Int_t kMaxPd_ORIVX_COV = 1;
const Int_t kMaxPs_OWNPV_COV = 1;
const Int_t kMaxPs_ORIVX_COV = 1;
const Int_t kMaxMu_OWNPV_COV = 1;
const Int_t kMaxMu_ORIVX_COV = 1;

class DT_D0_mix_CPV {
public :
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain

  // Declaration of leaf types
  Double_t        B_ENDVERTEX_X;
  Double_t        B_ENDVERTEX_Y;
  Double_t        B_ENDVERTEX_Z;
  Double_t        B_ENDVERTEX_XERR;
  Double_t        B_ENDVERTEX_YERR;
  Double_t        B_ENDVERTEX_ZERR;
  Double_t        B_ENDVERTEX_CHI2;
  Int_t           B_ENDVERTEX_NDOF;
  Float_t         B_ENDVERTEX_COV_[3][3];
  Double_t        B_OWNPV_X;
  Double_t        B_OWNPV_Y;
  Double_t        B_OWNPV_Z;
  Double_t        B_OWNPV_XERR;
  Double_t        B_OWNPV_YERR;
  Double_t        B_OWNPV_ZERR;
  Double_t        B_OWNPV_CHI2;
  Int_t           B_OWNPV_NDOF;
  Float_t         B_OWNPV_COV_[3][3];
  Double_t        B_IP_OWNPV;
  Double_t        B_IPCHI2_OWNPV;
  Double_t        B_FD_OWNPV;
  Double_t        B_FDCHI2_OWNPV;
  Double_t        B_DIRA_OWNPV;
  Double_t        B_P;
  Double_t        B_PT;
  Double_t        B_PE;
  Double_t        B_PX;
  Double_t        B_PY;
  Double_t        B_PZ;
  Double_t        B_MM;
  Double_t        B_MMERR;
  Double_t        B_M;
  Int_t           B_ID;
  Double_t        B_CORR_M;
  Int_t           B_VFit_nPV;
  Float_t         B_VFit_COV_E_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_COV_E_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_COV_E_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_COV_E_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_COV_PX_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_COV_PX_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_COV_PX_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_COV_PY_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_COV_PY_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_COV_PZ_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_COV_E_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_COV_E_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_COV_E_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_COV_E_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_COV_PX_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_COV_PX_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_COV_PX_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_COV_PY_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_COV_PY_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_COV_PZ_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_M[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_MERR[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_ctau[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_ctauErr[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_decayLength[100];   //[B_VFit_nPV]
  Float_t         B_VFit_D0_decayLengthErr[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_COV_E_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_COV_E_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_COV_E_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_COV_E_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_COV_PX_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_COV_PX_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_COV_PX_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_COV_PY_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_COV_PY_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_COV_PZ_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_M[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_MERR[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_ctau[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_ctauErr[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_decayLength[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Dst_2010_plus_decayLengthErr[100];   //[B_VFit_nPV]
  Float_t         B_VFit_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_COV_E_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_COV_E_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_COV_E_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_COV_E_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_COV_PX_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_COV_PX_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_COV_PX_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_COV_PY_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_COV_PY_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_COV_PZ_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_Kplus_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_M[100];   //[B_VFit_nPV]
  Float_t         B_VFit_MERR[100];   //[B_VFit_nPV]
  Float_t         B_VFit_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_chi2[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_COV_E_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_COV_E_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_COV_E_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_COV_E_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_COV_PX_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_COV_PX_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_COV_PX_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_COV_PY_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_COV_PY_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_COV_PZ_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_muminus_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_nDOF[100];   //[B_VFit_nPV]
  Float_t         B_VFit_nIter[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_COV_E_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_COV_E_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_COV_E_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_COV_E_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_COV_PX_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_COV_PX_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_COV_PX_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_COV_PY_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_COV_PY_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_COV_PZ_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_0_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_COV_E_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_COV_E_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_COV_E_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_COV_E_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_COV_PX_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_COV_PX_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_COV_PX_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_COV_PY_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_COV_PY_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_COV_PZ_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_E[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_PX[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_PY[100];   //[B_VFit_nPV]
  Float_t         B_VFit_piplus_PZ[100];   //[B_VFit_nPV]
  Float_t         B_VFit_status[100];   //[B_VFit_nPV]
  Double_t        B_Nu_Parl;
  Double_t        B_Nu_Perp;
  Double_t        B_Nu_a;
  Double_t        B_Nu_X;
  Double_t        B_Nu_Y;
  Double_t        B_Nu_pb;
  Double_t        B_Nu_pd;
  Double_t        B_Nu_Hi;
  Double_t        B_Nu_Lo;
  Bool_t          B_L0Global_Dec;
  Bool_t          B_L0Global_TIS;
  Bool_t          B_L0Global_TOS;
  Bool_t          B_Hlt1Global_Dec;
  Bool_t          B_Hlt1Global_TIS;
  Bool_t          B_Hlt1Global_TOS;
  Bool_t          B_Hlt1Phys_Dec;
  Bool_t          B_Hlt1Phys_TIS;
  Bool_t          B_Hlt1Phys_TOS;
  Bool_t          B_Hlt2Global_Dec;
  Bool_t          B_Hlt2Global_TIS;
  Bool_t          B_Hlt2Global_TOS;
  Bool_t          B_Hlt2Phys_Dec;
  Bool_t          B_Hlt2Phys_TIS;
  Bool_t          B_Hlt2Phys_TOS;
  Bool_t          B_Hlt2TopoMu4BodyBBDTDecision_Dec;
  Bool_t          B_Hlt2TopoMu4BodyBBDTDecision_TIS;
  Bool_t          B_Hlt2TopoMu4BodyBBDTDecision_TOS;
  Bool_t          B_Hlt2TopoMu3BodyBBDTDecision_Dec;
  Bool_t          B_Hlt2TopoMu3BodyBBDTDecision_TIS;
  Bool_t          B_Hlt2TopoMu3BodyBBDTDecision_TOS;
  Bool_t          B_Hlt2TopoMu2BodyBBDTDecision_Dec;
  Bool_t          B_Hlt2TopoMu2BodyBBDTDecision_TIS;
  Bool_t          B_Hlt2TopoMu2BodyBBDTDecision_TOS;
  Double_t        Dstar_ENDVERTEX_X;
  Double_t        Dstar_ENDVERTEX_Y;
  Double_t        Dstar_ENDVERTEX_Z;
  Double_t        Dstar_ENDVERTEX_XERR;
  Double_t        Dstar_ENDVERTEX_YERR;
  Double_t        Dstar_ENDVERTEX_ZERR;
  Double_t        Dstar_ENDVERTEX_CHI2;
  Int_t           Dstar_ENDVERTEX_NDOF;
  Float_t         Dstar_ENDVERTEX_COV_[3][3];
  Double_t        Dstar_OWNPV_X;
  Double_t        Dstar_OWNPV_Y;
  Double_t        Dstar_OWNPV_Z;
  Double_t        Dstar_OWNPV_XERR;
  Double_t        Dstar_OWNPV_YERR;
  Double_t        Dstar_OWNPV_ZERR;
  Double_t        Dstar_OWNPV_CHI2;
  Int_t           Dstar_OWNPV_NDOF;
  Float_t         Dstar_OWNPV_COV_[3][3];
  Double_t        Dstar_IP_OWNPV;
  Double_t        Dstar_IPCHI2_OWNPV;
  Double_t        Dstar_FD_OWNPV;
  Double_t        Dstar_FDCHI2_OWNPV;
  Double_t        Dstar_DIRA_OWNPV;
  Double_t        Dstar_ORIVX_X;
  Double_t        Dstar_ORIVX_Y;
  Double_t        Dstar_ORIVX_Z;
  Double_t        Dstar_ORIVX_XERR;
  Double_t        Dstar_ORIVX_YERR;
  Double_t        Dstar_ORIVX_ZERR;
  Double_t        Dstar_ORIVX_CHI2;
  Int_t           Dstar_ORIVX_NDOF;
  Float_t         Dstar_ORIVX_COV_[3][3];
  Double_t        Dstar_FD_ORIVX;
  Double_t        Dstar_FDCHI2_ORIVX;
  Double_t        Dstar_DIRA_ORIVX;
  Double_t        Dstar_P;
  Double_t        Dstar_PT;
  Double_t        Dstar_PE;
  Double_t        Dstar_PX;
  Double_t        Dstar_PY;
  Double_t        Dstar_PZ;
  Double_t        Dstar_MM;
  Double_t        Dstar_MMERR;
  Double_t        Dstar_M;
  Int_t           Dstar_ID;
  /*  Int_t           Dstar_DstFit_nPV;
  Float_t         Dstar_DstFit_COV_E_E[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_COV_E_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_COV_E_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_COV_E_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_COV_PX_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_COV_PX_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_COV_PX_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_COV_PY_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_COV_PY_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_COV_PZ_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_COV_E_E[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_COV_E_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_COV_E_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_COV_E_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_COV_PX_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_COV_PX_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_COV_PX_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_COV_PY_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_COV_PY_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_COV_PZ_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_E[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_M[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_MERR[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_ctau[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_ctauErr[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_decayLength[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_D0_decayLengthErr[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_E[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_COV_E_E[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_COV_E_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_COV_E_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_COV_E_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_COV_PX_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_COV_PX_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_COV_PX_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_COV_PY_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_COV_PY_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_COV_PZ_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_E[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_Kplus_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_M[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_MERR[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_chi2[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_nDOF[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_nIter[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_COV_E_E[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_COV_E_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_COV_E_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_COV_E_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_COV_PX_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_COV_PX_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_COV_PX_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_COV_PY_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_COV_PY_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_COV_PZ_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_E[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_0_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_COV_E_E[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_COV_E_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_COV_E_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_COV_E_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_COV_PX_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_COV_PX_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_COV_PX_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_COV_PY_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_COV_PY_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_COV_PZ_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_E[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_PX[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_PY[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_piplus_PZ[100];   //[Dstar_DstFit_nPV]
  Float_t         Dstar_DstFit_status[100];   //[Dstar_DstFit_nPV]
  */
  Bool_t          Dstar_L0Global_Dec;
  Bool_t          Dstar_L0Global_TIS;
  Bool_t          Dstar_L0Global_TOS;
  Bool_t          Dstar_Hlt1Global_Dec;
  Bool_t          Dstar_Hlt1Global_TIS;
  Bool_t          Dstar_Hlt1Global_TOS;
  Bool_t          Dstar_Hlt1Phys_Dec;
  Bool_t          Dstar_Hlt1Phys_TIS;
  Bool_t          Dstar_Hlt1Phys_TOS;
  Bool_t          Dstar_Hlt2Global_Dec;
  Bool_t          Dstar_Hlt2Global_TIS;
  Bool_t          Dstar_Hlt2Global_TOS;
  Bool_t          Dstar_Hlt2Phys_Dec;
  Bool_t          Dstar_Hlt2Phys_TIS;
  Bool_t          Dstar_Hlt2Phys_TOS;
  Bool_t          Dstar_Hlt1TrackAllL0Decision_Dec;
  Bool_t          Dstar_Hlt1TrackAllL0Decision_TIS;
  Bool_t          Dstar_Hlt1TrackAllL0Decision_TOS;
  Double_t        D_ENDVERTEX_X;
  Double_t        D_ENDVERTEX_Y;
  Double_t        D_ENDVERTEX_Z;
  Double_t        D_ENDVERTEX_XERR;
  Double_t        D_ENDVERTEX_YERR;
  Double_t        D_ENDVERTEX_ZERR;
  Double_t        D_ENDVERTEX_CHI2;
  Int_t           D_ENDVERTEX_NDOF;
  Float_t         D_ENDVERTEX_COV_[3][3];
  Double_t        D_OWNPV_X;
  Double_t        D_OWNPV_Y;
  Double_t        D_OWNPV_Z;
  Double_t        D_OWNPV_XERR;
  Double_t        D_OWNPV_YERR;
  Double_t        D_OWNPV_ZERR;
  Double_t        D_OWNPV_CHI2;
  Int_t           D_OWNPV_NDOF;
  Float_t         D_OWNPV_COV_[3][3];
  Double_t        D_IP_OWNPV;
  Double_t        D_IPCHI2_OWNPV;
  Double_t        D_FD_OWNPV;
  Double_t        D_FDCHI2_OWNPV;
  Double_t        D_DIRA_OWNPV;
  Double_t        D_ORIVX_X;
  Double_t        D_ORIVX_Y;
  Double_t        D_ORIVX_Z;
  Double_t        D_ORIVX_XERR;
  Double_t        D_ORIVX_YERR;
  Double_t        D_ORIVX_ZERR;
  Double_t        D_ORIVX_CHI2;
  Int_t           D_ORIVX_NDOF;
  Float_t         D_ORIVX_COV_[3][3];
  Double_t        D_FD_ORIVX;
  Double_t        D_FDCHI2_ORIVX;
  Double_t        D_DIRA_ORIVX;
  Double_t        D_P;
  Double_t        D_PT;
  Double_t        D_PE;
  Double_t        D_PX;
  Double_t        D_PY;
  Double_t        D_PZ;
  Double_t        D_MM;
  Double_t        D_MMERR;
  Double_t        D_M;
  Int_t           D_ID;
  Double_t        K_MC12TuneV2_ProbNNe;
  Double_t        K_MC12TuneV2_ProbNNmu;
  Double_t        K_MC12TuneV2_ProbNNpi;
  Double_t        K_MC12TuneV2_ProbNNk;
  Double_t        K_MC12TuneV2_ProbNNp;
  Double_t        K_MC12TuneV2_ProbNNghost;
  Double_t        K_MC12TuneV3_ProbNNe;
  Double_t        K_MC12TuneV3_ProbNNmu;
  Double_t        K_MC12TuneV3_ProbNNpi;
  Double_t        K_MC12TuneV3_ProbNNk;
  Double_t        K_MC12TuneV3_ProbNNp;
  Double_t        K_MC12TuneV3_ProbNNghost;
  Double_t        K_OWNPV_X;
  Double_t        K_OWNPV_Y;
  Double_t        K_OWNPV_Z;
  Double_t        K_OWNPV_XERR;
  Double_t        K_OWNPV_YERR;
  Double_t        K_OWNPV_ZERR;
  Double_t        K_OWNPV_CHI2;
  Int_t           K_OWNPV_NDOF;
  Float_t         K_OWNPV_COV_[3][3];
  Double_t        K_IP_OWNPV;
  Double_t        K_IPCHI2_OWNPV;
  Double_t        K_ORIVX_X;
  Double_t        K_ORIVX_Y;
  Double_t        K_ORIVX_Z;
  Double_t        K_ORIVX_XERR;
  Double_t        K_ORIVX_YERR;
  Double_t        K_ORIVX_ZERR;
  Double_t        K_ORIVX_CHI2;
  Int_t           K_ORIVX_NDOF;
  Float_t         K_ORIVX_COV_[3][3];
  Double_t        K_P;
  Double_t        K_PT;
  Double_t        K_PE;
  Double_t        K_PX;
  Double_t        K_PY;
  Double_t        K_PZ;
  Double_t        K_M;
  Int_t           K_ID;
  Double_t        K_PIDe;
  Double_t        K_PIDmu;
  Double_t        K_PIDK;
  Double_t        K_PIDp;
  Double_t        K_ProbNNe;
  Double_t        K_ProbNNk;
  Double_t        K_ProbNNp;
  Double_t        K_ProbNNpi;
  Double_t        K_ProbNNmu;
  Double_t        K_ProbNNghost;
  Bool_t          K_hasMuon;
  Bool_t          K_isMuon;
  Bool_t          K_hasRich;
  Bool_t          K_hasCalo;
  Int_t           K_TRACK_Type;
  Int_t           K_TRACK_Key;
  Double_t        K_TRACK_CHI2NDOF;
  Double_t        K_TRACK_PCHI2;
  Double_t        K_TRACK_MatchCHI2;
  Double_t        K_TRACK_GhostProb;
  Double_t        K_TRACK_CloneDist;
  Double_t        K_TRACK_Likelihood;
  Double_t        Pd_MC12TuneV2_ProbNNe;
  Double_t        Pd_MC12TuneV2_ProbNNmu;
  Double_t        Pd_MC12TuneV2_ProbNNpi;
  Double_t        Pd_MC12TuneV2_ProbNNk;
  Double_t        Pd_MC12TuneV2_ProbNNp;
  Double_t        Pd_MC12TuneV2_ProbNNghost;
  Double_t        Pd_MC12TuneV3_ProbNNe;
  Double_t        Pd_MC12TuneV3_ProbNNmu;
  Double_t        Pd_MC12TuneV3_ProbNNpi;
  Double_t        Pd_MC12TuneV3_ProbNNk;
  Double_t        Pd_MC12TuneV3_ProbNNp;
  Double_t        Pd_MC12TuneV3_ProbNNghost;
  Double_t        Pd_OWNPV_X;
  Double_t        Pd_OWNPV_Y;
  Double_t        Pd_OWNPV_Z;
  Double_t        Pd_OWNPV_XERR;
  Double_t        Pd_OWNPV_YERR;
  Double_t        Pd_OWNPV_ZERR;
  Double_t        Pd_OWNPV_CHI2;
  Int_t           Pd_OWNPV_NDOF;
  Float_t         Pd_OWNPV_COV_[3][3];
  Double_t        Pd_IP_OWNPV;
  Double_t        Pd_IPCHI2_OWNPV;
  Double_t        Pd_ORIVX_X;
  Double_t        Pd_ORIVX_Y;
  Double_t        Pd_ORIVX_Z;
  Double_t        Pd_ORIVX_XERR;
  Double_t        Pd_ORIVX_YERR;
  Double_t        Pd_ORIVX_ZERR;
  Double_t        Pd_ORIVX_CHI2;
  Int_t           Pd_ORIVX_NDOF;
  Float_t         Pd_ORIVX_COV_[3][3];
  Double_t        Pd_P;
  Double_t        Pd_PT;
  Double_t        Pd_PE;
  Double_t        Pd_PX;
  Double_t        Pd_PY;
  Double_t        Pd_PZ;
  Double_t        Pd_M;
  Int_t           Pd_ID;
  Double_t        Pd_PIDe;
  Double_t        Pd_PIDmu;
  Double_t        Pd_PIDK;
  Double_t        Pd_PIDp;
  Double_t        Pd_ProbNNe;
  Double_t        Pd_ProbNNk;
  Double_t        Pd_ProbNNp;
  Double_t        Pd_ProbNNpi;
  Double_t        Pd_ProbNNmu;
  Double_t        Pd_ProbNNghost;
  Bool_t          Pd_hasMuon;
  Bool_t          Pd_isMuon;
  Bool_t          Pd_hasRich;
  Bool_t          Pd_hasCalo;
  Int_t           Pd_TRACK_Type;
  Int_t           Pd_TRACK_Key;
  Double_t        Pd_TRACK_CHI2NDOF;
  Double_t        Pd_TRACK_PCHI2;
  Double_t        Pd_TRACK_MatchCHI2;
  Double_t        Pd_TRACK_GhostProb;
  Double_t        Pd_TRACK_CloneDist;
  Double_t        Pd_TRACK_Likelihood;
  Double_t        Ps_MC12TuneV2_ProbNNe;
  Double_t        Ps_MC12TuneV2_ProbNNmu;
  Double_t        Ps_MC12TuneV2_ProbNNpi;
  Double_t        Ps_MC12TuneV2_ProbNNk;
  Double_t        Ps_MC12TuneV2_ProbNNp;
  Double_t        Ps_MC12TuneV2_ProbNNghost;
  Double_t        Ps_MC12TuneV3_ProbNNe;
  Double_t        Ps_MC12TuneV3_ProbNNmu;
  Double_t        Ps_MC12TuneV3_ProbNNpi;
  Double_t        Ps_MC12TuneV3_ProbNNk;
  Double_t        Ps_MC12TuneV3_ProbNNp;
  Double_t        Ps_MC12TuneV3_ProbNNghost;
  Double_t        Ps_OWNPV_X;
  Double_t        Ps_OWNPV_Y;
  Double_t        Ps_OWNPV_Z;
  Double_t        Ps_OWNPV_XERR;
  Double_t        Ps_OWNPV_YERR;
  Double_t        Ps_OWNPV_ZERR;
  Double_t        Ps_OWNPV_CHI2;
  Int_t           Ps_OWNPV_NDOF;
  Float_t         Ps_OWNPV_COV_[3][3];
  Double_t        Ps_IP_OWNPV;
  Double_t        Ps_IPCHI2_OWNPV;
  Double_t        Ps_ORIVX_X;
  Double_t        Ps_ORIVX_Y;
  Double_t        Ps_ORIVX_Z;
  Double_t        Ps_ORIVX_XERR;
  Double_t        Ps_ORIVX_YERR;
  Double_t        Ps_ORIVX_ZERR;
  Double_t        Ps_ORIVX_CHI2;
  Int_t           Ps_ORIVX_NDOF;
  Float_t         Ps_ORIVX_COV_[3][3];
  Double_t        Ps_P;
  Double_t        Ps_PT;
  Double_t        Ps_PE;
  Double_t        Ps_PX;
  Double_t        Ps_PY;
  Double_t        Ps_PZ;
  Double_t        Ps_M;
  Int_t           Ps_ID;
  Double_t        Ps_PIDe;
  Double_t        Ps_PIDmu;
  Double_t        Ps_PIDK;
  Double_t        Ps_PIDp;
  Double_t        Ps_ProbNNe;
  Double_t        Ps_ProbNNk;
  Double_t        Ps_ProbNNp;
  Double_t        Ps_ProbNNpi;
  Double_t        Ps_ProbNNmu;
  Double_t        Ps_ProbNNghost;
  Bool_t          Ps_hasMuon;
  Bool_t          Ps_isMuon;
  Bool_t          Ps_hasRich;
  Bool_t          Ps_hasCalo;
  Int_t           Ps_TRACK_Type;
  Int_t           Ps_TRACK_Key;
  Double_t        Ps_TRACK_CHI2NDOF;
  Double_t        Ps_TRACK_PCHI2;
  Double_t        Ps_TRACK_MatchCHI2;
  Double_t        Ps_TRACK_GhostProb;
  Double_t        Ps_TRACK_CloneDist;
  Double_t        Ps_TRACK_Likelihood;
  Double_t        Mu_MC12TuneV2_ProbNNe;
  Double_t        Mu_MC12TuneV2_ProbNNmu;
  Double_t        Mu_MC12TuneV2_ProbNNpi;
  Double_t        Mu_MC12TuneV2_ProbNNk;
  Double_t        Mu_MC12TuneV2_ProbNNp;
  Double_t        Mu_MC12TuneV2_ProbNNghost;
  Double_t        Mu_MC12TuneV3_ProbNNe;
  Double_t        Mu_MC12TuneV3_ProbNNmu;
  Double_t        Mu_MC12TuneV3_ProbNNpi;
  Double_t        Mu_MC12TuneV3_ProbNNk;
  Double_t        Mu_MC12TuneV3_ProbNNp;
  Double_t        Mu_MC12TuneV3_ProbNNghost;
  Double_t        Mu_OWNPV_X;
  Double_t        Mu_OWNPV_Y;
  Double_t        Mu_OWNPV_Z;
  Double_t        Mu_OWNPV_XERR;
  Double_t        Mu_OWNPV_YERR;
  Double_t        Mu_OWNPV_ZERR;
  Double_t        Mu_OWNPV_CHI2;
  Int_t           Mu_OWNPV_NDOF;
  Float_t         Mu_OWNPV_COV_[3][3];
  Double_t        Mu_IP_OWNPV;
  Double_t        Mu_IPCHI2_OWNPV;
  Double_t        Mu_ORIVX_X;
  Double_t        Mu_ORIVX_Y;
  Double_t        Mu_ORIVX_Z;
  Double_t        Mu_ORIVX_XERR;
  Double_t        Mu_ORIVX_YERR;
  Double_t        Mu_ORIVX_ZERR;
  Double_t        Mu_ORIVX_CHI2;
  Int_t           Mu_ORIVX_NDOF;
  Float_t         Mu_ORIVX_COV_[3][3];
  Double_t        Mu_P;
  Double_t        Mu_PT;
  Double_t        Mu_PE;
  Double_t        Mu_PX;
  Double_t        Mu_PY;
  Double_t        Mu_PZ;
  Double_t        Mu_M;
  Int_t           Mu_ID;
  Double_t        Mu_PIDe;
  Double_t        Mu_PIDmu;
  Double_t        Mu_PIDK;
  Double_t        Mu_PIDp;
  Double_t        Mu_ProbNNe;
  Double_t        Mu_ProbNNk;
  Double_t        Mu_ProbNNp;
  Double_t        Mu_ProbNNpi;
  Double_t        Mu_ProbNNmu;
  Double_t        Mu_ProbNNghost;
  Bool_t          Mu_hasMuon;
  Bool_t          Mu_isMuon;
  Bool_t          Mu_hasRich;
  Bool_t          Mu_hasCalo;
  Int_t           Mu_TRACK_Type;
  Int_t           Mu_TRACK_Key;
  Double_t        Mu_TRACK_CHI2NDOF;
  Double_t        Mu_TRACK_PCHI2;
  Double_t        Mu_TRACK_MatchCHI2;
  Double_t        Mu_TRACK_GhostProb;
  Double_t        Mu_TRACK_CloneDist;
  Double_t        Mu_TRACK_Likelihood;
  Int_t           Mu_n_extra_mu;
  Float_t         Mu_extra_mu_PX[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_PY[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_PZ[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_E[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_ID[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_PIDmu[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_PIDK[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_ProbNNghost[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_TRACK_ghostProb[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_TRACK_chi2perDoF[100];   //[Mu_n_extra_mu]
  Float_t         Mu_dimuon_M[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_mu_vtx_chi2[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_mu_vtx_nDoF[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_dst_vtx_chi2[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_dst_vtx_nDoF[100];   //[Mu_n_extra_mu]
  Float_t         Mu_dst_mu_extra_M[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_IP[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_IPchi2[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_PV_match[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_IP_muPV[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_IPchi2_muPV[100];   //[Mu_n_extra_mu]
  Bool_t          Mu_L0Global_Dec;
  Bool_t          Mu_L0Global_TIS;
  Bool_t          Mu_L0Global_TOS;
  Bool_t          Mu_Hlt1Global_Dec;
  Bool_t          Mu_Hlt1Global_TIS;
  Bool_t          Mu_Hlt1Global_TOS;
  Bool_t          Mu_Hlt1Phys_Dec;
  Bool_t          Mu_Hlt1Phys_TIS;
  Bool_t          Mu_Hlt1Phys_TOS;
  Bool_t          Mu_Hlt2Global_Dec;
  Bool_t          Mu_Hlt2Global_TIS;
  Bool_t          Mu_Hlt2Global_TOS;
  Bool_t          Mu_Hlt2Phys_Dec;
  Bool_t          Mu_Hlt2Phys_TIS;
  Bool_t          Mu_Hlt2Phys_TOS;
  Bool_t          Mu_L0MuonDecision_Dec;
  Bool_t          Mu_L0MuonDecision_TIS;
  Bool_t          Mu_L0MuonDecision_TOS;
  Bool_t          Mu_Hlt1TrackMuonDecision_Dec;
  Bool_t          Mu_Hlt1TrackMuonDecision_TIS;
  Bool_t          Mu_Hlt1TrackMuonDecision_TOS;
  Bool_t          Mu_Hlt2SingleMuonDecision_Dec;
  Bool_t          Mu_Hlt2SingleMuonDecision_TIS;
  Bool_t          Mu_Hlt2SingleMuonDecision_TOS;
  UInt_t          nCandidate;
  ULong64_t       totCandidates;
  ULong64_t       EventInSequence;
  UInt_t          runNumber;
  ULong64_t       eventNumber;
  UInt_t          BCID;
  Int_t           BCType;
  UInt_t          OdinTCK;
  UInt_t          L0DUTCK;
  UInt_t          HLTTCK;
  ULong64_t       GpsTime;
  Short_t         Polarity;
  Int_t           nPV;
  Float_t         PVX[100];   //[nPV]
  Float_t         PVY[100];   //[nPV]
  Float_t         PVZ[100];   //[nPV]
  Float_t         PVXERR[100];   //[nPV]
  Float_t         PVYERR[100];   //[nPV]
  Float_t         PVZERR[100];   //[nPV]
  Float_t         PVCHI2[100];   //[nPV]
  Float_t         PVNDOF[100];   //[nPV]
  Float_t         PVNTRACKS[100];   //[nPV]
  Int_t           nPVs;
  Int_t           nTracks;
  Int_t           nLongTracks;
  Int_t           nDownstreamTracks;
  Int_t           nUpstreamTracks;
  Int_t           nVeloTracks;
  Int_t           nTTracks;
  Int_t           nBackTracks;
  Int_t           nRich1Hits;
  Int_t           nRich2Hits;
  Int_t           nVeloClusters;
  Int_t           nITClusters;
  Int_t           nTTClusters;
  Int_t           nOTClusters;
  Int_t           nSPDHits;
  Int_t           nMuonCoordsS0;
  Int_t           nMuonCoordsS1;
  Int_t           nMuonCoordsS2;
  Int_t           nMuonCoordsS3;
  Int_t           nMuonCoordsS4;
  Int_t           nMuonTracks;
  Int_t           L0Global;
  UInt_t          Hlt1Global;
  UInt_t          Hlt2Global;

  // List of branches
  TBranch        *b_B_ENDVERTEX_X;   //!
  TBranch        *b_B_ENDVERTEX_Y;   //!
  TBranch        *b_B_ENDVERTEX_Z;   //!
  TBranch        *b_B_ENDVERTEX_XERR;   //!
  TBranch        *b_B_ENDVERTEX_YERR;   //!
  TBranch        *b_B_ENDVERTEX_ZERR;   //!
  TBranch        *b_B_ENDVERTEX_CHI2;   //!
  TBranch        *b_B_ENDVERTEX_NDOF;   //!
  TBranch        *b_B_ENDVERTEX_COV_;   //!
  TBranch        *b_B_OWNPV_X;   //!
  TBranch        *b_B_OWNPV_Y;   //!
  TBranch        *b_B_OWNPV_Z;   //!
  TBranch        *b_B_OWNPV_XERR;   //!
  TBranch        *b_B_OWNPV_YERR;   //!
  TBranch        *b_B_OWNPV_ZERR;   //!
  TBranch        *b_B_OWNPV_CHI2;   //!
  TBranch        *b_B_OWNPV_NDOF;   //!
  TBranch        *b_B_OWNPV_COV_;   //!
  TBranch        *b_B_IP_OWNPV;   //!
  TBranch        *b_B_IPCHI2_OWNPV;   //!
  TBranch        *b_B_FD_OWNPV;   //!
  TBranch        *b_B_FDCHI2_OWNPV;   //!
  TBranch        *b_B_DIRA_OWNPV;   //!
  TBranch        *b_B_P;   //!
  TBranch        *b_B_PT;   //!
  TBranch        *b_B_PE;   //!
  TBranch        *b_B_PX;   //!
  TBranch        *b_B_PY;   //!
  TBranch        *b_B_PZ;   //!
  TBranch        *b_B_MM;   //!
  TBranch        *b_B_MMERR;   //!
  TBranch        *b_B_M;   //!
  TBranch        *b_B_ID;   //!
  TBranch        *b_B_CORR_M;   //!
  TBranch        *b_B_VFit_nPV;   //!
  TBranch        *b_B_VFit_COV_E_E;   //!
  TBranch        *b_B_VFit_COV_E_PX;   //!
  TBranch        *b_B_VFit_COV_E_PY;   //!
  TBranch        *b_B_VFit_COV_E_PZ;   //!
  TBranch        *b_B_VFit_COV_PX_PX;   //!
  TBranch        *b_B_VFit_COV_PX_PY;   //!
  TBranch        *b_B_VFit_COV_PX_PZ;   //!
  TBranch        *b_B_VFit_COV_PY_PY;   //!
  TBranch        *b_B_VFit_COV_PY_PZ;   //!
  TBranch        *b_B_VFit_COV_PZ_PZ;   //!
  TBranch        *b_B_VFit_D0_COV_E_E;   //!
  TBranch        *b_B_VFit_D0_COV_E_PX;   //!
  TBranch        *b_B_VFit_D0_COV_E_PY;   //!
  TBranch        *b_B_VFit_D0_COV_E_PZ;   //!
  TBranch        *b_B_VFit_D0_COV_PX_PX;   //!
  TBranch        *b_B_VFit_D0_COV_PX_PY;   //!
  TBranch        *b_B_VFit_D0_COV_PX_PZ;   //!
  TBranch        *b_B_VFit_D0_COV_PY_PY;   //!
  TBranch        *b_B_VFit_D0_COV_PY_PZ;   //!
  TBranch        *b_B_VFit_D0_COV_PZ_PZ;   //!
  TBranch        *b_B_VFit_D0_E;   //!
  TBranch        *b_B_VFit_D0_M;   //!
  TBranch        *b_B_VFit_D0_MERR;   //!
  TBranch        *b_B_VFit_D0_PX;   //!
  TBranch        *b_B_VFit_D0_PY;   //!
  TBranch        *b_B_VFit_D0_PZ;   //!
  TBranch        *b_B_VFit_D0_ctau;   //!
  TBranch        *b_B_VFit_D0_ctauErr;   //!
  TBranch        *b_B_VFit_D0_decayLength;   //!
  TBranch        *b_B_VFit_D0_decayLengthErr;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_COV_E_E;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_COV_E_PX;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_COV_E_PY;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_COV_E_PZ;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_COV_PX_PX;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_COV_PX_PY;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_COV_PX_PZ;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_COV_PY_PY;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_COV_PY_PZ;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_COV_PZ_PZ;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_E;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_M;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_MERR;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_PX;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_PY;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_PZ;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_ctau;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_ctauErr;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_decayLength;   //!
  TBranch        *b_B_VFit_Dst_2010_plus_decayLengthErr;   //!
  TBranch        *b_B_VFit_E;   //!
  TBranch        *b_B_VFit_Kplus_COV_E_E;   //!
  TBranch        *b_B_VFit_Kplus_COV_E_PX;   //!
  TBranch        *b_B_VFit_Kplus_COV_E_PY;   //!
  TBranch        *b_B_VFit_Kplus_COV_E_PZ;   //!
  TBranch        *b_B_VFit_Kplus_COV_PX_PX;   //!
  TBranch        *b_B_VFit_Kplus_COV_PX_PY;   //!
  TBranch        *b_B_VFit_Kplus_COV_PX_PZ;   //!
  TBranch        *b_B_VFit_Kplus_COV_PY_PY;   //!
  TBranch        *b_B_VFit_Kplus_COV_PY_PZ;   //!
  TBranch        *b_B_VFit_Kplus_COV_PZ_PZ;   //!
  TBranch        *b_B_VFit_Kplus_E;   //!
  TBranch        *b_B_VFit_Kplus_PX;   //!
  TBranch        *b_B_VFit_Kplus_PY;   //!
  TBranch        *b_B_VFit_Kplus_PZ;   //!
  TBranch        *b_B_VFit_M;   //!
  TBranch        *b_B_VFit_MERR;   //!
  TBranch        *b_B_VFit_PX;   //!
  TBranch        *b_B_VFit_PY;   //!
  TBranch        *b_B_VFit_PZ;   //!
  TBranch        *b_B_VFit_chi2;   //!
  TBranch        *b_B_VFit_muminus_COV_E_E;   //!
  TBranch        *b_B_VFit_muminus_COV_E_PX;   //!
  TBranch        *b_B_VFit_muminus_COV_E_PY;   //!
  TBranch        *b_B_VFit_muminus_COV_E_PZ;   //!
  TBranch        *b_B_VFit_muminus_COV_PX_PX;   //!
  TBranch        *b_B_VFit_muminus_COV_PX_PY;   //!
  TBranch        *b_B_VFit_muminus_COV_PX_PZ;   //!
  TBranch        *b_B_VFit_muminus_COV_PY_PY;   //!
  TBranch        *b_B_VFit_muminus_COV_PY_PZ;   //!
  TBranch        *b_B_VFit_muminus_COV_PZ_PZ;   //!
  TBranch        *b_B_VFit_muminus_E;   //!
  TBranch        *b_B_VFit_muminus_PX;   //!
  TBranch        *b_B_VFit_muminus_PY;   //!
  TBranch        *b_B_VFit_muminus_PZ;   //!
  TBranch        *b_B_VFit_nDOF;   //!
  TBranch        *b_B_VFit_nIter;   //!
  TBranch        *b_B_VFit_piplus_0_COV_E_E;   //!
  TBranch        *b_B_VFit_piplus_0_COV_E_PX;   //!
  TBranch        *b_B_VFit_piplus_0_COV_E_PY;   //!
  TBranch        *b_B_VFit_piplus_0_COV_E_PZ;   //!
  TBranch        *b_B_VFit_piplus_0_COV_PX_PX;   //!
  TBranch        *b_B_VFit_piplus_0_COV_PX_PY;   //!
  TBranch        *b_B_VFit_piplus_0_COV_PX_PZ;   //!
  TBranch        *b_B_VFit_piplus_0_COV_PY_PY;   //!
  TBranch        *b_B_VFit_piplus_0_COV_PY_PZ;   //!
  TBranch        *b_B_VFit_piplus_0_COV_PZ_PZ;   //!
  TBranch        *b_B_VFit_piplus_0_E;   //!
  TBranch        *b_B_VFit_piplus_0_PX;   //!
  TBranch        *b_B_VFit_piplus_0_PY;   //!
  TBranch        *b_B_VFit_piplus_0_PZ;   //!
  TBranch        *b_B_VFit_piplus_COV_E_E;   //!
  TBranch        *b_B_VFit_piplus_COV_E_PX;   //!
  TBranch        *b_B_VFit_piplus_COV_E_PY;   //!
  TBranch        *b_B_VFit_piplus_COV_E_PZ;   //!
  TBranch        *b_B_VFit_piplus_COV_PX_PX;   //!
  TBranch        *b_B_VFit_piplus_COV_PX_PY;   //!
  TBranch        *b_B_VFit_piplus_COV_PX_PZ;   //!
  TBranch        *b_B_VFit_piplus_COV_PY_PY;   //!
  TBranch        *b_B_VFit_piplus_COV_PY_PZ;   //!
  TBranch        *b_B_VFit_piplus_COV_PZ_PZ;   //!
  TBranch        *b_B_VFit_piplus_E;   //!
  TBranch        *b_B_VFit_piplus_PX;   //!
  TBranch        *b_B_VFit_piplus_PY;   //!
  TBranch        *b_B_VFit_piplus_PZ;   //!
  TBranch        *b_B_VFit_status;   //!
  TBranch        *b_B_Nu_Parl;   //!
  TBranch        *b_B_Nu_Perp;   //!
  TBranch        *b_B_Nu_a;   //!
  TBranch        *b_B_Nu_X;   //!
  TBranch        *b_B_Nu_Y;   //!
  TBranch        *b_B_Nu_pb;   //!
  TBranch        *b_B_Nu_pd;   //!
  TBranch        *b_B_Nu_Hi;   //!
  TBranch        *b_B_Nu_Lo;   //!
  TBranch        *b_B_L0Global_Dec;   //!
  TBranch        *b_B_L0Global_TIS;   //!
  TBranch        *b_B_L0Global_TOS;   //!
  TBranch        *b_B_Hlt1Global_Dec;   //!
  TBranch        *b_B_Hlt1Global_TIS;   //!
  TBranch        *b_B_Hlt1Global_TOS;   //!
  TBranch        *b_B_Hlt1Phys_Dec;   //!
  TBranch        *b_B_Hlt1Phys_TIS;   //!
  TBranch        *b_B_Hlt1Phys_TOS;   //!
  TBranch        *b_B_Hlt2Global_Dec;   //!
  TBranch        *b_B_Hlt2Global_TIS;   //!
  TBranch        *b_B_Hlt2Global_TOS;   //!
  TBranch        *b_B_Hlt2Phys_Dec;   //!
  TBranch        *b_B_Hlt2Phys_TIS;   //!
  TBranch        *b_B_Hlt2Phys_TOS;   //!
  TBranch        *b_B_Hlt2TopoMu4BodyBBDTDecision_Dec;   //!
  TBranch        *b_B_Hlt2TopoMu4BodyBBDTDecision_TIS;   //!
  TBranch        *b_B_Hlt2TopoMu4BodyBBDTDecision_TOS;   //!
  TBranch        *b_B_Hlt2TopoMu3BodyBBDTDecision_Dec;   //!
  TBranch        *b_B_Hlt2TopoMu3BodyBBDTDecision_TIS;   //!
  TBranch        *b_B_Hlt2TopoMu3BodyBBDTDecision_TOS;   //!
  TBranch        *b_B_Hlt2TopoMu2BodyBBDTDecision_Dec;   //!
  TBranch        *b_B_Hlt2TopoMu2BodyBBDTDecision_TIS;   //!
  TBranch        *b_B_Hlt2TopoMu2BodyBBDTDecision_TOS;   //!
  TBranch        *b_Dstar_ENDVERTEX_X;   //!
  TBranch        *b_Dstar_ENDVERTEX_Y;   //!
  TBranch        *b_Dstar_ENDVERTEX_Z;   //!
  TBranch        *b_Dstar_ENDVERTEX_XERR;   //!
  TBranch        *b_Dstar_ENDVERTEX_YERR;   //!
  TBranch        *b_Dstar_ENDVERTEX_ZERR;   //!
  TBranch        *b_Dstar_ENDVERTEX_CHI2;   //!
  TBranch        *b_Dstar_ENDVERTEX_NDOF;   //!
  TBranch        *b_Dstar_ENDVERTEX_COV_;   //!
  TBranch        *b_Dstar_OWNPV_X;   //!
  TBranch        *b_Dstar_OWNPV_Y;   //!
  TBranch        *b_Dstar_OWNPV_Z;   //!
  TBranch        *b_Dstar_OWNPV_XERR;   //!
  TBranch        *b_Dstar_OWNPV_YERR;   //!
  TBranch        *b_Dstar_OWNPV_ZERR;   //!
  TBranch        *b_Dstar_OWNPV_CHI2;   //!
  TBranch        *b_Dstar_OWNPV_NDOF;   //!
  TBranch        *b_Dstar_OWNPV_COV_;   //!
  TBranch        *b_Dstar_IP_OWNPV;   //!
  TBranch        *b_Dstar_IPCHI2_OWNPV;   //!
  TBranch        *b_Dstar_FD_OWNPV;   //!
  TBranch        *b_Dstar_FDCHI2_OWNPV;   //!
  TBranch        *b_Dstar_DIRA_OWNPV;   //!
  TBranch        *b_Dstar_ORIVX_X;   //!
  TBranch        *b_Dstar_ORIVX_Y;   //!
  TBranch        *b_Dstar_ORIVX_Z;   //!
  TBranch        *b_Dstar_ORIVX_XERR;   //!
  TBranch        *b_Dstar_ORIVX_YERR;   //!
  TBranch        *b_Dstar_ORIVX_ZERR;   //!
  TBranch        *b_Dstar_ORIVX_CHI2;   //!
  TBranch        *b_Dstar_ORIVX_NDOF;   //!
  TBranch        *b_Dstar_ORIVX_COV_;   //!
  TBranch        *b_Dstar_FD_ORIVX;   //!
  TBranch        *b_Dstar_FDCHI2_ORIVX;   //!
  TBranch        *b_Dstar_DIRA_ORIVX;   //!
  TBranch        *b_Dstar_P;   //!
  TBranch        *b_Dstar_PT;   //!
  TBranch        *b_Dstar_PE;   //!
  TBranch        *b_Dstar_PX;   //!
  TBranch        *b_Dstar_PY;   //!
  TBranch        *b_Dstar_PZ;   //!
  TBranch        *b_Dstar_MM;   //!
  TBranch        *b_Dstar_MMERR;   //!
  TBranch        *b_Dstar_M;   //!
  TBranch        *b_Dstar_ID;   //!
  /*  TBranch        *b_Dstar_DstFit_nPV;   //!
  TBranch        *b_Dstar_DstFit_COV_E_E;   //!
  TBranch        *b_Dstar_DstFit_COV_E_PX;   //!
  TBranch        *b_Dstar_DstFit_COV_E_PY;   //!
  TBranch        *b_Dstar_DstFit_COV_E_PZ;   //!
  TBranch        *b_Dstar_DstFit_COV_PX_PX;   //!
  TBranch        *b_Dstar_DstFit_COV_PX_PY;   //!
  TBranch        *b_Dstar_DstFit_COV_PX_PZ;   //!
  TBranch        *b_Dstar_DstFit_COV_PY_PY;   //!
  TBranch        *b_Dstar_DstFit_COV_PY_PZ;   //!
  TBranch        *b_Dstar_DstFit_COV_PZ_PZ;   //!
  TBranch        *b_Dstar_DstFit_D0_COV_E_E;   //!
  TBranch        *b_Dstar_DstFit_D0_COV_E_PX;   //!
  TBranch        *b_Dstar_DstFit_D0_COV_E_PY;   //!
  TBranch        *b_Dstar_DstFit_D0_COV_E_PZ;   //!
  TBranch        *b_Dstar_DstFit_D0_COV_PX_PX;   //!
  TBranch        *b_Dstar_DstFit_D0_COV_PX_PY;   //!
  TBranch        *b_Dstar_DstFit_D0_COV_PX_PZ;   //!
  TBranch        *b_Dstar_DstFit_D0_COV_PY_PY;   //!
  TBranch        *b_Dstar_DstFit_D0_COV_PY_PZ;   //!
  TBranch        *b_Dstar_DstFit_D0_COV_PZ_PZ;   //!
  TBranch        *b_Dstar_DstFit_D0_E;   //!
  TBranch        *b_Dstar_DstFit_D0_M;   //!
  TBranch        *b_Dstar_DstFit_D0_MERR;   //!
  TBranch        *b_Dstar_DstFit_D0_PX;   //!
  TBranch        *b_Dstar_DstFit_D0_PY;   //!
  TBranch        *b_Dstar_DstFit_D0_PZ;   //!
  TBranch        *b_Dstar_DstFit_D0_ctau;   //!
  TBranch        *b_Dstar_DstFit_D0_ctauErr;   //!
  TBranch        *b_Dstar_DstFit_D0_decayLength;   //!
  TBranch        *b_Dstar_DstFit_D0_decayLengthErr;   //!
  TBranch        *b_Dstar_DstFit_E;   //!
  TBranch        *b_Dstar_DstFit_Kplus_COV_E_E;   //!
  TBranch        *b_Dstar_DstFit_Kplus_COV_E_PX;   //!
  TBranch        *b_Dstar_DstFit_Kplus_COV_E_PY;   //!
  TBranch        *b_Dstar_DstFit_Kplus_COV_E_PZ;   //!
  TBranch        *b_Dstar_DstFit_Kplus_COV_PX_PX;   //!
  TBranch        *b_Dstar_DstFit_Kplus_COV_PX_PY;   //!
  TBranch        *b_Dstar_DstFit_Kplus_COV_PX_PZ;   //!
  TBranch        *b_Dstar_DstFit_Kplus_COV_PY_PY;   //!
  TBranch        *b_Dstar_DstFit_Kplus_COV_PY_PZ;   //!
  TBranch        *b_Dstar_DstFit_Kplus_COV_PZ_PZ;   //!
  TBranch        *b_Dstar_DstFit_Kplus_E;   //!
  TBranch        *b_Dstar_DstFit_Kplus_PX;   //!
  TBranch        *b_Dstar_DstFit_Kplus_PY;   //!
  TBranch        *b_Dstar_DstFit_Kplus_PZ;   //!
  TBranch        *b_Dstar_DstFit_M;   //!
  TBranch        *b_Dstar_DstFit_MERR;   //!
  TBranch        *b_Dstar_DstFit_PX;   //!
  TBranch        *b_Dstar_DstFit_PY;   //!
  TBranch        *b_Dstar_DstFit_PZ;   //!
  TBranch        *b_Dstar_DstFit_chi2;   //!
  TBranch        *b_Dstar_DstFit_nDOF;   //!
  TBranch        *b_Dstar_DstFit_nIter;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_COV_E_E;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_COV_E_PX;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_COV_E_PY;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_COV_E_PZ;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_COV_PX_PX;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_COV_PX_PY;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_COV_PX_PZ;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_COV_PY_PY;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_COV_PY_PZ;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_COV_PZ_PZ;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_E;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_PX;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_PY;   //!
  TBranch        *b_Dstar_DstFit_piplus_0_PZ;   //!
  TBranch        *b_Dstar_DstFit_piplus_COV_E_E;   //!
  TBranch        *b_Dstar_DstFit_piplus_COV_E_PX;   //!
  TBranch        *b_Dstar_DstFit_piplus_COV_E_PY;   //!
  TBranch        *b_Dstar_DstFit_piplus_COV_E_PZ;   //!
  TBranch        *b_Dstar_DstFit_piplus_COV_PX_PX;   //!
  TBranch        *b_Dstar_DstFit_piplus_COV_PX_PY;   //!
  TBranch        *b_Dstar_DstFit_piplus_COV_PX_PZ;   //!
  TBranch        *b_Dstar_DstFit_piplus_COV_PY_PY;   //!
  TBranch        *b_Dstar_DstFit_piplus_COV_PY_PZ;   //!
  TBranch        *b_Dstar_DstFit_piplus_COV_PZ_PZ;   //!
  TBranch        *b_Dstar_DstFit_piplus_E;   //!
  TBranch        *b_Dstar_DstFit_piplus_PX;   //!
  TBranch        *b_Dstar_DstFit_piplus_PY;   //!
  TBranch        *b_Dstar_DstFit_piplus_PZ;   //!
  TBranch        *b_Dstar_DstFit_status;   //!
  */
  TBranch        *b_Dstar_L0Global_Dec;   //!
  TBranch        *b_Dstar_L0Global_TIS;   //!
  TBranch        *b_Dstar_L0Global_TOS;   //!
  TBranch        *b_Dstar_Hlt1Global_Dec;   //!
  TBranch        *b_Dstar_Hlt1Global_TIS;   //!
  TBranch        *b_Dstar_Hlt1Global_TOS;   //!
  TBranch        *b_Dstar_Hlt1Phys_Dec;   //!
  TBranch        *b_Dstar_Hlt1Phys_TIS;   //!
  TBranch        *b_Dstar_Hlt1Phys_TOS;   //!
  TBranch        *b_Dstar_Hlt2Global_Dec;   //!
  TBranch        *b_Dstar_Hlt2Global_TIS;   //!
  TBranch        *b_Dstar_Hlt2Global_TOS;   //!
  TBranch        *b_Dstar_Hlt2Phys_Dec;   //!
  TBranch        *b_Dstar_Hlt2Phys_TIS;   //!
  TBranch        *b_Dstar_Hlt2Phys_TOS;   //!
  TBranch        *b_Dstar_Hlt1TrackAllL0Decision_Dec;   //!
  TBranch        *b_Dstar_Hlt1TrackAllL0Decision_TIS;   //!
  TBranch        *b_Dstar_Hlt1TrackAllL0Decision_TOS;   //!
  TBranch        *b_D_ENDVERTEX_X;   //!
  TBranch        *b_D_ENDVERTEX_Y;   //!
  TBranch        *b_D_ENDVERTEX_Z;   //!
  TBranch        *b_D_ENDVERTEX_XERR;   //!
  TBranch        *b_D_ENDVERTEX_YERR;   //!
  TBranch        *b_D_ENDVERTEX_ZERR;   //!
  TBranch        *b_D_ENDVERTEX_CHI2;   //!
  TBranch        *b_D_ENDVERTEX_NDOF;   //!
  TBranch        *b_D_ENDVERTEX_COV_;   //!
  TBranch        *b_D_OWNPV_X;   //!
  TBranch        *b_D_OWNPV_Y;   //!
  TBranch        *b_D_OWNPV_Z;   //!
  TBranch        *b_D_OWNPV_XERR;   //!
  TBranch        *b_D_OWNPV_YERR;   //!
  TBranch        *b_D_OWNPV_ZERR;   //!
  TBranch        *b_D_OWNPV_CHI2;   //!
  TBranch        *b_D_OWNPV_NDOF;   //!
  TBranch        *b_D_OWNPV_COV_;   //!
  TBranch        *b_D_IP_OWNPV;   //!
  TBranch        *b_D_IPCHI2_OWNPV;   //!
  TBranch        *b_D_FD_OWNPV;   //!
  TBranch        *b_D_FDCHI2_OWNPV;   //!
  TBranch        *b_D_DIRA_OWNPV;   //!
  TBranch        *b_D_ORIVX_X;   //!
  TBranch        *b_D_ORIVX_Y;   //!
  TBranch        *b_D_ORIVX_Z;   //!
  TBranch        *b_D_ORIVX_XERR;   //!
  TBranch        *b_D_ORIVX_YERR;   //!
  TBranch        *b_D_ORIVX_ZERR;   //!
  TBranch        *b_D_ORIVX_CHI2;   //!
  TBranch        *b_D_ORIVX_NDOF;   //!
  TBranch        *b_D_ORIVX_COV_;   //!
  TBranch        *b_D_FD_ORIVX;   //!
  TBranch        *b_D_FDCHI2_ORIVX;   //!
  TBranch        *b_D_DIRA_ORIVX;   //!
  TBranch        *b_D_P;   //!
  TBranch        *b_D_PT;   //!
  TBranch        *b_D_PE;   //!
  TBranch        *b_D_PX;   //!
  TBranch        *b_D_PY;   //!
  TBranch        *b_D_PZ;   //!
  TBranch        *b_D_MM;   //!
  TBranch        *b_D_MMERR;   //!
  TBranch        *b_D_M;   //!
  TBranch        *b_D_ID;   //!
  TBranch        *b_K_MC12TuneV2_ProbNNe;   //!
  TBranch        *b_K_MC12TuneV2_ProbNNmu;   //!
  TBranch        *b_K_MC12TuneV2_ProbNNpi;   //!
  TBranch        *b_K_MC12TuneV2_ProbNNk;   //!
  TBranch        *b_K_MC12TuneV2_ProbNNp;   //!
  TBranch        *b_K_MC12TuneV2_ProbNNghost;   //!
  TBranch        *b_K_MC12TuneV3_ProbNNe;   //!
  TBranch        *b_K_MC12TuneV3_ProbNNmu;   //!
  TBranch        *b_K_MC12TuneV3_ProbNNpi;   //!
  TBranch        *b_K_MC12TuneV3_ProbNNk;   //!
  TBranch        *b_K_MC12TuneV3_ProbNNp;   //!
  TBranch        *b_K_MC12TuneV3_ProbNNghost;   //!
  TBranch        *b_K_OWNPV_X;   //!
  TBranch        *b_K_OWNPV_Y;   //!
  TBranch        *b_K_OWNPV_Z;   //!
  TBranch        *b_K_OWNPV_XERR;   //!
  TBranch        *b_K_OWNPV_YERR;   //!
  TBranch        *b_K_OWNPV_ZERR;   //!
  TBranch        *b_K_OWNPV_CHI2;   //!
  TBranch        *b_K_OWNPV_NDOF;   //!
  TBranch        *b_K_OWNPV_COV_;   //!
  TBranch        *b_K_IP_OWNPV;   //!
  TBranch        *b_K_IPCHI2_OWNPV;   //!
  TBranch        *b_K_ORIVX_X;   //!
  TBranch        *b_K_ORIVX_Y;   //!
  TBranch        *b_K_ORIVX_Z;   //!
  TBranch        *b_K_ORIVX_XERR;   //!
  TBranch        *b_K_ORIVX_YERR;   //!
  TBranch        *b_K_ORIVX_ZERR;   //!
  TBranch        *b_K_ORIVX_CHI2;   //!
  TBranch        *b_K_ORIVX_NDOF;   //!
  TBranch        *b_K_ORIVX_COV_;   //!
  TBranch        *b_K_P;   //!
  TBranch        *b_K_PT;   //!
  TBranch        *b_K_PE;   //!
  TBranch        *b_K_PX;   //!
  TBranch        *b_K_PY;   //!
  TBranch        *b_K_PZ;   //!
  TBranch        *b_K_M;   //!
  TBranch        *b_K_ID;   //!
  TBranch        *b_K_PIDe;   //!
  TBranch        *b_K_PIDmu;   //!
  TBranch        *b_K_PIDK;   //!
  TBranch        *b_K_PIDp;   //!
  TBranch        *b_K_ProbNNe;   //!
  TBranch        *b_K_ProbNNk;   //!
  TBranch        *b_K_ProbNNp;   //!
  TBranch        *b_K_ProbNNpi;   //!
  TBranch        *b_K_ProbNNmu;   //!
  TBranch        *b_K_ProbNNghost;   //!
  TBranch        *b_K_hasMuon;   //!
  TBranch        *b_K_isMuon;   //!
  TBranch        *b_K_hasRich;   //!
  TBranch        *b_K_hasCalo;   //!
  TBranch        *b_K_TRACK_Type;   //!
  TBranch        *b_K_TRACK_Key;   //!
  TBranch        *b_K_TRACK_CHI2NDOF;   //!
  TBranch        *b_K_TRACK_PCHI2;   //!
  TBranch        *b_K_TRACK_MatchCHI2;   //!
  TBranch        *b_K_TRACK_GhostProb;   //!
  TBranch        *b_K_TRACK_CloneDist;   //!
  TBranch        *b_K_TRACK_Likelihood;   //!
  TBranch        *b_Pd_MC12TuneV2_ProbNNe;   //!
  TBranch        *b_Pd_MC12TuneV2_ProbNNmu;   //!
  TBranch        *b_Pd_MC12TuneV2_ProbNNpi;   //!
  TBranch        *b_Pd_MC12TuneV2_ProbNNk;   //!
  TBranch        *b_Pd_MC12TuneV2_ProbNNp;   //!
  TBranch        *b_Pd_MC12TuneV2_ProbNNghost;   //!
  TBranch        *b_Pd_MC12TuneV3_ProbNNe;   //!
  TBranch        *b_Pd_MC12TuneV3_ProbNNmu;   //!
  TBranch        *b_Pd_MC12TuneV3_ProbNNpi;   //!
  TBranch        *b_Pd_MC12TuneV3_ProbNNk;   //!
  TBranch        *b_Pd_MC12TuneV3_ProbNNp;   //!
  TBranch        *b_Pd_MC12TuneV3_ProbNNghost;   //!
  TBranch        *b_Pd_OWNPV_X;   //!
  TBranch        *b_Pd_OWNPV_Y;   //!
  TBranch        *b_Pd_OWNPV_Z;   //!
  TBranch        *b_Pd_OWNPV_XERR;   //!
  TBranch        *b_Pd_OWNPV_YERR;   //!
  TBranch        *b_Pd_OWNPV_ZERR;   //!
  TBranch        *b_Pd_OWNPV_CHI2;   //!
  TBranch        *b_Pd_OWNPV_NDOF;   //!
  TBranch        *b_Pd_OWNPV_COV_;   //!
  TBranch        *b_Pd_IP_OWNPV;   //!
  TBranch        *b_Pd_IPCHI2_OWNPV;   //!
  TBranch        *b_Pd_ORIVX_X;   //!
  TBranch        *b_Pd_ORIVX_Y;   //!
  TBranch        *b_Pd_ORIVX_Z;   //!
  TBranch        *b_Pd_ORIVX_XERR;   //!
  TBranch        *b_Pd_ORIVX_YERR;   //!
  TBranch        *b_Pd_ORIVX_ZERR;   //!
  TBranch        *b_Pd_ORIVX_CHI2;   //!
  TBranch        *b_Pd_ORIVX_NDOF;   //!
  TBranch        *b_Pd_ORIVX_COV_;   //!
  TBranch        *b_Pd_P;   //!
  TBranch        *b_Pd_PT;   //!
  TBranch        *b_Pd_PE;   //!
  TBranch        *b_Pd_PX;   //!
  TBranch        *b_Pd_PY;   //!
  TBranch        *b_Pd_PZ;   //!
  TBranch        *b_Pd_M;   //!
  TBranch        *b_Pd_ID;   //!
  TBranch        *b_Pd_PIDe;   //!
  TBranch        *b_Pd_PIDmu;   //!
  TBranch        *b_Pd_PIDK;   //!
  TBranch        *b_Pd_PIDp;   //!
  TBranch        *b_Pd_ProbNNe;   //!
  TBranch        *b_Pd_ProbNNk;   //!
  TBranch        *b_Pd_ProbNNp;   //!
  TBranch        *b_Pd_ProbNNpi;   //!
  TBranch        *b_Pd_ProbNNmu;   //!
  TBranch        *b_Pd_ProbNNghost;   //!
  TBranch        *b_Pd_hasMuon;   //!
  TBranch        *b_Pd_isMuon;   //!
  TBranch        *b_Pd_hasRich;   //!
  TBranch        *b_Pd_hasCalo;   //!
  TBranch        *b_Pd_TRACK_Type;   //!
  TBranch        *b_Pd_TRACK_Key;   //!
  TBranch        *b_Pd_TRACK_CHI2NDOF;   //!
  TBranch        *b_Pd_TRACK_PCHI2;   //!
  TBranch        *b_Pd_TRACK_MatchCHI2;   //!
  TBranch        *b_Pd_TRACK_GhostProb;   //!
  TBranch        *b_Pd_TRACK_CloneDist;   //!
  TBranch        *b_Pd_TRACK_Likelihood;   //!
  TBranch        *b_Ps_MC12TuneV2_ProbNNe;   //!
  TBranch        *b_Ps_MC12TuneV2_ProbNNmu;   //!
  TBranch        *b_Ps_MC12TuneV2_ProbNNpi;   //!
  TBranch        *b_Ps_MC12TuneV2_ProbNNk;   //!
  TBranch        *b_Ps_MC12TuneV2_ProbNNp;   //!
  TBranch        *b_Ps_MC12TuneV2_ProbNNghost;   //!
  TBranch        *b_Ps_MC12TuneV3_ProbNNe;   //!
  TBranch        *b_Ps_MC12TuneV3_ProbNNmu;   //!
  TBranch        *b_Ps_MC12TuneV3_ProbNNpi;   //!
  TBranch        *b_Ps_MC12TuneV3_ProbNNk;   //!
  TBranch        *b_Ps_MC12TuneV3_ProbNNp;   //!
  TBranch        *b_Ps_MC12TuneV3_ProbNNghost;   //!
  TBranch        *b_Ps_OWNPV_X;   //!
  TBranch        *b_Ps_OWNPV_Y;   //!
  TBranch        *b_Ps_OWNPV_Z;   //!
  TBranch        *b_Ps_OWNPV_XERR;   //!
  TBranch        *b_Ps_OWNPV_YERR;   //!
  TBranch        *b_Ps_OWNPV_ZERR;   //!
  TBranch        *b_Ps_OWNPV_CHI2;   //!
  TBranch        *b_Ps_OWNPV_NDOF;   //!
  TBranch        *b_Ps_OWNPV_COV_;   //!
  TBranch        *b_Ps_IP_OWNPV;   //!
  TBranch        *b_Ps_IPCHI2_OWNPV;   //!
  TBranch        *b_Ps_ORIVX_X;   //!
  TBranch        *b_Ps_ORIVX_Y;   //!
  TBranch        *b_Ps_ORIVX_Z;   //!
  TBranch        *b_Ps_ORIVX_XERR;   //!
  TBranch        *b_Ps_ORIVX_YERR;   //!
  TBranch        *b_Ps_ORIVX_ZERR;   //!
  TBranch        *b_Ps_ORIVX_CHI2;   //!
  TBranch        *b_Ps_ORIVX_NDOF;   //!
  TBranch        *b_Ps_ORIVX_COV_;   //!
  TBranch        *b_Ps_P;   //!
  TBranch        *b_Ps_PT;   //!
  TBranch        *b_Ps_PE;   //!
  TBranch        *b_Ps_PX;   //!
  TBranch        *b_Ps_PY;   //!
  TBranch        *b_Ps_PZ;   //!
  TBranch        *b_Ps_M;   //!
  TBranch        *b_Ps_ID;   //!
  TBranch        *b_Ps_PIDe;   //!
  TBranch        *b_Ps_PIDmu;   //!
  TBranch        *b_Ps_PIDK;   //!
  TBranch        *b_Ps_PIDp;   //!
  TBranch        *b_Ps_ProbNNe;   //!
  TBranch        *b_Ps_ProbNNk;   //!
  TBranch        *b_Ps_ProbNNp;   //!
  TBranch        *b_Ps_ProbNNpi;   //!
  TBranch        *b_Ps_ProbNNmu;   //!
  TBranch        *b_Ps_ProbNNghost;   //!
  TBranch        *b_Ps_hasMuon;   //!
  TBranch        *b_Ps_isMuon;   //!
  TBranch        *b_Ps_hasRich;   //!
  TBranch        *b_Ps_hasCalo;   //!
  TBranch        *b_Ps_TRACK_Type;   //!
  TBranch        *b_Ps_TRACK_Key;   //!
  TBranch        *b_Ps_TRACK_CHI2NDOF;   //!
  TBranch        *b_Ps_TRACK_PCHI2;   //!
  TBranch        *b_Ps_TRACK_MatchCHI2;   //!
  TBranch        *b_Ps_TRACK_GhostProb;   //!
  TBranch        *b_Ps_TRACK_CloneDist;   //!
  TBranch        *b_Ps_TRACK_Likelihood;   //!
  TBranch        *b_Mu_MC12TuneV2_ProbNNe;   //!
  TBranch        *b_Mu_MC12TuneV2_ProbNNmu;   //!
  TBranch        *b_Mu_MC12TuneV2_ProbNNpi;   //!
  TBranch        *b_Mu_MC12TuneV2_ProbNNk;   //!
  TBranch        *b_Mu_MC12TuneV2_ProbNNp;   //!
  TBranch        *b_Mu_MC12TuneV2_ProbNNghost;   //!
  TBranch        *b_Mu_MC12TuneV3_ProbNNe;   //!
  TBranch        *b_Mu_MC12TuneV3_ProbNNmu;   //!
  TBranch        *b_Mu_MC12TuneV3_ProbNNpi;   //!
  TBranch        *b_Mu_MC12TuneV3_ProbNNk;   //!
  TBranch        *b_Mu_MC12TuneV3_ProbNNp;   //!
  TBranch        *b_Mu_MC12TuneV3_ProbNNghost;   //!
  TBranch        *b_Mu_OWNPV_X;   //!
  TBranch        *b_Mu_OWNPV_Y;   //!
  TBranch        *b_Mu_OWNPV_Z;   //!
  TBranch        *b_Mu_OWNPV_XERR;   //!
  TBranch        *b_Mu_OWNPV_YERR;   //!
  TBranch        *b_Mu_OWNPV_ZERR;   //!
  TBranch        *b_Mu_OWNPV_CHI2;   //!
  TBranch        *b_Mu_OWNPV_NDOF;   //!
  TBranch        *b_Mu_OWNPV_COV_;   //!
  TBranch        *b_Mu_IP_OWNPV;   //!
  TBranch        *b_Mu_IPCHI2_OWNPV;   //!
  TBranch        *b_Mu_ORIVX_X;   //!
  TBranch        *b_Mu_ORIVX_Y;   //!
  TBranch        *b_Mu_ORIVX_Z;   //!
  TBranch        *b_Mu_ORIVX_XERR;   //!
  TBranch        *b_Mu_ORIVX_YERR;   //!
  TBranch        *b_Mu_ORIVX_ZERR;   //!
  TBranch        *b_Mu_ORIVX_CHI2;   //!
  TBranch        *b_Mu_ORIVX_NDOF;   //!
  TBranch        *b_Mu_ORIVX_COV_;   //!
  TBranch        *b_Mu_P;   //!
  TBranch        *b_Mu_PT;   //!
  TBranch        *b_Mu_PE;   //!
  TBranch        *b_Mu_PX;   //!
  TBranch        *b_Mu_PY;   //!
  TBranch        *b_Mu_PZ;   //!
  TBranch        *b_Mu_M;   //!
  TBranch        *b_Mu_ID;   //!
  TBranch        *b_Mu_PIDe;   //!
  TBranch        *b_Mu_PIDmu;   //!
  TBranch        *b_Mu_PIDK;   //!
  TBranch        *b_Mu_PIDp;   //!
  TBranch        *b_Mu_ProbNNe;   //!
  TBranch        *b_Mu_ProbNNk;   //!
  TBranch        *b_Mu_ProbNNp;   //!
  TBranch        *b_Mu_ProbNNpi;   //!
  TBranch        *b_Mu_ProbNNmu;   //!
  TBranch        *b_Mu_ProbNNghost;   //!
  TBranch        *b_Mu_hasMuon;   //!
  TBranch        *b_Mu_isMuon;   //!
  TBranch        *b_Mu_hasRich;   //!
  TBranch        *b_Mu_hasCalo;   //!
  TBranch        *b_Mu_TRACK_Type;   //!
  TBranch        *b_Mu_TRACK_Key;   //!
  TBranch        *b_Mu_TRACK_CHI2NDOF;   //!
  TBranch        *b_Mu_TRACK_PCHI2;   //!
  TBranch        *b_Mu_TRACK_MatchCHI2;   //!
  TBranch        *b_Mu_TRACK_GhostProb;   //!
  TBranch        *b_Mu_TRACK_CloneDist;   //!
  TBranch        *b_Mu_TRACK_Likelihood;   //!
  TBranch        *b_Mu_n_extra_mu;   //!
  TBranch        *b_Mu_extra_mu_PX;   //!
  TBranch        *b_Mu_extra_mu_PY;   //!
  TBranch        *b_Mu_extra_mu_PZ;   //!
  TBranch        *b_Mu_extra_mu_E;   //!
  TBranch        *b_Mu_extra_mu_ID;   //!
  TBranch        *b_Mu_extra_mu_PIDmu;   //!
  TBranch        *b_Mu_extra_mu_PIDK;   //!
  TBranch        *b_Mu_extra_mu_ProbNNghost;   //!
  TBranch        *b_Mu_extra_mu_TRACK_ghostProb;   //!
  TBranch        *b_Mu_extra_mu_TRACK_chi2perDoF;   //!
  TBranch        *b_Mu_dimuon_M;   //!
  TBranch        *b_Mu_extra_mu_mu_vtx_chi2;   //!
  TBranch        *b_Mu_extra_mu_mu_vtx_nDoF;   //!
  TBranch        *b_Mu_extra_mu_dst_vtx_chi2;   //!
  TBranch        *b_Mu_extra_mu_dst_vtx_nDoF;   //!
  TBranch        *b_Mu_dst_mu_extra_M;   //!
  TBranch        *b_Mu_extra_mu_IP;   //!
  TBranch        *b_Mu_extra_mu_IPchi2;   //!
  TBranch        *b_Mu_extra_mu_PV_match;   //!
  TBranch        *b_Mu_extra_mu_IP_muPV;   //!
  TBranch        *b_Mu_extra_mu_IPchi2_muPV;   //!
  TBranch        *b_Mu_L0Global_Dec;   //!
  TBranch        *b_Mu_L0Global_TIS;   //!
  TBranch        *b_Mu_L0Global_TOS;   //!
  TBranch        *b_Mu_Hlt1Global_Dec;   //!
  TBranch        *b_Mu_Hlt1Global_TIS;   //!
  TBranch        *b_Mu_Hlt1Global_TOS;   //!
  TBranch        *b_Mu_Hlt1Phys_Dec;   //!
  TBranch        *b_Mu_Hlt1Phys_TIS;   //!
  TBranch        *b_Mu_Hlt1Phys_TOS;   //!
  TBranch        *b_Mu_Hlt2Global_Dec;   //!
  TBranch        *b_Mu_Hlt2Global_TIS;   //!
  TBranch        *b_Mu_Hlt2Global_TOS;   //!
  TBranch        *b_Mu_Hlt2Phys_Dec;   //!
  TBranch        *b_Mu_Hlt2Phys_TIS;   //!
  TBranch        *b_Mu_Hlt2Phys_TOS;   //!
  TBranch        *b_Mu_L0MuonDecision_Dec;   //!
  TBranch        *b_Mu_L0MuonDecision_TIS;   //!
  TBranch        *b_Mu_L0MuonDecision_TOS;   //!
  TBranch        *b_Mu_Hlt1TrackMuonDecision_Dec;   //!
  TBranch        *b_Mu_Hlt1TrackMuonDecision_TIS;   //!
  TBranch        *b_Mu_Hlt1TrackMuonDecision_TOS;   //!
  TBranch        *b_Mu_Hlt2SingleMuonDecision_Dec;   //!
  TBranch        *b_Mu_Hlt2SingleMuonDecision_TIS;   //!
  TBranch        *b_Mu_Hlt2SingleMuonDecision_TOS;   //!
  TBranch        *b_nCandidate;   //!
  TBranch        *b_totCandidates;   //!
  TBranch        *b_EventInSequence;   //!
  TBranch        *b_runNumber;   //!
  TBranch        *b_eventNumber;   //!
  TBranch        *b_BCID;   //!
  TBranch        *b_BCType;   //!
  TBranch        *b_OdinTCK;   //!
  TBranch        *b_L0DUTCK;   //!
  TBranch        *b_HLTTCK;   //!
  TBranch        *b_GpsTime;   //!
  TBranch        *b_Polarity;   //!
  TBranch        *b_nPV;   //!
  TBranch        *b_PVX;   //!
  TBranch        *b_PVY;   //!
  TBranch        *b_PVZ;   //!
  TBranch        *b_PVXERR;   //!
  TBranch        *b_PVYERR;   //!
  TBranch        *b_PVZERR;   //!
  TBranch        *b_PVCHI2;   //!
  TBranch        *b_PVNDOF;   //!
  TBranch        *b_PVNTRACKS;   //!
  TBranch        *b_nPVs;   //!
  TBranch        *b_nTracks;   //!
  TBranch        *b_nLongTracks;   //!
  TBranch        *b_nDownstreamTracks;   //!
  TBranch        *b_nUpstreamTracks;   //!
  TBranch        *b_nVeloTracks;   //!
  TBranch        *b_nTTracks;   //!
  TBranch        *b_nBackTracks;   //!
  TBranch        *b_nRich1Hits;   //!
  TBranch        *b_nRich2Hits;   //!
  TBranch        *b_nVeloClusters;   //!
  TBranch        *b_nITClusters;   //!
  TBranch        *b_nTTClusters;   //!
  TBranch        *b_nOTClusters;   //!
  TBranch        *b_nSPDHits;   //!
  TBranch        *b_nMuonCoordsS0;   //!
  TBranch        *b_nMuonCoordsS1;   //!
  TBranch        *b_nMuonCoordsS2;   //!
  TBranch        *b_nMuonCoordsS3;   //!
  TBranch        *b_nMuonCoordsS4;   //!
  TBranch        *b_nMuonTracks;   //!
  TBranch        *b_L0Global;   //!
  TBranch        *b_Hlt1Global;   //!
  TBranch        *b_Hlt2Global;   //!


  //all of these histograms can be deleted in the unbinned fit in favour of a new ttree.
  //make a smaller ttree
  //the variables we want to store are
  //dstar mass as angelo defines
  //d0 mass
  //decay time
  //dstar pt
  //dstar p
  //mu pt
  //mu p
  //slow pion charge
  //polarity
  //DTF chi2
  //slow pion match ipchi2
  //slow pion ghost prob
  //D0 ipchi2
  //B fdchi2
  //mu ipchi2
  
  // no more histograms in unbinned.

  TTree* newTree;//want doubles, so you can't use tntuple

  virtual Int_t passCuts();
  DT_D0_mix_CPV(TTree *tree=0);
  virtual ~DT_D0_mix_CPV();
  virtual Int_t    Cut(Long64_t entry);
  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop();
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);
  void setRejectionFile(TString path_to_file);
  bool foundMatch(matchelement_t el);
private:

  TBranch* brDstM;
  TBranch* brD0M;
  TBranch* brTD0;
  TBranch* brPisQ;
  TBranch* brD0ipChi2;
  //for liang
  TBranch* brKpx;
  TBranch* brPipx;
  TBranch* brPiSpx;
  
  TBranch* brKpy;
  TBranch* brPipy;
  TBranch* brPiSpy;

  TBranch* brKpz;
  TBranch* brPipz;
  TBranch* brPiSpz;
  TBranch* brRunNum;
  TBranch* brEvNum;
  // end for liang
  //for kpi asymmetry
  TBranch* brDTFK_px;
  TBranch* brDTFK_py;
  TBranch* brDTFK_pz;
  TBranch* brDTFPi_px;
  TBranch* brDTFPi_py;
  TBranch* brDTFPi_pz;
  TBranch* brDTFPiS_px;
  TBranch* brDTFPiS_py;
  TBranch* brDTFPiS_pz;
  TBranch* brMu_px;
  TBranch* brMu_py;
  TBranch* brMu_pz;
  TBranch* brDTFMu_px;
  TBranch* brDTFMu_py;
  TBranch* brDTFMu_pz;
  TBranch* brK_PIDK;
  TBranch* brPi_PIDK;
  //end kpi asymmetry
  //extras for systematics
  TBranch* brD0P;
  TBranch* brD0Pt;
  TBranch* brMuIPchi2;
  TBranch* brBmass;
  TBranch* brBFlightDist;
  TBranch* brBFlightDistChisq;
  TBranch* brDstarvtxX;
  TBranch* brDstarvtxY;
  TBranch* brDstarvtxZ;

  TBranch* brPVX;
  TBranch* brPVY;
  TBranch* brPVZ;

  TBranch* brnCandid;
  //end extras for systematics
  //begin for PID calib
  TBranch* brnTrk;//number of tracks
  TBranch* brnpvs;//number of PVs
  TBranch* br_K_P;//just the total momentum
  TBranch* br_K_eta;//K eta
  TBranch* br_K_PT;//Pt
  TBranch* br_K_PIDp;//
  double newKeta;
  //end PID calib
  double newDstM;
  double newD0M;
  double newBmass;
  double newDecayTime;
  int newPiScharge;
  double newD0ipChi2;
  
  TLorentzVector k_daughter;
  TLorentzVector pi_daughter;
  TLorentzVector mu_vec;
  TLorentzVector slow_pion_vec;
  TLorentzVector pi_daughter_as_k;
  TLorentzVector k_daughter_as_pi;
  TLorentzVector mu_from_b;
  TLorentzVector extra_muon;
  TLorentzVector d0_vector;
  //TLorentzVector dstar_vector;
  const double pdg_d0_m = 1864.84;// MeV
  const double pdg_dstar_m = 2010.26;// MeV
  const double pdg_kplus_m = 493.677;// MeV
  const double pdg_piplus_m = 139.57018;//MeV
  const double kpidk_cut = 8;
  //const double kpidk_cut = 2;
  const double pi_dau_pidk_cut = -5;
  //  const double pi_dau_pidk_cut = 2;
  const double pi_slow_pide_cut=1;
  const double pi_slow_probnnghost_cut = 0.5;
  const double dmass_cut = 24;// MeV, for |m - m_pdg|<dmass_cut
  const double dstar_mass_cut = 0.9;
  const double mu_probnnmu_cut = 0.4;
  const double kk_pipi_cut = 40;// MeV
  const double bmass_cut_hi = 5100.;// MeV
  const double bmass_cut_low =3100.;//MeV
  const double pis_ghost_prob_cut = 0.25;//no units
  const double dtf_chi2_ndf_cut = 100;
  //const double pis_pt_cut = 100;//MeV
  //const double pis_probnnp_cut =  0.4;//less than this, no unitso
  //  const double mu_ip_chi2_cut = 100;//no units
  //  const double dst_bin_boundary1=2.690000e+03;//MeV
  //const double dst_bin_boundary2=4.330000e+03;//MeV, pt bin boundaries.
  const double dst_pt_bin_boundary1 = 2.130000e+03;//MeV
  const double dst_pt_bin_boundary2 = 2.950000e+03;//MeV
  const double dst_pt_bin_boundary3 = 3.910000e+03;//MeV
  const double dst_pt_bin_boundary4 = 5.470000e+03;//MeV

  const double dst_p_bin_boundary1 = 3.570000e+04;//MeV
  const double dst_p_bin_boundary2 = 4.590000e+04;//MeV
  const double dst_p_bin_boundary3 = 5.870000e+04;//MeV
  const double dst_p_bin_boundary4 = 7.990000e+04;//MeV

  const double mu_pt_bin_boundary1 = 2.070000e+03;//MeV
  const double mu_pt_bin_boundary2 = 2.630000e+03;//MeV
  const double mu_pt_bin_boundary3 = 3.310000e+03;//MeV
  const double mu_pt_bin_boundary4 = 4.450000e+03;//MeV

  const double mu_p_bin_boundary1 = 1.970000e+04;//MeV
  const double mu_p_bin_boundary2 = 2.990000e+04;//MeV
  const double mu_p_bin_boundary3 = 4.310000e+04;//MeV
  const double mu_p_bin_boundary4 = 6.510000e+04;//MeV

  const double mu_log_ip_bin_boundary1 = -1.585000e+00;//nominally mm, but log...
  const double mu_log_ip_bin_boundary2 =-1.115000e+00;
  const double mu_log_ip_bin_boundary3 =-6.850000e-01;
  const double mu_log_ip_bin_boundary4 =-1.850000e-01;

  const double k_pid_k_bin_boundary1 = 1.250000e+01;
  const double k_pid_k_bin_boundary2 = 2.050000e+01;
  const double k_pid_k_bin_boundary3 = 2.750000e+01;
  const double k_pid_k_bin_boundary4 = 3.850000e+01;

  const double pi_pid_k_bin_boundary1 = -4.050000e+01;
  const double pi_pid_k_bin_boundary2 = -2.550000e+01;
  const double pi_pid_k_bin_boundary3 = -1.450000e+01;
  const double pi_pid_k_bin_boundary4 = -5.500000e+00;

  //pid boundaries
  //decay time bin boundaries.
  /*const double d0_td0_bin_boundary1 = -0.5;
  const double d0_td0_bin_boundary2 = 0.25;
  const double d0_td0_bin_boundary3 = 0.55;
  const double d0_td0_bin_boundary4 = 0.95;
  const double d0_td0_bin_boundary5 = 1.55;//all for t/tau.
  */
  //change if we want more bins
  const double d0_td0_bin_boundary1 = -0.5;
  const double d0_td0_bin_boundary1a = 0.10;
  const double d0_td0_bin_boundary2 = 0.25;
  const double d0_td0_bin_boundary2a = 0.40;
  const double d0_td0_bin_boundary3 = 0.55;
  const double d0_td0_bin_boundary3a = 0.70;
  const double d0_td0_bin_boundary4 = 0.95;
  const double d0_td0_bin_boundary4a = 1.25;
  const double d0_td0_bin_boundary5 = 1.55;//all for t/tau.
  const double d0_td0_bin_boundary5a = 5.75;
  //just split all these in half, not necessarily the best way to do it, but whatever
  //did this so that the first bin in still encompassing some positive decay time.
  
  //
  //slow pion ghost bin boundaries
  const double pis_ghost_bin_boundary1 =0.0005;
  const double pis_ghost_bin_boundary2 =0.0025;
  const double pis_ghost_bin_boundary3 =0.0045;
  const double pis_ghost_bin_boundary4 =0.0065;
  const double pis_ghost_bin_boundary5 =0.0095;
  const double pis_ghost_bin_boundary6 =0.0125;
  const double pis_ghost_bin_boundary7 =0.0165;
  const double pis_ghost_bin_boundary8 =0.0205;
  const double pis_ghost_bin_boundary9 =0.0265;
  const double pis_ghost_bin_boundary10=0.0325;
  const double pis_ghost_bin_boundary11=0.0405;
  const double pis_ghost_bin_boundary12=0.0505;
  const double pis_ghost_bin_boundary13=0.0635;
  const double pis_ghost_bin_boundary14=0.0785;
  const double pis_ghost_bin_boundary15=0.0995;
  const double pis_ghost_bin_boundary16=0.1265;
  const double pis_ghost_bin_boundary17=0.1625;
  const double pis_ghost_bin_boundary18=0.2115;
  const double pis_ghost_bin_boundary19=0.2795;
  const double pis_ghost_bin_boundary20=0.3735;
  std::vector<double> the_pis_ghost_prob_bin_boundaries;

  const double pis_gp_pf_vals[10] = {0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5};
  const double d0_pdg_ct = 0.1229;//mm
  //for matching
  std::vector<matchelement_t> matchedToPrompt;
  bool matchElement (matchelement_t i, matchelement_t j); 
  inline static bool sorter(matchelement_t i, matchelement_t j){return i.eventNumber<j.eventNumber;}

};

#endif

#ifdef DT_D0_mix_CPV_cxx
DT_D0_mix_CPV::DT_D0_mix_CPV(TTree *tree) : fChain(0) 
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    TFile *f =(TFile*)gROOT->GetListOfFiles()->FindObject("DT_2012md_root5.root");
    if (!f || !f->IsOpen()) {
      //std::cout<<""
      f = new TFile("DT_2012md_root5.root");
    }
    TDirectory * dir = (TDirectory*)
      f->Get("DT_2012md_root5.root:/RS");
    dir->GetObject("DecayTree",tree);
    
  }
  std::cout<<"tree name = "<<tree->GetName()<<std::endl;
  Init(tree);
  TString name = tree->GetName();
  name.ReplaceAll("/DecayTree","");
  //ntuple for shit
  //ntp = new TNtuple("ntp","UnbinnedDatasetNtuple","dstarM:decayTime");
  newTree = new TTree("newTree","newTreeForUnbinnnedDataset");
  brDstM = newTree->Branch("dstarM",&newDstM,"dstarM/D");
  brD0M = newTree->Branch("d0M",&newD0M,"d0M/D");
  brTD0 = newTree->Branch("tD0", &newDecayTime, "tD0/D");
  brPisQ = newTree->Branch("pisQ",&newPiScharge,"pisQ/I");
  brD0ipChi2 = newTree->Branch("d0IPchi2",&newD0ipChi2,"d0IPchi2/D");
  brBmass = newTree->Branch("bMass",&newBmass,"bMass/D");
  brBFlightDist = newTree->Branch("bFlightDist",&B_FD_OWNPV,"bFlightDist/D");
  brBFlightDistChisq=newTree->Branch("bFlightDistChisq",&B_FDCHI2_OWNPV,"bFlightDistChisq/D");
  brDstarvtxX = newTree->Branch("DstarVtxX",&Dstar_OWNPV_X,"DstarVtxX/D");
  brDstarvtxY = newTree->Branch("DstarVtxY",&Dstar_OWNPV_Y,"DstarVtxY/D");
  brDstarvtxZ = newTree->Branch("DstarVtxZ",&Dstar_OWNPV_Z,"DstarVtxZ/D");

  brPVX = newTree->Branch("PVX",&B_OWNPV_X,"PVX/D");
  brPVY = newTree->Branch("PVY",&B_OWNPV_Y,"PVY/D");
  brPVZ = newTree->Branch("PVZ",&B_OWNPV_Z,"PVZ/D");
  brnCandid = newTree->Branch("nCandid",&nCandidate,"nCandid/i");
  //
  /*
  brKpx=newTree->Branch("k_px",&K_PX,"k_px/D");
  brPipx=newTree->Branch("k_py",&K_PY,"k_py/D");
  brPiSpx=newTree->Branch("k_pz",&K_PZ,"k_pz/D");
  
  brKpy=newTree->Branch("pi_px",&Pd_PX,"pi_px/D");
  brPipy=newTree->Branch("pi_py",&Pd_PY,"pi_py/D");
  brPiSpy=newTree->Branch("pi_pz",&Pd_PZ,"pi_pz/D");
  
  brKpz=newTree->Branch("pis_px",&Ps_PX,"pis_px/D");
  brPipz=newTree->Branch("pis_py",&Ps_PY,"pis_py/D");
  brPiSpz=newTree->Branch("pis_pz",&Ps_PZ,"pis_pz/D");
  
  brRunNum = newTree->Branch("RunNumber",&runNumber,"RunNumber/i");
  brEvNum = newTree->Branch("EventNumber",&eventNumber,"EventNumber/l");

  brDTFK_px=newTree->Branch("DTFK_px",&B_VFit_Kplus_PX[0],"DTFK_px/F");
  brDTFK_py=newTree->Branch("DTFK_py",&B_VFit_Kplus_PY[0],"DTFK_py/F");
  brDTFK_pz=newTree->Branch("DTFK_pz",&B_VFit_Kplus_PZ[0],"DTFK_pz/F");
  brDTFPi_px=newTree->Branch("DTFPi_px",&B_VFit_piplus_0_PX[0],"DTFPi_px/F");
  brDTFPi_py=newTree->Branch("DTFPi_py",&B_VFit_piplus_0_PY[0],"DTFPi_py/F");
  brDTFPi_pz=newTree->Branch("DTFPi_pz",&B_VFit_piplus_0_PZ[0],"DTFPi_pz/F");
  brDTFPiS_px=newTree->Branch("DTFPiS_px",&B_VFit_piplus_PX[0],"DTFPiS_px/F");
  brDTFPiS_py=newTree->Branch("DTFPiS_py",&B_VFit_piplus_PY[0],"DTFPiS_py/F");
  brDTFPiS_pz=newTree->Branch("DTFPiS_pz",&B_VFit_piplus_PZ[0],"DTFPiS_pz/F");

  brMu_px=newTree->Branch("Mu_PX",&Mu_PX,"Mu_PX/D");
  brMu_py=newTree->Branch("Mu_PY",&Mu_PY,"Mu_PY/D");
  brMu_pz=newTree->Branch("Mu_PZ",&Mu_PZ,"Mu_PZ/D");
  brDTFMu_px=newTree->Branch("DTFMu_px",&B_VFit_muminus_PX[0],"DTFMu_px/F");
  brDTFMu_py=newTree->Branch("DTFMu_py",&B_VFit_muminus_PY[0],"DTFMu_py/F");
  brDTFMu_pz=newTree->Branch("DTFMu_pz",&B_VFit_muminus_PZ[0],"DTFMu_pz/F");
  */
  brD0P = newTree->Branch("D0P",&D_P,"D0P/D");
  brD0Pt = newTree->Branch("D0Pt",&D_PT,"D0Pt/D");
  brMuIPchi2 = newTree->Branch("MuIPchi2",&Mu_IPCHI2_OWNPV,"MuIPchi2/D");
  brK_PIDK=newTree->Branch("K_PIDK",&K_PIDK,"K_PIDK/D");
  
  brPi_PIDK=newTree->Branch("Pi_PIDK",&Pd_PIDK,"Pi_PIDK/D");
  brnTrk = newTree->Branch("nTracks",&nTracks,"nTracks/I");
  brnpvs = newTree->Branch("nPVs",&nPVs,"nPVs/I");
  br_K_P = newTree->Branch("K_P",&K_P,"K_P/D");
  br_K_eta = newTree->Branch("K_ETA",&newKeta,"K_ETA/D");
  br_K_PT = newTree->Branch("K_PT",&K_PT,"K_PT/D");
  //

}

DT_D0_mix_CPV::~DT_D0_mix_CPV()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t DT_D0_mix_CPV::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t DT_D0_mix_CPV::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (fChain->GetTreeNumber() != fCurrent) {
    fCurrent = fChain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void DT_D0_mix_CPV::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("B_ENDVERTEX_X", &B_ENDVERTEX_X, &b_B_ENDVERTEX_X);
  fChain->SetBranchAddress("B_ENDVERTEX_Y", &B_ENDVERTEX_Y, &b_B_ENDVERTEX_Y);
  fChain->SetBranchAddress("B_ENDVERTEX_Z", &B_ENDVERTEX_Z, &b_B_ENDVERTEX_Z);
  fChain->SetBranchAddress("B_ENDVERTEX_XERR", &B_ENDVERTEX_XERR, &b_B_ENDVERTEX_XERR);
  fChain->SetBranchAddress("B_ENDVERTEX_YERR", &B_ENDVERTEX_YERR, &b_B_ENDVERTEX_YERR);
  fChain->SetBranchAddress("B_ENDVERTEX_ZERR", &B_ENDVERTEX_ZERR, &b_B_ENDVERTEX_ZERR);
  fChain->SetBranchAddress("B_ENDVERTEX_CHI2", &B_ENDVERTEX_CHI2, &b_B_ENDVERTEX_CHI2);
  fChain->SetBranchAddress("B_ENDVERTEX_NDOF", &B_ENDVERTEX_NDOF, &b_B_ENDVERTEX_NDOF);
  fChain->SetBranchAddress("B_ENDVERTEX_COV_", B_ENDVERTEX_COV_, &b_B_ENDVERTEX_COV_);
  fChain->SetBranchAddress("B_OWNPV_X", &B_OWNPV_X, &b_B_OWNPV_X);
  fChain->SetBranchAddress("B_OWNPV_Y", &B_OWNPV_Y, &b_B_OWNPV_Y);
  fChain->SetBranchAddress("B_OWNPV_Z", &B_OWNPV_Z, &b_B_OWNPV_Z);
  fChain->SetBranchAddress("B_OWNPV_XERR", &B_OWNPV_XERR, &b_B_OWNPV_XERR);
  fChain->SetBranchAddress("B_OWNPV_YERR", &B_OWNPV_YERR, &b_B_OWNPV_YERR);
  fChain->SetBranchAddress("B_OWNPV_ZERR", &B_OWNPV_ZERR, &b_B_OWNPV_ZERR);
  fChain->SetBranchAddress("B_OWNPV_CHI2", &B_OWNPV_CHI2, &b_B_OWNPV_CHI2);
  fChain->SetBranchAddress("B_OWNPV_NDOF", &B_OWNPV_NDOF, &b_B_OWNPV_NDOF);
  fChain->SetBranchAddress("B_OWNPV_COV_", B_OWNPV_COV_, &b_B_OWNPV_COV_);
  fChain->SetBranchAddress("B_IP_OWNPV", &B_IP_OWNPV, &b_B_IP_OWNPV);
  fChain->SetBranchAddress("B_IPCHI2_OWNPV", &B_IPCHI2_OWNPV, &b_B_IPCHI2_OWNPV);
  fChain->SetBranchAddress("B_FD_OWNPV", &B_FD_OWNPV, &b_B_FD_OWNPV);
  fChain->SetBranchAddress("B_FDCHI2_OWNPV", &B_FDCHI2_OWNPV, &b_B_FDCHI2_OWNPV);
  fChain->SetBranchAddress("B_DIRA_OWNPV", &B_DIRA_OWNPV, &b_B_DIRA_OWNPV);
  fChain->SetBranchAddress("B_P", &B_P, &b_B_P);
  fChain->SetBranchAddress("B_PT", &B_PT, &b_B_PT);
  fChain->SetBranchAddress("B_PE", &B_PE, &b_B_PE);
  fChain->SetBranchAddress("B_PX", &B_PX, &b_B_PX);
  fChain->SetBranchAddress("B_PY", &B_PY, &b_B_PY);
  fChain->SetBranchAddress("B_PZ", &B_PZ, &b_B_PZ);
  fChain->SetBranchAddress("B_MM", &B_MM, &b_B_MM);
  fChain->SetBranchAddress("B_MMERR", &B_MMERR, &b_B_MMERR);
  fChain->SetBranchAddress("B_M", &B_M, &b_B_M);
  fChain->SetBranchAddress("B_ID", &B_ID, &b_B_ID);
  fChain->SetBranchAddress("B_CORR_M", &B_CORR_M, &b_B_CORR_M);
  fChain->SetBranchAddress("B_VFit_nPV", &B_VFit_nPV, &b_B_VFit_nPV);
  fChain->SetBranchAddress("B_VFit_COV_E_E", B_VFit_COV_E_E, &b_B_VFit_COV_E_E);
  fChain->SetBranchAddress("B_VFit_COV_E_PX", B_VFit_COV_E_PX, &b_B_VFit_COV_E_PX);
  fChain->SetBranchAddress("B_VFit_COV_E_PY", B_VFit_COV_E_PY, &b_B_VFit_COV_E_PY);
  fChain->SetBranchAddress("B_VFit_COV_E_PZ", B_VFit_COV_E_PZ, &b_B_VFit_COV_E_PZ);
  fChain->SetBranchAddress("B_VFit_COV_PX_PX", B_VFit_COV_PX_PX, &b_B_VFit_COV_PX_PX);
  fChain->SetBranchAddress("B_VFit_COV_PX_PY", B_VFit_COV_PX_PY, &b_B_VFit_COV_PX_PY);
  fChain->SetBranchAddress("B_VFit_COV_PX_PZ", B_VFit_COV_PX_PZ, &b_B_VFit_COV_PX_PZ);
  fChain->SetBranchAddress("B_VFit_COV_PY_PY", B_VFit_COV_PY_PY, &b_B_VFit_COV_PY_PY);
  fChain->SetBranchAddress("B_VFit_COV_PY_PZ", B_VFit_COV_PY_PZ, &b_B_VFit_COV_PY_PZ);
  fChain->SetBranchAddress("B_VFit_COV_PZ_PZ", B_VFit_COV_PZ_PZ, &b_B_VFit_COV_PZ_PZ);
  fChain->SetBranchAddress("B_VFit_D0_COV_E_E", B_VFit_D0_COV_E_E, &b_B_VFit_D0_COV_E_E);
  fChain->SetBranchAddress("B_VFit_D0_COV_E_PX", B_VFit_D0_COV_E_PX, &b_B_VFit_D0_COV_E_PX);
  fChain->SetBranchAddress("B_VFit_D0_COV_E_PY", B_VFit_D0_COV_E_PY, &b_B_VFit_D0_COV_E_PY);
  fChain->SetBranchAddress("B_VFit_D0_COV_E_PZ", B_VFit_D0_COV_E_PZ, &b_B_VFit_D0_COV_E_PZ);
  fChain->SetBranchAddress("B_VFit_D0_COV_PX_PX", B_VFit_D0_COV_PX_PX, &b_B_VFit_D0_COV_PX_PX);
  fChain->SetBranchAddress("B_VFit_D0_COV_PX_PY", B_VFit_D0_COV_PX_PY, &b_B_VFit_D0_COV_PX_PY);
  fChain->SetBranchAddress("B_VFit_D0_COV_PX_PZ", B_VFit_D0_COV_PX_PZ, &b_B_VFit_D0_COV_PX_PZ);
  fChain->SetBranchAddress("B_VFit_D0_COV_PY_PY", B_VFit_D0_COV_PY_PY, &b_B_VFit_D0_COV_PY_PY);
  fChain->SetBranchAddress("B_VFit_D0_COV_PY_PZ", B_VFit_D0_COV_PY_PZ, &b_B_VFit_D0_COV_PY_PZ);
  fChain->SetBranchAddress("B_VFit_D0_COV_PZ_PZ", B_VFit_D0_COV_PZ_PZ, &b_B_VFit_D0_COV_PZ_PZ);
  fChain->SetBranchAddress("B_VFit_D0_E", B_VFit_D0_E, &b_B_VFit_D0_E);
  fChain->SetBranchAddress("B_VFit_D0_M", B_VFit_D0_M, &b_B_VFit_D0_M);
  fChain->SetBranchAddress("B_VFit_D0_MERR", B_VFit_D0_MERR, &b_B_VFit_D0_MERR);
  fChain->SetBranchAddress("B_VFit_D0_PX", B_VFit_D0_PX, &b_B_VFit_D0_PX);
  fChain->SetBranchAddress("B_VFit_D0_PY", B_VFit_D0_PY, &b_B_VFit_D0_PY);
  fChain->SetBranchAddress("B_VFit_D0_PZ", B_VFit_D0_PZ, &b_B_VFit_D0_PZ);
  fChain->SetBranchAddress("B_VFit_D0_ctau", B_VFit_D0_ctau, &b_B_VFit_D0_ctau);
  fChain->SetBranchAddress("B_VFit_D0_ctauErr", B_VFit_D0_ctauErr, &b_B_VFit_D0_ctauErr);
  fChain->SetBranchAddress("B_VFit_D0_decayLength", B_VFit_D0_decayLength, &b_B_VFit_D0_decayLength);
  fChain->SetBranchAddress("B_VFit_D0_decayLengthErr", B_VFit_D0_decayLengthErr, &b_B_VFit_D0_decayLengthErr);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_COV_E_E", B_VFit_Dst_2010_plus_COV_E_E, &b_B_VFit_Dst_2010_plus_COV_E_E);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_COV_E_PX", B_VFit_Dst_2010_plus_COV_E_PX, &b_B_VFit_Dst_2010_plus_COV_E_PX);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_COV_E_PY", B_VFit_Dst_2010_plus_COV_E_PY, &b_B_VFit_Dst_2010_plus_COV_E_PY);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_COV_E_PZ", B_VFit_Dst_2010_plus_COV_E_PZ, &b_B_VFit_Dst_2010_plus_COV_E_PZ);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_COV_PX_PX", B_VFit_Dst_2010_plus_COV_PX_PX, &b_B_VFit_Dst_2010_plus_COV_PX_PX);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_COV_PX_PY", B_VFit_Dst_2010_plus_COV_PX_PY, &b_B_VFit_Dst_2010_plus_COV_PX_PY);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_COV_PX_PZ", B_VFit_Dst_2010_plus_COV_PX_PZ, &b_B_VFit_Dst_2010_plus_COV_PX_PZ);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_COV_PY_PY", B_VFit_Dst_2010_plus_COV_PY_PY, &b_B_VFit_Dst_2010_plus_COV_PY_PY);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_COV_PY_PZ", B_VFit_Dst_2010_plus_COV_PY_PZ, &b_B_VFit_Dst_2010_plus_COV_PY_PZ);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_COV_PZ_PZ", B_VFit_Dst_2010_plus_COV_PZ_PZ, &b_B_VFit_Dst_2010_plus_COV_PZ_PZ);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_E", B_VFit_Dst_2010_plus_E, &b_B_VFit_Dst_2010_plus_E);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_M", B_VFit_Dst_2010_plus_M, &b_B_VFit_Dst_2010_plus_M);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_MERR", B_VFit_Dst_2010_plus_MERR, &b_B_VFit_Dst_2010_plus_MERR);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_PX", B_VFit_Dst_2010_plus_PX, &b_B_VFit_Dst_2010_plus_PX);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_PY", B_VFit_Dst_2010_plus_PY, &b_B_VFit_Dst_2010_plus_PY);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_PZ", B_VFit_Dst_2010_plus_PZ, &b_B_VFit_Dst_2010_plus_PZ);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_ctau", B_VFit_Dst_2010_plus_ctau, &b_B_VFit_Dst_2010_plus_ctau);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_ctauErr", B_VFit_Dst_2010_plus_ctauErr, &b_B_VFit_Dst_2010_plus_ctauErr);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_decayLength", B_VFit_Dst_2010_plus_decayLength, 
                           &b_B_VFit_Dst_2010_plus_decayLength);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_decayLengthErr", B_VFit_Dst_2010_plus_decayLengthErr, 
                           &b_B_VFit_Dst_2010_plus_decayLengthErr);
  fChain->SetBranchAddress("B_VFit_E", B_VFit_E, &b_B_VFit_E);
  fChain->SetBranchAddress("B_VFit_Kplus_COV_E_E", B_VFit_Kplus_COV_E_E, &b_B_VFit_Kplus_COV_E_E);
  fChain->SetBranchAddress("B_VFit_Kplus_COV_E_PX", B_VFit_Kplus_COV_E_PX, &b_B_VFit_Kplus_COV_E_PX);
  fChain->SetBranchAddress("B_VFit_Kplus_COV_E_PY", B_VFit_Kplus_COV_E_PY, &b_B_VFit_Kplus_COV_E_PY);
  fChain->SetBranchAddress("B_VFit_Kplus_COV_E_PZ", B_VFit_Kplus_COV_E_PZ, &b_B_VFit_Kplus_COV_E_PZ);
  fChain->SetBranchAddress("B_VFit_Kplus_COV_PX_PX", B_VFit_Kplus_COV_PX_PX, &b_B_VFit_Kplus_COV_PX_PX);
  fChain->SetBranchAddress("B_VFit_Kplus_COV_PX_PY", B_VFit_Kplus_COV_PX_PY, &b_B_VFit_Kplus_COV_PX_PY);
  fChain->SetBranchAddress("B_VFit_Kplus_COV_PX_PZ", B_VFit_Kplus_COV_PX_PZ, &b_B_VFit_Kplus_COV_PX_PZ);
  fChain->SetBranchAddress("B_VFit_Kplus_COV_PY_PY", B_VFit_Kplus_COV_PY_PY, &b_B_VFit_Kplus_COV_PY_PY);
  fChain->SetBranchAddress("B_VFit_Kplus_COV_PY_PZ", B_VFit_Kplus_COV_PY_PZ, &b_B_VFit_Kplus_COV_PY_PZ);
  fChain->SetBranchAddress("B_VFit_Kplus_COV_PZ_PZ", B_VFit_Kplus_COV_PZ_PZ, &b_B_VFit_Kplus_COV_PZ_PZ);
  fChain->SetBranchAddress("B_VFit_Kplus_E", B_VFit_Kplus_E, &b_B_VFit_Kplus_E);
  fChain->SetBranchAddress("B_VFit_Kplus_PX", B_VFit_Kplus_PX, &b_B_VFit_Kplus_PX);
  fChain->SetBranchAddress("B_VFit_Kplus_PY", B_VFit_Kplus_PY, &b_B_VFit_Kplus_PY);
  fChain->SetBranchAddress("B_VFit_Kplus_PZ", B_VFit_Kplus_PZ, &b_B_VFit_Kplus_PZ);
  fChain->SetBranchAddress("B_VFit_M", B_VFit_M, &b_B_VFit_M);
  fChain->SetBranchAddress("B_VFit_MERR", B_VFit_MERR, &b_B_VFit_MERR);
  fChain->SetBranchAddress("B_VFit_PX", B_VFit_PX, &b_B_VFit_PX);
  fChain->SetBranchAddress("B_VFit_PY", B_VFit_PY, &b_B_VFit_PY);
  fChain->SetBranchAddress("B_VFit_PZ", B_VFit_PZ, &b_B_VFit_PZ);
  fChain->SetBranchAddress("B_VFit_chi2", B_VFit_chi2, &b_B_VFit_chi2);
  fChain->SetBranchAddress("B_VFit_muminus_COV_E_E", B_VFit_muminus_COV_E_E, &b_B_VFit_muminus_COV_E_E);
  fChain->SetBranchAddress("B_VFit_muminus_COV_E_PX", B_VFit_muminus_COV_E_PX, &b_B_VFit_muminus_COV_E_PX);
  fChain->SetBranchAddress("B_VFit_muminus_COV_E_PY", B_VFit_muminus_COV_E_PY, &b_B_VFit_muminus_COV_E_PY);
  fChain->SetBranchAddress("B_VFit_muminus_COV_E_PZ", B_VFit_muminus_COV_E_PZ, &b_B_VFit_muminus_COV_E_PZ);
  fChain->SetBranchAddress("B_VFit_muminus_COV_PX_PX", B_VFit_muminus_COV_PX_PX, &b_B_VFit_muminus_COV_PX_PX);
  fChain->SetBranchAddress("B_VFit_muminus_COV_PX_PY", B_VFit_muminus_COV_PX_PY, &b_B_VFit_muminus_COV_PX_PY);
  fChain->SetBranchAddress("B_VFit_muminus_COV_PX_PZ", B_VFit_muminus_COV_PX_PZ, &b_B_VFit_muminus_COV_PX_PZ);
  fChain->SetBranchAddress("B_VFit_muminus_COV_PY_PY", B_VFit_muminus_COV_PY_PY, &b_B_VFit_muminus_COV_PY_PY);
  fChain->SetBranchAddress("B_VFit_muminus_COV_PY_PZ", B_VFit_muminus_COV_PY_PZ, &b_B_VFit_muminus_COV_PY_PZ);
  fChain->SetBranchAddress("B_VFit_muminus_COV_PZ_PZ", B_VFit_muminus_COV_PZ_PZ, &b_B_VFit_muminus_COV_PZ_PZ);
  fChain->SetBranchAddress("B_VFit_muminus_E", B_VFit_muminus_E, &b_B_VFit_muminus_E);
  fChain->SetBranchAddress("B_VFit_muminus_PX", B_VFit_muminus_PX, &b_B_VFit_muminus_PX);
  fChain->SetBranchAddress("B_VFit_muminus_PY", B_VFit_muminus_PY, &b_B_VFit_muminus_PY);
  fChain->SetBranchAddress("B_VFit_muminus_PZ", B_VFit_muminus_PZ, &b_B_VFit_muminus_PZ);
  fChain->SetBranchAddress("B_VFit_nDOF", B_VFit_nDOF, &b_B_VFit_nDOF);
  fChain->SetBranchAddress("B_VFit_nIter", B_VFit_nIter, &b_B_VFit_nIter);
  fChain->SetBranchAddress("B_VFit_piplus_0_COV_E_E", B_VFit_piplus_0_COV_E_E, &b_B_VFit_piplus_0_COV_E_E);
  fChain->SetBranchAddress("B_VFit_piplus_0_COV_E_PX", B_VFit_piplus_0_COV_E_PX, &b_B_VFit_piplus_0_COV_E_PX);
  fChain->SetBranchAddress("B_VFit_piplus_0_COV_E_PY", B_VFit_piplus_0_COV_E_PY, &b_B_VFit_piplus_0_COV_E_PY);
  fChain->SetBranchAddress("B_VFit_piplus_0_COV_E_PZ", B_VFit_piplus_0_COV_E_PZ, &b_B_VFit_piplus_0_COV_E_PZ);
  fChain->SetBranchAddress("B_VFit_piplus_0_COV_PX_PX", B_VFit_piplus_0_COV_PX_PX, &b_B_VFit_piplus_0_COV_PX_PX);
  fChain->SetBranchAddress("B_VFit_piplus_0_COV_PX_PY", B_VFit_piplus_0_COV_PX_PY, &b_B_VFit_piplus_0_COV_PX_PY);
  fChain->SetBranchAddress("B_VFit_piplus_0_COV_PX_PZ", B_VFit_piplus_0_COV_PX_PZ, &b_B_VFit_piplus_0_COV_PX_PZ);
  fChain->SetBranchAddress("B_VFit_piplus_0_COV_PY_PY", B_VFit_piplus_0_COV_PY_PY, &b_B_VFit_piplus_0_COV_PY_PY);
  fChain->SetBranchAddress("B_VFit_piplus_0_COV_PY_PZ", B_VFit_piplus_0_COV_PY_PZ, &b_B_VFit_piplus_0_COV_PY_PZ);
  fChain->SetBranchAddress("B_VFit_piplus_0_COV_PZ_PZ", B_VFit_piplus_0_COV_PZ_PZ, &b_B_VFit_piplus_0_COV_PZ_PZ);
  fChain->SetBranchAddress("B_VFit_piplus_0_E", B_VFit_piplus_0_E, &b_B_VFit_piplus_0_E);
  fChain->SetBranchAddress("B_VFit_piplus_0_PX", B_VFit_piplus_0_PX, &b_B_VFit_piplus_0_PX);
  fChain->SetBranchAddress("B_VFit_piplus_0_PY", B_VFit_piplus_0_PY, &b_B_VFit_piplus_0_PY);
  fChain->SetBranchAddress("B_VFit_piplus_0_PZ", B_VFit_piplus_0_PZ, &b_B_VFit_piplus_0_PZ);
  fChain->SetBranchAddress("B_VFit_piplus_COV_E_E", B_VFit_piplus_COV_E_E, &b_B_VFit_piplus_COV_E_E);
  fChain->SetBranchAddress("B_VFit_piplus_COV_E_PX", B_VFit_piplus_COV_E_PX, &b_B_VFit_piplus_COV_E_PX);
  fChain->SetBranchAddress("B_VFit_piplus_COV_E_PY", B_VFit_piplus_COV_E_PY, &b_B_VFit_piplus_COV_E_PY);
  fChain->SetBranchAddress("B_VFit_piplus_COV_E_PZ", B_VFit_piplus_COV_E_PZ, &b_B_VFit_piplus_COV_E_PZ);
  fChain->SetBranchAddress("B_VFit_piplus_COV_PX_PX", B_VFit_piplus_COV_PX_PX, &b_B_VFit_piplus_COV_PX_PX);
  fChain->SetBranchAddress("B_VFit_piplus_COV_PX_PY", B_VFit_piplus_COV_PX_PY, &b_B_VFit_piplus_COV_PX_PY);
  fChain->SetBranchAddress("B_VFit_piplus_COV_PX_PZ", B_VFit_piplus_COV_PX_PZ, &b_B_VFit_piplus_COV_PX_PZ);
  fChain->SetBranchAddress("B_VFit_piplus_COV_PY_PY", B_VFit_piplus_COV_PY_PY, &b_B_VFit_piplus_COV_PY_PY);
  fChain->SetBranchAddress("B_VFit_piplus_COV_PY_PZ", B_VFit_piplus_COV_PY_PZ, &b_B_VFit_piplus_COV_PY_PZ);
  fChain->SetBranchAddress("B_VFit_piplus_COV_PZ_PZ", B_VFit_piplus_COV_PZ_PZ, &b_B_VFit_piplus_COV_PZ_PZ);
  fChain->SetBranchAddress("B_VFit_piplus_E", B_VFit_piplus_E, &b_B_VFit_piplus_E);
  fChain->SetBranchAddress("B_VFit_piplus_PX", B_VFit_piplus_PX, &b_B_VFit_piplus_PX);
  fChain->SetBranchAddress("B_VFit_piplus_PY", B_VFit_piplus_PY, &b_B_VFit_piplus_PY);
  fChain->SetBranchAddress("B_VFit_piplus_PZ", B_VFit_piplus_PZ, &b_B_VFit_piplus_PZ);
  fChain->SetBranchAddress("B_VFit_status", B_VFit_status, &b_B_VFit_status);
  fChain->SetBranchAddress("B_Nu_Parl", &B_Nu_Parl, &b_B_Nu_Parl);
  fChain->SetBranchAddress("B_Nu_Perp", &B_Nu_Perp, &b_B_Nu_Perp);
  fChain->SetBranchAddress("B_Nu_a", &B_Nu_a, &b_B_Nu_a);
  fChain->SetBranchAddress("B_Nu_X", &B_Nu_X, &b_B_Nu_X);
  fChain->SetBranchAddress("B_Nu_Y", &B_Nu_Y, &b_B_Nu_Y);
  fChain->SetBranchAddress("B_Nu_pb", &B_Nu_pb, &b_B_Nu_pb);
  fChain->SetBranchAddress("B_Nu_pd", &B_Nu_pd, &b_B_Nu_pd);
  fChain->SetBranchAddress("B_Nu_Hi", &B_Nu_Hi, &b_B_Nu_Hi);
  fChain->SetBranchAddress("B_Nu_Lo", &B_Nu_Lo, &b_B_Nu_Lo);
  fChain->SetBranchAddress("B_L0Global_Dec", &B_L0Global_Dec, &b_B_L0Global_Dec);
  fChain->SetBranchAddress("B_L0Global_TIS", &B_L0Global_TIS, &b_B_L0Global_TIS);
  fChain->SetBranchAddress("B_L0Global_TOS", &B_L0Global_TOS, &b_B_L0Global_TOS);
  fChain->SetBranchAddress("B_Hlt1Global_Dec", &B_Hlt1Global_Dec, &b_B_Hlt1Global_Dec);
  fChain->SetBranchAddress("B_Hlt1Global_TIS", &B_Hlt1Global_TIS, &b_B_Hlt1Global_TIS);
  fChain->SetBranchAddress("B_Hlt1Global_TOS", &B_Hlt1Global_TOS, &b_B_Hlt1Global_TOS);
  fChain->SetBranchAddress("B_Hlt1Phys_Dec", &B_Hlt1Phys_Dec, &b_B_Hlt1Phys_Dec);
  fChain->SetBranchAddress("B_Hlt1Phys_TIS", &B_Hlt1Phys_TIS, &b_B_Hlt1Phys_TIS);
  fChain->SetBranchAddress("B_Hlt1Phys_TOS", &B_Hlt1Phys_TOS, &b_B_Hlt1Phys_TOS);
  fChain->SetBranchAddress("B_Hlt2Global_Dec", &B_Hlt2Global_Dec, &b_B_Hlt2Global_Dec);
  fChain->SetBranchAddress("B_Hlt2Global_TIS", &B_Hlt2Global_TIS, &b_B_Hlt2Global_TIS);
  fChain->SetBranchAddress("B_Hlt2Global_TOS", &B_Hlt2Global_TOS, &b_B_Hlt2Global_TOS);
  fChain->SetBranchAddress("B_Hlt2Phys_Dec", &B_Hlt2Phys_Dec, &b_B_Hlt2Phys_Dec);
  fChain->SetBranchAddress("B_Hlt2Phys_TIS", &B_Hlt2Phys_TIS, &b_B_Hlt2Phys_TIS);
  fChain->SetBranchAddress("B_Hlt2Phys_TOS", &B_Hlt2Phys_TOS, &b_B_Hlt2Phys_TOS);
  fChain->SetBranchAddress("B_Hlt2TopoMu4BodyBBDTDecision_Dec", &B_Hlt2TopoMu4BodyBBDTDecision_Dec, 
                           &b_B_Hlt2TopoMu4BodyBBDTDecision_Dec);
  fChain->SetBranchAddress("B_Hlt2TopoMu4BodyBBDTDecision_TIS", &B_Hlt2TopoMu4BodyBBDTDecision_TIS, 
                           &b_B_Hlt2TopoMu4BodyBBDTDecision_TIS);
  fChain->SetBranchAddress("B_Hlt2TopoMu4BodyBBDTDecision_TOS", &B_Hlt2TopoMu4BodyBBDTDecision_TOS, 
                           &b_B_Hlt2TopoMu4BodyBBDTDecision_TOS);
  fChain->SetBranchAddress("B_Hlt2TopoMu3BodyBBDTDecision_Dec", &B_Hlt2TopoMu3BodyBBDTDecision_Dec, 
                           &b_B_Hlt2TopoMu3BodyBBDTDecision_Dec);
  fChain->SetBranchAddress("B_Hlt2TopoMu3BodyBBDTDecision_TIS", &B_Hlt2TopoMu3BodyBBDTDecision_TIS, 
                           &b_B_Hlt2TopoMu3BodyBBDTDecision_TIS);
  fChain->SetBranchAddress("B_Hlt2TopoMu3BodyBBDTDecision_TOS", &B_Hlt2TopoMu3BodyBBDTDecision_TOS, 
                           &b_B_Hlt2TopoMu3BodyBBDTDecision_TOS);
  fChain->SetBranchAddress("B_Hlt2TopoMu2BodyBBDTDecision_Dec", &B_Hlt2TopoMu2BodyBBDTDecision_Dec, 
                           &b_B_Hlt2TopoMu2BodyBBDTDecision_Dec);
  fChain->SetBranchAddress("B_Hlt2TopoMu2BodyBBDTDecision_TIS", &B_Hlt2TopoMu2BodyBBDTDecision_TIS, 
                           &b_B_Hlt2TopoMu2BodyBBDTDecision_TIS);
  fChain->SetBranchAddress("B_Hlt2TopoMu2BodyBBDTDecision_TOS", &B_Hlt2TopoMu2BodyBBDTDecision_TOS, 
                           &b_B_Hlt2TopoMu2BodyBBDTDecision_TOS);
  fChain->SetBranchAddress("Dstar_ENDVERTEX_X", &Dstar_ENDVERTEX_X, &b_Dstar_ENDVERTEX_X);
  fChain->SetBranchAddress("Dstar_ENDVERTEX_Y", &Dstar_ENDVERTEX_Y, &b_Dstar_ENDVERTEX_Y);
  fChain->SetBranchAddress("Dstar_ENDVERTEX_Z", &Dstar_ENDVERTEX_Z, &b_Dstar_ENDVERTEX_Z);
  fChain->SetBranchAddress("Dstar_ENDVERTEX_XERR", &Dstar_ENDVERTEX_XERR, &b_Dstar_ENDVERTEX_XERR);
  fChain->SetBranchAddress("Dstar_ENDVERTEX_YERR", &Dstar_ENDVERTEX_YERR, &b_Dstar_ENDVERTEX_YERR);
  fChain->SetBranchAddress("Dstar_ENDVERTEX_ZERR", &Dstar_ENDVERTEX_ZERR, &b_Dstar_ENDVERTEX_ZERR);
  fChain->SetBranchAddress("Dstar_ENDVERTEX_CHI2", &Dstar_ENDVERTEX_CHI2, &b_Dstar_ENDVERTEX_CHI2);
  fChain->SetBranchAddress("Dstar_ENDVERTEX_NDOF", &Dstar_ENDVERTEX_NDOF, &b_Dstar_ENDVERTEX_NDOF);
  fChain->SetBranchAddress("Dstar_ENDVERTEX_COV_", Dstar_ENDVERTEX_COV_, &b_Dstar_ENDVERTEX_COV_);
  fChain->SetBranchAddress("Dstar_OWNPV_X", &Dstar_OWNPV_X, &b_Dstar_OWNPV_X);
  fChain->SetBranchAddress("Dstar_OWNPV_Y", &Dstar_OWNPV_Y, &b_Dstar_OWNPV_Y);
  fChain->SetBranchAddress("Dstar_OWNPV_Z", &Dstar_OWNPV_Z, &b_Dstar_OWNPV_Z);
  fChain->SetBranchAddress("Dstar_OWNPV_XERR", &Dstar_OWNPV_XERR, &b_Dstar_OWNPV_XERR);
  fChain->SetBranchAddress("Dstar_OWNPV_YERR", &Dstar_OWNPV_YERR, &b_Dstar_OWNPV_YERR);
  fChain->SetBranchAddress("Dstar_OWNPV_ZERR", &Dstar_OWNPV_ZERR, &b_Dstar_OWNPV_ZERR);
  fChain->SetBranchAddress("Dstar_OWNPV_CHI2", &Dstar_OWNPV_CHI2, &b_Dstar_OWNPV_CHI2);
  fChain->SetBranchAddress("Dstar_OWNPV_NDOF", &Dstar_OWNPV_NDOF, &b_Dstar_OWNPV_NDOF);
  fChain->SetBranchAddress("Dstar_OWNPV_COV_", Dstar_OWNPV_COV_, &b_Dstar_OWNPV_COV_);
  fChain->SetBranchAddress("Dstar_IP_OWNPV", &Dstar_IP_OWNPV, &b_Dstar_IP_OWNPV);
  fChain->SetBranchAddress("Dstar_IPCHI2_OWNPV", &Dstar_IPCHI2_OWNPV, &b_Dstar_IPCHI2_OWNPV);
  fChain->SetBranchAddress("Dstar_FD_OWNPV", &Dstar_FD_OWNPV, &b_Dstar_FD_OWNPV);
  fChain->SetBranchAddress("Dstar_FDCHI2_OWNPV", &Dstar_FDCHI2_OWNPV, &b_Dstar_FDCHI2_OWNPV);
  fChain->SetBranchAddress("Dstar_DIRA_OWNPV", &Dstar_DIRA_OWNPV, &b_Dstar_DIRA_OWNPV);
  fChain->SetBranchAddress("Dstar_ORIVX_X", &Dstar_ORIVX_X, &b_Dstar_ORIVX_X);
  fChain->SetBranchAddress("Dstar_ORIVX_Y", &Dstar_ORIVX_Y, &b_Dstar_ORIVX_Y);
  fChain->SetBranchAddress("Dstar_ORIVX_Z", &Dstar_ORIVX_Z, &b_Dstar_ORIVX_Z);
  fChain->SetBranchAddress("Dstar_ORIVX_XERR", &Dstar_ORIVX_XERR, &b_Dstar_ORIVX_XERR);
  fChain->SetBranchAddress("Dstar_ORIVX_YERR", &Dstar_ORIVX_YERR, &b_Dstar_ORIVX_YERR);
  fChain->SetBranchAddress("Dstar_ORIVX_ZERR", &Dstar_ORIVX_ZERR, &b_Dstar_ORIVX_ZERR);
  fChain->SetBranchAddress("Dstar_ORIVX_CHI2", &Dstar_ORIVX_CHI2, &b_Dstar_ORIVX_CHI2);
  fChain->SetBranchAddress("Dstar_ORIVX_NDOF", &Dstar_ORIVX_NDOF, &b_Dstar_ORIVX_NDOF);
  fChain->SetBranchAddress("Dstar_ORIVX_COV_", Dstar_ORIVX_COV_, &b_Dstar_ORIVX_COV_);
  fChain->SetBranchAddress("Dstar_FD_ORIVX", &Dstar_FD_ORIVX, &b_Dstar_FD_ORIVX);
  fChain->SetBranchAddress("Dstar_FDCHI2_ORIVX", &Dstar_FDCHI2_ORIVX, &b_Dstar_FDCHI2_ORIVX);
  fChain->SetBranchAddress("Dstar_DIRA_ORIVX", &Dstar_DIRA_ORIVX, &b_Dstar_DIRA_ORIVX);
  fChain->SetBranchAddress("Dstar_P", &Dstar_P, &b_Dstar_P);
  fChain->SetBranchAddress("Dstar_PT", &Dstar_PT, &b_Dstar_PT);
  fChain->SetBranchAddress("Dstar_PE", &Dstar_PE, &b_Dstar_PE);
  fChain->SetBranchAddress("Dstar_PX", &Dstar_PX, &b_Dstar_PX);
  fChain->SetBranchAddress("Dstar_PY", &Dstar_PY, &b_Dstar_PY);
  fChain->SetBranchAddress("Dstar_PZ", &Dstar_PZ, &b_Dstar_PZ);
  fChain->SetBranchAddress("Dstar_MM", &Dstar_MM, &b_Dstar_MM);
  fChain->SetBranchAddress("Dstar_MMERR", &Dstar_MMERR, &b_Dstar_MMERR);
  fChain->SetBranchAddress("Dstar_M", &Dstar_M, &b_Dstar_M);
  fChain->SetBranchAddress("Dstar_ID", &Dstar_ID, &b_Dstar_ID);
  /*  fChain->SetBranchAddress("Dstar_DstFit_nPV", &Dstar_DstFit_nPV, &b_Dstar_DstFit_nPV);
  fChain->SetBranchAddress("Dstar_DstFit_COV_E_E", Dstar_DstFit_COV_E_E, &b_Dstar_DstFit_COV_E_E);
  fChain->SetBranchAddress("Dstar_DstFit_COV_E_PX", Dstar_DstFit_COV_E_PX, &b_Dstar_DstFit_COV_E_PX);
  fChain->SetBranchAddress("Dstar_DstFit_COV_E_PY", Dstar_DstFit_COV_E_PY, &b_Dstar_DstFit_COV_E_PY);
  fChain->SetBranchAddress("Dstar_DstFit_COV_E_PZ", Dstar_DstFit_COV_E_PZ, &b_Dstar_DstFit_COV_E_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_COV_PX_PX", Dstar_DstFit_COV_PX_PX, &b_Dstar_DstFit_COV_PX_PX);
  fChain->SetBranchAddress("Dstar_DstFit_COV_PX_PY", Dstar_DstFit_COV_PX_PY, &b_Dstar_DstFit_COV_PX_PY);
  fChain->SetBranchAddress("Dstar_DstFit_COV_PX_PZ", Dstar_DstFit_COV_PX_PZ, &b_Dstar_DstFit_COV_PX_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_COV_PY_PY", Dstar_DstFit_COV_PY_PY, &b_Dstar_DstFit_COV_PY_PY);
  fChain->SetBranchAddress("Dstar_DstFit_COV_PY_PZ", Dstar_DstFit_COV_PY_PZ, &b_Dstar_DstFit_COV_PY_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_COV_PZ_PZ", Dstar_DstFit_COV_PZ_PZ, &b_Dstar_DstFit_COV_PZ_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_D0_COV_E_E", Dstar_DstFit_D0_COV_E_E, &b_Dstar_DstFit_D0_COV_E_E);
  fChain->SetBranchAddress("Dstar_DstFit_D0_COV_E_PX", Dstar_DstFit_D0_COV_E_PX, &b_Dstar_DstFit_D0_COV_E_PX);
  fChain->SetBranchAddress("Dstar_DstFit_D0_COV_E_PY", Dstar_DstFit_D0_COV_E_PY, &b_Dstar_DstFit_D0_COV_E_PY);
  fChain->SetBranchAddress("Dstar_DstFit_D0_COV_E_PZ", Dstar_DstFit_D0_COV_E_PZ, &b_Dstar_DstFit_D0_COV_E_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_D0_COV_PX_PX", Dstar_DstFit_D0_COV_PX_PX, &b_Dstar_DstFit_D0_COV_PX_PX);
  fChain->SetBranchAddress("Dstar_DstFit_D0_COV_PX_PY", Dstar_DstFit_D0_COV_PX_PY, &b_Dstar_DstFit_D0_COV_PX_PY);
  fChain->SetBranchAddress("Dstar_DstFit_D0_COV_PX_PZ", Dstar_DstFit_D0_COV_PX_PZ, &b_Dstar_DstFit_D0_COV_PX_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_D0_COV_PY_PY", Dstar_DstFit_D0_COV_PY_PY, &b_Dstar_DstFit_D0_COV_PY_PY);
  fChain->SetBranchAddress("Dstar_DstFit_D0_COV_PY_PZ", Dstar_DstFit_D0_COV_PY_PZ, &b_Dstar_DstFit_D0_COV_PY_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_D0_COV_PZ_PZ", Dstar_DstFit_D0_COV_PZ_PZ, &b_Dstar_DstFit_D0_COV_PZ_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_D0_E", Dstar_DstFit_D0_E, &b_Dstar_DstFit_D0_E);
  fChain->SetBranchAddress("Dstar_DstFit_D0_M", Dstar_DstFit_D0_M, &b_Dstar_DstFit_D0_M);
  fChain->SetBranchAddress("Dstar_DstFit_D0_MERR", Dstar_DstFit_D0_MERR, &b_Dstar_DstFit_D0_MERR);
  fChain->SetBranchAddress("Dstar_DstFit_D0_PX", Dstar_DstFit_D0_PX, &b_Dstar_DstFit_D0_PX);
  fChain->SetBranchAddress("Dstar_DstFit_D0_PY", Dstar_DstFit_D0_PY, &b_Dstar_DstFit_D0_PY);
  fChain->SetBranchAddress("Dstar_DstFit_D0_PZ", Dstar_DstFit_D0_PZ, &b_Dstar_DstFit_D0_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_D0_ctau", Dstar_DstFit_D0_ctau, &b_Dstar_DstFit_D0_ctau);
  fChain->SetBranchAddress("Dstar_DstFit_D0_ctauErr", Dstar_DstFit_D0_ctauErr, &b_Dstar_DstFit_D0_ctauErr);
  fChain->SetBranchAddress("Dstar_DstFit_D0_decayLength", Dstar_DstFit_D0_decayLength, &b_Dstar_DstFit_D0_decayLength);
  fChain->SetBranchAddress("Dstar_DstFit_D0_decayLengthErr", Dstar_DstFit_D0_decayLengthErr, &b_Dstar_DstFit_D0_decayLengthErr);
  fChain->SetBranchAddress("Dstar_DstFit_E", Dstar_DstFit_E, &b_Dstar_DstFit_E);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_COV_E_E", Dstar_DstFit_Kplus_COV_E_E, &b_Dstar_DstFit_Kplus_COV_E_E);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_COV_E_PX", Dstar_DstFit_Kplus_COV_E_PX, &b_Dstar_DstFit_Kplus_COV_E_PX);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_COV_E_PY", Dstar_DstFit_Kplus_COV_E_PY, &b_Dstar_DstFit_Kplus_COV_E_PY);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_COV_E_PZ", Dstar_DstFit_Kplus_COV_E_PZ, &b_Dstar_DstFit_Kplus_COV_E_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_COV_PX_PX", Dstar_DstFit_Kplus_COV_PX_PX, &b_Dstar_DstFit_Kplus_COV_PX_PX);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_COV_PX_PY", Dstar_DstFit_Kplus_COV_PX_PY, &b_Dstar_DstFit_Kplus_COV_PX_PY);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_COV_PX_PZ", Dstar_DstFit_Kplus_COV_PX_PZ, &b_Dstar_DstFit_Kplus_COV_PX_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_COV_PY_PY", Dstar_DstFit_Kplus_COV_PY_PY, &b_Dstar_DstFit_Kplus_COV_PY_PY);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_COV_PY_PZ", Dstar_DstFit_Kplus_COV_PY_PZ, &b_Dstar_DstFit_Kplus_COV_PY_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_COV_PZ_PZ", Dstar_DstFit_Kplus_COV_PZ_PZ, &b_Dstar_DstFit_Kplus_COV_PZ_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_E", Dstar_DstFit_Kplus_E, &b_Dstar_DstFit_Kplus_E);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_PX", Dstar_DstFit_Kplus_PX, &b_Dstar_DstFit_Kplus_PX);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_PY", Dstar_DstFit_Kplus_PY, &b_Dstar_DstFit_Kplus_PY);
  fChain->SetBranchAddress("Dstar_DstFit_Kplus_PZ", Dstar_DstFit_Kplus_PZ, &b_Dstar_DstFit_Kplus_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_M", Dstar_DstFit_M, &b_Dstar_DstFit_M);
  fChain->SetBranchAddress("Dstar_DstFit_MERR", Dstar_DstFit_MERR, &b_Dstar_DstFit_MERR);
  fChain->SetBranchAddress("Dstar_DstFit_PX", Dstar_DstFit_PX, &b_Dstar_DstFit_PX);
  fChain->SetBranchAddress("Dstar_DstFit_PY", Dstar_DstFit_PY, &b_Dstar_DstFit_PY);
  fChain->SetBranchAddress("Dstar_DstFit_PZ", Dstar_DstFit_PZ, &b_Dstar_DstFit_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_chi2", Dstar_DstFit_chi2, &b_Dstar_DstFit_chi2);
  fChain->SetBranchAddress("Dstar_DstFit_nDOF", Dstar_DstFit_nDOF, &b_Dstar_DstFit_nDOF);
  fChain->SetBranchAddress("Dstar_DstFit_nIter", Dstar_DstFit_nIter, &b_Dstar_DstFit_nIter);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_COV_E_E", Dstar_DstFit_piplus_0_COV_E_E, &b_Dstar_DstFit_piplus_0_COV_E_E);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_COV_E_PX", Dstar_DstFit_piplus_0_COV_E_PX, &b_Dstar_DstFit_piplus_0_COV_E_PX);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_COV_E_PY", Dstar_DstFit_piplus_0_COV_E_PY, &b_Dstar_DstFit_piplus_0_COV_E_PY);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_COV_E_PZ", Dstar_DstFit_piplus_0_COV_E_PZ, &b_Dstar_DstFit_piplus_0_COV_E_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_COV_PX_PX", Dstar_DstFit_piplus_0_COV_PX_PX, 
                           &b_Dstar_DstFit_piplus_0_COV_PX_PX);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_COV_PX_PY", Dstar_DstFit_piplus_0_COV_PX_PY, 
                           &b_Dstar_DstFit_piplus_0_COV_PX_PY);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_COV_PX_PZ", Dstar_DstFit_piplus_0_COV_PX_PZ, 
                           &b_Dstar_DstFit_piplus_0_COV_PX_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_COV_PY_PY", Dstar_DstFit_piplus_0_COV_PY_PY, 
                           &b_Dstar_DstFit_piplus_0_COV_PY_PY);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_COV_PY_PZ", Dstar_DstFit_piplus_0_COV_PY_PZ, 
                           &b_Dstar_DstFit_piplus_0_COV_PY_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_COV_PZ_PZ", Dstar_DstFit_piplus_0_COV_PZ_PZ, 
                           &b_Dstar_DstFit_piplus_0_COV_PZ_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_E", Dstar_DstFit_piplus_0_E, &b_Dstar_DstFit_piplus_0_E);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_PX", Dstar_DstFit_piplus_0_PX, &b_Dstar_DstFit_piplus_0_PX);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_PY", Dstar_DstFit_piplus_0_PY, &b_Dstar_DstFit_piplus_0_PY);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_0_PZ", Dstar_DstFit_piplus_0_PZ, &b_Dstar_DstFit_piplus_0_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_COV_E_E", Dstar_DstFit_piplus_COV_E_E, &b_Dstar_DstFit_piplus_COV_E_E);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_COV_E_PX", Dstar_DstFit_piplus_COV_E_PX, &b_Dstar_DstFit_piplus_COV_E_PX);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_COV_E_PY", Dstar_DstFit_piplus_COV_E_PY, &b_Dstar_DstFit_piplus_COV_E_PY);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_COV_E_PZ", Dstar_DstFit_piplus_COV_E_PZ, &b_Dstar_DstFit_piplus_COV_E_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_COV_PX_PX", Dstar_DstFit_piplus_COV_PX_PX, &b_Dstar_DstFit_piplus_COV_PX_PX);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_COV_PX_PY", Dstar_DstFit_piplus_COV_PX_PY, &b_Dstar_DstFit_piplus_COV_PX_PY);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_COV_PX_PZ", Dstar_DstFit_piplus_COV_PX_PZ, &b_Dstar_DstFit_piplus_COV_PX_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_COV_PY_PY", Dstar_DstFit_piplus_COV_PY_PY, &b_Dstar_DstFit_piplus_COV_PY_PY);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_COV_PY_PZ", Dstar_DstFit_piplus_COV_PY_PZ, &b_Dstar_DstFit_piplus_COV_PY_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_COV_PZ_PZ", Dstar_DstFit_piplus_COV_PZ_PZ, &b_Dstar_DstFit_piplus_COV_PZ_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_E", Dstar_DstFit_piplus_E, &b_Dstar_DstFit_piplus_E);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_PX", Dstar_DstFit_piplus_PX, &b_Dstar_DstFit_piplus_PX);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_PY", Dstar_DstFit_piplus_PY, &b_Dstar_DstFit_piplus_PY);
  fChain->SetBranchAddress("Dstar_DstFit_piplus_PZ", Dstar_DstFit_piplus_PZ, &b_Dstar_DstFit_piplus_PZ);
  fChain->SetBranchAddress("Dstar_DstFit_status", Dstar_DstFit_status, &b_Dstar_DstFit_status);*/
  fChain->SetBranchAddress("Dstar_L0Global_Dec", &Dstar_L0Global_Dec, &b_Dstar_L0Global_Dec);
  fChain->SetBranchAddress("Dstar_L0Global_TIS", &Dstar_L0Global_TIS, &b_Dstar_L0Global_TIS);
  fChain->SetBranchAddress("Dstar_L0Global_TOS", &Dstar_L0Global_TOS, &b_Dstar_L0Global_TOS);
  fChain->SetBranchAddress("Dstar_Hlt1Global_Dec", &Dstar_Hlt1Global_Dec, &b_Dstar_Hlt1Global_Dec);
  fChain->SetBranchAddress("Dstar_Hlt1Global_TIS", &Dstar_Hlt1Global_TIS, &b_Dstar_Hlt1Global_TIS);
  fChain->SetBranchAddress("Dstar_Hlt1Global_TOS", &Dstar_Hlt1Global_TOS, &b_Dstar_Hlt1Global_TOS);
  fChain->SetBranchAddress("Dstar_Hlt1Phys_Dec", &Dstar_Hlt1Phys_Dec, &b_Dstar_Hlt1Phys_Dec);
  fChain->SetBranchAddress("Dstar_Hlt1Phys_TIS", &Dstar_Hlt1Phys_TIS, &b_Dstar_Hlt1Phys_TIS);
  fChain->SetBranchAddress("Dstar_Hlt1Phys_TOS", &Dstar_Hlt1Phys_TOS, &b_Dstar_Hlt1Phys_TOS);
  fChain->SetBranchAddress("Dstar_Hlt2Global_Dec", &Dstar_Hlt2Global_Dec, &b_Dstar_Hlt2Global_Dec);
  fChain->SetBranchAddress("Dstar_Hlt2Global_TIS", &Dstar_Hlt2Global_TIS, &b_Dstar_Hlt2Global_TIS);
  fChain->SetBranchAddress("Dstar_Hlt2Global_TOS", &Dstar_Hlt2Global_TOS, &b_Dstar_Hlt2Global_TOS);
  fChain->SetBranchAddress("Dstar_Hlt2Phys_Dec", &Dstar_Hlt2Phys_Dec, &b_Dstar_Hlt2Phys_Dec);
  fChain->SetBranchAddress("Dstar_Hlt2Phys_TIS", &Dstar_Hlt2Phys_TIS, &b_Dstar_Hlt2Phys_TIS);
  fChain->SetBranchAddress("Dstar_Hlt2Phys_TOS", &Dstar_Hlt2Phys_TOS, &b_Dstar_Hlt2Phys_TOS);
  fChain->SetBranchAddress("Dstar_Hlt1TrackAllL0Decision_Dec", &Dstar_Hlt1TrackAllL0Decision_Dec, 
                           &b_Dstar_Hlt1TrackAllL0Decision_Dec);
  fChain->SetBranchAddress("Dstar_Hlt1TrackAllL0Decision_TIS", &Dstar_Hlt1TrackAllL0Decision_TIS, 
                           &b_Dstar_Hlt1TrackAllL0Decision_TIS);
  fChain->SetBranchAddress("Dstar_Hlt1TrackAllL0Decision_TOS", &Dstar_Hlt1TrackAllL0Decision_TOS, 
                           &b_Dstar_Hlt1TrackAllL0Decision_TOS);
  fChain->SetBranchAddress("D_ENDVERTEX_X", &D_ENDVERTEX_X, &b_D_ENDVERTEX_X);
  fChain->SetBranchAddress("D_ENDVERTEX_Y", &D_ENDVERTEX_Y, &b_D_ENDVERTEX_Y);
  fChain->SetBranchAddress("D_ENDVERTEX_Z", &D_ENDVERTEX_Z, &b_D_ENDVERTEX_Z);
  fChain->SetBranchAddress("D_ENDVERTEX_XERR", &D_ENDVERTEX_XERR, &b_D_ENDVERTEX_XERR);
  fChain->SetBranchAddress("D_ENDVERTEX_YERR", &D_ENDVERTEX_YERR, &b_D_ENDVERTEX_YERR);
  fChain->SetBranchAddress("D_ENDVERTEX_ZERR", &D_ENDVERTEX_ZERR, &b_D_ENDVERTEX_ZERR);
  fChain->SetBranchAddress("D_ENDVERTEX_CHI2", &D_ENDVERTEX_CHI2, &b_D_ENDVERTEX_CHI2);
  fChain->SetBranchAddress("D_ENDVERTEX_NDOF", &D_ENDVERTEX_NDOF, &b_D_ENDVERTEX_NDOF);
  fChain->SetBranchAddress("D_ENDVERTEX_COV_", D_ENDVERTEX_COV_, &b_D_ENDVERTEX_COV_);
  fChain->SetBranchAddress("D_OWNPV_X", &D_OWNPV_X, &b_D_OWNPV_X);
  fChain->SetBranchAddress("D_OWNPV_Y", &D_OWNPV_Y, &b_D_OWNPV_Y);
  fChain->SetBranchAddress("D_OWNPV_Z", &D_OWNPV_Z, &b_D_OWNPV_Z);
  fChain->SetBranchAddress("D_OWNPV_XERR", &D_OWNPV_XERR, &b_D_OWNPV_XERR);
  fChain->SetBranchAddress("D_OWNPV_YERR", &D_OWNPV_YERR, &b_D_OWNPV_YERR);
  fChain->SetBranchAddress("D_OWNPV_ZERR", &D_OWNPV_ZERR, &b_D_OWNPV_ZERR);
  fChain->SetBranchAddress("D_OWNPV_CHI2", &D_OWNPV_CHI2, &b_D_OWNPV_CHI2);
  fChain->SetBranchAddress("D_OWNPV_NDOF", &D_OWNPV_NDOF, &b_D_OWNPV_NDOF);
  fChain->SetBranchAddress("D_OWNPV_COV_", D_OWNPV_COV_, &b_D_OWNPV_COV_);
  fChain->SetBranchAddress("D_IP_OWNPV", &D_IP_OWNPV, &b_D_IP_OWNPV);
  fChain->SetBranchAddress("D_IPCHI2_OWNPV", &D_IPCHI2_OWNPV, &b_D_IPCHI2_OWNPV);
  fChain->SetBranchAddress("D_FD_OWNPV", &D_FD_OWNPV, &b_D_FD_OWNPV);
  fChain->SetBranchAddress("D_FDCHI2_OWNPV", &D_FDCHI2_OWNPV, &b_D_FDCHI2_OWNPV);
  fChain->SetBranchAddress("D_DIRA_OWNPV", &D_DIRA_OWNPV, &b_D_DIRA_OWNPV);
  fChain->SetBranchAddress("D_ORIVX_X", &D_ORIVX_X, &b_D_ORIVX_X);
  fChain->SetBranchAddress("D_ORIVX_Y", &D_ORIVX_Y, &b_D_ORIVX_Y);
  fChain->SetBranchAddress("D_ORIVX_Z", &D_ORIVX_Z, &b_D_ORIVX_Z);
  fChain->SetBranchAddress("D_ORIVX_XERR", &D_ORIVX_XERR, &b_D_ORIVX_XERR);
  fChain->SetBranchAddress("D_ORIVX_YERR", &D_ORIVX_YERR, &b_D_ORIVX_YERR);
  fChain->SetBranchAddress("D_ORIVX_ZERR", &D_ORIVX_ZERR, &b_D_ORIVX_ZERR);
  fChain->SetBranchAddress("D_ORIVX_CHI2", &D_ORIVX_CHI2, &b_D_ORIVX_CHI2);
  fChain->SetBranchAddress("D_ORIVX_NDOF", &D_ORIVX_NDOF, &b_D_ORIVX_NDOF);
  fChain->SetBranchAddress("D_ORIVX_COV_", D_ORIVX_COV_, &b_D_ORIVX_COV_);
  fChain->SetBranchAddress("D_FD_ORIVX", &D_FD_ORIVX, &b_D_FD_ORIVX);
  fChain->SetBranchAddress("D_FDCHI2_ORIVX", &D_FDCHI2_ORIVX, &b_D_FDCHI2_ORIVX);
  fChain->SetBranchAddress("D_DIRA_ORIVX", &D_DIRA_ORIVX, &b_D_DIRA_ORIVX);
  fChain->SetBranchAddress("D_P", &D_P, &b_D_P);
  fChain->SetBranchAddress("D_PT", &D_PT, &b_D_PT);
  fChain->SetBranchAddress("D_PE", &D_PE, &b_D_PE);
  fChain->SetBranchAddress("D_PX", &D_PX, &b_D_PX);
  fChain->SetBranchAddress("D_PY", &D_PY, &b_D_PY);
  fChain->SetBranchAddress("D_PZ", &D_PZ, &b_D_PZ);
  fChain->SetBranchAddress("D_MM", &D_MM, &b_D_MM);
  fChain->SetBranchAddress("D_MMERR", &D_MMERR, &b_D_MMERR);
  fChain->SetBranchAddress("D_M", &D_M, &b_D_M);
  fChain->SetBranchAddress("D_ID", &D_ID, &b_D_ID);
  fChain->SetBranchAddress("K_MC12TuneV2_ProbNNe", &K_MC12TuneV2_ProbNNe, &b_K_MC12TuneV2_ProbNNe);
  fChain->SetBranchAddress("K_MC12TuneV2_ProbNNmu", &K_MC12TuneV2_ProbNNmu, &b_K_MC12TuneV2_ProbNNmu);
  fChain->SetBranchAddress("K_MC12TuneV2_ProbNNpi", &K_MC12TuneV2_ProbNNpi, &b_K_MC12TuneV2_ProbNNpi);
  fChain->SetBranchAddress("K_MC12TuneV2_ProbNNk", &K_MC12TuneV2_ProbNNk, &b_K_MC12TuneV2_ProbNNk);
  fChain->SetBranchAddress("K_MC12TuneV2_ProbNNp", &K_MC12TuneV2_ProbNNp, &b_K_MC12TuneV2_ProbNNp);
  fChain->SetBranchAddress("K_MC12TuneV2_ProbNNghost", &K_MC12TuneV2_ProbNNghost, &b_K_MC12TuneV2_ProbNNghost);
  fChain->SetBranchAddress("K_MC12TuneV3_ProbNNe", &K_MC12TuneV3_ProbNNe, &b_K_MC12TuneV3_ProbNNe);
  fChain->SetBranchAddress("K_MC12TuneV3_ProbNNmu", &K_MC12TuneV3_ProbNNmu, &b_K_MC12TuneV3_ProbNNmu);
  fChain->SetBranchAddress("K_MC12TuneV3_ProbNNpi", &K_MC12TuneV3_ProbNNpi, &b_K_MC12TuneV3_ProbNNpi);
  fChain->SetBranchAddress("K_MC12TuneV3_ProbNNk", &K_MC12TuneV3_ProbNNk, &b_K_MC12TuneV3_ProbNNk);
  fChain->SetBranchAddress("K_MC12TuneV3_ProbNNp", &K_MC12TuneV3_ProbNNp, &b_K_MC12TuneV3_ProbNNp);
  fChain->SetBranchAddress("K_MC12TuneV3_ProbNNghost", &K_MC12TuneV3_ProbNNghost, &b_K_MC12TuneV3_ProbNNghost);
  fChain->SetBranchAddress("K_OWNPV_X", &K_OWNPV_X, &b_K_OWNPV_X);
  fChain->SetBranchAddress("K_OWNPV_Y", &K_OWNPV_Y, &b_K_OWNPV_Y);
  fChain->SetBranchAddress("K_OWNPV_Z", &K_OWNPV_Z, &b_K_OWNPV_Z);
  fChain->SetBranchAddress("K_OWNPV_XERR", &K_OWNPV_XERR, &b_K_OWNPV_XERR);
  fChain->SetBranchAddress("K_OWNPV_YERR", &K_OWNPV_YERR, &b_K_OWNPV_YERR);
  fChain->SetBranchAddress("K_OWNPV_ZERR", &K_OWNPV_ZERR, &b_K_OWNPV_ZERR);
  fChain->SetBranchAddress("K_OWNPV_CHI2", &K_OWNPV_CHI2, &b_K_OWNPV_CHI2);
  fChain->SetBranchAddress("K_OWNPV_NDOF", &K_OWNPV_NDOF, &b_K_OWNPV_NDOF);
  fChain->SetBranchAddress("K_OWNPV_COV_", K_OWNPV_COV_, &b_K_OWNPV_COV_);
  fChain->SetBranchAddress("K_IP_OWNPV", &K_IP_OWNPV, &b_K_IP_OWNPV);
  fChain->SetBranchAddress("K_IPCHI2_OWNPV", &K_IPCHI2_OWNPV, &b_K_IPCHI2_OWNPV);
  fChain->SetBranchAddress("K_ORIVX_X", &K_ORIVX_X, &b_K_ORIVX_X);
  fChain->SetBranchAddress("K_ORIVX_Y", &K_ORIVX_Y, &b_K_ORIVX_Y);
  fChain->SetBranchAddress("K_ORIVX_Z", &K_ORIVX_Z, &b_K_ORIVX_Z);
  fChain->SetBranchAddress("K_ORIVX_XERR", &K_ORIVX_XERR, &b_K_ORIVX_XERR);
  fChain->SetBranchAddress("K_ORIVX_YERR", &K_ORIVX_YERR, &b_K_ORIVX_YERR);
  fChain->SetBranchAddress("K_ORIVX_ZERR", &K_ORIVX_ZERR, &b_K_ORIVX_ZERR);
  fChain->SetBranchAddress("K_ORIVX_CHI2", &K_ORIVX_CHI2, &b_K_ORIVX_CHI2);
  fChain->SetBranchAddress("K_ORIVX_NDOF", &K_ORIVX_NDOF, &b_K_ORIVX_NDOF);
  fChain->SetBranchAddress("K_ORIVX_COV_", K_ORIVX_COV_, &b_K_ORIVX_COV_);
  fChain->SetBranchAddress("K_P", &K_P, &b_K_P);
  fChain->SetBranchAddress("K_PT", &K_PT, &b_K_PT);
  fChain->SetBranchAddress("K_PE", &K_PE, &b_K_PE);
  fChain->SetBranchAddress("K_PX", &K_PX, &b_K_PX);
  fChain->SetBranchAddress("K_PY", &K_PY, &b_K_PY);
  fChain->SetBranchAddress("K_PZ", &K_PZ, &b_K_PZ);
  fChain->SetBranchAddress("K_M", &K_M, &b_K_M);
  fChain->SetBranchAddress("K_ID", &K_ID, &b_K_ID);
  fChain->SetBranchAddress("K_PIDe", &K_PIDe, &b_K_PIDe);
  fChain->SetBranchAddress("K_PIDmu", &K_PIDmu, &b_K_PIDmu);
  fChain->SetBranchAddress("K_PIDK", &K_PIDK, &b_K_PIDK);
  fChain->SetBranchAddress("K_PIDp", &K_PIDp, &b_K_PIDp);
  fChain->SetBranchAddress("K_ProbNNe", &K_ProbNNe, &b_K_ProbNNe);
  fChain->SetBranchAddress("K_ProbNNk", &K_ProbNNk, &b_K_ProbNNk);
  fChain->SetBranchAddress("K_ProbNNp", &K_ProbNNp, &b_K_ProbNNp);
  fChain->SetBranchAddress("K_ProbNNpi", &K_ProbNNpi, &b_K_ProbNNpi);
  fChain->SetBranchAddress("K_ProbNNmu", &K_ProbNNmu, &b_K_ProbNNmu);
  fChain->SetBranchAddress("K_ProbNNghost", &K_ProbNNghost, &b_K_ProbNNghost);
  fChain->SetBranchAddress("K_hasMuon", &K_hasMuon, &b_K_hasMuon);
  fChain->SetBranchAddress("K_isMuon", &K_isMuon, &b_K_isMuon);
  fChain->SetBranchAddress("K_hasRich", &K_hasRich, &b_K_hasRich);
  fChain->SetBranchAddress("K_hasCalo", &K_hasCalo, &b_K_hasCalo);
  fChain->SetBranchAddress("K_TRACK_Type", &K_TRACK_Type, &b_K_TRACK_Type);
  fChain->SetBranchAddress("K_TRACK_Key", &K_TRACK_Key, &b_K_TRACK_Key);
  fChain->SetBranchAddress("K_TRACK_CHI2NDOF", &K_TRACK_CHI2NDOF, &b_K_TRACK_CHI2NDOF);
  fChain->SetBranchAddress("K_TRACK_PCHI2", &K_TRACK_PCHI2, &b_K_TRACK_PCHI2);
  fChain->SetBranchAddress("K_TRACK_MatchCHI2", &K_TRACK_MatchCHI2, &b_K_TRACK_MatchCHI2);
  fChain->SetBranchAddress("K_TRACK_GhostProb", &K_TRACK_GhostProb, &b_K_TRACK_GhostProb);
  fChain->SetBranchAddress("K_TRACK_CloneDist", &K_TRACK_CloneDist, &b_K_TRACK_CloneDist);
  fChain->SetBranchAddress("K_TRACK_Likelihood", &K_TRACK_Likelihood, &b_K_TRACK_Likelihood);
  fChain->SetBranchAddress("Pd_MC12TuneV2_ProbNNe", &Pd_MC12TuneV2_ProbNNe, &b_Pd_MC12TuneV2_ProbNNe);
  fChain->SetBranchAddress("Pd_MC12TuneV2_ProbNNmu", &Pd_MC12TuneV2_ProbNNmu, &b_Pd_MC12TuneV2_ProbNNmu);
  fChain->SetBranchAddress("Pd_MC12TuneV2_ProbNNpi", &Pd_MC12TuneV2_ProbNNpi, &b_Pd_MC12TuneV2_ProbNNpi);
  fChain->SetBranchAddress("Pd_MC12TuneV2_ProbNNk", &Pd_MC12TuneV2_ProbNNk, &b_Pd_MC12TuneV2_ProbNNk);
  fChain->SetBranchAddress("Pd_MC12TuneV2_ProbNNp", &Pd_MC12TuneV2_ProbNNp, &b_Pd_MC12TuneV2_ProbNNp);
  fChain->SetBranchAddress("Pd_MC12TuneV2_ProbNNghost", &Pd_MC12TuneV2_ProbNNghost, &b_Pd_MC12TuneV2_ProbNNghost);
  fChain->SetBranchAddress("Pd_MC12TuneV3_ProbNNe", &Pd_MC12TuneV3_ProbNNe, &b_Pd_MC12TuneV3_ProbNNe);
  fChain->SetBranchAddress("Pd_MC12TuneV3_ProbNNmu", &Pd_MC12TuneV3_ProbNNmu, &b_Pd_MC12TuneV3_ProbNNmu);
  fChain->SetBranchAddress("Pd_MC12TuneV3_ProbNNpi", &Pd_MC12TuneV3_ProbNNpi, &b_Pd_MC12TuneV3_ProbNNpi);
  fChain->SetBranchAddress("Pd_MC12TuneV3_ProbNNk", &Pd_MC12TuneV3_ProbNNk, &b_Pd_MC12TuneV3_ProbNNk);
  fChain->SetBranchAddress("Pd_MC12TuneV3_ProbNNp", &Pd_MC12TuneV3_ProbNNp, &b_Pd_MC12TuneV3_ProbNNp);
  fChain->SetBranchAddress("Pd_MC12TuneV3_ProbNNghost", &Pd_MC12TuneV3_ProbNNghost, &b_Pd_MC12TuneV3_ProbNNghost);
  fChain->SetBranchAddress("Pd_OWNPV_X", &Pd_OWNPV_X, &b_Pd_OWNPV_X);
  fChain->SetBranchAddress("Pd_OWNPV_Y", &Pd_OWNPV_Y, &b_Pd_OWNPV_Y);
  fChain->SetBranchAddress("Pd_OWNPV_Z", &Pd_OWNPV_Z, &b_Pd_OWNPV_Z);
  fChain->SetBranchAddress("Pd_OWNPV_XERR", &Pd_OWNPV_XERR, &b_Pd_OWNPV_XERR);
  fChain->SetBranchAddress("Pd_OWNPV_YERR", &Pd_OWNPV_YERR, &b_Pd_OWNPV_YERR);
  fChain->SetBranchAddress("Pd_OWNPV_ZERR", &Pd_OWNPV_ZERR, &b_Pd_OWNPV_ZERR);
  fChain->SetBranchAddress("Pd_OWNPV_CHI2", &Pd_OWNPV_CHI2, &b_Pd_OWNPV_CHI2);
  fChain->SetBranchAddress("Pd_OWNPV_NDOF", &Pd_OWNPV_NDOF, &b_Pd_OWNPV_NDOF);
  fChain->SetBranchAddress("Pd_OWNPV_COV_", Pd_OWNPV_COV_, &b_Pd_OWNPV_COV_);
  fChain->SetBranchAddress("Pd_IP_OWNPV", &Pd_IP_OWNPV, &b_Pd_IP_OWNPV);
  fChain->SetBranchAddress("Pd_IPCHI2_OWNPV", &Pd_IPCHI2_OWNPV, &b_Pd_IPCHI2_OWNPV);
  fChain->SetBranchAddress("Pd_ORIVX_X", &Pd_ORIVX_X, &b_Pd_ORIVX_X);
  fChain->SetBranchAddress("Pd_ORIVX_Y", &Pd_ORIVX_Y, &b_Pd_ORIVX_Y);
  fChain->SetBranchAddress("Pd_ORIVX_Z", &Pd_ORIVX_Z, &b_Pd_ORIVX_Z);
  fChain->SetBranchAddress("Pd_ORIVX_XERR", &Pd_ORIVX_XERR, &b_Pd_ORIVX_XERR);
  fChain->SetBranchAddress("Pd_ORIVX_YERR", &Pd_ORIVX_YERR, &b_Pd_ORIVX_YERR);
  fChain->SetBranchAddress("Pd_ORIVX_ZERR", &Pd_ORIVX_ZERR, &b_Pd_ORIVX_ZERR);
  fChain->SetBranchAddress("Pd_ORIVX_CHI2", &Pd_ORIVX_CHI2, &b_Pd_ORIVX_CHI2);
  fChain->SetBranchAddress("Pd_ORIVX_NDOF", &Pd_ORIVX_NDOF, &b_Pd_ORIVX_NDOF);
  fChain->SetBranchAddress("Pd_ORIVX_COV_", Pd_ORIVX_COV_, &b_Pd_ORIVX_COV_);
  fChain->SetBranchAddress("Pd_P", &Pd_P, &b_Pd_P);
  fChain->SetBranchAddress("Pd_PT", &Pd_PT, &b_Pd_PT);
  fChain->SetBranchAddress("Pd_PE", &Pd_PE, &b_Pd_PE);
  fChain->SetBranchAddress("Pd_PX", &Pd_PX, &b_Pd_PX);
  fChain->SetBranchAddress("Pd_PY", &Pd_PY, &b_Pd_PY);
  fChain->SetBranchAddress("Pd_PZ", &Pd_PZ, &b_Pd_PZ);
  fChain->SetBranchAddress("Pd_M", &Pd_M, &b_Pd_M);
  fChain->SetBranchAddress("Pd_ID", &Pd_ID, &b_Pd_ID);
  fChain->SetBranchAddress("Pd_PIDe", &Pd_PIDe, &b_Pd_PIDe);
  fChain->SetBranchAddress("Pd_PIDmu", &Pd_PIDmu, &b_Pd_PIDmu);
  fChain->SetBranchAddress("Pd_PIDK", &Pd_PIDK, &b_Pd_PIDK);
  fChain->SetBranchAddress("Pd_PIDp", &Pd_PIDp, &b_Pd_PIDp);
  fChain->SetBranchAddress("Pd_ProbNNe", &Pd_ProbNNe, &b_Pd_ProbNNe);
  fChain->SetBranchAddress("Pd_ProbNNk", &Pd_ProbNNk, &b_Pd_ProbNNk);
  fChain->SetBranchAddress("Pd_ProbNNp", &Pd_ProbNNp, &b_Pd_ProbNNp);
  fChain->SetBranchAddress("Pd_ProbNNpi", &Pd_ProbNNpi, &b_Pd_ProbNNpi);
  fChain->SetBranchAddress("Pd_ProbNNmu", &Pd_ProbNNmu, &b_Pd_ProbNNmu);
  fChain->SetBranchAddress("Pd_ProbNNghost", &Pd_ProbNNghost, &b_Pd_ProbNNghost);
  fChain->SetBranchAddress("Pd_hasMuon", &Pd_hasMuon, &b_Pd_hasMuon);
  fChain->SetBranchAddress("Pd_isMuon", &Pd_isMuon, &b_Pd_isMuon);
  fChain->SetBranchAddress("Pd_hasRich", &Pd_hasRich, &b_Pd_hasRich);
  fChain->SetBranchAddress("Pd_hasCalo", &Pd_hasCalo, &b_Pd_hasCalo);
  fChain->SetBranchAddress("Pd_TRACK_Type", &Pd_TRACK_Type, &b_Pd_TRACK_Type);
  fChain->SetBranchAddress("Pd_TRACK_Key", &Pd_TRACK_Key, &b_Pd_TRACK_Key);
  fChain->SetBranchAddress("Pd_TRACK_CHI2NDOF", &Pd_TRACK_CHI2NDOF, &b_Pd_TRACK_CHI2NDOF);
  fChain->SetBranchAddress("Pd_TRACK_PCHI2", &Pd_TRACK_PCHI2, &b_Pd_TRACK_PCHI2);
  fChain->SetBranchAddress("Pd_TRACK_MatchCHI2", &Pd_TRACK_MatchCHI2, &b_Pd_TRACK_MatchCHI2);
  fChain->SetBranchAddress("Pd_TRACK_GhostProb", &Pd_TRACK_GhostProb, &b_Pd_TRACK_GhostProb);
  fChain->SetBranchAddress("Pd_TRACK_CloneDist", &Pd_TRACK_CloneDist, &b_Pd_TRACK_CloneDist);
  fChain->SetBranchAddress("Pd_TRACK_Likelihood", &Pd_TRACK_Likelihood, &b_Pd_TRACK_Likelihood);
  fChain->SetBranchAddress("Ps_MC12TuneV2_ProbNNe", &Ps_MC12TuneV2_ProbNNe, &b_Ps_MC12TuneV2_ProbNNe);
  fChain->SetBranchAddress("Ps_MC12TuneV2_ProbNNmu", &Ps_MC12TuneV2_ProbNNmu, &b_Ps_MC12TuneV2_ProbNNmu);
  fChain->SetBranchAddress("Ps_MC12TuneV2_ProbNNpi", &Ps_MC12TuneV2_ProbNNpi, &b_Ps_MC12TuneV2_ProbNNpi);
  fChain->SetBranchAddress("Ps_MC12TuneV2_ProbNNk", &Ps_MC12TuneV2_ProbNNk, &b_Ps_MC12TuneV2_ProbNNk);
  fChain->SetBranchAddress("Ps_MC12TuneV2_ProbNNp", &Ps_MC12TuneV2_ProbNNp, &b_Ps_MC12TuneV2_ProbNNp);
  fChain->SetBranchAddress("Ps_MC12TuneV2_ProbNNghost", &Ps_MC12TuneV2_ProbNNghost, &b_Ps_MC12TuneV2_ProbNNghost);
  fChain->SetBranchAddress("Ps_MC12TuneV3_ProbNNe", &Ps_MC12TuneV3_ProbNNe, &b_Ps_MC12TuneV3_ProbNNe);
  fChain->SetBranchAddress("Ps_MC12TuneV3_ProbNNmu", &Ps_MC12TuneV3_ProbNNmu, &b_Ps_MC12TuneV3_ProbNNmu);
  fChain->SetBranchAddress("Ps_MC12TuneV3_ProbNNpi", &Ps_MC12TuneV3_ProbNNpi, &b_Ps_MC12TuneV3_ProbNNpi);
  fChain->SetBranchAddress("Ps_MC12TuneV3_ProbNNk", &Ps_MC12TuneV3_ProbNNk, &b_Ps_MC12TuneV3_ProbNNk);
  fChain->SetBranchAddress("Ps_MC12TuneV3_ProbNNp", &Ps_MC12TuneV3_ProbNNp, &b_Ps_MC12TuneV3_ProbNNp);
  fChain->SetBranchAddress("Ps_MC12TuneV3_ProbNNghost", &Ps_MC12TuneV3_ProbNNghost, &b_Ps_MC12TuneV3_ProbNNghost);
  fChain->SetBranchAddress("Ps_OWNPV_X", &Ps_OWNPV_X, &b_Ps_OWNPV_X);
  fChain->SetBranchAddress("Ps_OWNPV_Y", &Ps_OWNPV_Y, &b_Ps_OWNPV_Y);
  fChain->SetBranchAddress("Ps_OWNPV_Z", &Ps_OWNPV_Z, &b_Ps_OWNPV_Z);
  fChain->SetBranchAddress("Ps_OWNPV_XERR", &Ps_OWNPV_XERR, &b_Ps_OWNPV_XERR);
  fChain->SetBranchAddress("Ps_OWNPV_YERR", &Ps_OWNPV_YERR, &b_Ps_OWNPV_YERR);
  fChain->SetBranchAddress("Ps_OWNPV_ZERR", &Ps_OWNPV_ZERR, &b_Ps_OWNPV_ZERR);
  fChain->SetBranchAddress("Ps_OWNPV_CHI2", &Ps_OWNPV_CHI2, &b_Ps_OWNPV_CHI2);
  fChain->SetBranchAddress("Ps_OWNPV_NDOF", &Ps_OWNPV_NDOF, &b_Ps_OWNPV_NDOF);
  fChain->SetBranchAddress("Ps_OWNPV_COV_", Ps_OWNPV_COV_, &b_Ps_OWNPV_COV_);
  fChain->SetBranchAddress("Ps_IP_OWNPV", &Ps_IP_OWNPV, &b_Ps_IP_OWNPV);
  fChain->SetBranchAddress("Ps_IPCHI2_OWNPV", &Ps_IPCHI2_OWNPV, &b_Ps_IPCHI2_OWNPV);
  fChain->SetBranchAddress("Ps_ORIVX_X", &Ps_ORIVX_X, &b_Ps_ORIVX_X);
  fChain->SetBranchAddress("Ps_ORIVX_Y", &Ps_ORIVX_Y, &b_Ps_ORIVX_Y);
  fChain->SetBranchAddress("Ps_ORIVX_Z", &Ps_ORIVX_Z, &b_Ps_ORIVX_Z);
  fChain->SetBranchAddress("Ps_ORIVX_XERR", &Ps_ORIVX_XERR, &b_Ps_ORIVX_XERR);
  fChain->SetBranchAddress("Ps_ORIVX_YERR", &Ps_ORIVX_YERR, &b_Ps_ORIVX_YERR);
  fChain->SetBranchAddress("Ps_ORIVX_ZERR", &Ps_ORIVX_ZERR, &b_Ps_ORIVX_ZERR);
  fChain->SetBranchAddress("Ps_ORIVX_CHI2", &Ps_ORIVX_CHI2, &b_Ps_ORIVX_CHI2);
  fChain->SetBranchAddress("Ps_ORIVX_NDOF", &Ps_ORIVX_NDOF, &b_Ps_ORIVX_NDOF);
  fChain->SetBranchAddress("Ps_ORIVX_COV_", Ps_ORIVX_COV_, &b_Ps_ORIVX_COV_);
  fChain->SetBranchAddress("Ps_P", &Ps_P, &b_Ps_P);
  fChain->SetBranchAddress("Ps_PT", &Ps_PT, &b_Ps_PT);
  fChain->SetBranchAddress("Ps_PE", &Ps_PE, &b_Ps_PE);
  fChain->SetBranchAddress("Ps_PX", &Ps_PX, &b_Ps_PX);
  fChain->SetBranchAddress("Ps_PY", &Ps_PY, &b_Ps_PY);
  fChain->SetBranchAddress("Ps_PZ", &Ps_PZ, &b_Ps_PZ);
  fChain->SetBranchAddress("Ps_M", &Ps_M, &b_Ps_M);
  fChain->SetBranchAddress("Ps_ID", &Ps_ID, &b_Ps_ID);
  fChain->SetBranchAddress("Ps_PIDe", &Ps_PIDe, &b_Ps_PIDe);
  fChain->SetBranchAddress("Ps_PIDmu", &Ps_PIDmu, &b_Ps_PIDmu);
  fChain->SetBranchAddress("Ps_PIDK", &Ps_PIDK, &b_Ps_PIDK);
  fChain->SetBranchAddress("Ps_PIDp", &Ps_PIDp, &b_Ps_PIDp);
  fChain->SetBranchAddress("Ps_ProbNNe", &Ps_ProbNNe, &b_Ps_ProbNNe);
  fChain->SetBranchAddress("Ps_ProbNNk", &Ps_ProbNNk, &b_Ps_ProbNNk);
  fChain->SetBranchAddress("Ps_ProbNNp", &Ps_ProbNNp, &b_Ps_ProbNNp);
  fChain->SetBranchAddress("Ps_ProbNNpi", &Ps_ProbNNpi, &b_Ps_ProbNNpi);
  fChain->SetBranchAddress("Ps_ProbNNmu", &Ps_ProbNNmu, &b_Ps_ProbNNmu);
  fChain->SetBranchAddress("Ps_ProbNNghost", &Ps_ProbNNghost, &b_Ps_ProbNNghost);
  fChain->SetBranchAddress("Ps_hasMuon", &Ps_hasMuon, &b_Ps_hasMuon);
  fChain->SetBranchAddress("Ps_isMuon", &Ps_isMuon, &b_Ps_isMuon);
  fChain->SetBranchAddress("Ps_hasRich", &Ps_hasRich, &b_Ps_hasRich);
  fChain->SetBranchAddress("Ps_hasCalo", &Ps_hasCalo, &b_Ps_hasCalo);
  fChain->SetBranchAddress("Ps_TRACK_Type", &Ps_TRACK_Type, &b_Ps_TRACK_Type);
  fChain->SetBranchAddress("Ps_TRACK_Key", &Ps_TRACK_Key, &b_Ps_TRACK_Key);
  fChain->SetBranchAddress("Ps_TRACK_CHI2NDOF", &Ps_TRACK_CHI2NDOF, &b_Ps_TRACK_CHI2NDOF);
  fChain->SetBranchAddress("Ps_TRACK_PCHI2", &Ps_TRACK_PCHI2, &b_Ps_TRACK_PCHI2);
  fChain->SetBranchAddress("Ps_TRACK_MatchCHI2", &Ps_TRACK_MatchCHI2, &b_Ps_TRACK_MatchCHI2);
  fChain->SetBranchAddress("Ps_TRACK_GhostProb", &Ps_TRACK_GhostProb, &b_Ps_TRACK_GhostProb);
  fChain->SetBranchAddress("Ps_TRACK_CloneDist", &Ps_TRACK_CloneDist, &b_Ps_TRACK_CloneDist);
  fChain->SetBranchAddress("Ps_TRACK_Likelihood", &Ps_TRACK_Likelihood, &b_Ps_TRACK_Likelihood);
  fChain->SetBranchAddress("Mu_MC12TuneV2_ProbNNe", &Mu_MC12TuneV2_ProbNNe, &b_Mu_MC12TuneV2_ProbNNe);
  fChain->SetBranchAddress("Mu_MC12TuneV2_ProbNNmu", &Mu_MC12TuneV2_ProbNNmu, &b_Mu_MC12TuneV2_ProbNNmu);
  fChain->SetBranchAddress("Mu_MC12TuneV2_ProbNNpi", &Mu_MC12TuneV2_ProbNNpi, &b_Mu_MC12TuneV2_ProbNNpi);
  fChain->SetBranchAddress("Mu_MC12TuneV2_ProbNNk", &Mu_MC12TuneV2_ProbNNk, &b_Mu_MC12TuneV2_ProbNNk);
  fChain->SetBranchAddress("Mu_MC12TuneV2_ProbNNp", &Mu_MC12TuneV2_ProbNNp, &b_Mu_MC12TuneV2_ProbNNp);
  fChain->SetBranchAddress("Mu_MC12TuneV2_ProbNNghost", &Mu_MC12TuneV2_ProbNNghost, &b_Mu_MC12TuneV2_ProbNNghost);
  fChain->SetBranchAddress("Mu_MC12TuneV3_ProbNNe", &Mu_MC12TuneV3_ProbNNe, &b_Mu_MC12TuneV3_ProbNNe);
  fChain->SetBranchAddress("Mu_MC12TuneV3_ProbNNmu", &Mu_MC12TuneV3_ProbNNmu, &b_Mu_MC12TuneV3_ProbNNmu);
  fChain->SetBranchAddress("Mu_MC12TuneV3_ProbNNpi", &Mu_MC12TuneV3_ProbNNpi, &b_Mu_MC12TuneV3_ProbNNpi);
  fChain->SetBranchAddress("Mu_MC12TuneV3_ProbNNk", &Mu_MC12TuneV3_ProbNNk, &b_Mu_MC12TuneV3_ProbNNk);
  fChain->SetBranchAddress("Mu_MC12TuneV3_ProbNNp", &Mu_MC12TuneV3_ProbNNp, &b_Mu_MC12TuneV3_ProbNNp);
  fChain->SetBranchAddress("Mu_MC12TuneV3_ProbNNghost", &Mu_MC12TuneV3_ProbNNghost, &b_Mu_MC12TuneV3_ProbNNghost);
  fChain->SetBranchAddress("Mu_OWNPV_X", &Mu_OWNPV_X, &b_Mu_OWNPV_X);
  fChain->SetBranchAddress("Mu_OWNPV_Y", &Mu_OWNPV_Y, &b_Mu_OWNPV_Y);
  fChain->SetBranchAddress("Mu_OWNPV_Z", &Mu_OWNPV_Z, &b_Mu_OWNPV_Z);
  fChain->SetBranchAddress("Mu_OWNPV_XERR", &Mu_OWNPV_XERR, &b_Mu_OWNPV_XERR);
  fChain->SetBranchAddress("Mu_OWNPV_YERR", &Mu_OWNPV_YERR, &b_Mu_OWNPV_YERR);
  fChain->SetBranchAddress("Mu_OWNPV_ZERR", &Mu_OWNPV_ZERR, &b_Mu_OWNPV_ZERR);
  fChain->SetBranchAddress("Mu_OWNPV_CHI2", &Mu_OWNPV_CHI2, &b_Mu_OWNPV_CHI2);
  fChain->SetBranchAddress("Mu_OWNPV_NDOF", &Mu_OWNPV_NDOF, &b_Mu_OWNPV_NDOF);
  fChain->SetBranchAddress("Mu_OWNPV_COV_", Mu_OWNPV_COV_, &b_Mu_OWNPV_COV_);
  fChain->SetBranchAddress("Mu_IP_OWNPV", &Mu_IP_OWNPV, &b_Mu_IP_OWNPV);
  fChain->SetBranchAddress("Mu_IPCHI2_OWNPV", &Mu_IPCHI2_OWNPV, &b_Mu_IPCHI2_OWNPV);
  fChain->SetBranchAddress("Mu_ORIVX_X", &Mu_ORIVX_X, &b_Mu_ORIVX_X);
  fChain->SetBranchAddress("Mu_ORIVX_Y", &Mu_ORIVX_Y, &b_Mu_ORIVX_Y);
  fChain->SetBranchAddress("Mu_ORIVX_Z", &Mu_ORIVX_Z, &b_Mu_ORIVX_Z);
  fChain->SetBranchAddress("Mu_ORIVX_XERR", &Mu_ORIVX_XERR, &b_Mu_ORIVX_XERR);
  fChain->SetBranchAddress("Mu_ORIVX_YERR", &Mu_ORIVX_YERR, &b_Mu_ORIVX_YERR);
  fChain->SetBranchAddress("Mu_ORIVX_ZERR", &Mu_ORIVX_ZERR, &b_Mu_ORIVX_ZERR);
  fChain->SetBranchAddress("Mu_ORIVX_CHI2", &Mu_ORIVX_CHI2, &b_Mu_ORIVX_CHI2);
  fChain->SetBranchAddress("Mu_ORIVX_NDOF", &Mu_ORIVX_NDOF, &b_Mu_ORIVX_NDOF);
  fChain->SetBranchAddress("Mu_ORIVX_COV_", Mu_ORIVX_COV_, &b_Mu_ORIVX_COV_);
  fChain->SetBranchAddress("Mu_P", &Mu_P, &b_Mu_P);
  fChain->SetBranchAddress("Mu_PT", &Mu_PT, &b_Mu_PT);
  fChain->SetBranchAddress("Mu_PE", &Mu_PE, &b_Mu_PE);
  fChain->SetBranchAddress("Mu_PX", &Mu_PX, &b_Mu_PX);
  fChain->SetBranchAddress("Mu_PY", &Mu_PY, &b_Mu_PY);
  fChain->SetBranchAddress("Mu_PZ", &Mu_PZ, &b_Mu_PZ);
  fChain->SetBranchAddress("Mu_M", &Mu_M, &b_Mu_M);
  fChain->SetBranchAddress("Mu_ID", &Mu_ID, &b_Mu_ID);
  fChain->SetBranchAddress("Mu_PIDe", &Mu_PIDe, &b_Mu_PIDe);
  fChain->SetBranchAddress("Mu_PIDmu", &Mu_PIDmu, &b_Mu_PIDmu);
  fChain->SetBranchAddress("Mu_PIDK", &Mu_PIDK, &b_Mu_PIDK);
  fChain->SetBranchAddress("Mu_PIDp", &Mu_PIDp, &b_Mu_PIDp);
  fChain->SetBranchAddress("Mu_ProbNNe", &Mu_ProbNNe, &b_Mu_ProbNNe);
  fChain->SetBranchAddress("Mu_ProbNNk", &Mu_ProbNNk, &b_Mu_ProbNNk);
  fChain->SetBranchAddress("Mu_ProbNNp", &Mu_ProbNNp, &b_Mu_ProbNNp);
  fChain->SetBranchAddress("Mu_ProbNNpi", &Mu_ProbNNpi, &b_Mu_ProbNNpi);
  fChain->SetBranchAddress("Mu_ProbNNmu", &Mu_ProbNNmu, &b_Mu_ProbNNmu);
  fChain->SetBranchAddress("Mu_ProbNNghost", &Mu_ProbNNghost, &b_Mu_ProbNNghost);
  fChain->SetBranchAddress("Mu_hasMuon", &Mu_hasMuon, &b_Mu_hasMuon);
  fChain->SetBranchAddress("Mu_isMuon", &Mu_isMuon, &b_Mu_isMuon);
  fChain->SetBranchAddress("Mu_hasRich", &Mu_hasRich, &b_Mu_hasRich);
  fChain->SetBranchAddress("Mu_hasCalo", &Mu_hasCalo, &b_Mu_hasCalo);
  fChain->SetBranchAddress("Mu_TRACK_Type", &Mu_TRACK_Type, &b_Mu_TRACK_Type);
  fChain->SetBranchAddress("Mu_TRACK_Key", &Mu_TRACK_Key, &b_Mu_TRACK_Key);
  fChain->SetBranchAddress("Mu_TRACK_CHI2NDOF", &Mu_TRACK_CHI2NDOF, &b_Mu_TRACK_CHI2NDOF);
  fChain->SetBranchAddress("Mu_TRACK_PCHI2", &Mu_TRACK_PCHI2, &b_Mu_TRACK_PCHI2);
  fChain->SetBranchAddress("Mu_TRACK_MatchCHI2", &Mu_TRACK_MatchCHI2, &b_Mu_TRACK_MatchCHI2);
  fChain->SetBranchAddress("Mu_TRACK_GhostProb", &Mu_TRACK_GhostProb, &b_Mu_TRACK_GhostProb);
  fChain->SetBranchAddress("Mu_TRACK_CloneDist", &Mu_TRACK_CloneDist, &b_Mu_TRACK_CloneDist);
  fChain->SetBranchAddress("Mu_TRACK_Likelihood", &Mu_TRACK_Likelihood, &b_Mu_TRACK_Likelihood);
  fChain->SetBranchAddress("Mu_n_extra_mu", &Mu_n_extra_mu, &b_Mu_n_extra_mu);
  fChain->SetBranchAddress("Mu_extra_mu_PX", Mu_extra_mu_PX, &b_Mu_extra_mu_PX);
  fChain->SetBranchAddress("Mu_extra_mu_PY", Mu_extra_mu_PY, &b_Mu_extra_mu_PY);
  fChain->SetBranchAddress("Mu_extra_mu_PZ", Mu_extra_mu_PZ, &b_Mu_extra_mu_PZ);
  fChain->SetBranchAddress("Mu_extra_mu_E", Mu_extra_mu_E, &b_Mu_extra_mu_E);
  fChain->SetBranchAddress("Mu_extra_mu_ID", Mu_extra_mu_ID, &b_Mu_extra_mu_ID);
  fChain->SetBranchAddress("Mu_extra_mu_PIDmu", Mu_extra_mu_PIDmu, &b_Mu_extra_mu_PIDmu);
  fChain->SetBranchAddress("Mu_extra_mu_PIDK", Mu_extra_mu_PIDK, &b_Mu_extra_mu_PIDK);
  fChain->SetBranchAddress("Mu_extra_mu_ProbNNghost", Mu_extra_mu_ProbNNghost, &b_Mu_extra_mu_ProbNNghost);
  fChain->SetBranchAddress("Mu_extra_mu_TRACK_ghostProb", Mu_extra_mu_TRACK_ghostProb, &b_Mu_extra_mu_TRACK_ghostProb);
  fChain->SetBranchAddress("Mu_extra_mu_TRACK_chi2perDoF", Mu_extra_mu_TRACK_chi2perDoF, &b_Mu_extra_mu_TRACK_chi2perDoF);
  fChain->SetBranchAddress("Mu_dimuon_M", Mu_dimuon_M, &b_Mu_dimuon_M);
  fChain->SetBranchAddress("Mu_extra_mu_mu_vtx_chi2", Mu_extra_mu_mu_vtx_chi2, &b_Mu_extra_mu_mu_vtx_chi2);
  fChain->SetBranchAddress("Mu_extra_mu_mu_vtx_nDoF", Mu_extra_mu_mu_vtx_nDoF, &b_Mu_extra_mu_mu_vtx_nDoF);
  fChain->SetBranchAddress("Mu_extra_mu_dst_vtx_chi2", Mu_extra_mu_dst_vtx_chi2, &b_Mu_extra_mu_dst_vtx_chi2);
  fChain->SetBranchAddress("Mu_extra_mu_dst_vtx_nDoF", Mu_extra_mu_dst_vtx_nDoF, &b_Mu_extra_mu_dst_vtx_nDoF);
  fChain->SetBranchAddress("Mu_dst_mu_extra_M", Mu_dst_mu_extra_M, &b_Mu_dst_mu_extra_M);
  fChain->SetBranchAddress("Mu_extra_mu_IP", Mu_extra_mu_IP, &b_Mu_extra_mu_IP);
  fChain->SetBranchAddress("Mu_extra_mu_IPchi2", Mu_extra_mu_IPchi2, &b_Mu_extra_mu_IPchi2);
  fChain->SetBranchAddress("Mu_extra_mu_PV_match", Mu_extra_mu_PV_match, &b_Mu_extra_mu_PV_match);
  fChain->SetBranchAddress("Mu_extra_mu_IP_muPV", Mu_extra_mu_IP_muPV, &b_Mu_extra_mu_IP_muPV);
  fChain->SetBranchAddress("Mu_extra_mu_IPchi2_muPV", Mu_extra_mu_IPchi2_muPV, &b_Mu_extra_mu_IPchi2_muPV);
  fChain->SetBranchAddress("Mu_L0Global_Dec", &Mu_L0Global_Dec, &b_Mu_L0Global_Dec);
  fChain->SetBranchAddress("Mu_L0Global_TIS", &Mu_L0Global_TIS, &b_Mu_L0Global_TIS);
  fChain->SetBranchAddress("Mu_L0Global_TOS", &Mu_L0Global_TOS, &b_Mu_L0Global_TOS);
  fChain->SetBranchAddress("Mu_Hlt1Global_Dec", &Mu_Hlt1Global_Dec, &b_Mu_Hlt1Global_Dec);
  fChain->SetBranchAddress("Mu_Hlt1Global_TIS", &Mu_Hlt1Global_TIS, &b_Mu_Hlt1Global_TIS);
  fChain->SetBranchAddress("Mu_Hlt1Global_TOS", &Mu_Hlt1Global_TOS, &b_Mu_Hlt1Global_TOS);
  fChain->SetBranchAddress("Mu_Hlt1Phys_Dec", &Mu_Hlt1Phys_Dec, &b_Mu_Hlt1Phys_Dec);
  fChain->SetBranchAddress("Mu_Hlt1Phys_TIS", &Mu_Hlt1Phys_TIS, &b_Mu_Hlt1Phys_TIS);
  fChain->SetBranchAddress("Mu_Hlt1Phys_TOS", &Mu_Hlt1Phys_TOS, &b_Mu_Hlt1Phys_TOS);
  fChain->SetBranchAddress("Mu_Hlt2Global_Dec", &Mu_Hlt2Global_Dec, &b_Mu_Hlt2Global_Dec);
  fChain->SetBranchAddress("Mu_Hlt2Global_TIS", &Mu_Hlt2Global_TIS, &b_Mu_Hlt2Global_TIS);
  fChain->SetBranchAddress("Mu_Hlt2Global_TOS", &Mu_Hlt2Global_TOS, &b_Mu_Hlt2Global_TOS);
  fChain->SetBranchAddress("Mu_Hlt2Phys_Dec", &Mu_Hlt2Phys_Dec, &b_Mu_Hlt2Phys_Dec);
  fChain->SetBranchAddress("Mu_Hlt2Phys_TIS", &Mu_Hlt2Phys_TIS, &b_Mu_Hlt2Phys_TIS);
  fChain->SetBranchAddress("Mu_Hlt2Phys_TOS", &Mu_Hlt2Phys_TOS, &b_Mu_Hlt2Phys_TOS);
  fChain->SetBranchAddress("Mu_L0MuonDecision_Dec", &Mu_L0MuonDecision_Dec, &b_Mu_L0MuonDecision_Dec);
  fChain->SetBranchAddress("Mu_L0MuonDecision_TIS", &Mu_L0MuonDecision_TIS, &b_Mu_L0MuonDecision_TIS);
  fChain->SetBranchAddress("Mu_L0MuonDecision_TOS", &Mu_L0MuonDecision_TOS, &b_Mu_L0MuonDecision_TOS);
  fChain->SetBranchAddress("Mu_Hlt1TrackMuonDecision_Dec", &Mu_Hlt1TrackMuonDecision_Dec, &b_Mu_Hlt1TrackMuonDecision_Dec);
  fChain->SetBranchAddress("Mu_Hlt1TrackMuonDecision_TIS", &Mu_Hlt1TrackMuonDecision_TIS, &b_Mu_Hlt1TrackMuonDecision_TIS);
  fChain->SetBranchAddress("Mu_Hlt1TrackMuonDecision_TOS", &Mu_Hlt1TrackMuonDecision_TOS, &b_Mu_Hlt1TrackMuonDecision_TOS);
  fChain->SetBranchAddress("Mu_Hlt2SingleMuonDecision_Dec", &Mu_Hlt2SingleMuonDecision_Dec, &b_Mu_Hlt2SingleMuonDecision_Dec);
  fChain->SetBranchAddress("Mu_Hlt2SingleMuonDecision_TIS", &Mu_Hlt2SingleMuonDecision_TIS, &b_Mu_Hlt2SingleMuonDecision_TIS);
  fChain->SetBranchAddress("Mu_Hlt2SingleMuonDecision_TOS", &Mu_Hlt2SingleMuonDecision_TOS, &b_Mu_Hlt2SingleMuonDecision_TOS);
  fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
  fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
  fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
  fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
  fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
  fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
  fChain->SetBranchAddress("BCType", &BCType, &b_BCType);
  fChain->SetBranchAddress("OdinTCK", &OdinTCK, &b_OdinTCK);
  fChain->SetBranchAddress("L0DUTCK", &L0DUTCK, &b_L0DUTCK);
  fChain->SetBranchAddress("HLTTCK", &HLTTCK, &b_HLTTCK);
  fChain->SetBranchAddress("GpsTime", &GpsTime, &b_GpsTime);
  fChain->SetBranchAddress("Polarity", &Polarity, &b_Polarity);
  fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
  fChain->SetBranchAddress("PVX", PVX, &b_PVX);
  fChain->SetBranchAddress("PVY", PVY, &b_PVY);
  fChain->SetBranchAddress("PVZ", PVZ, &b_PVZ);
  fChain->SetBranchAddress("PVXERR", PVXERR, &b_PVXERR);
  fChain->SetBranchAddress("PVYERR", PVYERR, &b_PVYERR);
  fChain->SetBranchAddress("PVZERR", PVZERR, &b_PVZERR);
  fChain->SetBranchAddress("PVCHI2", PVCHI2, &b_PVCHI2);
  fChain->SetBranchAddress("PVNDOF", PVNDOF, &b_PVNDOF);
  fChain->SetBranchAddress("PVNTRACKS", PVNTRACKS, &b_PVNTRACKS);
  fChain->SetBranchAddress("nPVs", &nPVs, &b_nPVs);
  fChain->SetBranchAddress("nTracks", &nTracks, &b_nTracks);
  fChain->SetBranchAddress("nLongTracks", &nLongTracks, &b_nLongTracks);
  fChain->SetBranchAddress("nDownstreamTracks", &nDownstreamTracks, &b_nDownstreamTracks);
  fChain->SetBranchAddress("nUpstreamTracks", &nUpstreamTracks, &b_nUpstreamTracks);
  fChain->SetBranchAddress("nVeloTracks", &nVeloTracks, &b_nVeloTracks);
  fChain->SetBranchAddress("nTTracks", &nTTracks, &b_nTTracks);
  fChain->SetBranchAddress("nBackTracks", &nBackTracks, &b_nBackTracks);
  fChain->SetBranchAddress("nRich1Hits", &nRich1Hits, &b_nRich1Hits);
  fChain->SetBranchAddress("nRich2Hits", &nRich2Hits, &b_nRich2Hits);
  fChain->SetBranchAddress("nVeloClusters", &nVeloClusters, &b_nVeloClusters);
  fChain->SetBranchAddress("nITClusters", &nITClusters, &b_nITClusters);
  fChain->SetBranchAddress("nTTClusters", &nTTClusters, &b_nTTClusters);
  fChain->SetBranchAddress("nOTClusters", &nOTClusters, &b_nOTClusters);
  fChain->SetBranchAddress("nSPDHits", &nSPDHits, &b_nSPDHits);
  fChain->SetBranchAddress("nMuonCoordsS0", &nMuonCoordsS0, &b_nMuonCoordsS0);
  fChain->SetBranchAddress("nMuonCoordsS1", &nMuonCoordsS1, &b_nMuonCoordsS1);
  fChain->SetBranchAddress("nMuonCoordsS2", &nMuonCoordsS2, &b_nMuonCoordsS2);
  fChain->SetBranchAddress("nMuonCoordsS3", &nMuonCoordsS3, &b_nMuonCoordsS3);
  fChain->SetBranchAddress("nMuonCoordsS4", &nMuonCoordsS4, &b_nMuonCoordsS4);
  fChain->SetBranchAddress("nMuonTracks", &nMuonTracks, &b_nMuonTracks);
  fChain->SetBranchAddress("L0Global", &L0Global, &b_L0Global);
  fChain->SetBranchAddress("Hlt1Global", &Hlt1Global, &b_Hlt1Global);
  fChain->SetBranchAddress("Hlt2Global", &Hlt2Global, &b_Hlt2Global);
  Notify();
}

Bool_t DT_D0_mix_CPV::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void DT_D0_mix_CPV::Show(Long64_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}
Int_t DT_D0_mix_CPV::Cut(Long64_t entry)
{
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  
  return 1;
}
Int_t DT_D0_mix_CPV::passCuts(){
  return 1;
}
#endif // #ifdef DT_D0_mix_CPV_cxx
