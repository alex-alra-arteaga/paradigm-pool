/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Step 3 Day 4 AM Paradigm pool
*/

#include "../include/common.h"
#include "../include/concat.h"


void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    *res = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        (*res)[i] = malloc(sizeof(int) * (width));
        for (int j = 0; j < width; j++) {
            (*res)[i][j] = array[j + (i * width)];
        }
    }
}

// Free a 2D array created by your array_1d_to_2d function.
void array_2d_free(int **array, size_t height, size_t width)
{
    for (int i = 0; i < height; i++) {
        free(array[i]);
    }
    free(array);
}
