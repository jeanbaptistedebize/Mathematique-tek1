/*
** EPITECH PROJECT, 2020
** vector
** File description:
** calcul of vector
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "myvector.h"

point_adress_t create_vector(float x, float y)
{
    point_adress_t a;
    
    a.x = x;
    a.y = y;
    return a;
}

velocity_vector_t create_velocity(sfVector2f *a, sfVector2f *b)
{
    velocity_vector_t velocity;

    velocity.x = b->x - a->x;
    velocity.y = b->y - a->y;
    return velocity;
}

point_adress_t calcul_ball_coord(velocity_vector_t velocity, float xc, float yc, float t)
{
    point_adress_t tn;

    tn.x = velocity.x * t + xc;
    tn.y = velocity.y * t + yc;
    return tn;
}

float calcul_angle(velocity_vector_t velocity)
{
    float incidence = sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));

    return 90 - asinf(fabs(velocity.y) / incidence * M_PI / 180) * 180 / M_PI;
}

void start_direction(sfVector2f *t0, sfVector2f *t1)
{
    srand(time(NULL));
    int n = rand() % 100 - 50;
    int b = rand() % 2 + 1;

    n *= b;
    t0->x = 500;
    t0->y = 300;
    t1->x = 500 + 0.9 * cos(n * M_PI / 180);
    t1->y = 300 + 0.9 * sin(n * M_PI / 180);
}