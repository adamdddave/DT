//the necessity
#include "TimeDependent2D.h"
//c++
#include <iostream>

#include <cmath>
#include <string>

//root
#include <TH1.h>
#include <TH2.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TString.h>
#include <TLegend.h>
#include <THStack.h>

using namespace std;
TimeDependent2D::TimeDependent2D(TString histName, TFile *f1, TString saveName, std::vector<int> slices){
  mName = histName;
  std::vector<int>slices_local = slices;
  mSaveName = "./SavedFits/TimeDependentSystematics/"+saveName;
  //hist name tells us the 2d histogram from the file, so get it.
  //convention will be to pass the name with "td0" in it. This is without the "RS" or "RS_ss"
  //make sure to subtract the background.
  f1->ls();
  cout<<"now looking for RS_"<<histName<<endl;
  theHist_vs_time = (TH2D*)f1->Get("RS_"+histName);
  theHist_vs_time->Sumw2();
  TH2D* time_subtr =(TH2D*)f1->Get("RS_ss_"+histName);
  time_subtr->Sumw2();
  theHist_vs_time->Add(time_subtr,-1);
  TString hist_name_v_mass = histName;
  hist_name_v_mass.ReplaceAll("td0","dstm");
  theHist_vs_mass = (TH2D*)f1->Get("RS_"+hist_name_v_mass);
  theHist_vs_mass->Sumw2();
  TH2D* mass_subtr =(TH2D*)f1->Get("RS_ss_"+hist_name_v_mass);
  mass_subtr->Sumw2();
  theHist_vs_mass->Add(mass_subtr,-1);
  //now, if slices are blank, calculate them myself as 5 bins of approximately equal population.
  if(slices_local.empty()){
    cout<<"calculating bin boundaries for stuff."<<endl;
    slices_local.push_back(1);
    //make temp projeciton
    TH1D* temp_proj = theHist_vs_time->ProjectionY("temp_proj");
    for(int i=1; i<5;++i){//nbins
      for(int bin=2; bin<temp_proj->GetNbinsX();++bin){
	if((temp_proj->Integral(1,bin))>=temp_proj->GetEntries()*i/5.){
	  slices_local.push_back(bin); break;
	}
      }
    }
  }
  cout<<"using bin boundaries"<<endl;
  for(int i=0;i<6;++i){
    cout<<"bin = "<<slices_local[i]<<endl;
  }
  //assert(0);
  //now that we have the distributions,make the slices
  TH1D* theproj_td0[5],*theproj_m[5],*theproj_td0_y[5];  
  for(int i=0; i<5;++i){
    theproj_td0[i]=theHist_vs_time->ProjectionX(Form("projx_%d",i+1),slices_local[i],slices_local[i+1],"e");
    theproj_m[i] = theHist_vs_mass->ProjectionX(Form("projxm_%d",i+1),slices_local[i],slices_local[i+1]); 
    theproj_td0_y[i]=theHist_vs_time->ProjectionY(Form("projx_%d",i+1),td0_bin_boundaries[i],td0_bin_boundaries[i+1],"e");
  }
  //draw all the projections on the same graph.
  int the_colors[5]={kBlue,kGreen+2,kMagenta, kOrange,kRed};
  TString the_leg_text;
  THStack *hs_t = new THStack("hs_t","");
  THStack *hs_t_y = new THStack("hs_t_y","");
  THStack *hs_m = new THStack("hs_m","");
  TLegend theleg(0.6,0.7,0.9,0.9);
  //need to define the axis label here. for the legend.
  //first draw the T(D^0) hist if we have it.
  TString theAxisLabel;
  for(int i=0; i<5;++i){

    if(i==0){the_leg_text = theAxisLabel+Form("<%.1f",theHist_vs_time->GetXaxis()->GetBinLowEdge(slices_local[i+1]));}
    else if(i<4){the_leg_text = Form("%.1f#leq",theHist_vs_time->GetXaxis()->GetBinLowEdge(slices_local[i]))+theAxisLabel+Form("<%.1f",theHist_vs_time->GetXaxis()->GetBinLowEdge(slices_local[i+1]));}
    else{the_leg_text = theAxisLabel+Form("#geq %.1f",theHist_vs_time->GetXaxis()->GetBinLowEdge(slices_local[i]));}
    theproj_td0[i]->SetLineColor(the_colors[i]);
    theproj_m[i]->SetLineColor(the_colors[i]);
    theleg.AddEntry(theproj_td0[i],the_leg_text);
    hs_t->Add(theproj_td0[i],"hist");
    hs_m->Add(theproj_m[i],"hist");
  }
  TLegend theleg2(0.6,0.7,0.9,0.9);
  for(int i=0; i<5;++i){
    if(i<4){the_leg_text = Form("%.1f#leq",theHist_vs_time->GetYaxis()->GetBinLowEdge(td0_bin_boundaries[i]))+theAxisLabel+Form("<%.1f",theHist_vs_time->GetYaxis()->GetBinLowEdge(td0_bin_boundaries[i+1]));}
    else{the_leg_text = theAxisLabel+Form("#geq %.1f",theHist_vs_time->GetYaxis()->GetBinLowEdge(td0_bin_boundaries[i]));}
    theproj_td0_y[i]->SetLineColor(the_colors[i]);
    theleg2.AddEntry(theproj_td0_y[i],the_leg_text);
    hs_t_y->Add(theproj_td0_y[i],"hist");
  }
  TCanvas *cc = new TCanvas();
  hs_t->Draw("nostack");
  theleg.Draw();
  cc->SaveAs(mSaveName+"_vs_td0.pdf");
}
