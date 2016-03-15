ROOTCFLAGS    = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS      = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS     = $(shell $(ROOTSYS)/bin/root-config --glibs)

#ROOTCFLAGS    = $(shell /usr/bin/root-config --cflags)
#ROOTLIBS      = $(shell /usr/bin/root-config --libs)
#ROOTGLIBS     = $(shell /usr/bin/root-config --glibs)

CXX           = g++
CXXFLAGS      = -g -Wall -fPIC -Wno-deprecated

NGLIBS         = $(ROOTGLIBS) 
NGLIBS        += -lMinuit
NGLIBS        += -lRooFit
NGLIBS        += -lRooFitCore
NGLIBS        += -lTreePlayer
NGLIBS        += -L$(MYPLOTTOOLS) -lPlottingTools
NGLIBS        += -L$(MYROOFITMODELS) -lRooJohnson -L$(MYROOFITMODELS) -lRooJohnsonSU -L$(MYROOFITMODELS) -lRooRBW
NGLIBS        += -L$(MYROOFITMODELS) -lRooCarolP3
CXXFLAGS      += $(ROOTCFLAGS)
CXX           += -I./	
LIBS           = $(ROOTLIBS) 

GLIBS          = $(filter-out -lNew, $(NGLIBS))

CXX	      += -I./lib/ -I$(MYPLOTTOOLS) -I$(MYROOFITMODELS)
OUTLIB	      = ./lib/
.SUFFIXES: .C
.PREFIXES: ./lib/

#----------------------------------------------------#

all:  mass_fits_compiled test_mass_fits bs_fits time_int_systs test_single_bin time_dep_systs matchRS_WS PiSgpStudy doRStimeDep testTimeDepLinearity loose_time_int_systs doD0massFits FindAl0 doTotTimeDep getRSoverRSfromfile

mass_fits_compiled: analysis.cpp 
	$(CXX) $(CXXFLAGS) DT_D0_mix_CPV.cpp massFit.cpp betastar_plot.cpp WrongB.cpp -o DTAnalysis  $(GLIBS) $<

test_mass_fits: testFit.cpp
	$(CXX) $(CXXFLAGS) massFit.cpp -o testMassFit  $(GLIBS) $<
bs_fits: betastarFits.cpp
	$(CXX) $(CXXFLAGS) betastar_plot.cpp massFit.cpp -o doBetastarFits $(GLIBS) $<
time_int_systs: TimeIntegratedSystematics.cpp
	$(CXX) $(CXXFLAGS) massFit.cpp TimeIntegratedSystematicsClass.cpp -o doTimeIntegratedSystematics $(GLIBS) $<
loose_time_int_systs: TimeIntegratedSystematicsLooseBins.cpp
	$(CXX) $(CXXFLAGS) massFit.cpp TimeIntegratedSystematicsClass.cpp -o doLooseTimeIntegratedSystematics $(GLIBS) $<
test_single_bin: TestSingleBinFit.cpp
	$(CXX) $(CXXFLAGS) massFit.cpp -o SingleBinFit $(GLIBS) $<
time_dep_systs: TimeDependentSystematics.cpp
	$(CXX) $(CXXFLAGS) massFit.cpp TimeDependent2D.cpp -o doTimeDepSysts $(GLIBS) $<
matchRS_WS: MatchWSandRSoverlap.cpp
	$(CXX) $(CXXFLAGS) DT_D0_mix_CPV.cpp betastar_plot.cpp WrongB.cpp -o doWSRSmatch $(GLIBS) $<
PiSgpStudy: doSlowPionStudy.cpp
	$(CXX) $(CXXFLAGS) slowPionStudy.cpp massFit.cpp -o doTheSlowPionStudy $(GLIBS) $<
doRStimeDep: extractDT_RS_Time_Dependence.cpp
	$(CXX) $(CXXFLAGS) massFit.cpp -o extractRSTimeDep $(GLIBS) $<
testTimeDepLinearity: TimeDependentChi2Fit.cpp
	$(CXX) $(CXXFLAGS) -o testTimeDepLinFit $(GLIBS) $<
doD0massFits: fitD0mass.cpp
	$(CXX) $(CXXFLAGS) -o D0massFit $(GLIBS) $<
FindAl0: getL0efficiency.cpp
	$(CXX) $(CXXFLAGS) massFit.cpp -o FindAl0muon $(GLIBS) $<
doTotTimeDep: extractTimeDependence.cpp
	$(CXX) $(CXXFLAGS) massFit.cpp -o extractTotTimeDep $(GLIBS) $<
getRSoverRSfromfile: RS_over_RS_from_file.cpp
	$(CXX) $(CXXFLAGS) -o extractRSoverRSfromfile $(GLIBS) $<

getRSTimeDepWithVariableModels: extractTimeDependence_RS_multimodel.cpp
	$(CXX) $(CXXFLAGS) massFit.cpp -o getRSTimeDepWithVariableModel $(GLIBS) $<
clean:
	rm -f DTAnalysis
	rm -f testMassFit
	rm -f doBetastarFits
	rm -f doTimeIntegratedSystematics
	rm -f SingleBinFit
	rm -f doTimeDepSysts
	rm -f doWSRSmatch
	rm -f doTheSlowPionStudy
	rm -f extractRSTimeDep
	rm -rf testTimeDepLinFit
	rm -f D0massFit
	rm -f FindAl0muon
	rm -f extractTotTimeDep
	rm -f extractRSoverRSfromfile
#	rm -rf *dSYM
