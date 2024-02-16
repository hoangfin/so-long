/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:51:02 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/16 16:38:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_images(t_game *game, int32_t row, int32_t col)
{
	if (game->map->grid[row][col] == '1')
		mlx_image_to_window(
			game->mlx, game->wall, col * RENDER_PIXELS, row * RENDER_PIXELS \
		);
	if (game->map->grid[row][col] == 'P')
		mlx_image_to_window(
			game->mlx, game->player, col * RENDER_PIXELS, row * RENDER_PIXELS \
		);
	if (game->map->grid[row][col] == 'C')
		mlx_image_to_window(
			game->mlx, \
			game->collectible, \
			col * RENDER_PIXELS, \
			row * RENDER_PIXELS \
		);
	if (game->map->grid[row][col] == 'E')
		mlx_image_to_window(
			game->mlx, game->exit, col * RENDER_PIXELS, row * RENDER_PIXELS \
		);
}

static void	draw_floor(t_game *game)
{
	uint32_t	row;
	uint32_t	col;

	row = 0;
	while (row < game->map->rows)
	{
		col = 0;
		while (col < game->map->cols)
		{
			mlx_image_to_window(
				game->mlx,
				game->space,
				col * RENDER_PIXELS,
				row * RENDER_PIXELS \
			);
			col++;
		}
		row++;
	}
}

static void	draw(t_game *game)
{
	uint32_t	row;
	uint32_t	col;

	draw_floor(game);
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
