NAME = gnl.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror -DBUFFER_SIZE=$(BUFFER_SIZE)

INCLUDE = get_next_line.h

CFILES = main.c get_next_line.c get_next_line_utils.c

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re