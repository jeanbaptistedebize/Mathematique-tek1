/*
** EPITECH PROJECT, 2020
** my_rev_list
** File description:
** JBD & NH
*/

#include <stddef.h>
#include "mylist.h"

int my_list_size(link_list_t const *begin)
{
    int len_list = 0;

    while (begin != NULL) {
        begin = begin->next;
        len_list++;
    }
    return len_list;
}
