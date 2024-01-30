/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, string implementations
*/

#include "string.h"
#include "common.h"

int to_int(const string_t *this)
{
    return atoi(this->str);
}

void free_string_array(string_t **array, int count)
{
    for (int i = 0; i < count && array && array[i]; i++)
        free(array[i]);
    if (array)
        free(array);
}

void free_char_array(char **array)
{
    for (int i = 0; array && array[i]; i++)
        free(array[i]);
    if (array)
        free(array);
}

string_t **create_string_array(char **c_str_array, int count)
{
    string_t **str_array = malloc(sizeof(string_t *) * (count + 1));

    if (!str_array)
        return NULL;
    for (int i = 0; i < count; i++) {
        str_array[i] = malloc(sizeof(string_t));
        if (str_array[i] != NULL && c_str_array && c_str_array[i]) {
            str_array[i]->str = c_str_array[i];
        } else {
            free_string_array(str_array, i);
            free_char_array(c_str_array);
            return NULL;
        }
    }
    str_array[count] = NULL;
    return str_array;
}

string_t **split_s(const string_t *this, char separator)
{
    string_t **str_array;
    char **c_str_array;
    int count;

    if (!this)
        return NULL;
    c_str_array = my_str_to_array(this->str, separator);
    if (!c_str_array)
        return NULL;
    for (count = 0; c_str_array[count] != NULL; count++);
    str_array = create_string_array(c_str_array, count);
    if (str_array == NULL)
        return NULL;
    if (c_str_array)
        free(c_str_array);
    return str_array;
}
