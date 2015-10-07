//c++
#include <iostream>
#include <cmath>
//root

#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TStyle.h>

//roofit
#ifndef __CINT__
#include "RooGlobalFunc.h"
#include "RooCFunction1Binding.h"
#include "RooCFunction3Binding.h"
#endif
#include <RooWorkspace.h>

#include <PlottingTools.h>
#include "massFit.h"
using namespace RooFit ;
//external
#include "slowPionStudy.h"

int main(int argc, char* const argv[]){
  cout<<"Testing Mass Fit on External Data"<<endl;
  bool hasWorkspace=  false;
  if(argc<2){
    cout<<"*************************************"<<endl;
    cout<<"Expecting an external file to process"<<endl;
    cout<<" and possibly a workspace"<<endl;
    cout<<"*************************************"<<endl;
    return 0;
  }
  if(argc==3){
    cout<<"argv[1]="<<argv[1]<<", argv[2] = "<<argv[2]<<endl;
    hasWorkspace = true;
    //return 0;
  }
  //get the rooworkspace
  if(!hasWorkspace){
    cout<<"this should never happen!"<<endl;
    return 0;
  }
  TFile *ws_f = TFile::Open(argv[2]);
  RooWorkspace * w = (RooWorkspace*)ws_f->Get("rsw");
  //get all the fucking histograms
  TFile* hist_f = TFile::Open(argv[1]);
  std::vector<TH1D*> hpp,hpf,hnp,hnf;
  for(int i=0; i<10;++i){
    hpp.push_back((TH1D*)hist_f->Get(Form("RS_dstm_pis_ghostprob_pos_pass_%d",i+1)));
    hpf.push_back((TH1D*)hist_f->Get(Form("RS_dstm_pis_ghostprob_pos_fail_%d",i+1)));
    hnp.push_back((TH1D*)hist_f->Get(Form("RS_dstm_pis_ghostprob_neg_pass_%d",i+1)));
    hnf.push_back((TH1D*)hist_f->Get(Form("RS_dstm_pis_ghostprob_neg_fail_%d",i+1)));
  }
  slowPionStudy st("SlowPionEffBkgStudy",w);
  st.setHistogramsPositive(hpp,hpf);
  st.setHistogramsNegative(hnp,hnf);
  st.setPlotDir("./SlowPionStudy/");
  st.makeProbNNghostPlots();
  st.drawPlot();
  return 0;
}
