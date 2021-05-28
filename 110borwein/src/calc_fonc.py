##
## EPITECH PROJECT, 2021
## B-MAT-200-PAR-2-1-110borwein-jean-baptiste.debize
## File description:
## calc_fonc
##

from math import sin
from math import pi

def fonc_eval(n, x):
    result = 1
    if x == 0:
        return 1
    for k in range(n + 1):
        result *= sin(x / (2 * k + 1)) / (x / (2 * k + 1))
    return result

def midpoint(n):
    b = 5000
    result = 0
    dec = 0.5

    for i in range(int(b / dec)):
        result += fonc_eval(n, i * dec + 0.25) / 2
    print("Midpoint:")
    print("I%d = %.10f" %(n, result))
    print("diff = %.10f" %(abs(result - pi/2)))

def trapezoids(n):
    b = 5000
    dec = 0.5
    result = 0

    for i in range(int(b / dec)):
        result += fonc_eval(n, i * dec) + fonc_eval(n, (i + 1) * dec)
    result *= dec / 2
    print("Trapezoidal:")
    print("I%d = %.10f" %(n, result))
    print("diff = %.10f" %(abs(result - pi / 2)))

def simpson(n):
    b = 5000
    result = 0
    dec = 0.5

    for i  in range(int(b / dec)):
        a = i * dec
        b = i * dec + 0.5
        result += ((b - a) / 6) * (fonc_eval(n, a) + 4 * fonc_eval(n, (a + b) / 2) + fonc_eval(n , b))
    print("Simpson:")
    print("I%d = %.10f" % (n, result))
    print("diff = %.10f" % (abs(result - pi / 2)))
