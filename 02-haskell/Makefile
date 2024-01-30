##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## This is just a Makefile but v2
##

SRC = 	DoOp.hs

BINARY = doop

CC = ghc

all: $(BINARY)

$(BINARY): $(SRC)
	$(CC) -O2 -o $(BINARY) $(SRC)

clean:
	rm -f *.o
	rm -f *.hi

fclean: clean
	rm -f $(BINARY)

re: fclean all

.PHONY: all clean fclean re