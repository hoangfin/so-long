/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:55:34 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/25 18:48:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static t_animation	*new_animation(mlx_t *mlx)
{
	t_animation	*animation;

	animation = (t_animation *)malloc(sizeof(t_animation));
	if (animation == NULL)
		return (perror("Failed to create animation"), NULL);
	animation->image = mlx_new_image(mlx, RENDER_PIXELS, RENDER_PIXELS);
	if (animation->image == NULL)
	{
		free(animation);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		return (NULL);
	}
	animation->current_frame = 0;
	animation->duration = 0;
}

int	init_player(t_game *game)
{
	int32_t	player_x;
	int32_t	player_y;

	game->player = (t_player *)malloc(sizeof(t_player));
	if (game->player == NULL)
		return (perror("Failed to initialize player"), -1);
	game->player->animation = new_animation(game->mlx);
	if (game->player->animation == NULL)
		return (free(game->player), -1);
	get_player_pos(game->map, &player_x, &player_y);
	game->player->x = game->map_x + player_x * RENDER_PIXELS;
	game->player->y = game->map_y + player_y * RENDER_PIXELS;
	game->player->state = PLAYER_IDLE;
	return (0);
}