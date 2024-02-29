/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_enemies_ui_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:44:22 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/29 23:43:22 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_enemy_ui(t_character *enemy, t_sprite *enemy_sprite)
{
	if (enemy->state == ENEMY_IDLE_LEFT)
		animate_idle(enemy, enemy_sprite, 0);
	else if (enemy->state == ENEMY_IDLE_RIGHT)
		animate_idle(enemy, enemy_sprite, 1);
	else if (enemy->state == ENEMY_MOVE_LEFT)
		animate_hor_move(enemy, enemy_sprite, 2);
	else if (enemy->state == ENEMY_MOVE_RIGHT)
		animate_hor_move(enemy, enemy_sprite, 3);
	else if (enemy->state == ENEMY_MOVE_UP)
		animate_ver_move(enemy, enemy_sprite, 4);
	else if (enemy->state == ENEMY_MOVE_DOWN)
		animate_ver_move(enemy, enemy_sprite, 5);
}

void	update_enemies_ui(t_character *enemies, t_sprite *enemy_sprite)
{
	t_character *enemy;

	enemy = enemies;
	while (enemy != NULL)
	{
		update_enemy_ui(enemy, enemy_sprite);
		enemy++;
	}
}
