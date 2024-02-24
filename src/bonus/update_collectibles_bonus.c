/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_collectibles_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:45:09 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/24 18:16:27 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_collectibles(void *param, double elapsed_time)
{
	static double	accumulator = 0;
	static int		current_frame = 0;
	t_game *const	game = (t_game *)param;

	accumulator += elapsed_time;
	if (accumulator > 0.1)
	{
		put_pixel(
			game->collectible,
			game->collectible_sprite->image,
			(current_frame % game->collectible_sprite->col_count) * 128,
			0 \
		);
		current_frame++;
		accumulator -= 0.1;
	}
	printf("update_collectibles\n");
}
