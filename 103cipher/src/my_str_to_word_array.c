/*
** EPITECH PROJECT, 2020
** my_str_to_worda
** File description:
** my_str_to_word_array
*/

#include <string.h>
#include <stdlib.h>

static int number_of_word(char  const *str)
{
    int i = 0;
    int conteur = 0;
    int a = 0;

    while (str[i] != '\0') {
        while ((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= '0' && str[i] <= '9')) {
            a = 1;
            i++;
        }
        if (a == 1) {
            a = 0;
            conteur++;
        }
        i++;
    }
    return conteur;
}

static char copy_putain_de_string(char const *str, char *src, int len, int i)
{
    int src_len = 0;

    while (0 < len) {
        src_len = strlen(src);
        src[src_len] = str[i - len];
        src[src_len + 1] = '\0';
        len--;
    }
}

static int test_if_alpha(char const *str, int len, int i)
{
    while ((str[i] >= 'a' && str[i] <= 'z')
        || (str[i] >= 'A' && str[i] <= 'Z')
        || (str[i] >= '0' && str[i] <= '9')) {
        len++;
        i++;
    }
    return len;
}

static int do_the_things(char  const *str, char **tab, char *src, int len)
{
    int place = 0;
    int i = 0;

    while (str[i] != '\0') {
        len = test_if_alpha(str, len, i);
        i += len;
        if (len > 0) {
            src = malloc(sizeof(char) * (len + 1));
            src[0] = '\0';
            copy_putain_de_string(str, src, len, i);
            tab[place] = src;
            src = "";
            len = 0;
            place++;
        }
        if (str[i] != '\0')
            i++;
    }
    return place;
}

char **my_str_to_word_array(char  const *str)
{
    char **tab;
    char *src;
    int len = 0;
    int place = 0;

    tab = malloc(sizeof(char *) * (number_of_word(str) + 1));
    place = do_the_things(str, tab, src, len);
    tab[place] = NULL;
    return tab;
}
