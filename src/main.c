/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:41:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/09 16:54:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int32_t	main(int argc, char **argv)
{
	char	**map;
	t_game	game;

	if (argc != 2)
	{
		perror("Error: Map file .ber is missing\n");
		return (EXIT_FAILURE);
	}
	map = parse_map(argv[1]);
	if (map == NULL)
	{
		perror(ft_strerror(errno));
		return (EXIT_FAILURE);
	}
	init_game(&game);

	return (EXIT_SUCCESS);
}
