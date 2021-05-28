#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## equation calc
## File description:
## equation cacl
##

from src.error import *
from src.class_ import *
import sys

def calcul_equation(a_valeur, x) :
    return a_valeur.a4 * (x ** 4) +  a_valeur.a3 * (x ** 3) + a_valeur.a2 *(x ** 2) +  a_valeur.a1 * x + a_valeur.a0

def calcul_derive_equation(a_valeur, x) :
    return (4 * a_valeur.a4 * (x ** 3)) + (3 * a_valeur.a3 * (x ** 2)) + (2 * a_valeur.a2 * x) + a_valeur.a1

def bisection(a_valeur, n, a, b) :
    c = (a + b) / 2
    fc =  calcul_equation(a_valeur, c)

    if c == a or b == c :
        return c
    if abs(fc) <= (10 ** (-n)) :
        return c
    print("x = {2:.{1}g}".format("test", n, c))
    if fc * calcul_equation(a_valeur, a) < 0 :
        return bisection(a_valeur, n, a, c)
    else :
        return bisection(a_valeur, n, c, b)

def newton(a_valeur, x, n, x2) :
    fxd = calcul_derive_equation(a_valeur, x)
    if fxd == 0 :
        sys.exit(84)
    xn = x - ((calcul_equation(a_valeur, x)) / fxd)
    if xn == x or x2 == xn:
        return xn
    print("x = {2:.{1}g}".format("test", n, x))
    if abs(calcul_equation(a_valeur, xn)) <= (10 ** (-n)) :
        return xn
    return newton(a_valeur, xn, n, x)

def secant(a_valeur, x0, x1, n) :
    fxn1 = calcul_equation(a_valeur, x1)
    fxn0 = calcul_equation(a_valeur, x0)

    if fxn1 - fxn0 == 0 :
        sys.exit(84)
    fxnew = x1 - (fxn1 * (x1 - x0) / (fxn1 - fxn0))
    if (fxnew == x1) :
        return fxnew
    if abs(calcul_equation(a_valeur, fxnew)) <= (10 ** (-n)) :
        return fxnew
    print("x = {2:.{1}g}".format("test", n, fxnew))
    return secant(a_valeur, x1, fxnew, n)

def main(argv, ac) :
    error(argv, ac)
    a_valeur = func_def(float(argv[2]), float(argv[3]), float(argv[4]), float(argv[5]), float(argv[6]))

    if (int(argv[1]) == 1):
        x = bisection(a_valeur, int(argv[7]), 0, 1)
        print("x = {2:.{1}f}".format("test", int(argv[7]), x))
    if (int(argv[1]) == 2) :
        x = newton(a_valeur, 0.5, int(argv[7]), 0) 
        print("x = {2:.{1}f}".format("test", int(argv[7]), x))
    if (int(argv[1]) == 3) :
        x = secant(a_valeur, 0, 1,  int(argv[7]))
        print("x = {2:.{1}f}".format("test", int(argv[7]), x))
    sys.exit(0)