/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/10 16:46:07 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_line(const char *path)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(path, O_RDONLY);
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
	if (errno)
		return (-1);
	return (line_count);
}

static int	fill_map(t_map *map, const char *path)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(path, O_RDONLY);
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
	if (errno)
		return (-1);
	map->row = i;
	map->col = ft_strlen(map->matrix[0]);
	map->width = map->col * 32;
	map->height = map->row * 32;
	return (0);
}

static void	delete_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		free(matrix[i++]);
}

int	init_map(t_map *map, const char *path)
{
	int	line_count;

	line_count = count_line(path);
	if (line_count < 0)
		return (-1);
	map->matrix = (char **)ft_calloc(line_count + 1, sizeof(char *));
	if (map->matrix == NULL)
		return (-1);
	if (fill_map(map, path) < 0)
	{
		delete_matrix(map->matrix);
		return (-1);
	}
	return (0);
}
