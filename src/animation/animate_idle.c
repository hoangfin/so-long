/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_idle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 21:51:23 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	animate_idle(t_character *ch, t_sprite *spr, uint32_t spr_row)
{
	if (ch->elapsed_time >= 0.083)
	{
		put_pixel(
			ch->image,
			spr->image,
			ch->current_frame % spr->col_count * spr->frame_w,
			spr_row * spr->frame_h \
		);
		(ch->current_frame)++;
		ch->elapsed_time -= 0.083;
	}
}
