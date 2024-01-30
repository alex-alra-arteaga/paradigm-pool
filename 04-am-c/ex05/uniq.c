/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Step 5 Day 4 AM Paradigm pool
*/

#include "../include/common.h"

void mark_duplicates(int *array, size_t nmemb, int curr, int magic_num)
{
    for (size_t j = 0; j < nmemb; j++) {
        if (curr == array[j]) {
            array[j] = magic_num;
        }
    }
}

size_t count_unique(const int *array, size_t nmemb, int magic_num)
{
    size_t unique_num = 0;

    for (size_t i = 0; i < nmemb; i++) {
        if (array[i] != magic_num) {
            unique_num++;
        }
    }
    return unique_num;
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    int magic_num = -32342132;

    for (size_t i = 0; i < nmemb; i++) {
        if (array[i] != magic_num) {
            mark_duplicates(array, nmemb, array[i], magic_num);
        }
    }
    return count_unique(array, nmemb, magic_num);
}

bool is_unique
(char *fst_arg, char *snd_arg, int (*c)(const void *, const void *))
{
    bool unique = true;

    if (c(fst_arg, snd_arg) == 0) {
        unique = false;
    }
    return unique;
}

size_t uniq_array
(void *arr, size_t nmemb, size_t size, int (*c)(const void *, const void *))
{
    char *array = (char *)arr;
    size_t unique_count = 0;
    bool unique;
    bool _break;

    for (size_t i = 0; i < nmemb; i++) {
        unique = true;
        for (size_t j = 0; j < i && unique; j++)
            unique = is_unique(array + i * size, array + j * size, c);
        if (unique && unique_count != i)
            memcpy(array + unique_count * size, array + i * size, size);
        if (unique)
            unique_count++;
    }
    return unique_count;
}
