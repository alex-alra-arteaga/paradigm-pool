/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises generic linked list
*/

#include "include/common.h"
#include "include/list.h"

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *tmp;

    if (new_node == NULL)
        return false;
    tmp = *front_ptr;
    new_node->next = tmp;
    new_node->value = elem;
    *front_ptr = new_node;
    return true;
}

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *tmp = *front_ptr;

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = NULL;
    if (tmp == NULL) {
        *front_ptr = new_node;
        return true;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
    return true;
}

bool list_add_elem_at_position
(list_t **front_ptr, void *elem, unsigned int pos)
{
    list_t *new_node = malloc(sizeof(list_t));
    list_t *tmp = *front_ptr;

    if (new_node == NULL)
        return false;
    for (int i = 1; i < pos && tmp != NULL; i++) {
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        free(new_node);
        return false;
    }
    new_node->value = elem;
    new_node->next = tmp->next;
    tmp->next = new_node;
    return true;
}
