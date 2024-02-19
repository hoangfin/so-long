/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/19 17:42:58 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_rows(const char *pathname)
{
	int		fd;
	int		row_count;
	int		status;
	char	*line;
	size_t	line_length;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error\nCouldn't open file", 2), -1);
	status = get_next_line(fd, &line);
	if (status < 0)
		return (ft_putendl_fd("Error\nCouldn't read file", 2), -1);
	while (get_next_line(fd, &line) > -1 && line != NULL)
	{
		row_count++;

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
		return (ft_putendl_fd("Error\nCouldn't open file", 2), -1);
	*row_count = 0;
	*col_count = 0;
	while (get_next_line(fd, &line) > -1 && line != NULL)
	{
		row_count++;
		line_length = ft_strlen(line);
		if (line_length == 0)
			return (ft_putendl_fd("Error\nMap has empty line", 2), free(line), -1);
		free(line);
		if (*col_count == 0)
			*col_count = line_length;
		if (*col_count != line_length)
			return (ft_putendl_fd("Map file is not rect", 2), close(fd), -1);
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
