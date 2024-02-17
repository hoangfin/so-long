/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/17 16:42:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_rect_and_valid_chars(char **grid, int32_t row_count)
{
	int32_t	row;
	char	*str;

	row = 0;
	while (row < row_count)
	{
		str = grid[row];
		while (*str != '\0')
		{
			if (
				*str != '0' && *str != '1' && *str != 'C'
				&& *str != 'E' && *str != 'P'
			)
				return (false);
			str++;
		}
		if (
			row + 1 < row_count
			&& ft_strlen(grid[row]) != ft_strlen(grid[row + 1])
		)
			return (false);
		row++;
	}
	return (true);
}

static bool	is_enclosed(char **grid, int32_t row_count, int32_t col_count)
{
	int32_t	i;

	i = 0;
	while (i < row_count)
	{
		if (grid[i][0] != '1' || grid[i][col_count - 1] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < col_count)
	{
		if (grid[0][i] != '1' || grid[row_count - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	has_valid_pec(char **grid, int32_t p, int32_t e, int32_t c)
{
	int32_t	row;
	int32_t	col;

	row = 0;
	while (grid[row] != NULL)
	{
		col = 0;
		while (grid[row][col] != '\0')
		{
			if (grid[row][col] == 'P')
				p++;
			if (grid[row][col] == 'C')
				c++;
			if (grid[row][col++] == 'E')
				e++;
		}
		row++;
	}
	if (p > 2 || e > 2)
		return (ft_putendl_fd("Error: Duplicate chars (exit/start)", 2), false);
	if (c < 1)
		return (false);
	return (true);
}

bool	validate(char **grid, int32_t row_count)
{
	size_t	col_count;

	if (is_rect_and_valid_chars(grid, row_count) == false)
		return (false);
	col_count = ft_strlen(grid[0]);
	if (is_enclosed(grid, row_count, col_count) == false)
		return (false);
	if (has_valid_pec(grid, 0, 0, 0) == false)
		return (false);
	// if (has_valid_path(grid, row_count, col_count) == false)
	// 	return (false);
	return (true);
}
