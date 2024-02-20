/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:18:04 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/20 23:56:28 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move(game, 0, -RENDER_PIXELS);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move(game, -RENDER_PIXELS, 0);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move(game, 0, RENDER_PIXELS);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move(game, RENDER_PIXELS, 0);
}

