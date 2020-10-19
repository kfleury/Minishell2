/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** init.c
*/
#include "struct.h"

void init_sh(data_t *data, char **env)
{
    data->env = NULL;
    data->path = NULL;
    data->list = my_create_list();
    data->temp = my_create_list();
    tabcpy(&data->env, env, tablen(env));
}
