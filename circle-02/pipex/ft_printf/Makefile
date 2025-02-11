NAME = libftprintf.a
CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = ft_printf.h

CFILES = utils.c ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putpointer.c ft_puthex.c

OBJS = $(CFILES:.c=.o)

OUTPUT = test_ft_printf.o

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
BG_BLUE = \033[44;37m

all: $(NAME)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -I./ -c $< -o $@
	@printf "\r                                                                           "
	@printf "\r🔧 $(GRAY)$(CC) $(CFLAGS) -c $< -o $@$(DEF_COLOR)"

start:
	@echo "$(BG_BLUE)    Creating [$(NAME)]    $(DEF_COLOR)"

$(NAME): start $(OBJS) $(INCLUDE)
	@ar -rcs $(NAME) $(OBJS)
	@echo "\n🔗 $(CYAN) ar -rcs $(NAME) $(OBJS)$(DEF_COLOR)"
	@echo  "\n✅ DONE $(NAME) created!"

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(OBJS)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

