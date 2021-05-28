/*
** EPITECH PROJECT, 2020
** my putchar function
** File description:
** my ptuchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
