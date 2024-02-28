/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:22:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/28 22:59:54 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_player(t_character *player, double elapsed_time)
{
	int32_t	distance;

	if (player->distance_moved == RENDER_PIXELS)
	{
		set_character_state(player, PLAYER_IDLE);
		return ;
	}
	distance = (int32_t)(player->velocity * elapsed_time);
	if (player->distance_moved + distance > RENDER_PIXELS)
		distance = RENDER_PIXELS - player->distance_moved;
	if (player->state == PLAYER_IDLE)
		distance = 0;
	else if (player->state == PLAYER_MOVE_UP)
		player->y -= distance;
	else if (player->state == PLAYER_MOVE_RIGHT)
		player->x += distance;
	else if (player->state == PLAYER_MOVE_DOWN)
		player->y += distance;
	else if (player->state == PLAYER_MOVE_LEFT)
		player->x -= distance;
	player->distance_moved += distance;
	player->distance_acc += distance;
	player->elapsed_time_acc += elapsed_time;
}
