#!/usr/bin/python
"""
A quick script to make all the tables from all the systematic checks we tried.

"""
import sys, os
from ROOT import *
gROOT.ProcessLine(".X /home/davis3a4/private/stye_file/lhcbStyle.C");
import numpy as np
from numpy.linalg import *


#function to read the result from a file
def makeResultMixing(filename,result):
    doneReading= False
    file2read = open(filename)
    while not doneReading:
        line =file2read.readline()
        if not line: doneReading=True
        if 'Correlation matrix' in line:
            print 'reading correlation matrix'
            result['corrMatrix'] = np.eye(3)#for mixing only
            for i in range(3):line = file2read.readline()
            result['corrMatrix'][0,1] = float(line.split()[1])
            result['corrMatrix'][1,0] = float(line.split()[1])
            line = file2read.readline()
            result['corrMatrix'][0,2] = float(line.split()[1])
            result['corrMatrix'][1,2] = float(line.split()[2])
            
            result['corrMatrix'][2,0] = float(line.split()[1])
            result['corrMatrix'][2,1] = float(line.split()[2])
            #print line.split()
            #print result['corrMatrix']
            #covariance = err(x)*err(y)*corr(x,y)
            result['covMatrix']=np.eye(3)
            doneReading = True
            break
        if "R_D+" in line:
            result['R_D']=[float(line.split()[1]),float(line.split()[2])]
        if "x'2+" in line:
            result['xprime2']=[float(line.split()[1]),float(line.split()[2])]
        if "y'+" in line:
            result['yprime']=[float(line.split()[1]),float(line.split()[2])]
        if "chi2" in line:
            result["chi2"]=line.split()[1]
    file2read.close()
    result['covMatrix'][0,0]=result['corrMatrix'][0,0]*result['R_D'][1]*result['R_D'][1]
    result['covMatrix'][0,1]=result['corrMatrix'][0,1]*result['R_D'][1]*result['yprime'][1]
    result['covMatrix'][0,2]=result['corrMatrix'][0,2]*result['R_D'][1]*result['xprime2'][1]
    result['covMatrix'][1,1]=result['corrMatrix'][1,1]*result['yprime'][1]*result['yprime'][1]
    result['covMatrix'][1,2]=result['corrMatrix'][1,2]*result['yprime'][1]*result['xprime2'][1]
    result['covMatrix'][2,2]=result['corrMatrix'][2,2]*result['xprime2'][1]*result['xprime2'][1]
    #make symmetric
    result['covMatrix'][1,0]=result['covMatrix'][0,1]
    result['covMatrix'][2,0]=result['covMatrix'][0,2]
    result['covMatrix'][2,1]=result['covMatrix'][1,2]
    #finally, add another thing for use with the chi2
    result['final_result']=np.array([result['R_D'],result['yprime'],result['xprime2']])
    
