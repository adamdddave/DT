#!/usr/bin/python
import sys, os
from ROOT import *
import numpy as np
from numpy.linalg import *
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
    result['final_result']=np.array([result['R_D'][0],
                                     result['yprime'][0],
                                     result['xprime2'][0]])
    
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
    result['final_result']=np.array([result['R_D'][0],
                                     result['yprime+'][0],
                                     result['xprime2+'][0],
                                     result['yprime-'][0],
                                     result['xprime2-'][0]])

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
    result['final_result']=np.array([result['R_D+'][0],
                                     result['yprime+'][0],
                                     result['xprime2+'][0],
                                     result['R_D-'][0],
                                     result['yprime-'][0],
                                     result['xprime2-'][0]])
