/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, string implementations
*/

#include "string.h"
#include "common.h"

char **split_c(const string_t *this, char separator)
{
    if (!this)
        return NULL;
    return my_str_to_array(this->str, separator);
}

void print(const string_t *this)
{
    if (!this)
        return;
    printf("%s", this->str);
}

void join_c(string_t *this, char delim, const char *const *array)
{
    char *tmp;
    int i = 0;

    if (!this)
        return;
    tmp = malloc(sizeof(char) * (strlen(this->str) + 1));
    if (!tmp)
        return;
    tmp = strcpy(tmp, this->str);
    if (this->str)
        free(this->str);
    this->str = strdup("");
    for (; array[i] != NULL; i++) {
        this->append_c(this, array[i]);
        if (array[i + 1] != NULL)
            this->append_c(this, &delim);
    }
    free(tmp);
}

void join_s(string_t *this, char delim, const string_t *const *array)
{
    char *tmp;
    int i = 0;

    if (!this)
        return;
    tmp = malloc(sizeof(char) * (strlen(this->str) + 1));
    if (!tmp)
        return;
    tmp = strcpy(tmp, this->str);
    if (this->str)
        free(this->str);
    this->str = strdup("");
    for (; array[i] != NULL; i++) {
        this->append_s(this, array[i]);
        if (array[i + 1] != NULL)
            this->append_c(this, &delim);
    }
    free(tmp);
}

string_t *substr(const string_t *this, int offset, int length)
{
    string_t *str;
    char *tmp;

    if (!this)
        return NULL;
    str = malloc(sizeof(string_t));
    if (!str)
        return NULL;
    tmp = malloc(sizeof(char) * (length + 1));
    if (!tmp)
        return NULL;
    tmp = strncpy(tmp, this->str + offset, length);
    tmp[length] = '\0';
    str->str = tmp;
    return str;
}
