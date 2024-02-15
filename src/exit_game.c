/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 21:53:09 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/15 21:58:43 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game, int32_t x, int32_t y)
{
	if (
		game->exit->instances[0].x == x
		&& game->exit->instances[0].y == y
		&& game->exit->instances[0].enabled == true
	)
		mlx_close_window(game->mlx);
}
