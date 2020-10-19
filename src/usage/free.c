/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** free.c
*/
#include "struct.h"
#include <stdlib.h>

void free_all(data_t *data)
{
    list_t *current = data->list;
    list_t *next;

    while (current != NULL) {
        free_end(current->command, NULL);
        next = current->next;
        free(current);
        current = next;
    }
    data->list = NULL;
}

void free_end(char **data, char *str)
{
    if (data != NULL) {
        for (int i = 0; data[i]; i++) {
            if (data[i] != NULL)
                free(data[i]);
        }
        free(data);
    }
    if (str != NULL)
        free(str);
}