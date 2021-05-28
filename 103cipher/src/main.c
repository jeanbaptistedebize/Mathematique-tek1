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

float **create_message_mat(char *message, int colone)
{
    int line = ceilf(strlen(message) / (float)colone);
    int len = strlen(message);
    float **mat = malloc(sizeof(float **) * line);
    int pose = 0;

    for (int b = 0; b < line;  b++)
        mat[b] = calloc(sizeof(float *), colone);
    for (int i = 0; i < line; i++) {
        for (int b = 0; b < colone; b++, pose++) {
            if (pose > len)
                return mat;
            mat[i][b] = message[pose];
        }
    }
    return  mat;
}

float **mul_det_mat(float det, float **mat, int line, int colone)
{
    float **mat_final = malloc(sizeof(float **) * line);

    for (int b = 0; b < line;  b++)
        mat_final[b] = calloc(sizeof(float *), colone);
    for (int i = 0; i < line ; i++)
        for (int b = 0; b < colone; b++) {
            mat_final[i][b] = mat[i][b] * (1 / det);
            if ((int)(mat_final[i][b] * 10000) == 0)
                mat_final[i][b] = 0;
        }
    return mat_final;
}

float **create_criptecle_mat(char *message, int colone)
{
    int line;
    int nbr = 1;
    char **nbr_tab = my_str_to_word_array(message);
    int pose = 0;
    float **mat;

    for (int i = 0; message[i] != '\0'; i++)
        if (message[i] == ' ') { nbr++;}
    line = ceilf(nbr / (float)colone);
    mat = malloc(sizeof(float **) * line);
    for (int b = 0; b < line;  b++)
        mat[b] = calloc(sizeof(float *), colone);
    for (int i = 0; i < line; i++)
        for (int b = 0; b < colone; b++, pose++) {
            if (pose > nbr) { return mat;}
            mat[i][b] = atoi(nbr_tab[pose]);
        }
    free_tap(nbr_tab, nbr);
    return mat;
}

void encrypte_the_mat(float **key, int i, int b, char **argv)
{
    float **encrypte_mat;
    float **message;

    message = create_message_mat(argv[1], b);
    printf("Key matrix:\n");
    print_matrix(key, b, b);
    printf("\nEncrypted message:\n");
    encrypte_mat = mult_mat(message, key, i, b);
    print_encrypted(encrypte_mat, i, b);
}

int main(int av, char **argv)
{
    int b;
    int i;
    float **key;

    if (error(av, argv) == 84) {
        printf("Wrong imput\n");
        return 84;
    }
    b = ceilf(sqrt(strlen(argv[2])));
    i = ceilf(strlen(argv[1]) / (float)b);
    key = create_key_mat(argv[2]);
    if (argv[3][0] == '0')
        encrypte_the_mat(key, i, b, argv);
    if (argv[3][0] == '1' && strlen(argv[2]) > 1) {
        decrypte_mat(key, argv[1], b);
    } else if (argv[3][0] == '1' && strlen(argv[2]) == 1)
        decrypte_one_mat(key, argv[1]);
    return 0;
}