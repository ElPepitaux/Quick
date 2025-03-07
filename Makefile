NAME = quick

SRC = 	main.c \
		$(wildcard src/*.c)

CFLAGS = -Wall -W -Werror -Wextra -I./include

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

all: $(NAME)

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

.PHONY: clean fclean re all