def makeResultNoDCPV(filename,result):
    #print 'opening ', filename
    doneReading = False
    file2read=open(filename)
    while not doneReading:
        line = file2read.readline()
        #print line
        #print line.split()
        if 'Correlation matrix' in line:
            result['corrMatrix']=np.eye(5)#for no dcpv
            for i in range(3):line = file2read.readline()
            result['corrMatrix'][0,1] =float(line.split()[1])
            result['corrMatrix'][1,0] =float(line.split()[1])
            line = file2read.readline()
            result['corrMatrix'][0,2] = float(line.split()[1])
            result['corrMatrix'][1,2] = float(line.split()[2])
            result['corrMatrix'][2,0] = float(line.split()[1])
            result['corrMatrix'][2,1] = float(line.split()[2])
            line = file2read.readline()
            result['corrMatrix'][0,3] = float(line.split()[1])
            result['corrMatrix'][1,3] = float(line.split()[2])
            result['corrMatrix'][2,3] = float(line.split()[3])
            result['corrMatrix'][3,0] = float(line.split()[1])
            result['corrMatrix'][3,1] = float(line.split()[2])
            result['corrMatrix'][3,2] = float(line.split()[3])
            line = file2read.readline()
            result['corrMatrix'][0,4] = float(line.split()[1])
            result['corrMatrix'][1,4] = float(line.split()[2])
            result['corrMatrix'][2,4] = float(line.split()[3])
            result['corrMatrix'][3,4] = float(line.split()[4])
            
            result['corrMatrix'][4,0] = float(line.split()[1])
            result['corrMatrix'][4,1] = float(line.split()[2])
            result['corrMatrix'][4,2] = float(line.split()[3])
            result['corrMatrix'][4,3] = float(line.split()[4])
            doneReading = True
            break
        if "R_D+" in line:
            result['R_D']=[float(line.split()[1]),float(line.split()[2])]
        if "x'2+" in line:
            result['xprime2+']=[float(line.split()[1]),float(line.split()[2])]
        if "y'+" in line:
            result['yprime+']=[float(line.split()[1]),float(line.split()[2])]
        if "x'2-" in line:
            result['xprime2-']=[float(line.split()[1]),float(line.split()[2])]
        if "y'-" in line:
            result['yprime-']=[float(line.split()[1]),float(line.split()[2])]
        if "chi2" in line:
            result["chi2"]=line.split()[1]
    file2read.close()
    result['covMatrix']=np.eye(5)#for no dcpv
    #covariance matrix. cov(x,y)=err(x)*err(y)*corr(x,y)
    result['covMatrix'][0,0]=result['corrMatrix'][0,0]*result['R_D'][1]*result['R_D'][1]
    result['covMatrix'][0,1]=result['corrMatrix'][0,1]*result['R_D'][1]*result['yprime+'][1]

    result['covMatrix'][0,2]=result['corrMatrix'][0,2]*result['R_D'][1]*result['xprime2+'][1]
    result['covMatrix'][0,3]=result['corrMatrix'][0,3]*result['R_D'][1]*result['yprime-'][1]
    result['covMatrix'][0,4]=result['corrMatrix'][0,4]*result['R_D'][1]*result['xprime2-'][1]
    #
    result['covMatrix'][1,1]=result['corrMatrix'][1,1]*result['yprime+'][1]*result['yprime+'][1]
    result['covMatrix'][1,2]=result['corrMatrix'][1,2]*result['yprime+'][1]*result['xprime2+'][1]
    result['covMatrix'][1,3]=result['corrMatrix'][1,3]*result['yprime+'][1]*result['yprime-'][1]
    result['covMatrix'][1,4]=result['corrMatrix'][1,4]*result['yprime+'][1]*result['xprime2-'][1]
    #
    result['covMatrix'][2,2]=result['corrMatrix'][2,2]*result['xprime2+'][1]*result['xprime2+'][1]
    result['covMatrix'][2,3]=result['corrMatrix'][2,3]*result['xprime2+'][1]*result['yprime-'][1]
    result['covMatrix'][2,4]=result['corrMatrix'][2,4]*result['xprime2+'][1]*result['xprime2-'][1]
    #
    result['covMatrix'][3,3]=result['corrMatrix'][3,3]*result['yprime-'][1]*result['yprime-'][1]
    result['covMatrix'][3,4]=result['corrMatrix'][3,4]*result['yprime-'][1]*result['xprime2-'][1]
    #
    result['covMatrix'][4,4]=result['corrMatrix'][4,4]*result['xprime2-'][1]*result['xprime2-'][1]
    #make symmetric
    result['covMatrix'][1,0]=result['covMatrix'][0,1]
    result['covMatrix'][2,0]=result['covMatrix'][0,2]
    result['covMatrix'][3,0]=result['covMatrix'][0,3]
    result['covMatrix'][4,0]=result['covMatrix'][0,4]
    #
    result['covMatrix'][2,1]=result['covMatrix'][1,2]
    result['covMatrix'][3,1]=result['covMatrix'][1,3]
    result['covMatrix'][4,1]=result['covMatrix'][1,4]
    #
    result['covMatrix'][3,2]=result['covMatrix'][2,3]
    result['covMatrix'][4,2]=result['covMatrix'][2,4]
    #
    result['covMatrix'][4,3]=result['covMatrix'][3,4]
    #
    result['final_result']=np.array([result['R_D'],
                                     result['yprime+'],
                                     result['xprime2+'],
                                     result['yprime-'],
                                     result['xprime2-']])

