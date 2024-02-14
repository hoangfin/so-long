/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/14 15:31:56 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_line(const char *pathname)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	// if (errno)
	// 	return (-1);
	return (line_count);
}

static int	fill_map(t_map *map, const char *pathname)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	i = 0;
	while (line != NULL)
	{
		map->matrix[i++] = ft_strdup_chr(line, '\n');
		free(line);
		line = get_next_line(fd);
	}
	map->matrix[i] = NULL;
	close(fd);
	// if (errno)
	// 	return (-1);
	map->rows = i;
	map->cols = ft_strlen(map->matrix[0]);
	map->width = map->cols * 32;
	map->height = map->width * map->rows / map->cols;
	return (0);
}

t_map	*read_map(const char *pathname)
{
	t_map	*map;
	int		line_count;

	line_count = count_line(pathname);
	if (line_count < 0)
		return (NULL);
	map = (t_map *)malloc(sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->matrix = (char **)ft_calloc(line_count + 1, sizeof(char *));
	if (map->matrix == NULL)
	{
		free(map);
		return (NULL);
	}
	if (fill_map(map, pathname) < 0)
	{
		delete_map(map);
		return (NULL);
	}
	return (map);
}
