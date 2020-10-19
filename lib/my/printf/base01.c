/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** put base
*/
#include "my.h"

int my_putnbr_base01(int nbr, char const *base)
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
        my_putnbr_base01(i, base);
    my_putchar(base[j]);
    return (0);
}

void base01(int nbr)
{
    char *base2 = "01";
    my_putnbr_base01(nbr, base2);
}
