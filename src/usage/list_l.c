/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** push.c
*/
#include "struct.h"

list_t *my_create_list(void)
{
    list_t *list;

    list = NULL;
    return (list);
}

void push(list_t data, list_t **list)
{
    list_t *new_node = malloc(sizeof(list_t));

    list_t *last = *list;
    new_node->command = data.command;
    new_node->flag = data.flag;
    new_node->next = NULL;
    if (*list == NULL) {
        *list = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void print_l(list_t *head) 
{
    list_t *elem = head;

    for (; elem; elem = elem->next) {
        my_printf("command: ");
        if (elem->command)
            tabprint(elem->command);
        if (elem->flag == NULL)
            my_printf("(null)");
        else
            my_printf("flag: %s\n", elem->flag);
    }
}