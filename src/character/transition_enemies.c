/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition_enemies.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	transition_enemy(t_character *enemy, t_game *game)
{
	const int	next_state = rand() % 6 + 6;

	if (enemy->state == ENEMY_IDLE_LEFT || enemy->state == ENEMY_IDLE_RIGHT)
	{
		if (next_state == ENEMY_MOVE_UP
			&& is_movable(game, enemy->x, enemy->y - RENDER_PIXELS))
			return (set_character_state(enemy, ENEMY_MOVE_UP));
		if (next_state == ENEMY_MOVE_RIGHT
			&& is_movable(game, enemy->x + RENDER_PIXELS, enemy->y))
			return (set_character_state(enemy, ENEMY_MOVE_RIGHT));
		if (next_state == ENEMY_MOVE_DOWN
			&& is_movable(game, enemy->x, enemy->y + RENDER_PIXELS))
			return (set_character_state(enemy, ENEMY_MOVE_DOWN));
		if (next_state == ENEMY_MOVE_LEFT
			&& is_movable(game, enemy->x - RENDER_PIXELS, enemy->y))
			return (set_character_state(enemy, ENEMY_MOVE_LEFT));
	}
}

void	transition_enemies(t_character **enemies, t_game *game)
{
	while (*enemies != NULL)
	{
		transition_enemy(*enemies, game);
		enemies++;
	}
}
