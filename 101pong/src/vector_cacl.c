/*
** EPITECH PROJECT, 2020
** vector
** File description:
** calcul of vector
*/

#include "myvector.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

point_adress_t create_vector(float x, float y, float z)
{
    point_adress_t a;
    
    a.x = x;
    a.y = y;
    a.z = z;

    return a;
}

velocity_vector_t create_velocity(point_adress_t a, point_adress_t b)
{
    velocity_vector_t velocity;

    velocity.x = b.x - a.x;
    velocity.y = b.y - a.y;
    velocity.z = b.z - a.z;
    return velocity;
}

point_adress_t calcul_ball_coord(velocity_vector_t velocity, point_adress_t a, int t)
{
    point_adress_t tn;

    tn.x = velocity.x * t + a.x;
    tn.y = velocity.y * t + a.y;
    tn.z = velocity.z * t + a.z;
    return tn;
}

float calcul_angle(velocity_vector_t velocity)
{
    float incidence;

    incidence = sqrt(
        pow(velocity.x, 2) + pow(velocity.y, 2) + pow(velocity.z, 2));
    incidence = 90 - acosf(fabs(velocity.z) / incidence) * 180 / M_PI;
    return incidence;
}    