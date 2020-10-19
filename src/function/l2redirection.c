/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** double redirection on the left
*/
#include "struct.h"
#include "core.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

static void write_in_temp(char *str, list_t *elem, data_t *data)
{
    int cpy = dup(1);
    char *tkt = "/tmp/double_redirection.tmp";
    int fd = open(tkt, O_CREAT | O_WRONLY | O_TRUNC,
        S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    dup2(fd, 1);
    close(fd);
    my_printf("%s", str);
    free(elem->next->command[0]);
    elem->next->command[0] = my_strdup(tkt);
    dup2(cpy, 1);
    cpy = dup(0);
    fd = open(elem->next->command[0], O_RDONLY);
    dup2(fd, 0);
    close(fd);
    main_core(data, elem);
    dup2(cpy, 0);
}

int my_l2redirection(list_t *elem, data_t *data)
{
    char *new = NULL;
    char *str = NULL;
    size_t oui = 0;
    char *res = NULL;

    if (elem->next->command == NULL) {
        my_printf("%e\n", "Missing name for redirect.");
        return (1);
    }
    res = my_strdup(elem->next->command[0]);
    my_strcat(&res, "\n");
    do {
        my_printf("? ");
        getline(&str, &oui, stdin);
        my_strcat(&new, str);
    } while (my_strcmp(str, res) != 0);
    write_in_temp(new, elem, data);
    free(res);
    free(str);
    free(new);
    return (1);
}