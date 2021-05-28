/*
** EPITECH PROJECT, 2020
** decrypte fonc
** File description:
** fonc decryte
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"

void decrypte_one_mat(float **key, char *str)
{
    float **encrypte_mat;
    float **mat_final;
    int i = 1;

    for (int comp = 0; str[comp] != '\0'; comp++)
        if (str[comp] == ' ') { i++;}
    key[0][0] = powf(key[0][0], -1);
    encrypte_mat = create_criptecle_mat(str, 1);
    mat_final = mult_mat(encrypte_mat, key, i, 1);
    printf("Key matrix:\n");
    print_matrix(key, 1, 1);
    printf("\nDecrypted message:\n");
    print_decrypte_matrix(mat_final, i, 1);
}

void decrypte_mat(float **key, char *str, int b)
{
    int i = 0;
    float **encrypte_mat;
    float **message;
    float **mat_final;

    for (int comp = 0; str[comp] != '\0'; comp++)
        if (str[comp] == ' ') { i++;}
    i = ceilf(i / (float)b);
    encrypte_mat = get_cofactors(key, b, b);
    message = mul_det_mat(calcul_determinant(key, b), encrypte_mat, b, b);
    free_matrix(encrypte_mat, b);
    encrypte_mat = create_criptecle_mat(str, b);
    printf("Key matrix:\n");
    print_matrix(message, b, b);
    printf("\nDecrypted message:\n");
    mat_final = mult_mat(encrypte_mat, message, i, b);
    print_decrypte_matrix(mat_final, i, b);
    free_matrix(encrypte_mat, i);
    free_matrix(message, b);
    free_matrix(mat_final, i);
}

int error(int av, char **argv)
{
    if (av != 4)
        return 84;
    if (strlen(argv[3]) != 1 || (argv[3][0] != '0' && argv[3][0] != '1'))
        return 84;
    if (strlen(argv[2]) == 0 ||
        (strlen(argv[2]) > 10 && argv[3][0] == '1'))
        return 84;
    return 0;
}
