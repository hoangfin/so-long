/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:24:50 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/26 17:57:49 by hoatran          ###   ########.fr       */
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
