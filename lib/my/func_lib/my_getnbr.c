/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** atoy
*/
#include "my.h"

int my_getnbr(char const *str)
{
    int count = 0;
    int negativ = 1;
    int nb = 0;

    for (; str[count] < '0' || str[count] > '9'; count++) {
        if (str[count] == '-')
            negativ = -negativ;
    }
    for (; str[count] >= '0' && str[count] <= '9'; count++) {
        nb *= 10;
        nb += str[count] - '0';
    }
    return (nb * negativ);
}
