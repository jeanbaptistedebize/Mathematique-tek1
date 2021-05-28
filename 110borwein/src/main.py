#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 109titration
## File description:
## main
##

from src.calc_fonc import *
from src.error import error_handle

def main(argv):
    error_handle(argv, len(argv))
    midpoint(int(argv[1]))
    print()
    trapezoids(int(argv[1]))
    print()
    simpson(int(argv[1]))