def makeResultAllCPV(filename,result):
    doneReading = False
    file2read=open(filename)
    while not doneReading:
        line = file2read.readline()
        #print line
        #print line.split()
        if 'Correlation matrix' in line:
            result['corrMatrix']=np.eye(6)#all cpv
            for i in range(3):line = file2read.readline()
            result['corrMatrix'][0,1] =float(line.split()[1])
            result['corrMatrix'][1,0] =float(line.split()[1])
            line = file2read.readline()
            result['corrMatrix'][0,2] = float(line.split()[1])
            result['corrMatrix'][1,2] = float(line.split()[2])
            result['corrMatrix'][2,0] = float(line.split()[1])
            result['corrMatrix'][2,1] = float(line.split()[2])
            line = file2read.readline()
            result['corrMatrix'][0,3] = float(line.split()[1])
            result['corrMatrix'][1,3] = float(line.split()[2])
            result['corrMatrix'][2,3] = float(line.split()[3])
            result['corrMatrix'][3,0] = float(line.split()[1])
            result['corrMatrix'][3,1] = float(line.split()[2])
            result['corrMatrix'][3,2] = float(line.split()[3])
            line = file2read.readline()
            result['corrMatrix'][0,4] = float(line.split()[1])
            result['corrMatrix'][1,4] = float(line.split()[2])
            result['corrMatrix'][2,4] = float(line.split()[3])
            result['corrMatrix'][3,4] = float(line.split()[4])
            
            result['corrMatrix'][4,0] = float(line.split()[1])
            result['corrMatrix'][4,1] = float(line.split()[2])
            result['corrMatrix'][4,2] = float(line.split()[3])
            result['corrMatrix'][4,3] = float(line.split()[4])
            line = file2read.readline()
            result['corrMatrix'][0,5] = float(line.split()[1])
            result['corrMatrix'][1,5] = float(line.split()[2])
            result['corrMatrix'][2,5] = float(line.split()[3])
            result['corrMatrix'][3,5] = float(line.split()[4])
            result['corrMatrix'][4,5] = float(line.split()[5])
            
            result['corrMatrix'][5,0] = float(line.split()[1])
            result['corrMatrix'][5,1] = float(line.split()[2])
            result['corrMatrix'][5,2] = float(line.split()[3])
            result['corrMatrix'][5,3] = float(line.split()[4])
            result['corrMatrix'][5,4] = float(line.split()[5])
            doneReading = True
            break
        if "R_D+" in line:
            result['R_D+']=[float(line.split()[1]),float(line.split()[2])]
        if "R_D-" in line:
            result['R_D-']=[float(line.split()[1]),float(line.split()[2])]
        if "x'2+" in line:
            result['xprime2+']=[float(line.split()[1]),float(line.split()[2])]
        if "y'+" in line:
            result['yprime+']=[float(line.split()[1]),float(line.split()[2])]
        if "x'2-" in line:
            result['xprime2-']=[float(line.split()[1]),float(line.split()[2])]
        if "y'-" in line:
            result['yprime-']=[float(line.split()[1]),float(line.split()[2])]
        if "chi2" in line:
            result["chi2"]=line.split()[1]
    file2read.close()
    result['covMatrix']=np.eye(6)#for all cpv
    #covariance matrix. cov(x,y)=err(x)*err(y)*corr(x,y)
    result['covMatrix'][0,0]=result['corrMatrix'][0,0]*result['R_D+'][1]*result['R_D+'][1]
    result['covMatrix'][0,1]=result['corrMatrix'][0,1]*result['R_D+'][1]*result['yprime+'][1]

    result['covMatrix'][0,2]=result['corrMatrix'][0,2]*result['R_D+'][1]*result['xprime2+'][1]
    result['covMatrix'][0,3]=result['corrMatrix'][0,3]*result['R_D+'][1]*result['R_D-'][1]
    result['covMatrix'][0,4]=result['corrMatrix'][0,4]*result['R_D+'][1]*result['yprime-'][1]
    result['covMatrix'][0,5]=result['corrMatrix'][0,5]*result['R_D+'][1]*result['xprime2-'][1]
    #
    result['covMatrix'][1,1]=result['corrMatrix'][1,1]*result['yprime+'][1]*result['yprime+'][1]
    result['covMatrix'][1,2]=result['corrMatrix'][1,2]*result['yprime+'][1]*result['xprime2+'][1]
    result['covMatrix'][1,3]=result['corrMatrix'][1,3]*result['yprime+'][1]*result['R_D-'][1]
    result['covMatrix'][1,4]=result['corrMatrix'][1,4]*result['yprime+'][1]*result['yprime-'][1]
    result['covMatrix'][1,5]=result['corrMatrix'][1,5]*result['yprime+'][1]*result['xprime2-'][1]
    #
    result['covMatrix'][2,2]=result['corrMatrix'][2,2]*result['xprime2+'][1]*result['xprime2+'][1]
    result['covMatrix'][2,3]=result['corrMatrix'][2,3]*result['xprime2+'][1]*result['R_D-'][1]
    result['covMatrix'][2,4]=result['corrMatrix'][2,4]*result['xprime2+'][1]*result['yprime-'][1]
    result['covMatrix'][2,5]=result['corrMatrix'][2,5]*result['xprime2+'][1]*result['xprime2-'][1]
    #
    result['covMatrix'][3,3]=result['corrMatrix'][3,3]*result['R_D-'][1]*result['R_D-'][1]
    result['covMatrix'][3,4]=result['corrMatrix'][3,4]*result['R_D-'][1]*result['yprime-'][1]
    result['covMatrix'][3,5]=result['corrMatrix'][3,5]*result['R_D-'][1]*result['xprime2-'][1]
    #
    result['covMatrix'][4,4]=result['corrMatrix'][4,4]*result['yprime-'][1]*result['yprime-'][1]
    result['covMatrix'][4,5]=result['corrMatrix'][4,5]*result['yprime-'][1]*result['xprime2-'][1]
    #
    result['covMatrix'][5,5]=result['corrMatrix'][5,5]*result['xprime2-'][1]*result['xprime2-'][1]
    #make symmetric
    result['covMatrix'][1,0]=result['covMatrix'][0,1]
    result['covMatrix'][2,0]=result['covMatrix'][0,2]
    result['covMatrix'][3,0]=result['covMatrix'][0,3]
    result['covMatrix'][4,0]=result['covMatrix'][0,4]
    result['covMatrix'][5,0]=result['covMatrix'][0,5]
    #
    result['covMatrix'][2,1]=result['covMatrix'][1,2]
    result['covMatrix'][3,1]=result['covMatrix'][1,3]
    result['covMatrix'][4,1]=result['covMatrix'][1,4]
    result['covMatrix'][5,1]=result['covMatrix'][1,5]
    #
    result['covMatrix'][3,2]=result['covMatrix'][2,3]
    result['covMatrix'][4,2]=result['covMatrix'][2,4]
    result['covMatrix'][5,2]=result['covMatrix'][2,5]
    #
    result['covMatrix'][4,3]=result['covMatrix'][3,4]
    result['covMatrix'][5,3]=result['covMatrix'][3,5]
    result['covMatrix'][5,4]=result['covMatrix'][4,5]
    result['final_result']=np.array([result['R_D+'],
                                     result['yprime+'],
                                     result['xprime2+'],
                                     result['R_D-'],
                                     result['yprime-'],
                                     result['xprime2-']])

