/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:24:50 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/04 23:10:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	handle_game_running(t_game *game, double elapsed_time)
{
	update_player(game->player, elapsed_time);
	update_player_ui(game->player, game->player_sprite);
	transition_enemies(game->enemies, game);
	update_enemies(game->enemies, elapsed_time);
	update_enemies_ui(game->enemies, game->enemy_sprite);
	update_collectibles(game, elapsed_time);
	update_counter_ui(game);
	handle_collision(game);
}

static void	handle_game_lost(t_game *game)
{
	if (game->lose_img->count == 0)
		mlx_image_to_window(
			game->mlx,
			game->lose_img,
			0,
			game->mlx->height / 2 - game->lose_img->height / 2 \
		);
}

static void	handle_game_won(t_game *game)
{
	if (game->win_img->count == 0)
		mlx_image_to_window(
			game->mlx,
			game->win_img,
			game->mlx->width / 2 - game->win_img->width / 2,
			game->mlx->height / 2 - game->win_img->height / 2 \
		);
}

void	loop_hook(void *param)
{
	t_game *const	game = (t_game *)param;
	const double	elapsed_time = game->mlx->delta_time;

	if (game->state == GAME_RUNNING)
		return (handle_game_running(game, elapsed_time));
	if (game->state == GAME_LOST)
		return (handle_game_lost(game));
	if (game->state == GAME_WON)
		return (handle_game_won(game));
	if (game->state == GAME_EXIT)
	{
		cleanup(game);
		mlx_close_window(game->mlx);
	}
}
