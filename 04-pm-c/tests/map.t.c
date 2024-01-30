/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Tests for map manipulation
*/

#include <criterion/criterion.h>
#include "../include/common.h"
#include "../include/map.h"

int int_comparator(const void *first, const void *second)
{
    int val1 = *(const int *)first;
    int val2 = *(const int *)second;
    return (val1 - val2);
}

Test(map, test_case_1)
{
    map_t *map = NULL;
    int first_key = 1;
    int second_key = 2;
    int third_key = 3;
    char *first_value = "first";
    char *first_value_rw = "first_rw";
    char *second_value = "second";
    char *third_value = "third";
    char **data = NULL;
    map_add_elem(&map, &first_key, &first_value, &int_comparator);
    map_add_elem(&map, &first_key, &first_value_rw, &int_comparator);
    map_add_elem(&map, &second_key, &second_value, &int_comparator);
    map_add_elem(&map, &third_key, &third_value, &int_comparator);
    data = (char **)map_get_elem(map, &second_key, &int_comparator);
    cr_assert_eq(second_key, 2, "Expected 2, Got: %d", second_key);
    cr_assert_str_eq(*data, "second", "Expected 'second', Got: %s", *data);
    map_clear(&map);
}