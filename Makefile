NAME = quick

SRC = 	main.c \
		$(wildcard src/*.c)

CFLAGS = -Wall -W -Werror -Wextra -I./include

OBJ = $(SRC:.c=.o)

CC = gcc

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

all: $(NAME)

clean:
	rm -fr $(OBJ)

fclean: clean
	rm -fr $(NAME)

re: fclean all

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $(NAME) $(DESTDIR)$(PREFIX)/bin/$(NAME)
	chmod 755 $(DESTDIR)$(PREFIX)/bin/$(NAME)

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/$(NAME)

.PHONY: clean fclean re all install
