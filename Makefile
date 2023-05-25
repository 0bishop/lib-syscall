##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## my Makefile
##

.SILENT:

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = ./bin

all: $(NAME) clean

$(NAME): $(OBJ)
	gcc -fverbose-asm -w -c $(SRC)
	gcc -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
