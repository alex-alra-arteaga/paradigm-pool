/*
** EPITECH PROJECT, 2022
** my_strdup.c
** File description:
** allocates memory and copies the string given as argument
*/

#include <stdlib.h>
#include "../include/common.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *string = malloc((len +1) * sizeof(char));

    if (src[0] == '\0')
        return (NULL);
    string[0] = '\0';
    while (src[i]) {
        string[i] = src[i];
        i++;
    }
    string[i] = '\0';
    return (string);
}
