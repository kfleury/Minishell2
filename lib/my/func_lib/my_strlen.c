/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** counts and returns
** the number of characters
** found in the string
** passed as parameter
*/
#include "my.h"

int my_strlen(char const *str)
{
    int f = 0;
    while (str[f] != '\0') {
        f++;
    }
    return (f);
}
