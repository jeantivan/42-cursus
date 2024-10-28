NAME = gnl.o

CC = gcc

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE)
#CFLAGS = -Wall -Wextra -Werror

INCLUDE = get_next_line.h

CFILES = main.c get_next_line.c get_next_line_utils.c

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC)  $(CFLAGS) $(INCLUDE) $(OBJS) -g -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

exec: fclean
	@make BUFFER_SIZE=84
	@echo "Executing $(NAME)"
	./gnl.o

.PHONY: all clean fclean re