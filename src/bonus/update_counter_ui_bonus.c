/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_counter_ui_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:18:36 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/04 16:53:09 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
