NAME = gnl.o

NAME_BONUS = gnl_bonus.o

CC = gcc

#CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=$(BUFFER_SIZE) -fsanitize=address 
CFLAGS = -Wall -Wextra -Werror

INCLUDE = get_next_line.h

CFILES = main.c get_next_line.c get_next_line_utils.c

INCLUDE_BONUS = get_next_line_bonus.h

BONUSCFILES = main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS = $(CFILES:.c=.o)

BONUSOBJS = $(BONUSCFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

bonus: $(BONUSOBJS)
	@$(CC) $(CFLAGS) $(INCLUDE_BONUS) $(BONUSOBJS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

exec: fclean
	@make BUFFER_SIZE=100000
	@echo "Executing $(NAME)"
	./gnl.o

.PHONY: all clean fclean re