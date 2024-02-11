/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:41:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/11 16:42:27 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	print_map(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (map->matrix[i] != NULL)
// 		printf("%s\n", map->matrix[i++]);
// 	printf("row: %d\n", map->rows);
// 	printf("col: %d\n", map->cols);
// 	printf("width: %d\n", map->width);
// 	printf("height: %d\n", map->height);
// }

int32_t	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc != 2)
	{
		perror(strerror(errno));
		return (EXIT_FAILURE);
	}
	if (read_map(&map, argv[1]) < 0)
	{
		perror(strerror(errno));
		return (EXIT_FAILURE);
	}
	// print_map(&map);
	// if (!is_valid_map(&map))
	// 	printf("INVALID MAP\n");
	// delete_matrix(map.matrix);
	init_game(&game, &map);

	return (EXIT_SUCCESS);
}
