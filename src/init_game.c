/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:30:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/24 17:19:44 by hoatran          ###   ########.fr       */
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
	if (image->width != RENDER_PIXELS)
	{
		if (!mlx_resize_image(\
			image, \
			RENDER_PIXELS, \
			image->height * RENDER_PIXELS / image->width \
		))
		{
			mlx_delete_image(mlx, image);
			return (NULL);
		}
	}
	return (image);
}

static int	init_images(t_game *game)
{
	game->space = load_png(game->mlx, "assets/textures/space.png");
	game->wall = load_png(game->mlx, "assets/textures/wall.png");
	game->player = load_png(game->mlx, "assets/textures/player.png");
	game->collectible = load_png(\
		game->mlx, "assets/textures/collectible.png"\
	);
	game->exit = load_png(game->mlx, "assets/textures/exit.png");
	game->exit->enabled = false;
	if (mlx_errno)
		return (ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2), -1);
	return (0);
}

static void	register_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);
}

int	init_game(t_game *game, char **map)
{
	game->map = map;
	game->row_count = ft_matrix_count_rows(map);
	game->col_count = ft_strlen(map[0]);
	game->map_w = game->col_count * RENDER_PIXELS;
	game->map_h = game->row_count * RENDER_PIXELS;
	game->collectible_count = count_collectibles(game->map);
	game->move_count = 0;
	game->mlx = mlx_init(game->map_w, game->map_h, "so_long", true);
	if (game->mlx == NULL)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		return (ft_matrix_delete(&game->map), -1);
	}
	if (init_images(game) < 0)
	{
		ft_matrix_delete(&(game->map));
		mlx_close_window(game->mlx);
		return (-1);
	}
	register_hooks(game);
	return (0);
}
