/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	handle_move(t_character *ch, t_game *game, t_character_state state)
{
	game->move_count++;
	set_character_state(ch, state);
}

void	transition_player(t_game *game, keys_t key)
{
	t_character *const	player = game->player;
	const int32_t		x = player->x;
	const int32_t		y = player->y;

	if (player->state == PLAYER_IDLE_LEFT || player->state == PLAYER_IDLE_RIGHT)
	{
		if (key == MLX_KEY_W && is_movable(game, x, y - RENDER_PIXELS))
			return (handle_move(player, game, PLAYER_MOVE_UP));
		if (key == MLX_KEY_D && is_movable(game, x + RENDER_PIXELS, y))
			return (handle_move(player, game, PLAYER_MOVE_RIGHT));
		if (key == MLX_KEY_S && is_movable(game, x, y + RENDER_PIXELS))
			return (handle_move(player, game, PLAYER_MOVE_DOWN));
		if (key == MLX_KEY_A && is_movable(game, x - RENDER_PIXELS, y))
			return (handle_move(player, game, PLAYER_MOVE_LEFT));
	}
}
