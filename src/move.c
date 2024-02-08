/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:45:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/08 00:30:47 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static bool	is_wall(int32_t x, int32_t y, t_game *game)
// {
// 	size_t			i;
// 	size_t			count;
// 	mlx_instance_t *instances;

// 	i = 0;
// 	count = game->wall->count;
// 	instances = game->wall->instances;
// 	while (i < count)
// 	{
// 		if (instances[i].x == x && instances[i].y == y)
// 			return (true);
// 		i++;
// 	}
// 	return (false);
// }

void	move(int32_t x, int32_t y, t_game *game)
{
	// mlx_image_t	*player;
	printf("x = %d, y = %d\n", x, y);
	game->player->instances[0].x += x;
	game->player->instances[0].y += y;
	printf("player's x = %d, player's y = %d\n", game->player->instances[0].x , game->player->instances[0].y);
}