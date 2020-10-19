/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** exec
*/
#include "core.h"
#include "error.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int signal_parent(pid_t c_pid)
{
    int value = 0;
    int status = 0;
    pid_t pid = 0;

    if ((pid = waitpid(c_pid, &status, 0)) < 0)
        return (84);
    if (WIFSIGNALED(status)) {
        value = WTERMSIG(status);
        if (value == 11)
            my_printf("%e", "Segmentation fault");
        if (value == 8)
            my_printf("%e", "Floating exception");
        if (value == 6)
            my_printf("%e", "Abort");
        if (WCOREDUMP(status))
            my_printf("%e", " (core dumped)");
        my_printf("%e", "\n");
    }
    return (0);
}

static char *find_path(char *path, char *command, int *i)
{
    char *temp = my_strdup(path);
    for (int j = 0; temp[j]; j++) {
        if (temp[j] == ':') {
            for ((*i) = 0; temp[(*i)] != ':'; (*i)++);
            temp[(*i)] = '\0';
            break;
        }
    }
    my_strcat(&temp, "/");
    my_strcat(&temp, command);
    return (temp);
}

char *get_path(list_t *list, data_t *data)
{
    char *temp = NULL;
    char *path = NULL;

    if (access(list->command[0], F_OK) == 0)
        return (list->command[0]);
    if (list->command[0][0] == '.' && list->command[0][1] == '/')
        return (list->command[0]);
    path = path_env(data->env, "PATH");
    if (path == NULL)
        return (NULL);
    for (int i = 0; path[0]; path += i + 1) {
        temp = find_path(path, list->command[0], &i);
        if (access(temp, F_OK) == 0)
            break;
        else
            free(temp);
    }
    return ((my_strlen(path) == 0) ? NULL : temp);
}

int exec_bin(list_t *list, data_t *data)
{
    pid_t c_pid = 0;
    data->path = get_path(list, data);

    if (data->path == NULL) {
        error_nf(list->command[0]);
        return (84);
    }
    if ((c_pid = fork()) == 0) {
        execve(data->path, list->command, data->env);
        my_printf("%e: %e.", data->path, strerror(errno));
        if (my_strcmp(strerror(errno), "Exec format error") == 0)
            my_printf("%e", " Wrong Architecture.");
        my_printf("%e", "\n");
        exit(84);
    } else if (c_pid > 0) {
        return (signal_parent(c_pid));
    } else {
        my_printf("%e: %e.\n", "fork", strerror(errno));
        return (84);
    }
}