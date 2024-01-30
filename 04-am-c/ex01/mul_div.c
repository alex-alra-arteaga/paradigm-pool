/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Step 1 Day 4 AM Paradigm pool
*/
void mul_div_long(int a, int b, int *mul, int *div) {
    *mul = a * b;
    if (b != 0) {
        *div = a / b;
    } else {
        *div = 42;
    }
}

void mul_div_short(int *a, int *b) {
    int tmp_a = *a;

    *a = *a * *b;
    if (*b == 0) {
        *b = 42;
    } else {
        *b = tmp_a / *b;
    }
}
