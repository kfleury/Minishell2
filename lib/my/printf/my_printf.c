/*
** EPITECH PROJECT, 2019
** printc
** File description:
** print des f
*/
#include "my.h"

void writing_sequel(va_list ap, int k)
{
    if (k == 2 || k == 3 || k == 4 || k == 5
        || k == 6 || k == 7 || k == 9) {
        if (k == 2)
            k = 0;
        if (k == 3)
            k = 1;
        if (k == 4)
            k = 2;
        if (k == 5)
            k = 3;
        if (k == 6)
            k = 4;
        if (k == 7)
            k = 5;
        if (k == 9)
            k = 6;
        tabi[k].tpf(va_arg(ap, int));
        k = 0;
    }
}

void writing(bases *use, va_list ap, int k)
{
    if (use->flag[k] == use->flag[which_flag(use->fmt[use->i+1], use)]) {
        if (k == 0 || k == 10 || k == 12) {
            if (k == 10)
                k = 2;
            if (k == 12)
                k = 1;
            tabcs[k].tpf(va_arg(ap, char *));
            k = 0;
        }
        if (k == 1)
            tabc[0].tpf(va_arg(ap, int));
        if (k == 8)
            tabu[0].tpf(va_arg(ap, unsigned int));
        if (k == 11)
            tabb[0].tpf(use);
        writing_sequel(ap, k);
        use->i++;
    }
}

int my_printf(char *fmt, ...)
{
    bases use;
    va_list ap;

    va_start(ap, fmt);
    for (use.i = 0; fmt[use.i]; use.i++) {
        if (fmt[use.i] == '%' && is_it_a_flag(fmt[use.i+1], &use, fmt) == 1)
            for (int k = 0; use.flag[k]; k++)
                writing(&use, ap, k);
        else {
            if (fmt[use.i-1] == '%'
                && is_it_a_flag(fmt[use.i], &use, fmt) == 0);
            else
                my_putchar(fmt[use.i]);
        }
    }
    va_end(ap);
    return (0);
}
