/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 23:13:38 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/18 16:17:30 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player_position(t_grid *grid, int32_t *row, int32_t *col)
{
	*row = 0;
	while (*row < grid->row_count)
	{
		*col = 0;
		while (*col < grid->col_count)
		{
			if (grid->matrix[*row][*col] == 'P')
				return ;
			(*col)++;
		}
		(*row)++;
	}
	*row = -1;
	*col = -1;
}

static void	dfs(t_grid *grid, int32_t row, int32_t col, t_grid *visited)
{
	if (grid->matrix[row][col] == 'P')
		visited->matrix[row][col] = 'P';
	else if (grid->matrix[row][col] == 'E')
		visited->matrix[row][col] = 'E';
	else if (grid->matrix[row][col] == 'C')
		visited->matrix[row][col] = 'C';
	else
		visited->matrix[row][col] = 'Y';
	if (col - 1 >= 0 && col - 1 < grid->col_count && grid->matrix[row][col - 1] != '1')
		dfs(grid, row, col - 1, visited);
	if (col + 1 >= 0 && col + 1 < grid->col_count && grid->matrix[row][col + 1] != '1')
		dfs(grid, row, col + 1, visited);
	if (row - 1 >= 0 && row - 1 < grid->row_count && grid->matrix[row - 1][col] != '1')
		dfs(grid, row - 1, col, visited);
	if (row + 1 >= 0 && row + 1 < grid->row_count && grid->matrix[row + 1][col] != '1')
		dfs(grid, row + 1, col, visited);
}

bool	has_valid_path(t_grid *grid)
{
	t_grid	*visited;
	int32_t	start_row;
	int32_t	start_col;

	visited = ft_grid(grid->row_count, grid->col_count, '.');
	if (visited == NULL)
		return (false);
	get_player_position(grid, &start_row, &start_col);
	dfs(grid, start_row, start_col, visited);
	ft_grid_print(visited);
	ft_grid_delete(&visited);
	return (false);
}

int	main(void)
{
	t_grid	*visited;
	size_t	i;

	visited = ft_grid(13, 6, 'X');
	i = 0;
	while (i < visited->row_count)
		printf("%s\n", visited->matrix[i++]);
	return (0);
}