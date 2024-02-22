/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:19:24 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/22 17:09:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	cleanup(t_game *game)
{
	ft_matrix_delete(&game->map);
	mlx_delete_image(game->mlx, game->space);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->player);
	mlx_delete_image(game->mlx, game->collectible);
	mlx_delete_image(game->mlx, game->exit);
}
