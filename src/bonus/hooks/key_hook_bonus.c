/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:18:04 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/28 14:30:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/**
 * Callback function used to handle keypresses.
 *
 * @param[in] keydata The callback data, contains info on key, action, ...
 * @param[in] param Additional parameter to pass to the function.
 */
void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		cleanup(game);
		mlx_close_window(game->mlx);
		return ;
	}
	transition_player(game, keydata.key);
}
