/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** cd
*/
#include "core.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

static const int NUMBER_FOR_ARRAY_PWD = 4;

char *path_env(char **tab, char *name)
{
    char *temp = NULL;

    for (int i = 0; tab[i]; i++)
        if ((tab[i][my_strlen(name)] == '=')
            && (my_strncmp(tab[i], name, my_strlen(name)) == 0)) {
            temp = tab[i];
            for (; temp[0] != '='; temp++);
            temp++;
        }
    return (temp);
}

static char **create_tab(char *command, char *env_name, char *pwd)
{
    char **tab = malloc(sizeof(char *) * NUMBER_FOR_ARRAY_PWD);

    tab[0] = my_strdup(command);
    tab[1] = my_strdup(env_name);
    tab[2] = pwd;
    tab[3] = NULL;
    return (tab);
}

static void refresh_pwd(data_t *data)
{
    char *old_pwd = my_strdup(path_env(data->env, "PWD"));
    char **tab = NULL;
    char *path = NULL;
    size_t oui = 0;

    tab = create_tab("setenv", "OLDPWD", old_pwd);
    push((list_t) {tab, NULL, NULL}, &data->temp);
    my_setenv(data->temp, data);
    tab = create_tab("setenv", "PWD", getcwd(path, oui));
    push((list_t) {tab, NULL, NULL}, &data->temp);
    my_setenv(data->temp->next, data);
}

static int different_arg(list_t *list, data_t *data)
{
    char *path = NULL;

    if (list->command[1] == NULL
        || my_strcmp(list->command[1], "~") == 0)
        path = path_env(data->env, "HOME");
    else if (my_strcmp(list->command[1], "-") == 0)
        path = path_env(data->env, "OLDPWD");
    else
        path = list->command[1];
    if (path == NULL) {
        my_printf("%e: %e.\n", "", "No such file or directory");
        return (84);
    } else if (chdir(path) == -1) {
        my_printf("%e: %e.\n", path, strerror(errno));
        return (84);
    }
    refresh_pwd(data);
    return (0);
}

int my_cd(list_t *list, data_t *data)
{
    if (tablen(list->command) >= 3) {
        my_printf("%e\n", "cd: Too many arguments.");
        return (1);
    }
    else {
        different_arg(list, data);
    }
    return (0);
}