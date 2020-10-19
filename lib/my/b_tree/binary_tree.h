/*
** EPITECH PROJECT, 2020
** PSU_minishell2_2019
** File description:
** binary_tree
*/

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

typedef struct use_s {
    char *command;
    char *path;
    char **argument;
} use_t;

typedef struct b_node_s {
    char *command;
    char *path;
    char **argument;
    struct b_node_s *left;
    struct b_node_s *right;
} b_node_t;

b_node_t *new_node(use_t use);
void print_postorder(b_node_t *node);
void print_inorder(b_node_t *node);
void print_preorder(b_node_t *node);

#endif /* !BINARY_TREE_H_ */
