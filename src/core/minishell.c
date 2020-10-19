/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** loop in minishell
*/
#include "main.h"
#include "struct.h"

int run_minishell(data_t *data)
{
    size_t oui = 0;
    char *new_str = NULL;
    char *str = NULL;

    while (show_prompt() == 0 && (getline(&str, &oui, stdin) != -1)) {
        new_str = clean_str(str, " \t");
        if (new_str[0] == '\0') {
            free(new_str);
            continue;
        }
        handle_arg(data, new_str);
        parse_command(data);
        free(new_str);
        free_all(data);
    }
    if (isatty(0) == 1)
        my_printf("exit\n");
    free_end(data->env, str);
    return (0);
}