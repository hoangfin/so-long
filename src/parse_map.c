/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/09 10:55:09 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	get_line_count(const char *path)
{
	int		fd;
	char	*line;
	size_t	line_count;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	line_count = 0;
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static bool	init_map(char **map, const char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
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

	map = (char **)ft_calloc(get_line_count(path) + 1, sizeof(char *));
	if (map == NULL)
	{
		perror(strerror(errno));
		exit(EXIT_FAILURE);
	}
	if (init_map(map, path) == false)
	{

	}
	return (map);
}
