/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** core function
*/
#include "struct.h"
#include "core.h"

void main_core(data_t *data, list_t *elem)
{
    for (int i = 0; func_tab[i].flag; i++) {
        if (my_strcmp(func_tab[i].flag, elem->command[0]) == 0) {
            func_tab[i].tpf(elem, data);
            return;
        }
    }
    exec_bin(elem, data);
}

int check_priorities(list_t *elem, data_t *data)
{
    if (elem->flag[0] == '|')
        return (my_pipe(elem, data));
    if (my_strcmp(elem->flag, ">") == 0)
        return (my_rredirection(elem, data));
    if (my_strcmp(elem->flag, ">>") == 0)
        return (my_r2redirection(elem, data));
    if (my_strcmp(elem->flag, "<") == 0)
        return (my_lredirection(elem, data));
    if (my_strcmp(elem->flag, "<<") == 0)
        return (my_l2redirection(elem, data));
    main_core(data, elem);
    return (0);
}

static int check_null_command(list_t *elem)
{
    if (elem->command == NULL && my_strcmp(elem->flag, "NULL") != 0
        && my_strcmp(elem->flag, ";") != 0) {
        my_printf("%e\n", "Invalid null command.");
        return (1);
    }
    return (0);
}

void parse_command(data_t *data)
{
    int return_value = 0;
    list_t *elem = data->list;

    for (; elem; elem = elem->next) {
        if (check_null_command(elem) == 1)
            exit(84);
        if (elem->command == NULL)
            continue;
        return_value = check_priorities(elem, data);
        if (return_value >= 1)
            for (int i = 0; i != return_value; i++, elem = elem->next);
    }
}