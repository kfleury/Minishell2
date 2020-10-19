/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** simple redirection on the right
*/
#include "core.h"
#include "struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int open_file_trunc(list_t *elem)
{
    int old_fd = 0;

    if (elem->next->command == NULL) {
        my_printf("%e\n", "Missing name for redirect.");
        return (-1);
    }
    old_fd = open(elem->next->command[0], O_CREAT | O_WRONLY | O_TRUNC,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (old_fd == -1) {
        my_printf("%e: %e.\n", elem->next->command[0], strerror(errno));
        return (-1);
    }
    return (old_fd);
}

int my_rredirection(list_t *elem, data_t *data)
{
    int cpy_fd = dup(STDOUT_FILENO);
    int old_fd = 0;

    if ((old_fd = open_file_trunc(elem)) == -1)
        return (1);
    dup2(old_fd, 1);
    close(old_fd);
    main_core(data, elem);
    dup2(cpy_fd, 1);
    return (1);
}