/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:45:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/11 21:38:52 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_game *game, int32_t x, int32_t y)
{
	mlx_instance_t	player;
	mlx_instance_t	*walls;
	uint32_t		i;

	player = game->player->instances[0];
	walls = game->wall->instances;
	if (x < 0 || x >= game->map->width || y < 0 || y >= game->map->height)
		return ;
	i = 0;
	while (i < game->wall->count)
	{
		if (walls[i].x == x && walls[i].y == y)
			return ;
		i++;
	}
	player.x += x;
	player.y += y;
	game->move_count++;
	// ft_printf("Number of movements: %u\n", game->move_count);
}
