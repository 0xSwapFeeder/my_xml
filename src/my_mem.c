/*
** EPITECH PROJECT, 2020
** my_mem.c
** File description:
** header for my_mem.c
*/

#include <stdlib.h>

void my_memcpy(void *dest, void *src, size_t size)
{
    char *str_dest = (char *)dest;
    char *str_src = (char *)src;

    for (int i = 0; i < size; i++)
        str_dest[i] = str_src[i];
}

void *mem_expand(void *data, size_t actual_size, size_t newsize)
{
    void *new = malloc(newsize);

    if (new) {
        if (!data)
            return new;
        my_memcpy(new, data, actual_size);
        free(data);
    }
    return new;
}