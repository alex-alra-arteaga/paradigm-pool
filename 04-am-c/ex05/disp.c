/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Step 5 Day 4 AM Paradigm pool
*/

#include "../include/common.h"

void disp_int_array(const int *array, size_t nmemb)
{
    for (int i = 0; i < nmemb; i++) {
        printf("%d\n", array[i]);
    }
}

void disp_array
(const void *array, size_t nm, size_t s, void (*p)(const void *))
{
    const char *arr = (const char *)array;

    for (size_t i = 0; i < nm; i++) {
        p(arr + i * s);
    }
}
