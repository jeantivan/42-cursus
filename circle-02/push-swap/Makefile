NAME=push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

CFILES = main.c error.c parser.c utils.c

OBJS = $(CFILES:.c=.o)

INCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I .

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@echo "Compling files..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF) $(INCLUDES)
	@echo "Created $(NAME)"

$(OBJS): $(CFILES)
	@$(CC) $(CFLAGS) -c $(CFILES) $(INCLUDES)

$(LIBFT): 
	make -C $(LIBFT_DIR) bonus

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	@rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

exec: all
	./$(NAME)

.PHONY: all clean fclean re