def compare_results(res1,res2):
    #take the covariance matrices, and add them.
    mat2inv=res1['covMatrix']+res2['covMatrix']
    mat = np.inv(mat2inv)
    r1=res1['final_result']
    r2=res2['final_result']
    chi2  = np.dot((r1-r2),np.dot(mat,(r1-r2)))#dot product
    return chi2
    
def make_syst_table(name, description, nominal_res, res_tocompare):
    print 'testing chi2 compatibility, chi2=%f , ndf=%f'%(compare_results(nominal_res,res_tocompare),nominal_res['final_result'].size)
    nominal_mixing = nominal_res[0]
    nominal_nodcpv = nominal_res[1]
    nominal_allcpv = nominal_res[2]

    compare_mixing = res_tocompare[0]
    compare_nodcpv = res_tocompare[1]
    compare_allcpv = res_tocompare[2]
    ofile=open(name,'w')
    
    ofile.write("\\begin{table}[htdp]\n")
    ofile.write("\\caption{%s}\n"%description)
    ofile.write("\\begin{center}\n")
    ofile.write("\\begin{tabular}{cccc}\n")
    ofile.write("\\hline\\hline\n")
    ofile.write("Parameter & Central Value & Error & Difference From Nominal \\\\\\hline\n")
    ofile.write("\\multicolumn{4}{c}{No CPV}\\\\\\hline\n")
    ofile.write("$R_D$ & %f & %f & %f \\\\ \n"%(compare_mixing['R_D'][0],compare_mixing['R_D'][1],compare_mixing['R_D'][0]-nominal_mixing['R_D'][0]))
    ofile.write("$x'^2$ & %f & %f & %f \\\\ \n"%(compare_mixing['xprime2'][0],compare_mixing['xprime2'][1],compare_mixing['xprime2'][0]-nominal_mixing['xprime2'][0]))
    ofile.write("$y'$ & %f & %f & %f \\\\ \n"%(compare_mixing['yprime'][0],compare_mixing['yprime'][1],compare_mixing['yprime'][0]-nominal_mixing['yprime'][0]))
    ofile.write("\\multicolumn{4}{c}{$\chi^2$/NDF = %s}\\\\ \n"%compare_mixing['chi2'])
    ofile.write("\\\\\\hline\n")
    ofile.write("\\multicolumn{4}{c}{No Direct CPV}\\\\\\hline\n")
    ofile.write("$R_D$ & %f & %f & %f \\\\ \n"%(compare_nodcpv['R_D'][0],compare_nodcpv['R_D'][1],compare_nodcpv['R_D'][0]-nominal_nodcpv['R_D'][0]))
    ofile.write("$x'^{2+}$ & %f & %f & %f \\\\ \n"%(compare_nodcpv['xprime2+'][0],compare_nodcpv['xprime2+'][1],compare_nodcpv['xprime2+'][0]-nominal_nodcpv['xprime2+'][0]))
    ofile.write("$y'^{+}$ & %f & %f & %f \\\\ \n"%(compare_nodcpv['yprime+'][0],compare_nodcpv['yprime+'][1],compare_nodcpv['yprime+'][0]-nominal_nodcpv['yprime+'][0]))
    ofile.write("$x'^{2-}$ & %f & %f & %f \\\\ \n"%(compare_nodcpv['xprime2-'][0],compare_nodcpv['xprime2-'][1],compare_nodcpv['xprime2-'][0]-nominal_nodcpv['xprime2-'][0]))
    ofile.write("$y'^{-}$ & %f & %f & %f\\\\ \n"%(compare_nodcpv['yprime-'][0],compare_nodcpv['yprime-'][1],compare_nodcpv['yprime-'][0]-nominal_nodcpv['yprime-'][0]))
    ofile.write("\\multicolumn{4}{c}{$\chi^2$/NDF = %s}\\\\ \n"%compare_nodcpv['chi2'])
    ofile.write("\\\\\\hline\n")
    ofile.write("\\multicolumn{4}{c}{All CPV Allowed}\\\\\\hline\n")
    ofile.write("$R_D^+$ & %f & %f & %f \\\\ \n"%(compare_allcpv['R_D+'][0],compare_allcpv['R_D+'][1],compare_allcpv['R_D+'][0]-nominal_allcpv['R_D+'][0]))
    ofile.write("$x'^{2+}$ & %f & %f & %f \\\\ \n"%(compare_allcpv['xprime2+'][0],compare_allcpv['xprime2+'][1],compare_allcpv['xprime2+'][0]-nominal_allcpv['xprime2+'][0]))
    ofile.write("$y'^{+}$ & %f & %f & %f \\\\ \n"%(compare_allcpv['yprime+'][0],compare_allcpv['yprime+'][1],compare_allcpv['yprime+'][0]-nominal_allcpv['yprime+'][0]))
    ofile.write("$R_D^-$ & %f & %f & %f \\\\ \n"%(compare_allcpv['R_D-'][0],compare_allcpv['R_D-'][1],compare_allcpv['R_D-'][0]-nominal_allcpv['R_D-'][0]))
    ofile.write("$x'^{2-}$ & %f & %f & %f \\\\ \n"%(compare_allcpv['xprime2-'][0],compare_allcpv['xprime2-'][1],compare_allcpv['xprime2-'][0]-nominal_allcpv['xprime2-'][0]))
    ofile.write("$y'^{-}$ & %f & %f & %f \\\\ \n"%(compare_allcpv['yprime-'][0],compare_allcpv['yprime-'][1],compare_allcpv['yprime-'][0]-nominal_allcpv['yprime-'][0]))
    ofile.write("\\multicolumn{4}{c}{$\chi^2$/NDF = %s}\\\\ \n"%compare_allcpv['chi2'])
    ofile.write("\\\\\\hline\n")
    ofile.write("\\end{tabular}\n")
    ofile.write("\\end{center}\n")
    ofile.write("\\label{default}\n")
    ofile.write("\\end{table}%\n")
    ofile.close()

