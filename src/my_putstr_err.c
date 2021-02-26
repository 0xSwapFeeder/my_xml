/*
** EPITECH PROJECT, 2020
** my_putstr_err.c
** File description:
** my_putstr_err.c
*/

#include <unistd.h>

void my_putstr_err(char *str)
{
    for (int i = 0; str[i]; i++)
        write(2, str + i, 1);
}