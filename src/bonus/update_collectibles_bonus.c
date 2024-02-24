/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_collectibles_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:45:09 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/23 20:43:44 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_collectibles(void *param)
{
	static double	accumulator = 0;
	static int		current_slice = 0;
	t_game *const	game = (t_game *)param;

	accumulator += game->mlx->delta_time;
	if (accumulator > 0.1)
	{
		put_pixel(
			game->collectible,
			game->collectible_sprite->image,
			(current_slice % game->collectible_sprite->slice_count) * 128,
			0 \
		);
		current_slice++;
		accumulator -= 0.1;
	}
	// printf("accumulator time = %f\n", accumulator);
	// put_pixel(game->collectible, game->collectible_sprite,)
}
