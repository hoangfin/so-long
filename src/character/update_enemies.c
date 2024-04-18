/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:22:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	update_enemy(t_character *enemy, double elapsed_time)
{
	if (enemy->is_state_changed)
	{
		enemy->is_state_changed = false;
		return ;
	}
	if (enemy->distance_moved == RENDER_PIXELS)
	{
		if (enemy->state == ENEMY_MOVE_LEFT)
			return (set_character_state(enemy, ENEMY_IDLE_LEFT));
		return (set_character_state(enemy, ENEMY_IDLE_RIGHT));
	}
	if (enemy->state == ENEMY_MOVE_UP)
		enemy->y -= RENDER_PIXELS * 0.03125;
	else if (enemy->state == ENEMY_MOVE_RIGHT)
		enemy->x += RENDER_PIXELS * 0.03125;
	else if (enemy->state == ENEMY_MOVE_DOWN)
		enemy->y += RENDER_PIXELS * 0.03125;
	else if (enemy->state == ENEMY_MOVE_LEFT)
		enemy->x -= RENDER_PIXELS * 0.03125;
	enemy->distance_moved += RENDER_PIXELS * 0.03125;
	enemy->elapsed_time += elapsed_time;
}

void	update_enemies(t_character **enemies, double elapsed_time)
{
	while (*enemies != NULL)
	{
		update_enemy(*enemies, elapsed_time);
		enemies++;
	}
}
