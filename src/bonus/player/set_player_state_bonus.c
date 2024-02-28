/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_state_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:51:10 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/28 16:37:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	set_player_state(t_character *player, t_character_state state)
{
	player->current_frame = 0;
	player->distance_moved = 0;
	player->distance_acc = 0;
	player->elapsed_time_acc = 0;
	player->state = state;
}
