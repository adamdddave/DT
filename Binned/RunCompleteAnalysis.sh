#!/bin/bash
#Code for running the complete analysis chain after all the histogram files have been generated. To generate histogram files, run ./DTAnalysis files after rerunning.
#also included a line that if there is no fit model, you assume you're starting from scratch.
echo 'Starting code for running complete analysis.'

ARGV=("$@")
ARGC=("$#")
#echo $ARGV
#echo $ARGC
DATADIR='~/private/data'
#echo 'Do you already have a fit model? [1 or 0]'
#read FITEXISTS
FITEXISTS=$ARGC
echo 'fit exists = ' $FITEXISTS
FITNAME='rs_j3gfitModel'

SCRIPTDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo $SCRIPTDIR

CURRDIR="$(pwd)"
echo $CURRDIR
#-1. Make sure that directories for betastar exist
if [ ! -d "$CURRDIR/SavedFits/betastar" ]; then
    echo 'making betastar directory';
    mkdir $CURRDIR/SavedFits/betastar
fi

if [ "$FITEXISTS" -ne "1" ]; then
    #0. Run the ntuple maker for the jobs
    echo 'starting from scratch'
    $SCRIPTDIR/DTAnalysis $DATADIR/*.root | tee $CURRDIR/ana.out;
    #1. Run the mass fit for the RS sample to generate the fit model
    echo 'no fit model';
    $SCRIPTDIR/testMassFit $CURRDIR/SavedFits/rs_mass.root | tee $CURRDIR/rs_fit.out;
fi
#do the validation
$SCRIPTDIR/testMassFit $CURRDIR/SavedFits/rs_mass.root $CURRDIR/SavedFits/$FITNAME.root | tee $CURRDIR/rs_validation_fit.out
#2. Run the WS fit time independent
$SCRIPTDIR/testMassFit $CURRDIR/SavedFits/ws_mass.root $CURRDIR/SavedFits/$FITNAME.root | tee $CURRDIR/ws_validation_fit.out
#3. Betastar
#needs input from RS decay time
$SCRIPTDIR/extractRSTimeDep $CURRDIR/SavedFits/rs_mass.root $CURRDIR/SavedFits/$FITNAME.root | tee $CURRDIR/betastar_time_dep_fits.out

$SCRIPTDIR/doBetastarFits $CURRDIR/SavedFits/betastar/RS_betastar_plots.root $CURRDIR/SavedFits/betastar/RS_ss_betastar_plots.root $CURRDIR/SavedFits/$FITNAME.root | tee $CURRDIR/betastar_rs.out
$SCRIPTDIR/doBetastarFits $CURRDIR/SavedFits/betastar/WS_betastar_plots.root $CURRDIR/SavedFits/betastar/WS_ss_betastar_plots.root $CURRDIR/SavedFits/$FITNAME.root | tee $CURRDIR/betastar_ws.out
#4. Time dependent fits
$SCRIPTDIR/extractTotTimeDep $CURRDIR/SavedFits/rs_mass.root $CURRDIR/SavedFits/$FITNAME.root $CURRDIR/SavedFits/ws_mass.root | tee $CURRDIR/final_time_dep_extraction.out
#change the permissions
chmod go-rwx $CURRDIR/SavedFits/final_yields_in_bins_pos.txt
chmod go-rwx $CURRDIR/SavedFits/final_yields_in_bins_neg.txt
chmod u-r $CURRDIR/SavedFits/final_yields_in_bins_pos.txt
chmod u-r $CURRDIR/SavedFits/final_yields_in_bins_neg.txt
#5. systematic uncertainties.
#time independent
$SCRIPTDIR/doTimeIntegratedSystematics $CURRDIR/SavedFits/rs_mass.root $CURRDIR/SavedFits/$FITNAME.root | tee $CURRDIR/time_integrated_systematics.out
#time dependent
$SCRIPTDIR/doTimeDepSysts $CURRDIR/SavedFits/rs_mass.root $CURRDIR/SavedFits/$FITNAME.root | tee $CURRDIR/time_dependent_systematics.out

#6. Compile all the results into the correct format 
