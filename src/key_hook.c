/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:18:04 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/05 23:20:41 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		move(0, -32, game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		move(-32, 0, game);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		move(0, 32, game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		move(32, 0, game);
}
