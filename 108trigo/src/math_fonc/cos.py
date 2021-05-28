##
## EPITECH PROJECT, 2021
## 108trigo
## File description:
## cos
##

from src.matrix_class import Mats
import src.matrix_fonc as Fonc
import math

def calc_cos(mat):
    result = Fonc.create_map_andfill(len(mat), len(mat), 0)
    Fonc.identity_matrix(result)
    b = 0
    for i in range(2, 100, 2):
        div = Fonc.calc_mat_power(mat, i).div_num(math.factorial(i))
        if b % 2 == 0:
            result = result.sub_mat(div)
        else:
            result = result.add_mat(div)
        b += 1
    return result

def calc_cosh(mat):
    result = Fonc.create_map_andfill(len(mat), len(mat), 0)
    Fonc.identity_matrix(result)

    for i in range(2, 100, 2):
        div = Fonc.calc_mat_power(mat, i).div_num(math.factorial(i))
        result = result.add_mat(div)
    return result