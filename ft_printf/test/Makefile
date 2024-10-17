NAME = test_ft_prinft

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = test.h 

CFILES = main.c ft_test_base.c ft_test_null.c ft_test_char.c ft_test_string.c ft_test_digit.c ft_test_int.c \
ft_test_u.c ft_test_x.c ft_test_p.c

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
