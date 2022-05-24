#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      bruno
#
# Created:     14/11/2020
# Copyright:   (c) bruno 2020
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import numpy as np
import sympy as spy

def old_read_input_file(filename):
    file = open(filename,'r') #abre no modo 'r'(read), i.e., de leitura
    data = file.read().split('\n') #cria uma lista na qual cada linha do arquivo de entrada é um item da lista na forma de string
    #Os valores de interesse são armazenados na sua respectiva variável
    #e este elemento da lista é excluido para que o próximo valor passe a ser o primeiro elemento da lista
    data.pop(0)
    n_mod = int(data.pop(0).split(':')[1]) #número de módulos ou pórticos
    n_columns_mod = int(data.pop(0).split(':')[1]) #número de pilares por módulo
    n_floors = int(data.pop(0).split(':')[1])
    bay_sizes =  np.array([float(item) for item in data.pop(0).split(':')[1].split(',')],dtype=float)
    floor_heights =  np.array([float(item) for item in data.pop(0).split(':')[1].split(',')],dtype=float)
    floor_weights =  np.array([float(item) for item in data.pop(0).split(':')[1].split(',')],dtype=float)
    young_beam = float(data.pop(0).split(':')[1])
    young_column = float(data.pop(0).split(':')[1])
    mominert_beam = np.zeros((n_mod,n_floors))
    mominert_column = np.zeros((n_mod,n_columns_mod))

    data.pop(0)
    data.pop(0)
    data.pop(0)

    for i in range(n_mod):
        for j in range(n_floors):
            aux = data.pop(0).split(',')
            i_mod = int(aux[0])
            j_floor = int(aux[1])
            inert_value = float(aux[2])
            mominert_beam[i_mod,j_floor] = inert_value

    data.pop(0)
    data.pop(0)
    data.pop(0)

    for i in range(n_mod):
        for j in range(n_columns_mod):
            aux = data.pop(0).split(',')
            i_mod = int(aux[0])
            j_column = int(aux[1])
            inert_value = float(aux[2])
            mominert_column[i_mod,j_column] = inert_value

    data.pop(0)
    data.pop(0)
    aux = data.pop(0).split(',')
    b_valor = float(aux[0])
    mgl_min = float(aux[1])
    mgl_max = float(aux[2])
    Δmgl = float(aux[3])
    dist = float(aux[4])

    file.close()
    ierror = []
    table_error = {
        1:"number of bays different from the number of columns minus one",
        2:"number of floors different from the number of heights of the floors",
        3:"number of floors different from the number of masses of the floors"
    }

    if (n_columns_mod-1!=len(bay_sizes)):
        ierror.append(1)
    if (n_floors!=len(floor_heights)):
        ierror.append(2)
    if (n_floors!=len(floor_weights)):
        ierror.append(3)

    for i in ierror:
        print(table_error[i])

    return n_mod,n_columns_mod,n_floors,bay_sizes,floor_heights,floor_weights,\
    young_beam,young_column,mominert_beam,mominert_column,b_valor,mgl_min,mgl_max,Δmgl,dist

def column_stiffness_matrix(i_mod,j_column,k_floor,young_column,mominert_column,floor_heights):
    E = young_column
    I = mominert_column[i_mod,j_column]
    L = floor_heights[k_floor]
    local_matrix = np.array([[12.0,6.0*L,-12.0,6.0*L],
                            [6.0*L,4.0*L*L,-6.0*L,2.0*L*L],
                            [-12.0,-6.0*L,12.0,-6.0*L],
                            [6.0*L,2.0*L*L,-6.0*L,4.0*L*L]])*E*I/(L*L*L)
    return local_matrix

def beam_stiffness_matrix(i_mod,j_beam,k_bay,young_beam,mominert_beam,bay_sizes):
    E = young_beam
    I = mominert_beam[i_mod,j_beam]
    L = bay_sizes[k_bay]
    local_matrix = np.array([[4.0*L*L,2.0*L*L],
                            [2.0*L*L,4.0*L*L]])*E*I/(L*L*L)
    return local_matrix

def conec_column(n_mod,n_columns_mod,n_floors):
    conec_column = np.zeros([n_columns_mod*n_mod*n_floors,6],dtype=int)
    for i in range(n_mod):
        for j in range(n_columns_mod):
            for k in range(n_floors):
                num_col = i*n_columns_mod+j
                num_elem = num_col*n_floors+k

                conec_column [num_elem,0] = i
                conec_column [num_elem,1] = j
                conec_column [num_elem,2] = k
                conec_column [num_elem,3] = (n_floors+k+1)+((n_floors+1)*num_col)
                conec_column [num_elem,4] = k+1
                conec_column [num_elem,5] = (n_floors+k+2)+((n_floors+1)*num_col)
    return conec_column

