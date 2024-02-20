/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:41:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/20 15:23:16 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	print_map(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (map->grid[i] != NULL)
// 		printf("%s\n", map->grid[i++]);
// 	printf("row: %d\n", map->rows);
// 	printf("col: %d\n", map->cols);
// 	printf("width: %d\n", map->width);
// 	printf("height: %d\n", map->height);
// }

void	print(char **map)
{
	while (*map != NULL)
	{
		printf("%s\n", *map);
		map++;
	}
}

int32_t	main(int argc, char **argv)
{
	char	**map;
	// t_game	game;

	if (argc < 2)
		return (ft_putendl_fd("Map file .ber is missing", 2), EXIT_FAILURE);
	if (argc > 2)
		return (ft_putendl_fd("Only one argument allowed", 2), EXIT_FAILURE);
	if (!ft_ends_with(argv[1], ".ber"))
		return (ft_putendl_fd("Map file must end with .ber", 2), EXIT_FAILURE);
	map = read_map(argv[1]);
	if (validate_map(map) == false)
		return (delete_map(map), EXIT_FAILURE);
	print(map);
	// if (init_game(&game, argv[1]) < 0)
	// 	return (EXIT_FAILURE);
	// print_map(game.map);
	// start_game(&game);
	// cleanup(&game);
	return (EXIT_SUCCESS);
}
