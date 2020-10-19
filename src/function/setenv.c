/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** setenv
*/
#include "core.h"

int my_env(list_t *list, data_t *data)
{
    if (list->command[1] == NULL)
        tabprint(data->env);
    else
        my_printf("env: ‘%e’: No such file or directory\n",
            list->command[1]);
    return (0);
}

static int is_letter(char c, int status)
{
    if (status == 0) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            return (1);
    } else {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
            || (c >= '1' && c <= '9'))
            return (1);
    }
    return (0);
}

static int my_add_new_in_env(list_t *list, data_t *data)
{
    char *name = list->command[1];
    int len = 0;
    int i = 0;

    for (i = 0; data->env[i]; i++)
            if ((data->env[i][my_strlen(name)] == '=')
                && (my_strncmp(data->env[i], name, my_strlen(name)) == 0))
                break;
    if (list->command[2] == NULL)
        data->env[i][my_strlen(name) + 1] = '\0';
    else {
        len = my_strlen(list->command[1]) +
            my_strlen(list->command[2]) + 1;
        free(data->env[i]);
        data->env[i] = my_realloc_mod(list->command[1],
            list->command[2], len);
    }
    return (0);
}

static int exist_env(list_t *list, data_t *data, int len)
{
    if (is_letter(list->command[1][0], 0) == 0) {
        my_printf("%e\n",
                "setenv: Variable name must begin with a letter.");
        return (1);
    }
    for (int i = 0; list->command[1][i]; i++)
        if (is_letter(list->command[1][i], 1) == 0) {
            my_printf("%e\n",
                "setenv: Variable name must contain alphanumeric characters.");
            return (1);
        }
    data->env = my_realloc_td(data->env, len);
    if (list->command[2] == NULL)
        data->env[len - 1] = my_strdup_mod(list->command[1]);
    else
        data->env[len - 1] = my_strcat_mod(list->command[1],
            list->command[2]);
    return (0);
}

int my_setenv(list_t *list, data_t *data)
{
    int len = tablen(data->env) + 1;

    if (list->command[1] == NULL) {
        my_env(list, data);
        return (0);
    } else if (tablen(list->command) >=  4) {
        my_printf("%e\n", "setenv:Too many arguments.");
        return (1);
    }
    if (is_env_exist(data->env, list->command[1]) == false) {
        if (exist_env(list, data, len) == 1)
            return (1);
    } else
        my_add_new_in_env(list, data);
    return (0);
}
