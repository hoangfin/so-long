/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:52:19 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 00:39:30 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/**
 * Callback function used to handle window closing which is called when the
 * user attempts to close the window, for example by clicking the close widget
 * in the title bar.
 *
 * @param[in] param Additional parameter to pass to the function.
 */
void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	cleanup(game);
	mlx_close_window(game->mlx);
}
