/*
** EPITECH PROJECT, 2021
** B-MAT-100-PAR-1-3-102architect-jean-baptiste.debize
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

float **create_mat(float x, float y);
float **create_trans_mat(float i, float j);
float **create_scale_mat(float m, float n);
float **create_rotate_mat(float rotate);
float **create_reflex_mat(float axe_reflex);
float **create_calcul_mat(char **argv, int av, float ****matrix);
int error(int av, char **argv);

#endif /* !MY_H_ */
