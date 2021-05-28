/*
** EPITECH PROJECT, 2020
** 101_pong
** File description:
** calcul velocity and position of a ball
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "myvector.h"
#include "my_csfml.h"

velocity_vector_t create_velocity(sfVector2f *a, sfVector2f *b);
point_adress_t calcul_ball_coord(velocity_vector_t velocity, float xc, float yc, float t);
float calcul_angle(velocity_vector_t velocity);

static void fix_t1(sfVector2f *t1)
{
    if (t1->x < 125)
        t1->x = 125;
    if (t1->y < 71)
        t1->y = 71;
    if (t1->y > 515)
        t1->y = 515;
    if (t1->x > 863)
        t1->x = 863;
}

static void direction_calculator(velocity_vector_t *velocity, sfVector2f *t1, int *a, int *b)
{
    if (velocity->x * velocity->y > 0) { 
        if (t1->x == 125 || t1->y == 515) {
            *b = -1;
        } else 
            *a = -1;
    } else {
        if (t1->x == 863 || t1->y == 515) {
            *b = -1;
            *a = -1;
        }
    }
}

void calcul_rebon(sfVector2f *t0, sfVector2f *t1)
{
    velocity_vector_t velocity;
    int b = 1;
    int a = 1;
    float incidence;

    fix_t1(t1);
    velocity = create_velocity(t0, t1);
    incidence = calcul_angle(velocity);
    direction_calculator(&velocity, t1, &a, &b);
    t0->x = t1->x;
    t0->y = t1->y;
    t1->x += sin(incidence * M_PI / 180) * a;
    t1->y += sin(incidence * M_PI / 180) * b;
}

void calcul_pos(sfVector2f *t0, sfVector2f *t1)
{
    point_adress_t tn;
    velocity_vector_t velocity;
    velocity = create_velocity(t0, t1);

    tn = calcul_ball_coord(velocity, t0->x, t0->y, 2);
    t0->x = t1->x;
    t0->y = t1->y;
    t1->x = tn.x;
    t1->y = tn.y;
}   

void display_result(int *result, sfRenderWindow *window, sfEvent event)
{
    sfSprite *game_over = sfSprite_create();
    sfTexture *game_over_texture = set_texture("template/ia.png", game_over);
    sfSprite *num1 = sfSprite_create();
    sfTexture *num1_texture = set_texture("template/number1.png", num1);

    drawsprite(window, game_over, 277, 50);
    if (result[0] > result[1])
        drawsprite(window, num1, 480, 350);
    if (result[0] < result[1]) {
        drawsprite(window, num1, 495, 350);
        drawsprite(window, num1, 470, 350);
    }
    sfRenderWindow_display(window);
    while (sfRenderWindow_pollEvent(window, &event) && sfRenderWindow_isOpen(window)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window); 
    }
    sfSprite_destroy(game_over);
    sfTexture_destroy(game_over_texture);
}