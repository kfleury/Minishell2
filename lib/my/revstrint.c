/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** revstrint
*/
#include "my.h"

void my_swapint(int *a, int *b)
{
    int a3 = *a;

    *a = *b;
    *b = a3;
}

int my_intlen(int o)
{
    int cmp = 0;

    for (; o > 0; cmp++, o /= 10);
    return (cmp);
}

int *my_revstrint(int *str, int len)
{
    int decount = 0;
    int count = len - 1;

    while (count >= decount) {
        my_swapint(&str[count], &str[decount]);
        decount++;
        count--;
    }
    return (str);
}