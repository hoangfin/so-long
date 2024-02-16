/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:30:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/16 17:38:59 by hoatran          ###   ########.fr       */
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
	if (mlx_resize_image(image, RENDER_PIXELS, RENDER_PIXELS) == false)
	{
		mlx_delete_image(mlx, image);
		return (NULL);
	}
	return (image);
}

static int	init_images(t_game *game)
{
	game->space = load_png(game->mlx, "assets/textures/mandatory/space.png");
	game->wall = load_png(game->mlx, "assets/textures/mandatory/wall.png");
	game->player = load_png(game->mlx, "assets/textures/mandatory/player.png");
	game->collectible = load_png(\
		game->mlx, \
		"assets/textures/mandatory/collectible.png"\
	);
	game->exit = load_png(game->mlx, "assets/textures/mandatory/exit.png");
	game->exit->enabled = false;
	if (mlx_errno)
		return (-1);
	return (0);
}

static uint32_t	count_collectible(t_map *map)
{
	uint32_t	row;
	uint32_t	col;
	uint32_t	count;

	row = 1;
	count = 0;
	while (row < map->rows - 1)
	{
		col = 1;
		while (col < map->cols - 1)
		{
			if (map->grid[row][col] == 'C')
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

static void	register_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);
	// mlx_loop_hook(game->mlx, exit_hook, game);
}

void	init_game(t_game *game, const char *pathname)
{
	if (init_map(game, pathname) < 0)
	{
		perror("Failed to read map");
		exit(EXIT_FAILURE);
	}
	game->mlx = mlx_init(game->map->width, game->map->height, "so_long", true);
	if (game->mlx == NULL)
	{
		delete_map(game->map);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
	if (init_images(game) < 0)
	{
		cleanup(game);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
	game->collectible_count = count_collectible(game->map);
	game->move_count = 0;
	register_hooks(game);
}
