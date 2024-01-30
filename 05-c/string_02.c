/*
** EPITECH PROJECT, 2024
** test.c
** File description:
** Paradigm Seminar, string implementations
*/

#include "string.h"
#include "common.h"

void assign_c(string_t *this, const char *s)
{
    if (this && this->str)
        this->str = strdup(s);
}

void append_s(string_t *this, const string_t *ap)
{
    int this_len;
    int ap_len;
    char *tmp;

    if (this && this->str && ap && ap->str) {
        this_len = strlen(this->str);
        ap_len = strlen(ap->str);
        tmp = malloc(sizeof(char) * (this_len + ap_len + 1));
        tmp = strcat(tmp, this->str);
        tmp = strcat(tmp, ap->str);
        free(this->str);
        this->str = strdup(tmp);
    }
}

void append_c(string_t *this, const char *ap)
{
    char *tmp;

    if (this && this->str && ap) {
        tmp = malloc(sizeof(char) * (strlen(this->str) + strlen(ap) + 1));
        tmp = strcat(tmp, this->str);
        tmp = strcat(tmp, ap);
        free(this->str);
        this->str = strdup(tmp);
    }
}

char at(const string_t *this, size_t pos)
{
    if (this && this->str) {
        if (pos > strlen(this->str))
            return -1;
        return this->str[pos];
    }
}

void clear(string_t *this)
{
    if (this && this->str) {
        free(this->str);
        this->str = strdup("");
    }
}
