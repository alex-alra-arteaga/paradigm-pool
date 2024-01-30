/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises generic linked list
*/

#include "include/common.h"
#include "include/list.h"

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *tmp = *front_ptr;

    if (tmp == NULL)
        return false;
    *front_ptr = tmp->next;
    free(tmp);
    return true;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    list_t *tmp;

    if (list_is_empty(*front_ptr))
        return false;
    if ((*front_ptr)->next == NULL) {
        free(*front_ptr);
        *front_ptr = NULL;
        return true;
    }
    tmp = *front_ptr;
    while (tmp->next->next != NULL)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;
    return true;
}

bool list_del_elem_at_position(list_t **front_ptr, unsigned int position)
{
    list_t *tmp;
    list_t *to_delete;

    if (list_is_empty(*front_ptr))
        return false;
    if (position == 0) {
        to_delete = *front_ptr;
        *front_ptr = (*front_ptr)->next;
        free(to_delete);
        return true;
    }
    tmp = *front_ptr;
    for (unsigned int i = 0; i < position - 1 && tmp->next != NULL; i++)
        tmp = tmp->next;
    if (tmp == NULL || tmp->next == NULL)
        return false;
    to_delete = tmp->next;
    tmp->next = to_delete->next;
    free(to_delete);
    return true;
}

void list_clear(list_t **front)
{
    while (*front != NULL) {
        list_del_elem_at_front(front);
    }
}
