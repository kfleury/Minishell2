/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_realloc
*/
#include "my.h"

char *my_realloc(char *str, int size)
{
    char *ptr_realloc = NULL;
    int c = 0;

    if (str == NULL || size < 1)
        return (NULL);
    ptr_realloc = malloc(size + 2);
    if (ptr_realloc == NULL)
        return (NULL);
    for (; str[c]; c++)
        ptr_realloc[c] = str[c];
    ptr_realloc[c] = '\0';
    free(str);
    return (ptr_realloc);
}
