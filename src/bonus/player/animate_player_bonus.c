/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:05:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/27 18:00:58 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

// static void	move_up(t_character *player, t_sprite *sprite)
// {

// }

static void	move_right(t_character *player, t_sprite *sprite)
{
	if (player->distance_acc >= RENDER_PIXELS / 6)
	{
		put_pixel(
			player->image,
			sprite->image,
			++(player->current_frame) % sprite->col_count * sprite->frame_w,
			sprite->frame_h \
		);
		player->image->instances[0].x = player->x;
	}
}

// static void	move_down(t_character *player, t_sprite *sprite)
// {

// }

// static void	move_left(t_character *player, t_sprite *sprite)
// {

// }

void	animate_player(t_character *player, t_sprite *sprite)
{
	if (player->state == PLAYER_IDLE)
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
	// else if (player->state == PLAYER_MOVE_UP)
	// 	move_up(player, sprite);
	else if (player->state == PLAYER_MOVE_RIGHT)
		move_right(player, sprite);
	// else if (player->state == PLAYER_MOVE_DOWN)
	// 	move_down(player, sprite);
	// else if (player->state == PLAYER_MOVE_LEFT)
	// 	move_left(player, sprite);
}
