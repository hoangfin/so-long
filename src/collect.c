/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:14:22 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/15 22:00:07 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect(t_game *game, int32_t x, int32_t y)
{
	uint32_t	i;

	i = 0;
	while (i < game->collectible->count)
	{
		if (
			game->collectible->instances[i].x == x
			&& game->collectible->instances[i].y == y
			&& game->collectible->instances[i].enabled == true
		)
		{
			game->collectible->instances[i].enabled = false;
			game->collectible_count--;
			break ;
		}
		i++;
	}
	printf("collectible count = %d\n", game->collectible_count);
	if (game->collectible_count == 0)
		game->exit->enabled = true;
}