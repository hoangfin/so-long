/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 23:18:04 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/04 16:21:35 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
	{
		ft_putendl_fd("You've pressed escape", 1);
		mlx_close_window(game->mlx);
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		ft_putendl_fd("You've pressed W", 1);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		ft_putendl_fd("You've pressed A", 1);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ft_putendl_fd("You've pressed S", 1);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		ft_putendl_fd("You've pressed D", 1);
}
