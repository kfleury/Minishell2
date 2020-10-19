/*
** EPITECH PROJECT, 2019
** my_strdupo
** File description:
** allocate memory and copies the string given in argument
*/
#include "my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src) + 1;
    char *dup = malloc(len);

    if (dup == NULL)
        return (NULL);
    dup = my_strcpy(dup, src);
    dup[len - 1] = '\0';
    return (dup);
}
