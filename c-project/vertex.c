/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "new.h"
#include "vertex.h"
#include "point.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
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

static char *Vertex_str(VertexClass *this)
{
    char *str = malloc(sizeof("<Vertex (, , )>") + nbr_len(this->x) + nbr_len(this->y) + nbr_len(this->z));

    if (str == NULL) {
        raise("Out of memory");
    }
    sprintf(str, "<Vertex (%d, %d, %d)>", this->x, this->y, this->z);
    return (str);
}

static VertexClass *Vertex_add(VertexClass *this, VertexClass *other)
{
    return new(Vertex, this->x + other->x, this->y + other->y, this->z + other->z);
}

static VertexClass *Vertex_sub(VertexClass *this, VertexClass *other)
{
    return new(Vertex, this->x - other->x, this->y - other->y, this->z - other->z);
}

static VertexClass *Vertex_mul(VertexClass *this, VertexClass *other)
{
    return new(Vertex, this->x * other->x, this->y * other->y, this->z * other->z);
}

static VertexClass *Vertex_div(VertexClass *this, VertexClass *other)
{
    if (other->x == 0 || other->y == 0 || other->z == 0)
        raise("Division by zero");
    return new(Vertex, this->x / other->x, this->y / other->y, this->z / other->z);
}

static bool Vertex_eq(VertexClass *this, VertexClass *other)
{
    return (this->x == other->x && this->y == other->y
        && this->z == other->z);
}

static bool Vertex_gt(VertexClass *this, VertexClass *other)
{
    return (this->x > other->x && this->y > other->y
        && this->z > other->z);
}

static bool Vertex_lt(VertexClass *this, VertexClass *other)
{
    return (this->x < other->x && this->y < other->y
        && this->z < other->z);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = (binary_operator_t)&Vertex_mul,
        .__div__ = (binary_operator_t)&Vertex_div,
        .__eq__ = (binary_comparator_t)&Vertex_eq,
        .__gt__ = (binary_comparator_t)&Vertex_gt,
        .__lt__ = (binary_comparator_t)&Vertex_lt
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;
