#ifndef WSFitter_cxx
#define WSFitter_cxx
#include <TDirectory.h>
#include <TRandom3.h>
#include <TMath.h>
#include <TMinuit.h>
#include <Math/QuantFuncMathCore.h>
#include <TAxis.h>
#include <algorithm>
#include <complex>
#include "WSFitter.h"
using namespace std;
ThisFitter *_fitter(0);

//______________________________________________________________________________
WSFitter::WSFitter(int n_time,int cpvType)
	: _n_time_bins(n_time),
	  _Aeps_tos(0.), _Aeps_err_tos(1.), _Aeps_ntos(0.), _Aeps_err_ntos(1.),
	  _Fb_tos(n_time), _Fb_err_tos(n_time), _Fb_ntos(n_time), _Fb_err_ntos(n_time),
	  _Fp_tos(n_time), _Fp_err_tos(n_time), _Fp_ntos(n_time), _Fp_err_ntos(n_time),
	  _status(-1), _chi2(0.), _ndf(0), _printlevel(-1),
	  _n_time_bins_DT(5),
	  _Aeps_DT(0.),_Aeps_err_DT(1.),
	  _Fb_DT(5),_Fb_err_DT(5),
	  _Fp_DT(0.),_Fp_err_DT(1.),

	  _CPVtype(cpvType),
	  _usePrompt(true),_useDT(false)
{
	TVirtualFitter::SetDefaultFitter("Minuit");
	_fitter = new ThisFitter(this,60+7);//7 is the number of DT params we have now, this is Aeps, Fp and Fb x 5
	if(_CPVtype==2){cout<<"All CPV Fit"<<endl;      Fitter()->SetFCN(FitFCN);}
	else if(_CPVtype==1){cout<<"No DCPV Fit"<<endl; Fitter()->SetFCN(FitFCN_noDCPV);}
	else{cout<<"Mixing Fit"<<endl;                  Fitter()->SetFCN(FitFCN_mixing);}

	double arglist = _printlevel;
	Fitter()->ExecuteCommand("SET PRI",&arglist,1);
	arglist = 2.;
	Fitter()->ExecuteCommand("SET STRAT",&arglist,1);

	Reset(false);
}

//______________________________________________________________________________
WSFitter::~WSFitter()
{
	Fitter()->Clear();
	delete _fitter;
}

//______________________________________________________________________________
TFitter* WSFitter::Fitter() const
{
	return _fitter->GetFitter();
}

//______________________________________________________________________________
void WSFitter::SetParameter(unsigned int i, double value)
{
	char name[20];
	double oldvalue(0.), err(0.), low(0.), high(0.);
	Fitter()->GetParameter(i,name,oldvalue,err,low,high);
	Fitter()->SetParameter(i,name,value,err,low,high);
}

//______________________________________________________________________________
void WSFitter::FixParameter(unsigned int i, double value)
{
	SetParameter(i,value);
	Fitter()->FixParameter(i);
}

//______________________________________________________________________________
double WSFitter::ParErrors(int ipar, double &eplus, double &eminus, double &eparab) const
{
	double globcc(0.);
	Fitter()->GetErrors(ipar,eplus,eminus,eparab,globcc);
	eplus = fabs(eplus);	eminus = fabs(eminus);
	return globcc;
}

//______________________________________________________________________________
double WSFitter::Covariance(int i, int j) const
{
	if (Fitter()->IsFixed(i) || Fitter()->IsFixed(j)) return 0.;

	Int_t ioff(0), joff(0);
	for(Int_t k=0; k<i; ++k)
		if(Fitter()->IsFixed(k)) ioff++;
	for(Int_t k=0; k<j; ++k)
		if(Fitter()->IsFixed(k)) joff++;

	return Fitter()->GetCovarianceMatrixElement(i-ioff,j-joff);
}

//______________________________________________________________________________
double WSFitter::Correlation(int i, int j) const
{
	if (Fitter()->IsFixed(i) || Fitter()->IsFixed(j)) return 0.;

	return Covariance(i,j)/sqrt(Covariance(i,i)*Covariance(j,j));
}

//______________________________________________________________________________
bool WSFitter::ReadData(const char *filename, int d0flavor, bool tos, bool verbose)
{
	std::ifstream file(filename);
	if (!file) {
		std::cout << "Unable to open " << filename << std::endl;
		return false;
	}
	if (verbose) std::cout << "Reading " << filename << std::endl;

	DataPoints *data;
	if (d0flavor>=0)
		data = (tos)? &_points_pos_tos : &_points_pos_ntos;
	else
		data = (tos)? &_points_neg_tos : &_points_neg_ntos;

	// remove header lines
	char line[100];
	file.get(line,99);
	
	// read data
	DataPoint point; unsigned int n(0);
	while (point.Read(file)) {
		if (point.i>=_n_time_bins) continue;
		data->push_back(point);
		n++;
		if (verbose) point.Print();
	}
	file.close();

	std::sort(data->begin(), data->end(), CompareDataPoints);

	return (n!=0);
}

