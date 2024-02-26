/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition_player_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/26 20:50:15 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_player_state	transition_player(t_player_state current_state, keys_t key)
{
	if (current_state == PLAYER_IDLE)
	{
		if (key == MLX_KEY_W)
			return (PLAYER_MOVE_UP);
		if (key == MLX_KEY_D)
			return (PLAYER_MOVE_RIGHT);
		if (key == MLX_KEY_S)
			return (PLAYER_MOVE_DOWN);
		if (key == MLX_KEY_A)
			return (PLAYER_MOVE_LEFT);
	}
	if (current_state == PLAYER_MOVE_UP)
		return (PLAYER_MOVE_UP);
	if (current_state == PLAYER_MOVE_RIGHT)
		return (PLAYER_MOVE_RIGHT);
	if (current_state == PLAYER_MOVE_DOWN)
		return (PLAYER_MOVE_DOWN);
	if (current_state == PLAYER_MOVE_LEFT)
		return (PLAYER_MOVE_LEFT);
	return (current_state);
}
