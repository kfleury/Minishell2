/*
** EPITECH PROJECT, 2020
** my lib 2019
** File description:
** my_strncmp.c
*/
#include "my.h"

int my_strncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    for (; s1[i] == s2[i] && s1[i] && s2[i] && i < n; i++);
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
        return (0);
    else if (s1[i] > s2[i])
        return (1);
    else
        return (-1);
}
