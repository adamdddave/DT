#ifndef Plotter_h
#define Plotter_h
#include <TFitter.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include "WSFitter.h"
#include <TString.h>

class Plotter {
 public:
  Plotter(TString name, WSFitter* fitter, int CPVType=0);
  ~Plotter();
  
  void PlotRatios();//Plot RD+, RD-, RD
  void PlotDiffs();//Plot RD+ - RD-/RD+ + RD-
  void PlotPulls();//pulls for fits
  void PlotXYContours();//do the contours for x'2 and y'
  void PlotCPVContours();//same as above but split by charge
 private:
  int     _cpvType;//type of CPV Fit
  WSFitter* _Fitter;
  TString _name;
  TString _titleName;
};
#endif
