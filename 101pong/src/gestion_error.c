/*
** EPITECH PROJECT, 2021
** Mathematique-tek1
** File description:
** gestion_error
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"

static void display_usage(void)
{
    my_putstr("USAGE\n     ./101pong x0 y0 z0 x1 y1 z1 n\n\n");
    my_putstr("DESCRIPTION\n   x0 ball abscissa at time t - 1\n");
    my_putstr("   x0 ball abscissa at time t - 1\n");
    my_putstr("   y0 ball ordinate at time t - 1\n");
    my_putstr("   z0 ball altitude at time t - 1\n");
    my_putstr("   x1 ball abscissa at time t\n");
    my_putstr("   y1 ball ordinate at time t\n");
    my_putstr("   z1 ball altitude at time t\n");
    my_putstr("   n  time shift (greater than or equal to zero, integer)\n");
}

int check_arg(int av, char **argv)
{

    if (av == 2 && strcmp(argv[1], "-h") == 0) {
        display_usage();
        exit(84);
    }
    if (av != 8)
        return 84;
    for(int i = 1; i < 7; i++) {
        if(my_str_isnum(argv[i]) == 84) {
            return 84;
        }
    }
    if(my_str_isnum(argv[7]) != 1)
        return  84;
    return 0;
}
