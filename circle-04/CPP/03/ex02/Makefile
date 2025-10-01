NAME = repetitive_work

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

INCLUDES = -I.


SRC_DIR = .

OBJ_DIR = ./obj

FILES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

SRC_FILES = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

# Colors
BOLD_PURPLE = \033[1;35m
BOLD_CYAN = \033[1;36m
BOLD_YELLOW = \033[1;33m
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

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "✅ DONE ./$(NAME) created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@printf "🔧 $(GRAY)$(CC) $(FLAGS) -c $< -o $@$(DEF_COLOR)\n"

clean:
	@rm -dfr $(OBJ_DIR)
	@printf "$(GRAY)🧼 $(OBJ_DIR) removed! 🫧\n$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@printf "🗑️ $(GRAY) ./$(NAME) removed!$(DEF_COLOR)\n"

re: fclean all

.PHONY: all fclean clean re
