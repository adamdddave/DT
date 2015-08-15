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
      for(int bin=1; bin<temp_proj->GetNbinsX();++bin){
	if((temp_proj->Integral(1,bin))>=temp_proj->GetEntries()*i/5.){
	  cout<<"found good bin "<<bin<<"corresponding to central value "<<temp_proj->GetBinCenter(bin)<<endl;
	  slices_local.push_back(bin); break;
	}
      }
    }
  }
  slices_local.push_back(-1);
  cout<<"using bin boundaries"<<endl;
  for(int i=0;i<5;++i){
    cout<<"bin = "<<slices_local[i]<<endl;
  }
  
  
  //assert(0);
  //now that we have the distributions,make the slices
  TH1D* theproj_td0[5],*theproj_m[5],*theproj_td0_y[5];  
  for(int i=0; i<5;++i){
    theproj_td0[i]=theHist_vs_time->ProjectionX(Form("projy_%d",i+1),slices_local[i],slices_local[i+1],"e");
    theproj_m[i] = theHist_vs_mass->ProjectionX(Form("projym_%d",i+1),slices_local[i],slices_local[i+1]); 
    theproj_td0_y[i]=theHist_vs_time->ProjectionY(Form("projx_%d",i+1),td0_bin_boundaries[i],td0_bin_boundaries[i+1],"e");
    cout<<"testing entries. theproj_td0["<<i<<"]->GetEntries() = "<<theproj_td0[i]->GetEntries()<<endl;
    cout<<"testing entries. theproj_m["<<i<<"]->GetEntries() = "<<theproj_m[i]->GetEntries()<<endl;
    cout<<"testing entries. theproj_td0_y["<<i<<"]->GetEntries() = "<<theproj_td0_y[i]->GetEntries()<<endl;
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
  if(histName.Contains("b_flight_distance")){
    theAxisLabel = "B_{Flight Distance}";
  }
  else if(histName.Contains("b_corr_mass")){
    theAxisLabel = "m(B)_{Corrected}";
  }
  else if(histName.Contains("dtf_chi2")){
    theAxisLabel = "#chi^{2}_{DTF}";
  }
  else if(histName.Contains("mu_ipchi2") && !histName.Contains("log")){
    theAxisLabel = "#chi^{2}_{IP}(#mu)";
  }
  else if(histName.Contains("log_mu_ipchi2")){
    theAxisLabel = "log(#chi^{2}_{IP})(#mu)";
  }
  else if(histName.Contains("b_endvertex_chi2")){
    theAxisLabel = "B #chi^{2}_{End Vertex}";
  }
  else if(histName.Contains("b_fd_chi2")){
    theAxisLabel = "B_{Flight Distance}#chi^{2}";
  }
  else if(histName.Contains("d_log_ip_chi2")){
    theAxisLabel = "log(#chi^{2}_\text{IP}(D^{0})";
  }
  
  for(int i=0; i<5;++i){

    if(i==0){the_leg_text = theAxisLabel+Form("<%.1f",theHist_vs_time->GetYaxis()->GetBinLowEdge(slices_local[i+1]));}
    else if(i<4){the_leg_text = Form("%.1f#leq",theHist_vs_time->GetYaxis()->GetBinLowEdge(slices_local[i]))+theAxisLabel+Form("<%.1f",theHist_vs_time->GetYaxis()->GetBinLowEdge(slices_local[i+1]));}
    else{the_leg_text = theAxisLabel+Form("#geq %.1f",theHist_vs_time->GetYaxis()->GetBinLowEdge(slices_local[i]));}
    theproj_td0[i]->SetLineColor(the_colors[i]);
    theproj_m[i]->SetLineColor(the_colors[i]);
    theleg.AddEntry(theproj_td0[i],the_leg_text);
    hs_t->Add(theproj_td0[i],"hist");
    hs_m->Add(theproj_m[i],"hist");
  }
  TLegend theleg2(0.6,0.7,0.9,0.9);
  for(int i=0; i<5;++i){
    if(i<4){the_leg_text = Form("%.1f#leqD^{0} t/#tau<%.1f",theHist_vs_time->GetXaxis()->GetBinLowEdge(td0_bin_boundaries[i]),theHist_vs_time->GetXaxis()->GetBinLowEdge(td0_bin_boundaries[i+1]));}
    else{the_leg_text = Form("D^{0} t/#tau#geq %.1f",theHist_vs_time->GetXaxis()->GetBinLowEdge(td0_bin_boundaries[i]));}
    theproj_td0_y[i]->SetLineColor(the_colors[i]);
    theleg2.AddEntry(theproj_td0_y[i],the_leg_text);
    hs_t_y->Add(theproj_td0_y[i],"hist");
  }
  TCanvas *cc = new TCanvas();
  
  hs_t->Draw("nostack");
  hs_t->SetTitle(Form(";D^{0}t/#tau; Entries/ %.2f",theproj_td0[0]->GetBinWidth(1)));
  cc->Modified();
  theleg.Draw();
  cc->SaveAs(mSaveName+"_vs_td0.pdf");
  cc->SetLogy(true);
  cc->SaveAs(mSaveName+"_vs_td0_logy.pdf");
  cc->SetLogy(false);
  cc->Clear();

  
  hs_m->Draw("nostack");
  hs_m->SetTitle(Form(";m(D^{0}#pi_{S})[MeV];Entries / %.2f",theproj_m[0]->GetBinWidth(1)));
  cc->Modified();
  theleg.Draw();
  cc->SaveAs(mSaveName+"_vs_dst_m.pdf");
  cc->SetLogy(true);
  cc->SaveAs(mSaveName+"_vs_dst_m_logy.pdf");
  cc->SetLogy(false);
  cc->Clear();


  hs_t_y->Draw("nostack");
  hs_t_y->SetTitle(";"+theAxisLabel+Form("; Entries / %.2f",theproj_td0_y[0]->GetBinWidth(1)));
  cc->Modified();
  theleg2.Draw();
  cc->SaveAs(mSaveName+"_bins_of_td0.pdf");
  cc->SetLogy(true);
  cc->SaveAs(mSaveName+"_bins_of_td0_logy.pdf");
  /*  if(histName.Contains("mu_ipchi2")){
    cc->SetLogx(true);
    cc->SaveAs(mSaveName+"_bins_of_td0_logx_logy.pdf");
    cc->SetLogy(false);
    cc->SaveAs(mSaveName+"_bins_of_td0_logx.pdf");
    cc->SetLogx(false);
    }*/
  cc->SetLogy(false);
  //make a root file of these files.
  TFile *fout_from_2d = new TFile(mSaveName+histName+"_output.root","RECREATE");
  fout_from_2d->cd();
  for(int i=0; i<5; ++i){
    theproj_td0[i]->Write();
  }
  for(int i=0; i<5; ++i){
    theproj_m[i]->Write();
  }
  for(int i=0; i<5; ++i){
    theproj_td0_y[i]->Write();
  }
  fout_from_2d->Close();
}
