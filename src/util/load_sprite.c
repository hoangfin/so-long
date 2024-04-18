/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:15:47 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	resize_sprite(
	mlx_t *mlx,
	t_sprite *sprite,
	uint32_t row_count,
	uint32_t col_count
)
{
	if (sprite->image->width / col_count != RENDER_PIXELS)
	{
		if (!mlx_resize_image(\
			sprite->image, col_count * RENDER_PIXELS, row_count * RENDER_PIXELS \
		))
		{
			mlx_delete_image(mlx, sprite->image);
			free(sprite);
			ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
			return (-1);
		}
	}
	return (0);
}

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
		ft_putendl_fd((char *)mlx_strerror(mlx_errno), 2);
		free(sprite);
		return (NULL);
	}
	sprite->image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (resize_sprite(mlx, sprite, row_count, col_count) < 0)
		return (NULL);
	sprite->row_count = row_count;
	sprite->col_count = col_count;
	sprite->frame_w = RENDER_PIXELS;
	sprite->frame_h = RENDER_PIXELS;
	return (sprite);
}
