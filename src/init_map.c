/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:31:57 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/16 18:39:06 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_rows(const char *pathname)
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
	if (errno)
		return (-1);
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
		map->grid[i++] = ft_strdup_chr(line, '\n');
		free(line);
		line = get_next_line(fd);
	}
	map->grid[i] = NULL;
	close(fd);
	if (errno)
		return (-1);

	return (0);
}

static char	**read_map(const char *pathname)
{
	char	**grid;
	int32_t	row_count;

	row_count = count_rows(pathname);
	(char **)ft_calloc(game->map->rows + 1, sizeof(char *));
}

int	init_map(t_game *game, const char *pathname)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	if (game->map == NULL)
		return (-1);
	game->map->grid = read_map(pathname);
	if (game->map->grid == NULL)
	{
		free(game->map);
		return (-1);
	}
	game->map->rows = count_rows(game->map->grid);
	game->map->cols = ft_strlen(game->map->grid[0]);
	game->map->width = game->map->cols * RENDER_PIXELS;
	game->map->height = game->map->width * game->map->rows / game->map->cols;
}
