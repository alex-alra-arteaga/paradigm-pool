##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that compiles and creates a static library
##

SRC =	$(wildcard *.c)

OBJ = 	$(SRC:.c=.o)

NAME = a.out

CFLAGS = -I ./ -g3

all:	$(NAME)

$(NAME):	lib $(OBJ)
		gcc -g3 -o $(NAME) $(OBJ) $(CFLAGS)

lib:	$(OBJ)
	ar rc libstring.a $(OBJ)
	ranlib libstring.a

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf libstring.a

re: fclean all
