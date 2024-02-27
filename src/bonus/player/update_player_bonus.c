/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:22:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/27 14:33:37 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_player(t_character *player, double elapsed_time)
{
	int32_t	distance;

	if (player->distance_acc == RENDER_PIXELS)
	{
		player->distance_acc = 0;
		player->state = PLAYER_IDLE;
		return ;
	}
	distance = (int32_t)(player->velocity * elapsed_time);
	if (player->distance_acc + distance > RENDER_PIXELS)
		distance = RENDER_PIXELS - player->distance_acc;
	if (player->state == PLAYER_MOVE_UP)
		player->y -= distance;
		// animate_player_idle(game, elapsed_time, 0.083);
	else if (player->state == PLAYER_MOVE_RIGHT)
		player->x += distance;
	else if (player->state == PLAYER_MOVE_DOWN)
		player->y += distance;
	else if (player->state == PLAYER_MOVE_LEFT)
		player->x -= distance;
	player->distance_acc += distance;
	player->elapsed_time_acc += elapsed_time;
		// animate_player_move_right(game, elapsed_time, 20, 0.083);
}
