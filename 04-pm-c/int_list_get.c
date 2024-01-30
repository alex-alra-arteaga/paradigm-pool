/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises linked list
*/

#include "include/common.h"
#include "include/int_list.h"

unsigned int int_list_get_size(int_list_t *list)
{
    int_list_t *tmp = list;
    unsigned int size = 0;

    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return size;
}

int int_list_get_elem_at_front(int_list_t *list)
{
    if (int_list_is_empty(list))
        return 0;
    else
        return list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    int_list_t *curr = list;

    if (int_list_is_empty(list))
        return 0;
    while (curr->next != NULL)
        curr = curr->next;
    return curr->value;
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    int_list_t *tmp = list;

    for (int i = 0; i < position && tmp != NULL; i++)
        tmp = tmp->next;
    if (tmp == NULL)
        return 0;
    return tmp->next->value;
}
