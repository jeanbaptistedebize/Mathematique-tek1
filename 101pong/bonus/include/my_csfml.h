/*
** EPITECH PROJECT, 2020
** sfmlf header
** File description:
** my sfml header
*/


#ifndef MY_CSFML_H_
#define MY_CSFML_H_

#include <SFML/Graphics.h>
#include "mylist.h"

sfRenderWindow *create_window(
    unsigned int x, unsigned int y,unsigned int bpp, char *title);
void drawsprite(
    sfRenderWindow *window, sfSprite *my_sprite, float x, float y);
void drawCircleShape(sfRenderWindow *window, sfCircleShape *shape, float x, float y);
void drawRectangleShape(sfRenderWindow *window, sfRectangleShape *shape, float x, float y);
sfTexture *set_texture(char *texture_path, sfSprite *my_sprite);
sfCircleShape *create_CircleShape(int radius);
sfRectangleShape *create_RectangleShape(int h, int l);
link_list_t *add_sprite(char *texture, link_list_t *my_list, float x, float y);

#endif