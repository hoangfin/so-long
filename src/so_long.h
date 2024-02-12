/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:46:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/12 16:25:13 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "MLX42/MLX42.h"

typedef struct s_map
{
	char	**matrix;
	int32_t	rows;
	int32_t	cols;
	int32_t	width;
	int32_t	height;

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

int			read_map(t_map *map, const char *path);
void		draw_map(t_game *game);
bool		is_valid_map(t_map *map);
void		init_game(t_game *game, t_map *map);
void		cleanup(t_game *game);
void		key_hook(mlx_key_data_t keydata, void *param);
void		resize_hook(int32_t width, int32_t height, void *param);
void		close_hook(void *param);
t_list		*find_shortest_path(t_map *map, int32_t target_x, int32_t target_y);
t_path_node	*create_path_node(t_path_node *parent, int32_t x, int32_t y);
void		move(t_game *game, int32_t x, int32_t y);

#endif