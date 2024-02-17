/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:46:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/17 13:37:46 by hoatran          ###   ########.fr       */
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
	char		**grid;
	uint32_t	rows;
	uint32_t	cols;
	uint32_t	width;
	uint32_t	height;
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
	uint32_t	collectible_count;
	uint32_t	move_count;
}	t_game;

t_map	*read_map(const char *pathname);
void	delete_map(t_map *map);
bool	is_valid_map(t_map *map);
void	init_game(t_game *game, const char *pathname);
void	start_game(t_game *game);
void	cleanup(t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	close_hook(void *param);
void	exit_hook(void *param);
void	move(t_game *game, int32_t dx, int32_t dy);
void	collect(t_game *game, int32_t x, int32_t y);
void	exit_game(t_game *game, int32_t x, int32_t y);

#endif