/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** put base
*/
#include "my.h"

int my_putnbr_baseoct(int nbr, char const *base)
{
    unsigned long long i = 0;
    unsigned long long j = 0;
    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    i = nbr / my_strlen(base);
    j = nbr % my_strlen(base);
    if (i > 0)
        my_putnbr_baseoct(i, base);
    my_putchar(base[j]);
    return (0);
}

void baseoct(int nbr)
{
    char *base3 = "01234567";
    my_putnbr_baseoct(nbr, base3);
}
