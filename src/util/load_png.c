/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:19:09 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*load_png(mlx_t *mlx, const char *path, bool resize)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (texture == NULL)
		return (NULL);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (resize == true && image->width != RENDER_PIXELS)
	{
		if (!mlx_resize_image(\
			image, \
			RENDER_PIXELS, \
			image->height * RENDER_PIXELS / image->width \
		))
		{
			mlx_delete_image(mlx, image);
			return (NULL);
		}
	}
	return (image);
}
