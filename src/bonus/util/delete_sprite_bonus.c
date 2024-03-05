/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_sprite_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:31:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 12:19:48 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	delete_sprite(mlx_t *mlx, t_sprite **sprite)
{
	if (*sprite == NULL)
		return ;
	mlx_delete_image(mlx, (*sprite)->image);
	free(*sprite);
	*sprite = NULL;
}
