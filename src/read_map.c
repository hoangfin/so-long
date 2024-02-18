/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/19 00:41:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count(const char *pathname, size_t *row_count, size_t *col_count)
{
	int		fd;
	char	*line;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (-1);
	*row_count = 0;
	*col_count = 0;
	if (get_next_line(fd, &line) < 0)
		return (close(fd), -1);
	while (line != NULL)
	{
		row_count++;
		free(line);
		if (get_next_line(fd, &line) < 0)
			return (close(fd), -1);
	}
	close(fd);
	return (0);
}

static char	**make_grid(int32_t row_count, const char *pathname)
{
	int		fd;
	char	**grid;
	char	*line;
	int		i;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (NULL);
	grid = (char **)ft_calloc(row_count + 1, sizeof(char *));
	if (grid == NULL)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		grid[i++] = ft_strdup_chr(line, '\n');
		free(line);
		line = get_next_line(fd);
	}
	grid[i] = NULL;
	close(fd);
	// if (errno)
	// 	return (NULL);
	return (grid);
}

static void	delete_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i] != NULL)
		free(grid[i++]);
	free(grid);
}

t_grid	*read_map(const char *pathname)
{
	t_grid	*map;
	size_t	row_count;
	size_t	col_count;

	if (!ft_ends_with(".ber"))
		return (NULL);
	if (count(pathname, &row_count, &col_count) < 0)
		return (NULL);
	map = ft_grid(row_count, col_count, 0);
	if (map == NULL)
		return (NULL);
	if (validate(grid, row_count) == false)
	{
		delete_grid(grid);
		return (NULL);
	}
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
	{
		delete_grid(grid);
		return (NULL);
	}

	return (map);
}
