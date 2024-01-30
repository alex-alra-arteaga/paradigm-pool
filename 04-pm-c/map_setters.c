/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercises generic linked list
*/

#include "include/common.h"
#include "include/map.h"

map_t *create_new_map_elem(void *key, void *value)
{
    pair_t *pair_value = malloc(sizeof(pair_t));
    map_t *new_elem = malloc(sizeof(map_t));

    if (new_elem == NULL || pair_value == NULL) {
        free(pair_value);
        free(new_elem);
        return NULL;
    }
    pair_value->key = key;
    pair_value->value = value;
    new_elem->value = pair_value;
    new_elem->next = NULL;
    return new_elem;
}

bool map_add_elem
(map_t **map_ptr, void *key, void *value, key_comparator_t key_cmp)
{
    map_t *new_elem = create_new_map_elem(key, value);
    map_t *tmp = *map_ptr;

    if (new_elem == NULL)
        return false;
    if (tmp == NULL) {
        *map_ptr = new_elem;
        return true;
    }
    while (tmp->next != NULL) {
        if (key_cmp(((pair_t *)(tmp->value))->key, key) == 0) {
            free(tmp->value);
            tmp->value = new_elem->value;
            return true;
        }
        tmp = tmp->next;
    }
    tmp->next = new_elem;
    return true;
}

bool map_del_elem(map_t **map_ptr, void *key, key_comparator_t key_cmp)
{
    map_t *tmp = *map_ptr;
    pair_t *pair;

    if (tmp == NULL)
        return false;
    while (tmp->next != NULL) {
        pair = (pair_t *)(tmp->value);
        if ((key_cmp(pair->key, key) == 0) && (pair->value == NULL))
            return false;
        if (key_cmp(pair->key, key) == 0) {
            free(tmp->value);
            tmp->value = NULL;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

void map_clear(map_t **map_ptr)
{
    map_t *tmp;
    pair_t *pair;

    while (*map_ptr != NULL) {
        tmp = *map_ptr;
        *map_ptr = (*map_ptr)->next;
        pair = (pair_t *)(tmp->value);
        if (pair != NULL) {
            free(pair);
        }
        free(tmp);
    }
}
