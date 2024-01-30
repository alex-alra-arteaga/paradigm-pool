/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Step 5 Day 4 AM Paradigm pool
*/

#include "../include/common.h"

void my_swap_void(void *a, void *b, size_t size)
{
    char temp[size];

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

bool is_ascending_sorted(int *array)
{
    for (int i = 0; array[i + 1]; i++) {
        if (array[i] > array[i + 1]) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

bool is_ascending_sorted_void
(void *arr, size_t nmemb, size_t s, int (*compar)(const void *, const void *))
{
    char *array = (char *)arr;

    for (size_t i = 0; i < nmemb - 1; i++) {
        if (compar(array + i * s, array + (i + 1) * s) > 0) {
            return false;
        }
    }
    return true;
}

void sort_int_array(int *arr, size_t nmemb)
{
    int a;
    int b;
    int c;

    if (nmemb <= 1)
        return;
    for (size_t i = 0; i < nmemb - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            c = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = c;
        }
    }
    sort_int_array(arr, nmemb - 1);
}

void sort_array
(void *arr, size_t nmemb, size_t s, int (*compar)(const void *, const void *))
{
    char *array = (char *)arr;
    char temp[s];

    if (nmemb <= 1)
        return;
    for (size_t i = 0; i < nmemb - 1; i++) {
        if (compar(array + i * s, array + (i + 1) * s) > 0) {
            my_swap_void(array + i * s, array + (i + 1) * s, s);
        }
    }
    sort_array(arr, nmemb - 1, s, compar);
}
