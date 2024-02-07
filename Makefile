NAME := so_long

SOURCE_DIR := ./src

LIBFT_DIR := ./libs/libft
MLX42_DIR := ./libs/MLX42

LIBFT := $(LIBFT_DIR)/libft.a
MLX42 := $(MLX42_DIR)/build/libmlx42.a

CC := cc
CFLAGS := -g -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(MLX42_DIR)/include

SOURCES := $(SOURCE_DIR)/main.c \
			$(SOURCE_DIR)/init_game.c \
			$(SOURCE_DIR)/draw_map.c \
			$(SOURCE_DIR)/close_hook.c \
			$(SOURCE_DIR)/key_hook.c \
			$(SOURCE_DIR)/move.c \
			$(SOURCE_DIR)/cleanup.c

OBJECTS := $(SOURCES:.c=.o)

.PHONY = all bonus clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX42) -ldl -lglfw -pthread -lm -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# bonus: $(NAME) $(BONUS_OBJECTS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(SOURCE_DIR)/*.o

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean $(NAME)
