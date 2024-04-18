/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_counter_ui.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:18:36 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_counter_ui(t_game *game)
{
	char	buffer[sizeof(int) * 8 + 1];

	if (game->move_count_img == NULL)
	{
		game->move_count_img = mlx_put_string(\
			game->mlx, \
			(const char *)ft_itoa(game->move_count, buffer, 10), \
			175, \
			PADDING \
		);
		return ;
	}
	mlx_delete_image(game->mlx, game->move_count_img);
	game->move_count_img = mlx_put_string(\
		game->mlx, \
		(const char *)ft_itoa(game->move_count, buffer, 10), \
		175, \
		PADDING \
	);
}
