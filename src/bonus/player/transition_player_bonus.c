/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition_player_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/27 13:56:37 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	reset(t_character *player)
{
	player->current_frame = 0;
	player->distance_acc = 0;
	player->elapsed_time_acc = 0;
}

t_player_state	transition_player(t_character *player, keys_t key)
{
	if (player->state == PLAYER_IDLE)
	{
		if (key == MLX_KEY_W)
			return (reset(player), PLAYER_MOVE_UP);
		if (key == MLX_KEY_D)
			return (reset(player), PLAYER_MOVE_RIGHT);
		if (key == MLX_KEY_S)
			return (reset(player), PLAYER_MOVE_DOWN);
		if (key == MLX_KEY_A)
			return (reset(player), PLAYER_MOVE_LEFT);
	}
	if (player->state == PLAYER_MOVE_UP)
		return (PLAYER_MOVE_UP);
	if (player->state == PLAYER_MOVE_RIGHT)
		return (PLAYER_MOVE_RIGHT);
	if (player->state == PLAYER_MOVE_DOWN)
		return (PLAYER_MOVE_DOWN);
	if (player->state == PLAYER_MOVE_LEFT)
		return (PLAYER_MOVE_LEFT);
	return (player->state);
}
