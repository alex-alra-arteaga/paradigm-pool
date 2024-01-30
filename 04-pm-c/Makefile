##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for unit tests
##

.PHONY: tests_run clean

tests_run: int_list_tests linked_list_tests stack_tests queue_tests map_tests
	./int_linked_list_tests
	./linked_list_tests
	./stack_tests
	./queue_tests
	./map_tests

int_list_tests:
	gcc -std=gnu17 -Wall -Wextra -o int_linked_list_tests *.c \
	tests/int_list.t.c --coverage -lcriterion

linked_list_tests:
	gcc -std=gnu17 -Wall -Wextra -o linked_list_tests *.c tests/list.t.c \
	--coverage -lcriterion

stack_tests:
	gcc -std=gnu17 -Wall -Wextra -o stack_tests *.c tests/stack.t.c \
	--coverage -lcriterion

queue_tests:
	gcc -std=gnu17 -Wall -Wextra -o queue_tests *.c tests/queue.t.c \
	--coverage -lcriterion

map_tests:
	gcc -std=gnu17 -Wall -Wextra -o map_tests *.c tests/map.t.c \
	--coverage -lcriterion

clean:
	@rm -f int_linked_list_tests linked_list_tests stack_tests queue_tests \
	map_tests
	@rm -f *.gcno *.gcda *.gcov
	@rm -f *.o
