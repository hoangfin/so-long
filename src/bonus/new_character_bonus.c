/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_character_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:20:48 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/01 11:13:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_character	*new_character(
	mlx_t *mlx,
	int32_t x,
	int32_t y,
	t_character_state state
)
{
	t_character	*character;

	character = (t_character *)malloc(sizeof(t_character));
	if (character == NULL)
		return (perror("Failed to create character"), NULL);
	character->image = mlx_new_image(mlx, RENDER_PIXELS, RENDER_PIXELS);
	if (character->image == NULL)
	{
		free(character);
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		return (NULL);
	}
	character->x = x;
	character->y = y;
	character->velocity = (16.67 * RENDER_PIXELS / 350) / 0.01667;
	character->distance_moved = 0;
	character->distance_acc = 0;
	character->elapsed_time_acc = 0;
	character->current_frame = 0;
	character->state = state;
	return (character);
}
