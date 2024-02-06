/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:41:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/06 21:07:30 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// const char	*error_message = NULL;

int32_t main(void)
{
	t_game	game;

	// if (argc != 2)
	// {
	// 	perror("Error: Map file .ber is missing\n");
	// 	return (EXIT_FAILURE);
	// }
	// map = parse(argv[1]);
	init_game(&game);
	if (errno)
	{
		perror(get_error_msg(errno));
		cleanup(&game);
		return (EXIT_FAILURE);
	}
	cleanup(&game);
	// mlx_t *mlx = mlx_init(500, 500, "so_long", true);
	// mlx_texture_t *texture = mlx_load_png("./assets/textures/collectible.png");
	// if (mlx_errno)
	// {
	// 	perror(mlx_strerror(mlx_errno));
	// 	return (EXIT_FAILURE);
	// }
	// mlx_image_t *image = mlx_texture_to_image(mlx, texture);
	// mlx_resize_image(image, 32, 32);
	// mlx_image_to_window(mlx, image, 0, 0);

	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
