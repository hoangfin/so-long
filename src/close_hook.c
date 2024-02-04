/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:52:19 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/04 16:21:27 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	ft_putendl_fd("You've clicked close icon at title bar", 1);
	mlx_close_window(game->mlx);
}
