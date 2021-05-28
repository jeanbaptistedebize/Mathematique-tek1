/*
** EPITECH PROJECT, 2021
** B-MAT-100-PAR-1-3-102architect-jean-baptiste.debize
** File description:
** gestion_error
*/


#include <string.h>
#include <stdio.h>
#include <ctype.h>

static int my_str_isnum(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (isdigit(str[i]))
            return -1;
    }
    return 0;
}

static int print_usage(void)
{
    printf("USAGE\n    ./102architect x y transfo1 arg11 [arg12]");
    printf(" [transfo2 arg12 [arg22]] ...\n\n");
    printf("DESCRIPTION\n    x   abscissa of the original point\n");
    printf("    y   ordinate of the original point\n\n    ");
    printf("transfo arg1 [arg2]\n    -t i j  translation along vector (i, j)\n");
    printf("    -z m n  scaling by factors m (x-axis) and n (y-axis\n");
    printf("    -r d    rotation centered in O by a d degree angle\n    ");
    printf("-s d    reflection over the axis passing through");
    printf(" O with an inclination\n    \t    angle of d degrees\n");
    return 84;
}

static int check_num(char **argv, int av, int i)
{
    if (strcmp(argv[i], "-t") == 0 &&
        (i + 2 < av && !my_str_isnum(argv[i + 1]) &&
        !my_str_isnum(argv[i + 2])))
        return i += 2;
    if (strcmp(argv[i], "-z") == 0 &&
        (i + 2 < av && !my_str_isnum(argv[i + 1]) &&
        !my_str_isnum(argv[i + 2])))
        return i += 2;
    if (strcmp(argv[i], "-r") == 0 && (i + 1 < av &&
        !my_str_isnum(argv[i + 1])))
        return i += 1;
    if (strcmp(argv[i], "-s") == 0 && (i + 1 < av &&
        !my_str_isnum(argv[i + 1])))
        return i += 1;
    return 84;
}

int error(int av, char **argv)
{
    int b = 0;
    int i = 3;

    if (av > 1 && strcmp(argv[1], "-h") == 0)
        return print_usage();
    if (av < 4 || my_str_isnum(argv[1]) == 84 || my_str_isnum(argv[2]) == 84)
        return 84;
    for (; i < av; i++) {
        if (i == av)
            return b;
        else if (i > av ||  strstr("-t-z-r-s", argv[i]) == NULL)
            return 84;
        i = check_num(argv, av, i);
        if (i == 84)
            return 84;
        b++;
    }
    return b;
}