#
mixing_res={}
nodcpv_res={}
allcpv_res={}

makeResultMixing("Results/tt_nominal/mixing_only_fit.txt",mixing_res)
makeResultNoDCPV("Results/tt_nominal/noDCPV_fit.txt",nodcpv_res)
makeResultAllCPV("Results/tt_nominal/allCPV_fit.txt",allcpv_res)
#print nodcpv_res

#get the systematic stuff


ssScale_mixing_res={}
ssScale_nodcpv_res={}
ssScale_allcpv_res={}
makeResultMixing("Results/tt_scale_to_sideband/mixing.txt",ssScale_mixing_res)
makeResultNoDCPV("Results/tt_scale_to_sideband/noDCPV.txt",ssScale_nodcpv_res)
makeResultAllCPV("Results/tt_scale_to_sideband/allCPV.txt",ssScale_allcpv_res)

## get MD2011

md2011_mixing_res={}
md2011_nodcpv_res={}
md2011_allcpv_res={}
makeResultMixing("Results/tt_scale_to_sideband/systematics/2011MD/mixing.txt",md2011_mixing_res)
makeResultNoDCPV("Results/tt_scale_to_sideband/systematics/2011MD/noDCPV.txt",md2011_nodcpv_res)
makeResultAllCPV("Results/tt_scale_to_sideband/systematics/2011MD/allCPV.txt",md2011_allcpv_res)

