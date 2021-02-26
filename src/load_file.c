/*
** EPITECH PROJECT, 2020
** load_file.c
** File description:
** header for load_file.c
*/

#include <stdlib.h>
#include <ftw.h>
#include <fcntl.h>
#include <unistd.h>

char *load_file(char *filepath)
{
    char *content = NULL;
    int fd = open(filepath, O_RDONLY);
    struct stat st;


    if (stat(filepath, &st) == -1 || !S_ISREG(st.st_mode) || fd < 0)
        return NULL;
    content = malloc(sizeof(char) * (st.st_size + 1));
    content[st.st_size] = '\0';
    if (content == NULL)
        return NULL;
    if (read(fd, content, st.st_size) == -1)
        return NULL;
    close(fd);
    return content;
}