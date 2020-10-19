/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** my_itoa
*/

#include "my.h"

static char *itoa_neg(int i, int temp, char *result)
{
    char *res = NULL;

    temp *= -1;
    res = malloc(my_intlen(temp) + 2);
    for (; temp != 0; i++) {
        res[i] = temp % 10 + '0';
        temp /= 10;
    }
    res[i] = '-';
    res[i+1] = '\0';
    free(result);
    return (my_revstr(res));
}

char *my_itoa(int o)
{
    int i = 0;
    int temp = o;
    char *result = malloc(my_intlen(o) + 1);

    if (temp == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    if (o < 0)
        return (itoa_neg(i, temp, result));
    for (; temp != 0; i++) {
        result[i] = temp % 10 + '0';
        temp /= 10;
    }
    result[i] = '\0';
    return (my_revstr(result));
}