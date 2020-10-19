/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** pipe
*/
#include "struct.h"
#include "core.h"
#include "error.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>

static void redirect(int old_fd, int new_fd)
{
    if (old_fd != new_fd) {
        if (dup2(old_fd, new_fd) != -1)
            close(old_fd);
        else
            report_error_and_exit("dup2");
    }
}

static void make_fork(list_t *elem, int in_fd, data_t *data, int *fd)
{
    pid_t c_pid = fork();

    switch (c_pid) {
        case -1:
            report_error_and_exit("fork");
            break;
        case 0:
            close(fd[0]);
            redirect(in_fd, STDIN_FILENO);
            redirect(fd[1], STDOUT_FILENO);
            execve(data->path, elem->command, data->env);
            report_error_and_exit(elem->command[0]);
            break;
        default:
            close(fd[1]);
            close(in_fd);
            signal_parent(in_fd);
            return;
    }
}

static void last_fork(list_t *elem, data_t *data)
{
    pid_t c_pid = 0;

    if (elem->next != NULL)
        c_pid = fork();
    switch (c_pid) {
        case -1:
            report_error_and_exit("fork");
            break;
        case 0:
            execve(data->path, elem->command, data->env);
            report_error_and_exit(elem->command[0]);
            break;
        default:
            signal_parent(c_pid);
            return;
    }
}

static int exec_pipeline(list_t *elem, int in_fd, data_t *data)
{
    int fd[2];
    static int nbr_time = 0;

    if ((data->path = get_path(elem, data)) == NULL)
        error_nf(elem->command[0]);
    if (my_strcmp(elem->flag, "NULL") == 0
        || my_strcmp(elem->flag, ";") == 0) {
        redirect(in_fd, STDIN_FILENO);
        last_fork(elem, data);
        return (nbr_time);
    } else if (my_strcmp(elem->flag, "|") != 0) {
        redirect(in_fd, STDIN_FILENO);
        check_priorities(elem, data);
        return (nbr_time+1);
    } else {
        if (pipe(fd) == -1)
            report_error_and_exit("pipe");
        make_fork(elem, in_fd, data, fd);
        nbr_time++;
        return (exec_pipeline(elem->next, fd[0], data));
    }
}

int my_pipe(list_t *elem, data_t *data)
{
    list_t *temp = elem;
    int ret = 0;
    int ret2 = 0;

    for (; temp; temp = temp->next) {
        if (my_strcmp(temp->flag, ">") == 0
            && my_strcmp(temp->command[0], "wc") == 0)
            ret2 = open_file_trunc(temp);
        else if (my_strcmp(temp->flag, ">>") == 0
                && my_strcmp(temp->command[0], "wc") == 0)
            ret2 = open_file_append(temp);
        if (ret2 == -1)
            return (ret);
        else if (my_strcmp(temp->flag, "|") != 0)
            break;
    }
    ret = exec_pipeline(elem, STDIN_FILENO, data);
    return (ret);
}