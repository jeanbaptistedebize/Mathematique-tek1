#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 109titration
## File description:
## error py
##

import os
from sys import exit

def error_handle(argv, av):
    if av != 2:
        exit(84)
    if (argv[1] == "-h"):
        print("USAGE\n    ./109titration file\n")
        print("DESCRIPTION")
        print("    file\ta csv file containing \"vol;ph\" lines")
        exit(0)
    if not (os.path.isfile(argv[1])):
        exit(84)