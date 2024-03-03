/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:22:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/02 14:44:59 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_player(t_character *player, double elapsed_time)
{
	if (player->is_state_changed)
	{
		player->is_state_changed = false;
		return ;
	}
	if (player->distance_moved == RENDER_PIXELS)
	{
		if (player->state == PLAYER_MOVE_LEFT)
			return (set_character_state(player, PLAYER_IDLE_LEFT));
		return (set_character_state(player, PLAYER_IDLE_RIGHT));
	}
	if (player->state == PLAYER_MOVE_UP)
		player->y -= 2;
	else if (player->state == PLAYER_MOVE_RIGHT)
		player->x += 2;
	else if (player->state == PLAYER_MOVE_DOWN)
		player->y += 2;
	else if (player->state == PLAYER_MOVE_LEFT)
		player->x -= 2;
	player->distance_moved += 2;
	player->elapsed_time += elapsed_time;
}
