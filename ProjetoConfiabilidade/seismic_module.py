#-------------------------------------------------------------------------------
# Name:        seismic_avaliation
# Purpose:
#
# Author:      bruno
#
# Created:     11/11/2020
# Copyright:   (c) bruno 2020
# Licence:     <your licence>
#-------------------------------------------------------------------------------
import numpy as np
import bisect


def mean_lnSA(M,R,ω):
    if ω<3.141592653589793:
        ω=3.141592653589793
    table_coefficients={
    3.141592653589793:np.array([-0.97,2.52,-0.47,0.93,0.6,0.0012,7.0]),
    6.283185307179586:np.array([-0.12,2.05,-0.34,0.90,0.59,0.0019,6.8]),
    15.707963267948966:np.array([0.90,1.70,-0.26,0.94,0.65,0.0030,7.2]),
    31.41592653589793:np.array([1.60,1.24,0.00,0.98,0.74,0.0039,7.5]),
    62.83185307179586:np.array([2.36,1.23,0.00,1.12,1.05,0.0043,8.5]),
    157.07963267948966:np.array([3.54,1.19,0.00,1.46,1.84,0.0010,10.5]),
    219.9114857512855:np.array([3.87,1.19,0.00,1.58,1.9,0.0005,11.1]),
    10000.:np.array([2.07,1.20,0.00,1.28,1.23,0.0018,9.3])
    }

    ω_ref_lst=np.array([3.141592653589793,6.283185307179586,15.707963267948966,
                    31.41592653589793,62.83185307179586,157.07963267948966,
                    219.9114857512855,10000.])

    position_ω_ref=bisect.bisect_right(ω_ref_lst,ω)

    ω_ref_sup = ω_ref_lst[position_ω_ref]
    ω_ref_inf = ω_ref_lst[position_ω_ref-1]

    coeff_sup = table_coefficients[ω_ref_sup]
    coeff_inf = table_coefficients[ω_ref_inf]

    C = coeff_sup-(coeff_sup-coeff_inf)*(ω_ref_sup-ω)/(ω_ref_sup-ω_ref_inf)

    RM = np.sqrt(R*R+C[6]*C[6])

    lnSA = (C[0]+C[1]*(M-6)+C[2]*(M-6)*(M-6)-C[3]*np.log(RM)
            -(C[4]-C[3])*np.maximum(np.log(RM)/100,0)-C[5]*RM)+2.2830556283855414

    return lnSA

def sigma_aleatory(M,R,ω):

    if ω<3.141592653589793:
        ω=3.141592653589793

    table_M_uncertainty={
        3.141592653589793:np.array([0.63,0.63,0.81,0.61]),
        6.283185307179586:np.array([0.62,0.62,0.81,0.61]),
        15.707963267948966:np.array([0.58,0.58,0.70,0.59]),
        31.41592653589793:np.array([0.54,0.54,0.63,0.51]),
        62.83185307179586:np.array([0.54,0.54,0.57,0.44]),
        157.07963267948966:np.array([0.57,0.57,0.58,0.44]),
        219.9114857512855:np.array([0.57,0.57,0.58,0.44]),
        10000.:np.array([0.58,0.58,0.58,0.44])
    }

    table_R_uncertainty={
        3.141592653589793:np.array([0.45,0.45,0.12,0.12]),
        6.283185307179586:np.array([0.45,0.45,0.12,0.12]),
        15.707963267948966:np.array([0.45,0.45,0.12,0.12]),
        31.41592653589793:np.array([0.45,0.45,0.12,0.12]),
        62.83185307179586:np.array([0.50,0.50,0.17,0.17]),
        157.07963267948966:np.array([0.57,0.57,0.29,0.29]),
        219.9114857512855:np.array([0.62,0.62,0.35,0.35]),
        10000.:np.array([0.54,0.54,0.20,0.20])
    }

    ω_ref_lst=np.array([3.141592653589793,6.283185307179586,15.707963267948966,
                        31.41592653589793,62.83185307179586,157.07963267948966,
                        219.9114857512855,10000.])
    M_ref_lst=np.array([0.0,5.0,6.0,7.5])
    R_ref_lst=np.array([0.0,5.0,20.0,1000.0])

    position_ω_ref=bisect.bisect_right(ω_ref_lst,ω)
    position_M_ref=bisect.bisect_right(M_ref_lst,M)
    position_R_ref=bisect.bisect_right(R_ref_lst,R)

    ω_ref_sup = ω_ref_lst[position_ω_ref]
    ω_ref_inf = ω_ref_lst[position_ω_ref-1]
    M_ref_sup = M_ref_lst[position_M_ref]
    M_ref_inf = M_ref_lst[position_M_ref-1]
    R_ref_sup = R_ref_lst[position_R_ref]
    R_ref_inf = R_ref_lst[position_R_ref-1]

    coeff_M_sup = table_M_uncertainty[ω_ref_sup]
    coeff_M_inf = table_M_uncertainty[ω_ref_inf]
    coeff_R_sup = table_R_uncertainty[ω_ref_sup]
    coeff_R_inf = table_R_uncertainty[ω_ref_inf]


    ξ_M_ref_lst = coeff_M_sup-(coeff_M_sup-coeff_M_inf)*(ω_ref_sup-ω)/(ω_ref_sup-ω_ref_inf)
    ξ_R_ref_lst = coeff_R_sup-(coeff_R_sup-coeff_R_inf)*(ω_ref_sup-ω)/(ω_ref_sup-ω_ref_inf)

    coeff_ξ_M_sup = ξ_M_ref_lst[position_M_ref]
    coeff_ξ_M_inf = ξ_M_ref_lst[position_M_ref-1]
    coeff_ξ_R_sup = ξ_R_ref_lst[position_R_ref]
    coeff_ξ_R_inf = ξ_R_ref_lst[position_R_ref-1]


    ξ_M = coeff_ξ_M_sup-(coeff_ξ_M_sup-coeff_ξ_M_inf)*(M_ref_sup-M)/(M_ref_sup-M_ref_inf)
    ξ_R = coeff_ξ_R_sup-(coeff_ξ_R_sup-coeff_ξ_R_inf)*(R_ref_sup-R)/(R_ref_sup-R_ref_inf)

    ξ = np.sqrt(ξ_M*ξ_M+ξ_R*ξ_R)

    return ξ

