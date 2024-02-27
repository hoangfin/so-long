/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_state_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:51:10 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/27 23:41:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_player_state(t_character *player, t_character_state player_state)
{
	player->current_frame = 0;
	player->distance_acc = 0;
	player->elapsed_time_acc = 0;
	player->state = player_state;
}
