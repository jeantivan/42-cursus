NAME = libftprintf.a
CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = -I $(LIBFT_DIR) -I .

CFILES = utils.c ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putpointer.c ft_puthex.c

OBJS = $(CFILES:.c=.o)

OUTPUT = test_ft_printf.o


all: $(NAME)

$(NAME): $(OBJS) 
	ar -rcs $(NAME) $(OBJS) 
	@echo  "Created $(NAME)"

$(OBJS): $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES) $(INCLUDE)

# $(LIBFT):
# 	make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
#	make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(OBJS)
	@rm -f $(NAME)
#	make -C $(LIBFT_DIR) fclean

re: fclean all

compile: all
	$(CC) $(CFLAGS) main.c $(NAME) -o $(OUTPUT) 

.PHONY: all clean fclean re test
