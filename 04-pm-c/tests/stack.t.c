/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Tests for stack manipulation
*/

#include <criterion/criterion.h>
#include "../include/common.h"
#include "../include/stack.h"

Test(stack, test_case_1)
{
    stack_t *stack = NULL;
    int i = 5;
    int j = 4;
    int *data = NULL;

    stack_push(&stack,&i);
    stack_push(&stack,&j);
    data = (int *)stack_top(stack);
    printf("%d\n", *data);
    stack_clear(&stack);
    return (0);
}