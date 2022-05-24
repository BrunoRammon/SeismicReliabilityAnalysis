import matplotlib.pyplot as plt
import numpy as np
def output_matlab(λ,ξ,lim_state_expr,n_ddof):
    posproc = []
    posproc.append('clearvars\n')
    posproc.append("rng(100,'twister')\n")
    posproc.append('uqlab\n')
    posproc.append("ModelOpts.mString = "+lim_state_expr+";\n")
    posproc.append("modelopts.isVectorized = true;\n")
    posproc.append("myModel = uq_createModel(ModelOpts);\n")
    for i in range(n_ddof):
        posproc.append("InputOpts.Marginals("+str(i+1)+").Name = 'S"+str(i+1)+"';\n")
        posproc.append("InputOpts.Marginals("+str(i+1)+").Type = 'Lognormal';\n")
        posproc.append("InputOpts.Marginals("+str(i+1)+").Parameters = ["+λ+" "+ξ+"];\n")

    posproc.append("myInput = uq_createInput(InputOpts);\n")
    posproc.append("FORMOpts.Type = 'Reliability';\n")
    posproc.append("FORMOpts.Method = 'FORM';\n")
    posproc.append("FORMAnalysis = uq_createAnalysis(FORMOpts);\n")
    posproc.append("uq_print(FORMAnalysis)\n")
    posproc.append("uq_display(FORMAnalysis)\n")
    posproc.append("SORMOpts.Type = 'Reliability';\n")
    posproc.append("SORMOpts.Method = 'SORM';\n")
    posproc.append("SORMAnalysis = uq_createAnalysis(SORMOpts);\n")
    posproc.append("uq_print(SORMAnalysis)\n")
    posproc.append("uq_display(SORMAnalysis)\n")

def output_data(filename,num_mag,n_ddof,n_lse,magnitudes,Δm,f_m,λ,ξ,lse):
    posproc = []
    posproc.append('{:8}\n'.format(num_mag))
    posproc.append('{:8}\n'.format(n_ddof))
    posproc.append('{:8}\n'.format(n_lse))
    posproc.append('{:20.18f}\n'.format(Δm))

    posproc.append('\n')
    for i in range(num_mag):
        posproc.append('{:20.18f}\n'.format(magnitudes[i]))

    posproc.append('\n')
    for i in range(num_mag):
        posproc.append('{:20.18f}\n'.format(f_m[i]))


    posproc.append('\n')
    for i in range(num_mag):
        for j in range(n_ddof):
            posproc.append('{:20.18f}\n'.format(λ[i,j]))

    posproc.append('\n')
    for i in range(num_mag):
        for j in range(n_ddof):
            posproc.append('{:20.18f}\n'.format(ξ[i,j]))

    posproc.append('\n')
    for i in range(n_lse):
            posproc.append(lse[i]+'\n')

    saida = open(filename,'w')
    saida.writelines(posproc)
    saida.close()

def plot_mode_shapes(ω,φ,floor_heights):

    fig = plt.figure()
    ax = fig.add_subplot(111)

    base_heights = np.zeros(len(floor_heights))
    base_heights[0] = floor_heights[0]

    for i in range(len(floor_heights)-1):
        base_heights[i+1]=base_heights[i]+floor_heights[i+1]

    for i in range(len(floor_heights)):
        ax.plot(ω[i]+φ[:,i]/φ[len(ω)-1,i],base_heights)

    ax.set_title("Mode Shapes")
    ax.set_xlabel("ω")
    ax.set_ylabel("Height")
    ax.set_xlim(0,ω[0]+10)
    ax.set_ylim(0,base_heights[len(floor_heights)-1]+3)
    ax.grid()
    plt.show()
