//c++
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
#include <TGraphAsymmErrors.h>
#include <TString.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TText.h>
#include <TLine.h>
#include "PlottingTools.h"
using namespace std;
using namespace PlottingTools;

int main(int argc, char* const argv[]){
  if(argc<2){
    cout<<"*****************************************"<<endl;
    cout<<"Code to get RS-/RS+ vs tD0 from file"<<endl;
    cout<<"-------------------------------------"<<endl;
    cout<<"Expecting a root file for the rs sample"<<endl;
    cout<<"*****************************************"<<endl;
    return 0;
  }
  double the_scaling_factor;
  std::ifstream sf_file("./theScalingFactor.txt");
  while(sf_file>>the_scaling_factor){cout<<"reading scaling factor from file"<<endl;}
  cout<<"read scaling factor "<<the_scaling_factor<<endl;
  if(!the_scaling_factor){cout<<"something terribly wrong here"<<endl;return 0;}
  sf_file.close();

  cout<<"trivial code to extract RS over RS ratio from a file"<<endl;
  int dum;
  double pos_yield[5];
  double pos_yield_err[5];
  double neg_yield[5];
  double neg_yield_err[5];
  ifstream infile_pos("./SavedFits/rs_yields_in_bins_pos");
  if(infile_pos.is_open()){
    //fix the reader
  }
  cout<<"read in positive and negative yields"<<endl;
  for(int i=0;i<5;++i){cout<<i<<"\t"<<pos_yield[i]<<" +/- "<<pos_yield_err[i]
			   <<"\t" <<neg_yield[i]<<" +/- "<<neg_yield_err[i]<<endl;
  }
  //get the mean decay time from the file
  TFile *f1 = TFile::Open(argv[1]);
  TH1D* the_td_distr  = (TH1D*)f1->Get("RS_dt_d0_decay_time_distr");
  TH1D* the_td_distr_ss  = (TH1D*)f1->Get("RS_ss_dt_d0_decay_time_distr");
  the_td_distr->Sumw2();
  the_td_distr_ss->Sumw2();
  the_td_distr->Add(the_td_distr_ss,-the_scaling_factor);
  int bins_td []= {451,521,551,591,651,the_td_distr->GetNbinsX()};
  int nbins=5;
  double mean_td_pos[nbins];
  double xLow[nbins],xHi[nbins];
  double binVal[nbins],binValErr[nbins];
  for(int i=0;i<nbins;++i){
    binVal[i]=neg_yield[i]/pos_yield[i];
    binValErr[i]=binVal[i]*TMath::Sqrt(TMath::Power(pos_yield_err[i]/pos_yield[i],2)+
				       TMath::Power(neg_yield_err[i]/neg_yield[i],2));
    the_td_distr->GetXaxis()->SetRange(bins_td[i],bins_td[i+1]);
    mean_td_pos[i] = the_td_distr->GetMean();
    the_td_distr->GetXaxis()->SetRange();
    xLow[i]=mean_td_pos[i] - the_td_distr->GetBinCenter(bins_td[i]);
    xHi[i]=the_td_distr->GetBinCenter(bins_td[i+1])-mean_td_pos[i];
  }
  TGraphAsymmErrors *thePlot = new TGraphAsymmErrors(5,mean_td_pos,binVal,xLow,xHi,binValErr,binValErr);
  thePlot->SetMarkerSize(1.5);
  thePlot->SetMarkerColor(kBlack);
  thePlot->SetLineColor(kBlack);
  thePlot->SetTitle(";D^{0}t/#tau;N(D*^{-})/N(D*^{+})");
  thePlot->SetName("rs_over_rs_ratio");
  TCanvas cc;
  thePlot->Draw("ap");
  cc.SaveAs("SavedFits/rs_over_rs_from_file_plot.pdf");
  thePlot->Fit("pol0");
  gStyle->SetOptFit(111111);
  cc.Update();
  cc.SaveAs("SavedFits/rs_over_rs_from_file_plot_fitted.pdf");
  TFile *fout = new TFile("SavedFits/rs_over_rs_from_file.root","RECREATE");
  fout->cd();
  thePlot->Write();
  fout->Close();
  return 0;
  
}
