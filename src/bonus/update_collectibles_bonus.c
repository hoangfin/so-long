/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_collectibles_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:45:09 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/24 20:06:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_collectibles(void *param, double elapsed_time)
{
	static double	accumulator = 0;
	static int32_t	current_frame = 0;
	t_game *const	game = (t_game *)param;
	int32_t			frame_index;

	accumulator += elapsed_time;
	frame_index = current_frame % game->collectible_sprite->col_count;
	if (accumulator > 0.1)
	{
		put_pixel(
			game->collectible,
			game->collectible_sprite->image,
			frame_index * game->collectible_sprite->frame_w,
			0 \
		);
		current_frame++;
		accumulator -= 0.1;
	}
}
