/*
** EPITECH PROJECT, 2020
** CPE_getnextline_2019
** File description:
** get_next_line
*/
#include "get_next_line.h"

char *my_strcatalloc(char *s1, char *s2, base *use)
{
    char *str = malloc(my_strlen(s1) + my_strlen(s2) + 1);
    int i = 0;
    int j = 0;

    if (s2[0] == '\n' && s2[1] <= 31) {
        use->buffer = NULL;
        return (s1);
    }
    if (str == NULL)
        return (NULL);
    for (; s1[i]; i++)
        str[i] = s1[i];
    for (; s2[j]; i++, j++)
        str[i] = s2[j];
    str[i] = '\0';
    free(s1);
    free(s2);
    return (str);
}

void too_many(base *use, sbase *suse, int nbr)
{
    int i = 0;
    int j = 0;
    int max = (my_strlen(use->buffer) - nbr) + 1;

    suse->sbuff = malloc(max);
    if (use->buffer[0] == '\n' && use->buffer[1] <= 31) {
        use->buffer = NULL;
        return;
    }
    if (suse->sbuff == NULL) {
        use->buffer = NULL;
        return;
    }
    for (; use->buffer[i] != '\n'; i++);
    for (i += 1; use->buffer[i]; i++, j++)
        suse->sbuff[j] = use->buffer[i];
    suse->sbuff[j] = '\0';
    use->buffer[nbr] = '\0';
    return;
}

char *not_enough(base *use, sbase *suse, int fd)
{
    while (1) {
        use->next = malloc(READ_SIZE + 1);
        if (use->next == NULL)
            return (NULL);
        if (read(fd, use->next, READ_SIZE) == 0) {
            if (use->next == NULL)
                return (NULL);
            else
                return (use->next);
        }
        use->next[READ_SIZE] = '\0';
        use->buffer = my_strcatalloc(use->buffer, use->next, use);
        for (int i = 0; use->buffer[i]; i++)
            if (use->buffer[i] == '\n' || use->buffer[i] == '\0') {
                too_many(use, suse, i);
                return (use->buffer);
            }
    }
}

char *gnl(sbase *suse)
{
    if (suse->nbr_time != 0 || suse->sbuff == NULL)
        return (NULL);
    else {
        suse->nbr_time++;
        for (int i = 0; suse->sbuff[i]; i++);
        return (suse->sbuff);
    }
}

char *get_next_line(int fd)
{
    base use;
    static sbase suse;
    int rd = 0;
    use.buffer = malloc(READ_SIZE+1);
    rd = read(fd, use.buffer, READ_SIZE);

    if (rd == 0)
        return (gnl(&suse));
    if (rd < READ_SIZE)
        use.buffer[rd] = '\0';
    else
        use.buffer[READ_SIZE] = '\0';
    use.buffer = (suse.sbuff != NULL)
    ? my_strcatalloc(suse.sbuff, use.buffer, &use) : use.buffer;
    for (int i = 0; use.buffer[i]; i++)
        if (use.buffer[i] == '\n') {
            too_many(&use, &suse, i);
            return (use.buffer);
        }
    return (not_enough(&use, &suse, fd));
}