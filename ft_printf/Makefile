NAME = libftprintf.a
CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I .

CFILES = utils.c ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putpointer.c ft_puthex.c

OBJS = $(CFILES:.c=.o)

OUTPUT = test_ft_printf.o


all: $(NAME)

$(NAME): $(OBJS) 
	ar -rcs $(NAME) $(OBJS) 
	@echo  "Created $(NAME)"

$(OBJS): $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES) $(INCLUDE)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all

compile: all
	$(CC) $(CFLAGS) main.c $(NAME) -o $(OUTPUT) 

.PHONY: all clean fclean re test
