NAME = libftprintf.a
CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = -I $(LIBFT_DIR) -I .

CFILES = ft_printf.c ft_nbr_to_hex.c ft_putchar.c ft_putstr.c

OBJS = $(CFILES:.c=.o)

OUTPUT = test_ft_printf.o


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar -rcs $(NAME) $(OBJS) $(LIBFT)
	@echo  "Created $(NAME)"

$(OBJS): $(CFILES)
	$(CC) $(CFLAGS) -c $(CFILES) $(INCLUDES)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(OBJS)
	@rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

compile: all
	$(CC) $(CFLAGS) main.c $(NAME) -o $(OUTPUT)

.PHONY: all clean fclean re test
