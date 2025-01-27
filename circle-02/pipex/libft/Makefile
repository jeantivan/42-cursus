NAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDE = libft.h

P1FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_tolower.c \
ft_toupper.c ft_strlen.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memset.c ft_bzero.c ft_memchr.c \
ft_memcmp.c ft_strlcat.c ft_strlcpy.c \
ft_calloc.c ft_strdup.c ft_memcpy.c \
ft_memmove.c ft_strnstr.c ft_atoi.c

P2FILES = ft_substr.c ft_strjoin.c ft_itoa.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_striteri.c ft_strmapi.c \
ft_split.c ft_strtrim.c

LISTS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
 ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
 ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS = $(P1FILES:.c=.o) $(P2FILES:.c=.o)
BONUS_OBJS = $(LISTS:.c=.o)

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
BG_YELLOW = \033[43;37m

all: $(NAME)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -I./ -c $< -o $@
	@printf "\r                                                                           "
	@printf "\r🔧 $(GRAY)$(CC) $(CFLAGS) -c $< -o $@$(DEF_COLOR)"

start:
	@echo "$(BG_YELLOW)    Creating [$(NAME)]    $(DEF_COLOR)"

$(NAME): start $(OBJS) $(INCLUDE)

	@ar -rcs $(NAME) $(OBJS)
	@echo "\n🔗 $(CYAN) ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)$(DEF_COLOR)"
	@echo  "\n✅ DONE $(NAME) created!"

bonus: $(OBJS) $(BONUS_OBJS) $(INCLUDE)
	@ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "\n🔗 $(CYAN) ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)$(DEF_COLOR)"
	@echo  "\n✅ DONE $(NAME) created!"
	@touch bonus

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f $(NAME)
	@rm -f bonus

re: fclean all

.PHONY: all clean fclean re
