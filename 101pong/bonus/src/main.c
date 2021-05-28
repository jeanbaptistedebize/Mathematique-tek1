/*
** EPITECH PROJECT, 2020
** main
** File description:
** main fonction
*/


#include <SFML/Graphics.h>
#include "my_csfml.h"

int pong(sfRenderWindow *window, int *result);
void display_result(int *result, sfRenderWindow *window, sfEvent event);

int main(void)
{
    sfRenderWindow *window = create_window(1000, 600, 32, "Pong");
    sfEvent event;
    int i = 0;
    int result[3] = {0};

    while (sfRenderWindow_isOpen(window) && result[0] < 3 && result[1] < 3) {
        i = pong(window, result);
        if (i == 1)
            result[0]++;
        if (i == 2)
            result[1]++;
    }
    while (sfRenderWindow_isOpen(window)) {
        display_result(result, window, event);
    }
    return 0;
}
