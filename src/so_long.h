/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:46:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/08 16:16:48 by hoatran          ###   ########.fr       */
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
# include "MLX42.h"

typedef struct s_game
{
	mlx_t		*mlx;
	uint32_t	map_width;
	uint32_t	map_height;
	mlx_image_t	*space;
	mlx_image_t	*wall;
	mlx_image_t	*collectible;
	mlx_image_t	*exit;
	mlx_image_t	*player;
	int32_t		collectible_count;
	int32_t		move_count;
}	t_game;

void		init_game(t_game *game);
void		cleanup(t_game *game);
void		key_hook(mlx_key_data_t keydata, void *param);
void		close_hook(void *param);
void		draw_map(t_game *game);
void		move(int32_t x, int32_t y, t_game *game);
const char	*get_error_msg(int errno);

#endif