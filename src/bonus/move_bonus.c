/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:45:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/26 12:22:35 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static bool	is_valid_move(t_game *game, int32_t x, int32_t y)
{
	mlx_instance_t *const	walls = game->wall->instances;
	uint32_t				i;

	if (x < 0 || x >= game->map_w || y < 0 || y >= game->map_h)
		return (false);
	i = 0;
	while (i < game->wall->count)
	{
		if (walls[i].x == x && walls[i].y == y)
			return (false);
		i++;
	}
	return (true);
}

void	collect(t_game *game, int32_t player_x, int32_t player_y)
{
	uint32_t	i;

	i = 0;
	while (i < game->collectible->count)
	{
		if (
			game->collectible->instances[i].x == player_x
			&& game->collectible->instances[i].y == player_y
			&& game->collectible->instances[i].enabled == true
		)
		{
			game->collectible->instances[i].enabled = false;
			game->collectible_count--;
			break ;
		}
		i++;
	}
	if (game->collectible_count == 0)
		game->exit->enabled = true;
}

static void	escape(t_game *game, int32_t player_x, int32_t player_y)
{
	if (
		game->exit->instances[0].x == player_x
		&& game->exit->instances[0].y == player_y
		&& game->exit->enabled == true
	)
	{
		ft_putendl_fd("YOU'VE WON", 1);
		cleanup(game);
		mlx_close_window(game->mlx);
	}
}

void	move(t_game *game, int32_t dx, int32_t dy)
{
	const int32_t	x = game->player->instances[0].x + dx;
	const int32_t	y = game->player->instances[0].y + dy;

	if (is_valid_move(game, x, y) == false)
		return ;
	game->player->instances[0].x += dx;
	game->player->instances[0].y += dy;
	game->move_count++;
	printf("Number of movements: %u\n", game->move_count);
	collect(game, x, y);
	escape(game, x, y);
}
