/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** Contains the prototypes of all the functions in libmy.a
*/

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#ifndef MY_H_
    #define MY_H_

void *my_memmove(void *dest, const void *src, size_t n);
char *trim_until_alpha(char *input);
char **my_str_to_array_2(char *buff, char c, char c2);
int my_arraylen(char **array);
int is_empty_or_whitespace(const char *);
char *merge_lines(char *, char *);
int increment_j_on_invalid_line(char **, int);
char *remove_comment(char *);
char **my_str_to_array_whitespace(char *, char);
int line_counter(char *, char);
int which_opcode(char *);
int is_empty_or_whitespace_or_header(const char *);
char *my_strcpy(char *, char const *);
int is_whitespace(char);
void *my_memcpy(void *, const void *, int32_t);
void *my_memset(void *, int32_t, int64_t);
int my_strcmp(char const *, char const *);
int my_strlen(char const *);
char *remove_character(char *, char);
char *my_strncpy(char *, char const *, int);
char **my_str_to_array(char *, char);
long long my_strtoull(const char *str);
int my_intlen(const int *array);
char *my_strchr(char *str, int c);

#endif /* MY_H_ */
