NAME = libft

CC = cc

HEADERS_DIR = /

CFLAGS = -Wall -Werror -Wextra -I $(HEADERS_DIR)

CFILES = main.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c

OBJS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	@echo "Compiling $(NAME) and creatin object files..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME).o

clean:
	@echo "Cleaning objects files..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Cleaning $(NAME).o"
	@rm -f $(NAME).o

re: fclean all

exe: all clean
	@echo "Running $(NAME).o"
	@./$(NAME).o
	@rm -f $(NAME).o

.PHONY: all clean fclean re