def conec_beam(n_mod,n_columns_mod,n_floors):
    conec_beam = np.zeros(((n_columns_mod-1)*n_mod*n_floors,5),dtype=int)
    for i in range(n_mod):
        for j in range(n_columns_mod-1):
            for k in range(n_floors):
                num_col = i*n_columns_mod+j
                num_elem_col = num_col*n_floors+k
                num_elem_beam = num_elem_col-i*n_floors

                conec_beam [num_elem_beam,0] = i
                conec_beam [num_elem_beam,1] = k
                conec_beam [num_elem_beam,2] = j
                conec_beam [num_elem_beam,3] = (n_floors+k+2)+((n_floors+1)*num_col)
                conec_beam [num_elem_beam,4] = (n_floors+k+n_floors+3)+((n_floors+1)*num_col)
    return conec_beam

def assemblage_condensed_stiffness_matrix(n_mod,n_columns_mod,n_floors,conec_column,conec_beam,young_column,young_beam,mominert_column,mominert_beam,floor_heights,bay_sizes):
    kglobal = np.zeros((n_floors+1+(n_floors+1)*n_columns_mod*n_mod,n_floors+1+(n_floors+1)*n_columns_mod*n_mod))


    for i in range(len(conec_column)):
        klocal = column_stiffness_matrix(conec_column[i,0],conec_column[i,1],conec_column[i,2],young_column,mominert_column,floor_heights,)
        for j in range(2,6):
            for k in range(2,6):
                kglobal[conec_column[i,j],conec_column[i,k]]+=klocal[(j-2),(k-2)]


    for i in range(len(conec_beam)):
        klocal = beam_stiffness_matrix(conec_beam[i,0],conec_beam[i,1],conec_beam[i,2],young_beam,mominert_beam,bay_sizes)
        for j in range(3,5):
            for k in range(3,5):
                kglobal[conec_beam[i,j],conec_beam[i,k]]+=klocal[(j-3),(k-3)]

    #excluir linhas e colunas dos graus de liberdade da base
    kglobal = np.delete(kglobal, 0, 0)
    kglobal = np.delete(kglobal, 0, 1)

    for i in range(n_columns_mod*n_mod):
        kglobal = np.delete(kglobal, (n_floors+1)*(i+1)-i*1, 0)
        kglobal = np.delete(kglobal, (n_floors+1)*(i+1)-i*1, 1)

    ktt = np.zeros((n_floors,n_floors))
    kt0 = np.zeros((n_floors,n_floors*n_columns_mod*n_mod))
    k00 = np.zeros((n_floors*n_columns_mod*n_mod,n_floors*n_columns_mod*n_mod))

    for i in range(n_floors):
        for j in range(n_floors):
            ktt[i,j]=kglobal[i,j]

    for i in range(n_floors):
        for j in range(n_floors*n_columns_mod*n_mod):
            kt0[i,j] = kglobal[i,n_floors+j]

    for i in range(n_floors*n_columns_mod*n_mod):
        for j in range(n_floors*n_columns_mod*n_mod):
            k00[i,j] = kglobal[n_floors+i,n_floors+j]
    ktt_condensed = ktt-np.dot(kt0,np.dot(np.linalg.inv(k00),np.transpose(kt0)))
    return ktt_condensed

def assemblage_lumped_mass_matrix(n_floors,floor_weights):
    m_lumped=np.zeros((n_floors,n_floors))

    for i in range(n_floors):
        m_lumped[i,i] = floor_weights[i]
    return m_lumped

def floor_stiffness_matrix(E,A,I,L):
    K = np.array([[E*A/L,0.0,0.0,-E*A/L,0.0,0.0],\
                  [0.0,12*E*I/L**3,6*E*I/L**2,0.0,-12*E*I/L**3,6*E*I/L**2],\
                  [0.0,6*E*I/L**2,4*E*I/L,0.0,-6*E*I/L**2,2*E*I/L],\
                  [-E*A/L,0.0,0.0,E*A/L,0.0,0.0],\
                  [0.0,-12*E*I/L**3,-6*E*I/L**2,0.0,12*E*I/L**3,-6*E*I/L**2],\
                  [0.0,6*E*I/L**2,2*E*I/L,0.0,-6*E*I/L**2,4*E*I/L]])
    return K
