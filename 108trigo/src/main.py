#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## equation calc
## File description:
## equation cacl
##

from src.error import error
from src.matrix_class import Mats
from src.math_fonc import exp, cos, sin
import src.matrix_fonc as Fonc
import math
import sys

def creat_mat_from_arg(argv):
    x = int(math.sqrt(len(argv) - 2))
    mat = Fonc.create_map_andfill(x, x, 0)
    pos = 2
    for i in range(len(mat)):
        for j in range(len(mat)):
            mat[i][j] = float(argv[pos])
            pos += 1
    return Mats(mat)

def main(argv, ac):
    error(argv, ac)
    mat = creat_mat_from_arg(argv)
    result = 0
    if argv[1] == "SIN":
        result = sin.calc_sin(mat)
    if argv[1] == "SINH":
        result = sin.calc_sinh(mat)
    if argv[1] == "EXP":
        result = exp.calc_exp(mat)
    if argv[1] == "COS":
        result = cos.calc_cos(mat)
    if argv[1] == "COSH":
        result = cos.calc_cosh(mat)
    if not(result):
        sys.exit(84)
    result.print_mat()
    sys.exit(0)