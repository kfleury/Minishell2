/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** put error
*/
#include "my.h"

void my_puterror(char *str)
{
    write(2, str, my_strlen(str));
}