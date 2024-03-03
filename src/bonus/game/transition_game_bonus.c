/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition_game_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 10:15:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/03 13:15:59 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	transition_game(t_game *game, t_game_state new_state)
{
	if (game->state == GAME_RUNNING)
	{
		if (new_state == GAME_LOST)
			game->state = GAME_LOST;
		else if (new_state == GAME_WON)
			game->state = GAME_WON;
		else if (new_state == GAME_EXIT)
			game->state = GAME_EXIT;
	}
}