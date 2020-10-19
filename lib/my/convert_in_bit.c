/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** convert_int_bit
*/
#include "my.h"

int *dec_to_binary(int n)
{
    int *tkt = malloc(sizeof(int) * 4);
    int *binaryNum = malloc(sizeof(int) * 32);
    int i = 0;

    for (; n > 0; i++, n /= 2)
        binaryNum[i] = n % 2;
    for (int a = 0; a != 4; a++)
        tkt[a] = binaryNum[a];
    free(binaryNum);
    tkt = my_revstrint(tkt, 4);
    return (tkt);
}
