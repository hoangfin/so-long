/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:15:47 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/24 15:01:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

t_sprite	*load_sprite(
				mlx_t *mlx,
				const char *pathname,
				uint32_t row_count,
				uint32_t col_count
)
{
	t_sprite		*sprite;
	mlx_texture_t	*texture;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (sprite == NULL)
		return (NULL);
	texture = mlx_load_png(pathname);
	if (texture == NULL)
	{
		free(sprite);
		return (NULL);
	}
	sprite->image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	sprite->row_count = row_count;
	sprite->col_count = col_count;
	sprite->frame_w = sprite->image->width / col_count;
	sprite->frame_h = sprite->image->height / row_count;
	return (sprite);
}