NAME=FdF

MAKEFLAGS += --no-print-directory

CC = cc

CFLAGS = -g  -Wunreachable-code -Ofast

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ./ft_printf

PRINTF = $(PRINTF_DIR)/libftprintf.a

GET_NEXT_LINE_DIR = ./get_next_line

GET_NEXT_LINE = $(GET_NEXT_LINE_DIR)/libgnl.a

MLX42_DIR = ./MLX42

MLX42 = $(MLX42_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

CFILES = main.c parser.c error.c utils.c map.c map_utils.c points.c points_utils.c \
 draw.c draw_utils.c matrix.c projection.c dda.c colors.c hooks.c handlers.c handlers_aux.c

OBJS = $(CFILES:.c=.o)

INCLUDES = -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(GET_NEXT_LINE_DIR) -I $(MLX42_DIR)/include -I .

WIN_W ?= 1920
WIN_H ?= 1080
MARGIN ?= 20

all: libmlx $(NAME)

$(MLX42): libmlx

libmlx:
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -DWIN_H=$(WIN_H) -DWIN_W=${WIN_W} -DMARGIN=${MARGIN} -o $@ -c $< $(INCLUDES)

$(NAME): $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(MLX42) $(OBJS) 
	@echo "Compling files..."
	@$(CC) $(CFLAGS)  $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF) $(GET_NEXT_LINE) $(MLX42) $(INCLUDES)
	@echo "Created $(NAME)"

$(LIBFT): 
	@echo "\033[43;37m    Compilando libft    \033[0m"
	@make -C $(LIBFT_DIR) bonus

$(PRINTF): $(LIBFT)
	@echo "\033[44;37m    Compilando ft_prinft    \033[0m"
	@make -C $(PRINTF_DIR)

$(GET_NEXT_LINE):
	@echo "\033[42;37m    Compilando get_next_line    \033[0m"
	@make -C $(GET_NEXT_LINE_DIR) 

clean:
	@rm -rf $(MLX42_DIR)/build
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

test: 
	./$(NAME) test.txt

laptop:
	make WIN_W=1300 WIN_H=680

.PHONY: all clean fclean re