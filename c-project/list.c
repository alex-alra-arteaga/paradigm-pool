/*
** EPITECH PROJECT, 2024
** rush02
** File description:
** list
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct list_s {
    Object *value;
    struct list_s *next;
} list_t;

typedef struct {
    Container base;
    Class *_type;
    size_t _size;
    list_t *_head;
    list_t *_tail;
} ListClass;

typedef struct {
    Iterator base;
    ListClass *_list;
    list_t *_current;
    size_t _idx;
} ListIteratorClass;

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
    this->_idx = va_arg(*args, int);
    this->_current = this->_list->_head;
    if (this->_idx == (this->_list->_size - 1)) {
        this->_current = this->_list->_tail;
        return;
    }
    for (size_t i = 0; i < this->_idx; ++i) {
        if (this == NULL) {
            raise("Out of range");
        }
        this->_current = this->_current->next;
    }
}

static bool ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void ListIterator_incr(ListIteratorClass *this)
{
    this->_idx += 1;
    this->_current = this->_current->next;
    if (this->_current == NULL)
        raise("Out of range");
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    return this->_current->value;
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list args;

    va_start(args, this);
    delete(this->_current->value);
    this->_current->value = va_new(this->_list->_type, &args);
    va_end(args);
}

static const ListIteratorClass   ListIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._list = NULL,
    ._idx = 0
};

static const Class *ListIterator = (const Class *)&ListIteratorDescr;

void list_add_elem_at_back(ListClass *this, void *elem)
{
    list_t *node = malloc(sizeof *node);

    if (node == NULL)
        raise("Out of memory");
    node->value = elem;
    node->next = node;
    if (this->_head == NULL) {
        this->_head = node;
        this->_tail = node;
    } else {
        this->_tail->next = node;
        this->_tail = node;
    }
    this->_size += 1;
}

static void List_ctor(ListClass *this, va_list *args)
{
    va_list tmp;
    Object *new_obj;
    size_t size = va_arg(*args, size_t);

    this->_type = va_arg(*args, Class *);
    this->_size = 0;

    for (size_t i = 0; i < size; ++i) {
        va_copy(tmp, *args);
        new_obj = va_new(this->_type, &tmp);
        list_add_elem_at_back(this, new_obj);
    }
}

static void List_dtor(ListClass *this)
{
    list_t *aux;

    this->_tail->next = NULL;
    while (this->_head != NULL) {
        aux = this->_head;
        delete(aux->value);
        this->_head = aux->next;
        free(aux);
    }
}

static size_t List_len(ListClass *this)
{
    return (this->_size);
}

static Iterator *List_begin(ListClass *this)
{
    return (new(ListIterator, this, 0));
}

static Iterator *List_end(ListClass *this)
{
    return (new(ListIterator, this, this->_size));
}

Object *list_get_elem_at_position(list_t *list, unsigned int position)
{
    for (unsigned int i = 0; (i < position) && (list != NULL); i++)
        list = list->next;
    if (list != NULL)
        return (list->value);
    else
        return (NULL);
}

static Object *List_getitem(ListClass *this, ...)
{
    va_list args;
    size_t index;

    va_start(args, this);
    index = va_arg(args, int);
    if (this->_size <= index) {
        raise("Out of range");;
    }
    va_end(args);

    return list_get_elem_at_position(this->_head, index);
}

static void List_setitem(ListClass *this, ...)
{
    va_list args;
    size_t index;
    list_t *tmp = this->_head;

    va_start(args, this);
    index = va_arg(args, int);
    for (unsigned int i = 0; (i < index) && (tmp != NULL); i++)
        tmp = tmp->next;
    if (tmp == NULL)
        raise("Error on list");
    delete(tmp->value);
    tmp->value = va_new(this->_type, &args);
    va_end(args);
}

static const ListClass _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._head = NULL,
    ._tail = NULL,
};

const Class *List = (const Class *)&_descr;
