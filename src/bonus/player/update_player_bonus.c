/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:22:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/26 17:57:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_player(
			t_player *player,
			double elapsed_time,
			int32_t x,
			int32_t y
)
{
	const double	velocity = 100;
	const int32_t	distance = (int32_t)(velocity * elapsed_time);

	if (player->x == end || player->y == end)
	{
		player->state = PLAYER_IDLE;
		return ;
	}
	if (player->state == PLAYER_MOVE_UP)
		player->y -= distance;
		// animate_player_idle(game, elapsed_time, 0.083);
	else if (player->state == PLAYER_MOVE_RIGHT)
		player->x += distance;
	else if (player->state == PLAYER_MOVE_DOWN)
		player->y += distance;
	else if (player->state == PLAYER_MOVE_LEFT)
		player->x -= distance;
		// animate_player_move_right(game, elapsed_time, 20, 0.083);
}
