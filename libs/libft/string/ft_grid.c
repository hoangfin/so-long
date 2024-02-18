/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 01:26:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/18 11:14:49 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

static char	**create_matrix(size_t rows, size_t cols, int c)
{
	char	**grid;
	size_t	i;

	grid = (char **)malloc((rows + 1) * sizeof(char *));
	if (grid == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		grid[i] = (char *)ft_calloc(cols + 1, sizeof(char));
		if (grid[i] == NULL)
		{
			while (i > 0)
				free(grid[i--]);
			free(grid[i]);
			free(grid);
			return (NULL);
		}
		ft_memset(grid[i], c, cols);
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

t_grid	*ft_grid(size_t rows, size_t cols, int c)
{
	t_grid	*grid;

	grid = (t_grid *)malloc(sizeof(t_grid));
	if (grid == NULL)
		return (NULL);
	grid->matrix = create_matrix(rows, cols, c);
	if (grid->matrix == NULL)
	{
		free(grid);
		return (NULL);
	}
	grid->row_count = rows;
	grid->col_count = cols;
	return (grid);
}
