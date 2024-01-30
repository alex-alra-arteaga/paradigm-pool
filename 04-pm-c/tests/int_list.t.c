/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Tests for int linked lists adding
*/

#include <criterion/criterion.h>
#include "../include/common.h"
#include "../include/int_list.h"

Test(int_list_beginning, test_case_1)
{
    int_list_t *list_head = NULL;

    cr_assert_eq(int_list_is_empty(list_head), true, "Expected empty list, Got: %d", int_list_is_empty(list_head));
    int_list_add_elem_at_back(&list_head, 1);
    int_list_add_elem_at_back(&list_head, 2);
    cr_assert_eq(int_list_get_size(list_head), 2, "Expected 2 elements in the list, Got: %d", int_list_get_size(list_head));
    int_list_dump(list_head);
    int_list_clear(&list_head);
    cr_assert_eq(int_list_get_size(list_head), 0, "Expected 0 elements in the list, Got: %d", int_list_get_size(list_head));
}

Test(int_list_add, test_case_1)
{
    int_list_t *list_head = NULL;
    int_list_add_elem_at_front(&list_head, 1);
    int_list_add_elem_at_front(&list_head, 2);
    int_list_add_elem_at_position(&list_head, 3, 1);
    cr_assert_eq(int_list_get_size(list_head), 3, "Expected 3 elements in the list, Got: %d", int_list_get_size(list_head));
    int_list_dump(list_head);
    int_list_clear(&list_head);
}

Test(int_list_almost_end, test_case_1)
{
    int_list_t * list_head = NULL ;
    int_list_add_elem_at_front(&list_head, 1);
    int_list_add_elem_at_front(&list_head, 2);
    int_list_add_elem_at_position(&list_head, 3, 1);
    cr_assert_eq(int_list_get_size(list_head), 3, "Expected 3 elements in the list, Got: %d", int_list_get_size(list_head));
    cr_assert_eq(int_list_get_elem_at_front(list_head), 2, "Expected 2 as first element, Got: %d", int_list_get_elem_at_front(list_head));
    cr_assert_eq(int_list_get_elem_at_back(list_head), 1, "Expected 1 as last element, Got: %d", int_list_get_elem_at_back(list_head));
    int_list_clear(&list_head);
}

Test(int_list_end, test_case_1)
{
    int_list_t *list_head = NULL;
    int_list_add_elem_at_back(&list_head, 1);
    int_list_add_elem_at_back(&list_head, 2);
    int_list_add_elem_at_back(&list_head, 3);
    cr_assert_eq(int_list_get_size(list_head), 3, "Expected 3 elements in the list, Got: %d", int_list_get_size(list_head));
    int_list_del_elem_at_front(&list_head);
    int_list_dump(list_head);
    int_list_clear(&list_head);
}