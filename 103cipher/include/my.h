/*
** EPITECH PROJECT, 2020
** lib
** File description:
** lib_true
*/

#ifndef MY_H_
#define MY_H_

void print_matrix(float **mat, int l, int c);
void free_matrix(float **mat, int l);
void print_encrypted(float **mat, int l, int c);
float **mult_mat(float **mat1, float **mat2, float c1, float c2);
float **create_key_mat(char *key);
void print_decrypte_matrix(float **mat, int l, int c);
void free_tap(char **tap, int l);
float **get_cofactors(float **mat, int line, int colone);
float calcul_determinant(float **mat, int size);
void decrypte_one_mat(float **key, char *str);
void decrypte_mat(float **key, char *str, int b);
int error(int av, char **argv);
char **my_str_to_word_array(char  const *str);
float **create_criptecle_mat(char *message, int colone);
float **mul_det_mat(float det, float **mat, int line, int colone);

#endif