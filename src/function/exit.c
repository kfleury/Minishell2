/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** exit
*/
#include "struct.h"

static int exit_number(char *data, char *command, data_t *to_free)
{
    int quit = 0;
    unsigned char quit2;

    if (my_str_isnum(data) == 1) {
        quit2 = my_getnbr(data);
        quit = quit2;
        free_all(to_free);
        free_end(to_free->env, NULL);
        exit(quit);
    }
    else {
        my_puterror(command);
        my_puterror(": Expression Syntax.\n");
    }
    return (0);
}

int my_exit(list_t *list, data_t *data)
{
    if (list->command[1] == NULL) {
        my_printf("exit\n");
        free_all(data);
        free_end(data->env, NULL);
        exit(0);
    }
    else
        exit_number(list->command[1], list->command[0], data);
    return (0);
}