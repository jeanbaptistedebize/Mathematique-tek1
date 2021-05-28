#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 109titration
## File description:
## s
##

def backward(tab, i):
    return (tab[i][1] - tab[i - 1][1]) / (tab[i][0] - tab[i - 1][0])

def forward(tab, i):
    return (tab[i + 1][1] - tab[i][1]) / (tab[i + 1][0] - tab[i][0])

def coeff(tab, i):
    return (tab[i][0] - tab[i - 1][0]) / ((tab[i][0] - tab[i - 1][0]) + (tab[i + 1][0] - tab[i][0]))