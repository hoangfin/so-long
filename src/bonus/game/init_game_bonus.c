/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:30:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/04 01:18:44 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
		game->mlx, "assets/textures/sprites/player.png", 6, 6 \
	);
	game->enemy_sprite = load_sprite(\
		game->mlx, "assets/textures/sprites/enemy.png", 6, 6 \
	);
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

static int	init_characters(t_game *game)
{
	int32_t	row;
	int32_t	col;
	int32_t	i;

	game->player = new_character(game->mlx, 0, 0, PLAYER_IDLE_RIGHT);
	if (game->player == NULL)
		return (-1);
	game->enemies = (t_character **)ft_calloc(count_enemies(game->map) + 1, sizeof(t_character *));
	if (game->enemies == NULL)
		return (-1);
	row = 0;
	i = 0;
	while (game->map[row] != NULL)
	{
		col = 0;
		while (game->map[row][col] != '\0')
		{
			if (game->map[row][col] == 'P')
			{
				game->player->x = game->map_x + col * RENDER_PIXELS;
				game->player->y = game->map_y + row * RENDER_PIXELS;
			}
			if (game->map[row][col] == 'X')
			{
				game->enemies[i] = new_character(\
					game->mlx, \
					game->map_x + col * RENDER_PIXELS, \
					game->map_y + row * RENDER_PIXELS, \
					ENEMY_IDLE_RIGHT \
				);
				i++;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	init_game(t_game *game, char **map)
{
	init_map(game, map);
	game->mlx = mlx_init(\
		game->map_w + 2 * PADDING, \
		game->map_h + 2 * PADDING + MENUBAR_HEIGHT, "so_long", true \
	);
	if (game->mlx == NULL)
	{
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		return (ft_matrix_delete(&game->map), -1);
	}
	if (init_assets(game) < 0)
		return (cleanup(game), -1);
	if (init_characters(game) < 0)
		return (cleanup(game), -1);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, loop_hook, game);
	mlx_close_hook(game->mlx, close_hook, game);
	game->collectible_count = count_collectibles(game->map);
	game->text = NULL;
	game->lost_msg_img = NULL;
	game->move_count_img = NULL;
	game->move_count = 0;
	game->overlay = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	ft_memset(game->overlay->pixels, 0x374151cc, game->mlx->width * game->mlx->height * sizeof(int32_t));
	game->overlay->enabled = false;
	game->state = GAME_RUNNING;
	return (0);
}
