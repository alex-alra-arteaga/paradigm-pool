/*
** EPITECH PROJECT, 2023
** mini_sprintf.c
** File description:
** Mini mini_sprintf implementation
*/

#include "../include/common.h"

long long my_strtoull(const char *str)
{
    long long result = 0;
    int sign = 1;
    int i = 0;

    while (is_whitespace(str[i]))
        i++;
    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return sign * result;
}