## MU2011


mu2011_mixing_res={}
mu2011_nodcpv_res={}
mu2011_allcpv_res={}
makeResultMixing("Results/tt_scale_to_sideband/systematics/2011MU/mixing.txt",mu2011_mixing_res)
makeResultNoDCPV("Results/tt_scale_to_sideband/systematics/2011MU/noDCPV.txt",mu2011_nodcpv_res)
makeResultAllCPV("Results/tt_scale_to_sideband/systematics/2011MU/allCPV.txt",mu2011_allcpv_res)

###2012


md2012_mixing_res={}
md2012_nodcpv_res={}
md2012_allcpv_res={}
makeResultMixing("Results/tt_scale_to_sideband/systematics/2012MD/mixing.txt",md2012_mixing_res)
makeResultNoDCPV("Results/tt_scale_to_sideband/systematics/2012MD/noDCPV.txt",md2012_nodcpv_res)
makeResultAllCPV("Results/tt_scale_to_sideband/systematics/2012MD/allCPV.txt",md2012_allcpv_res)
## MU2012
mu2012_mixing_res={}
mu2012_nodcpv_res={}
mu2012_allcpv_res={}
makeResultMixing("Results/tt_scale_to_sideband/systematics/2012MU/mixing.txt",mu2012_mixing_res)
makeResultNoDCPV("Results/tt_scale_to_sideband/systematics/2012MU/noDCPV.txt",mu2012_nodcpv_res)
makeResultAllCPV("Results/tt_scale_to_sideband/systematics/2012MU/allCPV.txt",mu2012_allcpv_res)

#MU only
muOnly_mixing_res={}
muOnly_nodcpv_res={}
muOnly_allcpv_res={}
makeResultMixing("Results/tt_scale_to_sideband/systematics/MUonly/mixing.txt",muOnly_mixing_res)
makeResultNoDCPV("Results/tt_scale_to_sideband/systematics/MUonly/noDCPV.txt",muOnly_nodcpv_res)
makeResultAllCPV("Results/tt_scale_to_sideband/systematics/MUonly/allCPV.txt",muOnly_allcpv_res)

#md only
mdOnly_mixing_res={}
mdOnly_nodcpv_res={}
mdOnly_allcpv_res={}
makeResultMixing("Results/tt_scale_to_sideband/systematics/MDonly/mixing.txt",mdOnly_mixing_res)
makeResultNoDCPV("Results/tt_scale_to_sideband/systematics/MDonly/noDCPV.txt",mdOnly_nodcpv_res)
makeResultAllCPV("Results/tt_scale_to_sideband/systematics/MDonly/allCPV.txt",mdOnly_allcpv_res)

#subtract SS time dependence

