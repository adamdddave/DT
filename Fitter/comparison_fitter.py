#!/usr/bin/python
###implementation of the chi2 fit to minuit for checking multiple results.
import sys
from ROOT import *
from array import array
import numpy as np
from numpy.linalg import *
results= []
nthings= 0
# def theChi2(res,par):
#     mat = np.linalg.inv(res['covMatrix'])
#     vec = np.array([p for p in par])
#     diff = vec-res['final_result']
#     tmp=np.dot(mat,diff)
#     chi2=np.dot(diff,tmp)
#     print 'using chi2 = %f'%chi2
#     return chi2

def fcn(npar,gin, f, par, iflag):
    global results
    global nthings
    ##print 'using', results
    #get chi2 contribution of each fit
    chi2=0
    ##print 'calling chi2'
    ##print nthings
    for res in results:
        mat = np.linalg.inv(res['covMatrix'])
        vec = np.array([par[i] for i in range(nthings)])
        ##print vec
        diff = vec-res['final_result']
        tmp=np.dot(mat,diff)
        chi2+=np.dot(diff,tmp)
        ##print 'using chi2 = %f'%chi2
    f[0]= chi2 #some stupid shit here.
    
    #sys.exit()

class comparison_fitter():
    def __init__(self,reses):
        #reses here is a vector of mixing fits, or no dcpv or all cpv fits. not the combination
        global results
        global nthings
        results = reses
        self.results = reses
        self.nParams = len(self.results[0]['final_result'])
        self.nResults = len(self.results)
        print 'initialized with %d results and %d params'%(self.nResults,self.nParams)
        self.Minuit = TMinuit(self.nParams)
        self.Minuit.SetFCN(fcn)

        if self.nParams==3:
            print 'mixing combination'
            nthings=3
            rdmean = np.mean([res['R_D'] for res in self.results])
            ypmean = np.mean([res['yprime'] for res in self.results])
            xp2mean = np.mean([res['xprime2'] for res in self.results])
            #print [rdmean, ypmean,xp2mean]
            self.Minuit.DefineParameter(0,'R_D',np.floor(rdmean),1e-3,0.,0.)
            self.Minuit.DefineParameter(1,"y'",np.floor(ypmean),1e-2,0.,0.)
            self.Minuit.DefineParameter(2,"x'2",np.floor(xp2mean),1e-2,0.,0.)
        elif self.nParams==5:
            nthings=5
            rdmean = np.floor(np.mean([res['R_D'] for res in self.results]))
            yppmean = np.floor(np.mean([res['yprime+'] for res in self.results]))
            xp2pmean = np.floor(np.mean([res['xprime2+'] for res in self.results]))
            ypmmean = np.floor(np.mean([res['yprime-'] for res in self.results]))
            xp2mmean = np.floor(np.mean([res['xprime2-'] for res in self.results]))
            self.Minuit.DefineParameter(0,'R_D',rdmean,1e-3,0.,0.)
            self.Minuit.DefineParameter(1,"y'+",yppmean,1e-2,0.,0.)
            self.Minuit.DefineParameter(2,"x'2+",xp2pmean,1e-2,0.,0.)
            self.Minuit.DefineParameter(3,"y'-",ypmmean,1e-2,0.,0.)
            self.Minuit.DefineParameter(4,"x'2-",xp2mmean,1e-2,0.,0.)
        else:
            nthings=6
            rdpmean = np.mean([res['R_D+'] for res in self.results])
            yppmean = np.mean([res['yprime+'] for res in self.results])
            xp2pmean = np.mean([res['xprime2+'] for res in self.results])
            rdmmean = np.mean([res['R_D-'] for res in self.results])
            ypmmean = np.mean([res['yprime-'] for res in self.results])
            xp2mmean = np.mean([res['xprime2-'] for res in self.results])
            self.Minuit.DefineParameter(0,'R_D+',rdpmean,1e-3,0.,0.)
            self.Minuit.DefineParameter(1,"y'+",yppmean,1e-2,0.,0.)
            self.Minuit.DefineParameter(2,"x'2+",xp2pmean,1e-2,0.,0.)
            self.Minuit.DefineParameter(3,'R_D-',rdmmean,1e-3,0.,0.)
            self.Minuit.DefineParameter(4,"y'-",ypmmean,1e-2,0.,0.)
            self.Minuit.DefineParameter(5,"x'2-",xp2mmean,1e-2,0.,0.)
    def fit(self):
        arglist = array('d',2*[0.])
        arglist[0]=500000.
        arglist[1]=0.0001
        self.Minuit.Command("MIGRAD %d %f"%(arglist[0],arglist[1]))
    def chi2(self):
        return self.Minuit.fAmin#the chi2 value
