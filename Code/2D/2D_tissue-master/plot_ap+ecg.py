# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from sys import * 
# from os import *

# plt.figure(figsize=(8,4))
# plt.plot(x,y,label="$sin(x)$",color="red",linewidth=2)
# plt.plot(x,z,"b--",label="$cos(x^2)$")
# plt.xlabel("Time(s)")
# plt.ylabel("Volt")
# plt.title("PyPlot First Example")
# plt.ylim(-1.2,1.2)
# plt.legend()
# plt.show()

# lv=[[],[],[]]

# for i in range(1):
# 	f=i+20
# 	filename='out_cell'+str(f)+'_BCL100.dat'
# 	# print filename
# 	fp=open(filename)
# 	# fp=open('out_cell20_BCL500.dat')
# 	print type(i),i
# 	# print i+2;
   

# One=np.loadtxt('Block_Model_0/AP.BCL.1Hz.Popul.Index.0.AF_Model.3.block.0',unpack=True)
# One=np.loadtxt('OneD_output.dat')#,unpack=True)
One=np.loadtxt('OneD_output.dat.0')#,unpack=True)
# two=np.loadtxt('OneD_output.dat.1')#,unpack=True)
print( len(One[:,1]))
data=One
# data = np.concatenate((One,two), axis=1)
# APD=np.loadtxt(APD_file)
plt.figure()
plt.contourf(data.T, 40)
plt.colorbar()
# # plt.pcolor(data.T, vmax=0)
# def u_exact(x, t):
# 	L=1.5
#     return x*(L-x)*5*t  # fulfills BC at x=0 and x=L

# t=range(1, 300)#(8000- 2006,10000- 6000)
# # a = 3.5;
# L = 1.5;
# Nx = 30;
# F = 0.5;
# # Compute dt from Nx and F
# dx = L / Nx;
# dt = F / a * dx * dx;
# Nt = int(round(5/float(dt)))
# t = np.linspace(0, Nt*dt, Nt+1)   # Mesh points in time
# x = np.linspace(0, L, Nx+1)       # Mesh points in space
# print(dt)


# # print One[:,50]
# plt.subplot(211)
# # plt.plot(t,One[:,5],label='AP-endo')
# plt.contourf(One[0:2000][:])
# plt.colorbar()
# # plt.caxis([-80,40])
# plt.clim(vmin=-80,vmax=40)
# plt.xlabel('time')
# plt.ylabel('Voltage')
# # plt.xlim(396000,400000)
# # plt.legend()

# # plt.subplot(312)
# # plt.plot(One[75],label='AP-epi')
# # plt.xlabel('time')
# # plt.ylabel('Voltage')
# # plt.xlim(396000,400000)
# plt.legend()


# print len(One)

# HX=0.15
# a = 0.0011
# N=100
# p=[]
# for i in t:
# 	sumv=0.0
# 	for n in range(1,N):
# 	    # // 121*HX = 195.5
# 	    r1 = 121 + (N - n + 1)
# 	    r2 = 121 + (N - n - 1)
# 	    sumv -= (One[n, i] - One[n-1,i] ) * (1.0 / r2 - 1.0 / r1);
# 	p.append(100 * a * a * sumv / (64 * HX * HX))

# plt.figure()#(212)
# plt.plot(t,p,label='ECG')
# plt.subplot(312)
# plt.plot(APD[:,0],APD[:,1],label='APD90')
# plt.plot(APD[:,0],APD[:,2],'ro',label='APD75')
# plt.plot(APD[:,0],APD[:,3],label='APD50')
# plt.xlabel('Time(count*BCL)')
# plt.ylabel('APD(ms)')
# plt.legend()

# plt.subplot(313)
# plt.plot(APD[:,0],APD[:,7],label='dvdtmax')
# plt.xlabel('Time(count*BCL)')
# plt.ylabel('dvdtmax')

# plt.figure()
# plt.plot(Result[:,0],Result[:,3],'ro', label='Ina')
# plt.plot(Result[:,0],Result[:,4],'b-', label='Ikr')
# plt.xlabel('time')
# plt.ylabel('pA/pF')
# plt.legend()

# plt.savefig('twod_plot.png')

# plt.figure()
# plt.plot(One[25][:],'k')
# plt.plot(One[45][:],'r')
# plt.plot(One[85][:],'b')
plt.show()


