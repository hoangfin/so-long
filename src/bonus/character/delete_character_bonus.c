/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_character_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:30:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/03 20:24:59 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	delete_character(mlx_t *mlx, t_character **character)
{
	if (*character == NULL)
		return ;
	mlx_delete_image(mlx, (*character)->image);
	free(*character);
	*character = NULL;
}
