NAME = get_next_line

CC = gcc

HEADERS_DIR = /

CFILES = main.c get_next_line.c get_next_line_utils.c

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o ${NAME}

clean:
	rm -f $(OBJS)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re