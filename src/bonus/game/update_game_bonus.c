/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 12:48:01 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/03 13:01:25 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_game(t_game *game, double elapsed_time)
{
	if (game->state == GAME_RUNNING)
	{
		update_player(game->player, elapsed_time);
		update_player_ui(game->player, game->player_sprite);
		transition_enemies(game->enemies, game);
		update_enemies(game->enemies, elapsed_time);
		update_enemies_ui(game->enemies, game->enemy_sprite);
		update_collectibles(game, elapsed_time);
		update_counter_ui(game);
		// update_exit_ui()
		handle_collision(game);
	}
	else if (game->state == GAME_LOST)
	{

	}
	else if (game->state == GAME_WON)
	{
		
	}
	else if (game->state == GAME_EXIT)
	{
		cleanup(game);
		mlx_close_window(game->mlx);
	}
}
