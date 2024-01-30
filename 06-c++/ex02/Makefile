##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that compiles and creates a static library
##

SRC =	$(wildcard *.cpp)

OBJ = 	$(SRC:.cpp=.o)

NAME = StupidUnitConverter

CFLAGS = -g3

all:	$(NAME)

$(NAME):	$(OBJ)
		g++ -std=c++20 -Wall -Wextra -Werror -g3 -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
