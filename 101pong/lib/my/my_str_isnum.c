/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** is num
*/

int  my_str_isnum(char  const *str)
{
    int i = 0;
    int compte = 0;
    int compte_neg = 0;

    while (str[i] != '\0') {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '-')
            return 84;
        if (str[i] == '-')
            compte_neg++;
        if (str[i] == '.')
            compte++;
        i++;
    }
    if(compte > 1)
        return 84;
    if(compte == 1 || compte_neg % 2 != 0)
        return 2;
    return 1;
}