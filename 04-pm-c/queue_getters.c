/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises queue manipulation
*/

#include "include/common.h"
#include "include/queue.h"

void *queue_front(queue_t *queue)
{
    return list_get_elem_at_front(queue);
}

unsigned int queue_get_size(queue_t *queue)
{
    return list_get_size(queue);
}

bool queue_is_empty(queue_t *queue)
{
    return list_is_empty(queue);
}
