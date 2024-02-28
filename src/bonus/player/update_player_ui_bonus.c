/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_ui_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:44:22 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/28 23:11:06 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_player_ui(t_character *player, t_sprite *player_sprite)
{
	if (player->state == PLAYER_IDLE)
		animate_idle(player, player_sprite, 0);
	else if (player->state == PLAYER_MOVE_UP)
		animate_ver_move(player, player_sprite, 7);
	else if (player->state == PLAYER_MOVE_RIGHT)
		animate_hor_move(player, player_sprite, 1);
	else if (player->state == PLAYER_MOVE_DOWN)
		animate_ver_move(player, player_sprite, 5);
	else if (player->state == PLAYER_MOVE_LEFT)
		animate_hor_move(player, player_sprite, 2);
}
