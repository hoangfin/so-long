/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:30:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/23 17:19:11 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	init_images(t_game *game)
{
	game->space = load_png(game->mlx, "assets/textures/mandatory/space.png");
	game->wall = load_png(game->mlx, "assets/textures/mandatory/wall.png");
	game->player = load_png(game->mlx, "assets/textures/mandatory/player.png");
	game->clt_sprite = load_sprite(\
		game->mlx, "assets/textures/sprites/collectible.png", 7 \
	);
	game->collectible = mlx_new_image(game->mlx, 128, 128);
	put_pixel(game->collectible, game->clt_sprite->image, 0, 0);
	game->exit = load_png(game->mlx, "assets/textures/mandatory/exit.png");
	game->exit->enabled = false;
	if (mlx_errno)
		return (ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2), -1);
	return (0);
}

static void	register_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, loop_hook, game);
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
	game->state = GAME_RUNNING;
	return (0);
}
