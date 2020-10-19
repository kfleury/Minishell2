/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** main
*/
#include "my.h"
#include <string.h>
#include <errno.h>

void error_nf(char *command)
{
    my_printf("%e: Command not found.\n", command);
}

void report_error_and_exit(const char *msg)
{
    my_printf("%e: %e.", msg, strerror(errno));
    exit(84);
}