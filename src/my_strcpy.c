/*
** EPITECH PROJECT, 2020
** MY_STRCPY.C
** File description:
** copy the provided string
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
