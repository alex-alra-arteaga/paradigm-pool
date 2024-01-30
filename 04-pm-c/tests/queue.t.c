/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Tests for linked lists adding
*/

#include <criterion/criterion.h>
#include "../include/common.h"
#include "../include/queue.h"

Test(queue, test_case_1)
{
    queue_t *queue = NULL;
    int i = 5;
    int j = 4;
    int *data = NULL;
    queue_push(&queue, &i);
    queue_push(&queue, &j);
    data = (int *)queue_front(queue);
    printf("%d\n", *data);
    queue_clear(&queue);
    return (0);
}