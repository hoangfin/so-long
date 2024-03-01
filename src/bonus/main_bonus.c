/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:00:29 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/01 16:14:58 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int32_t	main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	if (argc < 2)
		return (ft_putendl_fd("Map file .ber is missing", 2), EXIT_FAILURE);
	if (argc > 2)
		return (ft_putendl_fd("Only one argument allowed", 2), EXIT_FAILURE);
	if (!ft_ends_with(argv[1], ".ber"))
		return (ft_putendl_fd("Map file must end with .ber", 2), EXIT_FAILURE);
	map = read_map(argv[1]);
	if (validate_map(map) == false)
		return (ft_matrix_delete(&map), EXIT_FAILURE);
	if (init_game(&game, map) < 0)
		return (EXIT_FAILURE);
	start_game(&game);
	return (EXIT_SUCCESS);
}