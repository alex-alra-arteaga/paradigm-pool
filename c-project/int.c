/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercise 04
*/

#include "object.h"
#include "int.h"
#include "new.h"

typedef struct {
    Class base;
    int x;
} IntClass;

static char *Int_str(IntClass *this)
{
    char *base_str = "<Int (%d)>";
    int len = snprintf(NULL, 0, base_str, this->x);
    char *str = malloc(sizeof(char) * (len + 1));

    if (str == NULL)
        raise("Out of memory");
    sprintf(str, base_str, this->x);
    return str;
}

static void Int_ctor(IntClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
};

static void Int_dtor(IntClass *this)
{
    this->x = 0;
};

static IntClass *_add(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    if (this->x + other->x > 2147483647)
        raise("Overflow");
    return new(Int, this->x + other->x);
}

static IntClass *_sub(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    if (this->x - other->x > 2147483647)
        raise("Overflow");
    return new(Int, this->x - other->x);
}

static IntClass *_mul(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    if (this->x * other->x > 2147483647)
        raise("Overflow");
    return new(Int, this->x * other->x);
}

static IntClass *_div(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    if (other->x == 0)
        raise("Division by zero");
    return (new(Int, this->x / other->x));
}

static bool _eq(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    return (this->x == other->x);
}

static bool _gt(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    return (this->x > other->x);
}

static bool _lt(IntClass *this, IntClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    return (this->x < other->x);
}

static const IntClass _description = {
        {
                .__size__ = sizeof(IntClass),
                .__name__ = "Int",
                .__ctor__ = (ctor_t)&Int_ctor,
                .__dtor__ = (dtor_t)&Int_dtor,
                .__str__ = (to_string_t)&Int_str,
                .__add__ = (binary_operator_t)&_add,
                .__sub__ = (binary_operator_t)&_sub,
                .__mul__ = (binary_operator_t)&_mul,
                .__div__ = (binary_operator_t)&_div,
                .__eq__ = (binary_comparator_t)_eq,
                .__gt__ = (binary_comparator_t)_gt,
                .__lt__ = (binary_comparator_t)_lt
        },
        .x = 0,
};

const Class *Int = (const Class *)&_description;
