/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition_player_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/02 17:11:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	transition_player(t_game *game, keys_t key)
{
	t_character *const	player = game->player;

	if (player->state == PLAYER_IDLE_LEFT || player->state == PLAYER_IDLE_RIGHT)
	{
		if (key == MLX_KEY_W
			&& is_movable(game, player->x, player->y - RENDER_PIXELS))
		{
			game->move_count++;
			return (set_character_state(player, PLAYER_MOVE_UP));
		}
		if (key == MLX_KEY_D
			&& is_movable(game, player->x + RENDER_PIXELS, player->y))
		{
			game->move_count++;
			return (set_character_state(player, PLAYER_MOVE_RIGHT));
		}
		if (key == MLX_KEY_S
			&& is_movable(game, player->x, player->y + RENDER_PIXELS))
		{
			game->move_count++;
			return (set_character_state(player, PLAYER_MOVE_DOWN));
		}
		if (key == MLX_KEY_A
			&& is_movable(game, player->x - RENDER_PIXELS, player->y))
		{
			game->move_count++;
			return (set_character_state(player, PLAYER_MOVE_LEFT));
		}
	}
}
