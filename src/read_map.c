/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/20 00:14:16 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_rows(const char *pathname)
{
	int		fd;
	int		row_count;
	char	*line;
	size_t	line_length;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (perror(pathname), -1);
	row_count = 0;
	while (get_next_line(fd, &line) > -1 && line != NULL)
	{
		row_count++;
		if (*line == '\0')
		{

		}
		if (line_length == 0)
			return (ft_putendl_fd("Error\nMap has empty line", 2), free(line), -1);
		free(line);
	}
	close(fd);
	return (0);
}

static int	count(const char *pathname, size_t *row_count, size_t *col_count)
{
	int		fd;
	char	*line;
	size_t	line_length;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (perror(pathname), -1);
	*row_count = 0;
	*col_count = 0;
	while (get_next_line(fd, &line) > -1 && line != NULL)
	{
		row_count++;
		line_length = ft_strlen(line);
		free(line);
		if (line_length == 0)
			return (ft_putendl_fd("Error\nMap has empty line", 2), close(fd), -1);
		if (*col_count == 0)
			*col_count = line_length;
		if (*col_count != line_length)
			return (ft_putendl_fd("Map file is not rect", 2), close(fd), -1);
	}
	close(fd);
	return (0);
}

static char	**create_matrix(const char *pathname)
{
	int		fd;
	char	**matrix;
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

t_grid	*read_map(const char *pathname)
{
	t_grid	*map;
	size_t	row_count;
	size_t	col_count;

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
	return (map);
}
