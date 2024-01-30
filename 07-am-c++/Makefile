##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for unit tests
##

.PHONY: tests_run clean

tests_run: string_test
	./int_linked_list_tests

string_test:
	g++ -std=c++20 -Wall -Wextra -o string_tests tests/*.cpp \
	tests/ex00.cpp --coverage -lcriterion

clean:
	@rm -f string_tests
	@rm -f *.gcno *.gcda *.gcov
	@rm -f *.o
