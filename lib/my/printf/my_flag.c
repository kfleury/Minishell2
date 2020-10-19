/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_flag
*/
#include "my.h"

int is_it_a_flag(char f, bases *use, char *fmt)
{
    char *flag = "scdioxXbupS%e";
    use->flag = flag;
    use->nbr = 0;
    use->fmt = fmt;

    if (f == 's' || f == 'c' || f == 'd'
        || f == 'i' || f == 'o' || f == 'x'
        || f == 'X' || f == 'b' || f == 'u'
        || f == 'p' || f == 'S' || f == '%'
        || f == 'e')
        return (1);
    else
        return (0);
}

int which_flag(char fmt, bases *use)
{
    for (int i = 0; use->flag[i]; i++)
        if (use->flag[i] == fmt)
            return (i);
    return (0);
}
