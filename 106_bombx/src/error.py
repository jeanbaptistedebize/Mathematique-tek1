#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## error .py
## File description:
## 105 error
##

import sys

def isfloat(value):
    try:
        float(value)
        return True
    except ValueError:
        return False

def print_usage():
    print("USAGE\n\t./106bombx n [k| i0 i1]")
    print("Description\n\tn\tNumber of first generation individual")
    print("\tk\tgrow rate from 1 to 4")
    print("\ti0\tinitial generation (include)")
    print("\ti1\tfinal generation (include)")

def error(argv, av):
    if (av < 3 or av > 4):
        if av == 2 and argv[1] == "-h":
            print_usage()
        sys.exit(84)
    for i in range(1, av):
        if ((not(str.isdigit(argv[i])) and not(isfloat(argv[i]))) or argv[i][0] == '-'):
            sys.exit(84)
    if (int(argv[1]) < 0):
        sys.exit(84)
    if (av == 3):
        if (float(argv[2]) < 1 or float(argv[2]) > 4):
            sys.exit(84)