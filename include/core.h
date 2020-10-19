/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** core.h
*/

#ifndef CORE_H
#define CORE_H

#include "struct.h"

// env function
bool is_env_exist(char **env, char *name);
char *my_strdup_mod(char const *src);
char *my_strcat_mod(char *s1, char *s2);
char *my_realloc_mod(char *s1, char *s2, int size);
void my_realloc_td_mod(char ***tab, int size, int o);

// exec function
void main_core(data_t *data, list_t *elem);
int exec_bin(list_t *list, data_t *data);
char *path_env(char **tab, char *name);
int signal_parent(pid_t c_pid);
int check_priorities(list_t *elem, data_t *data);

// flag
char *get_path(list_t *list, data_t *data);
int open_file_trunc(list_t *elem);
int open_file_append(list_t *elem);

// flag
int my_pipe(list_t *elem, data_t *data);
int my_l2redirection(list_t *elem, data_t *data);
int my_lredirection(list_t *elem, data_t *data);
int my_rredirection(list_t *elem, data_t *data);
int my_r2redirection(list_t *elem, data_t *data);

typedef struct tabptr_s {
    int (*tpf)(list_t *, data_t *);
    char *flag;
} tabptr_t;

// needed prototypes for tables of pointers for function
int my_cd(list_t *list, data_t *data);
int my_exit(list_t *list, data_t *data);
int my_setenv(list_t *list, data_t *data);
int my_unsetenv(list_t *list, data_t *data);
int my_env(list_t *list, data_t *data);

static const tabptr_t func_tab[6] = {
    {my_cd, "cd"},
    {my_exit, "exit"},
    {my_setenv, "setenv"},
    {my_unsetenv, "unsetenv"},
    {my_env, "env"},
    {NULL, NULL}
};

#endif //PSU_MINISHELL2_2019_CORE_H
