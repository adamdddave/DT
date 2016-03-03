#!/usr/bin/python
"""
A quick script to make all the tables from all the systematic checks we tried.

"""
import sys, os
from ROOT import *
gROOT.ProcessLine(".X /home/davis3a4/private/stye_file/lhcbStyle.C");
import numpy as np
from numpy.linalg import *
from scipy import stats #pvalue
#import itertools
from result_maker import * #makeResultMixing,noDCPV,allCPV, etc
from comparison_fitter import *

#function to read the result from a file

def compare_results(res1,res2):
    #take the covariance matrices, and add them.
    mat2inv=res1['covMatrix']+res2['covMatrix']
    mat = np.linalg.inv(mat2inv)
    r1=res1['final_result']
    r2=res2['final_result']
    dr = r1-r2
    tmp=np.dot(mat,dr)
    chi2  = np.dot(dr,tmp)#dot product
    return chi2

def compare_mult_results(results):
    #compute the chi2 for the combined results
    chi2=0
    # for comp in comp_list:
    #     chi2 += compare_results(comp[0],comp[1];
    if len(results)==2:
        chi2+=compare_results(results[0],results[1])
    elif len(results)>2:
        fitres = comparison_fitter(results)
        fitres.fit()
        chi2+=fitres.chi2()
        print 'from new chi2 = %f'%fitres.chi2()
    return chi2

