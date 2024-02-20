/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:45:38 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/20 23:56:32 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	loop_hook(void *param)
{
	t_game *const	game = (t_game *)param;

	if (game->state == GAME_EXIT)
		mlx_close_window(game->mlx);
}
