NAME := so_long

SOURCE_DIR := ./src

LIBFT_DIR := ./libs/libft
MLX42_DIR := ./libs/MLX42

LIBFT := $(LIBFT_DIR)/libft.a
MLX42 := $(MLX42_DIR)/build/libmlx42.a

CC := cc
CFLAGS := -g \
			-fsanitize=address \
			-D RENDER_PIXELS=64 \
			-Wall -Wextra -Werror \
			-I$(LIBFT_DIR) \
			-I$(MLX42_DIR)/include

SOURCES := $(SOURCE_DIR)/main.c \
			$(SOURCE_DIR)/map/has_valid_chars.c \
			$(SOURCE_DIR)/map/has_valid_path.c \
			$(SOURCE_DIR)/map/has_valid_pec.c \
			$(SOURCE_DIR)/map/is_enclosed.c \
			$(SOURCE_DIR)/map/is_rectangular.c \
			$(SOURCE_DIR)/map/read_map.c \
			$(SOURCE_DIR)/map/validate_map.c \
			$(SOURCE_DIR)/init_game.c \
			$(SOURCE_DIR)/start_game.c \
			$(SOURCE_DIR)/hooks/close_hook.c \
			$(SOURCE_DIR)/hooks/key_hook.c \
			$(SOURCE_DIR)/hooks/loop_hook.c \
			$(SOURCE_DIR)/move.c \
			$(SOURCE_DIR)/count_collectibles.c \
			$(SOURCE_DIR)/collect.c \
			$(SOURCE_DIR)/exit_game.c \
			$(SOURCE_DIR)/cleanup.c
#			$(SOURCE_DIR)/exit_hook.c \

OBJECTS := $(SOURCES:.c=.o)

.PHONY = all bonus clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
#	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX42) -ldl -lglfw -pthread -lm -o $(NAME)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX42) -ldl -lglfw -L"/Users/$(USER)/.brew/Cellar/glfw/3.3.9/lib" -pthread -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# bonus: $(NAME) $(BONUS_OBJECTS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(SOURCE_DIR)/*.o
	rm -f $(SOURCE_DIR)/hooks/*.o
	rm -f $(SOURCE_DIR)/map/*.o

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean $(NAME)
