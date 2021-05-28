/*
** EPITECH PROJECT, 2020
** 101_pong
** File description:
** calcul velocity and position of a ball
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include "myvector.h"
#include <stdlib.h>
#include "my.h"

void display_result(
    velocity_vector_t velocity, point_adress_t tn, float incidence, char **arg)
{
    printf("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", velocity.x, velocity.y, velocity.z);
    printf("At time t + %d, ball coordinates will be:\n", atoi(arg[7]));
    printf("(%.2f, %.2f, %.2f)\n", tn.x, tn.y, tn.z);
    if (tn.z != 0 && atof(arg[7]) > 0 && (-atof(arg[6])) / tn.z >= 0) {
        printf("The incidence angle is:\n%.2f degrees\n", incidence);
    } else {
        printf("The ball won't reach the paddle.\n");
    }
}

int pong_calc_direction(int av, char **ag)
{
    point_adress_t t0 = create_vector(atof(ag[1]), atof(ag[2]), atof(ag[3]));
    point_adress_t t1 = create_vector(atof(ag[4]), atof(ag[5]), atof(ag[6]));
    velocity_vector_t velocity = create_velocity(t0, t1);
    point_adress_t tn = calcul_ball_coord(velocity, t0, atoi(ag[7]) + 1);

    display_result(velocity, tn, calcul_angle(velocity), ag);
    return 0;
}