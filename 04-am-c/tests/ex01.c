/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Tests for ex01
*/

#include <criterion/criterion.h>
#include "../include/common.h"

Test(mul_div_long, test_case_1)
{
    int a = 13;
    int b = 4;
    int mul;
    int div;
    mul_div_long(a, b, &mul,&div);

    cr_assert_eq(mul, 52, "Expected: 52, Got: %d", mul);
    cr_assert_eq(div, 3, "Expected: 3, Got: %d", div);
}

Test(mul_div_short, test_case_1)
{
    int a = 12;
    int b = 0;
    int mul_res = a;
    int div_res = b;

    mul_div_short(&mul_res, &div_res);

    cr_assert_eq(mul_res, 0, "Expected: 0, Got: %d", mul_res);
    cr_assert_eq(div_res, 42, "Expected: 42, Got %d", div_res);
}