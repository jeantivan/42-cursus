NAME = libgnl.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = get_next_line.h

CFILES = get_next_line.c get_next_line_utils.c

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re