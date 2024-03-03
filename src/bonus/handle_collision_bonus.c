/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_collision_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:00:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/03 13:11:43 by hoatran          ###   ########.fr       */
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
	const int32_t	padding = RENDER_PIXELS * 0.3;
	const int32_t	player_rect[4][2] = {
		{player->x + padding, player->y + padding},
		{player->x + RENDER_PIXELS - padding, player->y + padding},
		{player->x + padding, player->y + RENDER_PIXELS - padding},
		{player->x + RENDER_PIXELS - padding, player->y + RENDER_PIXELS - padding}
	};
	int32_t			i;

	i = 0;
	while (i < 4)
	{
		if (
			player_rect[i][0] >= enemy->x + padding
			&& player_rect[i][0] <= enemy->x + RENDER_PIXELS - padding
			&& player_rect[i][1] >= enemy->y + padding
			&& player_rect[i][1] <= enemy->y + RENDER_PIXELS - padding
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
			transition_game(game, GAME_LOST);
			return ;
		}
		enemies++;
	}

}

static void	handle_escape(t_game *game)
{
	if (
		game->exit->instances[0].x == game->player->x
		&& game->exit->instances[0].y == game->player->y
		&& game->exit->enabled == true
	)
		transition_game(game, GAME_WON);

}

void	handle_collision(t_game *game)
{
	handle_collectibles(game);
	handle_enemies(game);
	handle_escape(game);
}