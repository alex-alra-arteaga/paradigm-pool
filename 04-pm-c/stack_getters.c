/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises stack manipulation
*/

#include "include/common.h"
#include "include/stack.h"

unsigned int stack_get_size(stack_t *stack)
{
    return list_get_size(stack);
}

bool stack_is_empty(stack_t *stack)
{
    return list_is_empty(stack);
}

void *stack_top(stack_t *stack)
{
    return list_get_elem_at_front(stack);
}
