/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises linked list
*/

#include "include/common.h"
#include "include/int_list.h"



void int_list_clear(int_list_t **front_ptr)
{
    while (*front_ptr != NULL) {
        int_list_del_elem_at_front(front_ptr);
    }
}

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *tmp = *front_ptr;

    if (tmp == NULL)
        return false;
    *front_ptr = tmp->next;
    free(tmp);
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    int_list_t *tmp;

    if (int_list_is_empty(*front_ptr))
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

bool int_list_del_elem_at_position
(int_list_t **front_ptr, unsigned int position)
{
    int_list_t *tmp;
    int_list_t *to_delete;

    if (int_list_is_empty(*front_ptr))
        return false;
    if (position == 0) {
        free(*front_ptr);
        *front_ptr = NULL;
        return true;
    }
    tmp = *front_ptr;
    for (unsigned int i = 0; i < position - 1 && tmp != NULL; i++)
        tmp = tmp->next;
    if (tmp == NULL || tmp->next == NULL)
        return false;
    to_delete = tmp->next;
    tmp->next = to_delete->next;
    free(to_delete);
    return true;
}
