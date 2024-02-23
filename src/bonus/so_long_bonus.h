/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:46:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/23 20:33:40 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	GAME_WIN,
	GAME_LOSE,
	GAME_EXIT
}	t_game_state;

typedef struct s_sprite
{
	mlx_image_t	*image;
	uint32_t	slice_w;
	uint32_t	slice_h;
	uint32_t	slice_count;
}	t_sprite;

typedef struct s_animation
{
	uint32_t	duration;
}	t_animation;

typedef enum e_player_state
{
	PLAYER_IDLE,
	PLAYER_RUNNING
}	t_player_state;

typedef struct s_player
{
	int32_t			x;
	int32_t			y;
	t_animation		*move;
	t_player_state	state;
}	t_player;

typedef struct s_game
{
	mlx_t			*mlx;
	char			**map;
	int32_t			row_count;
	int32_t			col_count;
	int32_t			map_w;
	int32_t			map_h;
	mlx_image_t		*space;
	mlx_image_t		*wall;
	mlx_image_t		*collectible;
	t_sprite		*clt_sprite;
	mlx_image_t		*exit;
	mlx_image_t		*player;
	uint32_t		collectible_count;
	uint32_t		move_count;
	t_game_state	state;
}	t_game;

mlx_image_t	*load_png(mlx_t *mlx, const char *path);
t_sprite	*load_sprite(mlx_t *mlx, const char *path, uint32_t slice_count);
void		delete_sprite(mlx_t *mlx, t_sprite **sprite);

char		**read_map(const char *pathname);
bool		validate_map(char **map);
bool		is_rectangular(char **map);
bool		has_valid_chars(char **map);
bool		has_valid_pec(char **map, int p, int e, int c);
bool		has_valid_path(char **map, size_t row_count, size_t col_count);
bool		is_enclosed(char **map, size_t row_count, size_t col_count);
uint32_t	count_collectibles(char **map);

int			init_game(t_game *game, char **map);
void		start_game(t_game *game);
void		cleanup(t_game *game);
void		key_hook(mlx_key_data_t keydata, void *param);
void		loop_hook(void *param);
void		close_hook(void *param);
void		move(t_game *game, int32_t dx, int32_t dy);

void		update_collectibles(void *param);
void		put_pixel(
				mlx_image_t *img,
				mlx_image_t *sprite,
				uint32_t x,
				uint32_t y \
			);

#endif