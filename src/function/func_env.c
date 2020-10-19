/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** env function
*/
#include "my.h"

bool is_env_exist(char **env, char *name)
{
    for (int i = 0; env[i]; i++)
        if (my_strncmp(env[i], name, my_strlen(name)) == 0)
            return (true);
    return (false);
}

char *my_strdup_mod(char const *src)
{
    int len = my_strlen(src) + 2;
    char *dup = malloc(len);

    if (dup == NULL)
        return (NULL);
    dup = my_strcpy(dup, src);
    dup[len - 2] = '=';
    dup[len - 1] = '\0';
    return (dup);
}

char *my_strcat_mod(char *s1, char *s2)
{
    int len = my_strlen(s1) + my_strlen(s2) + 2;
    int i = 0;
    char *res = malloc(len);

    for (int j = 0; s1[j]; j++, i++)
        res[i] = s1[j];
    res[i++] = '=';
    for (int j = 0; s2[j]; j++, i++)
        res[i] = s2[j];
    res[i] = '\0';
    return (res);
}

char *my_realloc_mod(char *s1, char *s2, int size)
{
    char *ptr_realloc = NULL;
    int c = 0;

    if (s1 == NULL || s2 == NULL || size < 1)
        return (NULL);
    ptr_realloc = malloc(size + 1);
    if (ptr_realloc == NULL)
        return (NULL);
    for (; s1[c]; c++)
        ptr_realloc[c] = s1[c];
    ptr_realloc[c++] = '=';
    for (int i = 0; s2[i]; i++, c++)
        ptr_realloc[c] = s2[i];
    ptr_realloc[c] = '\0';
    return (ptr_realloc);
}