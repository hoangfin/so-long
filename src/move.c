/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:45:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/15 20:13:23 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_valid_move(t_game *game, int32_t x, int32_t y)
{
	mlx_instance_t *const	walls = game->wall->instances;
	uint32_t				i;

	if (
		x < 0
		|| x >= (int32_t)game->map->width
		|| y < 0
		|| y >= (int32_t)game->map->height
	)
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
	exit_game(game, x, y);
}
