/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_idle_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:37:42 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/28 16:48:43 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	render_player_idle(t_character *player, t_sprite *sprite)
{
	if (player->elapsed_time_acc >= 0.083)
	{
		put_pixel(
			player->image,
			sprite->image,
			player->current_frame % sprite->col_count * sprite->frame_w,
			0 \
		);
		(player->current_frame)++;
		player->elapsed_time_acc -= 0.083;
	}
}
