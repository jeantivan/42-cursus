NAME = push_swap

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

MAKEFLAGS += --no-print-directory

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

BASEINCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I . 
BASEFILES = error.c utils.c stack.c parser.c operations.c extra.c push.c swap.c rotate.c r_rotate.c

MAINFILES = main.c k_sort.c sort_aux.c sort_small.c sort.c
CHECKERFILES = checker.c get_next_line.c made_mov.c

OBJS = $(MAINFILES:.c=.o) $(BASEFILES:.c=.o)
CHECKEROBJS = $(CHECKERFILES:.c=.o) $(BASEFILES:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	@echo "\033[42;37m  Compilando PUSH_SWAP  \033[0m"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)

bonus: $(LIBFT) $(PRINTF) checker

checker: $(CHECKEROBJS)
	@echo "\033[41;37m  Creando checker  \033[0m"
	$(CC) $(CFLAGS) $(CHECKEROBJS) -o checker $(LIBFT) $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "\033[43;37m    Compilando LIBFT    \033[0m"
	make -C $(LIBFT_DIR) bonus

$(PRINTF):
	@echo "\033[44;37m    Compilando FT_PRINTF    \033[0m"
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	rm -f $(CHECKEROBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f checker
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all

exec: all
	./$(NAME) $(shell shuf -i 1-100 -n 100 | tr '\n' ' ')

.PHONY: all clean fclean re bonus exec
