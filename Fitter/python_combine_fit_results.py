#!/usr/bin/python
import sys, os
from ROOT import *
import numpy as np
if len(sys.argv)<4:
    print "didn't pass three files!"
    sys.exit()
print 'will open %s, %s and %s'%(sys.argv[1],sys.argv[2],sys.argv[3])

gROOT.ProcessLine(".X private/stye_file/lhcbStyle.C");

f1 = TFile.Open(sys.argv[1])
f2 = TFile.Open(sys.argv[2])
f3 = TFile.Open(sys.argv[3])
savename = sys.argv[4]
path1=sys.argv[1].split('/')
path2=sys.argv[2].split('/')
path3=sys.argv[3].split('/')

path1.pop(-1)
path2.pop(-1)
path3.pop(-1)

the_thing1 = path1[0]
path1.pop(0)
for thing in path1:
    the_thing1=the_thing1+"_%s"%thing

the_thing2 = path2[0]
path2.pop(0)
for thing in path2:
    the_thing2=the_thing2+"_%s"%thing

the_thing3 = path3[0]
path3.pop(0)
for thing in path3:
    the_thing3 = the_thing3+"_%s"%thing
    
mixingFitPos = f1.Get('%s_mixingtheFitPos'%the_thing1)
mixingFitNeg = f1.Get('%s_mixingtheFitNeg'%the_thing1)
mixingDataPos = f1.Get("%s_mixingr_plus_graph"%the_thing1)
mixingDataNeg = f1.Get("%s_mixingr_mins_graph"%the_thing1)

for dataset in [mixingDataPos,mixingDataNeg]:
    dataset.GetYaxis().SetRangeUser(2.95,5.95)

noDCPVFitPos = f2.Get('%s_noDCPVtheFitPos'%the_thing2)
noDCPVFitNeg = f2.Get('%s_noDCPVtheFitNeg'%the_thing2)
#noDCPVDataPos = f2.Get("%s_noDCPVr_plus_graph"%the_thing2)
#noDCPVDataNeg = f2.Get("%s_noDCPVr_mins_graph"%the_thing2)

allCPVFitPos = f3.Get('%s_allCPVtheFitPos'%the_thing3)
allCPVFitNeg = f3.Get('%s_allCPVtheFitNeg'%the_thing3)
#allCPVDataPos = f3.Get("%s_allCPVr_plus_graph"%the_thing3)
#allCPVDataNeg = f3.Get("%s_allCPVr_mins_graph"%the_thing3)
for fit in [mixingFitPos,mixingFitNeg]:
    fit.SetLineColor(kBlue)
for fit in [noDCPVFitPos,noDCPVFitNeg]:
    fit.SetLineStyle(kDotted)
    fit.SetLineColor(kBlue)
for fit in [allCPVFitPos,allCPVFitNeg]:
    fit.SetLineStyle(kDashed)
    fit.SetLineColor(kBlue)
#mixingDataNeg.SetMarkerColor(kRed)
#allCPVDataNeg.SetMarkerColor(kBlue)
# mixingDataNeg.SetLineColor(kRed)
leg = TLegend(0.5,0.2,0.7,0.5)
leg.AddEntry(mixingFitPos,"Mixing Only","l")
leg.AddEntry(noDCPVFitPos,"No Direct CPV","l")
leg.AddEntry(allCPVFitPos,"All CPV allowed","l")
cc = TCanvas("cc","cc",800,800)
#cc = TCanvas("cc","cc",800,1200)
cc.Divide(1,2,0,0)
cc.cd(1)
cc.cd(1).SetRightMargin(0.02)
mixingDataPos.Draw("ap")
mixingFitPos.Draw("same")
noDCPVFitPos.Draw("same")
allCPVFitPos.Draw("same")
leg.Draw()
cc.cd(2)
cc.cd(2).SetRightMargin(0.02)
mixingDataNeg.Draw("ap")
mixingFitNeg.Draw("same")
noDCPVFitNeg.Draw("same")
allCPVFitNeg.Draw("same")
# cc.cd(3)
# cc.cd(3).SetRightMargin(0.02)
# #make the difference graphs
# grDiff = TGraphErrors(5)
# for i in range(5):
#     theposX,theposY=Double(0),Double(0)
#     mixingDataPos.GetPoint(i,theposX,theposY)
#     thenegX,thenegY=Double(0),Double(0)
#     mixingDataNeg.GetPoint(i,thenegX,thenegY)
#     grDiff.SetPoint(i, (theposX+thenegX)/2., theposY-thenegY)
#     grDiff.SetPointError(i,0,(mixingDataPos.GetErrorY(i)**2. + mixingDataNeg.GetErrorY(i)**2.)**0.5)
# grDiff.Draw("ap")
# noDCPVDataNeg.Draw("psame")
# allCPVDataNeg.Draw("psame")
# mixingFitPos.Draw("same")
# mixingFitNeg.SetLineColor(kRed)
# mixingFitNeg.Draw("same")
cc.SaveAs(savename+".pdf")

# f2.ls()
# f3.ls()
