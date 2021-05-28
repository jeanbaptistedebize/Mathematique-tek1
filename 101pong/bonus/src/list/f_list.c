/*
** EPITECH PROJECT, 2020
** for list*
** File description:
** JBD & NH
*/

#include <stdlib.h>
#include "mylist.h"
#include "my_csfml.h"

void free_list(link_list_t *my_list)
{
    link_list_t *temp = NULL;

    while (my_list != NULL) {
        temp = my_list->next;
        sfTexture_destroy(my_list->my_texture);
        sfSprite_destroy(my_list->my_sprite);
        free(my_list);
        my_list = temp;
    }
}

sfSprite *get_ellement_pos_sprite(link_list_t *my_list, int pos)
{
    int i = 0;

    while (i < pos) {
        i++;
        my_list = my_list->next;
    }
    return my_list->my_sprite;
}

sfTexture *get_ellement_pos_texture(link_list_t *my_list, int pos)
{
    int i = 0;

    while (i < pos) {
        i++;
        my_list = my_list->next;
    }
    return my_list->my_texture;
}

static link_list_t *create_cell(char *texture, sfVector2f my_pose)
{
    link_list_t *new = malloc(sizeof(link_list_t));
    sfTexture *my_texture;

    new->my_sprite = sfSprite_create();
    my_texture = set_texture(texture, new->my_sprite);
    new->my_texture = my_texture;
    new->my_pose = my_pose;
    new->next = NULL;
    return new;
}

link_list_t *ad_cell_list(link_list_t *my_list, sfVector2f my_pose, char *texture, int pos)
{
    link_list_t *previous_pointer = my_list;
    link_list_t *current_pointer = my_list;
    link_list_t *cell = create_cell(texture, my_pose);
    int i = 0;

    if (my_list == NULL)
        return cell;
    if (pos == 0) {
        cell->next = my_list;
        my_list = cell;
        return my_list;
    }
    while (i < pos) {
        i++;
        previous_pointer = current_pointer;
        current_pointer = current_pointer->next;
    }
    previous_pointer->next = cell;
    cell->next = current_pointer;
    return my_list;
}