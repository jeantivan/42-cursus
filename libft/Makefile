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

LISTS = ft_lstnew_bonus.c

OBJS = $(P1FILES:%.c=%.o) $(P2FILES:%.c=%.o)
BONUS_OBJS = $(LISTS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
	@ar -rcs $(NAME) $(OBJS)
	@echo  "Created $(NAME)"

bonus: $(OBJS) $(BONUS_OBJS) $(INCLUDE)
	@ar -rcs $(NAME) $^
	@touch $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f $(NAME)
	@rm -f bonus

re: fclean all

compile:
	@make && make clean
	@$(CC) $(CFLAGS) main.c -L. -lft -o main.o

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(OBJS)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re
