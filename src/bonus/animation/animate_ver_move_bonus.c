/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_ver_move_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:19:39 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/02 15:59:10 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	animate_ver_move(t_character *ch, t_sprite *spr, uint32_t spr_row)
{
	if (ch->distance_moved % 4 == 0)
	{
		put_pixel(
			ch->image,
			spr->image,
			ch->current_frame % spr->col_count * spr->frame_w,
			spr_row * spr->frame_h \
		);
		(ch->current_frame)++;
		ch->image->instances[0].y = ch->y;
	}
}