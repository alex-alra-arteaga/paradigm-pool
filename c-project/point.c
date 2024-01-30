/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct
{
    Class   base;
    int x;
    int y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    (void) *this;
    return;
}

static size_t nbr_len(int nb)
{
    int cpy = nb;
    size_t result = 0;

    if (nb < 0) {
        result += 1;
        nb *= -1;
    }
    if (nb <= 9) {
        return result + 1;
    }
    while (cpy != 0) {
        result++;
        cpy /= 10;
    }
    return result;
}

char *point_to_string(PointClass *this)
{
    char start_msg[] = "<Point (";
    char mid_msg[] = ", ";
    char end_msg[] = ")>";
    size_t size_to_alloc = sizeof(start_msg) + sizeof(mid_msg) + sizeof(end_msg) + nbr_len(this->x) + nbr_len(this->y) + 1;
    char *new_str = malloc(size_to_alloc);

    sprintf(new_str, "%s%d%s%d%s", start_msg, this->x, mid_msg, this->y, end_msg);
    return new_str;
}

Object *point_addition(PointClass *a, PointClass *b)
{
    return new(Point, a->x + b->x, a->y + b->y);
}

Object *point_substraction(PointClass *a, PointClass *b)
{
    return new(Point, a->x - b->x, a->y - b->y);
}

// Create additional functions here

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&point_to_string,    /* Implement this method for exercice 02 */
        .__add__ = (binary_operator_t)&point_addition,
        .__sub__ = (binary_operator_t)&point_substraction,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class   *Point = (const Class *)&_description;
