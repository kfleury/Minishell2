/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** return 1 if the string contains digits
*/
#include "my.h"

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[0] == '-')
            i++;
        if ('0' <= str[i] && str[i] <= '9')
            continue;
        else
            return (0);
    }
    return (1);
}
