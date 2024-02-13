/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:51:02 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/13 20:58:35 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_images(t_game *game, int32_t row, int32_t col)
{
	if (game->map->matrix[row][col] == '1')
		mlx_image_to_window(game->mlx, game->wall, col * 32,
			row * 32);
	if (game->map->matrix[row][col] == '0')
		mlx_image_to_window(game->mlx, game->space, col * 32,
			row * 32);
	if (game->map->matrix[row][col] == 'P')
		mlx_image_to_window(game->mlx, game->player, col * 32,
			row * 32);
	if (game->map->matrix[row][col] == 'C')
		mlx_image_to_window(game->mlx, game->collectible,
			col * 32, row * 32);
	if (game->map->matrix[row][col] == 'E')
		mlx_image_to_window(game->mlx, game->exit, col * 32,
			row * 32);
}

static void	draw(t_game *game)
{
	uint32_t	row;
	uint32_t	col;

	row = 0;
	while (row < game->map->rows)
	{
		col = 0;
		while (col < game->map->cols)
		{
			draw_images(game, row, col);
			col++;
		}
		row++;
	}
}

void	start_game(t_game *game)
{
	draw(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
