/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:41:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/09 23:06:30 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		printf("%s\n", map[i++]);
}

static void	delete_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

int32_t	main(int argc, char **argv)
{
	char	**map;
	// t_game	game;

	if (argc != 2)
	{
		perror("Error: Map file .ber is missing\n");
		return (EXIT_FAILURE);
	}
	map = parse_map(argv[1]);
	if (map == NULL)
	{
		perror(strerror(errno));
		return (EXIT_FAILURE);
	}
	print_map(map);
	delete_map(map);
	// init_game(&game);

	return (EXIT_SUCCESS);
}
