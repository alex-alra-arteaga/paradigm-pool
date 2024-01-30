##
## EPITECH PROJECT, 2024
## Pushswap
## File description:
## Makefile Haskell
##

HC = ghc

HCFLAGS = -O2

SRC = pushswap_checker.hs

EXEC = pushswap_checker

all: $(EXEC)

$(EXEC): $(SRC)
	$(HC) $(HCFLAGS) -o $(EXEC) $(SRC)

clean:
	rm -f *.o *.hi

fclean : clean
	rm -f $(EXEC)

re: clean all

.PHONY : all clean fclean re