/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Tests for ex03
*/

#include <criterion/criterion.h>
#include "../include/common.h"

Test(array_1d_to_2d, test_case_1)
{
    int **array_2d;
    const int array_1d[42] = {
            0 , 1 , 2 , 3 , 4 , 5 ,
            6 , 7 , 8 , 9 , 10 , 11 ,
            12 , 13 , 14 , 15 , 16 , 17 ,
            18 , 19 , 20 , 21 , 22 , 23 ,
            24 , 25 , 26 , 27 , 28 , 29 ,
            30 , 31 , 32 , 33 , 34 , 35 ,
            36 , 37 , 38 , 39 , 40 , 41
    };
    array_1d_to_2d(array_1d, 7, 6, &array_2d);
    printf("array_2d[%d][%d] = %d\n", 0, 0, array_2d[0][0]);
    printf("array_2d[%d][%d] = %d\n", 6, 5, array_2d[6][5]);
    printf("array_2d[%d][%d] = %d\n", 4, 4, array_2d[4][4]);
    printf("array_2d[%d][%d] = %d\n", 0, 3, array_2d[0][3]);
    printf("array_2d[%d][%d] = %d\n", 3, 0, array_2d[3][0]);
    printf("array_2d[%d][%d] = %d\n", 4, 2, array_2d[4][2]);

    cr_assert_eq(array_2d[0][0], 0, "Expected: 0, Got: %d", array_2d[0][0]);
    cr_assert_eq(array_2d[6][5], 41, "Expected: 41, Got %d", array_2d[6][5]);
    cr_assert_eq(array_2d[4][4], 28, "Expected: 28, Got %d", array_2d[4][4]);
    cr_assert_eq(array_2d[0][3], 3, "Expected: 3, Got %d", array_2d[0][3]);
    cr_assert_eq(array_2d[3][0], 18, "Expected: 18, Got %d", array_2d[3][0]);
    cr_assert_eq(array_2d[4][2], 26, "Expected: 26, Got %d", array_2d[4][2]);
}

Test(array_2d_free, test_case_1)
{
    int **array_2d;
    const int array_1d[42] = {
            0 , 1 , 2 , 3 , 4 , 5 ,
            6 , 7 , 8 , 9 , 10 , 11 ,
            12 , 13 , 14 , 15 , 16 , 17 ,
            18 , 19 , 20 , 21 , 22 , 23 ,
            24 , 25 , 26 , 27 , 28 , 29 ,
            30 , 31 , 32 , 33 , 34 , 35 ,
            36 , 37 , 38 , 39 , 40 , 41
    };
    array_1d_to_2d(array_1d, 7, 6, &array_2d);
    array_2d_free(array_2d, 7, 6);
}