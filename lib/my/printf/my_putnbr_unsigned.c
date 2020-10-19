/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** put nbr
*/
#include "my.h"

void my_putnbr_unsigned(unsigned int nbr)
{
    unsigned int nbr2;

    if (nbr >= 10) {
        nbr2 = nbr % 10;
        nbr = nbr / 10;
        my_putnbr_unsigned(nbr);
        my_putchar(nbr2 + 48);
    } else {
        my_putchar(nbr + 48);
    }
    return;
}
