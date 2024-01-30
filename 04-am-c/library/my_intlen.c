/*
** EPITECH PROJECT, 2023
** intlen.c
** File description:
** Mini mini_sprintf implementation
*/

int my_intlen(const int *array)
{
    int i = 0;

    for (; array[i]; i++);
    return i;
}
