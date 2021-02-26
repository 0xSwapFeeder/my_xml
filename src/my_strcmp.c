/*
** EPITECH PROJECT, 2020
** String Compare
** File description:
** r
*/

int my_strcmp(char const *s1, char const *s2)
{
    int cmp = 0;
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);
    if (s1[i] > s2[i])
        cmp = s1[i] - s2[i];
    if (s1[i] < s2[i])
        cmp = (s2[i] - s1[i]) * (-1);
    return (cmp);
}
