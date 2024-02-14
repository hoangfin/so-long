/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:41:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/14 23:51:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->matrix[i] != NULL)
		printf("%s\n", map->matrix[i++]);
	printf("row: %d\n", map->rows);
	printf("col: %d\n", map->cols);
	printf("width: %d\n", map->width);
	printf("height: %d\n", map->height);
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
	{
		ft_putendl_fd("Map file .ber is missing", 2);
		return (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_putendl_fd("Program accepts only one argument", 2);
		return (EXIT_FAILURE);
	}
	init_game(&game, argv[1]);
	print_map(game.map);
	start_game(&game);
	cleanup(&game);
	return (EXIT_SUCCESS);
}