//______________________________________________________________________________
void WSFitter::Reset(bool print)
{
	if (print) std::cout << "Reset parameters" << std::endl;
	double val(3.); int inseed(12345);
	Fitter()->GetMinuit()->mnrn15(val,inseed);
	
	Fitter()->SetParameter(0,"R_D+",3.5, 1e-3, 0.,0.);
	Fitter()->SetParameter(1,"y'+" ,5.2, 1e-2, 0.,0.);
	Fitter()->SetParameter(2,"x'2+", 0., 1e-2, 0.,0.);
	Fitter()->SetParameter(3,"R_D-",3.5, 1e-3, 0.,0.);
	Fitter()->SetParameter(4,"y'-" ,5.2, 1e-2, 0.,0.);
	Fitter()->SetParameter(5,"x'2-", 0., 1e-2, 0.,0.);
	//nuissance parameters
	Fitter()->SetParameter(6,"a_tos" , _Aeps_tos,1e-4,0.,0.);
	Fitter()->SetParameter(7,"a_ntos",_Aeps_ntos,1e-4,0.,0.);
	for (int i=0; i<_n_time_bins; ++i) {
		Fitter()->SetParameter( 8+i, Form("fb%d_tos",i), 1e-2*_Fb_tos[i],1e-4,0.,0.);
		Fitter()->SetParameter(21+i,Form("fb%d_ntos",i),1e-2*_Fb_ntos[i],1e-4,0.,0.);
		Fitter()->SetParameter(34+i, Form("fp%d_tos",i),      _Fp_tos[i],1e-4,0.,0.);
		Fitter()->SetParameter(47+i,Form("fp%d_ntos",i),     _Fp_ntos[i],1e-4,0.,0.);
	}
	_status = -1;
	//AD
	//Add DT reset here
	if(_CPVtype==1){Fitter()->FixParameter(3);}
	if(_CPVtype==0){
	  Fitter()->FixParameter(3);
	  Fitter()->FixParameter(4);
	  Fitter()->FixParameter(5);
	}

	Fitter()->SetParameter(60, "a_DT",_Aeps_DT,1e-4,0.,0.);
	for(int i=0; i<_n_time_bins_DT;++i){
	  Fitter()->SetParameter(61+i, Form("fb%d_DT",i),1e-2*_Fb_DT[i],1e-4,0.,0.);
	}
	Fitter()->SetParameter(66,"fp_DT",_Fp_DT,1e-4,0.,0.);
	//fix the params if we're not using the DT dataset
	if(_useDT==false){
	  Fitter()->FixParameter(60);//aKpi
	  Fitter()->FixParameter(61);//fb0
	  Fitter()->FixParameter(62);//fb1
	  Fitter()->FixParameter(63);//fb2
	  Fitter()->FixParameter(64);//fb3
	  Fitter()->FixParameter(65);//fb4
	  Fitter()->FixParameter(66);//fp
	}
	//also implement fixing only the prompt params too
	if(_usePrompt==false){
	  for(int i=6;i<60;++i){
	    Fitter()->FixParameter(i);
	  }
	}
	//endAD
}

//______________________________________________________________________________
int WSFitter::Fit(bool minos)
{
	double arglist[2];
	if (_printlevel==-1) {
		arglist[0] = 0.;
		Fitter()->ExecuteCommand("SET PRI",arglist,1);
	}

	arglist[0] = 5000.;
	arglist[1] = .0001;
	int status = _status = Fitter()->ExecuteCommand("MIGRAD",arglist,2);
	std::cout << "migrad status = " << status << std::endl;
	if (status==0) {
		double chi2_migrad = _chi2; int ndf_migrad = _ndf;
		if (minos) {
			status = Fitter()->ExecuteCommand("MINOS",arglist,1);
			std::cout << "minos status = " << status << std::endl;
		} else {
			status = Fitter()->ExecuteCommand("HESSE",arglist,2);
			std::cout << "hesse status = " << status << std::endl;
		}
		_chi2 = chi2_migrad; _ndf = ndf_migrad;
		std::cout << "chi2/ndf = " << _chi2 << "/" << _ndf << std::endl;
		std::cout << "prob(chi2) = " << TMath::Prob(_chi2,_ndf) << std::endl;
	}

	if (_printlevel==-1) {
		arglist[0] = _printlevel;
		Fitter()->ExecuteCommand("SET PRI",arglist,1);
	}

	return status;
}

//______________________________________________________________________________
void WSFitter::SetPrintLevel(int l)
{
	_printlevel = l;
	double arglist = l;
	Fitter()->ExecuteCommand("SET PRI",&arglist,1);
	if (l<0) Fitter()->ExecuteCommand("SET NOW",&arglist,0);
}

