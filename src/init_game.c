/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:30:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/13 21:01:05 by hoatran          ###   ########.fr       */
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
	if (mlx_resize_image(image, 32, 32) == false)
	{
		mlx_delete_image(mlx, image);
		return (NULL);
	}
	return (image);
}

static void	init_images(t_game *game)
{
	game->space = load_png(game->mlx, "assets/textures/space.png");
	game->wall = load_png(game->mlx, "assets/textures/wall.png");
	game->player = load_png(game->mlx, "assets/textures/player/tim0.png");
	game->collectible = load_png(game->mlx, "assets/textures/collectible.png");
	game->exit = load_png(game->mlx, "assets/textures/exit.png");
}

static void	register_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
	// mlx_resize_hook(game->mlx, resize_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);
}

int	init_game(t_game *game, const char *pathname)
{
	game->map = read_map(pathname);
	if (game->map == NULL)
	{
		delete_map(game->map);
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	game->mlx = mlx_init(game->map->width, game->map->height, "so_long", true);
	if (game->mlx == NULL)
	{
		perror(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	init_images(game);
	game->collectible_count = 0;
	game->move_count = 0;
	register_hooks(game);
	return (0);
}
