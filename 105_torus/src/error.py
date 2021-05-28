#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## error .py
## File description:
## 105 error
##

import sys

def error(argv, av) :
    if (av != 8) :
        sys.exit(84)
    for i in range(1, 6) :
        if (argv[i][0] == '-' and len(argv[i]) == 1) :
            sys.exit(84)
        if (argv[i][0] != '-' and str.isdigit(argv[i]) == 0) :
            sys.exit(84)
    if int(argv[1]) < 1 or int(argv[1]) > 3 :
        sys.exit(84)
    if (str.isdigit(argv[7]) == 0) :
        sys.exit(84)