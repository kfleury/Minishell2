/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

/* lib */

int my_strlen(char const *str);
void my_putstr(char *str);
void my_putchar(char c);
int my_strlen(char const *str);
void my_swap(char *a, char *b);
int my_str_isnum(char const *str);
char *my_revstr(char *str);
int my_getnbr(char const *str);
void my_strcat(char **dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
void my_putnbr(int nbr);
char *my_strcpy(char *dest, char const *src);
int *my_strcat_int(int *dest, int const *src, int size_dest, int size_src);
char *convert_in_bit(char str);
char **my_split(char *str, char const *delim);
int my_putnbr_base(int nbr, char const *base);
char *my_realloc(char *str, int size);
char *get_next_line(int fd);
int *my_revstrint(int *str, int len);
int *decToBinary(int n);
int my_intlen(int o);
char *my_itoa(int o);
int *dec_to_binary(int n);
void my_memcpy(void *dest, void *src, int size);
int tablen(char **tab);
void tabcpy(char ***dest, char **src, int length);
void tabprint(char **tab);
char *my_join(char **tab, char c, bool free_tab);
char *char_to_str(char c);
void my_restr(char **str, int size);
void refactor(char **str, int nbr);
int is_char(char c);
int len_words(char **str);
void my_puterror(char *str);
int my_str_isnum(char const *str);
void remove_in_str(char **str, char c);
void add_in_str(char **str, char c, int *nbr, int max);
char *clean_str(char *str, char const *delim);
int is_delim(char c, char const *delim);
char *my_strstr(const char *s1, const char *s2);

/* linked list */

typedef struct node_s {
    char **command;
    const char *flag;
    struct node_s *next;
} list_t;

list_t *my_create_list();
list_t *add_list(list_t data, list_t *list);

/* my_printf */

typedef struct norm {
    int nbr;
    int i;
    char *fmt;
    char *flag;
}bases;

typedef struct {
    void (*tpf)(char *);
    char flag;
}tabpfchar_s;

typedef struct {
    void (*tpf)(char);
    char flag;
}tabpfchar;

typedef struct {
    void (*tpf)(int);
    char flag;
}tabpfint;

typedef struct {
    void (*tpf)(unsigned int);
    char flag;
}tabpfu_int;

typedef struct {
    void (*tpf)(bases *);
    char flag;
}tabpfbases;

void base01(int nbr);
void basehex_maj(int nbr);
void basehex(int nbr);
void baseoct(int nbr);
void flag_p(int nbr);
void my_putnbr_unsigned(unsigned int nbr);
int pointeur(char *str);
void ascii(char *str);
void percent_percent(bases *use);
int my_printf(char *fmt, ...);
int is_it_a_flag(char f, bases *use, char *fmt);
int which_flag(char fmt, bases *use);
void writing(bases *use, va_list ap, int k);
void writing_sequel(va_list ap, int k);
int my_strncmp(const char *s1, const char *s2, int n);
char **my_realloc_td(char **tab, int new_size);

static const tabpfchar_s tabcs[] = {
    {my_putstr, 's'},
    {my_puterror, 'e'},
    {ascii, 'S'},
    {NULL, 'n'},
};

static const tabpfchar tabc[] = {
    {my_putchar, 'c'},
    {NULL, 'n'},
};

static const tabpfint tabi[] = {
    {my_putnbr, 'd'},
    {my_putnbr, 'i'},
    {baseoct, 'o'},
    {basehex, 'x'},
    {basehex_maj, 'X'},
    {base01, 'b'},
    {flag_p, 'p'},
    {NULL, 'n'},
};

static const tabpfu_int tabu[] = {
    {my_putnbr_unsigned, 'u'},
    {NULL, 'n'},
};

static const tabpfbases tabb[] = {
    {percent_percent, '%'},
    {NULL, 'n'},
};

#endif /* !MY_H_ */
