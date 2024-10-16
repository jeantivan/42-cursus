NAME = ft_printf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ft_printf.h

CFILES = ft_printf.c

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	@ar -rcs $(NAME) $(OBJS)
	@echo  "Created $(NAME)"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all

compile:
	@make && make clean
	@$(CC) $(CFLAGS) main.c $(NAME) -o main.o

.PHONY: all clean fclean re
