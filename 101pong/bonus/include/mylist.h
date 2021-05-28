/*
** EPITECH PROJECT, 2020
** mylist
** File description:
** JBD & NH
*/

#ifndef mylist_H_
#define mylist_H_

#include <SFML/Graphics.h>

//____ struct ____//

typedef struct link_list_t
{
    sfSprite *my_sprite;
    sfTexture *my_texture;
    sfVector2f my_pose;
    struct link_list_t *next;
} link_list_t;

typedef struct first_add_t
{
    link_list_t *first;
} first_add_t;

//____ fonc_proto ____ //

int my_list_size(link_list_t const *begin);
void free_list(link_list_t *my_list);
sfTexture *get_ellement_pos_texture(link_list_t *my_list, int pos);
sfSprite *get_ellement_pos_sprite(link_list_t *my_list, int pos);

#endif
