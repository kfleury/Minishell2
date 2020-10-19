/*
** EPITECH PROJECT, 2019
** strkat
** File description:
** int
*/
#include "my.h"

int *my_strcat_int(int *dest, int const *src, int size_dest, int size_src)
{
    int *result = malloc(sizeof(int)*(size_dest + size_src));
    int i = 0;
    int j = 0;

    for (; i != size_dest; i++)
        result[i] = dest[i];
    for (; j != size_src; i++, j++)
        result[i] = src[j];
    return result;
}