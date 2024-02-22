/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/22 17:09:11 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static int	count_rows(const char *pathname)
{
	int		fd;
	int		row_count;
	char	*line;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (perror(pathname), -1);
	if (errno == 2)
		errno = 0;
	row_count = 0;
	while (get_next_line(fd, &line) > -1 && line != NULL)
	{
		row_count++;
		free(line);
	}
	close(fd);
	if (errno)
		return (perror("Error\n"), -1);
	return (row_count);
}

static int	init_map(char **map, const char *pathname)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(pathname, O_RDONLY);
	if (fd < 0)
		return (perror("Error\n"), -1);
	if (errno == 2)
		errno = 0;
	i = 0;
	while (get_next_line(fd, &line) > -1 && line != NULL)
	{
		map[i] = ft_strdup_chr(line, '\n');
		free(line);
		if (map[i] == NULL)
		{
			while (i >= 0)
				free(map[i--]);
			break ;
		}
		i++;
	}
	close(fd);
	if (errno)
		return (perror("Error\n"), -1);
	return (0);
}

char	**read_map(const char *pathname)
{
	char	**map;
	int		row_count;

	row_count = count_rows(pathname);
	if (row_count < 0)
		exit(EXIT_FAILURE);
	map = (char **)ft_calloc(row_count + 1, sizeof(char *));
	if (map == NULL)
	{
		perror("Map allocation failed");
		exit(EXIT_FAILURE);
	}
	if (init_map(map, pathname) < 0)
	{
		free(map);
		exit(EXIT_FAILURE);
	}
	return (map);
}
