/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:30:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/08 15:53:30 by hoatran          ###   ########.fr       */
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
		perror(mlx_strerror(mlx_errno));
		cleanup(game);
		exit(EXIT_FAILURE);
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
	game->map_width = 13 * 32;
	game->map_height = 5 * 32;
	game->mlx = mlx_init(game->map_width, game->map_height, "so_long", true);
	if (game->mlx == NULL)
	{
		perror(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	init_image(game);
	game->collectible_count = 0;
	game->move_count = 0;
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);

	draw_map(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	cleanup(game);
}
