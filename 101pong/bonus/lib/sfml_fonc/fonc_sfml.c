/*
** EPITECH PROJECT, 2020
** fonc for sfml
** File description:
** sfml
*/

#include <SFML/Graphics.h>
#include "../../include/mylist.h"

link_list_t *ad_cell_list(link_list_t *my_list, sfVector2f my_pose, char *texture, int pos);

sfRenderWindow *create_window(
    unsigned int x, unsigned int y,unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};
    return (sfRenderWindow_create(video_mode, title, sfClose, NULL));
} 

void drawsprite(
    sfRenderWindow *window, sfSprite *my_sprite, float x, float y)
{   
    sfVector2f pose = {x, y};

    sfSprite_setPosition(my_sprite, pose);
    sfRenderWindow_drawSprite(window, my_sprite, NULL);
}

void drawCircleShape(sfRenderWindow *window, sfCircleShape *shape, float x, float y)
{
    sfVector2f pose = {x, y};

    sfCircleShape_setPosition(shape, pose);
    sfRenderWindow_drawCircleShape(window, shape, NULL);
}

void drawRectangleShape(sfRenderWindow *window, sfRectangleShape *shape, float x, float y)
{
    sfVector2f pose = {x, y};

    sfRectangleShape_setPosition(shape, pose);
    sfRenderWindow_drawRectangleShape(window, shape, NULL);
}

sfTexture *set_texture(char *texture_path, sfSprite *my_sprite)
{
    sfTexture *my_texture = sfTexture_createFromFile(texture_path, NULL);

    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    return my_texture;
}

sfCircleShape *create_CircleShape(int radius)
{
    sfCircleShape *shape = sfCircleShape_create();

    sfCircleShape_setRadius(shape, radius);
    return shape;
}

sfRectangleShape *create_RectangleShape(int h, int l)
{
    sfRectangleShape *shape = sfRectangleShape_create();
    sfVector2f size = {h, l};

    sfRectangleShape_setSize(shape, size);
    return shape;
}

link_list_t *add_sprite(char *texture, link_list_t *my_list, float x, float y)
{   
    sfVector2f my_pose = {x, y};

    return ad_cell_list(my_list, my_pose, texture, my_list_size(my_list));
}