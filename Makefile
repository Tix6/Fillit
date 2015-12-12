NAME = fillit
CC = gcc
#CFLAGS = -Wall -Wextra -Werror -Iincludes
CFLAGS = -I ./inc
LDFLAGS = #-L libft/ -lft
SRCS = src/main.c \
src/input.c \
src/list.c \
src/tetriminos.c \
src/misc.c \
src/ft_strsplit.c


OBJS = $(SRCS:.c=.o)

all: lib $(NAME)

lib:
	# make -C libft

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
