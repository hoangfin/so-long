/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:30:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/11 17:47:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*load_png(mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (texture == NULL)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

static void	init_images(t_game *game)
{
	game->space = load_png(game->mlx, "assets/textures/space.png");
	game->wall = load_png(game->mlx, "assets/textures/wall.png");
	game->player = load_png(game->mlx, "assets/textures/player.png");
	game->collectible = load_png(game->mlx, "assets/textures/collectible.png");
	game->exit = load_png(game->mlx, "assets/textures/exit.png");
}

static void	register_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_resize_hook(game->mlx, resize_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);
}

void	init_game(t_game *game, t_map *map)
{
	game->map = map;
	game->mlx = mlx_init(map->width, map->height, "so_long", true);
	if (game->mlx == NULL)
	{
		perror(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	init_images(game);
	game->collectible_count = 0;
	game->move_count = 0;
	register_hooks(game);

	draw_map(game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	cleanup(game);
}
