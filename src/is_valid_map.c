/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:22:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/11 16:01:05 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_enclosed(t_map *map)
{
	int32_t	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->matrix[i][0] != '1' || map->matrix[i][map->cols - 1] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->cols)
	{
		if (map->matrix[0][i] != '1' || map->matrix[map->rows - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	has_valid_elements(t_map *map, int p, int c, int e)
{
	int	row;
	int	col;

	row = 1;
	while (row < map->rows - 1)
	{
		col = 1;
		while (col < map->cols - 1)
		{
			if (map->matrix[row][col] == 'P')
				p++;
			if (map->matrix[row][col] == 'C')
				c++;
			if (map->matrix[row][col] == 'E')
				e++;
			col++;
		}
		row++;
	}
	if (p != 1)
		return (false);
	if (e != 1)
		return (false);
	if (c < 1)
		return (false);
	return (true);
}

bool	is_valid_map(t_map *map)
{
	if (is_enclosed(map) == false)
		return (false);
	if (has_valid_elements(map, 0, 0, 0) == false)
		return (false);
	return (true);
}
