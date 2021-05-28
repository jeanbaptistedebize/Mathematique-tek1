/*
** EPITECH PROJECT, 2020
** fonc archi
** File description:
** archi fonc
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float **create_mat(float x, float y)
{
    float **mat = malloc(sizeof(float **) * 4);

    for (int b = 0; b < 4; b++)
        mat[b] = calloc(sizeof(float *), 1);
    mat[0][0] = x;
    mat[1][0] = y;
    mat[2][0] = 1;
    return mat;
}

float **create_trans_mat(float i, float j)
{
    float **mat = malloc(sizeof(float **) * 4);

    for (int b = 0; b < 4; b++)
        mat[b] = calloc(sizeof(float *), 4);
    mat[0][0] = 1;
    mat[0][2] = i;
    mat[1][1] = 1;
    mat[1][2] = j;
    mat[2][2] = 1;
    return mat;
}

float **create_scale_mat(float m, float n)
{
    float **mat = malloc(sizeof(float **) * 4);

    for (int b = 0; b < 4; b++)
        mat[b] = calloc(sizeof(float *), 4);
    mat[0][0] = m;
    mat[1][1] = n;
    mat[2][2] = 1;
    return mat;
}

float **create_rotate_mat(float rotate)
{
    float **mat = malloc(sizeof(float **) * 4);

    for (int b = 0; b < 4; b++)
        mat[b] = calloc(sizeof(float *), 4);
    mat[0][0] = cos(rotate * M_PI / 180);
    mat[0][1] = -sin(rotate * M_PI / 180);
    mat[1][0] = sin(rotate * M_PI / 180);
    mat[1][1] = cos(rotate * M_PI / 180);
    mat[2][2] =  1;
    return mat;
}

float **create_reflex_mat(float axe_reflex)
{
    float **mat = malloc(sizeof(float **) * 4);

    for (int b = 0; b < 4; b++)
        mat[b] = calloc(sizeof(float *), 4);
    mat[0][0] = cos(2 * axe_reflex * M_PI / 180);
    mat[0][1] = sin(2 * axe_reflex * M_PI / 180);
    mat[1][0] = sin(2 * axe_reflex * M_PI / 180);
    mat[1][1] = -cos(2 * axe_reflex * M_PI / 180);
    mat[2][2] =  1;
    return mat;
}
