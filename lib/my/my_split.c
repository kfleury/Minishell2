/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_str_to_wordarray
*/
#include "my.h"

int is_char(char c)
{
    if (c >= '!' && c <= '~')
        return (1);
    return (0);
}

int nbr_of_words(char const *str, char const *delim)
{
    int len = 0;

    for (; str[0]; len++) {
        for (; str[0] && is_delim(str[0], delim) == 0; str++);
        for (; is_delim(str[0], delim) == 1; str++);
    }
    return (len);
}

static int malloc_word(char *str, char **tab, char const *delim)
{
    int len = 0;

    for (; str[len] != '\0' && is_delim(str[len], delim) == 0; len++);
    tab[0] = malloc(sizeof(char) * (len + 1));
    if (!tab[0])
        return (1);
    return (0);
}

static void copy_word(char **str, char *tab, char const *delim)
{
    for (; **str != '\0' && is_delim(**str, delim) == 0; (*str)++, tab++)
        *tab = **str;
    *tab = '\0';
    (*str)++;
}

char **my_split(char *str, char const *delim)
{
    int nbr_words = nbr_of_words(str, delim);
    char **tab = NULL;

    if (nbr_words == 0)
        return (NULL);
    tab = malloc(sizeof(char *) * (nbr_words + 1));
    for (int i = 0; i != nbr_words; i++) {
        if (malloc_word(str, &tab[i], delim) == 1)
            return (NULL);
        copy_word(&str, tab[i], delim);
    }
    tab[nbr_words] = NULL;
    return (tab);
}