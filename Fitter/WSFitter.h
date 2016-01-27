#ifndef WSFitter_h
#define WSFitter_h
#include <TFitter.h>
#include <TH1F.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include <TArrayD.h>
#include "DataPoint.h"

class WSFitter {
public:
  WSFitter(int n_time=13, int cpvType=2);
	~WSFitter();

	TFitter      *Fitter() const;
	unsigned int  NTimeBins() const { return _n_time_bins; }
	double        Chi2() const { return _chi2; }
	int           NDF() const { return _ndf; }
	void          SetParameter(unsigned int i, double value);
	void          FixParameter(unsigned int i, double value);
	void          ReleaseParameter(unsigned int i) { Fitter()->ReleaseParameter(i); }
	double        Parameter(int i) const { return Fitter()->GetParameter(i); }
	double        ParError(int i) const { return Fitter()->GetParError(i); }
	double        ParErrors(int i, double& eplus, double& eminus, double& eparab) const;
	double        Covariance(int i, int j) const;
	double        Correlation(int i, int j) const;
	bool          ReadData(const char *filename, int charge, bool tos, bool verbose=false);
	void          Reset(bool print=true);
	void          ClearData() { _points_pos_tos.clear(); _points_neg_tos.clear(); _points_pos_ntos.clear(); _points_neg_ntos.clear(); }
	int           Fit(bool minos=false);
	void          SetPrintLevel(int l);
	
	void          SetDetectorAsymmetries(double a, double a_err, bool tos);
	void          SetSecondaryFractions(double *fb, double *fb_err, bool tos);
	void          SetPeakingFractions(double *fp, double *fp_err, bool tos);
	

	//AD
	void          UseDTData(bool use){_useDT = use;}
	void          UsePromptData(bool use){_usePrompt=use;}
	
	void          Set_DT_DetectorAsymmetries(double a, double a_err);
	void          Set_DT_PromptFractions(double *fb, double *fb_err);
	void          Set_DT_PeakingFractions(double fp, double fp_err );
	bool          Read_DT_Data(const char *filename, int charge, bool verbose=false);
	
	//end AD

	std::ostream &Print(std::ostream &out=std::cout, bool verbose=false);
	std::ostream &PrintResults(std::ostream &out=std::cout, bool verbose=false);
	void          WriteResults(const char *filename, bool verbose=true);

	TGraph       *Contour  (int par1, int par2, double cl=0.6827, int npoints=50);
	
	// This global function needs access to private members
	friend void   FitFCN(int& , double* , double& , double* , int );
	friend void   FitFCN_noDCPV(int& , double* , double& , double* , int );
	friend void   FitFCN_mixing(int& , double* , double& , double* , int );

private:
	void          ComputeChi2(int& , double* , double& , double* , int );
	void          ComputeMixingChi2(int& , double* , double& , double* , int );
	void          ComputeNoDCPVChi2(int& , double* , double& , double* , int );
protected:
	unsigned int _n_time_bins;
	double       _Aeps_tos, _Aeps_err_tos;
	double       _Aeps_ntos, _Aeps_err_ntos;
	TArrayD      _Fb_tos, _Fb_err_tos;
	TArrayD      _Fb_ntos, _Fb_err_ntos;
	TArrayD      _Fp_tos, _Fp_err_tos;
	TArrayD      _Fp_ntos, _Fp_err_ntos;
	DataPoints   _points_pos_tos, _points_neg_tos;
	DataPoints   _points_pos_ntos, _points_neg_ntos;
	int          _status;
	double       _chi2;
	int          _ndf;
	int          _printlevel;
	//AD
	DataPoints   _points_pos_DT, _points_neg_DT;
	unsigned int _n_time_bins_DT;
	double       _Aeps_DT, _Aeps_err_DT;
	TArrayD      _Fb_DT, _Fb_err_DT;//fraction of feedthrough from propmt
	double       _Fp_DT, _Fp_err_DT;//fraction of peaking background, only one number from DT

	int          _CPVtype;
	bool         _usePrompt;
	bool         _useDT;
};

class ThisFitter {
public:
	ThisFitter(WSFitter *o, unsigned int npar)
		: _object(o), _fitter(new TFitter(npar)) {;}
	~ThisFitter() { delete _fitter; _fitter = 0;	_object = 0;}

	TFitter       *GetFitter() const { return _fitter; }
	WSFitter *GetObject() const { return _object; }

protected:
	WSFitter *_object;
	TFitter       *_fitter;
};

void        FitFCN(int& , double* , double& , double* , int );
void FitFCN_noDCPV(int& , double* , double& , double* , int );
void FitFCN_mixing(int& , double* , double& , double* , int );
#endif
