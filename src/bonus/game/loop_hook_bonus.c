/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:24:50 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/04 01:16:13 by hoatran          ###   ########.fr       */
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
	// uint32_t	current_width;
	// uint32_t	current_height;
	game->overlay->enabled = true;
	if (game->lost_msg_img == NULL)
		game->lost_msg_img = mlx_put_string(game->mlx, "You died", 100, 100);
	mlx_resize_image(\
		game->lost_msg_img, \
		320, \
		80 \
	);
	printf("handle_game_lost\n");
	// current_width = game->lost_msg_img->width;
	// current_height = game->lost_msg_img->height;
	// if (current_width >= 250)
	// 	return ;

	/*
	mlx_resize_image(\
		game->lost_msg_img, \
		current_width * 3 * elapsed_time, \
		current_height * 3 * elapsed_time \
	);
	*/
}

// static void	handle_game_won(t_game *game, double elapsed_time)
// {

// }

void	loop_hook(void *param)
{
	t_game *const	game = (t_game *)param;
	const double	elapsed_time = game->mlx->delta_time;

	if (game->state == GAME_RUNNING)
		return (handle_game_running(game, elapsed_time));
	if (game->state == GAME_LOST)
		return (handle_game_lost(game));
	// if (game->state == GAME_WON)
	// 	return (handle_game_won(game, elapsed_time));
}
