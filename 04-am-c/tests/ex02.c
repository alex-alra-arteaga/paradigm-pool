/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Tests for ex02
*/

#include <criterion/criterion.h>
#include "../include/common.h"
#include "../include/concat.h"

Test(concat_strings, test_case_1)
{
    char str1[] = "I find your lack of faith... ";
    char str2[] = "disturbing.";
    char *res = NULL;
    concat_strings(str1, str2, &res);

    cr_assert_eq(strcmp(res, "I find your lack of faith... disturbing."), 0, "Expected: 'I find your lack of faith... disturbing.', Got: %s", res);
    free(res);
}

Test(concat_struct, test_case1)
{
    char str1[] = "These aren't the Droids ";
    char str2[] = "you're looking for.";

    concat_t str = {
        .str1 = str1,
        .str2 = str2,
        .res = NULL
    };
    concat_struct(&str);

    cr_assert_eq(strcmp(str.res, "These aren't the Droids you're looking for."), 0, "Expected: 'These aren't the Droids you're looking for.', Got: %s", str.res);
    free(str.res);
}