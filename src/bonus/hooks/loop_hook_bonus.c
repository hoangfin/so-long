/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:24:50 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/29 23:45:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	loop_hook(void *param)
{
	t_game *const	game = (t_game *)param;
	double			elapsed_time;

	elapsed_time = game->mlx->delta_time;
	if (game->state == GAME_RUNNING)
	{
		update_player(game->player, elapsed_time);
		update_player_ui(game->player, game->player_sprite);
		transition_enemies(game->enemies, game);
		update_enemies(game->enemies, elapsed_time);
		update_enemies_ui(game->enemies, game->enemy_sprite);
		update_collectibles(game, elapsed_time);
		// update_exit_ui()
		// handle_collision()
	}
	else if (game->state == GAME_WIN)
	{

	}
	else if (game->state == GAME_LOSE)
	{
	}
	else if (game->state == GAME_EXIT)
	{
		cleanup(game);
		mlx_close_window(game->mlx);
	}
}
