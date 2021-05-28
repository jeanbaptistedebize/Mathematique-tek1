#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## equation calc
## File description:
## equation cacl
##

from src.error import *
import sys

def pow_nbr(list, x):
    resulte = 0
    power = 0
    for nbr in list:
        resulte += (nbr * (x  ** power)) / 1000 ** power
        power += 1
    return resulte 

def calc_all_arg(list_v):
    result = 1
    for x in range(0, 1001):
        for place in range(0, len(list_v), 2):
            first = pow_nbr(list_v[place], x)
            seconde = pow_nbr(list_v[place + 1], x)
            if first != seconde:
                result *= (first / seconde)
            elif int(seconde * 100000) == 0:
                sys.exit(84)
        print("%0.3f ->" % (x / 1000), "%0.5f" % result)
        result = 1

def init_list(argv):
    if (len(argv) - 1) % 2:
        sys.exit(84)
    list_v = []
    for arg in range(1, len(argv)):
        list_v.append(argv[arg].split('*'))
    return list_v

def main(argv, ac):
    if ac < 3:
        sys.exit(84)
    list_v = init_list(argv)
    list_to_int(list_v)
    calc_all_arg(list_v)
    sys.exit(0)