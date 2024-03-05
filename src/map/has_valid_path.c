/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:06:33 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 16:28:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	get_player_position(char **map, int *row, int *col)
{
	*row = 0;
	while (map[*row] != NULL)
	{
		*col = 0;
		while (map[*row][*col] != '\0')
		{
			if (map[*row][*col] == 'P')
				return ;
			(*col)++;
		}
		(*row)++;
	}
	*row = -1;
	*col = -1;
}

static bool	is_valid_move(char **map, int row, int col)
{
	int	row_count;
	int	col_count;

	row_count = 0;
	while (map[row_count] != NULL)
		row_count++;
	col_count = ft_strlen(map[0]);
	if (row < 0 || row >= row_count || col < 0 || col >= col_count)
		return (false);
	if (map[row][col] == '1')
		return (false);
	return (true);
}

static void	dfs(char **map, int row, int col, char **visited)
{
	static const int	directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int					i;
	int					next_row;
	int					next_col;

	visited[row][col] = map[row][col];
	i = 0;
	while (i < 4)
	{
		next_row = row + directions[i][0];
		next_col = col + directions[i][1];
		if (
			is_valid_move(map, next_row, next_col)
			&& visited[next_row][next_col] == '.'
		)
			dfs(map, next_row, next_col, visited);
		i++;
	}
}

static uint32_t	count_exit(char **map)
{
	int32_t		row;
	int32_t		col;
	uint32_t	count;

	row = 0;
	count = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'E')
				count++;
			col++;
		}
		row++;
	}
	return (count);
}

bool	has_valid_path(char **map, size_t row_count, size_t col_count)
{
	char	**visited;
	int		start_row;
	int		start_col;

	visited = ft_matrix(row_count, col_count, '.');
	if (visited == NULL)
		return (perror("Error\n"), false);
	get_player_position(map, &start_row, &start_col);
	dfs(map, start_row, start_col, visited);
	if (
		count_collectibles(map) != count_collectibles(visited)
		|| count_exit(visited) != 1
	)
		return (ft_putendl_fd("Error\nMap has invalid path", 2), false);
	ft_matrix_print(visited);
	ft_matrix_delete(&visited);
	return (true);
}
