/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_character_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:51:10 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_character_state(t_character *ch, t_character_state state)
{
	ch->current_frame = 0;
	ch->distance_moved = 0;
	ch->elapsed_time = 0;
	ch->is_state_changed = true;
	ch->state = state;
}
