#include <TFile.h>
#include <TTree.h>
#include <Riostream.h>
#include <TString.h>
#include "WSFitter.h"
#include "TMarker.h"

const int nbins(13);

//*** tos nuisance pars
double Fb_tos[] = { 0., 0.52596e-2, 1.45988e-2, 2.07807e-2, 2.82813e-2, 2.73008e-2, 2.84643e-2, 3.2358e-2, 3.48736e-2, 3.75776e-2, 4.39282e-2, 5.47691e-2, 8.72898e-2};
double Fb_err_tos[] = { 0.1, 0.0587098e-2, 0.0885105e-2, 0.124796e-2, 0.14663e-2, 0.0982035e-2, 0.0904245e-2, 0.10492e-2, 0.109644e-2, 0.0922559e-2, 0.0954065e-2, 0.189172e-2, 0.410221e-2};
double Fp_tos[] = {1.84328e-05, 2.10621e-05, 2.02552e-05, 2.45093e-05, 2.66489e-05, 2.43631e-05, 2.68709e-05, 2.62705e-05, 2.49372e-05, 3.34959e-05, 2.66623e-05, 2.44331e-05, 3.16432e-05};
double Fp_err_tos[] = {1.16015e-05, 7.71372e-06, 7.06207e-06, 8.98002e-06, 9.57476e-06, 7.60268e-06, 8.58263e-06, 9.38692e-06, 1.02916e-05, 9.59164e-06, 8.6544e-06, 1.43273e-05, 2.17873e-05};
//double Aeps_tos(1.48e-2), Aeps_err_tos(0.25e-2);
double Aeps_tos(1.17e-2), Aeps_err_tos(0.35e-2);

//*** !tos nuisance pars
double Fb_ntos[] = { 0., 0.341882e-2, 1.17774e-2, 1.80928e-2, 2.75759e-2, 2.38632e-2, 3.10919e-2, 3.35169e-2, 3.94876e-2, 4.79789e-2, 5.71315e-2, 7.70593e-2, 13.1365e-2};
double Fb_err_ntos[] = { 0.1e-2, 0.0514722e-2, 0.0845139e-2, 0.107266e-2, 0.173481e-2, 0.0221e-2, 0.121356e-2, 0.0340128e-2, 0.046843e-2, 0.135314e-2, 0.141434e-2, 0.320891e-2, 0.914995e-2};
double Fp_ntos[] = {1.50816e-05, 8.9216e-06, 1.38685e-05, 1.20544e-05, 1.2649e-05, 1.09998e-05, 1.70324e-05, 1.56184e-05, 1.10394e-05, 1.76248e-05, 1.37407e-05, 9.25967e-06, 7.95085e-06};
double Fp_err_ntos[] = {1.4416e-05, 6.79537e-06, 6.67624e-06, 7.52942e-06, 7.82098e-06, 6.12179e-06, 7.52621e-06, 8.04489e-06, 8.20814e-06, 8.08355e-06, 7.4548e-06, 1.12302e-05, 1.42233e-05};
//double Aeps_ntos(1.13e-2), Aeps_err_ntos(0.16e-2);
double Aeps_ntos(0.83e-2), Aeps_err_ntos(0.22e-2);

void mixing_fit_data(bool plot=false, bool minos=false, TString name="output.txt",int cpvType=2)
{
	// init fitter
  WSFitter *fitter = new WSFitter(nbins,cpvType);

	// read tos data
	if (!fitter->ReadData("./fitdata/yield_vs_time_pos_2011_tos.txt",+1,true)) return;
	if (!fitter->ReadData("./fitdata/yield_vs_time_neg_2011_tos.txt",-1,true)) return;
	if (!fitter->ReadData("./fitdata/yield_vs_time_pos_2012_tos.txt",+1,true)) return;
	if (!fitter->ReadData("./fitdata/yield_vs_time_neg_2012_tos.txt",-1,true)) return;
	// read !tos data
	if (!fitter->ReadData("./fitdata/yield_vs_time_pos_2011_ntos.txt",+1,false)) return;
	if (!fitter->ReadData("./fitdata/yield_vs_time_neg_2011_ntos.txt",-1,false)) return;
	if (!fitter->ReadData("./fitdata/yield_vs_time_pos_2012_ntos.txt",+1,false)) return;
	if (!fitter->ReadData("./fitdata/yield_vs_time_neg_2012_ntos.txt",-1,false)) return;

	// read DT data
	if (!fitter->Read_DT_Data("./dtfitdata/DT_unblinded_data_for_testing_pos.txt",+1)) return;
	if (!fitter->Read_DT_Data("./dtfitdata/DT_unblinded_data_for_testing_neg.txt",-1)) return;

	fitter->SetDetectorAsymmetries(Aeps_tos,Aeps_err_tos,true);
	fitter->SetDetectorAsymmetries(Aeps_ntos,Aeps_err_ntos,false);

	fitter->SetSecondaryFractions(Fb_tos,Fb_err_tos,true);
	fitter->SetSecondaryFractions(Fb_ntos,Fb_err_ntos,false);

	fitter->SetPeakingFractions(Fp_tos,Fp_err_tos,true);
	fitter->SetPeakingFractions(Fp_ntos,Fp_err_ntos,false);
	
	//DT
	double dtPrFrac[]={0.,0.,0.,0.,0.};
	double dtPrFracErr[]={1.,1.,1.,1.,1.,};
	//fitter->Set_DT_DetectorAsymmetries(0.96e-2,0.11e-2);
	fitter->Set_DT_DetectorAsymmetries(0.,1.);
	fitter->Set_DT_PromptFractions(dtPrFrac,dtPrFracErr);
	//fitter->Set_DT_PeakingFractions(3.611e-5,2.260e-5);
	fitter->Set_DT_PeakingFractions(0.,1.);
	fitter->UsePromptData(false);
	fitter->UseDTData(true);
	// fitting
	fitter->Reset();
	fitter->Print();
		for(int i=60;i<67;++i){fitter->FixParameter(i,0);}
	if (fitter->Fit(minos) !=0) return;
	fitter->WriteResults(name.Data());
//	// plotting
//	if (!plot) return;
//
//	Plotter *p = new Plotter(fitter);
//	p->PlotRatios();
//	p->PlotDiffs();
//	p->PlotPulls();
//
//	p->PlotXYContours();
//	TMarker *m = new TMarker(0.,0.,2);
//	m->SetMarkerSize(3);
//	m->Draw("same");
//
//	if (fitter->Fitter()->IsFixed(2) || fitter->Fitter()->IsFixed(3)) return;
//
//	p->PlotCPVContours();
//	m->Draw("same");
}
