/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collision_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:00:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/02 23:43:41 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	handle_collectibles(t_game *game)
{
	uint32_t	i;

	i = 0;
	while (i < game->collectible->count)
	{
		if (
			game->collectible->instances[i].x == game->player->x
			&& game->collectible->instances[i].y == game->player->y
			&& game->collectible->instances[i].enabled == true
		)
		{
			game->collectible->instances[i].enabled = false;
			game->collectible_count--;
			break ;
		}
		i++;
	}
	if (game->collectible_count == 0)
		game->exit->enabled = true;
}

static bool	has_collision(t_character *player, t_character *enemy)
{
	const int32_t	player_rect[4][2] = {
		{player->x, player->y},
		{player->x + (int32_t)player->image->width, player->y},
		{player->x, player->y + (int32_t)player->image->height},
		{
			player->x + (int32_t)player->image->width,
			player->y + (int32_t)player->image->height
		}
	};
	int32_t			i;

	i = 0;
	while (i < 4)
	{
		if (
			player_rect[i][0] >= enemy->x
			&& player_rect[i][0] <= enemy->x + (int32_t)enemy->image->width
			&& player_rect[i][1] >= enemy->y
			&& player_rect[i][1] <= enemy->y + (int32_t)enemy->image->height
		)
			return (true);
		i++;
	}
		return (false);
}

static void	handle_enemies(t_game *game)
{
	t_character		**enemies;

	enemies = game->enemies;
	while (*enemies != NULL)
	{
		if (has_collision(game->player, *enemies))
		{
			set_game_state(game, GAME_LOST);
			return ;
		}
		enemies++;
	}

}

static void	handle_exit(t_game *game)
{
	if (
		game->exit->instances[0].x == game->player->x
		&& game->exit->instances[0].y == game->player->y
		&& game->exit->enabled == true
	)
		game->state = GAME_WON;
}

void	handle_collision(t_game *game)
{
	handle_collectibles(game);
	handle_enemies(game);
	handle_exit(game);
}