/*
** EPITECH PROJECT, 2020
** my lib 2019
** File description:
** my_join
*/
#include "my.h"

static void free_join(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

char *char_to_str(char c)
{
    char *str = malloc(2);

    str[0] = c;
    str[1] = '\0';
    return (str);
}

void my_strcat_na(char **dest, char const *src)
{
    int len = 0;

    for (; (*dest)[len]; len++);
    for (int i = 0; src[i]; i++, len++)
        (*dest)[len] = src[i];
    (*dest)[len] = '\0';
}

char *my_join(char **tab, char cc, bool free_tab)
{
    char *str = NULL;
    char *c = char_to_str(cc);
    size_t total_length = 0;

    for (int i = 0; tab[i]; i++)
        total_length += my_strlen(tab[i]) + 1;
    str = malloc(total_length);
    str = my_strcpy(str, tab[0]);
    for (int i = 1; tab[i]; i++) {
        my_strcat_na(&str, c);
        my_strcat_na(&str, tab[i]);
    }
    free(c);
    if (free_tab == true)
        free_join(tab);
    return (str);
}
