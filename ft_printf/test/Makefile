NAME = test_ft_prinft

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = test.h 

CFILES = main.c ft_test_base.c ft_test_null.c ft_test_char.c

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
