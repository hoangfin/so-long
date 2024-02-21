/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:46:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/21 23:53:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

typedef struct s_map
{
	char	**grid;
	int32_t	rows;
	int32_t	cols;
	int32_t	width;
	int32_t	height;
}	t_map;

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
	mlx_image_t		*exit;
	mlx_image_t		*player;
	uint32_t		collectible_count;
	uint32_t		move_count;
}	t_game;

char		**read_map(const char *pathname);
bool		validate_map(char **map);
bool		is_rectangular(char **map);
bool		has_valid_chars(char **map);
bool		has_valid_pec(char **map, int p, int e, int c);
bool		has_valid_path(char **map, size_t row_count, size_t col_count);
bool		is_enclosed(char **map, size_t row_count, size_t col_count);

int			init_game(t_game *game, char **map);
void		start_game(t_game *game);
void		cleanup(t_game *game);
void		key_hook(mlx_key_data_t keydata, void *param);
void		close_hook(void *param);
void		move(t_game *game, int32_t dx, int32_t dy);
uint32_t	count_collectibles(char **map);

#endif