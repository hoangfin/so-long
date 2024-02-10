/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:22:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/10 23:22:21 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_enclosed(t_map *map)
{
	int32_t	i;

	i = 0;
	while (i < map->row)
	{
		if (map->matrix[i][0] != '1' || map->matrix[i][map->col - 1] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->col)
	{
		if (map->matrix[0][i] != '1' || map->matrix[map->row - 1][i] != '1')
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
	while (row < map->row - 1)
	{
		col = 1;
		while (col < map->col - 1)
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
