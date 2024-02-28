/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_ui_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:44:22 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/28 15:31:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_player_ui(t_character *player, t_sprite *player_sprite)
{
	if (player->state == PLAYER_IDLE)
		render_player_idle(player, player_sprite);
	else if (player->state == PLAYER_MOVE_RIGHT)
		render_player_move_right(player, player_sprite);
}
