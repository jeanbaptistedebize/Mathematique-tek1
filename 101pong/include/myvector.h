/*
** EPITECH PROJECT, 2020
** vector struct
** File description:
** structur vector
*/

#ifndef myvector_H_
#define myvector_H_

typedef struct point_adress_s
{
    float x;
    float y;
    float z;
} point_adress_t;

typedef struct velocity_vector_t
{
    float x;
    float y;
    float z;
} velocity_vector_t;

point_adress_t create_vector(float x, float y, float z);
velocity_vector_t create_velocity(point_adress_t a, point_adress_t b);
point_adress_t calcul_ball_coord(velocity_vector_t velocity, point_adress_t a, int t);
float calcul_angle(velocity_vector_t velocity);

#endif
