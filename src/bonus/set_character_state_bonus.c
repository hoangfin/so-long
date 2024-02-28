/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_character_state_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:51:10 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/28 22:58:05 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_character_state(t_character *ch, t_character_state state)
{
	ch->current_frame = 0;
	ch->distance_moved = 0;
	ch->distance_acc = 0;
	ch->elapsed_time_acc = 0;
	ch->state = state;
}
