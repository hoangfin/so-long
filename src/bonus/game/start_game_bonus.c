/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:51:02 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/04 01:14:30 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	draw_images(t_game *game, int32_t row, int32_t col)
{
	const int32_t	x = game->map_x + col * RENDER_PIXELS;
	const int32_t	y = game->map_y + row * RENDER_PIXELS;

	if (game->map[row][col] == '1')
		mlx_image_to_window(game->mlx, game->wall, x, y);
	if (game->map[row][col] == 'C')
		mlx_image_to_window(game->mlx, game->collectible, x, y);
	if (game->map[row][col] == 'E')
		mlx_image_to_window(game->mlx, game->exit, x, y);
}

static void	draw_floor(t_game *game)
{
	int32_t	row;
	int32_t	col;

	row = 0;
	while (row < game->row_count)
	{
		col = 0;
		while (col < game->col_count)
		{
			mlx_image_to_window(
				game->mlx,
				game->space,
				game->map_x + col * RENDER_PIXELS,
				game->map_y + row * RENDER_PIXELS \
			);
			col++;
		}
		row++;
	}
}

static void	draw_enemies(mlx_t *mlx, t_character **enemies)
{
	while (*enemies != NULL)
	{
		mlx_image_to_window(
			mlx,
			(*enemies)->image,
			(*enemies)->x,
			(*enemies)->y \
		);
		enemies++;
	}
}

static int	draw(t_game *game)
{
	int32_t	row;
	int32_t	col;

	game->text = mlx_put_string(game->mlx, "Movement count:", PADDING, PADDING);
	game->move_count_img = mlx_put_string(\
		game->mlx, "0", PADDING + game->text->width + 5, PADDING \
	);
	draw_floor(game);
	row = 0;
	while (row < game->row_count)
	{
		col = 0;
		while (col < game->col_count)
		{
			draw_images(game, row, col);
			col++;
		}
		row++;
	}
	if (mlx_image_to_window(
			game->mlx, game->player->image, game->player->x, game->player->y \
	) == -1)
		return (-1);
	draw_enemies(game->mlx, game->enemies);
	mlx_image_to_window(game->mlx, game->overlay, 0, 0);
	return (0);
}

void	start_game(t_game *game)
{
	draw(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
