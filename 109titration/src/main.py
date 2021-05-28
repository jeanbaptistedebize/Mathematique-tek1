#!/usr/bin/env python3
##
## EPITECH PROJECT, 2021
## 109titration
## File description:
## main
##

from src.calc_fonc import *
from src.read_csv import *
from src.error import error_handle

def derivation(tab):
    vol_equivalence = 0
    i_equivalence = 0

    new_tab = [[0, 0] for i in range(len(tab) - 1)]
    print("Derivative:")
    for i in range(1, len(tab) - 1):
        coeff_v = coeff(tab, i)
        backward_v = backward(tab, i)
        forward_v = forward(tab, i)
        derivation_v = ((1 - coeff_v) * backward_v) + coeff_v * forward_v
        new_tab[i][0] = tab[i][0]
        new_tab[i][1] = derivation_v
        if vol_equivalence < derivation_v:
            i_equivalence = i
            vol_equivalence = derivation_v
        print("%.1f ml -> %.2f" %(tab[i][0], derivation_v))
    print("\nEquivalence point at %.1f ml\n" % tab[i_equivalence][0])
    return new_tab

def derivation_seconde(tab):
    prec_derivation = 0
    i_equivalence = 0
    new_tab = [[0,0] for i in range(len(tab) - 1)]
    print("Second derivative:")
    for i in range(2, len(tab) - 1):
        coeff_v = coeff(tab, i)
        backward_v = backward(tab, i)
        forward_v = forward(tab, i)
        derivation_v = ((1 - coeff_v) * backward_v) + coeff_v * forward_v
        new_tab[i][0] = tab[i][0]
        new_tab[i][1] = derivation_v
        if prec_derivation > 0.00 and derivation_v < 0.00:
            i_equivalence = i - 1
        prec_derivation = derivation_v
        print("%.1f ml -> %.2f" %(tab[i][0], derivation_v))
    tab_encadrement = [new_tab[i_equivalence - 1], new_tab[i_equivalence], new_tab[i_equivalence + 1]]
    return tab_encadrement

def derivation_seconde_estimate(tab_encadrement):
    i_equivalence = 0
    vol_equivalence = 0
    value = 0
    vol_arround = tab_encadrement[0][0]
    print("\nSecond derivative estimated:")
    while vol_arround < tab_encadrement[2][0]:
        value = (vol_arround > tab_encadrement[1][0])
        prec = (vol_arround - tab_encadrement[0 + value][0]) / (tab_encadrement[1 + value][0] - tab_encadrement[0 + value][0])
        pos = (tab_encadrement[1 + value][0] - vol_arround) / (tab_encadrement[1 + value][0] - tab_encadrement[0 + value][0])
        derivation_v = prec * tab_encadrement[1 + value][1] + pos * tab_encadrement[0 + value][1]
        if derivation_v < vol_equivalence and vol_equivalence >= 0:
            vol_equivalence = derivation_v
            i_equivalence = vol_arround
        print("%.1f ml -> %.2f" %(vol_arround, derivation_v))
        vol_arround += 0.1
    print("\nEquivalence point at %.1f ml" %(i_equivalence))

def main(argv):
    error_handle(argv, len(argv))
    data = get_csv_data(argv[1])
    derivation_seconde_estimate(derivation_seconde(derivation(data)))