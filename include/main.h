/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\x1B[0m"

#include "struct.h"

// set
int show_prompt(void);
void init_sh(data_t *data, char **env);
list_t *my_create_list();
int run_minishell(data_t *data);

// parsing
void handle_arg(data_t *data, char *str);

// core function
void parse_command(data_t *data);

#endif /* !MAIN_H_ */