def sigma_epistemic(M,ω):

    if ω<3.141592653589793:
        ω=3.141592653589793

    table_epist_uncertainty={
        3.141592653589793:0.37+0.1*(M-6),
        6.283185307179586:0.35+0.08*(M-6),
        15.707963267948966:0.34+0.07*(M-6),
        10000.:0.34+0.07*(M-6)
    }

    ω_ref_lst=np.array([3.141592653589793,6.283185307179586,15.707963267948966,
                        10000.])

    position_ω_ref=bisect.bisect_right(ω_ref_lst,ω)

    coeff_epist_sup = table_epist_uncertainty[ω_ref_sup]
    coeff_epist_inf = table_epist_uncertainty[ω_ref_inf]

    ξ_e = coeff_epist_sup-(coeff_epist_sup-coeff_epist_inf)*(ω_ref_sup-ω)/(ω_ref_sup-ω_ref_inf)

    return ξ

def statistical_parameters_λξ(n_ddof,ω,mgl,dist):
    λ = np.zeros(n_ddof)
    ξ = np.zeros(n_ddof)
    for i in range(n_ddof):
        λ[i] = mean_lnSA(mgl,dist,ω[i])
        ξ[i] = sigma_aleatory(mgl,dist,ω[i])

    return λ,ξ

def earthquake_density_function(mgl,mgl_max,mgl_min,b):
    β = b*2.302585092994046
    return (β*np.exp(-β*(mgl-4.0)))/(1-np.exp(-β*(mgl_max-4.0)))

def vector_magnitudes(mgl_max,mgl_min,Δmgl):
    num_mag = int((mgl_max-mgl_min)/(Δmgl)+1)
    magnitudes = np.zeros(num_mag)
    for i in range(num_mag-1):
        magnitudes[i]=mgl_min+i*Δmgl
    magnitudes[num_mag-1] = mgl_max
    return magnitudes, num_mag

def seismic_parameters(b_value,mgl_max,mgl_min,Δmgl,dist,n_ddof,ω):
    magnitudes,num_mag = vector_magnitudes(mgl_max,mgl_min,Δmgl)
    λ = np.zeros((num_mag,n_ddof))
    ξ = np.zeros((num_mag,n_ddof))
    f_m = np.zeros(num_mag)
    for i in range(num_mag):
        f_m[i] = earthquake_density_function(magnitudes[i],mgl_max,mgl_min,b_value)
        λ[i,:],ξ[i,:] = statistical_parameters_λξ(n_ddof,ω,magnitudes[i],dist)
    return num_mag,magnitudes,f_m,λ,ξ
