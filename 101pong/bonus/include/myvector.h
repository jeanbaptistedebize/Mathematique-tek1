/*
** EPITECH PROJECT, 2020
** vector struct
** File description:
** structur vector
*/

#ifndef myvector_H_
#define myvector_H_

#include <SFML/Graphics.h>

typedef struct point_adress_s
{
    float x;
    float y;
} point_adress_t;

typedef struct velocity_vector_s
{
    float x;
    float y;
} velocity_vector_t;

typedef struct adress_ball_s
{
    sfVector2f t0;
    sfVector2f t1;
} adress_ball_t;

#endif