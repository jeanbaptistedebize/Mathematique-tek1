#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## B-MAT-200-PAR-2-1-110borwein-jean-baptiste.debize
## File description:
## _test_borwein
##

from src.calc_fonc import *
import pytest

def test_calcBorwein():
    n = 1
    x = 1
    assert fonc_eval(n, x) == 0.8259745312109379

    n = 1
    x = 0
    assert fonc_eval(n, x) == 1

    n = 56
    x = 3
    assert fonc_eval(n, x) == 0.03311610968142407

def test_midPoint(capfd):
    n = 10
    midpoint(n)
    out,err = capfd.readouterr()
    assert out == "Midpoint:\nI10 = 1.5707958915\ndiff = 0.0000004353\n"

    n = 42
    midpoint(n)
    out,err = capfd.readouterr()
    assert out == "Midpoint:\nI42 = 1.5707783895\ndiff = 0.0000179373\n"

def test_trapezoid(capfd):
    n = 10
    trapezoids(n)
    out,err = capfd.readouterr()
    assert  "Trapezoidal:\nI10 = 1.5707958915\ndiff = 0.0000004353\n"

    n = 5
    trapezoids(n)
    out,err = capfd.readouterr()
    assert  "Trapezoidal:\nI5 = 1.5707963268\ndiff = 0.0000000000\n"

def test_simpson(capfd):
    n = 10
    simpson(n)
    out,err = capfd.readouterr()
    assert  "Simpson:\nI10 = 1.5707958915\ndiff = 0.0000004353\n"

    n = 19
    simpson(n)
    out,err = capfd.readouterr()
    assert  "Simpson:\nI19 = 1.5707898368\ndiff = 0.0000064900\n"

