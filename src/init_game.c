/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:30:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/08 00:30:06 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_image(t_game *game)
{
	mlx_texture_t	*textures[5];
	int				i;

	textures[0] = mlx_load_png("assets/textures/space.png");
	textures[1] = mlx_load_png("assets/textures/wall.png");
	textures[2] = mlx_load_png("assets/textures/player.png");
	textures[3] = mlx_load_png("assets/textures/collectible.png");
	textures[4] = mlx_load_png("assets/textures/exit.png");
	if (mlx_errno)
	{
		mlx_strerror(mlx_errno);
		printf("errno = %d\n", errno);
		return ;
	}
	game->space = mlx_texture_to_image(game->mlx, textures[0]);
	game->wall = mlx_texture_to_image(game->mlx, textures[1]);
	game->player = mlx_texture_to_image(game->mlx, textures[2]);
	game->collectible = mlx_texture_to_image(game->mlx, textures[3]);
	game->exit = mlx_texture_to_image(game->mlx, textures[4]);
	i = 0;
	while (i < 5)
		mlx_delete_texture(textures[i++]);
}

void	init_game(t_game *game)
{
	printf("errno = %d\n", errno);
	game->map_width = 13 * 32;
	game->map_height = 5 * 32;
	game->mlx = mlx_init(800, 800, "so_long", true);
	if (game->mlx == NULL)
	{
		errno = mlx_errno;
		printf("errno = %d\n", errno);
		return ;
	}
	init_image(game);
	printf("errno = %d\n", errno);
	// if (errno)
	// 	return ;
	game->collectible_count = 0;
	game->move_count = 0;
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);

	draw_map(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}
