/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, string implementations
*/

#include "string.h"
#include "common.h"

int empty(const string_t *this)
{
    if (!this || this->str == NULL || strlen(this->str) == 0)
        return 1;
    return 0;
}

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *tmp;

    if (this && str)
        tmp = strstr(this->str + pos, str->str);
    if (tmp == NULL)
        return -1;
    return tmp - this->str;
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *tmp;

    if (this)
        tmp = strstr(this->str + pos, str);
    if (tmp == NULL)
        return -1;
    return tmp - this->str;
}

void insert_c(string_t *this, size_t pos, const char *str)
{
    char *tmp;

    if (this)
        tmp = malloc(sizeof(char) * (strlen(this->str) + strlen(str) + 1));
    if (!tmp)
        return NULL;
    tmp = strncpy(tmp, this->str, pos);
    tmp = strcat(tmp, str);
    tmp = strcat(tmp, this->str + pos);
    free(this->str);
    this->str = strdup(tmp);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    int this_len;
    int str_len;
    char *tmp;

    if (!this)
        return NULL;
    this_len = strlen(this->str);
    str_len = strlen(str->str);
    tmp = malloc(sizeof(char) * (this_len + str_len + 1));
    if (!tmp)
        return NULL;
    tmp = strncpy(tmp, this->str, pos);
    tmp = strcat(tmp, str->str);
    tmp = strcat(tmp, this->str + pos);
    free(this->str);
    this->str = strdup(tmp);
}
