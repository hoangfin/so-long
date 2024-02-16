/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:22:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/16 16:38:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_rect(t_map *map)
{
	uint32_t	row;

	row = 0;
	while (row < map->rows)
	{
		if (
			row + 1 < map->rows
			&& ft_strlen(map->grid[row]) != ft_strlen(map->grid[row + 1])
		)
			return (false);
		row++;
	}
	return (true);
}

static bool	has_valid_chars(t_map *map)
{
	uint32_t	row;
	uint32_t	col;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			if (
				map->grid[row][col] != '0'
				&& map->grid[row][col] != '1'
				&& map->grid[row][col] != 'C'
				&& map->grid[row][col] != 'E'
				&& map->grid[row][col] != 'P'
			)
				return (false);
		}
		row++;
	}
	return (true);
}

static bool	is_enclosed(t_map *map)
{
	uint32_t	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->cols - 1] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->cols)
	{
		if (map->grid[0][i] != '1' || map->grid[map->rows - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	has_valid_elements(t_map *map, int p, int c, int e)
{
	uint32_t	row;
	uint32_t	col;

	row = 1;
	while (row < map->rows - 1)
	{
		col = 1;
		while (col < map->cols - 1)
		{
			if (map->grid[row][col] == 'P')
				p++;
			if (map->grid[row][col] == 'C')
				c++;
			if (map->grid[row][col] == 'E')
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
	if (is_rect(map) == false)
		return (false);
	if (has_valid_chars(map) == false)
		return (false);
	if (is_enclosed(map) == false)
		return (false);
	if (has_valid_elements(map, 0, 0, 0) == false)
		return (false);
	return (true);
}
