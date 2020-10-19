/*
** EPITECH PROJECT, 2019
** percent
** File description:
** precentù
*/
#include "my.h"

int compteur_percent(bases *use)
{
    int cmp = 0;
    int i = use->i;

    for (; use->fmt[i] == '%'; i++) {
        if (use->fmt[i] == '%')
            cmp++;
    }
    cmp = (cmp % 2 == 0) ? 2 : 1;
    return (cmp);
}

void percent_percent(bases *use)
{
    for (; use->fmt[use->i] != '\0'; use->i += compteur_percent(use)) {
        if (use->fmt[use->i] != '%')
            break;
        if (use->fmt[use->i] == '%' && use->fmt[use->i+1] == '%') {
            my_putchar('%');
        }
    }
    use->i -= 2;
}
