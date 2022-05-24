#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      bruno
#
# Created:     19/12/2020
# Copyright:   (c) bruno 2020
# Licence:     <your licence>
#-------------------------------------------------------------------------------

import numpy as np

def read_input_file_2Dframe_Model(filename):
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

def read_input_file_ShearBuilding_Model(filename):
    file = open(filename,'r') #abre no modo 'r'(read), i.e., de leitura
    data = file.read().split('\n')

    data.pop(0)
    n_ddof = int(data.pop(0).split(':')[1])


    data.pop(0)
    data.pop(0)
    data.pop(0)

    h = np.zeros(n_ddof)
    A_eq = np.zeros(n_ddof)
    I_eq = np.zeros(n_ddof)
    for i in range(n_ddof):
        aux = data.pop(0).split(',')
        h[i] = float(aux[1])
        A_eq[i] = float(aux[2])
        I_eq[i] = float(aux[3])

    data.pop(0)
    data.pop(0)
    data.pop(0)

    E = np.zeros(n_ddof)
    ρ_eq = np.zeros(n_ddof)
    for i in range(n_ddof):
        aux = data.pop(0).split(',')
        E[i] = aux[1]
        ρ_eq[i] = aux[2]

    data.pop(0)
    data.pop(0)
    data.pop(0)
    aux = data.pop(0).split(',')
    b_valor = float(aux[0])
    mgl_min = float(aux[1])
    mgl_max = float(aux[2])
    Δmgl = float(aux[3])
    dist = float(aux[4])

    file.close()
    return n_ddof,h,A_eq,I_eq,E,ρ_eq,b_valor,mgl_min,mgl_max,Δmgl,dist
