##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for unit tests
##

.PHONY: tests_run

tests_run: ex01_tests ex02_tests ex03_tests
	./unit_tests
	./ex02_tests
	./ex03_tests

ex01_tests:
	gcc -std=gnu17 -Wall -Wextra -o unit_tests ex01/mul_div.c tests/ex01.c --coverage -lcriterion

ex02_tests:
	gcc -std=gnu17 -Wall -Wextra -o ex02_tests ex02/concat.c tests/ex02.c --coverage -lcriterion

ex03_tests:
	gcc -std=gnu17 -Wall -Wextra -o ex03_tests ex03/array_1d_to_2d.c tests/ex03.c --coverage -lcriterion
