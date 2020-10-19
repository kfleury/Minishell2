/*
** EPITECH PROJECT, 2019
** printc %S
** File description:
** oui
*/
#include "my.h"

void ascii(char *str)
{
    for (int i = 0; str[i]; i++) {
        if ((0 <= str[i] && str[i] <= 32) || (str[i] == 127)) {
            my_putchar('\\');
            if (0 <= str[i] && str[i] <= 7)
                my_putstr("00");
            if (8 <= str[i] && str[i] <= 32)
                my_putchar('0');
            baseoct(str[i]);
            i++;
        }
        my_putchar(str[i]);
    }
}
