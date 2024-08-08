NAME := so_long

SOURCE_DIR := ./src

LIBFT_DIR := ./libs/libft
MLX42_DIR := ./libs/MLX42

LIBFT := $(LIBFT_DIR)/libft.a
MLX42 := $(MLX42_DIR)/build/libmlx42.a

CC := cc
CFLAGS := -Wall -Wextra -Werror \
			-I$(LIBFT_DIR) \
			-I$(MLX42_DIR)/include

SOURCES := $(SOURCE_DIR)/main.c \
			$(SOURCE_DIR)/util/load_png.c \
			$(SOURCE_DIR)/util/load_sprite.c \
			$(SOURCE_DIR)/util/delete_sprite.c \
			$(SOURCE_DIR)/util/is_hidden_file.c \
			$(SOURCE_DIR)/util/put_pixel.c \
			\
			$(SOURCE_DIR)/map/get_player_pos.c \
			$(SOURCE_DIR)/map/has_valid_chars.c \
			$(SOURCE_DIR)/map/has_valid_path.c \
			$(SOURCE_DIR)/map/has_valid_pec.c \
			$(SOURCE_DIR)/map/is_enclosed.c \
			$(SOURCE_DIR)/map/is_rectangular.c \
			$(SOURCE_DIR)/map/read_map.c \
			$(SOURCE_DIR)/map/validate_map.c \
			$(SOURCE_DIR)/map/count_enemies.c \
			$(SOURCE_DIR)/map/count_collectibles.c \
			\
			$(SOURCE_DIR)/is_movable.c \
			$(SOURCE_DIR)/handle_collision.c \
			$(SOURCE_DIR)/update_collectibles.c \
			$(SOURCE_DIR)/update_counter_ui.c \
			\
			$(SOURCE_DIR)/game/cleanup.c \
			$(SOURCE_DIR)/game/init_characters.c \
			$(SOURCE_DIR)/game/init_game.c \
			$(SOURCE_DIR)/game/start_game.c \
			$(SOURCE_DIR)/game/loop_hook.c \
			$(SOURCE_DIR)/game/close_hook.c \
			$(SOURCE_DIR)/game/key_hook.c \
			\
			$(SOURCE_DIR)/animation/animate_hor_move.c \
			$(SOURCE_DIR)/animation/animate_idle.c \
			$(SOURCE_DIR)/animation/animate_ver_move.c \
			\
			$(SOURCE_DIR)/character/delete_character.c \
			$(SOURCE_DIR)/character/new_character.c \
			$(SOURCE_DIR)/character/set_character_state.c \
			$(SOURCE_DIR)/character/transition_player.c \
			$(SOURCE_DIR)/character/update_player.c \
			$(SOURCE_DIR)/character/update_player_ui.c \
			$(SOURCE_DIR)/character/transition_enemies.c \
			$(SOURCE_DIR)/character/update_enemies.c \
			$(SOURCE_DIR)/character/update_enemies_ui.c

OBJECTS := $(SOURCES:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX42) -ldl -lglfw -pthread -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build && $(MAKE) -C $(MLX42_DIR)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(SOURCE_DIR)/*.o
	rm -f $(SOURCE_DIR)/hooks/*.o
	rm -f $(SOURCE_DIR)/map/*.o
	rm -f $(SOURCE_DIR)/*.o
	rm -f $(SOURCE_DIR)/map/*.o
	rm -f $(SOURCE_DIR)/util/*.o
	rm -f $(SOURCE_DIR)/character/*.o
	rm -f $(SOURCE_DIR)/animation/*.o
	rm -f $(SOURCE_DIR)/game/*.o
	rm -rf $(MLX42_DIR)/build

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean $(NAME)
