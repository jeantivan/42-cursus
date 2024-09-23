NAME = libft.a

CC = cc

HEADERS_DIR = /

CFLAGS = -Wall -Werror -Wextra -I $(HEADERS_DIR)

CFILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
ft_isascii.c ft_isprint.c ft_tolower.c \
ft_toupper.c ft_strlen.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_memset.c ft_bzero.c ft_memchr.c \
ft_memcmp.c ft_strlcat.c ft_strlcpy.c \
ft_calloc.c ft_strdup.c ft_memcpy.c ft_memmove.c

OBJS = $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

compile:
	@make && make clean
	@$(CC) $(CFLAGS) main.c -L. $(NAME) -o main.o

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
