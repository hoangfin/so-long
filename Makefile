NAME := so_long

SOURCE_DIR := ./src
BONUS_SOURCE_DIR := ./src/bonus

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
			$(SOURCE_DIR)/move.c \
			$(SOURCE_DIR)/count_collectibles.c \
			$(SOURCE_DIR)/cleanup.c

BONUS_SOURCES := $(BONUS_SOURCE_DIR)/main_bonus.c \
					$(BONUS_SOURCE_DIR)/load_png_bonus.c \
					$(BONUS_SOURCE_DIR)/sprite/load_sprite_bonus.c \
					$(BONUS_SOURCE_DIR)/sprite/delete_sprite_bonus.c \
					$(BONUS_SOURCE_DIR)/map/has_valid_chars_bonus.c \
					$(BONUS_SOURCE_DIR)/map/has_valid_path_bonus.c \
					$(BONUS_SOURCE_DIR)/map/has_valid_pec_bonus.c \
					$(BONUS_SOURCE_DIR)/map/is_enclosed_bonus.c \
					$(BONUS_SOURCE_DIR)/map/is_rectangular_bonus.c \
					$(BONUS_SOURCE_DIR)/map/read_map_bonus.c \
					$(BONUS_SOURCE_DIR)/map/validate_map_bonus.c \
					$(BONUS_SOURCE_DIR)/init_game_bonus.c \
					$(BONUS_SOURCE_DIR)/put_pixel_bonus.c \
					$(BONUS_SOURCE_DIR)/start_game_bonus.c \
					$(BONUS_SOURCE_DIR)/hooks/loop_hook_bonus.c \
					$(BONUS_SOURCE_DIR)/hooks/close_hook_bonus.c \
					$(BONUS_SOURCE_DIR)/hooks/key_hook_bonus.c \
					$(BONUS_SOURCE_DIR)/move_bonus.c \
					$(BONUS_SOURCE_DIR)/count_collectibles_bonus.c \
					$(BONUS_SOURCE_DIR)/update_collectibles_bonus.c \
					$(BONUS_SOURCE_DIR)/cleanup_bonus.c

OBJECTS := $(SOURCES:.c=.o)
BONUS_OBJECTS := $(BONUS_SOURCES:.c=.o)

.PHONY = all bonus clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX42) -ldl -lglfw -pthread -lm -o $(NAME)
#	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX42) -ldl -lglfw -L"/Users/$(USER)/.brew/Cellar/glfw/3.3.9/lib" -pthread -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: .bonus

.bonus: $(LIBFT) $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) $(MLX42) -ldl -lglfw -pthread -lm -o $(NAME)
#	$(CC) $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) $(MLX42) -ldl -lglfw -L"/Users/$(USER)/.brew/Cellar/glfw/3.3.9/lib" -pthread -lm -o $(NAME)
	touch .bonus

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(SOURCE_DIR)/*.o
	rm -f $(SOURCE_DIR)/hooks/*.o
	rm -f $(SOURCE_DIR)/map/*.o
	rm -f $(BONUS_SOURCE_DIR)/*.o
	rm -f $(BONUS_SOURCE_DIR)/hooks/*.o
	rm -f $(BONUS_SOURCE_DIR)/map/*.o

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f .bonus

re: fclean $(NAME)
