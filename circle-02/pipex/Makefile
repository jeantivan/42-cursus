NAME = pipex

CC = cc
CFLAGS = -g -Wall -Werror -Wextra

MAKEFLAGS += --no-print-directory

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

BASEINCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I . 

MAINFILES = main.c utils.c command.c

OBJS = $(MAINFILES:.c=.o)

# Colors
BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
BG_GREEN = \033[42;37m

all: $(NAME)

start:
	@echo "$(BG_GREEN)    Creating [$(NAME)]    $(DEF_COLOR)"

$(NAME): $(LIBFT) $(PRINTF) start $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)
	@printf "\r                                                                           "
	@printf "\r🔧 $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF)$(DEF_COLOR)"
	@echo  "\n✅ DONE $(NAME) created!"

%.o: %.c
	@$(CC) $(CFLAGS) $(BASEINCLUDES) -c $< -o $@
	@printf "\r                                                                           "
	@printf "\r🔧 $(GRAY)$(CC) $(CFLAGS) -c $< -o $@$(DEF_COLOR)"

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

$(PRINTF):
	@make -C $(PRINTF_DIR)

clean:
	@rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
