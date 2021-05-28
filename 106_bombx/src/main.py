#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## equation calc
## File description:
## equation cacl
##

from src.error import error
import sys

def start_fonc(x_value, growth_rate):
    print(1,"%0.2f" % (x_value))
    for i in range(2, 101):
        x_1 = growth_rate * int(x_value * 10000000)
        x_2 = ((1000 - x_value) / 1000)
        x_value = x_1 * x_2  / 10000000000
        if (x_value < 0):
            x_value = 0
        print(i, "%0.2f" % x_value)

def display_calc(growth_rate, start_print, end_print, x_value):
    for i in range(2, end_print +1):
        x_value = (growth_rate / 100) * x_value * (1000 - x_value) / 1000
        if (x_value < 0):
            x_value = 0
        if i >= start_print:
            print("%0.2f" % (growth_rate / 100), "%0.2f" % x_value)

def start_fonc_w(begin, start, end_print):
    x_value = start

    for growth_rate in range(100, 401):
        for i in range(2, end_print + 1):
            x_value = (growth_rate / 100) * x_value * (1000 - x_value) / 1000
            if (x_value < 0):
                x_value = 0
            if i >= begin:
                print("%0.2f" % (growth_rate / 100), "%0.2f" % x_value)
        x_value = start

def start_fonc_w_3(x_value, start_print, end_print):
    growth_rate = 10
    for growth_rate in range(100, 401):
        display_calc(growth_rate, start_print, end_print, x_value)

def main(argv, ac):
    error(argv, ac)
    if (ac == 3):
        first_value = float(argv[1])
        growth_rate =  int(float(argv[2]) * 1000)
        start_fonc(first_value, growth_rate)
    if (ac == 4):
        start_fonc_w(int(argv[2]), int(argv[1]), int(argv[3]))
    sys.exit(0)