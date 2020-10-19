/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** main
*/
#include "my.h"

int is_delim(char c, char const *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return (1);
    return (0);
}

static int get_length(int len, char const *delim, char *str)
{
    char *tmp = str;

    for (; tmp[len] != '\n' && tmp[len] != '\0'; len++)
        if (is_delim(tmp[len], delim) == 1)
            for (; is_delim(tmp[len+1], delim) == 1; tmp++);
    return (len);
}

static void copy_clean_str(char *new_str, char *str, char const *delim)
{
    int i = 0;

    for (i = 0; str[0] != '\n' && str[0] != '\0'; str++) {
        new_str[i++] = str[0];
        if (is_delim(str[0], delim) == 1)
            for (; is_delim(str[1], delim) == 1; str++);
    }
    if (i)
        i -= is_delim(new_str[i-1], delim);
    new_str[i] = '\0';
}

char *clean_str(char *str, char const *delim)
{
    int len = 0;
    char *new_str = NULL;

    for (; is_delim(str[0], delim) == 1; str++);
    len = get_length(len, delim, str);
    new_str = malloc(sizeof(char) * (len + 1));
    if (!new_str)
        return (NULL);
    copy_clean_str(new_str, str, delim);
    return (new_str);
}