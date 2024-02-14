/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:46:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/14 23:35:38 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef RENDER_PIXELS
#  define RENDER_PIXELS 32
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
	char		**matrix;
	uint32_t	rows;
	uint32_t	cols;
	uint32_t	width;
	uint32_t	height;
}	t_map;

typedef struct s_path_node
{
	struct s_path_node	*parent;
	int32_t				x;
	int32_t				y;
}	t_path_node;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*space;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	uint32_t	collectible_count;
	uint32_t	move_count;
}	t_game;

t_map		*read_map(const char *pathname);
void		delete_map(t_map *map);
bool		is_valid_map(t_map *map);
void		init_game(t_game *game, const char *pathname);
void		start_game(t_game *game);
void		cleanup(t_game *game);
void		key_hook(mlx_key_data_t keydata, void *param);
void		close_hook(void *param);
// t_list		*find_shortest_path(t_map *map, int32_t target_x, int32_t target_y);
t_path_node	*create_path_node(t_path_node *parent, int32_t x, int32_t y);
void		move(t_game *game, int32_t x, int32_t y);

#endif