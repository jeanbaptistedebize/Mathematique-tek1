##
## EPITECH PROJECT, 2021
## 104_intersection
## File description:
## error_manager
##

import sys
from src.usage import usage_display

def check_if_nbr(argv) :
    for i in range(2, 8) :
        if (argv[i][0] == '-' and len(argv[i]) == 1) :
            sys.exit(84)
        if (argv[i][0] != '-' and str.isdigit(argv[i]) == 0) :
            sys.exit(84)

def error_manager(argv, ac) :
    if ac < 9 or argv[1] == "-h" :
        usage_display()
        sys.exit(0)
    if ac != 9 :
        return 84
    if (argv[1] == "1" and int(argv[8]) <= 0) :
        return 84
    if (argv[1] == "2" and int(argv[8]) <= 0) :
        return 84
    if (argv[1] == "3" and int(argv[8]) <= 0 or int(argv[8]) >= 90) :
        return 84
    check_if_nbr(argv)
    return 0