subtrSS_timedep_mixing_res={}
subtrSS_timedep_nodcpv_res={}
subtrSS_timedep_allcpv_res={}
makeResultMixing("Results/tt_scale_to_sideband/systematics/subtr_SS_time_dep/mixing.txt",subtrSS_timedep_mixing_res)
makeResultNoDCPV("Results/tt_scale_to_sideband/systematics/subtr_SS_time_dep/noDCPV.txt",subtrSS_timedep_nodcpv_res)
makeResultAllCPV("Results/tt_scale_to_sideband/systematics/subtr_SS_time_dep/allCPV.txt",subtrSS_timedep_allcpv_res)

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
ofile.write("$R_D$ & %f & %f \\\\ \n"%(ssScale_mixing_res['R_D'][0],ssScale_mixing_res['R_D'][1]))
ofile.write("$x'^2$ & %f & %f \\\\ \n"%(ssScale_mixing_res['xprime2'][0],ssScale_mixing_res['xprime2'][1]))
ofile.write("$y'$ & %f & %f \\\\ \n"%(ssScale_mixing_res['yprime'][0],ssScale_mixing_res['yprime'][1]))
ofile.write("\\multicolumn{3}{c}{$\chi^2$/NDF = %s}\\\\ \n"%ssScale_mixing_res['chi2'])
ofile.write("\\\\\\hline\n")
ofile.write("\\multicolumn{3}{c}{No Direct CPV}\\\\\\hline\n")
ofile.write("$R_D$ & %f & %f \\\\ \n"%(ssScale_nodcpv_res['R_D'][0],ssScale_nodcpv_res['R_D'][1]))
ofile.write("$x'^{2+}$ & %f & %f \\\\ \n"%(ssScale_nodcpv_res['xprime2+'][0],ssScale_nodcpv_res['xprime2+'][1]))
ofile.write("$y'^{+}$ & %f & %f \\\\ \n"%(ssScale_nodcpv_res['yprime+'][0],ssScale_nodcpv_res['yprime+'][1]))
ofile.write("$x'^{2-}$ & %f & %f \\\\ \n"%(ssScale_nodcpv_res['xprime2-'][0],ssScale_nodcpv_res['xprime2-'][1]))
ofile.write("$y'^{-}$ & %f & %f\\\\ \n"%(ssScale_nodcpv_res['yprime-'][0],ssScale_nodcpv_res['yprime-'][1]))
ofile.write("\\multicolumn{3}{c}{$\chi^2$/NDF = %s}\\\\ \n"%ssScale_nodcpv_res['chi2'])
ofile.write("\\\\\\hline\n")
ofile.write("\\multicolumn{3}{c}{All CPV Allowed}\\\\\\hline\n")
ofile.write("$R_D^+$ & %f & %f \\\\ \n"%(ssScale_allcpv_res['R_D+'][0],ssScale_allcpv_res['R_D+'][1]))
ofile.write("$x'^{2+}$ & %f & %f \\\\ \n"%(ssScale_allcpv_res['xprime2+'][0],ssScale_allcpv_res['xprime2+'][1]))
ofile.write("$y'^{+}$ & %f & %f \\\\ \n"%(ssScale_allcpv_res['yprime+'][0],ssScale_allcpv_res['yprime+'][1]))
ofile.write("$R_D^-$ & %f & %f \\\\ \n"%(ssScale_allcpv_res['R_D-'][0],ssScale_allcpv_res['R_D-'][1]))
ofile.write("$x'^{2-}$ & %f & %f \\\\ \n"%(ssScale_allcpv_res['xprime2-'][0],ssScale_allcpv_res['xprime2-'][1]))
ofile.write("$y'^{-}$ & %f & %f \\\\ \n"%(ssScale_allcpv_res['yprime-'][0],ssScale_allcpv_res['yprime-'][1]))
ofile.write("\\multicolumn{3}{c}{$\chi^2$/NDF = %s}\\\\ \n"%ssScale_allcpv_res['chi2'])
ofile.write("\\\\\\hline\n")
ofile.write("\\end{tabular}\n")
ofile.write("\\end{center}\n")
ofile.write("\\label{default}\n")
ofile.write("\\end{table}%\n")
ofile.close()



#now that we have this, do the tables for the systematics.
make_syst_table("no_scaling_systematic.tex","Systematic based on not scaling SS sideband",
                [ssScale_mixing_res,ssScale_nodcpv_res,ssScale_allcpv_res],
                [mixing_res,nodcpv_res,allcpv_res])

# #timedep scaling systematic
make_syst_table("timedep_scaling_systematic.tex","Systematic based on scaling the SS sideband and allowing the factor to vary with decay time.",
                [ssScale_mixing_res,ssScale_nodcpv_res,ssScale_allcpv_res],
                [subtrSS_timedep_mixing_res, subtrSS_timedep_nodcpv_res,subtrSS_timedep_allcpv_res])

#mag polarity
make_syst_table("magup_vs_nominal_syst.tex","Systematic based on Magnet Polarity of sample.",
                [ssScale_mixing_res,ssScale_nodcpv_res,ssScale_allcpv_res],
                [muOnly_mixing_res, muOnly_nodcpv_res,muOnly_allcpv_res])

make_syst_table("magdown_vs_nominal_syst.tex","Systematic based on Magnet Polarity of sample.",
                [ssScale_mixing_res,ssScale_nodcpv_res,ssScale_allcpv_res],
                [mdOnly_mixing_res, mdOnly_nodcpv_res,mdOnly_allcpv_res])

#individual years
make_syst_table("magup2011_vs_nominal_syst.tex","Systematic based on Magnet Polarity of sample.",
                [ssScale_mixing_res,ssScale_nodcpv_res,ssScale_allcpv_res],
                [mu2011_mixing_res, mu2011_nodcpv_res,mu2011_allcpv_res])

make_syst_table("magdown2011_vs_nominal_syst.tex","Systematic based on Magnet Polarity of sample.",
                [ssScale_mixing_res,ssScale_nodcpv_res,ssScale_allcpv_res],
                [md2011_mixing_res, md2011_nodcpv_res,md2011_allcpv_res])

