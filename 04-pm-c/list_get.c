/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises generic linked list
*/

#include "include/common.h"
#include "include/list.h"

void *list_get_elem_at_front(list_t *list)
{
    if (list_is_empty(list))
        return NULL;
    else
        return list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    list_t *curr = list;

    if (list_is_empty(list))
        return NULL;
    while (curr->next != NULL)
        curr = curr->next;
    return curr->value;
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    list_t *tmp = list;

    for (int i = 0; i < position && tmp != NULL; i++)
        tmp = tmp->next;
    if (tmp == NULL)
        return NULL;
    return tmp->next->value;
}

unsigned int list_get_size(list_t *list)
{
    list_t *tmp = list;
    unsigned int size = 0;

    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return size;
}
