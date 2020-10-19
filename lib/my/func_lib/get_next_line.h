/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** getnextline
*/

#ifndef GETNEXTLINE_H_
#define GETNEXTLINE_H_

#define READ_SIZE (2)

#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

typedef struct {
    char *buffer;
    char *next;
    int len;
}base;

typedef struct {
    char *sbuff;
    int nbr_time;
}sbase;

static inline int my_strlen(char *str) {
    int i = 0;

    for (i = 0; str[i]; i++);
    return (i);
}

char *get_next_line(int fd);

#endif /* !GETNEXTLINE_H_ */
