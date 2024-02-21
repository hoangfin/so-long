/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:45:38 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/21 17:49:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	loop_hook(void *param)
{
	t_game *const	game = (t_game *)param;

	if (game->state == GAME_RUNNING)
	{
		
	}
	if (game->state == GAME_EXIT)
		mlx_close_window(game->mlx);
}
