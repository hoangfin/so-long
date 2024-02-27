/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_movable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:51:15 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/27 17:13:28 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

bool	is_movable(t_game *game, int32_t x, int32_t y)
{
	mlx_instance_t *const	walls = game->wall->instances;
	uint32_t				i;

	if (
		x < game->map_x
		|| x >= game->map_w
		|| y < game->map_y
		|| y >= game->map_h
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