make_syst_table("magup2012_vs_nominal_syst.tex","Systematic based on Magnet Polarity of sample.",
                [ssScale_mixing_res,ssScale_nodcpv_res,ssScale_allcpv_res],
                [mu2012_mixing_res, mu2012_nodcpv_res,mu2012_allcpv_res])

make_syst_table("magdown2012_vs_nominal_syst.tex","Systematic based on Magnet Polarity of sample.",
                [ssScale_mixing_res,ssScale_nodcpv_res,ssScale_allcpv_res],
                [md2012_mixing_res, md2012_nodcpv_res,md2012_allcpv_res])

#since we're here, let's draw the one sigma contours for the mixing fit only to assess sytematics which may not work.
can = TCanvas("can","can",800,800)
fnom = TFile.Open("Results/tt_scale_to_sideband/mixingnoCPV_xy_contours.root")
grnom = fnom.Get("Results_tt_scale_to_sideband_mixing_1sigma_nocpv_contour")

fnoscale = TFile.Open("Results/tt_nominal/mixingnoCPV_xy_contours.root")
grnoscale = fnoscale.Get("Results_tt_nominal_mixing_1sigma_nocpv_contour")

fscale_td = TFile.Open("Results/tt_scale_to_sideband/systematics/subtr_SS_time_dep/mixingnoCPV_xy_contours.root")
grscale_td = fscale_td.Get("Results_tt_scale_to_sideband_systematics_subtr_SS_time_dep_mixing_1sigma_nocpv_contour")

fMD = TFile.Open("Results/tt_scale_to_sideband/systematics/MDonly/mixingnoCPV_xy_contours.root")
grMD=fMD.Get("Results_tt_scale_to_sideband_systematics_MDonly_mixing_1sigma_nocpv_contour")


fMU = TFile.Open("Results/tt_scale_to_sideband/systematics/MUonly/mixingnoCPV_xy_contours.root")
grMU=fMU.Get("Results_tt_scale_to_sideband_systematics_MUonly_mixing_1sigma_nocpv_contour")


f2011MD = TFile.Open("Results/tt_scale_to_sideband/systematics/2011MD/mixingnoCPV_xy_contours.root")
gr2011MD=f2011MD.Get("Results_tt_scale_to_sideband_systematics_2011MD_mixing_1sigma_nocpv_contour")


f2011MU = TFile.Open("Results/tt_scale_to_sideband/systematics/2011MU/mixingnoCPV_xy_contours.root")
gr2011MU=f2011MU.Get("Results_tt_scale_to_sideband_systematics_2011MU_mixing_1sigma_nocpv_contour")


f2012MD = TFile.Open("Results/tt_scale_to_sideband/systematics/2012MD/mixingnoCPV_xy_contours.root")
gr2012MD=f2012MD.Get("Results_tt_scale_to_sideband_systematics_2012MD_mixing_1sigma_nocpv_contour")


f2012MU = TFile.Open("Results/tt_scale_to_sideband/systematics/2012MU/mixingnoCPV_xy_contours.root")
gr2012MU=f2012MU.Get("Results_tt_scale_to_sideband_systematics_2012MU_mixing_1sigma_nocpv_contour")

grMD.SetLineColor(kBlue);
grMU.SetLineColor(kRed);

gr2011MD.SetLineColor(kBlue);gr2011MD.SetLineStyle(kDashed)
gr2011MU.SetLineColor(kRed);gr2011MU.SetLineStyle(kDashed)
gr2012MD.SetLineColor(kBlue);gr2012MD.SetLineStyle(1)
gr2012MU.SetLineColor(kRed);gr2012MU.SetLineStyle(1)
grnoscale.SetLineColor(kRed);
grscale_td.SetLineColor(kBlue);

things_to_draw = [[grnom,grnoscale],
                  [grnom,grMD,grMU],
                  [grnom,gr2011MD,gr2011MU,gr2012MD,gr2012MU],
                  [grnom,grscale_td]
]

mg = TMultiGraph()
mg.Add(grnom.Clone(),"l")
mg.Add(grnoscale.Clone(),"l")
mg.Draw("al")
mg.SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]")
can.Update()
can.SaveAs("compare_nom_to_no_scale.pdf");
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
mg4.Add(grscale_td.Clone(),"l")
mg4.Draw("al")
mg4.SetTitle(";x'^{2} [10^{-3}];y'[10^{-3}]")
can.Update()
can.SaveAs("compare_td_ssScale.pdf");
can.Clear()

for g in [mg,mg2,mg3,mg4]:
    g=[]
