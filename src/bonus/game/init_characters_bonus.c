/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_characters_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:53:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/04 13:54:18 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	init_player(t_game *game)
{
	int32_t	row;
	int32_t	col;

	game->player = new_character(game->mlx, 0, 0, PLAYER_IDLE_RIGHT);
	if (game->player == NULL)
		return (-1);
	row = 0;
	while (game->map[row] != NULL)
	{
		col = 0;
		while (game->map[row][col] != '\0')
		{
			if (game->map[row][col] == 'P')
			{
				game->player->x = game->map_x + col * RENDER_PIXELS;
				game->player->y = game->map_y + row * RENDER_PIXELS;
				return (0);
			}
			col++;
		}
		row++;
	}
	return (-1);
}

static int	init_enemies(t_game *game, int32_t row, int32_t col)
{
	int32_t	i;

	i = 0;
	while (game->map[row] != NULL)
	{
		col = 0;
		while (game->map[row][col] != '\0')
		{
			if (game->map[row][col] == 'X')
			{
				game->enemies[i] = new_character(\
					game->mlx, \
					game->map_x + col * RENDER_PIXELS, \
					game->map_y + row * RENDER_PIXELS, \
					ENEMY_IDLE_RIGHT \
				);
				if (game->enemies[i] == NULL)
					return (-1);
				i++;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	init_characters(t_game *game)
{
	if (init_player(game) < 0)
		return (-1);
	game->enemies = (t_character **)ft_calloc(\
		count_enemies(game->map) + 1, sizeof(t_character *) \
	);
	if (game->enemies == NULL)
		return (-1);
	if (init_enemies(game, 0, 0) < 0)
		return (-1);
	return (0);
}