//______________________________________________________________________________
void WSFitter::SetDetectorAsymmetries(double a, double a_err, bool tos)
{
	if (tos) {
		_Aeps_tos = a;
		_Aeps_err_tos = a_err;
	} else {
		_Aeps_ntos = a;
		_Aeps_err_ntos = a_err;
	}
}

//______________________________________________________________________________
void WSFitter::SetSecondaryFractions(double *f, double *f_err, bool tos)
{
	if (tos) {
		for (int i=0; i<_n_time_bins; ++i) {
			_Fb_tos[i] = f[i];
			_Fb_err_tos[i] = f_err[i];
		}
	} else {
		for (int i=0; i<_n_time_bins; ++i) {
			_Fb_ntos[i] = f[i];
			_Fb_err_ntos[i] = f_err[i];
		}
	}
}

//______________________________________________________________________________
void WSFitter::SetPeakingFractions(double *f, double *f_err, bool tos)
{
	if (tos) {
		for (int i=0; i<_n_time_bins; ++i) {
			_Fp_tos[i] = f[i];
			_Fp_err_tos[i] = f_err[i];
		}
	} else {
		for (int i=0; i<_n_time_bins; ++i) {
			_Fp_ntos[i] = f[i];
			_Fp_err_ntos[i] = f_err[i];
		}
	}
}

//______________________________________________________________________________
std::ostream &WSFitter::Print(std::ostream &out, bool verbose)
{
	// print nuissance parameters
	out << "*** N time bins: " << _n_time_bins << std::endl;

	out << "*** Detector asymmetry TOS: " << std::endl;
	out << "A(Kpi) = " << _Aeps_tos << " +/-" << _Aeps_err_tos << std::endl;
	out << "*** Detector asymmetry !TOS: " << std::endl;
	out << "A(Kpi) = " << _Aeps_ntos << " +/-" << _Aeps_err_ntos << std::endl;
	
	out << "*** Secondary fractions TOS: " << std::endl;
	for (unsigned int i=0; i<_n_time_bins; ++i)
		out << setw(2) << i << "\t" << setw(8) << _Fb_tos[i] << " +/-" << setw(8) << _Fb_err_tos[i] << std::endl;
	out << "*** Secondary fractions !TOS: " << std::endl;
	for (unsigned int i=0; i<_n_time_bins; ++i)
		out << setw(2) << i << "\t" << setw(8) << _Fb_ntos[i] << " +/-" << setw(8) << _Fb_err_ntos[i] << std::endl;

	out << "*** Peaking fractions TOS: " << std::endl;
	for (unsigned int i=0; i<_n_time_bins; ++i)
		out << setw(2) << i << "\t" << setw(8) << _Fp_tos[i] << " +/-" << setw(8) << _Fp_err_tos[i] << std::endl;
	out << "*** Peaking fractions !TOS: " << std::endl;
	for (unsigned int i=0; i<_n_time_bins; ++i)
		out << setw(2) << i << "\t" << setw(8) << _Fp_ntos[i] << " +/-" << setw(8) << _Fp_err_ntos[i] << std::endl;

	// print values and uncertainties
	out << "*** N data points D0 TOS: " << _points_pos_tos.size() << std::endl;
	DataPoint::PrintTitle();
	for (DataPoints::iterator it = _points_pos_tos.begin(); it!=_points_pos_tos.end(); ++it)
		(*it).Print();
	out << "*** N data points D0bar TOS: " << _points_neg_tos.size() << std::endl;
	DataPoint::PrintTitle();
	for (DataPoints::iterator it = _points_neg_tos.begin(); it!=_points_neg_tos.end(); ++it)
		(*it).Print();
	out << "*** N data points D0 !TOS: " << _points_pos_ntos.size() << std::endl;
	DataPoint::PrintTitle();
	for (DataPoints::iterator it = _points_pos_ntos.begin(); it!=_points_pos_ntos.end(); ++it)
		(*it).Print();
	out << "*** N data points D0bar !TOS: " << _points_neg_ntos.size() << std::endl;
	DataPoint::PrintTitle();
	for (DataPoints::iterator it = _points_neg_ntos.begin(); it!=_points_neg_ntos.end(); ++it)
		(*it).Print();

	// print fit status
	out << "Fit status = " << _status << std::endl;
	if (verbose) PrintResults(out);

	return out;
}

