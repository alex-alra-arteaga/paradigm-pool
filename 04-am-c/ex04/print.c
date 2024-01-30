/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** Step 4 Day 4 AM Paradigm pool
*/

#include "../include/common.h"
#include "../include/print.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    int length = strlen(str);
    char *reversed_str = malloc(length + 1);

    if (reversed_str == NULL) {
        return;
    }
    for (int i = 0; i < length; i++) {
        reversed_str[i] = str[length - i - 1];
    }
    reversed_str[length] = '\0';
    printf("%s\n", reversed_str);
    free(reversed_str);
}

void print_upper(const char *str)
{
    int len = strlen(str);
    char *upcased_str = malloc(len + 1);

    if (upcased_str == NULL) {
        return;
    }
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            upcased_str[i] = str[i] - 32;
        } else {
            upcased_str[i] = str[i];
        }
    }
    upcased_str[len] = '\0';
    printf("%s\n", upcased_str);
    free(upcased_str);
}

void print_42(const char *str)
{
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*f[4]) (const char *str) =
            {print_normal, print_reverse, print_upper, print_42};

    (*f[action]) (str);
}
