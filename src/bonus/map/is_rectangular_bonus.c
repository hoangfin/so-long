/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:50:35 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/22 17:09:11 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

bool	is_rectangular(char **map)
{
	size_t	row;

	row = 0;
	while (map[row] != NULL)
	{
		if (
			map[row + 1] != NULL
			&& ft_strlen(map[row]) != ft_strlen(map[row + 1])
		)
		{
			ft_putendl_fd("Error\nMap is not rectangular", 2);
			return (false);
		}
		row++;
	}
	return (true);
}
