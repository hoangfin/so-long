/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:15:47 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/23 17:15:33 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_sprite	*load_sprite(mlx_t *mlx, const char *path, uint32_t slice_count)
{
	t_sprite		*sprite;
	mlx_texture_t	*texture;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (sprite == NULL)
		return (NULL);
	texture = mlx_load_png(path);
	if (texture == NULL)
	{
		free(sprite);
		return (NULL);
	}
	sprite->image = mlx_texture_to_image(mlx, texture);
	sprite->slice_count = slice_count;
	mlx_delete_texture(texture);
	return (sprite);
}
