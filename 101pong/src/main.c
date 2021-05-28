/*
** EPITECH PROJECT, 2021
** Mathematique-tek1
** File description:
** main
*/

#include <unistd.h>
#include "my.h"

int main(int av, char **argv)
{
    if (check_arg(av, argv) == 84) {
        write(2, "error syntax \nMust be: x0 y0 z0 x1 y1 z1 t\n", 43);
        return 84; 
    }
    pong_calc_direction(av, argv);
    return 0;
}