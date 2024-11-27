NAME=push_swap

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

CFILES = main.c error.c utils.c stack.c parser.c operations.c sort_temp.c movs_1.c sort.c
OBJS = $(CFILES:.c=.o)

INCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I .

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS) 
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

test: all
	
#./$(NAME)  ${nums}

exec: all
	./$(NAME) $(shell shuf -i 1-100 -n 100 | tr '\n' ' ')

.PHONY: all clean fclean re