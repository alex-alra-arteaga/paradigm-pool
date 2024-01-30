/*
** EPITECH PROJECT, 2024
** Paradigms Seminar
** File description:
** Exercise 07
*/

#pragma once

#include "list.h"

/* Types */

typedef struct pair {
    void *key;
    void *value;
} pair_t;

typedef list_t map_t;

typedef int (*key_comparator_t)(const void *first_key, const void *second_key);

/* Informations */

unsigned int map_get_size(map_t *map);
bool map_is_empty(map_t *map);

/* Modification */

bool map_add_elem(map_t **m_ptr, void *key, void *v, key_comparator_t key_cmp);
bool map_del_elem(map_t **map_ptr, void *key, key_comparator_t key_cmp);
void map_clear(map_t **map_ptr);

/* Access */

void *map_get_elem(map_t *map, void *key, key_comparator_t key_cmp);
