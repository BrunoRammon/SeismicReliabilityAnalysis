import numpy as np
import input_module as inp
import seismic_module as s_m
import structural_analisys_module as sam
import output_module as out

inputfile = 'Entrada_dados_pórtico8.txt'
outputfile_data = 'Saída_dados_pórtico8.txt'
r0 = [0.0491925,0.06,0.06,0.06,0.06] #análise estática ftool NBR
n_mod,n_columns_mod,n_floors,bay_sizes,floor_heights,floor_weights,young_beam,\
young_column,mominert_beam,mominert_column,b_value,mgl_min,mgl_max,Δmgl,dist=inp.read_input_file_2Dframe_Model(inputfile)

conec_column = sam.conec_column(n_mod,n_columns_mod,n_floors)

conec_beam = sam.conec_beam(n_mod,n_columns_mod,n_floors)

ktt_condensed = sam.assemblage_condensed_stiffness_matrix(n_mod,n_columns_mod,n_floors,\
conec_column,conec_beam,young_column,young_beam,mominert_column,mominert_beam,floor_heights,bay_sizes)

m_lumped = sam.assemblage_lumped_mass_matrix(n_floors,floor_weights)

mode_shape,ω,sorted_indexes = sam.modal_parameters(m_lumped,ktt_condensed)

u_factor,Δu_factor,s_factor,Vb_factor = sam.static_modal_factors(n_floors,m_lumped,ktt_condensed,mode_shape,ω)

ρ = sam.modal_correlation(n_floors,ω,0.05)

lse = []
lse.append(sam.limit_state_expression_SRSS(n_floors,u_factor[n_floors-1,:],ω,r0[0]))
for i in range(n_floors):
    lse.append(sam.limit_state_expression_SRSS(n_floors,Δu_factor[i,:],ω,r0[i+1]))

num_mag,magnitudes,f_m,λ,ξ = s_m.seismic_parameters(b_value,mgl_max,mgl_min,Δmgl,dist,n_floors,ω)

n_lse = len(lse)
out.output_data(outputfile_data,num_mag,n_floors,n_lse,magnitudes,Δmgl,f_m,λ,ξ,lse)
out.plot_mode_shapes(ω,mode_shape,floor_heights)
