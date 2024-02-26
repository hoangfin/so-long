/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_player_move_right_bonus copy.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:05:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/26 12:18:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	animate_player_move_right(
			t_game *game,
			double elapsed_time,
			double velocity,
			double interval
)
{
	t_animation *const	animation = game->player->animation;
	t_sprite *const		sprite = game->player_sprite;

	animation->elapsed_time_acc += elapsed_time;
	game->player->x += velocity * elapsed_time;
	if (animation->elapsed_time_acc >= interval)
	{
		put_pixel(
			animation->image,
			sprite->image,
			animation->current_frame % sprite->col_count * sprite->frame_w,
			0 \
		);
		animation->image->instances[0].x = game->player->x;
		(animation->current_frame)++;
		animation->elapsed_time_acc -= interval;
	}
}
