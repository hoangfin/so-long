/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:46:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/03 13:06:11 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define PADDING 16
# define MENUBAR_HEIGHT 32

# ifndef RENDER_PIXELS
#  define RENDER_PIXELS 64
# endif

# include "libft.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"

typedef enum s_game_state
{
	GAME_RUNNING,
	GAME_WON,
	GAME_LOST,
	GAME_EXIT
}	t_game_state;

typedef enum e_character_state
{
	PLAYER_IDLE_LEFT,
	PLAYER_IDLE_RIGHT,
	PLAYER_MOVE_UP,
	PLAYER_MOVE_RIGHT,
	PLAYER_MOVE_DOWN,
	PLAYER_MOVE_LEFT,
	ENEMY_IDLE_LEFT,
	ENEMY_IDLE_RIGHT,
	ENEMY_MOVE_UP,
	ENEMY_MOVE_RIGHT,
	ENEMY_MOVE_DOWN,
	ENEMY_MOVE_LEFT,
}	t_character_state;

typedef struct s_sprite
{
	mlx_image_t	*image;
	uint32_t	frame_w;
	uint32_t	frame_h;
	uint32_t	row_count;
	uint32_t	col_count;
}	t_sprite;

typedef struct s_character
{
	mlx_image_t			*image;
	int32_t				x;
	int32_t				y;
	int32_t				distance_moved;
	double				elapsed_time;
	int32_t				current_frame;
	bool				is_state_changed;
	t_character_state	state;
}	t_character;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int32_t			row_count;
	int32_t			col_count;
	int32_t			map_x;
	int32_t			map_y;
	int32_t			map_w;
	int32_t			map_h;
	mlx_image_t		*space;
	mlx_image_t		*wall;
	mlx_image_t		*collectible;
	mlx_image_t		*exit;
	mlx_image_t		*text;
	mlx_image_t		*move_count_img;
	t_sprite		*player_sprite;
	t_sprite		*enemy_sprite;
	t_sprite		*collectible_sprite;
	t_character		*player;
	t_character		**enemies;
	uint32_t		collectible_count;
	uint32_t		move_count;
	t_game_state	state;
}	t_game;

mlx_image_t	*load_png(mlx_t *mlx, const char *path);
t_sprite	*load_sprite(
				mlx_t *mlx,
				const char *pathname,
				uint32_t row_count,
				uint32_t col_count\
			);
void		delete_sprite(mlx_t *mlx, t_sprite **sprite);

char		**read_map(const char *pathname);
bool		validate_map(char **map);
bool		is_rectangular(char **map);
bool		has_valid_chars(char **map);
bool		has_valid_pec(char **map, int p, int e, int c);
bool		has_valid_path(char **map, size_t row_count, size_t col_count);
bool		is_enclosed(char **map, size_t row_count, size_t col_count);
void		get_player_pos(char **map, int *row, int *col);
uint32_t	count_enemies(char **map);
uint32_t	count_collectibles(char **map);

t_character	*new_character(
				mlx_t *mlx,
				int32_t x,
				int32_t y,
				t_character_state state \
			);
void		delete_character(mlx_t *mlx, t_character **character);
int			init_game(t_game *game, char **map);
void		start_game(t_game *game);
void		cleanup(t_game *game);
void		key_hook(mlx_key_data_t keydata, void *param);
void		loop_hook(void *param);
void		close_hook(void *param);
bool		is_movable(t_game *game, int32_t x, int32_t y);

void		transition_game(t_game *game, t_game_state new_state);
void		transition_player(t_game *game, keys_t key);
void		transition_enemies(t_character **enemies, t_game *game);
void		update_game(t_game *game, double elapsed_time);
void		update_player(t_character *player, double elapsed_time);
void		update_enemies(t_character **enemies, double elapsed_time);
void		update_player_ui(t_character *player, t_sprite *player_sprite);
void		update_enemies_ui(t_character **enemies, t_sprite *enemy_sprite);
void		update_counter_ui(t_game *game);
void		update_collectibles(t_game *game, double elapsed_time);
void		handle_collision(t_game *game);
void		animate_idle(t_character *ch, t_sprite *spr, uint32_t spr_row);
void		animate_hor_move(t_character *ch, t_sprite *spr, uint32_t spr_row);
void		animate_ver_move(t_character *ch, t_sprite *spr, uint32_t spr_row);
void		set_character_state(t_character *ch, t_character_state state);
void		put_pixel(
				mlx_image_t *img,
				mlx_image_t *sprite,
				uint32_t x,
				uint32_t y\
			);

#endif