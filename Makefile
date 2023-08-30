.SILENT:

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = ./bin

all: $(NAME) clean

$(NAME): $(OBJ)
	clang -fverbose-asm -fkeep-inline-functions -w -c $(SRC)
	clang -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
