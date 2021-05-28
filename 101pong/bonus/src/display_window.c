/*
** EPITECH PROJECT, 2020
** graph test
** File description:
** test
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "mylist.h"
#include "myvector.h"
#include "my_csfml.h"

int calcul_pos(sfVector2f *t0, sfVector2f *t1);
void calcul_rebon(sfVector2f *t0, sfVector2f *t1);
void start_direction(sfVector2f *t0, sfVector2f *t1);

static void mouv_palled(int key , sfVector2f *pose_palled_l,  sfVector2f *pose_palled_r)
{
    if (key == sfKeyZ && pose_palled_l->y > 90)
        pose_palled_l->y -= 34;
    if (key == sfKeyS && pose_palled_l->y < 410 )
        pose_palled_l->y += 34;
    if (key == sfKeyUp && pose_palled_r->y > 90)
        pose_palled_r->y -= 34;
    if (key == sfKeyDown && pose_palled_r->y < 410)
        pose_palled_r->y += 34;
}

static int test_if_palled(float t1x, float t1y, sfVector2f *pose_palled_l, sfVector2f *pose_palled_r)
{
    if (pose_palled_l->x < t1x && pose_palled_l->x + 10 > t1x && pose_palled_l->y < t1y && pose_palled_l->y + 100 > t1y)
            return 1;
    if (t1x >= 863 &&  pose_palled_r->y < t1y && pose_palled_r->y + 100 > t1y)
        return 1;
    return 0;            
}

static void display_point(int *result, sfRenderWindow *window)
{
    sfSprite *num1 = sfSprite_create();
    sfTexture *num1_texture = set_texture("template/number1.png", num1);

    if (result[0] == 1)
        drawsprite(window, num1, 445, 80);    
    if (result[0] == 2) {
        drawsprite(window, num1, 460, 80);
        drawsprite(window, num1, 435, 80);
    }
    if (result[1] == 1)
        drawsprite(window, num1, 520, 80);    
    if (result[1] == 2) {
        drawsprite(window, num1, 535, 80);
        drawsprite(window, num1, 510, 80);
    }
    sfTexture_destroy(num1_texture);
    sfSprite_destroy(num1);
}

int pong(sfRenderWindow *window, int *result)
{
    link_list_t *my_list = NULL;
    my_list = add_sprite("template/pong_bord.jpg", my_list, 0, 0);
    sfRectangleShape  *palled_l = create_RectangleShape(10, 100);
    sfRectangleShape  *palled_r = create_RectangleShape(10, 100);
    sfCircleShape *shape = create_CircleShape(10);
    sfVector2f pose_palled_l = {115, 250};
    sfVector2f pose_palled_r = {875, 250};
    adress_ball_t ball_adress;
    sfEvent event;

    start_direction(&ball_adress.t0, &ball_adress.t1);
    drawsprite(window, get_ellement_pos_sprite(my_list, 0), 9, 0);
    drawCircleShape(window, shape, ball_adress.t1.x , ball_adress.t1.y);
    sfRenderWindow_display(window);
    sfRenderWindow_setFramerateLimit(window, 500);
    while (ball_adress.t1.x > 108 && ball_adress.t1.x < 870 && sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if(event.type == sfEvtKeyPressed)
                mouv_palled(event.key.code, &pose_palled_l, &pose_palled_r);
        }
        if (ball_adress.t1.y > 71 && ball_adress.t1.x < 870 && ball_adress.t1.y < 515 && ball_adress.t1.x > 108) {
            calcul_pos(&ball_adress.t0, &ball_adress.t1);
        }   
        if (ball_adress.t1.y <= 71 || ball_adress.t1.y >= 515 || test_if_palled(ball_adress.t1.x, ball_adress.t1.y, &pose_palled_l, &pose_palled_r) == 1) {
            calcul_rebon(&ball_adress.t0, &ball_adress.t1);
        }
        drawsprite(window, get_ellement_pos_sprite(my_list, 0), 0, 0);
        display_point(result, window);
        drawRectangleShape(window, palled_l, pose_palled_r.x, pose_palled_r.y);
        drawRectangleShape(window, palled_l, pose_palled_l.x, pose_palled_l.y);
        drawCircleShape(window, shape, ball_adress.t1.x , ball_adress.t1.y);
        sfRenderWindow_display(window);
    }
    sfRectangleShape_destroy(palled_r);
    sfRectangleShape_destroy(palled_l);
    free_list(my_list);
    if (ball_adress.t1.x < 108) {return 2;}
    if (ball_adress.t1.x > 870) {return 1;}
    return 0;
}