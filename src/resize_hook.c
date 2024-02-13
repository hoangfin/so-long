/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:45:24 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/13 21:00:35 by hoatran          ###   ########.fr       */
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
	// t_game		*game;
	// uint32_t	canvas_width;
	// uint32_t	canvas_height;

	// game = (t_game *)param;
	(void *)param;
	(void)width;
	(void)height;
	// if (width % game->map->cols == 0)
	// 	canvas_width = width;
	// else
	// 	canvas_width = 300;
	// canvas_width = game->canvas->width;
	// canvas_height = game->canvas->height;
	// if (width >= 860)
	// 	canvas_width = 650;
	// canvas_height = canvas_width * game->map->rows / game->map->cols;
	// (void)height;
	// resize_canvas(game, canvas_width, canvas_height);
	// printf("map_width = %d, map_height = %d\n", game->map->width, game->map->height);
}
