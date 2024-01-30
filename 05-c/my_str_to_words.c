/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** my_str_to_array.c
*/

#include "string.h"
#include "common.h"

int count_lines(char *buff, char c)
{
    int i = 0;
    int lines = 0;

    while (buff[i] != '\0') {
        if (buff[i] == c)
            lines++;
        i++;
    }
    return lines + 1;
}

int line_length(char *buff, int i)
{
    int count = 0;

    while (buff[i] > ' ') {
        i++;
        count++;
    }
    return count;
}

void fill_array(char **array, char *buff, char c, int lines)
{
    int b;
    int i = 0;

    for (int a = 0; a < lines; a++) {
        b = 0;
        array[a] = malloc(sizeof(char) * (line_length(buff, i) + 1));
        while (buff[i] != c && buff[i] != '\0') {
            array[a][b] = buff[i];
            i++;
            b++;
        }
        array[a][b] = '\0';
        i++;
    }
    array[lines] = NULL;
}

char **my_str_to_array(char *buff, char c)
{
    int lines = count_lines(buff, c);
    char **array = malloc(sizeof(char *) * (lines + 1));

    if (array == NULL)
        return NULL;
    fill_array(array, buff, c, lines);
    return array;
}
