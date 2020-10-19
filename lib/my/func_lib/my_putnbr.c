/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** put nbr
*/
#include "my.h"

void my_putnbr(int nbr)
{
    int nbr2;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr >= 10) {
        nbr2 = nbr % 10;
        nbr = nbr / 10;
        my_putnbr(nbr);
        my_putchar(nbr2 + 48);
    } else {
        my_putchar(nbr + 48);
    }
    return;
}
