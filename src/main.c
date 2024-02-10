/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:41:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/10 17:52:39 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->matrix[i] != NULL)
		printf("%s\n", map->matrix[i++]);
	printf("row: %d\n", map->row);
	printf("col: %d\n", map->col);
	printf("width: %d\n", map->width);
	printf("height: %d\n", map->height);
}

static void	delete_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		free(matrix[i++]);
}

int32_t	main(int argc, char **argv)
{
	t_map	map;
	// t_game	game;

	if (argc != 2)
	{
		perror(strerror(errno));
		return (EXIT_FAILURE);
	}
	if (init_map(&map, argv[1]) < 0)
	{
		perror(strerror(errno));
		return (EXIT_FAILURE);
	}
	print_map(&map);
	if (!is_valid_map(&map))
		printf("INVALID MAP");
	delete_matrix(map.matrix);
	// init_game(&game);

	return (EXIT_SUCCESS);
}
