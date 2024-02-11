/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:45:24 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/11 21:18:40 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Callback function used to handle window resizing.
 *
 * @param[in] width The new width of the window.
 * @param[in] height The new height of the window.
 * @param[in] param Additional parameter to pass to the function.
 */
void	resize_hook(int32_t width, int32_t height, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	game->map->width = width;
	game->map->height = height;
	printf("map_width = %d, map_height = %d\n", game->map->width, game->map->height);
}
