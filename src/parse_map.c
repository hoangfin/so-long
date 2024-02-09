/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/09 18:31:00 by hoatran          ###   ########.fr       */
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

static int	init_map(char **map, const char *path)
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
		map[i++] = ft_strdup_chr(line, '\n');
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	if (errno)
		return (-1);
	return (0);
}

static void	delete_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}

char	**parse_map(const char *path)
{
	char	**map;
	int		line_count;

	line_count = count_line(path);
	if (line_count < 0)
		return (NULL);
	map = (char **)ft_calloc(line_count + 1, sizeof(char *));
	if (map == NULL)
		return (NULL);
	if (init_map(map, path) < 0)
	{
		delete_map(map);
		return (NULL);
	}
	return (map);
}
