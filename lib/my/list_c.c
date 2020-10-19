/*
** EPITECH PROJECT, 2019
** function
** File description:
** for chained list
*/
#include "my.h"

int count_link(list_t *head)
{
    int cmp = 0;
    list_t *current_node = head;

    while (current_node != NULL) {
        cmp++;
        current_node = current_node->next;
    }
    return (cmp);
}
