/*
** EPITECH PROJECT, 2020
** my lib 2019
** File description:
** my realoc 2d array
*/
#include "my.h"

char **my_realloc_td(char **tab, int new_size)
{
    char **new_tab = NULL;
    int i = 0;

    if (tab == NULL || new_size < 1)
        return (NULL);
    new_tab = malloc(sizeof(char *) * (new_size + 1));
    for (i = 0; tab[i]; i++) {
        new_tab[i] = my_strdup(tab[i]);
        free(tab[i]);
    }
    new_tab[new_size] = NULL;
    free(tab);
    return (new_tab);
}