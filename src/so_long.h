/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:46:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/10 17:50:27 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 512
# define HEIGHT 512

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
	int32_t	row;
	int32_t	col;
	int32_t	width;
	int32_t	height;
}	t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	*space;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	int32_t		collectible_count;
	int32_t		move_count;
}	t_game;

int		init_map(t_map *map, const char *path);
bool	is_valid_map(t_map *map);
void	init_game(t_game *game, t_map *map);
void	cleanup(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	close_hook(void *param);
void	draw_map(t_game *game);
void	move(int32_t x, int32_t y, t_game *game);

#endif