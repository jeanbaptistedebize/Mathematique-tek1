/*
** EPITECH PROJECT, 2021
** 103cipher
** File description:
** free_fonc
*/

#include <stdlib.h>

void free_tap(char **tab, int l)
{
    for (int i = 0; i <= l ; i++)
        free(tab[i]);
    free(tab);
}