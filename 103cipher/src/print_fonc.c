/*
** EPITECH PROJECT, 2020
** pprint fonc
** File description:
** fonc print
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void print_matrix(float **mat, int l, int c)
{
    for (int i = 0; i < l ; i++) {
        for (int b = 0; b < c; b++) {
            printf("%.0f", mat[i][b]);
            if ( b < c - 1)
                printf("\t");
        }
        printf("\n");
    }
}

void print_decrypte_matrix(float **mat, int l, int c)
{
    int lettre = 0;

    for (int i = 0; i < l ; i++)
        for (int b = 0; b < c; b++) {
            lettre = roundf(mat[i][b]);
            if (lettre > 31 && lettre < 127)
                printf("%c", lettre);
        }
    printf("\n");
}

void free_matrix(float **mat, int l)
{
    for (int i = 0; i < l ; i++)
        free(mat[i]);
    free(mat);
}

void print_encrypted(float **mat, int l, int c)
{
    for (int i = 0; i < l ; i++) {
        for (int b = 0; b < c; b++) {
            if (i < l -1 || b < c - 1) {
                printf("%.0f ", mat[i][b]);
            } else
                printf("%.0f", mat[i][b]);
        }
    }
    printf("\n");
}

float **mult_mat(float **mat1, float **mat2, float c1, float c2)
{
    float **mat_result = malloc(sizeof(float **) * c1);

    for (int b = 0; b < c1; b++)
        mat_result[b] = calloc(sizeof(float *), c2);
    for (int i = 0; i < c2; i++) {
        for (int b = 0; b < c1; b++)
            for (int c = 0; c < c2; c++)
                mat_result[b][i] += mat1[b][c] * mat2[c][i];
    }
    return mat_result;
}
