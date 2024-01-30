/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, string implementations
*/

#include <criterion/criterion.h>

Test(string, default_value)
{
    std::string s;
    cr_assert_eq(s, "");
}

Test(string, assign)
{
    std::string s;
    s = "test";
    cr_assert_eq(s, "test");
}

Test(string, append)
{
    std::string s("test");
    s += "ing";
    cr_assert_eq(s, "testing");
}