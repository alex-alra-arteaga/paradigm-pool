/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises generic linked list
*/

#include "include/common.h"
#include "include/map.h"

unsigned int map_get_size(map_t *map)
{
    return list_get_size(map);
}

bool map_is_empty(map_t *map)
{
    return list_is_empty(map);
}

void *map_get_elem(map_t *map, void *key, key_comparator_t key_cmp)
{
    map_t *tmp = map;

    if (tmp == NULL)
        return NULL;
    while (tmp->next != NULL) {
        if (key_cmp(((pair_t *)(tmp->value))->key, key) == 0) {
            return ((pair_t *)(tmp->value))->value;
        }
        tmp = tmp->next;
    }
    return NULL;
}
