/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 20:50:09 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/11 15:22:39 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw(t_game *game, int32_t row, int32_t col, char c)
{
	if (c == '1')
		mlx_image_to_window(game->mlx, game->wall, col * game->wall->width,
			row * game->wall->height);
	if (c == '0')
		mlx_image_to_window(game->mlx, game->space, col * game->space->width,
			row * game->space->height);
	if (c == 'P')
		mlx_image_to_window(game->mlx, game->player, col * game->player->width,
			row * game->player->height);
	if (c == 'C')
		mlx_image_to_window(game->mlx, game->collectible,
			col * game->collectible->width, row * game->collectible->height);
	if (c == 'E')
		mlx_image_to_window(game->mlx, game->exit, col * game->exit->width,
			row * game->exit->height);
}

void	draw_map(t_game *game)
{
	int32_t	row;
	int32_t	col;

	row = 0;
	while (row < game->map->rows)
	{
		col = 0;
		while (col < game->map->cols)
			draw(game, row, col, game->map->matrix[row][col++]);
		row++;
	}
}