def floor_stiffness_matrix2(E,I,L):
    K = np.array([[12*E*I/L**3,-12*E*I/L**3],[-12*E*I/L**3,12*E*I/L**3]])
    return K

def floor_mass_matrix(ρ,A,L):
    M = np.array([[140.,0.,0.,70.,0.,0.],\
                  [0.,156,22*L,0.,54,-13*L],\
                  [0.,22*L,4*L**2,0.,13*L,-3*L**2],\
                  [70.,0.,0.,140.,0.,0.],\
                  [0.,54,13*L,0.,156,-22*L],\
                  [0.,-13*L,-3*L**2,0.,-22*L,4*L**2]])*ρ*A*L/420
    return M


def assemblage_shear_building_matrices(n_ddof,h,A_eq,I_eq,E,ρ_eq):
    K_glob = np.zeros([3*(n_ddof+1),3*(n_ddof+1)])
    M_glob = np.zeros([3*(n_ddof+1),3*(n_ddof+1)])

    for i in range(n_ddof):
        K_floor = floor_stiffness_matrix(E[i],A_eq[i],I_eq[i],h[i])
        M_floor = floor_mass_matrix(ρ_eq[i],A_eq[i],h[i])
        for j in range(6):
            for k in range(6):
                K_glob[3*i+j,3*i+k]=K_glob[3*i+j,3*i+k]+K_floor[j,k]
                M_glob[3*i+j,3*i+k]=M_glob[3*i+j,3*i+k]+M_floor[j,k]

    #excluir linhas e colunas dos graus de liberdade da base
    K_glob = np.delete(K_glob, 0, 0)
    K_glob = np.delete(K_glob, 0, 1)
    K_glob = np.delete(K_glob, 0, 0)
    K_glob = np.delete(K_glob, 0, 1)
    K_glob = np.delete(K_glob, 0, 0)
    K_glob = np.delete(K_glob, 0, 1)

    M_glob = np.delete(M_glob, 0, 0)
    M_glob = np.delete(M_glob, 0, 1)
    M_glob = np.delete(M_glob, 0, 0)
    M_glob = np.delete(M_glob, 0, 1)
    M_glob = np.delete(M_glob, 0, 0)
    M_glob = np.delete(M_glob, 0, 1)

##    for i in range(3*(n_ddof+1)-3):
##        for j in range(3*(n_ddof+1)-3):
##            print('{:2.3e}'.format(K_glob[i,j]),end=' ')
##        print('')
    return K_glob, M_glob



def modal_parameters(M,K):
    eig=np.linalg.eig(np.linalg.solve(M,K))
    mode_shape=eig[1]
    ω=np.sqrt(eig[0])
    sort_indexes = np.argsort(ω)
    ω = ω[sort_indexes]
    mode_shape = mode_shape[:,sort_indexes]
    return mode_shape,ω,sort_indexes

def static_modal_factors(n_ddof,M,K,mode_shape,ω):
    W_φ=0
    W_φ2=0
    Lnh = np.zeros(n_ddof)
    Mn = np.zeros(n_ddof)
    Γn=np.zeros(n_ddof)
    #calculos dos fatores Lnh
    for j in range(n_ddof): #varia de acordo com o pavimento
        for n in range(n_ddof): #varia de acordo com a quantidade de modos
            Lnh[n] += M[j,j]*mode_shape[j,n]

    #calculos dos fatores Mn
    for j in range(n_ddof): #varia de acordo com o pavimento
        for n in range(n_ddof): #varia de acordo com a quantidade de modos
            Mn[n] += M[j,j]*mode_shape[j,n]*mode_shape[j,n]

    #calculo dos fatores Γn
    for n in range(n_ddof): #varia de acordo com a quantidade de modos
        Γn[n]=Lnh[n]/Mn[n]

    #calculo de fator estático de deslocamento absoluto
    u_factor=np.zeros((n_ddof,n_ddof))
    for j in range(n_ddof): #varia de acordo com o pavimento
        for n in range(n_ddof): #varia de acordo com a quantidade de modos
            u_factor[j,n] = Γn[n]*mode_shape[j,n]

    #calculo de fator estátic de deslocamento relativo entre pavimentos
    Δu_factor=np.zeros((n_ddof,n_ddof))
    Δu_factor[0,:] = Γn[:]*(mode_shape[0,:]) # consideração IMPORTANTE
    #considera que o primeiro pavimento é colocado primeiro na matriz de massa
    #e na matriz de rigidez
    for j in range(n_ddof-1): #varia de acordo com o pavimento
        for n in range(n_ddof): #varia de acordo com a quantidade de modos
            Δu_factor[j+1,n] = Γn[n]*(mode_shape[j+1,n]-mode_shape[j,n])
    #calculo dos vetores de contribuição
    s_factor = np.zeros((n_ddof,n_ddof))
    for j in range(n_ddof): #varia de acordo com o pavimento
        for n in range(n_ddof): #varia de acordo com a quantidade de modos
            s_factor[j,n] += Γn[n]*M[j,j]*mode_shape[j,n]

    #calculo do fator estático de força de base
    Vb_factor = np.zeros(n_ddof)
    for j in range(n_ddof): #varia de acordo com o pavimento
        for n in range(n_ddof): #varia de acordo com a quantidade de modos
            Vb_factor[n] += s_factor[j,n]

    return u_factor,Δu_factor,s_factor,Vb_factor

