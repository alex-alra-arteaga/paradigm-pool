/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Step 2 Day 4 AM Paradigm pool
*/

#include "../include/common.h"
#include "../include/concat.h"

void concat_strings(const char *str1, const char *str2, char **res)
{
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);

    *res = malloc(str1_len + str2_len + 1);
    for (int i = 0; str1[i]; i++) {
        (*res)[i] = str1[i];
    }
    for (int i = 0; str2[i]; i++) {
        (*res)[str1_len + i] = str2[i];
    }
    (*res)[str1_len + str2_len] = '\0';
}

void concat_struct(concat_t *str)
{
    int str1_len = strlen(str->str1);
    int str2_len = strlen(str->str2);

    str->res = malloc(str1_len + str2_len + 1);
    for (int i = 0; str->str1[i]; i++) {
        str->res[i] = str->str1[i];
    }
    for (int i = 0; str->str2[i]; i++) {
        str->res[str1_len + i] = str->str2[i];
    }
    str->res[str1_len + str2_len] = '\0';
}
