/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises linked list
*/

#include "include/common.h"
#include "include/int_list.h"

void int_list_dump(int_list_t *list)
{
    int_list_t *tmp = list;

    while (tmp != NULL) {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
}

bool int_list_is_empty(int_list_t *list)
{
    if (list == NULL)
        return (true);
    return (false);
}
