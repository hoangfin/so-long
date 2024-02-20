/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:06:33 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/20 17:12:28 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	has_valid_path(char **map, size_t row_count, size_t col_count)
{

}

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

static void	dfs(char **map, int row, int col, char **visited)
{
	if (map[row][col] == 'P')
		visited[row][col] = 'P';
	else if (map[row][col] == 'E')
		visited[row][col] = 'E';
	else if (map[row][col] == 'C')
		visited[row][col] = 'C';
	else
		visited[row][col] = 'Y';
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