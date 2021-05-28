#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 109titration
## File description:
## error py
##

from sys import exit

def isfloat(value):
    try:
        float(value)
        return True
    except ValueError:
        return False

def isint(value):
    try:
        int(value)
        return True
    except ValueError:
        return False

def display_usage():
    print("USAGE\n    ./110borwein n\n")
    print("DESCRIPTION")
    print("    n\tconstant defining the integral to be computed")

def error_handle(argv, av):
    if av != 2:
        exit(84)
    if (argv[1] == "-h"):
        display_usage()
        exit(0)
    if not(isint(argv[1])) or int(argv[1]) < 0:
        exit(84)