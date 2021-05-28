#
# EPITECH PROJECT, 2021
# mat
# File description:
# mae
#

from src.matrix_class import Mats

def identity_matrix(mat):
    for i in range(len(mat)):
        mat[i][i] = 1

def create_map_andfill(x, y, fill):
    A = [[fill for i in range(x)] for i in range(y)]
    return Mats(A)

def calc_mat_power(mat, n):
    result = mat
    for i in range(1, n):
        result = mat @ result
    return result