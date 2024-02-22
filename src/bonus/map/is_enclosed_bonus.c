/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enclosed_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:05:14 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/22 17:09:11 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

bool	is_enclosed(char **map, size_t row_count, size_t col_count)
{
	size_t	i;

	i = 0;
	while (i < row_count)
	{
		if (map[i][0] != '1' || map[i][col_count - 1] != '1')
		{
			ft_putendl_fd("Error\nMap is not enclosed by walls", 2);
			return (false);
		}
		i++;
	}
	i = 0;
	while (i < col_count)
	{
		if (map[0][i] != '1' || map[row_count - 1][i] != '1')
		{
			ft_putendl_fd("Error\nMap is not enclosed by walls", 2);
			return (false);
		}
		i++;
	}
	return (true);
}
