/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:41:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/13 20:57:13 by hoatran          ###   ########.fr       */
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
	t_game	game;

	if (argc != 2)
	{
		perror(strerror(errno));
		return (EXIT_FAILURE);
	}
	init_game(&game, argv[1]);
	start_game(&game);
	cleanup(&game);
	return (EXIT_SUCCESS);
}
