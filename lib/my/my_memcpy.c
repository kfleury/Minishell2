/*
** EPITECH PROJECT, 2020
** my lib 2019
** File description:
** my_memcpy
*/
#include <stdlib.h>
#include "my.h"

void my_memcpy(void *dest, void *src, int size)
{
    char *ptr_dest = (char *) dest;
    char *ptr_src = (char *) src;
    int i = 0;

    for (; i < size; i++)
        ptr_dest[i] = ptr_src[i];
}