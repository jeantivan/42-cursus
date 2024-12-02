NAME=FdF

MAKEFLAGS += --no-print-directory

CC = cc

CFLAGS = -g -Wall -Werror -Wextra

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

GET_NEXT_LINE_DIR = ./get_next_line

GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/libgnl.a

CFILES = main.c

OBJS = $(CFILES:.c=.o)

INCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(GET_NEXT_LINE_DIR) -I .

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(OBJS) 
	@echo "Compling files..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(INCLUDES)
	@echo "Created $(NAME)"

$(OBJS): $(CFILES)
	@$(CC) $(CFLAGS) -c $(CFILES) $(INCLUDES)

$(LIBFT): 
	@echo "\033[43;37m    Compilando libft    \033[0m"
	@make -C $(LIBFT_DIR) bonus

$(PRINTF):
	@echo "\033[44;37m    Compilando ft_prinft    \033[0m"
	@make -C $(PRINTF_DIR)

$(GET_NEXT_LINE):
	@echo "\033[42;37m    Compilando get_next_line    \033[0m"
	@make -C $(GET_NEXT_LINE_DIR) 

clean:
	@rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	make -C $(GET_NEXT_LINE_DIR) clean

fclean: clean
	@rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	make -C $(GET_NEXT_LINE_DIR) fclean

re: fclean all

.PHONY: all clean fclean re