def modal_correlation(n_ddof,ω,ξ_damp):
        ρ=np.zeros((n_ddof,n_ddof))
        for i in range(n_ddof):
            for j in range(n_ddof):
                β=ω[i]/ω[j]
                ρ[i,j]=(8*ξ_damp**2*(1+β)*β**1.5)/((1-β**2)**2+4*ξ_damp**2*β*(1+β)**2)
        return ρ

def limit_state_expression2(n_ddof,x_factor,ω,ρ,r0):
    n_comb = n_ddof**2

    var_str = spy.symbols('X1:%d'%(n_ddof+1))
    termR = r0
    termS = 0
##    for i in range(n_ddof):
##        for j in range(n_ddof):
##            termS += (x_factor[i]*x_factor[j]*ρ[i,j]/(ω[i]*ω[i]*ω[j]*ω[j]))*var_str[i]*var_str[j]
    for i in range(n_ddof):
        for j in range(n_ddof):
            termS += (x_factor[i]*x_factor[j]*ρ[i,j]/(ω[i]*ω[i]*ω[j]*ω[j]))*var_str[i]*var_str[j]
    termS = str(termS)

    for i in range(n_ddof):
        old = 'X'+str(i+1)
        new = 'X(:,'+str(i+1)+')'
        termS = termS.replace(old,new)
    termS = termS.replace(' ','')
    termS = termS.replace('**','^')
    expr = str(termR)+'-sqrt('+termS+')'
    return expr

def limit_state_expression(n_ddof,x_factor,ω,ρ,r0):
    n_comb = n_ddof**2

    var_str = spy.symbols('X1:%d'%(n_ddof+1))
    expr=r0*r0

    for i in range(n_ddof):
        for j in range(n_ddof):
            expr += (-x_factor[i]*x_factor[j]*ρ[i,j]/(ω[i]*ω[i]*ω[j]*ω[j]))*var_str[i]*var_str[j]
    expr = str(expr)

    for i in range(n_ddof):
        old = 'X'+str(i+1)
        new = 'X(:,'+str(i+1)+')'
        expr = expr.replace(old,new)
    expr = expr.replace(' ','')
    expr = expr.replace('**','^')
    return expr

def limit_state_expression_SRSS(n_ddof,x_factor,ω,r0):


    expr = str(r0)+'-sqrt('

    for i in range(n_ddof):
        expr += '+'+str(x_factor[i]*x_factor[i]/(ω[i]*ω[i]*ω[i]*ω[i]))+'*'+'X(:,{:d})^2'.format(i+1)

    expr = expr+')'

    return expr

def limit_state_expression_SRSS2(n_ddof,x_factor,ω,r0):


    expr = str(r0**2)

    for i in range(n_ddof):
        expr += '-'+str(x_factor[i]*x_factor[i]/(ω[i]*ω[i]*ω[i]*ω[i]))+'*'+'X(:,{:d})^2'.format(i+1)

    expr = expr

    return expr

def reduce_VA(vec,ω,index):
    reduced_vec = []
    reduced_ω = []
    index_keep = []
    for i in range(len(vec)):
        if vec[i] != 0:
            reduced_vec.append(vec[i])
            reduced_ω.append(ω[i])
            index_keep.append(index[i])


    reduced_vec = np.array(reduced_vec)
    index_keep = np.array(index_keep)
    reduced_ω = np.array(reduced_ω)

    return reduced_vec,reduced_ω,index_keep






