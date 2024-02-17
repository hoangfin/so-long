/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/17 16:49:11 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int32_t	count_rows(const char *pathname)
{
	int		fd;
	int32_t	row_count;
	char	*line;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (-1);
	row_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		row_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	// if (errno)
	// 	return (-1);
	return (row_count);
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

t_map	*read_map(const char *pathname)
{
	t_map	*map;
	int		row_count;
	char	**grid;

	row_count = count_rows(pathname);
	if (row_count < 0)
		return (NULL);
	grid = make_grid(row_count, pathname);
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
	map->grid = grid;
	map->rows = row_count;
	map->cols = ft_strlen(map->grid[0]);
	map->width = map->cols * RENDER_PIXELS;
	map->height = map->width * map->rows / map->cols;
	return (map);
}
