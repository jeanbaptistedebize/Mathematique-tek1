#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## error .py
## File description:
## 105 error
##

import math
import sys

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

def isqrt(n):
    x = 1
    result = 0

    while result < n:
        result = x * x
        x += 1
    if result != n:
        return False
    return True

def error(argv, av) :
    if (av < 3 or not(isqrt(av - 2))):
        sys.exit(84)

    for i in range(2, av):
        if (not(isfloat(argv[i])) and not(isint(argv[i]))):
            sys.exit(84)