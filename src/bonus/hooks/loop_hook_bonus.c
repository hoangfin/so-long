/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:24:50 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/22 16:38:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	loop_hook(void *param)
{
	t_game *const	game = (t_game *)param;

	if (game->state == GAME_RUNNING)
	{
		// update_player_ui()
		// update_collectibles_ui()
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
