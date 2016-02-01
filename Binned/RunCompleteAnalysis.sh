#!/bin/bash
#Code for running the complete analysis chain after all the histogram files have been generated. To generate histogram files, run ./DTAnalysis files after rerunning.
#also included a line that if there is no fit model, you assume you're starting from scratch.
echo 'Starting code for running complete analysis.'
#defaults
SCRIPTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo $SCRIPTDIR

CURRDIR="$(pwd)"
echo $CURRDIR

ARGV=("$@")
ARGC=("$#")
#echo $ARGV
#echo $ARGC
FITNAME=$CURRDIR/SavedFits/"rs_j3gfitModel.root"
DATADIR='~/private/data'
ROOTFILES="${DATADIR}/*.root"

#echo 'Do you already have a fit model? [1 or 0]'
#read FITEXISTS
FITEXISTS=0
DOSYSTEMATICS=1
#add parsing options for input data and cuts.
while getopts "hf:x:m:s:" arg; do
    case "${arg}" in
	h)
	    echo "This script runs the entire analysis of the B->mu D* X WS mixing/CPV"
	    echo "The optional arguments are"
	    echo "-m PATH/fitmodel.root provides the path to the RS fit model to use"
	    echo "-x CUTS is a cutstring for using extra cuts"
	    echo "-f ROOTFILES is the files to process in the very first step of the analysis."
	    echo "-s DOSYSTS, where DOSYSTS is 1 or 0, a boolean to do systematics"
	    exit 1
	    ;;
	f)
	    ROOTFILES="${OPTARG}"
	    echo "modified rootfiles to" ${ROOTFILES}
	    ;;
	x)
	    EXTRACUTS="${OPTARG}"
	    echo "using extra cuts " $EXTRACUTS
	    ;;
	m)
	    FITNAME="${OPTARG}"
	    FITEXISTS=1
	    echo 'set fit name to' ${FITNAME}
	    ;;
	s)
	    DOSYSTEMATICS="${OPTARG}"
	    echo "do systematics " ${DOSYSTEMATICS}
	    ;;
    esac
    done


#Bad arguments


echo "EXTRACUTS = ${EXTRACUTS}"
echo "ROOTFILES = ${ROOTFILES}"
echo "FITNAME   = ${FITNAME}"

#####HERE

# #-1. Make sure that directories for betastar exist

if [ ! -d "$CURRDIR/SavedFits/betastar" ]; then
    echo 'making betastar directory';
    mkdir -p $CURRDIR/SavedFits/betastar
fi

if [ "$FITEXISTS" -ne "1" ]; then
    #0. Run the ntuple maker for the jobs
    echo 'starting from scratch'
    if [[ -z "$EXTRACUTS" ]]; then #no extra cuts exist
	$SCRIPTDIR/DTAnalysis $ROOTFILES | tee $CURRDIR/ana.out;
    else
	$SCRIPTDIR/DTAnalysis $ROOTFILES --extraCuts="${EXTRACUTS}"| tee $CURRDIR/ana.out;
    fi
    #1. Run the mass fit for the RS sample to generate the fit model
    echo 'no fit model';
    $SCRIPTDIR/testMassFit $CURRDIR/SavedFits/rs_mass.root | tee $CURRDIR/rs_fit.out;
fi
# #do the validation
$SCRIPTDIR/testMassFit $CURRDIR/SavedFits/rs_mass.root $FITNAME | tee $CURRDIR/rs_validation_fit.out
#2. Run the WS fit time independent
$SCRIPTDIR/testMassFit $CURRDIR/SavedFits/ws_mass.root $FITNAME | tee $CURRDIR/ws_validation_fit.out
#3. Betastar
#needs input from RS decay time
$SCRIPTDIR/extractRSTimeDep $CURRDIR/SavedFits/rs_mass.root $FITNAME | tee $CURRDIR/betastar_time_dep_fits.out

$SCRIPTDIR/doBetastarFits $CURRDIR/SavedFits/betastar/RS_betastar_plots.root $CURRDIR/SavedFits/betastar/RS_ss_betastar_plots.root $FITNAME | tee $CURRDIR/betastar_rs.out
$SCRIPTDIR/doBetastarFits $CURRDIR/SavedFits/betastar/WS_betastar_plots.root $CURRDIR/SavedFits/betastar/WS_ss_betastar_plots.root $FITNAME | tee $CURRDIR/betastar_ws.out
#4. Time dependent fits
$SCRIPTDIR/extractTotTimeDep $CURRDIR/SavedFits/rs_mass.root $FITNAME $CURRDIR/SavedFits/ws_mass.root | tee $CURRDIR/final_time_dep_extraction.out
#change the permissions
chmod go-rwx $CURRDIR/SavedFits/final_yields_in_bins_pos.txt
chmod go-rwx $CURRDIR/SavedFits/final_yields_in_bins_neg.txt
chmod u-r $CURRDIR/SavedFits/final_yields_in_bins_pos.txt
chmod u-r $CURRDIR/SavedFits/final_yields_in_bins_neg.txt
#5. systematic uncertainties.
if [ "$DOSYSTEMATICS" -ne "0" ]; then
#time independent
    $SCRIPTDIR/doTimeIntegratedSystematics $CURRDIR/SavedFits/rs_mass.root $FITNAME | tee $CURRDIR/time_integrated_systematics.out
#time dependent
    $SCRIPTDIR/doTimeDepSysts $CURRDIR/SavedFits/rs_mass.root $FITNAME | tee $CURRDIR/time_dependent_systematics.out
fi
# #6. Compile all the results into the correct format

unset EXTRACUTS
unset ROOTFILES
unset FITNAME
