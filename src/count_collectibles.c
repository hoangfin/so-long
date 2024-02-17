/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_collectibles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:59:36 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/17 16:45:52 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

uint32_t	count_collectibles(t_map *map)
{
	int32_t		row;
	int32_t		col;
	uint32_t	count;

	row = 1;
	count = 0;
	while (row < map->rows - 1)
	{
		col = 1;
		while (col < map->cols - 1)
		{
			if (map->grid[row][col] == 'C')
				count++;
			col++;
		}
		row++;
	}
	return (count);
}
