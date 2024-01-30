##
## EPITECH PROJECT, 2024
## make
## File description:
## file
##

SRC = point.c \
		new.c \
		vertex.c \
		int.c \
		char.c \
		float.c \
		array.c \
		player.c \

TESTS = tests/tests.c

INCDIR = -I tests/include/

CRITERION = --coverage -lcriterion

UNIT_TESTS = unit_tests

clean:
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(UNIT_TESTS)

re: fclean tests_run

unit_tests:
	gcc -o $(UNIT_TESTS) $(SRC) $(TESTS) $(INCDIR) $(CRITERION)

tests_run: unit_tests
	./$(UNIT_TESTS)

.PHONY: unit_tests tests_run clean fclean re