/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:30:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/25 18:49:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_map(t_game *game, char **map)
{
	game->map = map;
	game->row_count = ft_matrix_count_rows(map);
	game->col_count = ft_strlen(map[0]);
	game->map_x = PADDING;
	game->map_y = PADDING + MENUBAR_HEIGHT;
	game->map_w = game->col_count * RENDER_PIXELS;
	game->map_h = game->row_count * RENDER_PIXELS;
}

static int	init_assets(t_game *game)
{
	game->space = load_png(game->mlx, "assets/textures/space.png");
	game->wall = load_png(game->mlx, "assets/textures/wall.png");
	game->player_sprite = load_sprite(\
		game->mlx, "assets/textures/sprites/player.png", 8, 6 \
	);
	/*
	game->enemy_sprite = load_sprite(\
		game->mlx, "assets/textures/sprites/enemy.png", 5, 6 \
	);
	*/
	game->collectible_sprite = load_sprite(\
		game->mlx, "assets/textures/sprites/collectible.png", 1, 7 \
	);
	game->collectible = mlx_new_image(game->mlx, RENDER_PIXELS, RENDER_PIXELS);
	game->exit = load_png(game->mlx, "assets/textures/exit.png");
	game->exit->enabled = false;
	if (mlx_errno)
		return (ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2), -1);
	return (0);
}

// static int	init_enemies(t_game *game)
// {
// 	game->player = (t_player *)malloc(sizeof(t_player));
// 	if (game->player == NULL)
// 		return (perror("Failed to initialize player"), -1);
// }

int	init_game(t_game *game, char **map)
{
	init_map(game, map);
	game->mlx = mlx_init(\
		game->map_w + 2 * PADDING,
		game->map_h + 2 * PADDING + MENUBAR_HEIGHT, "so_long", true \
	);
	if (game->mlx == NULL)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		return (ft_matrix_delete(&game->map), -1);
	}
	if (init_assets(game) < 0)
		return (cleanup(game), -1);
	if (init_player(game) < 0)
		return (cleanup(game), -1);
	// if (init_enemies(game) < 0)
	// 	return (cleanup(game), -1);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, loop_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);
	game->collectible_count = count_collectibles(game->map);
	game->move_count = 0;
	game->state = GAME_RUNNING;
	return (0);
}
