/*
** EPITECH PROJECT, 2020
** fonc archi
** File description:
** archi fonc
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"

float **create_key_mat(char *key)
{
    int c = strlen(key);
    int len = ceilf(sqrt(c));
    float **mat = malloc(sizeof(float **) * len);
    int pose = 0;

    for (int b = 0; b < len;  b++)
        mat[b] = calloc(sizeof(float *), len);
    for (int i = 0; i < len; i++)
        for (int b = 0; b < len; b++, pose++) {
            if (pose > c)
                return mat;
            mat[i][b] = key[pose];
        }
    return  mat;
}

float get_determinant(float **mat, int line, int colone)
{
    float det_mat[2][2] = {{0, 0}, {0, 0}};
    int i = 0;
    int x = 0;
    float result;

    for (; i == line; i++);
    for (int b = 0; b < 3; b++) {
        if (b != colone) {
            det_mat[0][x] = mat[i][b];
            x++;
        }
    }
    for (i++; i == line; i++);
    x = 0;
    for (int b = 0; b < 3; b++) {
        if (b != colone) {
            det_mat[1][x] = mat[i][b];
            x++;
        }
    }
    result = det_mat[0][0] * det_mat[1][1] - det_mat[0][1] * det_mat[1][0];
    return result;
}

float **get_cofactors(float **mat, int line, int colone)
{
    float **mat_final = malloc(sizeof(float **) * line);
    int neg = 1;

    for (int b = 0; b < line;  b++)
        mat_final[b] = calloc(sizeof(float *), colone);
    if (colone == 2) {
        mat_final[0][0] = mat[1][1];
        mat_final[0][1] = -mat[0][1];
        mat_final[1][0] = -mat[1][0];
        mat_final[1][1] = mat[0][0];
        return mat_final;
    }
    for (int i = 0; i < line ; i++)
        for (int b = 0; b < colone; b++, neg *= -1) {
            mat_final[b][i] = get_determinant(mat, i, b) * neg;
            if ((int)(mat_final[b][i] * 10000) == 0)
                mat_final[b][i] = 0.0;
        }
    return mat_final;
}

float calcul_determinant(float **mat, int size)
{
    float result = 0;
    float cur = 0;
    int neg = 1;

    if (size == 2) {
        result = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
        if (result == 0)
            exit(84);
        return result;
    }
    for (int i = 0; i < size; i++, neg *= -1) {
        cur = mat[i][0] * neg * get_determinant(mat, i, 0);
        if ((int)(cur * 10000) == 0)
                cur = 0.0;
        result += cur;
    }
    if (result == 0)
        exit(84);
    return result;
}