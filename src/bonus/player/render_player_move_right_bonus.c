/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player_move_right_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:19:39 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/28 17:07:08 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	render_player_move_right(t_character *player, t_sprite *sprite)
{
	if (player->distance_acc >= RENDER_PIXELS / 12)
	{
		put_pixel(
			player->image,
			sprite->image,
			player->current_frame % sprite->col_count * sprite->frame_w,
			sprite->frame_h \
		);
		(player->current_frame)++;
		player->image->instances[0].x = player->x;
		player->distance_acc -= RENDER_PIXELS / 12;
	}
}
