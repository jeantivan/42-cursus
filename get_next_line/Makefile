NAME = gnl.o

CC = gcc

#CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -fsanitize=address 
CFLAGS = -Wall -Wextra -Werror

INCLUDE = get_next_line.h

CFILES = main.c get_next_line.c get_next_line_utils.c

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC)  $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

exec: fclean
	@make BUFFER_SIZE=100000
	@echo "Executing $(NAME)"
	./gnl.o

.PHONY: all clean fclean re