def make_syst_table(name, description, nominal_res, results_to_compare):
    ###changed to analyze an arbitrary number of comparison res things
    #this includes how the table is organized.
    #print 'testing chi2 compatibility, chi2=%f , ndf=%f'%(compare_results(nominal_res[0],results_to_compare[0]),nominal_res[0]['final_result'].size)
    nominal_mixing = nominal_res[0]
    nominal_nodcpv = nominal_res[1]
    nominal_allcpv = nominal_res[2]

    ofile=open(name,'w')
    print 'len of results_to_compare[0]= ',len(results_to_compare[0])
    ofile.write("\\begin{table}[!htp]\n")
    ofile.write("\\caption{%s}\n"%description)
    ofile.write("\\begin{center}\n")
    ofile.write("\\begin{tabular}{%s}\n"%('c'*(len(results_to_compare[0])+2)))#param, each result, largest deviation from nominal
    ofile.write("\\hline\\hline\n")
    ofile.write("Parameter [$10^{-3}$]& \multicolumn{%s}{c}{Central Value $\\pm$ Error} & Largest Difference From Nominal \\\\\\hline\n"%len(results_to_compare[0]))
    ofile.write("\\multicolumn{%s}{c}{No CPV}\\\\\\hline\n"%(len(results_to_compare[0])+2))
    
    ofile.write("$R_D$ &")
    for res in results_to_compare[0]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['R_D'][0],res['R_D'][1]))
    max_diff = max(map(lambda x:abs(x['R_D'][0]-nominal_mixing['R_D'][0]), results_to_compare[0]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write("$x'^2$ &")
    for res in results_to_compare[0]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['xprime2'][0],res['xprime2'][1]))
    max_diff = max(map(lambda x:abs(x['xprime2'][0]-nominal_mixing['xprime2'][0]), results_to_compare[0]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write("$y'$ &")
    for res in results_to_compare[0]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['yprime'][0],res['yprime'][1]))
    max_diff = max(map(lambda x:abs(x['yprime'][0]-nominal_mixing['yprime'][0]), results_to_compare[0]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write('Fit $\\chi^2$ &')
    for res in results_to_compare[0]:
        ofile.write('$%s$ &'%(res['chi2']))
    ofile.write(' - \\\\\\hline \n')
    tot_chi2 = compare_mult_results(results_to_compare[0])
    tot_ndf = 3*(len(results_to_compare[0])-1)
    #print'tot chi2/ndf = %f/%d'%(tot_chi2,tot_ndf)
    ofile.write("\\multicolumn{%s}{c}{Compatibility of Samples $\chi^2$/NDF=%f/%d (p=%f)}\\\\ \n"
                %(len(results_to_compare[0])+2,
                  tot_chi2,
                  tot_ndf,
                  1 - stats.chi2.cdf(tot_chi2,tot_ndf)))
                                                                 
    ofile.write("\\\\\\hline\n")
    ofile.write("\\multicolumn{%s}{c}{No Direct CPV}\\\\\\hline\n"%(len(results_to_compare[1])+2))
    
    ofile.write("$R_D$ &")
    for res in results_to_compare[1]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['R_D'][0],res['R_D'][1]))
    max_diff = max(map(lambda x:abs(x['R_D'][0]-nominal_nodcpv['R_D'][0]), results_to_compare[1]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write("$x'^{2+}$ &")
    for res in results_to_compare[1]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['xprime2+'][0],res['xprime2+'][1]))
    max_diff = max(map(lambda x:abs(x['xprime2+'][0]-nominal_nodcpv['xprime2+'][0]), results_to_compare[1]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write("$y'^+$ &")
    for res in results_to_compare[1]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['yprime+'][0],res['yprime+'][1]))
    max_diff = max(map(lambda x:abs(x['yprime+'][0]-nominal_nodcpv['yprime+'][0]), results_to_compare[1]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    
    ofile.write("$x'^{2-}$ &")
    for res in results_to_compare[1]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['xprime2-'][0],res['xprime2-'][1]))
    max_diff = max(map(lambda x:abs(x['xprime2-'][0]-nominal_nodcpv['xprime2-'][0]), results_to_compare[1]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write("$y'^-$ &")
    for res in results_to_compare[1]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['yprime-'][0],res['yprime-'][1]))
    max_diff = max(map(lambda x:abs(x['yprime-'][0]-nominal_nodcpv['yprime-'][0]), results_to_compare[1]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write('Fit $\\chi^2$ &')
    for res in results_to_compare[1]:
        ofile.write('$%s$ &'%(res['chi2']))
    ofile.write(' - \\\\\\hline \n')
    tot_chi2 = compare_mult_results(results_to_compare[1])
    tot_ndf = 5*(len(results_to_compare[1])-1)
    #print'tot chi2/ndf = %f/%d'%(tot_chi2,tot_ndf)
    ofile.write("\\multicolumn{%s}{c}{Compatibility of Samples $\chi^2$/NDF=%f/%d (p=%f)}\\\\ \n"
                %(len(results_to_compare[1])+2,
                  tot_chi2,
                  tot_ndf,
                  1 - stats.chi2.cdf(tot_chi2,tot_ndf)))
                                                                 
    ofile.write("\\\\\\hline\n")
    #ofile.write("\\\\\\hline\n")
    ofile.write("\\multicolumn{4}{c}{All CPV Allowed}\\\\\\hline\n")
    ofile.write("$R_D^+$ &")
    for res in results_to_compare[2]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['R_D+'][0],res['R_D+'][1]))
    max_diff = max(map(lambda x:abs(x['R_D+'][0]-nominal_allcpv['R_D+'][0]), results_to_compare[2]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write("$x'^{2+}$ &")
    for res in results_to_compare[2]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['xprime2+'][0],res['xprime2+'][1]))
    max_diff = max(map(lambda x:abs(x['xprime2+'][0]-nominal_allcpv['xprime2+'][0]), results_to_compare[2]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write("$y'^+$ &")
    for res in results_to_compare[2]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['yprime+'][0],res['yprime+'][1]))
    max_diff = max(map(lambda x:abs(x['yprime+'][0]-nominal_allcpv['yprime+'][0]), results_to_compare[2]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write("$R_D^-$ &")
    for res in results_to_compare[2]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['R_D-'][0],res['R_D-'][1]))
    max_diff = max(map(lambda x:abs(x['R_D-'][0]-nominal_allcpv['R_D-'][0]), results_to_compare[2]))
    ofile.write('%.2f \\\\\n'%(max_diff))
    
    ofile.write("$x'^{2-}$ &")
    for res in results_to_compare[2]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['xprime2-'][0],res['xprime2-'][1]))
    max_diff = max(map(lambda x:abs(x['xprime2-'][0]-nominal_allcpv['xprime2-'][0]), results_to_compare[2]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write("$y'^-$ &")
    for res in results_to_compare[2]:
        ofile.write('$%.2f \\pm %.2f$ &'%(res['yprime-'][0],res['yprime-'][1]))
    max_diff = max(map(lambda x:abs(x['yprime-'][0]-nominal_allcpv['yprime-'][0]), results_to_compare[2]))
    ofile.write('%.2f \\\\\n'%(max_diff))

    ofile.write('Fit $\\chi^2$ &')
    for res in results_to_compare[2]:
        ofile.write('$%s$ &'%(res['chi2']))
    ofile.write(' - \\\\\\hline \n')
    tot_chi2 = compare_mult_results(results_to_compare[2])
    tot_ndf = 6*(len(results_to_compare[2])-1)
    #print'tot chi2/ndf = %f/%d'%(tot_chi2,tot_ndf)
    ofile.write("\\multicolumn{%s}{c}{Compatibility of Samples $\chi^2$/NDF=%f/%d (p=%f)}\\\\ \n"
                %(len(results_to_compare[2])+2,
                  tot_chi2,
                  tot_ndf,
                  1 - stats.chi2.cdf(tot_chi2,tot_ndf)))

    ofile.write("\\\\\\hline\n")
    ofile.write("\\end{tabular}\n")
    ofile.write("\\end{center}\n")
    ofile.write("\\label{default}\n")
    ofile.write("\\end{table}%\n")
    ofile.close()

#start of processing
theCentralValue_mixing_res={}
theCentralValue_nodcpv_res={}
theCentralValue_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/mixing.txt",theCentralValue_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/noDCPV.txt",theCentralValue_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/allCPV.txt",theCentralValue_allcpv_res)

#systematics
## get MD2011

md2011_mixing_res={}
md2011_nodcpv_res={}
md2011_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/2011MD/mixing.txt",md2011_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/2011MD/noDCPV.txt",md2011_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/2011MD/allCPV.txt",md2011_allcpv_res)

## MU2011
mu2011_mixing_res={}
mu2011_nodcpv_res={}
mu2011_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/2011MU/mixing.txt",mu2011_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/2011MU/noDCPV.txt",mu2011_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/2011MU/allCPV.txt",mu2011_allcpv_res)

###MD2012
md2012_mixing_res={}
md2012_nodcpv_res={}
md2012_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/2012MD/mixing.txt",md2012_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/2012MD/noDCPV.txt",md2012_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/2012MD/allCPV.txt",md2012_allcpv_res)

## MU2012
mu2012_mixing_res={}
mu2012_nodcpv_res={}
mu2012_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/2012MU/mixing.txt",mu2012_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/2012MU/noDCPV.txt",mu2012_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/2012MU/allCPV.txt",mu2012_allcpv_res)
##combine everything together
magpols_yr_mixing_res=[md2011_mixing_res,mu2011_mixing_res,md2012_mixing_res,mu2012_mixing_res]
magpols_yr_nodcpv_res=[md2011_nodcpv_res,mu2011_nodcpv_res,md2012_nodcpv_res,mu2012_nodcpv_res]
magpols_yr_allcpv_res=[md2011_allcpv_res,mu2011_allcpv_res,md2012_allcpv_res,mu2012_allcpv_res]
magpols_yr_result=[magpols_yr_mixing_res,magpols_yr_nodcpv_res,magpols_yr_allcpv_res]

#MU only
muOnly_mixing_res={}
muOnly_nodcpv_res={}
muOnly_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/MUonly/mixing.txt",muOnly_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/MUonly/noDCPV.txt",muOnly_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/MUonly/allCPV.txt",muOnly_allcpv_res)

#md only
mdOnly_mixing_res={}
mdOnly_nodcpv_res={}
mdOnly_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/MDonly/mixing.txt",mdOnly_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/MDonly/noDCPV.txt",mdOnly_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/MDonly/allCPV.txt",mdOnly_allcpv_res)
##combo
magpol_mixing = [muOnly_mixing_res,mdOnly_mixing_res]
magpol_nodcpv = [muOnly_nodcpv_res,mdOnly_nodcpv_res]
magpol_allcpv = [muOnly_allcpv_res,mdOnly_allcpv_res]
magpol_result= [magpol_mixing,magpol_nodcpv,magpol_allcpv]
#2011 only
only2011_mixing_res={}
only2011_nodcpv_res={}
only2011_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/2011only/mixing.txt",only2011_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/2011only/noDCPV.txt",only2011_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/2011only/allCPV.txt",only2011_allcpv_res)

#2012 only
only2012_mixing_res={}
only2012_nodcpv_res={}
only2012_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/2012only/mixing.txt",only2012_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/2012only/noDCPV.txt",only2012_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/2012only/allCPV.txt",only2012_allcpv_res)
#combination
yr_mixing=[only2011_mixing_res,only2012_mixing_res]
yr_nodcpv=[only2011_nodcpv_res,only2012_nodcpv_res]
yr_allcpv=[only2011_allcpv_res,only2012_allcpv_res]
yr_result=[yr_mixing,yr_nodcpv,yr_allcpv]

#no scaling
no_scaling_mixing_res={}
no_scaling_nodcpv_res={}
no_scaling_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/no_scaling/mixing.txt",no_scaling_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/no_scaling/noDCPV.txt",no_scaling_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/no_scaling/allCPV.txt",no_scaling_allcpv_res)
print "no scaling mixing\n",no_scaling_mixing_res
print "no scaling nodcpv\n", no_scaling_nodcpv_res
print "no scaling allcpv\n",no_scaling_allcpv_res
no_scaling_mixing=[no_scaling_mixing_res]
no_scaling_nodcpv = [no_scaling_nodcpv_res]
no_scaling_allcpv = [no_scaling_allcpv_res]
noscaling_result = [no_scaling_mixing,no_scaling_nodcpv,no_scaling_allcpv]

#kaon p
kaon_P_bin1_mixing_res={}
kaon_P_bin1_nodcpv_res={}
kaon_P_bin1_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/kaonP/bin1/mixing.txt",kaon_P_bin1_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/kaonP/bin1/noDCPV.txt",kaon_P_bin1_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/kaonP/bin1/allCPV.txt",kaon_P_bin1_allcpv_res)

kaon_P_bin2_mixing_res={}
kaon_P_bin2_nodcpv_res={}
kaon_P_bin2_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/kaonP/bin2/mixing.txt",kaon_P_bin2_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/kaonP/bin2/noDCPV.txt",kaon_P_bin2_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/kaonP/bin2/allCPV.txt",kaon_P_bin2_allcpv_res)

kaon_P_bin3_mixing_res={}
kaon_P_bin3_nodcpv_res={}
kaon_P_bin3_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/kaonP/bin3/mixing.txt",kaon_P_bin3_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/kaonP/bin3/noDCPV.txt",kaon_P_bin3_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/kaonP/bin3/allCPV.txt",kaon_P_bin3_allcpv_res)

kaonP_mixing=[kaon_P_bin1_mixing_res,kaon_P_bin2_mixing_res,kaon_P_bin3_mixing_res]
kaonP_noDCPV=[kaon_P_bin1_nodcpv_res,kaon_P_bin2_nodcpv_res,kaon_P_bin3_nodcpv_res]
kaonP_allCPV=[kaon_P_bin1_allcpv_res,kaon_P_bin2_allcpv_res,kaon_P_bin3_allcpv_res]
kaonP_result=[kaonP_mixing,kaonP_noDCPV,kaonP_allCPV]
#slope to akpip
akpislope_mixing_res={}
akpislope_nodcpv_res={}
akpislope_allcpv_res={}
makeResultMixing("/home/davis3a4/private/analysis/SystematicsFitter_WSFitter_with_DT_aeps_timedep_slope_only/Results/tt_GP035_scale_timedep_with_slope/mixing.txt",akpislope_mixing_res)
makeResultNoDCPV("/home/davis3a4/private/analysis/SystematicsFitter_WSFitter_with_DT_aeps_timedep_slope_only/Results/tt_GP035_scale_timedep_with_slope/noDCPV.txt",akpislope_nodcpv_res)
makeResultAllCPV("/home/davis3a4/private/analysis/SystematicsFitter_WSFitter_with_DT_aeps_timedep_slope_only/Results/tt_GP035_scale_timedep_with_slope/allCPV.txt",akpislope_allcpv_res)

akpi_slope_mixing=[akpislope_mixing_res]
akpi_slope_noDCPV=[akpislope_nodcpv_res]
akpi_slope_allCPV=[akpislope_allcpv_res]
akpi_slope_result = [akpi_slope_mixing,akpi_slope_noDCPV,akpi_slope_allCPV]

# #npvs
# npvs_1_mixing_res={}
# npvs_1_nodcpv_res={}
# npvs_1_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/npvs/1/mixing.txt",npvs_1_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/npvs/1/noDCPV.txt",npvs_1_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/npvs/1/allCPV.txt",npvs_1_allcpv_res)

# #
# npvs_2_mixing_res={}
# npvs_2_nodcpv_res={}
# npvs_2_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/npvs/2/mixing.txt",npvs_2_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/npvs/2/noDCPV.txt",npvs_2_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/npvs/2/allCPV.txt",npvs_2_allcpv_res)
# #
# npvs_g3_mixing_res={}
# npvs_g3_nodcpv_res={}
# npvs_g3_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/npvs/g3/mixing.txt",npvs_g3_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/npvs/g3/noDCPV.txt",npvs_g3_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/npvs/g3/allCPV.txt",npvs_g3_allcpv_res)

#pdstar
# pdstar_bin1_mixing_res={}
# pdstar_bin1_nodcpv_res={}
# pdstar_bin1_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/pdstar/bin1/mixing.txt",pdstar_bin1_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/pdstar/bin1/noDCPV.txt",pdstar_bin1_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/pdstar/bin1/allCPV.txt",pdstar_bin1_allcpv_res)

# pdstar_bin2_mixing_res={}
# pdstar_bin2_nodcpv_res={}
# pdstar_bin2_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/pdstar/bin2/mixing.txt",pdstar_bin2_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/pdstar/bin2/noDCPV.txt",pdstar_bin2_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/pdstar/bin2/allCPV.txt",pdstar_bin2_allcpv_res)

# pdstar_bin3_mixing_res={}
# pdstar_bin3_nodcpv_res={}
# pdstar_bin3_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/pdstar/bin3/mixing.txt",pdstar_bin3_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/pdstar/bin3/noDCPV.txt",pdstar_bin3_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/pdstar/bin3/allCPV.txt",pdstar_bin3_allcpv_res)

# pdstar_bin4_mixing_res={}
# pdstar_bin4_nodcpv_res={}
# pdstar_bin4_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/pdstar/bin4/mixing.txt",pdstar_bin4_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/pdstar/bin4/noDCPV.txt",pdstar_bin4_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/pdstar/bin4/allCPV.txt",pdstar_bin4_allcpv_res)

# pdstar_bin5_mixing_res={}
# pdstar_bin5_nodcpv_res={}
# pdstar_bin5_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/pdstar/bin5/mixing.txt",pdstar_bin5_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/pdstar/bin5/noDCPV.txt",pdstar_bin5_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/pdstar/bin5/allCPV.txt",pdstar_bin5_allcpv_res)
# #

# #ptmu
ptmu_bin1_mixing_res={}
ptmu_bin1_nodcpv_res={}
ptmu_bin1_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/ptmu/bin1/mixing.txt",ptmu_bin1_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/ptmu/bin1/noDCPV.txt",ptmu_bin1_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/ptmu/bin1/allCPV.txt",ptmu_bin1_allcpv_res)

ptmu_bin2_mixing_res={}
ptmu_bin2_nodcpv_res={}
ptmu_bin2_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/ptmu/bin2/mixing.txt",ptmu_bin2_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/ptmu/bin2/noDCPV.txt",ptmu_bin2_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/ptmu/bin2/allCPV.txt",ptmu_bin2_allcpv_res)

ptmu_bin3_mixing_res={}
ptmu_bin3_nodcpv_res={}
ptmu_bin3_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/ptmu/bin3/mixing.txt",ptmu_bin3_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/ptmu/bin3/noDCPV.txt",ptmu_bin3_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/ptmu/bin3/allCPV.txt",ptmu_bin3_allcpv_res)
ptmu_mixing = [ptmu_bin1_mixing_res,ptmu_bin2_mixing_res,ptmu_bin3_mixing_res]
ptmu_noDCPV = [ptmu_bin1_nodcpv_res,ptmu_bin2_nodcpv_res, ptmu_bin3_nodcpv_res]
ptmu_allCPV = [ptmu_bin1_allcpv_res,ptmu_bin2_allcpv_res, ptmu_bin3_allcpv_res]
ptmu_result = [ptmu_mixing,ptmu_noDCPV,ptmu_allCPV]

# #pt slow pion
ptpis_bin1_mixing_res={}
ptpis_bin1_nodcpv_res={}
ptpis_bin1_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/ptpis/bin1/mixing.txt",ptpis_bin1_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/ptpis/bin1/noDCPV.txt",ptpis_bin1_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/ptpis/bin1/allCPV.txt",ptpis_bin1_allcpv_res)

ptpis_bin2_mixing_res={}
ptpis_bin2_nodcpv_res={}
ptpis_bin2_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/ptpis/bin2/mixing.txt",ptpis_bin2_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/ptpis/bin2/noDCPV.txt",ptpis_bin2_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/ptpis/bin2/allCPV.txt",ptpis_bin2_allcpv_res)

ptpis_bin3_mixing_res={}
ptpis_bin3_nodcpv_res={}
ptpis_bin3_allcpv_res={}
makeResultMixing("Results/tt_GP035_scale_timedep/systematics/ptpis/bin3/mixing.txt",ptpis_bin3_mixing_res)
makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/ptpis/bin3/noDCPV.txt",ptpis_bin3_nodcpv_res)
makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/ptpis/bin3/allCPV.txt",ptpis_bin3_allcpv_res)

ptpis_mixing =[ptpis_bin1_mixing_res, ptpis_bin2_mixing_res, ptpis_bin3_mixing_res]
ptpis_noDCPV =[ptpis_bin1_nodcpv_res, ptpis_bin2_nodcpv_res, ptpis_bin3_nodcpv_res]
ptpis_allCPV = [ptpis_bin1_allcpv_res, ptpis_bin2_allcpv_res, ptpis_bin3_allcpv_res]
ptpis_result = [ptpis_mixing,ptpis_noDCPV,ptpis_allCPV]

# #run period
# runperiod_bin1_mixing_res={}
# runperiod_bin1_nodcpv_res={}
# runperiod_bin1_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/runperiod/bin1/mixing.txt",runperiod_bin1_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin1/noDCPV.txt",runperiod_bin1_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin1/allCPV.txt",runperiod_bin1_allcpv_res)

# runperiod_bin2_mixing_res={}
# runperiod_bin2_nodcpv_res={}
# runperiod_bin2_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/runperiod/bin2/mixing.txt",runperiod_bin2_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin2/noDCPV.txt",runperiod_bin2_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin2/allCPV.txt",runperiod_bin2_allcpv_res)

# runperiod_bin3_mixing_res={}
# runperiod_bin3_nodcpv_res={}
# runperiod_bin3_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/runperiod/bin3/mixing.txt",runperiod_bin3_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin3/noDCPV.txt",runperiod_bin3_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin3/allCPV.txt",runperiod_bin3_allcpv_res)

# runperiod_bin4_mixing_res={}
# runperiod_bin4_nodcpv_res={}
# runperiod_bin4_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/runperiod/bin4/mixing.txt",runperiod_bin4_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin4/noDCPV.txt",runperiod_bin4_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin4/allCPV.txt",runperiod_bin4_allcpv_res)

# runperiod_bin5_mixing_res={}
# runperiod_bin5_nodcpv_res={}
# runperiod_bin5_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/runperiod/bin5/mixing.txt",runperiod_bin5_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin5/noDCPV.txt",runperiod_bin5_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin5/allCPV.txt",runperiod_bin5_allcpv_res)

# runperiod_bin6_mixing_res={}
# runperiod_bin6_nodcpv_res={}
# runperiod_bin6_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/runperiod/bin6/mixing.txt",runperiod_bin6_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin6/noDCPV.txt",runperiod_bin6_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin6/allCPV.txt",runperiod_bin6_allcpv_res)

# runperiod_bin7_mixing_res={}
# runperiod_bin7_nodcpv_res={}
# runperiod_bin7_allcpv_res={}
# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/runperiod/bin7/mixing.txt",runperiod_bin7_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin7/noDCPV.txt",runperiod_bin7_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/runperiod/bin7/allCPV.txt",runperiod_bin7_allcpv_res)


# akpi_timedep_mixing_res={}
# akpi_timedep_nodcpv_res={}
# akpi_timedep_allcpv_res={}
# makeResultMixing("/home/davis3a4/private/analysis/SystematicsFitter_WSFitter_with_DT_aeps_timedep/WSFitter-1.3/Results/tt_GP035_scale_timedep/systematics/timedep_akpi/mixing.txt",akpi_timedep_mixing_res)
# makeResultNoDCPV("/home/davis3a4/private/analysis/SystematicsFitter_WSFitter_with_DT_aeps_timedep/WSFitter-1.3/Results/tt_GP035_scale_timedep/systematics/timedep_akpi/noDCPV.txt",akpi_timedep_nodcpv_res)
# makeResultAllCPV("/home/davis3a4/private/analysis/SystematicsFitter_WSFitter_with_DT_aeps_timedep/WSFitter-1.3/Results/tt_GP035_scale_timedep/systematics/timedep_akpi/allCPV.txt",akpi_timedep_allcpv_res)


# akpi_increase1percent_mixing_res={}
# akpi_increase1percent_nodcpv_res={}
# akpi_increase1percent_allcpv_res={}


# makeResultMixing("Results/tt_GP035_scale_timedep/systematics/akpi_increase_by_1percent/mixing.txt",akpi_increase1percent_mixing_res)
# makeResultNoDCPV("Results/tt_GP035_scale_timedep/systematics/akpi_increase_by_1percent/noDCPV.txt",akpi_increase1percent_nodcpv_res)
# makeResultAllCPV("Results/tt_GP035_scale_timedep/systematics/akpi_increase_by_1percent/allCPV.txt",akpi_increase1percent_allcpv_res)
#########
#now the tables

ofile=open("the_central_val_table_blind.tex",'w')

ofile.write("\\begin{table}[htdp]\n")
ofile.write("\\caption{default}\n")
ofile.write("\\begin{center}\n")
ofile.write("\\begin{tabular}{ccc}\n")
ofile.write("\\hline\\hline\n")
ofile.write("Parameter & Central Value & Error \\\\\\hline\n")
ofile.write("\\multicolumn{3}{c}{No CPV}\\\\\\hline\n")
ofile.write("$R_D$ & %f & %f \\\\ \n"%(theCentralValue_mixing_res['R_D'][0],theCentralValue_mixing_res['R_D'][1]))
ofile.write("$x'^2$ & %f & %f \\\\ \n"%(theCentralValue_mixing_res['xprime2'][0],theCentralValue_mixing_res['xprime2'][1]))
ofile.write("$y'$ & %f & %f \\\\ \n"%(theCentralValue_mixing_res['yprime'][0],theCentralValue_mixing_res['yprime'][1]))
ofile.write("\\multicolumn{3}{c}{$\chi^2$/NDF = %s}\\\\ \n"%theCentralValue_mixing_res['chi2'])
ofile.write("\\\\\\hline\n")
ofile.write("\\multicolumn{3}{c}{No Direct CPV}\\\\\\hline\n")
ofile.write("$R_D$ & %f & %f \\\\ \n"%(theCentralValue_nodcpv_res['R_D'][0],theCentralValue_nodcpv_res['R_D'][1]))
ofile.write("$x'^{2+}$ & %f & %f \\\\ \n"%(theCentralValue_nodcpv_res['xprime2+'][0],theCentralValue_nodcpv_res['xprime2+'][1]))
ofile.write("$y'^{+}$ & %f & %f \\\\ \n"%(theCentralValue_nodcpv_res['yprime+'][0],theCentralValue_nodcpv_res['yprime+'][1]))
ofile.write("$x'^{2-}$ & %f & %f \\\\ \n"%(theCentralValue_nodcpv_res['xprime2-'][0],theCentralValue_nodcpv_res['xprime2-'][1]))
ofile.write("$y'^{-}$ & %f & %f\\\\ \n"%(theCentralValue_nodcpv_res['yprime-'][0],theCentralValue_nodcpv_res['yprime-'][1]))
ofile.write("\\multicolumn{3}{c}{$\chi^2$/NDF = %s}\\\\ \n"%theCentralValue_nodcpv_res['chi2'])
ofile.write("\\\\\\hline\n")
ofile.write("\\multicolumn{3}{c}{All CPV Allowed}\\\\\\hline\n")
ofile.write("$R_D^+$ & %f & %f \\\\ \n"%(theCentralValue_allcpv_res['R_D+'][0],theCentralValue_allcpv_res['R_D+'][1]))
ofile.write("$x'^{2+}$ & %f & %f \\\\ \n"%(theCentralValue_allcpv_res['xprime2+'][0],theCentralValue_allcpv_res['xprime2+'][1]))
ofile.write("$y'^{+}$ & %f & %f \\\\ \n"%(theCentralValue_allcpv_res['yprime+'][0],theCentralValue_allcpv_res['yprime+'][1]))
ofile.write("$R_D^-$ & %f & %f \\\\ \n"%(theCentralValue_allcpv_res['R_D-'][0],theCentralValue_allcpv_res['R_D-'][1]))
ofile.write("$x'^{2-}$ & %f & %f \\\\ \n"%(theCentralValue_allcpv_res['xprime2-'][0],theCentralValue_allcpv_res['xprime2-'][1]))
ofile.write("$y'^{-}$ & %f & %f \\\\ \n"%(theCentralValue_allcpv_res['yprime-'][0],theCentralValue_allcpv_res['yprime-'][1]))
ofile.write("\\multicolumn{3}{c}{$\chi^2$/NDF = %s}\\\\ \n"%theCentralValue_allcpv_res['chi2'])
ofile.write("\\\\\\hline\n")
ofile.write("\\end{tabular}\n")
ofile.write("\\end{center}\n")
ofile.write("\\label{default}\n")
ofile.write("\\end{table}%\n")
ofile.close()

# #now that we have this, do the tables for the systematics.
#for result2analyse in [magpols_result]:
the_shiz=[theCentralValue_mixing_res,theCentralValue_nodcpv_res,theCentralValue_allcpv_res]
make_syst_table('magnet_polarity_year_systematic.tex','Comparison of Magnet Polarities split by year',the_shiz,magpols_yr_result)

make_syst_table("magnet_polarity_systematic.tex","Comparison of Magnet Polarities",the_shiz,magpol_result) 

# #individual years
make_syst_table("year_systematic.tex","Comparison of 2011 and 2012",the_shiz,yr_result)

#scaling
make_syst_table("no_ss_scaling.tex","Result of not using the SS scaling",the_shiz,noscaling_result)

#kaon momentum
make_syst_table("kaon_p_systematic.tex","Result split into three bins of Kaon momentum",the_shiz,kaonP_result)

#pt muon
make_syst_table("muon_pt_systematic.tex","Result split into three bins of muon transverse momentum.",the_shiz,ptmu_result)

#pt slow pion
make_syst_table("slow_pion_pt_systematic.tex","Result split into three bins of slow pion transverse momentum.",
                the_shiz, ptpis_result)
#kpi asymmetry with slope
make_syst_table("kpi_asymmetry_slope.tex","Result allowing for the $K\\pi$ asymmetry to take on a time dependence.",
                the_shiz,akpi_slope_result)
#since we're here, let's draw the one sigma contours for the mixing fit only to assess sytematics which may not work.
can = TCanvas("can","can",800,800)
fnom = TFile.Open("Results/tt_GP035_scale_timedep/mixingnoCPV_xy_contours.root")
grnom = fnom.Get("Results_tt_GP035_scale_timedep_mixing_1sigma_nocpv_contour")

#fnoscale = TFile.Open("Results/tt_nominal/mixingnoCPV_xy_contours.root")
#grnoscale = fnoscale.Get("Results_tt_nominal_mixing_1sigma_nocpv_contour")

#fscale_td = TFile.Open("Results/tt_GP035_scale_timedep/systematics/subtr_SS_time_dep/mixingnoCPV_xy_contours.root")
#grscale_td = fscale_td.Get("Results_tt_scale_to_sideband_systematics_subtr_SS_time_dep_mixing_1sigma_nocpv_contour")

fMD = TFile.Open("Results/tt_GP035_scale_timedep/systematics/MDonly/mixingnoCPV_xy_contours.root")
grMD=fMD.Get("Results_tt_GP035_scale_timedep_systematics_MDonly_mixing_1sigma_nocpv_contour")


fMU = TFile.Open("Results/tt_GP035_scale_timedep/systematics/MUonly/mixingnoCPV_xy_contours.root")
grMU=fMU.Get("Results_tt_GP035_scale_timedep_systematics_MUonly_mixing_1sigma_nocpv_contour")


f2011MD = TFile.Open("Results/tt_GP035_scale_timedep/systematics/2011MD/mixingnoCPV_xy_contours.root")
gr2011MD=f2011MD.Get("Results_tt_GP035_scale_timedep_systematics_2011MD_mixing_1sigma_nocpv_contour")


f2011MU = TFile.Open("Results/tt_GP035_scale_timedep/systematics/2011MU/mixingnoCPV_xy_contours.root")
gr2011MU=f2011MU.Get("Results_tt_GP035_scale_timedep_systematics_2011MU_mixing_1sigma_nocpv_contour")


f2012MD = TFile.Open("Results/tt_GP035_scale_timedep/systematics/2012MD/mixingnoCPV_xy_contours.root")
gr2012MD=f2012MD.Get("Results_tt_GP035_scale_timedep_systematics_2012MD_mixing_1sigma_nocpv_contour")


f2012MU = TFile.Open("Results/tt_GP035_scale_timedep/systematics/2012MU/mixingnoCPV_xy_contours.root")
gr2012MU=f2012MU.Get("Results_tt_GP035_scale_timedep_systematics_2012MU_mixing_1sigma_nocpv_contour")


f2011 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/2011only/mixingnoCPV_xy_contours.root")
gr2011=f2011.Get("Results_tt_GP035_scale_timedep_systematics_2011only_mixing_1sigma_nocpv_contour")

f2012 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/2012only/mixingnoCPV_xy_contours.root")
gr2012=f2012.Get("Results_tt_GP035_scale_timedep_systematics_2012only_mixing_1sigma_nocpv_contour")


fNoScaling = TFile.Open("Results/tt_GP035_scale_timedep/systematics/no_scaling/mixingnoCPV_xy_contours.root")
grNoScaling = fNoScaling.Get("Results_tt_GP035_scale_timedep_systematics_no_scaling_mixing_1sigma_nocpv_contour")
# ftimedepAkpi = TFile.Open("/home/davis3a4/private/analysis/SystematicsFitter_WSFitter_with_DT_aeps_timedep/WSFitter-1.3/Results/tt_GP035_scale_timedep/systematics/timedep_akpi/mixingnoCPV_xy_contours.root");
# grtimedepAkpi = ftimedepAkpi.Get("Results_tt_GP035_scale_timedep_systematics_timedep_akpi_mixing_1sigma_nocpv_contour");

fkp1 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/kaonP/bin1/mixingnoCPV_xy_contours.root")
grkp1 = fkp1.Get("Results_tt_GP035_scale_timedep_systematics_kaonP_bin1_mixing_1sigma_nocpv_contour")

fkp2 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/kaonP/bin2/mixingnoCPV_xy_contours.root")
grkp2 = fkp2.Get("Results_tt_GP035_scale_timedep_systematics_kaonP_bin2_mixing_1sigma_nocpv_contour")

fkp3 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/kaonP/bin3/mixingnoCPV_xy_contours.root")
grkp3 = fkp3.Get("Results_tt_GP035_scale_timedep_systematics_kaonP_bin3_mixing_1sigma_nocpv_contour")

#

fmupt1 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/ptmu/bin1/mixingnoCPV_xy_contours.root")
grmupt1 = fmupt1.Get("Results_tt_GP035_scale_timedep_systematics_ptmu_bin1_mixing_1sigma_nocpv_contour")

fmupt2 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/ptmu/bin2/mixingnoCPV_xy_contours.root")
grmupt2 = fmupt2.Get("Results_tt_GP035_scale_timedep_systematics_ptmu_bin2_mixing_1sigma_nocpv_contour")

fmupt3 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/ptmu/bin3/mixingnoCPV_xy_contours.root")
grmupt3 = fmupt3.Get("Results_tt_GP035_scale_timedep_systematics_ptmu_bin3_mixing_1sigma_nocpv_contour")

#
fpispt1 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/ptpis/bin1/mixingnoCPV_xy_contours.root")
grpispt1 = fpispt1.Get("Results_tt_GP035_scale_timedep_systematics_ptpis_bin1_mixing_1sigma_nocpv_contour")

fpispt2 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/ptpis/bin2/mixingnoCPV_xy_contours.root")
grpispt2 = fpispt2.Get("Results_tt_GP035_scale_timedep_systematics_ptpis_bin2_mixing_1sigma_nocpv_contour")

fpispt3 = TFile.Open("Results/tt_GP035_scale_timedep/systematics/ptpis/bin3/mixingnoCPV_xy_contours.root")
grpispt3 = fpispt3.Get("Results_tt_GP035_scale_timedep_systematics_ptpis_bin3_mixing_1sigma_nocpv_contour")

#akpi
fkpislope = TFile.Open("/home/davis3a4/private/analysis/SystematicsFitter_WSFitter_with_DT_aeps_timedep_slope_only/Results/tt_GP035_scale_timedep_with_slope/mixingnoCPV_xy_contours.root")
grkpislope = fkpislope.Get("Results_tt_GP035_scale_timedep_with_slope_mixing_1sigma_nocpv_contour")
grMD.SetLineColor(kBlue);
grMU.SetLineColor(kRed);

gr2011MD.SetLineColor(kBlue);gr2011MD.SetLineStyle(kDashed)
gr2011MU.SetLineColor(kRed);gr2011MU.SetLineStyle(kDashed)
gr2012MD.SetLineColor(kBlue);gr2012MD.SetLineStyle(1)
gr2012MU.SetLineColor(kRed);gr2012MU.SetLineStyle(1)


gr2011.SetLineColor(kRed)
gr2012.SetLineColor(kBlue)
grNoScaling.SetLineColor(kRed);
#grnoscale.SetLineColor(kRed);
#grscale_td.SetLineColor(kBlue);

grkp1.SetLineColor(kBlue)
grkp2.SetLineColor(kRed)
grkp3.SetLineColor(kMagenta)

grmupt1.SetLineColor(kBlue)
grmupt2.SetLineColor(kRed)
grmupt3.SetLineColor(kMagenta)

grpispt1.SetLineColor(kBlue)
grpispt2.SetLineColor(kRed)
grpispt3.SetLineColor(kMagenta)

grkpislope.SetLineColor(kRed)

things_to_draw = [#[grnom,grnoscale],
                  [grnom,grMD,grMU],
                  [grnom,gr2011MD,gr2011MU,gr2012MD,gr2012MU]
                  #                  [grnom,grscale_td]
]

mg = TMultiGraph()
mg.Add(grnom.Clone(),"l")
mg.Add(gr2011.Clone(),"l")
mg.Add(gr2012.Clone(),"l")
mg.Draw("al")
mg.SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]")
can.Update()
can.SaveAs("compare_years.pdf");
can.Clear()


mg2 = TMultiGraph()
mg2.Add(grnom.Clone(),"l")
mg2.Add(grMD.Clone(),"l")
mg2.Add(grMU.Clone(),"l")
mg2.Draw("al")
mg2.SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]")
can.Update()
can.SaveAs("compare_magpols.pdf");
can.Clear()


