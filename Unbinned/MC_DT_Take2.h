//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jun  3 09:43:32 2015 by ROOT version 6.02/05
// from TTree DecayTree/DecayTree
// found on file: DVTuples_signalMC_with_hierarchy.root
//////////////////////////////////////////////////////////

#ifndef MC_DT_Take2_h
#define MC_DT_Take2_h

#include <iostream>
#include <vector>

#include <TH1.h>
#include <TH2.h>
#include <TLorentzVector.h>


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class MC_DT_Take2 {
public :
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain

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
  Int_t           B_BKGCAT;
  Int_t           B_TRUEID;
  Int_t           B_MC_MOTHER_ID;
  Int_t           B_MC_MOTHER_KEY;
  Int_t           B_MC_GD_MOTHER_ID;
  Int_t           B_MC_GD_MOTHER_KEY;
  Int_t           B_MC_GD_GD_MOTHER_ID;
  Int_t           B_MC_GD_GD_MOTHER_KEY;
  Double_t        B_TRUEP_E;
  Double_t        B_TRUEP_X;
  Double_t        B_TRUEP_Y;
  Double_t        B_TRUEP_Z;
  Double_t        B_TRUEPT;
  Double_t        B_TRUEORIGINVERTEX_X;
  Double_t        B_TRUEORIGINVERTEX_Y;
  Double_t        B_TRUEORIGINVERTEX_Z;
  Double_t        B_TRUEENDVERTEX_X;
  Double_t        B_TRUEENDVERTEX_Y;
  Double_t        B_TRUEENDVERTEX_Z;
  Bool_t          B_TRUEISSTABLE;
  Double_t        B_TRUETAU;
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
  Int_t           Dstar_BKGCAT;
  Int_t           Dstar_TRUEID;
  Int_t           Dstar_MC_MOTHER_ID;
  Int_t           Dstar_MC_MOTHER_KEY;
  Int_t           Dstar_MC_GD_MOTHER_ID;
  Int_t           Dstar_MC_GD_MOTHER_KEY;
  Int_t           Dstar_MC_GD_GD_MOTHER_ID;
  Int_t           Dstar_MC_GD_GD_MOTHER_KEY;
  Double_t        Dstar_TRUEP_E;
  Double_t        Dstar_TRUEP_X;
  Double_t        Dstar_TRUEP_Y;
  Double_t        Dstar_TRUEP_Z;
  Double_t        Dstar_TRUEPT;
  Double_t        Dstar_TRUEORIGINVERTEX_X;
  Double_t        Dstar_TRUEORIGINVERTEX_Y;
  Double_t        Dstar_TRUEORIGINVERTEX_Z;
  Double_t        Dstar_TRUEENDVERTEX_X;
  Double_t        Dstar_TRUEENDVERTEX_Y;
  Double_t        Dstar_TRUEENDVERTEX_Z;
  Bool_t          Dstar_TRUEISSTABLE;
  Double_t        Dstar_TRUETAU;
  Int_t           Dstar_ID;
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
  Int_t           D_BKGCAT;
  Int_t           D_TRUEID;
  Int_t           D_MC_MOTHER_ID;
  Int_t           D_MC_MOTHER_KEY;
  Int_t           D_MC_GD_MOTHER_ID;
  Int_t           D_MC_GD_MOTHER_KEY;
  Int_t           D_MC_GD_GD_MOTHER_ID;
  Int_t           D_MC_GD_GD_MOTHER_KEY;
  Double_t        D_TRUEP_E;
  Double_t        D_TRUEP_X;
  Double_t        D_TRUEP_Y;
  Double_t        D_TRUEP_Z;
  Double_t        D_TRUEPT;
  Double_t        D_TRUEORIGINVERTEX_X;
  Double_t        D_TRUEORIGINVERTEX_Y;
  Double_t        D_TRUEORIGINVERTEX_Z;
  Double_t        D_TRUEENDVERTEX_X;
  Double_t        D_TRUEENDVERTEX_Y;
  Double_t        D_TRUEENDVERTEX_Z;
  Bool_t          D_TRUEISSTABLE;
  Double_t        D_TRUETAU;
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
  Int_t           K_TRUEID;
  Int_t           K_MC_MOTHER_ID;
  Int_t           K_MC_MOTHER_KEY;
  Int_t           K_MC_GD_MOTHER_ID;
  Int_t           K_MC_GD_MOTHER_KEY;
  Int_t           K_MC_GD_GD_MOTHER_ID;
  Int_t           K_MC_GD_GD_MOTHER_KEY;
  Double_t        K_TRUEP_E;
  Double_t        K_TRUEP_X;
  Double_t        K_TRUEP_Y;
  Double_t        K_TRUEP_Z;
  Double_t        K_TRUEPT;
  Double_t        K_TRUEORIGINVERTEX_X;
  Double_t        K_TRUEORIGINVERTEX_Y;
  Double_t        K_TRUEORIGINVERTEX_Z;
  Double_t        K_TRUEENDVERTEX_X;
  Double_t        K_TRUEENDVERTEX_Y;
  Double_t        K_TRUEENDVERTEX_Z;
  Bool_t          K_TRUEISSTABLE;
  Double_t        K_TRUETAU;
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
  Bool_t          K_UsedRichAerogel;
  Bool_t          K_UsedRich1Gas;
  Bool_t          K_UsedRich2Gas;
  Bool_t          K_RichAboveElThres;
  Bool_t          K_RichAboveMuThres;
  Bool_t          K_RichAbovePiThres;
  Bool_t          K_RichAboveKaThres;
  Bool_t          K_RichAbovePrThres;
  Double_t        K_RichDLLe;
  Double_t        K_RichDLLmu;
  Double_t        K_RichDLLpi;
  Double_t        K_RichDLLk;
  Double_t        K_RichDLLp;
  Double_t        K_RichDLLbt;
  Bool_t          K_InAccMuon;
  Bool_t          K_isMuonLoose;
  Double_t        K_MuonMuLL;
  Double_t        K_MuonBkgLL;
  Int_t           K_MuonNShared;
  Bool_t          K_InAccEcal;
  Double_t        K_CaloEcalE;
  Double_t        K_EcalPIDe;
  Double_t        K_EcalPIDmu;
  Bool_t          K_InAccHcal;
  Double_t        K_CaloHcalE;
  Double_t        K_HcalPIDe;
  Double_t        K_HcalPIDmu;
  Bool_t          K_InAccPrs;
  Double_t        K_PrsPIDe;
  Double_t        K_CaloPrsE;
  Bool_t          K_InAccSpd;
  Double_t        K_CaloSpdE;
  Bool_t          K_InAccBrem;
  Double_t        K_BremPIDe;
  Double_t        K_VeloCharge;
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
  Int_t           Pd_TRUEID;
  Int_t           Pd_MC_MOTHER_ID;
  Int_t           Pd_MC_MOTHER_KEY;
  Int_t           Pd_MC_GD_MOTHER_ID;
  Int_t           Pd_MC_GD_MOTHER_KEY;
  Int_t           Pd_MC_GD_GD_MOTHER_ID;
  Int_t           Pd_MC_GD_GD_MOTHER_KEY;
  Double_t        Pd_TRUEP_E;
  Double_t        Pd_TRUEP_X;
  Double_t        Pd_TRUEP_Y;
  Double_t        Pd_TRUEP_Z;
  Double_t        Pd_TRUEPT;
  Double_t        Pd_TRUEORIGINVERTEX_X;
  Double_t        Pd_TRUEORIGINVERTEX_Y;
  Double_t        Pd_TRUEORIGINVERTEX_Z;
  Double_t        Pd_TRUEENDVERTEX_X;
  Double_t        Pd_TRUEENDVERTEX_Y;
  Double_t        Pd_TRUEENDVERTEX_Z;
  Bool_t          Pd_TRUEISSTABLE;
  Double_t        Pd_TRUETAU;
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
  Bool_t          Pd_UsedRichAerogel;
  Bool_t          Pd_UsedRich1Gas;
  Bool_t          Pd_UsedRich2Gas;
  Bool_t          Pd_RichAboveElThres;
  Bool_t          Pd_RichAboveMuThres;
  Bool_t          Pd_RichAbovePiThres;
  Bool_t          Pd_RichAboveKaThres;
  Bool_t          Pd_RichAbovePrThres;
  Double_t        Pd_RichDLLe;
  Double_t        Pd_RichDLLmu;
  Double_t        Pd_RichDLLpi;
  Double_t        Pd_RichDLLk;
  Double_t        Pd_RichDLLp;
  Double_t        Pd_RichDLLbt;
  Bool_t          Pd_InAccMuon;
  Bool_t          Pd_isMuonLoose;
  Double_t        Pd_MuonMuLL;
  Double_t        Pd_MuonBkgLL;
  Int_t           Pd_MuonNShared;
  Bool_t          Pd_InAccEcal;
  Double_t        Pd_CaloEcalE;
  Double_t        Pd_EcalPIDe;
  Double_t        Pd_EcalPIDmu;
  Bool_t          Pd_InAccHcal;
  Double_t        Pd_CaloHcalE;
  Double_t        Pd_HcalPIDe;
  Double_t        Pd_HcalPIDmu;
  Bool_t          Pd_InAccPrs;
  Double_t        Pd_PrsPIDe;
  Double_t        Pd_CaloPrsE;
  Bool_t          Pd_InAccSpd;
  Double_t        Pd_CaloSpdE;
  Bool_t          Pd_InAccBrem;
  Double_t        Pd_BremPIDe;
  Double_t        Pd_VeloCharge;
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
  Int_t           Ps_TRUEID;
  Int_t           Ps_MC_MOTHER_ID;
  Int_t           Ps_MC_MOTHER_KEY;
  Int_t           Ps_MC_GD_MOTHER_ID;
  Int_t           Ps_MC_GD_MOTHER_KEY;
  Int_t           Ps_MC_GD_GD_MOTHER_ID;
  Int_t           Ps_MC_GD_GD_MOTHER_KEY;
  Double_t        Ps_TRUEP_E;
  Double_t        Ps_TRUEP_X;
  Double_t        Ps_TRUEP_Y;
  Double_t        Ps_TRUEP_Z;
  Double_t        Ps_TRUEPT;
  Double_t        Ps_TRUEORIGINVERTEX_X;
  Double_t        Ps_TRUEORIGINVERTEX_Y;
  Double_t        Ps_TRUEORIGINVERTEX_Z;
  Double_t        Ps_TRUEENDVERTEX_X;
  Double_t        Ps_TRUEENDVERTEX_Y;
  Double_t        Ps_TRUEENDVERTEX_Z;
  Bool_t          Ps_TRUEISSTABLE;
  Double_t        Ps_TRUETAU;
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
  Bool_t          Ps_UsedRichAerogel;
  Bool_t          Ps_UsedRich1Gas;
  Bool_t          Ps_UsedRich2Gas;
  Bool_t          Ps_RichAboveElThres;
  Bool_t          Ps_RichAboveMuThres;
  Bool_t          Ps_RichAbovePiThres;
  Bool_t          Ps_RichAboveKaThres;
  Bool_t          Ps_RichAbovePrThres;
  Double_t        Ps_RichDLLe;
  Double_t        Ps_RichDLLmu;
  Double_t        Ps_RichDLLpi;
  Double_t        Ps_RichDLLk;
  Double_t        Ps_RichDLLp;
  Double_t        Ps_RichDLLbt;
  Bool_t          Ps_InAccMuon;
  Bool_t          Ps_isMuonLoose;
  Double_t        Ps_MuonMuLL;
  Double_t        Ps_MuonBkgLL;
  Int_t           Ps_MuonNShared;
  Bool_t          Ps_InAccEcal;
  Double_t        Ps_CaloEcalE;
  Double_t        Ps_EcalPIDe;
  Double_t        Ps_EcalPIDmu;
  Bool_t          Ps_InAccHcal;
  Double_t        Ps_CaloHcalE;
  Double_t        Ps_HcalPIDe;
  Double_t        Ps_HcalPIDmu;
  Bool_t          Ps_InAccPrs;
  Double_t        Ps_PrsPIDe;
  Double_t        Ps_CaloPrsE;
  Bool_t          Ps_InAccSpd;
  Double_t        Ps_CaloSpdE;
  Bool_t          Ps_InAccBrem;
  Double_t        Ps_BremPIDe;
  Double_t        Ps_VeloCharge;
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
  Int_t           Mu_TRUEID;
  Int_t           Mu_MC_MOTHER_ID;
  Int_t           Mu_MC_MOTHER_KEY;
  Int_t           Mu_MC_GD_MOTHER_ID;
  Int_t           Mu_MC_GD_MOTHER_KEY;
  Int_t           Mu_MC_GD_GD_MOTHER_ID;
  Int_t           Mu_MC_GD_GD_MOTHER_KEY;
  Double_t        Mu_TRUEP_E;
  Double_t        Mu_TRUEP_X;
  Double_t        Mu_TRUEP_Y;
  Double_t        Mu_TRUEP_Z;
  Double_t        Mu_TRUEPT;
  Double_t        Mu_TRUEORIGINVERTEX_X;
  Double_t        Mu_TRUEORIGINVERTEX_Y;
  Double_t        Mu_TRUEORIGINVERTEX_Z;
  Double_t        Mu_TRUEENDVERTEX_X;
  Double_t        Mu_TRUEENDVERTEX_Y;
  Double_t        Mu_TRUEENDVERTEX_Z;
  Bool_t          Mu_TRUEISSTABLE;
  Double_t        Mu_TRUETAU;
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
  Bool_t          Mu_UsedRichAerogel;
  Bool_t          Mu_UsedRich1Gas;
  Bool_t          Mu_UsedRich2Gas;
  Bool_t          Mu_RichAboveElThres;
  Bool_t          Mu_RichAboveMuThres;
  Bool_t          Mu_RichAbovePiThres;
  Bool_t          Mu_RichAboveKaThres;
  Bool_t          Mu_RichAbovePrThres;
  Double_t        Mu_RichDLLe;
  Double_t        Mu_RichDLLmu;
  Double_t        Mu_RichDLLpi;
  Double_t        Mu_RichDLLk;
  Double_t        Mu_RichDLLp;
  Double_t        Mu_RichDLLbt;
  Bool_t          Mu_InAccMuon;
  Bool_t          Mu_isMuonLoose;
  Double_t        Mu_MuonMuLL;
  Double_t        Mu_MuonBkgLL;
  Int_t           Mu_MuonNShared;
  Bool_t          Mu_InAccEcal;
  Double_t        Mu_CaloEcalE;
  Double_t        Mu_EcalPIDe;
  Double_t        Mu_EcalPIDmu;
  Bool_t          Mu_InAccHcal;
  Double_t        Mu_CaloHcalE;
  Double_t        Mu_HcalPIDe;
  Double_t        Mu_HcalPIDmu;
  Bool_t          Mu_InAccPrs;
  Double_t        Mu_PrsPIDe;
  Double_t        Mu_CaloPrsE;
  Bool_t          Mu_InAccSpd;
  Double_t        Mu_CaloSpdE;
  Bool_t          Mu_InAccBrem;
  Double_t        Mu_BremPIDe;
  Double_t        Mu_VeloCharge;
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
  Float_t         Mu_extra_mu_MC12TuneV2ProbNNmu[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV2ProbNNe[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV2ProbNNk[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV2ProbNNpi[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV2ProbNNp[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV2ProbNNghost[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV3ProbNNmu[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV3ProbNNe[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV3ProbNNk[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV3ProbNNpi[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV3ProbNNp[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MC12TuneV3ProbNNghost[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_hasMuon[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_isMuon[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_isMuonLoose[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_InAccMuon[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MuonMuLL[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MuonBkgLL[100];   //[Mu_n_extra_mu]
  Float_t         Mu_extra_mu_MuonNShared[100];   //[Mu_n_extra_mu]
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
  TBranch        *b_B_BKGCAT;   //!
  TBranch        *b_B_TRUEID;   //!
  TBranch        *b_B_MC_MOTHER_ID;   //!
  TBranch        *b_B_MC_MOTHER_KEY;   //!
  TBranch        *b_B_MC_GD_MOTHER_ID;   //!
  TBranch        *b_B_MC_GD_MOTHER_KEY;   //!
  TBranch        *b_B_MC_GD_GD_MOTHER_ID;   //!
  TBranch        *b_B_MC_GD_GD_MOTHER_KEY;   //!
  TBranch        *b_B_TRUEP_E;   //!
  TBranch        *b_B_TRUEP_X;   //!
  TBranch        *b_B_TRUEP_Y;   //!
  TBranch        *b_B_TRUEP_Z;   //!
  TBranch        *b_B_TRUEPT;   //!
  TBranch        *b_B_TRUEORIGINVERTEX_X;   //!
  TBranch        *b_B_TRUEORIGINVERTEX_Y;   //!
  TBranch        *b_B_TRUEORIGINVERTEX_Z;   //!
  TBranch        *b_B_TRUEENDVERTEX_X;   //!
  TBranch        *b_B_TRUEENDVERTEX_Y;   //!
  TBranch        *b_B_TRUEENDVERTEX_Z;   //!
  TBranch        *b_B_TRUEISSTABLE;   //!
  TBranch        *b_B_TRUETAU;   //!
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
  TBranch        *b_Dstar_BKGCAT;   //!
  TBranch        *b_Dstar_TRUEID;   //!
  TBranch        *b_Dstar_MC_MOTHER_ID;   //!
  TBranch        *b_Dstar_MC_MOTHER_KEY;   //!
  TBranch        *b_Dstar_MC_GD_MOTHER_ID;   //!
  TBranch        *b_Dstar_MC_GD_MOTHER_KEY;   //!
  TBranch        *b_Dstar_MC_GD_GD_MOTHER_ID;   //!
  TBranch        *b_Dstar_MC_GD_GD_MOTHER_KEY;   //!
  TBranch        *b_Dstar_TRUEP_E;   //!
  TBranch        *b_Dstar_TRUEP_X;   //!
  TBranch        *b_Dstar_TRUEP_Y;   //!
  TBranch        *b_Dstar_TRUEP_Z;   //!
  TBranch        *b_Dstar_TRUEPT;   //!
  TBranch        *b_Dstar_TRUEORIGINVERTEX_X;   //!
  TBranch        *b_Dstar_TRUEORIGINVERTEX_Y;   //!
  TBranch        *b_Dstar_TRUEORIGINVERTEX_Z;   //!
  TBranch        *b_Dstar_TRUEENDVERTEX_X;   //!
  TBranch        *b_Dstar_TRUEENDVERTEX_Y;   //!
  TBranch        *b_Dstar_TRUEENDVERTEX_Z;   //!
  TBranch        *b_Dstar_TRUEISSTABLE;   //!
  TBranch        *b_Dstar_TRUETAU;   //!
  TBranch        *b_Dstar_ID;   //!
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
  TBranch        *b_D_BKGCAT;   //!
  TBranch        *b_D_TRUEID;   //!
  TBranch        *b_D_MC_MOTHER_ID;   //!
  TBranch        *b_D_MC_MOTHER_KEY;   //!
  TBranch        *b_D_MC_GD_MOTHER_ID;   //!
  TBranch        *b_D_MC_GD_MOTHER_KEY;   //!
  TBranch        *b_D_MC_GD_GD_MOTHER_ID;   //!
  TBranch        *b_D_MC_GD_GD_MOTHER_KEY;   //!
  TBranch        *b_D_TRUEP_E;   //!
  TBranch        *b_D_TRUEP_X;   //!
  TBranch        *b_D_TRUEP_Y;   //!
  TBranch        *b_D_TRUEP_Z;   //!
  TBranch        *b_D_TRUEPT;   //!
  TBranch        *b_D_TRUEORIGINVERTEX_X;   //!
  TBranch        *b_D_TRUEORIGINVERTEX_Y;   //!
  TBranch        *b_D_TRUEORIGINVERTEX_Z;   //!
  TBranch        *b_D_TRUEENDVERTEX_X;   //!
  TBranch        *b_D_TRUEENDVERTEX_Y;   //!
  TBranch        *b_D_TRUEENDVERTEX_Z;   //!
  TBranch        *b_D_TRUEISSTABLE;   //!
  TBranch        *b_D_TRUETAU;   //!
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
  TBranch        *b_K_TRUEID;   //!
  TBranch        *b_K_MC_MOTHER_ID;   //!
  TBranch        *b_K_MC_MOTHER_KEY;   //!
  TBranch        *b_K_MC_GD_MOTHER_ID;   //!
  TBranch        *b_K_MC_GD_MOTHER_KEY;   //!
  TBranch        *b_K_MC_GD_GD_MOTHER_ID;   //!
  TBranch        *b_K_MC_GD_GD_MOTHER_KEY;   //!
  TBranch        *b_K_TRUEP_E;   //!
  TBranch        *b_K_TRUEP_X;   //!
  TBranch        *b_K_TRUEP_Y;   //!
  TBranch        *b_K_TRUEP_Z;   //!
  TBranch        *b_K_TRUEPT;   //!
  TBranch        *b_K_TRUEORIGINVERTEX_X;   //!
  TBranch        *b_K_TRUEORIGINVERTEX_Y;   //!
  TBranch        *b_K_TRUEORIGINVERTEX_Z;   //!
  TBranch        *b_K_TRUEENDVERTEX_X;   //!
  TBranch        *b_K_TRUEENDVERTEX_Y;   //!
  TBranch        *b_K_TRUEENDVERTEX_Z;   //!
  TBranch        *b_K_TRUEISSTABLE;   //!
  TBranch        *b_K_TRUETAU;   //!
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
  TBranch        *b_K_UsedRichAerogel;   //!
  TBranch        *b_K_UsedRich1Gas;   //!
  TBranch        *b_K_UsedRich2Gas;   //!
  TBranch        *b_K_RichAboveElThres;   //!
  TBranch        *b_K_RichAboveMuThres;   //!
  TBranch        *b_K_RichAbovePiThres;   //!
  TBranch        *b_K_RichAboveKaThres;   //!
  TBranch        *b_K_RichAbovePrThres;   //!
  TBranch        *b_K_RichDLLe;   //!
  TBranch        *b_K_RichDLLmu;   //!
  TBranch        *b_K_RichDLLpi;   //!
  TBranch        *b_K_RichDLLk;   //!
  TBranch        *b_K_RichDLLp;   //!
  TBranch        *b_K_RichDLLbt;   //!
  TBranch        *b_K_InAccMuon;   //!
  TBranch        *b_K_isMuonLoose;   //!
  TBranch        *b_K_MuonMuLL;   //!
  TBranch        *b_K_MuonBkgLL;   //!
  TBranch        *b_K_MuonNShared;   //!
  TBranch        *b_K_InAccEcal;   //!
  TBranch        *b_K_CaloEcalE;   //!
  TBranch        *b_K_EcalPIDe;   //!
  TBranch        *b_K_EcalPIDmu;   //!
  TBranch        *b_K_InAccHcal;   //!
  TBranch        *b_K_CaloHcalE;   //!
  TBranch        *b_K_HcalPIDe;   //!
  TBranch        *b_K_HcalPIDmu;   //!
  TBranch        *b_K_InAccPrs;   //!
  TBranch        *b_K_PrsPIDe;   //!
  TBranch        *b_K_CaloPrsE;   //!
  TBranch        *b_K_InAccSpd;   //!
  TBranch        *b_K_CaloSpdE;   //!
  TBranch        *b_K_InAccBrem;   //!
  TBranch        *b_K_BremPIDe;   //!
  TBranch        *b_K_VeloCharge;   //!
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
  TBranch        *b_Pd_TRUEID;   //!
  TBranch        *b_Pd_MC_MOTHER_ID;   //!
  TBranch        *b_Pd_MC_MOTHER_KEY;   //!
  TBranch        *b_Pd_MC_GD_MOTHER_ID;   //!
  TBranch        *b_Pd_MC_GD_MOTHER_KEY;   //!
  TBranch        *b_Pd_MC_GD_GD_MOTHER_ID;   //!
  TBranch        *b_Pd_MC_GD_GD_MOTHER_KEY;   //!
  TBranch        *b_Pd_TRUEP_E;   //!
  TBranch        *b_Pd_TRUEP_X;   //!
  TBranch        *b_Pd_TRUEP_Y;   //!
  TBranch        *b_Pd_TRUEP_Z;   //!
  TBranch        *b_Pd_TRUEPT;   //!
  TBranch        *b_Pd_TRUEORIGINVERTEX_X;   //!
  TBranch        *b_Pd_TRUEORIGINVERTEX_Y;   //!
  TBranch        *b_Pd_TRUEORIGINVERTEX_Z;   //!
  TBranch        *b_Pd_TRUEENDVERTEX_X;   //!
  TBranch        *b_Pd_TRUEENDVERTEX_Y;   //!
  TBranch        *b_Pd_TRUEENDVERTEX_Z;   //!
  TBranch        *b_Pd_TRUEISSTABLE;   //!
  TBranch        *b_Pd_TRUETAU;   //!
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
  TBranch        *b_Pd_UsedRichAerogel;   //!
  TBranch        *b_Pd_UsedRich1Gas;   //!
  TBranch        *b_Pd_UsedRich2Gas;   //!
  TBranch        *b_Pd_RichAboveElThres;   //!
  TBranch        *b_Pd_RichAboveMuThres;   //!
  TBranch        *b_Pd_RichAbovePiThres;   //!
  TBranch        *b_Pd_RichAboveKaThres;   //!
  TBranch        *b_Pd_RichAbovePrThres;   //!
  TBranch        *b_Pd_RichDLLe;   //!
  TBranch        *b_Pd_RichDLLmu;   //!
  TBranch        *b_Pd_RichDLLpi;   //!
  TBranch        *b_Pd_RichDLLk;   //!
  TBranch        *b_Pd_RichDLLp;   //!
  TBranch        *b_Pd_RichDLLbt;   //!
  TBranch        *b_Pd_InAccMuon;   //!
  TBranch        *b_Pd_isMuonLoose;   //!
  TBranch        *b_Pd_MuonMuLL;   //!
  TBranch        *b_Pd_MuonBkgLL;   //!
  TBranch        *b_Pd_MuonNShared;   //!
  TBranch        *b_Pd_InAccEcal;   //!
  TBranch        *b_Pd_CaloEcalE;   //!
  TBranch        *b_Pd_EcalPIDe;   //!
  TBranch        *b_Pd_EcalPIDmu;   //!
  TBranch        *b_Pd_InAccHcal;   //!
  TBranch        *b_Pd_CaloHcalE;   //!
  TBranch        *b_Pd_HcalPIDe;   //!
  TBranch        *b_Pd_HcalPIDmu;   //!
  TBranch        *b_Pd_InAccPrs;   //!
  TBranch        *b_Pd_PrsPIDe;   //!
  TBranch        *b_Pd_CaloPrsE;   //!
  TBranch        *b_Pd_InAccSpd;   //!
  TBranch        *b_Pd_CaloSpdE;   //!
  TBranch        *b_Pd_InAccBrem;   //!
  TBranch        *b_Pd_BremPIDe;   //!
  TBranch        *b_Pd_VeloCharge;   //!
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
  TBranch        *b_Ps_TRUEID;   //!
  TBranch        *b_Ps_MC_MOTHER_ID;   //!
  TBranch        *b_Ps_MC_MOTHER_KEY;   //!
  TBranch        *b_Ps_MC_GD_MOTHER_ID;   //!
  TBranch        *b_Ps_MC_GD_MOTHER_KEY;   //!
  TBranch        *b_Ps_MC_GD_GD_MOTHER_ID;   //!
  TBranch        *b_Ps_MC_GD_GD_MOTHER_KEY;   //!
  TBranch        *b_Ps_TRUEP_E;   //!
  TBranch        *b_Ps_TRUEP_X;   //!
  TBranch        *b_Ps_TRUEP_Y;   //!
  TBranch        *b_Ps_TRUEP_Z;   //!
  TBranch        *b_Ps_TRUEPT;   //!
  TBranch        *b_Ps_TRUEORIGINVERTEX_X;   //!
  TBranch        *b_Ps_TRUEORIGINVERTEX_Y;   //!
  TBranch        *b_Ps_TRUEORIGINVERTEX_Z;   //!
  TBranch        *b_Ps_TRUEENDVERTEX_X;   //!
  TBranch        *b_Ps_TRUEENDVERTEX_Y;   //!
  TBranch        *b_Ps_TRUEENDVERTEX_Z;   //!
  TBranch        *b_Ps_TRUEISSTABLE;   //!
  TBranch        *b_Ps_TRUETAU;   //!
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
  TBranch        *b_Ps_UsedRichAerogel;   //!
  TBranch        *b_Ps_UsedRich1Gas;   //!
  TBranch        *b_Ps_UsedRich2Gas;   //!
  TBranch        *b_Ps_RichAboveElThres;   //!
  TBranch        *b_Ps_RichAboveMuThres;   //!
  TBranch        *b_Ps_RichAbovePiThres;   //!
  TBranch        *b_Ps_RichAboveKaThres;   //!
  TBranch        *b_Ps_RichAbovePrThres;   //!
  TBranch        *b_Ps_RichDLLe;   //!
  TBranch        *b_Ps_RichDLLmu;   //!
  TBranch        *b_Ps_RichDLLpi;   //!
  TBranch        *b_Ps_RichDLLk;   //!
  TBranch        *b_Ps_RichDLLp;   //!
  TBranch        *b_Ps_RichDLLbt;   //!
  TBranch        *b_Ps_InAccMuon;   //!
  TBranch        *b_Ps_isMuonLoose;   //!
  TBranch        *b_Ps_MuonMuLL;   //!
  TBranch        *b_Ps_MuonBkgLL;   //!
  TBranch        *b_Ps_MuonNShared;   //!
  TBranch        *b_Ps_InAccEcal;   //!
  TBranch        *b_Ps_CaloEcalE;   //!
  TBranch        *b_Ps_EcalPIDe;   //!
  TBranch        *b_Ps_EcalPIDmu;   //!
  TBranch        *b_Ps_InAccHcal;   //!
  TBranch        *b_Ps_CaloHcalE;   //!
  TBranch        *b_Ps_HcalPIDe;   //!
  TBranch        *b_Ps_HcalPIDmu;   //!
  TBranch        *b_Ps_InAccPrs;   //!
  TBranch        *b_Ps_PrsPIDe;   //!
  TBranch        *b_Ps_CaloPrsE;   //!
  TBranch        *b_Ps_InAccSpd;   //!
  TBranch        *b_Ps_CaloSpdE;   //!
  TBranch        *b_Ps_InAccBrem;   //!
  TBranch        *b_Ps_BremPIDe;   //!
  TBranch        *b_Ps_VeloCharge;   //!
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
  TBranch        *b_Mu_TRUEID;   //!
  TBranch        *b_Mu_MC_MOTHER_ID;   //!
  TBranch        *b_Mu_MC_MOTHER_KEY;   //!
  TBranch        *b_Mu_MC_GD_MOTHER_ID;   //!
  TBranch        *b_Mu_MC_GD_MOTHER_KEY;   //!
  TBranch        *b_Mu_MC_GD_GD_MOTHER_ID;   //!
  TBranch        *b_Mu_MC_GD_GD_MOTHER_KEY;   //!
  TBranch        *b_Mu_TRUEP_E;   //!
  TBranch        *b_Mu_TRUEP_X;   //!
  TBranch        *b_Mu_TRUEP_Y;   //!
  TBranch        *b_Mu_TRUEP_Z;   //!
  TBranch        *b_Mu_TRUEPT;   //!
  TBranch        *b_Mu_TRUEORIGINVERTEX_X;   //!
  TBranch        *b_Mu_TRUEORIGINVERTEX_Y;   //!
  TBranch        *b_Mu_TRUEORIGINVERTEX_Z;   //!
  TBranch        *b_Mu_TRUEENDVERTEX_X;   //!
  TBranch        *b_Mu_TRUEENDVERTEX_Y;   //!
  TBranch        *b_Mu_TRUEENDVERTEX_Z;   //!
  TBranch        *b_Mu_TRUEISSTABLE;   //!
  TBranch        *b_Mu_TRUETAU;   //!
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
  TBranch        *b_Mu_UsedRichAerogel;   //!
  TBranch        *b_Mu_UsedRich1Gas;   //!
  TBranch        *b_Mu_UsedRich2Gas;   //!
  TBranch        *b_Mu_RichAboveElThres;   //!
  TBranch        *b_Mu_RichAboveMuThres;   //!
  TBranch        *b_Mu_RichAbovePiThres;   //!
  TBranch        *b_Mu_RichAboveKaThres;   //!
  TBranch        *b_Mu_RichAbovePrThres;   //!
  TBranch        *b_Mu_RichDLLe;   //!
  TBranch        *b_Mu_RichDLLmu;   //!
  TBranch        *b_Mu_RichDLLpi;   //!
  TBranch        *b_Mu_RichDLLk;   //!
  TBranch        *b_Mu_RichDLLp;   //!
  TBranch        *b_Mu_RichDLLbt;   //!
  TBranch        *b_Mu_InAccMuon;   //!
  TBranch        *b_Mu_isMuonLoose;   //!
  TBranch        *b_Mu_MuonMuLL;   //!
  TBranch        *b_Mu_MuonBkgLL;   //!
  TBranch        *b_Mu_MuonNShared;   //!
  TBranch        *b_Mu_InAccEcal;   //!
  TBranch        *b_Mu_CaloEcalE;   //!
  TBranch        *b_Mu_EcalPIDe;   //!
  TBranch        *b_Mu_EcalPIDmu;   //!
  TBranch        *b_Mu_InAccHcal;   //!
  TBranch        *b_Mu_CaloHcalE;   //!
  TBranch        *b_Mu_HcalPIDe;   //!
  TBranch        *b_Mu_HcalPIDmu;   //!
  TBranch        *b_Mu_InAccPrs;   //!
  TBranch        *b_Mu_PrsPIDe;   //!
  TBranch        *b_Mu_CaloPrsE;   //!
  TBranch        *b_Mu_InAccSpd;   //!
  TBranch        *b_Mu_CaloSpdE;   //!
  TBranch        *b_Mu_InAccBrem;   //!
  TBranch        *b_Mu_BremPIDe;   //!
  TBranch        *b_Mu_VeloCharge;   //!
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
  TBranch        *b_Mu_extra_mu_MC12TuneV2ProbNNmu;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV2ProbNNe;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV2ProbNNk;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV2ProbNNpi;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV2ProbNNp;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV2ProbNNghost;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV3ProbNNmu;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV3ProbNNe;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV3ProbNNk;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV3ProbNNpi;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV3ProbNNp;   //!
  TBranch        *b_Mu_extra_mu_MC12TuneV3ProbNNghost;   //!
  TBranch        *b_Mu_extra_mu_hasMuon;   //!
  TBranch        *b_Mu_extra_mu_isMuon;   //!
  TBranch        *b_Mu_extra_mu_isMuonLoose;   //!
  TBranch        *b_Mu_extra_mu_InAccMuon;   //!
  TBranch        *b_Mu_extra_mu_MuonMuLL;   //!
  TBranch        *b_Mu_extra_mu_MuonBkgLL;   //!
  TBranch        *b_Mu_extra_mu_MuonNShared;   //!
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


  TH1D* dstar_mass_resolution_plot;
  TH1D* dstar_mass_resolution_plot_decay_in_flight;
  TH1D* dstar_mass_resolution_zoom;
  TH1D* dtf_chi2_after_cuts;
  TH1D* dstar_mass_pis_decay;
  TH1D* dstar_mass_signal;
  TH2D* dstar_mass_vs_pis_endvertex_z;
  


  MC_DT_Take2(TTree *tree=0);
  virtual ~MC_DT_Take2();
  virtual Int_t    Cut(Long64_t entry);
  virtual Int_t    GetEntry(Long64_t entry);
  virtual Long64_t LoadTree(Long64_t entry);
  virtual void     Init(TTree *tree);
  virtual void     Loop();
  virtual Bool_t   Notify();
  virtual void     Show(Long64_t entry = -1);
  virtual void fitResolution();
  virtual void storeHistograms();
  
private:
  TLorentzVector k_daughter;
  TLorentzVector pi_daughter;
  TLorentzVector mu_vec;
  TLorentzVector slow_pion_vec;
  TLorentzVector pi_daughter_as_k;
  TLorentzVector k_daughter_as_pi;
  TLorentzVector mu_from_b;
  TLorentzVector extra_muon;
  TLorentzVector d0_vector;
  const double pdg_d0_m = 1864.84;// MeV
  const double pdg_dstar_m = 2010.26;// MeV
  const double pdg_kplus_m = 493.677;// MeV
  const double pdg_piplus_m = 139.57018;//MeV
  const double kpidk_cut = 2;
  const double pi_dau_pidk_cut = 2;
  const double pi_slow_pide_cut=1;
  const double pi_slow_probnnghost_cut = 0.5;
  const double dmass_cut = 24;// MeV, for |m - m_pdg|<dmass_cut
  const double dstar_mass_cut = 0.9;
  const double mu_probnnmu_cut = 0.4;
  const double kk_pipi_cut = 40;// MeV
  const double bmass_cut_hi = 5100.;// MeV
  const double bmass_cut_low =3100.;//MeV

};

#endif

#ifdef MC_DT_Take2_cxx
MC_DT_Take2::MC_DT_Take2(TTree *tree) : fChain(0) 
{
  // if parameter tree is not specified (or zero), connect the file
  // used to generate this class and read the Tree.
  if (tree == 0) {
    TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("DVTuples_signalMC_with_hierarchy.root");
    if (!f || !f->IsOpen()) {
      f = new TFile("DVTuples_signalMC_with_hierarchy.root");
    }
    TDirectory * dir = (TDirectory*)f->Get("DVTuples_signalMC_with_hierarchy.root:/RS");
    dir->GetObject("DecayTree",tree);

  }
  Init(tree);
  //init histograms
  dstar_mass_resolution_plot = new TH1D("dt_dstar_mass_res","", 200, -25,25);
  dstar_mass_resolution_plot->SetTitle(Form("#delta m(D^0#pi_{S}); #delta m(D^0#pi_{S})[MeV]; Entries / %.2f",dstar_mass_resolution_plot->GetBinWidth(1)));

  dstar_mass_resolution_plot_decay_in_flight = new TH1D("dt_dstar_mass_res_DIF","", 200, -25+pdg_dstar_m,25+pdg_dstar_m);//change this to fit the argus correctly
  dstar_mass_resolution_plot_decay_in_flight->SetTitle(Form("#delta m(D^0#pi_{S}), Decay in Flight; #delta m(D^0#pi_{S})[MeV]; Entries / %.2f",dstar_mass_resolution_plot_decay_in_flight->GetBinWidth(1)));

  dstar_mass_resolution_zoom = new TH1D("dt_dstar_mass_res_zoom","",1000,-5,5);
  dstar_mass_resolution_zoom->SetTitle(Form("#delta m(D^0#pi_{S}); #delta m(D^0#pi_{S})[MeV]; Entries / %.2f",dstar_mass_resolution_zoom->GetBinWidth(1)));
  dstar_mass_pis_decay = new TH1D("dstar_mass_pis_decay","",250,2000,2025);
  dstar_mass_pis_decay->SetTitle(Form("m(D^{0}#pi_{S}), #pi_{S} Decay;m(D^{0}#pi_{S})[MeV];Entries / %.2f",dstar_mass_pis_decay->GetBinWidth(1)));

  dstar_mass_signal = new TH1D("dstar_mass_signal","",250,2000,2025);
  dstar_mass_signal->SetTitle(Form("m(D^{0}#pi_{S}), Signal;m(D^{0}#pi_{S})[MeV];Entries / %.2f",dstar_mass_signal->GetBinWidth(1)));

  dstar_mass_vs_pis_endvertex_z = new TH2D("dstar_mass_vs_pis_endvertex_z","D^{*} mass vs #pi_{S} End Vertex Z; #pi_{S} EndVertex Z [mm]; m(D^{0}#pi_{S})[MeV]",1000,0.,10000, 250,2000,2025);
  
}

MC_DT_Take2::~MC_DT_Take2()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t MC_DT_Take2::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}
Long64_t MC_DT_Take2::LoadTree(Long64_t entry)
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

void MC_DT_Take2::Init(TTree *tree)
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
  fChain->SetBranchAddress("B_BKGCAT", &B_BKGCAT, &b_B_BKGCAT);
  fChain->SetBranchAddress("B_TRUEID", &B_TRUEID, &b_B_TRUEID);
  fChain->SetBranchAddress("B_MC_MOTHER_ID", &B_MC_MOTHER_ID, &b_B_MC_MOTHER_ID);
  fChain->SetBranchAddress("B_MC_MOTHER_KEY", &B_MC_MOTHER_KEY, &b_B_MC_MOTHER_KEY);
  fChain->SetBranchAddress("B_MC_GD_MOTHER_ID", &B_MC_GD_MOTHER_ID, &b_B_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("B_MC_GD_MOTHER_KEY", &B_MC_GD_MOTHER_KEY, &b_B_MC_GD_MOTHER_KEY);
  fChain->SetBranchAddress("B_MC_GD_GD_MOTHER_ID", &B_MC_GD_GD_MOTHER_ID, &b_B_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("B_MC_GD_GD_MOTHER_KEY", &B_MC_GD_GD_MOTHER_KEY, &b_B_MC_GD_GD_MOTHER_KEY);
  fChain->SetBranchAddress("B_TRUEP_E", &B_TRUEP_E, &b_B_TRUEP_E);
  fChain->SetBranchAddress("B_TRUEP_X", &B_TRUEP_X, &b_B_TRUEP_X);
  fChain->SetBranchAddress("B_TRUEP_Y", &B_TRUEP_Y, &b_B_TRUEP_Y);
  fChain->SetBranchAddress("B_TRUEP_Z", &B_TRUEP_Z, &b_B_TRUEP_Z);
  fChain->SetBranchAddress("B_TRUEPT", &B_TRUEPT, &b_B_TRUEPT);
  fChain->SetBranchAddress("B_TRUEORIGINVERTEX_X", &B_TRUEORIGINVERTEX_X, &b_B_TRUEORIGINVERTEX_X);
  fChain->SetBranchAddress("B_TRUEORIGINVERTEX_Y", &B_TRUEORIGINVERTEX_Y, &b_B_TRUEORIGINVERTEX_Y);
  fChain->SetBranchAddress("B_TRUEORIGINVERTEX_Z", &B_TRUEORIGINVERTEX_Z, &b_B_TRUEORIGINVERTEX_Z);
  fChain->SetBranchAddress("B_TRUEENDVERTEX_X", &B_TRUEENDVERTEX_X, &b_B_TRUEENDVERTEX_X);
  fChain->SetBranchAddress("B_TRUEENDVERTEX_Y", &B_TRUEENDVERTEX_Y, &b_B_TRUEENDVERTEX_Y);
  fChain->SetBranchAddress("B_TRUEENDVERTEX_Z", &B_TRUEENDVERTEX_Z, &b_B_TRUEENDVERTEX_Z);
  fChain->SetBranchAddress("B_TRUEISSTABLE", &B_TRUEISSTABLE, &b_B_TRUEISSTABLE);
  fChain->SetBranchAddress("B_TRUETAU", &B_TRUETAU, &b_B_TRUETAU);
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
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_decayLength", B_VFit_Dst_2010_plus_decayLength, &b_B_VFit_Dst_2010_plus_decayLength);
  fChain->SetBranchAddress("B_VFit_Dst_2010_plus_decayLengthErr", B_VFit_Dst_2010_plus_decayLengthErr, &b_B_VFit_Dst_2010_plus_decayLengthErr);
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
  fChain->SetBranchAddress("B_Hlt2TopoMu4BodyBBDTDecision_Dec", &B_Hlt2TopoMu4BodyBBDTDecision_Dec, &b_B_Hlt2TopoMu4BodyBBDTDecision_Dec);
  fChain->SetBranchAddress("B_Hlt2TopoMu4BodyBBDTDecision_TIS", &B_Hlt2TopoMu4BodyBBDTDecision_TIS, &b_B_Hlt2TopoMu4BodyBBDTDecision_TIS);
  fChain->SetBranchAddress("B_Hlt2TopoMu4BodyBBDTDecision_TOS", &B_Hlt2TopoMu4BodyBBDTDecision_TOS, &b_B_Hlt2TopoMu4BodyBBDTDecision_TOS);
  fChain->SetBranchAddress("B_Hlt2TopoMu3BodyBBDTDecision_Dec", &B_Hlt2TopoMu3BodyBBDTDecision_Dec, &b_B_Hlt2TopoMu3BodyBBDTDecision_Dec);
  fChain->SetBranchAddress("B_Hlt2TopoMu3BodyBBDTDecision_TIS", &B_Hlt2TopoMu3BodyBBDTDecision_TIS, &b_B_Hlt2TopoMu3BodyBBDTDecision_TIS);
  fChain->SetBranchAddress("B_Hlt2TopoMu3BodyBBDTDecision_TOS", &B_Hlt2TopoMu3BodyBBDTDecision_TOS, &b_B_Hlt2TopoMu3BodyBBDTDecision_TOS);
  fChain->SetBranchAddress("B_Hlt2TopoMu2BodyBBDTDecision_Dec", &B_Hlt2TopoMu2BodyBBDTDecision_Dec, &b_B_Hlt2TopoMu2BodyBBDTDecision_Dec);
  fChain->SetBranchAddress("B_Hlt2TopoMu2BodyBBDTDecision_TIS", &B_Hlt2TopoMu2BodyBBDTDecision_TIS, &b_B_Hlt2TopoMu2BodyBBDTDecision_TIS);
  fChain->SetBranchAddress("B_Hlt2TopoMu2BodyBBDTDecision_TOS", &B_Hlt2TopoMu2BodyBBDTDecision_TOS, &b_B_Hlt2TopoMu2BodyBBDTDecision_TOS);
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
  fChain->SetBranchAddress("Dstar_BKGCAT", &Dstar_BKGCAT, &b_Dstar_BKGCAT);
  fChain->SetBranchAddress("Dstar_TRUEID", &Dstar_TRUEID, &b_Dstar_TRUEID);
  fChain->SetBranchAddress("Dstar_MC_MOTHER_ID", &Dstar_MC_MOTHER_ID, &b_Dstar_MC_MOTHER_ID);
  fChain->SetBranchAddress("Dstar_MC_MOTHER_KEY", &Dstar_MC_MOTHER_KEY, &b_Dstar_MC_MOTHER_KEY);
  fChain->SetBranchAddress("Dstar_MC_GD_MOTHER_ID", &Dstar_MC_GD_MOTHER_ID, &b_Dstar_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("Dstar_MC_GD_MOTHER_KEY", &Dstar_MC_GD_MOTHER_KEY, &b_Dstar_MC_GD_MOTHER_KEY);
  fChain->SetBranchAddress("Dstar_MC_GD_GD_MOTHER_ID", &Dstar_MC_GD_GD_MOTHER_ID, &b_Dstar_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("Dstar_MC_GD_GD_MOTHER_KEY", &Dstar_MC_GD_GD_MOTHER_KEY, &b_Dstar_MC_GD_GD_MOTHER_KEY);
  fChain->SetBranchAddress("Dstar_TRUEP_E", &Dstar_TRUEP_E, &b_Dstar_TRUEP_E);
  fChain->SetBranchAddress("Dstar_TRUEP_X", &Dstar_TRUEP_X, &b_Dstar_TRUEP_X);
  fChain->SetBranchAddress("Dstar_TRUEP_Y", &Dstar_TRUEP_Y, &b_Dstar_TRUEP_Y);
  fChain->SetBranchAddress("Dstar_TRUEP_Z", &Dstar_TRUEP_Z, &b_Dstar_TRUEP_Z);
  fChain->SetBranchAddress("Dstar_TRUEPT", &Dstar_TRUEPT, &b_Dstar_TRUEPT);
  fChain->SetBranchAddress("Dstar_TRUEORIGINVERTEX_X", &Dstar_TRUEORIGINVERTEX_X, &b_Dstar_TRUEORIGINVERTEX_X);
  fChain->SetBranchAddress("Dstar_TRUEORIGINVERTEX_Y", &Dstar_TRUEORIGINVERTEX_Y, &b_Dstar_TRUEORIGINVERTEX_Y);
  fChain->SetBranchAddress("Dstar_TRUEORIGINVERTEX_Z", &Dstar_TRUEORIGINVERTEX_Z, &b_Dstar_TRUEORIGINVERTEX_Z);
  fChain->SetBranchAddress("Dstar_TRUEENDVERTEX_X", &Dstar_TRUEENDVERTEX_X, &b_Dstar_TRUEENDVERTEX_X);
  fChain->SetBranchAddress("Dstar_TRUEENDVERTEX_Y", &Dstar_TRUEENDVERTEX_Y, &b_Dstar_TRUEENDVERTEX_Y);
  fChain->SetBranchAddress("Dstar_TRUEENDVERTEX_Z", &Dstar_TRUEENDVERTEX_Z, &b_Dstar_TRUEENDVERTEX_Z);
  fChain->SetBranchAddress("Dstar_TRUEISSTABLE", &Dstar_TRUEISSTABLE, &b_Dstar_TRUEISSTABLE);
  fChain->SetBranchAddress("Dstar_TRUETAU", &Dstar_TRUETAU, &b_Dstar_TRUETAU);
  fChain->SetBranchAddress("Dstar_ID", &Dstar_ID, &b_Dstar_ID);
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
  fChain->SetBranchAddress("Dstar_Hlt1TrackAllL0Decision_Dec", &Dstar_Hlt1TrackAllL0Decision_Dec, &b_Dstar_Hlt1TrackAllL0Decision_Dec);
  fChain->SetBranchAddress("Dstar_Hlt1TrackAllL0Decision_TIS", &Dstar_Hlt1TrackAllL0Decision_TIS, &b_Dstar_Hlt1TrackAllL0Decision_TIS);
  fChain->SetBranchAddress("Dstar_Hlt1TrackAllL0Decision_TOS", &Dstar_Hlt1TrackAllL0Decision_TOS, &b_Dstar_Hlt1TrackAllL0Decision_TOS);
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
  fChain->SetBranchAddress("D_BKGCAT", &D_BKGCAT, &b_D_BKGCAT);
  fChain->SetBranchAddress("D_TRUEID", &D_TRUEID, &b_D_TRUEID);
  fChain->SetBranchAddress("D_MC_MOTHER_ID", &D_MC_MOTHER_ID, &b_D_MC_MOTHER_ID);
  fChain->SetBranchAddress("D_MC_MOTHER_KEY", &D_MC_MOTHER_KEY, &b_D_MC_MOTHER_KEY);
  fChain->SetBranchAddress("D_MC_GD_MOTHER_ID", &D_MC_GD_MOTHER_ID, &b_D_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("D_MC_GD_MOTHER_KEY", &D_MC_GD_MOTHER_KEY, &b_D_MC_GD_MOTHER_KEY);
  fChain->SetBranchAddress("D_MC_GD_GD_MOTHER_ID", &D_MC_GD_GD_MOTHER_ID, &b_D_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("D_MC_GD_GD_MOTHER_KEY", &D_MC_GD_GD_MOTHER_KEY, &b_D_MC_GD_GD_MOTHER_KEY);
  fChain->SetBranchAddress("D_TRUEP_E", &D_TRUEP_E, &b_D_TRUEP_E);
  fChain->SetBranchAddress("D_TRUEP_X", &D_TRUEP_X, &b_D_TRUEP_X);
  fChain->SetBranchAddress("D_TRUEP_Y", &D_TRUEP_Y, &b_D_TRUEP_Y);
  fChain->SetBranchAddress("D_TRUEP_Z", &D_TRUEP_Z, &b_D_TRUEP_Z);
  fChain->SetBranchAddress("D_TRUEPT", &D_TRUEPT, &b_D_TRUEPT);
  fChain->SetBranchAddress("D_TRUEORIGINVERTEX_X", &D_TRUEORIGINVERTEX_X, &b_D_TRUEORIGINVERTEX_X);
  fChain->SetBranchAddress("D_TRUEORIGINVERTEX_Y", &D_TRUEORIGINVERTEX_Y, &b_D_TRUEORIGINVERTEX_Y);
  fChain->SetBranchAddress("D_TRUEORIGINVERTEX_Z", &D_TRUEORIGINVERTEX_Z, &b_D_TRUEORIGINVERTEX_Z);
  fChain->SetBranchAddress("D_TRUEENDVERTEX_X", &D_TRUEENDVERTEX_X, &b_D_TRUEENDVERTEX_X);
  fChain->SetBranchAddress("D_TRUEENDVERTEX_Y", &D_TRUEENDVERTEX_Y, &b_D_TRUEENDVERTEX_Y);
  fChain->SetBranchAddress("D_TRUEENDVERTEX_Z", &D_TRUEENDVERTEX_Z, &b_D_TRUEENDVERTEX_Z);
  fChain->SetBranchAddress("D_TRUEISSTABLE", &D_TRUEISSTABLE, &b_D_TRUEISSTABLE);
  fChain->SetBranchAddress("D_TRUETAU", &D_TRUETAU, &b_D_TRUETAU);
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
  fChain->SetBranchAddress("K_TRUEID", &K_TRUEID, &b_K_TRUEID);
  fChain->SetBranchAddress("K_MC_MOTHER_ID", &K_MC_MOTHER_ID, &b_K_MC_MOTHER_ID);
  fChain->SetBranchAddress("K_MC_MOTHER_KEY", &K_MC_MOTHER_KEY, &b_K_MC_MOTHER_KEY);
  fChain->SetBranchAddress("K_MC_GD_MOTHER_ID", &K_MC_GD_MOTHER_ID, &b_K_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("K_MC_GD_MOTHER_KEY", &K_MC_GD_MOTHER_KEY, &b_K_MC_GD_MOTHER_KEY);
  fChain->SetBranchAddress("K_MC_GD_GD_MOTHER_ID", &K_MC_GD_GD_MOTHER_ID, &b_K_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("K_MC_GD_GD_MOTHER_KEY", &K_MC_GD_GD_MOTHER_KEY, &b_K_MC_GD_GD_MOTHER_KEY);
  fChain->SetBranchAddress("K_TRUEP_E", &K_TRUEP_E, &b_K_TRUEP_E);
  fChain->SetBranchAddress("K_TRUEP_X", &K_TRUEP_X, &b_K_TRUEP_X);
  fChain->SetBranchAddress("K_TRUEP_Y", &K_TRUEP_Y, &b_K_TRUEP_Y);
  fChain->SetBranchAddress("K_TRUEP_Z", &K_TRUEP_Z, &b_K_TRUEP_Z);
  fChain->SetBranchAddress("K_TRUEPT", &K_TRUEPT, &b_K_TRUEPT);
  fChain->SetBranchAddress("K_TRUEORIGINVERTEX_X", &K_TRUEORIGINVERTEX_X, &b_K_TRUEORIGINVERTEX_X);
  fChain->SetBranchAddress("K_TRUEORIGINVERTEX_Y", &K_TRUEORIGINVERTEX_Y, &b_K_TRUEORIGINVERTEX_Y);
  fChain->SetBranchAddress("K_TRUEORIGINVERTEX_Z", &K_TRUEORIGINVERTEX_Z, &b_K_TRUEORIGINVERTEX_Z);
  fChain->SetBranchAddress("K_TRUEENDVERTEX_X", &K_TRUEENDVERTEX_X, &b_K_TRUEENDVERTEX_X);
  fChain->SetBranchAddress("K_TRUEENDVERTEX_Y", &K_TRUEENDVERTEX_Y, &b_K_TRUEENDVERTEX_Y);
  fChain->SetBranchAddress("K_TRUEENDVERTEX_Z", &K_TRUEENDVERTEX_Z, &b_K_TRUEENDVERTEX_Z);
  fChain->SetBranchAddress("K_TRUEISSTABLE", &K_TRUEISSTABLE, &b_K_TRUEISSTABLE);
  fChain->SetBranchAddress("K_TRUETAU", &K_TRUETAU, &b_K_TRUETAU);
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
  fChain->SetBranchAddress("K_UsedRichAerogel", &K_UsedRichAerogel, &b_K_UsedRichAerogel);
  fChain->SetBranchAddress("K_UsedRich1Gas", &K_UsedRich1Gas, &b_K_UsedRich1Gas);
  fChain->SetBranchAddress("K_UsedRich2Gas", &K_UsedRich2Gas, &b_K_UsedRich2Gas);
  fChain->SetBranchAddress("K_RichAboveElThres", &K_RichAboveElThres, &b_K_RichAboveElThres);
  fChain->SetBranchAddress("K_RichAboveMuThres", &K_RichAboveMuThres, &b_K_RichAboveMuThres);
  fChain->SetBranchAddress("K_RichAbovePiThres", &K_RichAbovePiThres, &b_K_RichAbovePiThres);
  fChain->SetBranchAddress("K_RichAboveKaThres", &K_RichAboveKaThres, &b_K_RichAboveKaThres);
  fChain->SetBranchAddress("K_RichAbovePrThres", &K_RichAbovePrThres, &b_K_RichAbovePrThres);
  fChain->SetBranchAddress("K_RichDLLe", &K_RichDLLe, &b_K_RichDLLe);
  fChain->SetBranchAddress("K_RichDLLmu", &K_RichDLLmu, &b_K_RichDLLmu);
  fChain->SetBranchAddress("K_RichDLLpi", &K_RichDLLpi, &b_K_RichDLLpi);
  fChain->SetBranchAddress("K_RichDLLk", &K_RichDLLk, &b_K_RichDLLk);
  fChain->SetBranchAddress("K_RichDLLp", &K_RichDLLp, &b_K_RichDLLp);
  fChain->SetBranchAddress("K_RichDLLbt", &K_RichDLLbt, &b_K_RichDLLbt);
  fChain->SetBranchAddress("K_InAccMuon", &K_InAccMuon, &b_K_InAccMuon);
  fChain->SetBranchAddress("K_isMuonLoose", &K_isMuonLoose, &b_K_isMuonLoose);
  fChain->SetBranchAddress("K_MuonMuLL", &K_MuonMuLL, &b_K_MuonMuLL);
  fChain->SetBranchAddress("K_MuonBkgLL", &K_MuonBkgLL, &b_K_MuonBkgLL);
  fChain->SetBranchAddress("K_MuonNShared", &K_MuonNShared, &b_K_MuonNShared);
  fChain->SetBranchAddress("K_InAccEcal", &K_InAccEcal, &b_K_InAccEcal);
  fChain->SetBranchAddress("K_CaloEcalE", &K_CaloEcalE, &b_K_CaloEcalE);
  fChain->SetBranchAddress("K_EcalPIDe", &K_EcalPIDe, &b_K_EcalPIDe);
  fChain->SetBranchAddress("K_EcalPIDmu", &K_EcalPIDmu, &b_K_EcalPIDmu);
  fChain->SetBranchAddress("K_InAccHcal", &K_InAccHcal, &b_K_InAccHcal);
  fChain->SetBranchAddress("K_CaloHcalE", &K_CaloHcalE, &b_K_CaloHcalE);
  fChain->SetBranchAddress("K_HcalPIDe", &K_HcalPIDe, &b_K_HcalPIDe);
  fChain->SetBranchAddress("K_HcalPIDmu", &K_HcalPIDmu, &b_K_HcalPIDmu);
  fChain->SetBranchAddress("K_InAccPrs", &K_InAccPrs, &b_K_InAccPrs);
  fChain->SetBranchAddress("K_PrsPIDe", &K_PrsPIDe, &b_K_PrsPIDe);
  fChain->SetBranchAddress("K_CaloPrsE", &K_CaloPrsE, &b_K_CaloPrsE);
  fChain->SetBranchAddress("K_InAccSpd", &K_InAccSpd, &b_K_InAccSpd);
  fChain->SetBranchAddress("K_CaloSpdE", &K_CaloSpdE, &b_K_CaloSpdE);
  fChain->SetBranchAddress("K_InAccBrem", &K_InAccBrem, &b_K_InAccBrem);
  fChain->SetBranchAddress("K_BremPIDe", &K_BremPIDe, &b_K_BremPIDe);
  fChain->SetBranchAddress("K_VeloCharge", &K_VeloCharge, &b_K_VeloCharge);
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
  fChain->SetBranchAddress("Pd_TRUEID", &Pd_TRUEID, &b_Pd_TRUEID);
  fChain->SetBranchAddress("Pd_MC_MOTHER_ID", &Pd_MC_MOTHER_ID, &b_Pd_MC_MOTHER_ID);
  fChain->SetBranchAddress("Pd_MC_MOTHER_KEY", &Pd_MC_MOTHER_KEY, &b_Pd_MC_MOTHER_KEY);
  fChain->SetBranchAddress("Pd_MC_GD_MOTHER_ID", &Pd_MC_GD_MOTHER_ID, &b_Pd_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("Pd_MC_GD_MOTHER_KEY", &Pd_MC_GD_MOTHER_KEY, &b_Pd_MC_GD_MOTHER_KEY);
  fChain->SetBranchAddress("Pd_MC_GD_GD_MOTHER_ID", &Pd_MC_GD_GD_MOTHER_ID, &b_Pd_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("Pd_MC_GD_GD_MOTHER_KEY", &Pd_MC_GD_GD_MOTHER_KEY, &b_Pd_MC_GD_GD_MOTHER_KEY);
  fChain->SetBranchAddress("Pd_TRUEP_E", &Pd_TRUEP_E, &b_Pd_TRUEP_E);
  fChain->SetBranchAddress("Pd_TRUEP_X", &Pd_TRUEP_X, &b_Pd_TRUEP_X);
  fChain->SetBranchAddress("Pd_TRUEP_Y", &Pd_TRUEP_Y, &b_Pd_TRUEP_Y);
  fChain->SetBranchAddress("Pd_TRUEP_Z", &Pd_TRUEP_Z, &b_Pd_TRUEP_Z);
  fChain->SetBranchAddress("Pd_TRUEPT", &Pd_TRUEPT, &b_Pd_TRUEPT);
  fChain->SetBranchAddress("Pd_TRUEORIGINVERTEX_X", &Pd_TRUEORIGINVERTEX_X, &b_Pd_TRUEORIGINVERTEX_X);
  fChain->SetBranchAddress("Pd_TRUEORIGINVERTEX_Y", &Pd_TRUEORIGINVERTEX_Y, &b_Pd_TRUEORIGINVERTEX_Y);
  fChain->SetBranchAddress("Pd_TRUEORIGINVERTEX_Z", &Pd_TRUEORIGINVERTEX_Z, &b_Pd_TRUEORIGINVERTEX_Z);
  fChain->SetBranchAddress("Pd_TRUEENDVERTEX_X", &Pd_TRUEENDVERTEX_X, &b_Pd_TRUEENDVERTEX_X);
  fChain->SetBranchAddress("Pd_TRUEENDVERTEX_Y", &Pd_TRUEENDVERTEX_Y, &b_Pd_TRUEENDVERTEX_Y);
  fChain->SetBranchAddress("Pd_TRUEENDVERTEX_Z", &Pd_TRUEENDVERTEX_Z, &b_Pd_TRUEENDVERTEX_Z);
  fChain->SetBranchAddress("Pd_TRUEISSTABLE", &Pd_TRUEISSTABLE, &b_Pd_TRUEISSTABLE);
  fChain->SetBranchAddress("Pd_TRUETAU", &Pd_TRUETAU, &b_Pd_TRUETAU);
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
  fChain->SetBranchAddress("Pd_UsedRichAerogel", &Pd_UsedRichAerogel, &b_Pd_UsedRichAerogel);
  fChain->SetBranchAddress("Pd_UsedRich1Gas", &Pd_UsedRich1Gas, &b_Pd_UsedRich1Gas);
  fChain->SetBranchAddress("Pd_UsedRich2Gas", &Pd_UsedRich2Gas, &b_Pd_UsedRich2Gas);
  fChain->SetBranchAddress("Pd_RichAboveElThres", &Pd_RichAboveElThres, &b_Pd_RichAboveElThres);
  fChain->SetBranchAddress("Pd_RichAboveMuThres", &Pd_RichAboveMuThres, &b_Pd_RichAboveMuThres);
  fChain->SetBranchAddress("Pd_RichAbovePiThres", &Pd_RichAbovePiThres, &b_Pd_RichAbovePiThres);
  fChain->SetBranchAddress("Pd_RichAboveKaThres", &Pd_RichAboveKaThres, &b_Pd_RichAboveKaThres);
  fChain->SetBranchAddress("Pd_RichAbovePrThres", &Pd_RichAbovePrThres, &b_Pd_RichAbovePrThres);
  fChain->SetBranchAddress("Pd_RichDLLe", &Pd_RichDLLe, &b_Pd_RichDLLe);
  fChain->SetBranchAddress("Pd_RichDLLmu", &Pd_RichDLLmu, &b_Pd_RichDLLmu);
  fChain->SetBranchAddress("Pd_RichDLLpi", &Pd_RichDLLpi, &b_Pd_RichDLLpi);
  fChain->SetBranchAddress("Pd_RichDLLk", &Pd_RichDLLk, &b_Pd_RichDLLk);
  fChain->SetBranchAddress("Pd_RichDLLp", &Pd_RichDLLp, &b_Pd_RichDLLp);
  fChain->SetBranchAddress("Pd_RichDLLbt", &Pd_RichDLLbt, &b_Pd_RichDLLbt);
  fChain->SetBranchAddress("Pd_InAccMuon", &Pd_InAccMuon, &b_Pd_InAccMuon);
  fChain->SetBranchAddress("Pd_isMuonLoose", &Pd_isMuonLoose, &b_Pd_isMuonLoose);
  fChain->SetBranchAddress("Pd_MuonMuLL", &Pd_MuonMuLL, &b_Pd_MuonMuLL);
  fChain->SetBranchAddress("Pd_MuonBkgLL", &Pd_MuonBkgLL, &b_Pd_MuonBkgLL);
  fChain->SetBranchAddress("Pd_MuonNShared", &Pd_MuonNShared, &b_Pd_MuonNShared);
  fChain->SetBranchAddress("Pd_InAccEcal", &Pd_InAccEcal, &b_Pd_InAccEcal);
  fChain->SetBranchAddress("Pd_CaloEcalE", &Pd_CaloEcalE, &b_Pd_CaloEcalE);
  fChain->SetBranchAddress("Pd_EcalPIDe", &Pd_EcalPIDe, &b_Pd_EcalPIDe);
  fChain->SetBranchAddress("Pd_EcalPIDmu", &Pd_EcalPIDmu, &b_Pd_EcalPIDmu);
  fChain->SetBranchAddress("Pd_InAccHcal", &Pd_InAccHcal, &b_Pd_InAccHcal);
  fChain->SetBranchAddress("Pd_CaloHcalE", &Pd_CaloHcalE, &b_Pd_CaloHcalE);
  fChain->SetBranchAddress("Pd_HcalPIDe", &Pd_HcalPIDe, &b_Pd_HcalPIDe);
  fChain->SetBranchAddress("Pd_HcalPIDmu", &Pd_HcalPIDmu, &b_Pd_HcalPIDmu);
  fChain->SetBranchAddress("Pd_InAccPrs", &Pd_InAccPrs, &b_Pd_InAccPrs);
  fChain->SetBranchAddress("Pd_PrsPIDe", &Pd_PrsPIDe, &b_Pd_PrsPIDe);
  fChain->SetBranchAddress("Pd_CaloPrsE", &Pd_CaloPrsE, &b_Pd_CaloPrsE);
  fChain->SetBranchAddress("Pd_InAccSpd", &Pd_InAccSpd, &b_Pd_InAccSpd);
  fChain->SetBranchAddress("Pd_CaloSpdE", &Pd_CaloSpdE, &b_Pd_CaloSpdE);
  fChain->SetBranchAddress("Pd_InAccBrem", &Pd_InAccBrem, &b_Pd_InAccBrem);
  fChain->SetBranchAddress("Pd_BremPIDe", &Pd_BremPIDe, &b_Pd_BremPIDe);
  fChain->SetBranchAddress("Pd_VeloCharge", &Pd_VeloCharge, &b_Pd_VeloCharge);
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
  fChain->SetBranchAddress("Ps_TRUEID", &Ps_TRUEID, &b_Ps_TRUEID);
  fChain->SetBranchAddress("Ps_MC_MOTHER_ID", &Ps_MC_MOTHER_ID, &b_Ps_MC_MOTHER_ID);
  fChain->SetBranchAddress("Ps_MC_MOTHER_KEY", &Ps_MC_MOTHER_KEY, &b_Ps_MC_MOTHER_KEY);
  fChain->SetBranchAddress("Ps_MC_GD_MOTHER_ID", &Ps_MC_GD_MOTHER_ID, &b_Ps_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("Ps_MC_GD_MOTHER_KEY", &Ps_MC_GD_MOTHER_KEY, &b_Ps_MC_GD_MOTHER_KEY);
  fChain->SetBranchAddress("Ps_MC_GD_GD_MOTHER_ID", &Ps_MC_GD_GD_MOTHER_ID, &b_Ps_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("Ps_MC_GD_GD_MOTHER_KEY", &Ps_MC_GD_GD_MOTHER_KEY, &b_Ps_MC_GD_GD_MOTHER_KEY);
  fChain->SetBranchAddress("Ps_TRUEP_E", &Ps_TRUEP_E, &b_Ps_TRUEP_E);
  fChain->SetBranchAddress("Ps_TRUEP_X", &Ps_TRUEP_X, &b_Ps_TRUEP_X);
  fChain->SetBranchAddress("Ps_TRUEP_Y", &Ps_TRUEP_Y, &b_Ps_TRUEP_Y);
  fChain->SetBranchAddress("Ps_TRUEP_Z", &Ps_TRUEP_Z, &b_Ps_TRUEP_Z);
  fChain->SetBranchAddress("Ps_TRUEPT", &Ps_TRUEPT, &b_Ps_TRUEPT);
  fChain->SetBranchAddress("Ps_TRUEORIGINVERTEX_X", &Ps_TRUEORIGINVERTEX_X, &b_Ps_TRUEORIGINVERTEX_X);
  fChain->SetBranchAddress("Ps_TRUEORIGINVERTEX_Y", &Ps_TRUEORIGINVERTEX_Y, &b_Ps_TRUEORIGINVERTEX_Y);
  fChain->SetBranchAddress("Ps_TRUEORIGINVERTEX_Z", &Ps_TRUEORIGINVERTEX_Z, &b_Ps_TRUEORIGINVERTEX_Z);
  fChain->SetBranchAddress("Ps_TRUEENDVERTEX_X", &Ps_TRUEENDVERTEX_X, &b_Ps_TRUEENDVERTEX_X);
  fChain->SetBranchAddress("Ps_TRUEENDVERTEX_Y", &Ps_TRUEENDVERTEX_Y, &b_Ps_TRUEENDVERTEX_Y);
  fChain->SetBranchAddress("Ps_TRUEENDVERTEX_Z", &Ps_TRUEENDVERTEX_Z, &b_Ps_TRUEENDVERTEX_Z);
  fChain->SetBranchAddress("Ps_TRUEISSTABLE", &Ps_TRUEISSTABLE, &b_Ps_TRUEISSTABLE);
  fChain->SetBranchAddress("Ps_TRUETAU", &Ps_TRUETAU, &b_Ps_TRUETAU);
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
  fChain->SetBranchAddress("Ps_UsedRichAerogel", &Ps_UsedRichAerogel, &b_Ps_UsedRichAerogel);
  fChain->SetBranchAddress("Ps_UsedRich1Gas", &Ps_UsedRich1Gas, &b_Ps_UsedRich1Gas);
  fChain->SetBranchAddress("Ps_UsedRich2Gas", &Ps_UsedRich2Gas, &b_Ps_UsedRich2Gas);
  fChain->SetBranchAddress("Ps_RichAboveElThres", &Ps_RichAboveElThres, &b_Ps_RichAboveElThres);
  fChain->SetBranchAddress("Ps_RichAboveMuThres", &Ps_RichAboveMuThres, &b_Ps_RichAboveMuThres);
  fChain->SetBranchAddress("Ps_RichAbovePiThres", &Ps_RichAbovePiThres, &b_Ps_RichAbovePiThres);
  fChain->SetBranchAddress("Ps_RichAboveKaThres", &Ps_RichAboveKaThres, &b_Ps_RichAboveKaThres);
  fChain->SetBranchAddress("Ps_RichAbovePrThres", &Ps_RichAbovePrThres, &b_Ps_RichAbovePrThres);
  fChain->SetBranchAddress("Ps_RichDLLe", &Ps_RichDLLe, &b_Ps_RichDLLe);
  fChain->SetBranchAddress("Ps_RichDLLmu", &Ps_RichDLLmu, &b_Ps_RichDLLmu);
  fChain->SetBranchAddress("Ps_RichDLLpi", &Ps_RichDLLpi, &b_Ps_RichDLLpi);
  fChain->SetBranchAddress("Ps_RichDLLk", &Ps_RichDLLk, &b_Ps_RichDLLk);
  fChain->SetBranchAddress("Ps_RichDLLp", &Ps_RichDLLp, &b_Ps_RichDLLp);
  fChain->SetBranchAddress("Ps_RichDLLbt", &Ps_RichDLLbt, &b_Ps_RichDLLbt);
  fChain->SetBranchAddress("Ps_InAccMuon", &Ps_InAccMuon, &b_Ps_InAccMuon);
  fChain->SetBranchAddress("Ps_isMuonLoose", &Ps_isMuonLoose, &b_Ps_isMuonLoose);
  fChain->SetBranchAddress("Ps_MuonMuLL", &Ps_MuonMuLL, &b_Ps_MuonMuLL);
  fChain->SetBranchAddress("Ps_MuonBkgLL", &Ps_MuonBkgLL, &b_Ps_MuonBkgLL);
  fChain->SetBranchAddress("Ps_MuonNShared", &Ps_MuonNShared, &b_Ps_MuonNShared);
  fChain->SetBranchAddress("Ps_InAccEcal", &Ps_InAccEcal, &b_Ps_InAccEcal);
  fChain->SetBranchAddress("Ps_CaloEcalE", &Ps_CaloEcalE, &b_Ps_CaloEcalE);
  fChain->SetBranchAddress("Ps_EcalPIDe", &Ps_EcalPIDe, &b_Ps_EcalPIDe);
  fChain->SetBranchAddress("Ps_EcalPIDmu", &Ps_EcalPIDmu, &b_Ps_EcalPIDmu);
  fChain->SetBranchAddress("Ps_InAccHcal", &Ps_InAccHcal, &b_Ps_InAccHcal);
  fChain->SetBranchAddress("Ps_CaloHcalE", &Ps_CaloHcalE, &b_Ps_CaloHcalE);
  fChain->SetBranchAddress("Ps_HcalPIDe", &Ps_HcalPIDe, &b_Ps_HcalPIDe);
  fChain->SetBranchAddress("Ps_HcalPIDmu", &Ps_HcalPIDmu, &b_Ps_HcalPIDmu);
  fChain->SetBranchAddress("Ps_InAccPrs", &Ps_InAccPrs, &b_Ps_InAccPrs);
  fChain->SetBranchAddress("Ps_PrsPIDe", &Ps_PrsPIDe, &b_Ps_PrsPIDe);
  fChain->SetBranchAddress("Ps_CaloPrsE", &Ps_CaloPrsE, &b_Ps_CaloPrsE);
  fChain->SetBranchAddress("Ps_InAccSpd", &Ps_InAccSpd, &b_Ps_InAccSpd);
  fChain->SetBranchAddress("Ps_CaloSpdE", &Ps_CaloSpdE, &b_Ps_CaloSpdE);
  fChain->SetBranchAddress("Ps_InAccBrem", &Ps_InAccBrem, &b_Ps_InAccBrem);
  fChain->SetBranchAddress("Ps_BremPIDe", &Ps_BremPIDe, &b_Ps_BremPIDe);
  fChain->SetBranchAddress("Ps_VeloCharge", &Ps_VeloCharge, &b_Ps_VeloCharge);
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
  fChain->SetBranchAddress("Mu_TRUEID", &Mu_TRUEID, &b_Mu_TRUEID);
  fChain->SetBranchAddress("Mu_MC_MOTHER_ID", &Mu_MC_MOTHER_ID, &b_Mu_MC_MOTHER_ID);
  fChain->SetBranchAddress("Mu_MC_MOTHER_KEY", &Mu_MC_MOTHER_KEY, &b_Mu_MC_MOTHER_KEY);
  fChain->SetBranchAddress("Mu_MC_GD_MOTHER_ID", &Mu_MC_GD_MOTHER_ID, &b_Mu_MC_GD_MOTHER_ID);
  fChain->SetBranchAddress("Mu_MC_GD_MOTHER_KEY", &Mu_MC_GD_MOTHER_KEY, &b_Mu_MC_GD_MOTHER_KEY);
  fChain->SetBranchAddress("Mu_MC_GD_GD_MOTHER_ID", &Mu_MC_GD_GD_MOTHER_ID, &b_Mu_MC_GD_GD_MOTHER_ID);
  fChain->SetBranchAddress("Mu_MC_GD_GD_MOTHER_KEY", &Mu_MC_GD_GD_MOTHER_KEY, &b_Mu_MC_GD_GD_MOTHER_KEY);
  fChain->SetBranchAddress("Mu_TRUEP_E", &Mu_TRUEP_E, &b_Mu_TRUEP_E);
  fChain->SetBranchAddress("Mu_TRUEP_X", &Mu_TRUEP_X, &b_Mu_TRUEP_X);
  fChain->SetBranchAddress("Mu_TRUEP_Y", &Mu_TRUEP_Y, &b_Mu_TRUEP_Y);
  fChain->SetBranchAddress("Mu_TRUEP_Z", &Mu_TRUEP_Z, &b_Mu_TRUEP_Z);
  fChain->SetBranchAddress("Mu_TRUEPT", &Mu_TRUEPT, &b_Mu_TRUEPT);
  fChain->SetBranchAddress("Mu_TRUEORIGINVERTEX_X", &Mu_TRUEORIGINVERTEX_X, &b_Mu_TRUEORIGINVERTEX_X);
  fChain->SetBranchAddress("Mu_TRUEORIGINVERTEX_Y", &Mu_TRUEORIGINVERTEX_Y, &b_Mu_TRUEORIGINVERTEX_Y);
  fChain->SetBranchAddress("Mu_TRUEORIGINVERTEX_Z", &Mu_TRUEORIGINVERTEX_Z, &b_Mu_TRUEORIGINVERTEX_Z);
  fChain->SetBranchAddress("Mu_TRUEENDVERTEX_X", &Mu_TRUEENDVERTEX_X, &b_Mu_TRUEENDVERTEX_X);
  fChain->SetBranchAddress("Mu_TRUEENDVERTEX_Y", &Mu_TRUEENDVERTEX_Y, &b_Mu_TRUEENDVERTEX_Y);
  fChain->SetBranchAddress("Mu_TRUEENDVERTEX_Z", &Mu_TRUEENDVERTEX_Z, &b_Mu_TRUEENDVERTEX_Z);
  fChain->SetBranchAddress("Mu_TRUEISSTABLE", &Mu_TRUEISSTABLE, &b_Mu_TRUEISSTABLE);
  fChain->SetBranchAddress("Mu_TRUETAU", &Mu_TRUETAU, &b_Mu_TRUETAU);
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
  fChain->SetBranchAddress("Mu_UsedRichAerogel", &Mu_UsedRichAerogel, &b_Mu_UsedRichAerogel);
  fChain->SetBranchAddress("Mu_UsedRich1Gas", &Mu_UsedRich1Gas, &b_Mu_UsedRich1Gas);
  fChain->SetBranchAddress("Mu_UsedRich2Gas", &Mu_UsedRich2Gas, &b_Mu_UsedRich2Gas);
  fChain->SetBranchAddress("Mu_RichAboveElThres", &Mu_RichAboveElThres, &b_Mu_RichAboveElThres);
  fChain->SetBranchAddress("Mu_RichAboveMuThres", &Mu_RichAboveMuThres, &b_Mu_RichAboveMuThres);
  fChain->SetBranchAddress("Mu_RichAbovePiThres", &Mu_RichAbovePiThres, &b_Mu_RichAbovePiThres);
  fChain->SetBranchAddress("Mu_RichAboveKaThres", &Mu_RichAboveKaThres, &b_Mu_RichAboveKaThres);
  fChain->SetBranchAddress("Mu_RichAbovePrThres", &Mu_RichAbovePrThres, &b_Mu_RichAbovePrThres);
  fChain->SetBranchAddress("Mu_RichDLLe", &Mu_RichDLLe, &b_Mu_RichDLLe);
  fChain->SetBranchAddress("Mu_RichDLLmu", &Mu_RichDLLmu, &b_Mu_RichDLLmu);
  fChain->SetBranchAddress("Mu_RichDLLpi", &Mu_RichDLLpi, &b_Mu_RichDLLpi);
  fChain->SetBranchAddress("Mu_RichDLLk", &Mu_RichDLLk, &b_Mu_RichDLLk);
  fChain->SetBranchAddress("Mu_RichDLLp", &Mu_RichDLLp, &b_Mu_RichDLLp);
  fChain->SetBranchAddress("Mu_RichDLLbt", &Mu_RichDLLbt, &b_Mu_RichDLLbt);
  fChain->SetBranchAddress("Mu_InAccMuon", &Mu_InAccMuon, &b_Mu_InAccMuon);
  fChain->SetBranchAddress("Mu_isMuonLoose", &Mu_isMuonLoose, &b_Mu_isMuonLoose);
  fChain->SetBranchAddress("Mu_MuonMuLL", &Mu_MuonMuLL, &b_Mu_MuonMuLL);
  fChain->SetBranchAddress("Mu_MuonBkgLL", &Mu_MuonBkgLL, &b_Mu_MuonBkgLL);
  fChain->SetBranchAddress("Mu_MuonNShared", &Mu_MuonNShared, &b_Mu_MuonNShared);
  fChain->SetBranchAddress("Mu_InAccEcal", &Mu_InAccEcal, &b_Mu_InAccEcal);
  fChain->SetBranchAddress("Mu_CaloEcalE", &Mu_CaloEcalE, &b_Mu_CaloEcalE);
  fChain->SetBranchAddress("Mu_EcalPIDe", &Mu_EcalPIDe, &b_Mu_EcalPIDe);
  fChain->SetBranchAddress("Mu_EcalPIDmu", &Mu_EcalPIDmu, &b_Mu_EcalPIDmu);
  fChain->SetBranchAddress("Mu_InAccHcal", &Mu_InAccHcal, &b_Mu_InAccHcal);
  fChain->SetBranchAddress("Mu_CaloHcalE", &Mu_CaloHcalE, &b_Mu_CaloHcalE);
  fChain->SetBranchAddress("Mu_HcalPIDe", &Mu_HcalPIDe, &b_Mu_HcalPIDe);
  fChain->SetBranchAddress("Mu_HcalPIDmu", &Mu_HcalPIDmu, &b_Mu_HcalPIDmu);
  fChain->SetBranchAddress("Mu_InAccPrs", &Mu_InAccPrs, &b_Mu_InAccPrs);
  fChain->SetBranchAddress("Mu_PrsPIDe", &Mu_PrsPIDe, &b_Mu_PrsPIDe);
  fChain->SetBranchAddress("Mu_CaloPrsE", &Mu_CaloPrsE, &b_Mu_CaloPrsE);
  fChain->SetBranchAddress("Mu_InAccSpd", &Mu_InAccSpd, &b_Mu_InAccSpd);
  fChain->SetBranchAddress("Mu_CaloSpdE", &Mu_CaloSpdE, &b_Mu_CaloSpdE);
  fChain->SetBranchAddress("Mu_InAccBrem", &Mu_InAccBrem, &b_Mu_InAccBrem);
  fChain->SetBranchAddress("Mu_BremPIDe", &Mu_BremPIDe, &b_Mu_BremPIDe);
  fChain->SetBranchAddress("Mu_VeloCharge", &Mu_VeloCharge, &b_Mu_VeloCharge);
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
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV2ProbNNmu", Mu_extra_mu_MC12TuneV2ProbNNmu, &b_Mu_extra_mu_MC12TuneV2ProbNNmu);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV2ProbNNe", Mu_extra_mu_MC12TuneV2ProbNNe, &b_Mu_extra_mu_MC12TuneV2ProbNNe);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV2ProbNNk", Mu_extra_mu_MC12TuneV2ProbNNk, &b_Mu_extra_mu_MC12TuneV2ProbNNk);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV2ProbNNpi", Mu_extra_mu_MC12TuneV2ProbNNpi, &b_Mu_extra_mu_MC12TuneV2ProbNNpi);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV2ProbNNp", Mu_extra_mu_MC12TuneV2ProbNNp, &b_Mu_extra_mu_MC12TuneV2ProbNNp);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV2ProbNNghost", Mu_extra_mu_MC12TuneV2ProbNNghost, &b_Mu_extra_mu_MC12TuneV2ProbNNghost);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV3ProbNNmu", Mu_extra_mu_MC12TuneV3ProbNNmu, &b_Mu_extra_mu_MC12TuneV3ProbNNmu);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV3ProbNNe", Mu_extra_mu_MC12TuneV3ProbNNe, &b_Mu_extra_mu_MC12TuneV3ProbNNe);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV3ProbNNk", Mu_extra_mu_MC12TuneV3ProbNNk, &b_Mu_extra_mu_MC12TuneV3ProbNNk);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV3ProbNNpi", Mu_extra_mu_MC12TuneV3ProbNNpi, &b_Mu_extra_mu_MC12TuneV3ProbNNpi);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV3ProbNNp", Mu_extra_mu_MC12TuneV3ProbNNp, &b_Mu_extra_mu_MC12TuneV3ProbNNp);
  fChain->SetBranchAddress("Mu_extra_mu_MC12TuneV3ProbNNghost", Mu_extra_mu_MC12TuneV3ProbNNghost, &b_Mu_extra_mu_MC12TuneV3ProbNNghost);
  fChain->SetBranchAddress("Mu_extra_mu_hasMuon", Mu_extra_mu_hasMuon, &b_Mu_extra_mu_hasMuon);
  fChain->SetBranchAddress("Mu_extra_mu_isMuon", Mu_extra_mu_isMuon, &b_Mu_extra_mu_isMuon);
  fChain->SetBranchAddress("Mu_extra_mu_isMuonLoose", Mu_extra_mu_isMuonLoose, &b_Mu_extra_mu_isMuonLoose);
  fChain->SetBranchAddress("Mu_extra_mu_InAccMuon", Mu_extra_mu_InAccMuon, &b_Mu_extra_mu_InAccMuon);
  fChain->SetBranchAddress("Mu_extra_mu_MuonMuLL", Mu_extra_mu_MuonMuLL, &b_Mu_extra_mu_MuonMuLL);
  fChain->SetBranchAddress("Mu_extra_mu_MuonBkgLL", Mu_extra_mu_MuonBkgLL, &b_Mu_extra_mu_MuonBkgLL);
  fChain->SetBranchAddress("Mu_extra_mu_MuonNShared", Mu_extra_mu_MuonNShared, &b_Mu_extra_mu_MuonNShared);
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

Bool_t MC_DT_Take2::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}

void MC_DT_Take2::Show(Long64_t entry)
{
  // Print contents of entry.
  // If entry is not specified, print current entry
  if (!fChain) return;
  fChain->Show(entry);
}
Int_t MC_DT_Take2::Cut(Long64_t entry)
{
  // This function may be called from Loop.
  // returns  1 if entry is accepted.
  // returns -1 otherwise.
  return 1;
}
#endif // #ifdef MC_DT_Take2_cxx
