/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** main
*/
#include "my.h"
#include "main.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
    data_t data;
    (void) ac;
    (void) av;

    init_sh(&data, env);
    if (ac != 1)
        return (84);
    return (run_minishell(&data));
}
