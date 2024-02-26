/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:22:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/25 22:17:26 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	update_player(t_game *game, double elapsed_time)
{
	if (game->player->state == PLAYER_IDLE)
	{
		animate_player_idle(game, elapsed_time, 0.083);
	}
}
