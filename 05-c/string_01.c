/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, string implementations
*/

#include "string.h"
#include "common.h"

void init_fnc(string_t *this)
{
    this->string_init = &string_init;
    this->string_destroy = &string_destroy;
    this->assign_s = &assign_s;
    this->assign_c = &assign_c;
    this->append_s = &append_s;
    this->append_c = &append_c;
    this->at = &at;
    this->clear = &clear;
    this->length = &length;
    this->compare_s = &compare_s;
    this->compare_c = &compare_c;
    this->copy = &copy;
}

void init_fnc_2(string_t *this)
{
    this->c_str = &c_str;
    this->empty = &empty;
    this->find_s = &find_s;
    this->find_c = &find_c;
    this->insert_c = &insert_c;
    this->insert_s = &insert_s;
    this->to_int = &to_int;
    this->split_s = &split_s;
    this->split_c = &split_c;
    this->print = &print;
    this->join_c = &join_c;
    this->join_s = &join_s;
    this->substr = &substr;
}

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
    init_fnc(this);
    init_fnc_2(this);
}

void string_destroy(string_t *this)
{
    if (this) {
        free(this->str);
        this->str = NULL;
    }
}

void assign_s(string_t *this, const string_t *str)
{
    char *temp;

    if (str && str->str) {
        temp = strdup(str->str);
        if (temp) {
            free(this->str);
            this->str = temp;
        }
    }
}
