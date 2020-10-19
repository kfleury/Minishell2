/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** lib_b_tree.c
*/
#include "my.h"
#include "binary_tree.h"
#include <stdlib.h>

b_node_t *new_node(use_t use)
{
    b_node_t *node = (b_node_t *)malloc(sizeof(b_node_t));

    node->command = use.command;
    node->path = use.path;
    for (int i = 0; use.argument[i]; i++)
        node->argument[i] = use.argument[i];
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void print_postorder(b_node_t *node)
{
    if (node == NULL)
        return;
    print_postorder(node->left);
    print_postorder(node->right);
    my_printf("%s %s ", node->command, node->path);
    for (int i = 0; node->argument[i]; i++)
        my_printf("%s ", node->argument[i]);
}

void print_inorder(b_node_t *node)
{
    if (node == NULL)
        return;
    print_inorder(node->left);
    my_printf("%s %s ", node->command, node->path);
    for (int i = 0; node->argument[i]; i++)
        my_printf("%s ", node->argument[i]);
    print_inorder(node->right);
}

void print_preorder(b_node_t *node)
{
    if (node == NULL)
        return;
    my_printf("%s %s ", node->command, node->path);
    for (int i = 0; node->argument[i]; i++)
        my_printf("%s ", node->argument[i]);
    print_preorder(node->left);
    print_preorder(node->right);
}
