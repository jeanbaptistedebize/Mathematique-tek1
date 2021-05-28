#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## read csv
## File description:
## 109titrage
##

import csv
import sys

def isfloat(value):
  try:
    float(value) or int(value)
    return True
  except ValueError:
    return False

def get_csv_data(file):
    f = open(file,'rt')
    list = []
    file_data = csv.reader(f)
    nbr_row = 0
    for row in file_data:
        nbr_row += 1
        list.append(row[0].split(";"))
        if not isfloat(list[-1][0]) or not isfloat(list[-1][1]):
            sys.exit(84)
        list[-1][0] = float(list[-1][0])
        list[-1][1] = float(list[-1][1])
        if list[-1][0] < 0 or list[-1][1] < 0 or list[-1][1] > 14:
            sys.exit(84)
    if nbr_row == 0:
        sys.exit(84)
    return list
