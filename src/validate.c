/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/17 00:14:41 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_rect(char **grid, size_t row_count)
{
	uint32_t	row;

	row = 0;
	while (row < row_count)
	{
		if (
			row + 1 < row_count
			&& ft_strlen(grid[row]) != ft_strlen(grid[row + 1])
		)
			return (false);
		row++;
	}
	return (true);
}

static bool	has_valid_chars(char **grid, row_count, col_count)
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

static bool	is_enclosed(grid, row_count, col_count)
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

bool	validate(char **grid, size_t row_count)
{
	size_t	col_count;

	if (is_rect(grid, row_count) == false)
		return (false);
	col_count = ft_strlen(grid[0]);
	if (has_valid_chars(grid, row_count, col_count) == false)
		return (false);
	if (is_enclosed(grid, row_count, col_count) == false)
		return (false);
	if (has_valid_elements(grid, 0, 0, 0) == false)
		return (false);
	return (true);
}
