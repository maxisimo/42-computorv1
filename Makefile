NAME = computorv1

SRC = main.c \
	  parser.c \
	  reduce.c \
	  display.c \
	  solve.c \
	  utils.c \
	  utils2.c

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lm

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all
