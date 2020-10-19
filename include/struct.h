/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdio.h>
#include "my.h"

typedef struct double_s {
    int nbr;
    char *c;
} double_t;

typedef struct data_s {
    char **env;
    char *path;
    list_t *temp;
    list_t *list;
} data_t;

// list
void push(list_t data, list_t **list);
void print_l(list_t *head);

// free
void free_end(char **data, char *str);
void free_all(data_t *data);

#endif /* !STRUCT_H_ */
