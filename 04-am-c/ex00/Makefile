##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that compiles
##

SRC =	$(wildcard ../library/*.c) \
			z.c

OBJ = 	$(SRC:.c=.o)

NAME = z

CFLAGS = -I ../include/ -g3

all:	$(NAME)

$(NAME):	lib $(OBJ)
		gcc -g3 -o $(NAME) $(OBJ) $(CFLAGS)

lib:
	make ../library -lmy

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
