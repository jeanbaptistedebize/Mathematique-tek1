/*
** EPITECH PROJECT, 2020
** printf fonc 
** File description:
** fonc print
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"

int print_trans_mat(char **argv, int i, float ****matrix, int b)
{
    matrix[0][b] = create_trans_mat(atof(argv[i + 1]), atof(argv[i + 2]));
    b++;
    printf("Translation along vector (%d, %d)\n",
    atoi(argv[i + 1]), atoi(argv[i + 2]));
    return b;
}

int print_trans_scale(char **argv, int i, float ****matrix, int b)
{
    matrix[0][b] = create_scale_mat(atof(argv[i + 1]), atof(argv[i + 2]));
    printf("Scaling by factors %d and %d\n",
    atoi(argv[i + 1]), atoi(argv[i + 2]));
    b++;
    return b;
}

int print_trans_rotate(char **argv, int i, float ****matrix, int b)
{
    matrix[0][b] = create_rotate_mat(atof(argv[i + 1]));
    printf("Rotation by a %d degree angle\n",
    atoi(argv[i + 1]));
    b++;
    return b;
}

float **create_calcul_mat(char **argv, int av, float ****matrix)
{
    int b = 0;

    for (int i = 0; i < av; i++) {
        if (strcmp(argv[i], "-t") == 0 && i + 2 < av)
            b = print_trans_mat(argv, i, matrix, b);
        if (strcmp(argv[i], "-z") == 0 && i + 2 < av)
            b = print_trans_scale(argv, i, matrix, b);
        if (strcmp(argv[i], "-r") == 0 && i + 1 < av)
            b = print_trans_rotate(argv, i, matrix, b);
        if (strcmp(argv[i], "-s") == 0 && i + 1 < av) {
            matrix[0][b] = create_reflex_mat(atof(argv[i + 1]));
            printf("Reflection over an axis with an inclination angle of %d degrees\n",
            atoi(argv[i + 1]));
            b++;
        }
    }
}
