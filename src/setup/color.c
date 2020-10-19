/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** color.c
*/
#include "my.h"
#include "main.h"
#include <sys/wait.h>

void color2(void)
{
    char *path = NULL;
    size_t oui = 0;

    my_printf("%s\n", getcwd(path, oui));
    my_printf("%s", KRED);
    my_printf("> ");
    my_printf("%s", RESET);
}

int show_prompt(void)
{
    if (isatty(0) == 0)
        return (0);
    my_printf("%s", KRED);
    my_printf("M");
    my_printf("%s", KCYN);
    my_printf("y");
    my_printf("%s", KGRN);
    my_printf("_");
    my_printf("%s", KYEL);
    my_printf("s");
    my_printf("%s", KBLU);
    my_printf("h");
    my_printf("%s", KMAG);
    my_printf("%s", KCYN);
    my_printf(": ");
    color2();
    return (0);
}
