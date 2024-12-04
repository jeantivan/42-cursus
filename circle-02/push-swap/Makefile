NAME=push_swap

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

MAKEFLAGS += --no-print-directory

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a


CFILES = main.c error.c utils.c stack.c parser.c operations.c extra.c push.c swap.c rotate.c r_rotate.c \
 k_sort.c sort_aux.c sort_small.c sort.c

OBJS = $(CFILES:.c=.o)

INCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I .

CHECKERFILES = error.c utils.c stack.c parser.c operations.c extra.c push.c swap.c rotate.c r_rotate.c \
	checker.c get_next_line.c

CHECKEROBJS = $(CHECKERFILES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS) 
	@echo "\033[42;37m  Compilando PUSH_SWAP  \033[0m"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF) $(INCLUDES)
	@echo "Created $(NAME)"

checker: $(LIBFT) $(PRINTF) $(CHECKEROBJS)
	@echo "\033[41;37m  Creando checker  \033[0m"
	@$(CC) $(CFLAGS) $(CHECKEROBJS) -o checker $(LIBFT) $(PRINTF) $(INCLUDES)

$(OBJS): $(CFILES)
	@$(CC) $(CFLAGS) -c $(CFILES) $(INCLUDES)

$(CHECKEROBJS): $(CHECKERFILES)
	@$(CC) $(CFLAGS) -c $(CHECKERFILES) $(INCLUDES)

$(LIBFT):
	@echo "\033[43;37m    Compilando LIBFT    \033[0m"
	make -C $(LIBFT_DIR) bonus

$(PRINTF):
	@echo "\033[44;37m    Compilando FT_PRINTF    \033[0m"
	make -C $(PRINTF_DIR)

clean:
	@rm -f $(OBJS)
	@rm -f $(CHECKEROBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f checker
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

test: all
	
#./$(NAME)  ${nums}

exec: all
	./$(NAME) $(shell shuf -i 1-100 -n 100 | tr '\n' ' ')

.PHONY: all clean fclean re