/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition_enemies_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:27:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/29 23:30:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	transition_enemy(t_character *enemy, t_game *game)
{
	const int	random_state = rand() % 6 + 6;

	if (enemy->state == ENEMY_IDLE_LEFT || enemy->state == ENEMY_IDLE_RIGHT)
	{
		if (random_state == ENEMY_MOVE_UP
			&& is_movable(game, enemy->x, enemy->y - RENDER_PIXELS))
			return (set_character_state(enemy, PLAYER_MOVE_UP));
		if (random_state == ENEMY_MOVE_RIGHT
			&& is_movable(game, enemy->x + RENDER_PIXELS, enemy->y))
			return (set_character_state(enemy, PLAYER_MOVE_RIGHT));
		if (random_state == ENEMY_MOVE_DOWN
			&& is_movable(game, enemy->x, enemy->y + RENDER_PIXELS))
			return (set_character_state(enemy, PLAYER_MOVE_DOWN));
		if (random_state == ENEMY_MOVE_LEFT
			&& is_movable(game, enemy->x - RENDER_PIXELS, enemy->y))
			return (set_character_state(enemy, PLAYER_MOVE_LEFT));
	}
}

void	transition_enemies(t_character *enemies, t_game *game)
{

	t_character *enemy;

	enemy = enemies;
	while (enemy != NULL)
	{
		transition_enemy(enemy, game);
		enemy++;
	}
}