//______________________________________________________________________________
std::ostream &WSFitter::PrintResults(std::ostream &fout, bool verbose)
{
	fout << "Fitted parameters:" << std::endl;
	unsigned int npars = Fitter()->GetNumberTotalParameters();
	for(unsigned int k=0; k<npars; k++){
		fout << setw(8) << Fitter()->GetParName(k) << "\t" << setw(10) << fixed << setprecision(6) << Fitter()->GetParameter(k) << "\t";
		if(Fitter()->IsFixed(k))
			fout << setw(10) << "fixed" << std::endl;
		else
			fout << setw(10) << fixed << setprecision(6) << Fitter()->GetParError(k) << std::endl;
	}

	fout << "\nchi2/ndf:\t" << fixed << setprecision(3) << _chi2 << "/" << _ndf << std::endl;

	if (verbose) {
		fout << "\nCorrelation matrix:" << std::endl;
		fout << setw(9) << " ";
		for (unsigned int k=0; k<npars; k++) {
			if (Fitter()->IsFixed(k)) continue;
			fout << setw(8) << Fitter()->GetParName(k) << " ";
		}
		fout << std::endl;
		for (unsigned int i=0; i<npars; i++) {
			if (Fitter()->IsFixed(i)) continue;
			fout << setw(8) << Fitter()->GetParName(i) << " ";
			for (unsigned int j=0; j<=i; j++) {
				if (Fitter()->IsFixed(j)) continue;
				fout << setw(8) << fixed << setprecision(3) << Correlation(i,j) << " ";
			}
			fout << std::endl;
		}
	}

	return fout;
}

//______________________________________________________________________________
void WSFitter::WriteResults(const char *filename, bool verbose)
{
	std::ofstream fout(filename);
	if(!fout){
		std::cout << "Unable to create file" << filename << std::endl;
		return;
	}
	PrintResults(fout,verbose);
	fout.close();

	return;
}

//______________________________________________________________________________
TGraph* WSFitter::Contour(int par1, int par2, double cl, int npoints)
{
	TString s = TVirtualFitter::GetDefaultFitter();
	if ( (s != "") && (s!= "Minuit") ) {
		std::cout << "Contour method works only with Minuit!" << std::endl;
		return 0;
	}

	if ( Fitter()->IsFixed(par1) || Fitter()->IsFixed(par2) ) {
		std::cout << "Cannot evaluate contour for fixed parameters" << std::endl;
		return 0;
	}

	double up = ROOT::Math::chisquared_quantile(cl,2);
	double oldup = Fitter()->GetErrorDef();
	TMinuit *minuit = Fitter()->GetMinuit();
	minuit->SetErrorDef(up);
	TGraph *gr = (TGraph*) minuit->Contour(npoints,par1,par2);
	if (!gr) return 0;
	gr->SetTitle("");
	gr->GetXaxis()->SetTitle(Fitter()->GetParName(par1));
	gr->GetYaxis()->SetTitle(Fitter()->GetParName(par2));
	minuit->SetErrorDef(oldup);

	_status = -1;

	return gr;
}

