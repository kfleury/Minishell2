/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** unsetenv
*/
#include "core.h"
#include "struct.h"

void my_realloc_td_mod(char ***tab, int size, int o)
{
    char **str = malloc(sizeof(char *) * size);
    int a = 0;
    int b = 0;

    for (; a < size - 1; a++, b++) {
        if (a == o)
            b++;
        str[a] = my_strdup((*tab)[b]);
    }
    str[a] = NULL;
    free_end((*tab), NULL);
    (*tab) = str;
}

static int erase_line_in_env(data_t *data, char *name)
{
    int i = 0;
    int len = 0;

    if (is_env_exist(data->env, name) == false)
        return (84);
    for (i = 0; data->env[i]; i++) {
        len = (my_strlen(data->env[i]) < my_strlen(name)) ?
            my_strlen(data->env[i]) : my_strlen(name);
        if ((data->env[i][len] == '=')
            && (my_strncmp(data->env[i], name, my_strlen(name)) == 0)) {
            my_realloc_td_mod(&data->env, tablen(data->env), i);
            return (0);
        }
    }
    return (0);
}

int my_unsetenv(list_t *list, data_t *data)
{
    if (list->command[1] == NULL) {
        my_printf("%e\n", "unsetenv: Too few arguments.");
        return (0);
    }
    else {
        for (int j = 1; list->command[j]; j++)
            erase_line_in_env(data, list->command[j]);
        }
    return (0);
}