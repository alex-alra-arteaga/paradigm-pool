/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** Contains the prototypes of all the functions in libstring.a
*/

#include <stddef.h>
#include <stdio.h>

#ifndef STRING_H_
    #define STRING_H_

typedef struct string_s string_t;
typedef void (*string_init_t)(string_t *this, const char *s);
typedef void (*string_destroy_t)(string_t *this);
typedef void (*assign_s_t)(string_t *this, const string_t *str);
typedef void (*assign_c_t)(string_t *this, const char *s);
typedef void (*append_s_t)(string_t *this, const string_t *ap);
typedef void (*append_c_t)(string_t *this, const char *ap);
typedef char (*at_t)(const string_t *this, size_t pos);
typedef void (*clear_t)(string_t *this);
typedef int (*length_t)(const string_t *this);
typedef int (*compare_s_t)(const string_t *this, const string_t *str);
typedef int (*compare_c_t)(const string_t *this, const char *str);
typedef size_t (*copy_t)(const string_t *this, char *s, size_t n, size_t pos);
typedef const char *(*c_str_t)(const string_t *this);
typedef int (*empty_t)(const string_t *this);
typedef int (*find_s_t)(const string_t *this, const string_t *str, size_t pos);
typedef int (*find_c_t)(const string_t *this, const char *str, size_t pos);
typedef void (*insert_c_t)(string_t *this, size_t pos, const char *str);
typedef void (*insert_s_t)(string_t *this, size_t pos, const string_t *str);
typedef int (*to_int_t)(const string_t *this);
typedef string_t **(*split_s_t)(const string_t *this, char separator);
typedef char **(*split_c_t)(const string_t *this, char separator);
typedef void (*print_t)(const string_t *this);
typedef void (*join_c_t)(string_t *this, char delim, const char *const *array);
typedef void (*join_s_t)(string_t *th, char delim, const string_t *const *arr);
typedef string_t *(*substr_t)(const string_t *this, int offset, int length);

typedef struct string_s {
    char *str;
    string_init_t string_init;
    string_destroy_t string_destroy;
    assign_s_t assign_s;
    assign_c_t assign_c;
    append_s_t append_s;
    append_c_t append_c;
    at_t at;
    clear_t clear;
    length_t length;
    compare_s_t compare_s;
    compare_c_t compare_c;
    copy_t copy;
    c_str_t c_str;
    empty_t empty;
    find_s_t find_s;
    find_c_t find_c;
    insert_c_t insert_c;
    insert_s_t insert_s;
    to_int_t to_int;
    split_s_t split_s;
    split_c_t split_c;
    print_t print;
    join_c_t join_c;
    join_s_t join_s;
    substr_t substr;
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
char at(const string_t *this, size_t pos);
void clear(string_t *this);
int length(const string_t *this);
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);
int to_int(const string_t *this);
string_t **split_s(const string_t *this, char separator);
char **split_c(const string_t *this, char separator);
void print(const string_t *this);
void join_c(string_t *this, char delim, const char *const *array);
void join_s(string_t *this, char delim, const string_t *const *array);
string_t *substr(const string_t *this, int offset, int length);

#endif /* STRING_H_ */
