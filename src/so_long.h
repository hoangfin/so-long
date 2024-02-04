/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:46:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/04 20:50:51 by hoatran          ###   ########.fr       */
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
# include <MLX42/MLX42.h>

typedef struct s_map
{
	uint32_t	width;
	uint32_t	height;
}	t_map;

typedef struct s_image
{
	mlx_image_t *space;
	mlx_image_t *wall;
	mlx_image_t *collectible;
	mlx_image_t *exit;
	mlx_image_t *player;
}	t_image;

typedef struct s_game
{
	mlx_t		*mlx;
	t_image		image;
	int32_t		collectible_count;
	int32_t		move_count;
}	t_game;

void		init_game(t_game *game, t_map *map);
void		cleanup(t_game *game);
void		key_hook(mlx_key_data_t keydata, void *param);
void		close_hook(void *param);
void		draw_floor(t_game *game);
const char	*get_error_msg(int errno);

#endif