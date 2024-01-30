/*
** EPITECH PROJECT, 2024
** rush02
** File description:
** new
*/

#include <stdarg.h>
#include "object.h"
#include "raise.h"

Object *new(const Class *class, ...)
{
    Object *new_obj = malloc(class->__size__);
    va_list args;

    if (new_obj == NULL)
        raise("Out of memory");
    va_start(args,class);
    memcpy(new_obj, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(new_obj, &args);
    va_end(args);
    return new_obj;
}

Object *va_new(const Class *class, va_list* ap)
{
    Object *new_obj = malloc(class->__size__);

    if (new_obj == NULL)
        raise("Out of memory");
    memcpy(new_obj, class, class->__size__);
    if (class->__ctor__ != NULL)
        class->__ctor__(new_obj, ap);
    return new_obj;
}

void delete(Object *ptr)
{
    Class *casted_in_class = (Class *)ptr;

    if (casted_in_class->__dtor__ != NULL)
        casted_in_class->__dtor__(casted_in_class);
    free(ptr);
}
