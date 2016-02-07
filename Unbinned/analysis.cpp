//c++
#include <iostream>
#include <cmath>
#include <stdlib.h>//for validation files getenv.
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
#include <TRandom3.h>
#include <TString.h>
#include <TFile.h>
#include <TObject.h>
#include <TTree.h>
#include <TCut.h>
#include <THStack.h>
#include <TLegend.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TLeaf.h>
#include <TProfile2D.h>
#include <TChain.h>
#include <TPaveStats.h>
#include <TArrow.h>
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TText.h>

//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
#endif
#include <RooFitResult.h>
#include <RooRealVar.h>
#include <RooDataSet.h>
#include <RooGaussian.h>
#include <RooChebychev.h>
#include <RooPolynomial.h>
#include <RooArgusBG.h>
#include <RooAddPdf.h>
#include <RooPlot.h>
#include <RooHist.h>
#include <RooDataHist.h>
#include <RooExponential.h>
#include <RooBinning.h>
#include <RooDstD0BG.h>
#include <RooNLLVar.h>

// local

#include "DT_D0_mix_CPV.h"
#include "massFit.h"
#include "WrongB.h"
//#include "PlottingTools.h"
using namespace std;

void getLuminosity(TTree* the_lumi_tree){
  Float_t totLumi = 0.0;
  Float_t totLumiErr = 0.0;

    int entries = the_lumi_tree->GetEntries();
    for(int i=0; i<entries;++i){
      the_lumi_tree->GetEntry(i);
      totLumi+=the_lumi_tree->GetLeaf("IntegratedLuminosity")->GetValue();
      totLumiErr+=the_lumi_tree->GetLeaf("IntegratedLuminosityErr")->GetValue();
    }
    //cout<<"for OS tuple,"<<endl;

  printf(" Total Luminosity      : %.5f pb-1 +/- %.5f pb-1\n", totLumi, totLumiErr);
}



int main(int argc, char* const argv[]){
  cout<<"this is a test"<<endl;

  if(argc<2){
    cout<<"*************************************"<<endl;
    cout<<"Expecting a file or files to process"<<endl;
    cout<<"*************************************"<<endl;
    return 0;
  }
  cout<<"Starting analysis for file "<<argv[1]<<endl;
  TChain* rs_tree = new TChain("RS/DecayTree");
  TChain* rs_ss_tree = new TChain("RS_ss/DecayTree");
  TChain* ws_tree = new TChain("WS/DecayTree");
  TChain* ws_ss_tree = new TChain("WS_ss/DecayTree");
  TChain* lumi_tree = new TChain("GetIntegratedLuminosity/LumiTuple");
  TString  rootfname[argc];
  for(int i=0; i< argc-1; ++i){
    rootfname[i]=argv[i+1];
    rs_tree->Add(rootfname[i]);
    rs_ss_tree->Add(rootfname[i]);
    ws_tree->Add(rootfname[i]);
    ws_ss_tree->Add(rootfname[i]);
    lumi_tree->Add(rootfname[i]);
  }
  getLuminosity(lumi_tree);
  cout<<"rs tree"<<endl;
  char* dt_prompt_match_path_char = getenv("DTPROMPTLISTS");
  if(dt_prompt_match_path_char==NULL){
    cout<<"couldn't get the path to the validation files for removing prompt events"<<endl;
    return 0;
  }
  TString dt_prompt_match_path(dt_prompt_match_path_char);
  cout<<"Using DT Prompt Matching Path "<<dt_prompt_match_path<<endl;

  DT_D0_mix_CPV rs_looper(rs_tree);
  rs_looper.setRejectionFile(dt_prompt_match_path+"/cuts_forMD_2012.txt");
  rs_looper.setRejectionFile(dt_prompt_match_path+"/cuts_forMU_2012.txt");
  rs_looper.setRejectionFile(dt_prompt_match_path+"/cuts_forMD_2011.txt");
  rs_looper.setRejectionFile(dt_prompt_match_path+"/cuts_forMU_2011.txt");
  rs_looper.Loop();
  //  rs_looper.bs_plot->SavePlots();
  cout<<"rs ss tree"<<endl;
  
  DT_D0_mix_CPV rs_ss_looper(rs_ss_tree);
  rs_ss_looper.Loop();
  //rs_ss_looper.bs_plot->SavePlots();
  cout<<"ws tree"<<endl;
  DT_D0_mix_CPV ws_looper(ws_tree);
  ws_looper.Loop();
  //ws_looper.bs_plot->SavePlots();
  cout<<"ws ss tree"<<endl;
  
  DT_D0_mix_CPV ws_ss_looper(ws_ss_tree);
  ws_ss_looper.Loop();
  //ws_ss_looper.bs_plot->SavePlots();

  


  return 0;
}
