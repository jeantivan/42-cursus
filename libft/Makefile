NAME = libft.a

CC = cc

HEADERS_DIR = /

CFLAGS = -Wall -Werror -Wextra -I $(HEADERS_DIR)

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

OBJS = $(P1FILES:%.c=%.o) $(P2FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

compile:
	@make && make clean
	@$(CC) $(CFLAGS) main.c -L. -lft -o main.o

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(OBJS)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re compile 
