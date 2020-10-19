/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** handle line.c
*/
#include "my.h"
#include "struct.h"
#include <stdio.h>

static const int NUMBER_MANAGEMENT = 6;

static const char *management[6] = {
    "|",
    ";",
    "<<",
    "<",
    ">>",
    ">"
};

static char **trans(char *str, int n)
{
    char **tab = NULL;
    char *temp = my_strdup(str);

    temp[n] = '\0';
    tab = my_split(temp, " \t");
    free(temp);
    return (tab);
}

static void reorganize(char **str, char n, bool double_char)
{
    for (; (*str)[0] != n; (*str)++);
    (*str) += ((double_char == true) ? 2 : 1);
    for (; is_char((*str)[0]) == 0 && (*str)[0] != '\0'; (*str)++);
}

static void conditional(char **str, data_t *data, int *i, int *j)
{
    char *res = my_strstr(&(*str)[*i], management[*j]);

    if (res == NULL || res != &(*str)[*i])
        return;
    push((list_t) {trans((*str), (*i)), management[(*j)], NULL},
        &data->list);
    reorganize(str, (*str)[(*i)], my_strlen(management[*j]) == 2);
    (*i) = 0;
    (*j) = -1;
}

void handle_arg(data_t *data, char *temp)
{
    char *str = temp;

    for (int i = 0, j = 0; str[i]; j++) {
        conditional(&str, data, &i, &j);
        if (j == NUMBER_MANAGEMENT - 1) {
            j = -1;
            i++;
        }
    }
    push((list_t) {trans(str, my_strlen(str)), "NULL", NULL},
        &data->list);
}
