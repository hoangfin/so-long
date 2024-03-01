/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:22:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/01 17:39:56 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	update_enemy(t_character *enemy, double elapsed_time)
{
	int32_t		distance;

	if (enemy->distance_moved == RENDER_PIXELS)
	{
		if (enemy->state == ENEMY_MOVE_LEFT)
			return (set_character_state(enemy, ENEMY_IDLE_LEFT));
		return (set_character_state(enemy, ENEMY_IDLE_RIGHT));
	}
	distance = (int32_t)(enemy->velocity * elapsed_time);
	if (enemy->distance_moved + distance > RENDER_PIXELS)
		distance = RENDER_PIXELS - enemy->distance_moved;
	if (enemy->state == ENEMY_IDLE_LEFT || enemy->state == ENEMY_IDLE_RIGHT)
		distance = 0;
	else if (enemy->state == ENEMY_MOVE_UP)
		enemy->y -= distance;
	else if (enemy->state == ENEMY_MOVE_RIGHT)
		enemy->x += distance;
	else if (enemy->state == ENEMY_MOVE_DOWN)
		enemy->y += distance;
	else if (enemy->state == ENEMY_MOVE_LEFT)
		enemy->x -= distance;
	enemy->distance_moved += distance;
	enemy->distance_acc += distance;
	enemy->elapsed_time_acc += elapsed_time;
}

void	update_enemies(t_character **enemies, double elapsed_time)
{
	while (*enemies != NULL)
	{
		update_enemy(*enemies, elapsed_time);
		enemies++;
	}
}