mg3 = TMultiGraph()
mg3.Add(grnom,"l")
mg3.Add(gr2011MD.Clone(),"l")
mg3.Add(gr2011MU.Clone(),"l")
mg3.Add(gr2012MD.Clone(),"l")
mg3.Add(gr2012MU.Clone(),"l")
mg3.Draw("al")
mg3.SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]")
can.Update()
can.SaveAs("compare_mag_split_year_pols.pdf");
can.Clear()


mg4 = TMultiGraph()
mg4.Add(grnom.Clone(),"l")
mg4.Add(grNoScaling.Clone(),"l")
mg4.Draw("al")
mg4.SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]")
can.Update()
can.SaveAs("compare_no_scaling.pdf");
can.Clear()


mg5 = TMultiGraph()
mg5.Add(grnom.Clone(),"l")
mg5.Add(grkp1.Clone(),"l")
mg5.Add(grkp2.Clone(),"l")
mg5.Add(grkp3.Clone(),"l")
mg5.Draw("al")
mg5.SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]")
can.Update()
can.SaveAs("compare_kaon_momentum_1sig.pdf");
can.Clear()


mg6 = TMultiGraph()
mg6.Add(grnom.Clone(),"l")
mg6.Add(grmupt1.Clone(),"l")
mg6.Add(grmupt2.Clone(),"l")
mg6.Add(grmupt3.Clone(),"l")
mg6.Draw("al")
mg6.SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]")
can.Update()
can.SaveAs("compare_muon_pt_1sig.pdf");
can.Clear()



mg7 = TMultiGraph()
mg7.Add(grnom.Clone(),"l")
mg7.Add(grpispt1.Clone(),"l")
mg7.Add(grpispt2.Clone(),"l")
mg7.Add(grpispt3.Clone(),"l")
mg7.Draw("al")
mg7.SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]")
can.Update()
can.SaveAs("compare_slow_pion_pt_1sig.pdf");
can.Clear()

mg8 = TMultiGraph()
mg8.Add(grnom.Clone(),"l")
mg8.Add(grkpislope.Clone(),"l")
mg8.Draw("al")
mg8.SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]")
can.Update()
can.SaveAs("compare_akpi_slope_timedep_1sig.pdf");
can.Clear()

# for g in [mg,mg2,mg3,mg4]:
#     g=[]
