/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** Mini printf implementation
*/

#include "../include/common.h"

char *remove_spaces(char *input)
{
    int i = 0;
    int j = 0;

    while (input[i]) {
        if (!is_whitespace((unsigned char)input[i])) {
            input[j] = input[i];
            j++;
        }
        i++;
    }
    input[j] = '\0';
    return input;
}

char *remove_character(char *input, char c)
{
    int i = 0;
    int j = 0;

    while (input[i]) {
        if (input[i] != c) {
            input[j] = input[i];
            j++;
        }
        i++;
    }
    input[j] = '\0';
    return input;
}
