/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercise 04
*/

#include "object.h"
#include "char.h"
#include "new.h"

typedef struct {
    Class base;
    char x;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
};

static void Char_dtor(CharClass *this)
{
    this->x = 0;
};

static char *Char_str(CharClass *this)
{
    char *base_str = "<Char (%c)>";
    int len = snprintf(NULL, 0, base_str, this->x);
    char *str = malloc(sizeof(char) * (len + 1));

    if (str == NULL)
        raise("Out of memory");
    sprintf(str, base_str, this->x);
    return (str);
}

static CharClass *_add(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer exception");
    return new(Char, this->x + other->x);
}

static CharClass *_sub(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer exception");
    return new(Char, this->x - other->x);
}

static CharClass *_mul(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer exception");
    return new(Char, this->x * other->x);
}

static CharClass *_div(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer exception");
    if (other->x == 0)
        raise("Division by zero");
    return new(Char, this->x / other->x);
}

static bool _eq(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer exception");
    return (this->x == other->x);
}

static bool _gt(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer exception");
    return (this->x > other->x);
}

static bool _lt(CharClass *this, CharClass *other)
{
    if (this == NULL || other == NULL)
        raise("Null pointer exception");
    return (this->x < other->x);
}

static const CharClass _description = {
        {
                .__size__ = sizeof(CharClass),
                .__name__ = "Char",
                .__ctor__ = (ctor_t)&Char_ctor,
                .__dtor__ = (dtor_t)&Char_dtor,
                .__str__ = (to_string_t)&Char_str,
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

const Class *Char = (const Class *)&_description;