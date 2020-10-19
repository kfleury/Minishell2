/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** return 1 if the string contains digits
*/
#include "my.h"

int my_str_isnum(char const *str)
{
    for (int j = 0; str[j] != '\0';) {
        if (str[j]  >= '0' &&  str[j] <= '9')
            j++;
        else
                return (84);
    }
    return (0);
}
