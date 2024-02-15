/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:31:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/15 19:38:47 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_hook(void *param)
{
	t_game *const	game = (t_game *)param;

	printf(
		"exit_hook executed, player: %d, %d", \
		game->player->instances[0].x, \
		game->player->instances[0].y \
	);
}
