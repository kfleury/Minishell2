/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** usage.c
*/
#include "my.h"

void my_restr(char **str, int size)
{
    int c = 0;

    if ((*str) == NULL || size < 1)
        return;
    for (; (*str)[c] != '\n' && (*str)[c] != '\0'; c++);
    (*str)[c] = '\0';
}