//______________________________________________________________________________
void WSFitter::ComputeChi2(int & /*npars*/, double * /*gin*/, double &result, double *p, int /*flag*/)
{
	_chi2 = 0.; _ndf = 0;

	// physics parameters
	double RD_plus       = p[0]/1e3;
	double yprime_plus   = p[1]/1e3;
	double xprime2_plus  = p[2]/1e3;
	double RD_minus      = p[3]/1e3;
	double yprime_minus  = p[4]/1e3;
	double xprime2_minus = p[5]/1e3;
	if(_usePrompt){
	  // constraint on detector asymmetries
	  _chi2 += (p[6]-_Aeps_tos)*(p[6]-_Aeps_tos)/(_Aeps_err_tos*_Aeps_err_tos);
	  _ndf++;
	  _chi2 += (p[7]-_Aeps_ntos)*(p[7]-_Aeps_ntos)/(_Aeps_err_ntos*_Aeps_err_ntos);
	  _ndf++;
	  
	  for (int i=0; i<_n_time_bins; ++i) {
	    double res;
	    
	    // constraint on secondary fraction
	    res = (_Fb_tos[i]-p[8+i])/_Fb_err_tos[i];
	    _chi2 += res*res;
	    res = (_Fb_ntos[i]-p[8+_n_time_bins+i])/_Fb_err_ntos[i];
	    _chi2 += res*res;
	    
	    // constraint on peaking fraction
	    res = (_Fp_tos[i]-p[8+2*_n_time_bins+i])/_Fp_err_tos[i];
	    _chi2 += res*res;
	    res = (_Fp_ntos[i]-p[8+3*_n_time_bins+i])/_Fp_err_ntos[i];
	    _chi2 += res*res;
	  }
	  _ndf+=4*_n_time_bins;
	  
	  // compute chi2 on tos data
	  double eps_tos = (1.+p[6])/(1.-p[6]);
	  for (DataPoints::iterator it = _points_pos_tos.begin(); it!=_points_pos_tos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+i];
	      double fp    = p[8+2*_n_time_bins+i];
	      error = sqrt(17./12.)*error;//PDG-like scaling for up-down differences
	      if (error!=0) {
		double R      = RD_plus+sqrt(RD_plus)*yprime_plus*t+(xprime2_plus+yprime_plus*yprime_plus)/4.*t2;
		double deltaB = fb*(1.-RD_plus/R);
		double func   = eps_tos*R*(1.-deltaB)+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  for (DataPoints::iterator it = _points_neg_tos.begin(); it!=_points_neg_tos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+i];
	      double fp    = p[8+2*_n_time_bins+i];
	      error = sqrt(17./12.)*error;//PDG-like scaling for up-down differences
	      if (error!=0) {
		double R      = RD_minus+sqrt(RD_minus)*yprime_minus*t+(xprime2_minus+yprime_minus*yprime_minus)/4.*t2;
		double deltaB = fb*(1.-RD_minus/R);
		double func   = R*(1.-deltaB)/eps_tos+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  
	  // compute chi2 on ntos data
	  double eps_ntos = (1.+p[7])/(1.-p[7]);
	  for (DataPoints::iterator it = _points_pos_ntos.begin(); it!=_points_pos_ntos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+_n_time_bins+i];
	      double fp    = p[8+3*_n_time_bins+i];
	      if (error!=0) {
		double R      = RD_plus+sqrt(RD_plus)*yprime_plus*t+(xprime2_plus+yprime_plus*yprime_plus)/4.*t2;
		double deltaB = fb*(1.-RD_plus/R);
		double func   = eps_ntos*R*(1.-deltaB)+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  for (DataPoints::iterator it = _points_neg_ntos.begin(); it!=_points_neg_ntos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+_n_time_bins+i];
	      double fp    = p[8+3*_n_time_bins+i];
	      if (error!=0) {
		double R      = RD_minus+sqrt(RD_minus)*yprime_minus*t+(xprime2_minus+yprime_minus*yprime_minus)/4.*t2;
		double deltaB = fb*(1.-RD_minus/R);
		double func   = R*(1.-deltaB)/eps_ntos+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	}//usePrompt
	if(_useDT){
	  // constraint on detector asymmetries
	  _chi2 += (p[60]-_Aeps_DT)*(p[60]-_Aeps_DT)/(_Aeps_err_DT*_Aeps_err_DT);
	  _ndf++;
	  
	  for (int i=0; i<_n_time_bins_DT; ++i) {
	    double res;
	    // constraint on prompt fraction
	    res = (_Fb_DT[i]-p[61+i])/_Fb_err_DT[i];
	    _chi2 += res*res;
	    _ndf++;
	    	    
	  }

	  // constraint on peaking fraction
	  _chi2 += (_Fp_DT-p[66])*(_Fp_DT-p[66])/(_Fp_err_DT*_Fp_err_DT);
	  _ndf++;
	  
	  // compute chi2 on positive DT data
	  double eps_DT = (1.+p[60])/(1.-p[60]);
	  for (DataPoints::iterator it = _points_pos_DT.begin(); it!=_points_pos_DT.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[61+i];
	      double fp    = p[66];

	      if (error!=0) {
		double R      = RD_plus+sqrt(RD_plus)*yprime_plus*t+(xprime2_plus+yprime_plus*yprime_plus)/4.*t2;
		double deltaB = fb*(1.-RD_plus/R);
		double func   = eps_DT*R*(1.-deltaB)+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  //chi2 on negative DT data
	  for (DataPoints::iterator it = _points_neg_DT.begin(); it!=_points_neg_DT.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[61+i];
	      double fp    = p[66];
	      //error = sqrt(17./12.)*error;//PDG-like scaling for up-down differences
	      if (error!=0) {
		double R      = RD_minus+sqrt(RD_minus)*yprime_minus*t+(xprime2_minus+yprime_minus*yprime_minus)/4.*t2;
		double deltaB = fb*(1.-RD_minus/R);
		double func   = R*(1.-deltaB)/eps_DT+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	}//useDT
	_ndf -= Fitter()->GetNumberFreeParameters();	
	result = _chi2;
}

//______________________________________________________________________________
void FitFCN(int& npar, double* gin, double& f, double* par, int flag)
{
	WSFitter *fitter = dynamic_cast<WSFitter*>(_fitter->GetObject());
	if (!fitter) {
		std::cout << "Invalid fit object encountered!" << std::endl;
		return;
	}
	fitter->ComputeChi2(npar, gin, f, par, flag);
}

//AD

//______________________________________________________________________________
void FitFCN_noDCPV(int& npar, double* gin, double& f, double* par, int flag)
{
	WSFitter *fitter = dynamic_cast<WSFitter*>(_fitter->GetObject());
	if (!fitter) {
		std::cout << "Invalid fit object encountered!" << std::endl;
		return;
	}
	fitter->ComputeNoDCPVChi2(npar, gin, f, par, flag);
}
//______________________________________________________________________________
void FitFCN_mixing(int& npar, double* gin, double& f, double* par, int flag)
{
	WSFitter *fitter = dynamic_cast<WSFitter*>(_fitter->GetObject());
	if (!fitter) {
		std::cout << "Invalid fit object encountered!" << std::endl;
		return;
	}
	fitter->ComputeMixingChi2(npar, gin, f, par, flag);

}

//______________________________________________________________________________
void WSFitter::ComputeMixingChi2(int & /*npars*/, double * /*gin*/, double &result, double *p, int /*flag*/)
{
	_chi2 = 0.; _ndf = 0;

	// physics parameters
	double RD_plus       = p[0]/1e3;
	double yprime_plus   = p[1]/1e3;
	double xprime2_plus  = p[2]/1e3;
	double RD_minus      = RD_plus;
	double yprime_minus  = yprime_plus;
	double xprime2_minus = xprime2_plus;
	if(_usePrompt){
	  // constraint on detector asymmetries
	  _chi2 += (p[6]-_Aeps_tos)*(p[6]-_Aeps_tos)/(_Aeps_err_tos*_Aeps_err_tos);
	  _ndf++;
	  _chi2 += (p[7]-_Aeps_ntos)*(p[7]-_Aeps_ntos)/(_Aeps_err_ntos*_Aeps_err_ntos);
	  _ndf++;
	  
	  for (int i=0; i<_n_time_bins; ++i) {
	    double res;
	    
	    // constraint on secondary fraction
	    res = (_Fb_tos[i]-p[8+i])/_Fb_err_tos[i];
	    _chi2 += res*res;
	    res = (_Fb_ntos[i]-p[8+_n_time_bins+i])/_Fb_err_ntos[i];
	    _chi2 += res*res;
	    
	    // constraint on peaking fraction
	    res = (_Fp_tos[i]-p[8+2*_n_time_bins+i])/_Fp_err_tos[i];
	    _chi2 += res*res;
	    res = (_Fp_ntos[i]-p[8+3*_n_time_bins+i])/_Fp_err_ntos[i];
	    _chi2 += res*res;
	  }
	  _ndf+=4*_n_time_bins;
	  
	  // compute chi2 on tos data
	  double eps_tos = (1.+p[6])/(1.-p[6]);
	  for (DataPoints::iterator it = _points_pos_tos.begin(); it!=_points_pos_tos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+i];
	      double fp    = p[8+2*_n_time_bins+i];
	      error = sqrt(17./12.)*error;//PDG-like scaling for up-down differences
	      if (error!=0) {
		double R      = RD_plus+sqrt(RD_plus)*yprime_plus*t+(xprime2_plus+yprime_plus*yprime_plus)/4.*t2;
		double deltaB = fb*(1.-RD_plus/R);
		double func   = eps_tos*R*(1.-deltaB)+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  for (DataPoints::iterator it = _points_neg_tos.begin(); it!=_points_neg_tos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+i];
	      double fp    = p[8+2*_n_time_bins+i];
	      error = sqrt(17./12.)*error;//PDG-like scaling for up-down differences
	      if (error!=0) {
		double R      = RD_minus+sqrt(RD_minus)*yprime_minus*t+(xprime2_minus+yprime_minus*yprime_minus)/4.*t2;
		double deltaB = fb*(1.-RD_minus/R);
		double func   = R*(1.-deltaB)/eps_tos+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  
	  // compute chi2 on ntos data
	  double eps_ntos = (1.+p[7])/(1.-p[7]);
	  for (DataPoints::iterator it = _points_pos_ntos.begin(); it!=_points_pos_ntos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+_n_time_bins+i];
	      double fp    = p[8+3*_n_time_bins+i];
	      if (error!=0) {
		double R      = RD_plus+sqrt(RD_plus)*yprime_plus*t+(xprime2_plus+yprime_plus*yprime_plus)/4.*t2;
		double deltaB = fb*(1.-RD_plus/R);
		double func   = eps_ntos*R*(1.-deltaB)+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  for (DataPoints::iterator it = _points_neg_ntos.begin(); it!=_points_neg_ntos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+_n_time_bins+i];
	      double fp    = p[8+3*_n_time_bins+i];
	      if (error!=0) {
		double R      = RD_minus+sqrt(RD_minus)*yprime_minus*t+(xprime2_minus+yprime_minus*yprime_minus)/4.*t2;
		double deltaB = fb*(1.-RD_minus/R);
		double func   = R*(1.-deltaB)/eps_ntos+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	}//use Prompt
	if(_useDT){
	  _chi2 += (p[60]-_Aeps_DT)*(p[60]-_Aeps_DT)/(_Aeps_err_DT*_Aeps_err_DT);
	  _ndf++;
	  
	  for (int i=0; i<_n_time_bins_DT; ++i) {
	    double res;
	    // constraint on prompt fraction
	    res = (_Fb_DT[i]-p[61+i])/_Fb_err_DT[i];
	    _chi2 += res*res;
	    _ndf++;
	    	    
	  }

	  // constraint on peaking fraction
	  _chi2 += (_Fp_DT-p[66])*(_Fp_DT-p[66])/(_Fp_err_DT*_Fp_err_DT);
	  _ndf++;
	  
	  // compute chi2 on positive DT data
	  double eps_DT = (1.+p[60])/(1.-p[60]);
	  for (DataPoints::iterator it = _points_pos_DT.begin(); it!=_points_pos_DT.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[61+i];
	      double fp    = p[66];

	      if (error!=0) {
		double R      = RD_plus+sqrt(RD_plus)*yprime_plus*t+(xprime2_plus+yprime_plus*yprime_plus)/4.*t2;
		double deltaB = fb*(1.-RD_plus/R);
		double func   = eps_DT*R*(1.-deltaB)+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  //chi2 on negative DT data
	  for (DataPoints::iterator it = _points_neg_DT.begin(); it!=_points_neg_DT.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[61+i];
	      double fp    = p[66];
	      //error = sqrt(17./12.)*error;//PDG-like scaling for up-down differences
	      if (error!=0) {
		double R      = RD_minus+sqrt(RD_minus)*yprime_minus*t+(xprime2_minus+yprime_minus*yprime_minus)/4.*t2;
		double deltaB = fb*(1.-RD_minus/R);
		double func   = R*(1.-deltaB)/eps_DT+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	}//use DT
	_ndf -= Fitter()->GetNumberFreeParameters();

	result = _chi2;
}
//
//______________________________________________________________________________
void WSFitter::ComputeNoDCPVChi2(int & /*npars*/, double * /*gin*/, double &result, double *p, int /*flag*/)
{
	_chi2 = 0.; _ndf = 0;

	// physics parameters
	double RD_plus       = p[0]/1e3;
	double yprime_plus   = p[1]/1e3;
	double xprime2_plus  = p[2]/1e3;
	double RD_minus      = RD_plus;
	double yprime_minus  = p[4]/1e3;
	double xprime2_minus = p[5]/1e3;
	
	if(_usePrompt){
	  // constraint on detector asymmetries
	  _chi2 += (p[6]-_Aeps_tos)*(p[6]-_Aeps_tos)/(_Aeps_err_tos*_Aeps_err_tos);
	  _ndf++;
	  _chi2 += (p[7]-_Aeps_ntos)*(p[7]-_Aeps_ntos)/(_Aeps_err_ntos*_Aeps_err_ntos);
	  _ndf++;
	  
	  for (int i=0; i<_n_time_bins; ++i) {
	    double res;
	    
	    // constraint on secondary fraction
	    res = (_Fb_tos[i]-p[8+i])/_Fb_err_tos[i];
	    _chi2 += res*res;
	    res = (_Fb_ntos[i]-p[8+_n_time_bins+i])/_Fb_err_ntos[i];
	    _chi2 += res*res;
	    
	    // constraint on peaking fraction
	    res = (_Fp_tos[i]-p[8+2*_n_time_bins+i])/_Fp_err_tos[i];
	    _chi2 += res*res;
	    res = (_Fp_ntos[i]-p[8+3*_n_time_bins+i])/_Fp_err_ntos[i];
	    _chi2 += res*res;
	  }
	  _ndf+=4*_n_time_bins;
	  
	  // compute chi2 on tos data
	  double eps_tos = (1.+p[6])/(1.-p[6]);
	  for (DataPoints::iterator it = _points_pos_tos.begin(); it!=_points_pos_tos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+i];
	      double fp    = p[8+2*_n_time_bins+i];
	      error = sqrt(17./12.)*error;//PDG-like scaling for up-down differences
	      if (error!=0) {
		double R      = RD_plus+sqrt(RD_plus)*yprime_plus*t+(xprime2_plus+yprime_plus*yprime_plus)/4.*t2;
		double deltaB = fb*(1.-RD_plus/R);
		double func   = eps_tos*R*(1.-deltaB)+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  for (DataPoints::iterator it = _points_neg_tos.begin(); it!=_points_neg_tos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+i];
	      double fp    = p[8+2*_n_time_bins+i];
	      error = sqrt(17./12.)*error;//PDG-like scaling for up-down differences
	      if (error!=0) {
		double R      = RD_minus+sqrt(RD_minus)*yprime_minus*t+(xprime2_minus+yprime_minus*yprime_minus)/4.*t2;
		double deltaB = fb*(1.-RD_minus/R);
		double func   = R*(1.-deltaB)/eps_tos+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  
	  // compute chi2 on ntos data
	  double eps_ntos = (1.+p[7])/(1.-p[7]);
	  for (DataPoints::iterator it = _points_pos_ntos.begin(); it!=_points_pos_ntos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+_n_time_bins+i];
	      double fp    = p[8+3*_n_time_bins+i];
	      if (error!=0) {
		double R      = RD_plus+sqrt(RD_plus)*yprime_plus*t+(xprime2_plus+yprime_plus*yprime_plus)/4.*t2;
		double deltaB = fb*(1.-RD_plus/R);
		double func   = eps_ntos*R*(1.-deltaB)+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  for (DataPoints::iterator it = _points_neg_ntos.begin(); it!=_points_neg_ntos.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[8+_n_time_bins+i];
	      double fp    = p[8+3*_n_time_bins+i];
	      if (error!=0) {
		double R      = RD_minus+sqrt(RD_minus)*yprime_minus*t+(xprime2_minus+yprime_minus*yprime_minus)/4.*t2;
		double deltaB = fb*(1.-RD_minus/R);
		double func   = R*(1.-deltaB)/eps_ntos+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	}//usePrompt
	if(_useDT){
_chi2 += (p[60]-_Aeps_DT)*(p[60]-_Aeps_DT)/(_Aeps_err_DT*_Aeps_err_DT);
	  _ndf++;
	  
	  for (int i=0; i<_n_time_bins_DT; ++i) {
	    double res;
	    // constraint on prompt fraction
	    res = (_Fb_DT[i]-p[61+i])/_Fb_err_DT[i];
	    _chi2 += res*res;
	    _ndf++;
	    	    
	  }

	  // constraint on peaking fraction
	  _chi2 += (_Fp_DT-p[66])*(_Fp_DT-p[66])/(_Fp_err_DT*_Fp_err_DT);
	  _ndf++;
	  
	  // compute chi2 on positive DT data
	  double eps_DT = (1.+p[60])/(1.-p[60]);
	  for (DataPoints::iterator it = _points_pos_DT.begin(); it!=_points_pos_DT.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[61+i];
	      double fp    = p[66];

	      if (error!=0) {
		double R      = RD_plus+sqrt(RD_plus)*yprime_plus*t+(xprime2_plus+yprime_plus*yprime_plus)/4.*t2;
		double deltaB = fb*(1.-RD_plus/R);
		double func   = eps_DT*R*(1.-deltaB)+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	  //chi2 on negative DT data
	  for (DataPoints::iterator it = _points_neg_DT.begin(); it!=_points_neg_DT.end(); ++it)
	    {
	      int    i     = (*it).i;
	      double t     = (*it).t;
	      double t2    = (*it).t2;
	      double ratio = (*it).r();
	      double error = (*it).sr();
	      double fb    = p[61+i];
	      double fp    = p[66];
	      //error = sqrt(17./12.)*error;//PDG-like scaling for up-down differences
	      if (error!=0) {
		double R      = RD_minus+sqrt(RD_minus)*yprime_minus*t+(xprime2_minus+yprime_minus*yprime_minus)/4.*t2;
		double deltaB = fb*(1.-RD_minus/R);
		double func   = R*(1.-deltaB)/eps_DT+fp;
		
		double res = (ratio-func)/error;
		_chi2 += res*res;
		_ndf++;
	      }
	    }
	}//useDT
	_ndf -= Fitter()->GetNumberFreeParameters();

	result = _chi2;
}

//AD                                                                                                                                                                                                                                                                                                                       
//______________________________________________________________________________                                                                                                                                                                                                                                           
bool WSFitter::Read_DT_Data(const char *filename, int d0flavor, bool verbose)
{
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Unable to open " << filename << std::endl;
    return false;
  }
  if (verbose) std::cout << "Reading " << filename << std::endl;
  DataPoints *data;

  data=(d0flavor>=0)?&_points_pos_DT : &_points_neg_DT ;
  std::cout<<"using tight tight sample"<<std::endl;

  // remove header lines                                                                                                                                                                                                                                                                                             
  char line[150];
  file.get(line,99);

  // read data                                                                                                                                                                                                                                                                                                       
  DataPoint point; unsigned int n(0);
  while (point.Read(file)) {
    if (point.i>=(int)_n_time_bins) continue;
    data->push_back(point);
    n++;
    if (verbose) point.Print();
  }
  file.close();

  std::sort(data->begin(), data->end(), CompareDataPoints);
  std::cout<<"read "<<n<<" datapoints"<<std::endl;
  return (n!=0);
}


//AD                                                                                                                                                                                                                                                                                                                       
//______________________________________________________________________________                                                                                                                                                                                                                                           
void WSFitter::Set_DT_DetectorAsymmetries(double a, double a_err)
{
  _Aeps_DT = a;
  _Aeps_err_DT = a_err;
}
//AD                                                                            
//______________________________________________________________________________                                                                                                                                                                                                                                           
void WSFitter::Set_DT_PromptFractions(double *f, double *f_err)
{
  for(int i=0; i<(int)_n_time_bins_DT;++i){
    _Fb_DT[i] = f[i];
    _Fb_err_DT[i] = f_err[i];
  }
}
//AD      
//______________________________________________________________________________                                                                                                                                                                                                                                           
void WSFitter::Set_DT_PeakingFractions(double f, double f_err)
{
  _Fp_DT = f;
  _Fp_err_DT = f_err;
}


#endif
