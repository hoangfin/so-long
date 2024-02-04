/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 22:19:24 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/04 15:55:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup(t_game *game)
{
	free(game->image.space);
	free(game->image.wall);
	free(game->image.player);
	free(game->image.collectible);
	free(game->image.exit);
}
