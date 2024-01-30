/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises generic linked list
*/

#include "include/common.h"
#include "include/list.h"

bool list_is_empty(list_t *list)
{
    if (list == NULL)
        return (true);
    return (false);
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    list_t *tmp = list;

    if (val_disp == NULL)
        return;
    while (tmp != NULL) {
        val_disp(tmp->value);
        tmp = tmp->next;
    }
}
