/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises linked list
*/

#include "include/common.h"
#include "include/int_list.h"

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    int_list_t *new_node = malloc(sizeof(int_list_t));
    int_list_t *tmp = *front_ptr;

    if (new_node == NULL)
        return false;
    new_node->value = elem;
    new_node->next = NULL;
    if (*front_ptr == NULL) {
        *front_ptr = new_node;
        return (true);
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new_node;
    return true;
}

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *new_node = malloc(sizeof(int_list_t));
    int_list_t *tmp;

    if (new_node == NULL)
        return (false);
    tmp = *front_ptr;
    new_node->next = tmp;
    new_node->value = elem;
    *front_ptr = new_node;
    return true;
}

// int in the loop starts at 1 cause the tests positions is 1 when it is [0]
bool int_list_add_elem_at_position
(int_list_t **front_ptr, int elem, unsigned int position)
{
    int_list_t *new_node = malloc(sizeof(int_list_t));
    int_list_t *tmp;

    if (new_node == NULL)
        return false;
    if (position == 0)
        return int_list_add_elem_at_front(front_ptr, elem);
    tmp = *front_ptr;
    for (int i = 1; i < position && tmp != NULL; i++) {
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
