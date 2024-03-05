/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:19:24 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 14:02:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	delete_enemies(mlx_t *mlx, t_character **enemies)
{
	int32_t	i;

	i = 0;
	while (enemies[i] != NULL)
		delete_character(mlx, &enemies[i++]);
	free(enemies);
}

void	cleanup(t_game *game)
{
	ft_matrix_delete(&game->map);
	delete_sprite(game->mlx, &game->player_sprite);
	delete_sprite(game->mlx, &game->enemy_sprite);
	delete_sprite(game->mlx, &game->collectible_sprite);
	delete_character(game->mlx, &game->player);
	delete_enemies(game->mlx, game->enemies);
	mlx_delete_image(game->mlx, game->space);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->collectible);
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->text);
	mlx_delete_image(game->mlx, game->lose_img);
	mlx_delete_image(game->mlx, game->win_img);
	mlx_delete_image(game->mlx, game->move_count_img);
}
