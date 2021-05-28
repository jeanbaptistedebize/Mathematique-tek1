/*
** EPITECH PROJECT, 2020
** archi 102 test
** File description:
** test archi
*/

#include <criterion/criterion.h>
#include "my.h"

float **create_mat(float x, float y);

float **create_trans_mat(float i, float j);

float **create_scale_mat(float m, float n);

float **create_rotate_mat(float rotate);

float **create_reflex_mat(float axe_reflex);

Test(creat_simple_mat, test1)
{
    float **mat = create_mat(1, 2);

    cr_assert_eq(mat[0][0], 1);
    cr_assert_eq(mat[1][0], 2);
}

Test(create_trans_mat, test2)
{
    float **mat = create_trans_mat(3, 2);

    cr_assert_eq(mat[0][0], 1);
    cr_assert_eq(mat[0][2], 3);
    cr_assert_eq(mat[1][2], 2);
    cr_assert_eq(mat[1][0], 0);
    cr_assert_eq(mat[2][0], 0);
    cr_assert_eq(mat[1][1], 1);
    cr_assert_eq(mat[2][2], 1);
}

Test(create_scale_mat, test2)
{
    float **mat = create_scale_mat(5, 2);

    cr_assert_eq(mat[0][0], 5);
    cr_assert_eq(mat[0][2], 0);
    cr_assert_eq(mat[1][2], 0);
    cr_assert_eq(mat[1][0], 0);
    cr_assert_eq(mat[2][0], 0);
    cr_assert_eq(mat[1][1], 2);
    cr_assert_eq(mat[2][2], 1);
}

Test(create_rotate_mat, test3)
{
    float **mat = create_rotate_mat(90);

    cr_assert_eq(mat[0][1], -1);
    cr_assert_eq(mat[1][0], 1);
    cr_assert_eq(mat[2][2], 1);
}

Test(create_reflex_mat, test4)
{
    float **mat = create_reflex_mat(270);

    cr_assert_eq(mat[0][0], -1);
    cr_assert_eq(mat[1][1], 1);
    cr_assert_eq(mat[2][2], 1);
}