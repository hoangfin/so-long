/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_hor_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:19:39 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	animate_hor_move(t_character *ch, t_sprite *spr, uint32_t spr_row)
{
	const int32_t	update_rate = RENDER_PIXELS * 0.0625;

	if (ch->distance_moved % update_rate == 0)
	{
		put_pixel(
			ch->image,
			spr->image,
			ch->current_frame % spr->col_count * spr->frame_w,
			spr_row * spr->frame_h \
		);
		(ch->current_frame)++;
		ch->image->instances[0].x = ch->x;
	}
}
