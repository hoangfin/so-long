/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:19:24 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/23 20:45:50 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	cleanup(t_game *game)
{
	ft_matrix_delete(&game->map);
	delete_sprite(game->mlx, &game->player_sprite);
	delete_sprite(game->mlx, &game->enemy_sprite);
	delete_sprite(game->mlx, &game->collectible_sprite);
	mlx_delete_image(game->mlx, game->space);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->player);
	mlx_delete_image(game->mlx, game->collectible);
	mlx_delete_image(game->mlx, game->exit);
}
