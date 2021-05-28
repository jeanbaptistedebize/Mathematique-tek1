/*
** EPITECH PROJECT, 2020
** main
** File description:
** main.c
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"

void print_matrix(float **mat, int l, int c)
{
    if (mat == NULL)
        return;
    for (int i = 0; i < l ; i++) {
        for (int b = 0; b < c; b++) {
            if ((int)(mat[i][b] * 10000) == 0) {
                mat[i][b] = 0.0;
                printf("%.2f", 0.0);
            } else
                printf("%.2f", mat[i][b]);
            if ( b < c - 1)
                printf("\t");
        }
        printf("\n");
    }
}

float **mult_mat(float **mat1, float **mat2, float c1, float c2)
{
    float **mat_result = malloc(sizeof(float **) * c1);

    if (mat1 == NULL && mat2 != NULL)
        return mat2;
    if (mat1 == NULL && mat2 == NULL) {
        printf("Error wrong matrix");
        return NULL;
    }
    for (int b = 0; b < c1; b++)
        mat_result[b] = calloc(sizeof(float *), c2);
    for (int i = 0; i < c2; i++) {
        for (int b = 0; b < c1; b++)
            for (int c = 0; c < c1; c++)
                mat_result[b][i] += mat1[b][c] * mat2[c][i];
    }
    return mat_result;
}

int main(int av, char **argv)
{
    float **m_pose;
    float ***matrix;
    float **final_mat;
    int b = error(av, argv);

    if (b == 84) { return 84;}
    matrix = calloc(b + 1, sizeof(float ***));
    matrix[0] = NULL;
    create_calcul_mat(argv, av, &matrix);
    m_pose = create_mat(atof(argv[1]), atof(argv[2]));
    final_mat = matrix[0];
    for (int b = 1; matrix[b] !=  NULL; b++)
        final_mat = mult_mat(matrix[b], final_mat, 3, 3);
    print_matrix(final_mat, 3, 3);
    final_mat = mult_mat(final_mat, m_pose, 3, 1);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", atof(argv[1]), atof(argv[2]),
        final_mat[0][0], final_mat[1][0]);
    free(matrix);
    free(final_mat);
    return 0;
}