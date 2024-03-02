/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_counter_ui_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:18:36 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/02 17:35:43 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	update_counter_ui(t_game *game)
{
	char	buffer[sizeof(int) * 8 + 1];
	int32_t	x;
	int32_t	y;

	if (game->move_count_img != NULL)
	{
		x = game->move_count_img->instances[0].x;
		y = game->move_count_img->instances[0].y;
		mlx_delete_image(game->mlx, game->move_count_img);
	}
	else
	{
		x = PADDING + game->text->width + 5;
		y = PADDING;
	}
	game->move_count_img = mlx_put_string(\
		game->mlx, \
		(const char *)ft_itoa(game->move_count, buffer, 10), \
		x, \
		y \
	);
}
