/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, string implementations
*/

#include "string.h"
#include "common.h"

int length(const string_t *this)
{
    if (this == NULL || this->str == NULL)
        return -1;
    return strlen(this->str);
}

int compare_s(const string_t *this, const string_t *str)
{
    if (this && str)
        return strcmp(this->str, str->str);
    return -1;
}

int compare_c(const string_t *this, const char *str)
{
    if (this)
        return strcmp(this->str, str);
    return -1;
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    size_t i = 0;

    if (!this || pos > strlen(this->str))
        return 0;
    for (; i < n && this->str[pos] != '\0'; i++) {
        s[i] = this->str[pos];
        pos++;
    }
    return i;
}

const char *c_str(const string_t *this)
{
    return this ? this->str : NULL;
}
