/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player_idle_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:05:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/25 22:18:08 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	animate_player_idle(t_game *game, double elapsed_time, double interval)
{
	t_animation *const	animation = game->player->animation;
	t_sprite *const		sprite = game->player_sprite;

	animation->elapsed_time_acc += elapsed_time;
	if (animation->elapsed_time_acc >= interval)
	{
		put_pixel(
			animation->image,
			sprite->image,
			animation->current_frame % sprite->col_count * sprite->frame_w,
			0);
		(animation->current_frame)++;
		animation->elapsed_time_acc -= interval;
	}
}
