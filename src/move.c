/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:45:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/06 11:58:17 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_wall(int32_t x, int32_t y, t_game *game)
{
	size_t			i;
	size_t			count;
	mlx_instance_t *instances;

	i = 0;
	count = game->wall->count;
	instances = game->wall->instances;
	while (i < count)
	{
		if (instances[i].x == x && instances[i].y == y)
			return (true);
		i++;
	}
}

void	move(int32_t x, int32_t y, t_game *game)
{
	// mlx_image_t	*player;

	// player = game->image.player;

}