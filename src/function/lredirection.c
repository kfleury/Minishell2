/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** simple redirection on the left
*/
#include "core.h"
#include "struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int my_lredirection(list_t *elem, data_t *data)
{
    int cpy_fd = dup(0);
    int old_fd = 0;

    if (elem->next->command == NULL) {
        my_printf("%e\n", "Missing name for redirect.");
        return (1);
    }
    old_fd = open(elem->next->command[0], O_RDONLY);
    if (old_fd == -1) {
        my_printf("%e: %e.\n", elem->next->command[0], strerror(errno));
        return (1);
    }
    dup2(old_fd, 0);
    close(old_fd);
    main_core(data, elem);
    dup2(cpy_fd, 0);
    return (1);
}