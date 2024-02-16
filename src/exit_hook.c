/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:31:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/16 12:25:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_hook(void *param)
{
	t_game *const	game = (t_game *)param;

	(void *)game;
	printf("delta time: %f\n", game->mlx->delta_time);
}
