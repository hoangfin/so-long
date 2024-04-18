/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:00:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	if (argc < 2)
		return (ft_putendl_fd("Error\nMap file .ber is missing", 2), 1);
	if (argc > 2)
		return (ft_putendl_fd("Error\nOnly one argument allowed", 2), 1);
	if (!ft_ends_with(argv[1], ".ber"))
		return (ft_putendl_fd("Error\nMap file must end with .ber", 2), 1);
	if (is_hidden_file(argv[1]))
		return (ft_putendl_fd("Error\nMap file must have a name", 2), 1);
	map = read_map(argv[1]);
	if (map == NULL)
		return (1);
	if (validate_map(map) == false)
		return (ft_matrix_delete(&map), 1);
	if (init_game(&game, map) < 0)
		return (1);
	if (start_game(&game) < 0)
		return (cleanup(&game), 1);
	return (EXIT_SUCCESS);
}
