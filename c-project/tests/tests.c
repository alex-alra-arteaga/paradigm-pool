/*
** EPITECH PROJECT, 2024
** test player
** File description:
** test unit
*/

#include <criterion/criterion.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "point.h"
#include "new.h"
#include "vertex.h"
#include "int.h"
#include "float.h"
#include "char.h"
#include "raise.h"
#include "player.h"
#include "iterator.h"
#include "array.h"

Test(point_addition, test_point_addition)
{
    Object *obj = new(Point, 1, 2);
    Object *obj2 = new(Point, 3, 4);

    char *result = str(addition(obj, obj2));
    cr_assert_str_eq(result, "<Point (4, 6)>");
}

Test(point_substraction, test_point_substraction)
{
    Object *obj = new(Point, 1, 2);
    Object *obj2 = new(Point, 3, 4);

    char *result = str(subtraction(obj, obj2));
    cr_assert_str_eq(result, "<Point (-2, -2)>");
}

Test(new, Point_creation)
{
    Object *n = new(Point);

    delete(n);
}

Test(Vertex_add, test_vertex_addition)
{
    Object *obj = new(Vertex, 1, 2, 3);
    Object *obj2 = new(Vertex, 4, 5, 6);

    char *result = str(addition(obj, obj2));
    cr_assert_str_eq(result, "<Vertex (5, 7, 9)>");
}

Test(Vertex_sub, test_vertex_substraction)
{
    Object *obj = new(Vertex, 1, 2, 3);
    Object *obj2 = new(Vertex, 4, 5, 6);

    char *result = str(subtraction(obj, obj2));
    cr_assert_str_eq(result, "<Vertex (-3, -3, -3)>");
}

Test(new, Vertex_creation)
{
    Object *n = new(Vertex);

    delete(n);
}

Test(new, Int_creation)
{
    Object *n = new(Int, 5);

    delete(n);
}

Test(new, Char_creation)
{
    Object *n = new(Char, 'c');

    delete(n);
}

Test(new, Player_creation)
{
    Object *n = new(Player, "toto");

    delete(n);
}

Test(new, Array_creation)
{
    Object *n = new(Array, 5, Int, 5);

    delete(n);
}

Test(Array, test_array_getitem)
{
    Object *n = new(Array, 5, Int, 5);

    cr_assert_str_eq(str(getitem(n, 2)), "<Int (5)>");
    delete(n);
}

Test(Array, test_array_setitem)
{
    Object *n = new(Array, 5, Int, 5);

    setitem(n, 2, 10);
    cr_assert_str_eq(str(getitem(n, 2)), "<Int (10)>");
    delete(n);
}

Test(Array, test_array_len)
{
    Object *n = new(Array, 5, Int, 5);

    cr_assert_eq(len(n), 5);
    delete(n);
}

Test(Iterator, test_iterator_begin)
{
    Object *n = new(Array, 5, Int, 5);
    Iterator *it = begin(n);

    cr_assert_str_eq(str(getval(it)), "<Int (5)>");
    delete(n);
}

Test(Point, test_point_str)
{
    Object *n = new(Point, 5, 6);

    cr_assert_str_eq(str(n), "<Point (5, 6)>");
    delete(n);
}

Test(Vertex, test_vertex_str)
{
    Object *n = new(Vertex, 5, 6, 7);

    cr_assert_str_eq(str(n), "<Vertex (5, 6, 7)>");
    delete(n);
}

Test(Int, test_int_str)
{
    Object *n = new(Int, 5);

    cr_assert_str_eq(str(n), "<Int (5)>");
    delete(n);
}
