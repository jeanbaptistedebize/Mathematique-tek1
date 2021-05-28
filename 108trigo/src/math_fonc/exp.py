##
## EPITECH PROJECT, 2021
## 108trigo
## File description:
## exp
##

from src.matrix_class import Mats
import src.matrix_fonc as Fonc
import math

def calc_exp(mat):
    tab = Fonc.create_map_andfill(len(mat), len(mat), 0)
    Fonc.identity_matrix(tab)
    result = mat.add_mat(tab)
    for i in range(2, 100):
        div = Fonc.calc_mat_power(mat, i).div_num(math.factorial(i))
        result = result.add_mat(div)
    return result