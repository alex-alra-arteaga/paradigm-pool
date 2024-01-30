/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercise 04
*/

#include "object.h"
#include "float.h"
#include "new.h"
#include <float.h>

typedef struct {
    Class base;
    float x;
} FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->x = va_arg(*args, double);
};

static void Float_dtor(FloatClass *this)
{
    this->x = 0;
};

static char *Float_str(FloatClass *this)
{
    char *base_str = "<Float (%f)>";
    int len = snprintf(NULL, 0, base_str, this->x);
    char *str = malloc(sizeof(char) * (len + 1));

    if (str == NULL)
        raise("Out of memory");
    sprintf(str, base_str, this->x);
    return (str);
}

static FloatClass *_add(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    // if (this->x + other->x > FLT_MAX)
    //     raise("Overflow");
    // if (this->x + other->x < FLT_MIN)
    //     raise("Underflow");
    return new(Float, this->x + other->x);
}

static FloatClass *_sub(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    // if (this->x - other->x > FLT_MAX)
    //     raise("Overflow");
    // if (this->x - other->x < FLT_MIN)
    //     raise("Underflow");
    return new(Float, this->x - other->x);
}

static FloatClass *_mul(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    // if (this->x * other->x > FLT_MAX)
    //     raise("Overflow");
    // if (this->x * other->x < FLT_MIN)
    //     raise("Underflow");
    return new(Float, this->x * other->x);
}

static FloatClass *_div(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    if (other->x == 0)
        raise("Division by zero");
    return new(Float, this->x / other->x);
}

static bool _eq(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    return (this->x == other->x);
}

static bool _gt(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    return (this->x > other->x);
}

static bool _lt(FloatClass *this, FloatClass *other)
{
    if (this == NULL || other == NULL)
        raise("NULL pointer");
    return (this->x < other->x);
}

static const FloatClass _description = {
        {
                .__size__ = sizeof(FloatClass),
                .__name__ = "Float",
                .__ctor__ = (ctor_t)&Float_ctor,
                .__dtor__ = (dtor_t)&Float_dtor,
                .__str__ = (to_string_t)&Float_str,
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

const Class *Float = (const Class *)&_description;