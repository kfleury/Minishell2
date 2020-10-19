/*
** EPITECH PROJECT, 2020
** my lib 2019
** File description:
** function for 2d array
*/
#include "my.h"

int tablen(char **tab)
{
    int i = 0;

    for (; tab[i]; i++);
    return (i);
}

void tabprint(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        if (tab[i+1] == NULL)
            my_printf("%s\n", tab[i]);
        else
            my_printf("%s\n", tab[i]);
    }
}

void tabcpy(char ***dest, char **src, int length)
{
    int width = 0;
    (*dest) = malloc(sizeof(char *) * (length + 1));

    for (int i = 0; i < length; i++) {
        width = my_strlen(src[i]) + 1;
        (*dest)[i] = malloc(sizeof(char) * width);
        my_memcpy((*dest)[i], src[i], width);
    }
    (*dest)[length] = NULL;
}
