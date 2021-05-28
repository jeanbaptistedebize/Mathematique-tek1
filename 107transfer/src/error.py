#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## error .py
## File description:
## 105 error
##

import sys

def list_to_int(value_v):
    for list in value_v:
        i = 0
        for nbr in list:
            if not(nbr.isnumeric()):
                sys.exit(84)
            list[i] = int(nbr)
            i += 1