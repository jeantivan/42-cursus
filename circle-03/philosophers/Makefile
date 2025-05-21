NAME = philo

CC = cc

MAKEFLAGS += --no-print-directory

CFLAGS = -g -Wall -Werror -Wextra
LDFLAGS = -lpthread

INCLUDES = -I./inc

SRC_DIR = ./src
OBJ_DIR = ./obj

SRC = main.c \
	  utils/error.c \
	  utils/basic.c \
	  utils/check_args.c \
	  fork.c \
	  table.c

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))


# Colors
BOLD_PURPLE	= \033[1;35m
BOLD_CYAN =	\033[1;36m
BOLD_YELLOW	= \033[1;33m
NO_COLOR = \033[0m
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
BLUE_UNDER = \033[1;34m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME) $(LDFLAGS)
	@echo  "\n✅ DONE ./$(NAME) created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "🔧 $(GRAY)$(CC) $(CFLAGS) -c $< -o $@$(DEF_COLOR)\n"

clean:
	@printf "🧼 Cleaning .o files! 🫧\n"
	@rm -f $(OBJS_FILES)
	@rm -rf $(OBJ_DIR)
	@printf "🧼 $(GRAY)$(OBJ_DIR) cleaned!$(DEF_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "🗑️ $(GRAY) ./$(NAME) cleaned!$(DEF_COLOR)\n"

re: fclean all
	@printf "🔄 $(GRAY) ./$(NAME) rebuilt!$(DEF_COLOR)\n"

.PHONY: all clean fclean re
