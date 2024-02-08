/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/08 17:19:36 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**parse_map(const char *path)
{
	int		fd;
	char	*line;
	size_t	line_count;
	char	**map;

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
		//
		free(line);
		line = get_next_line(fd);
	}
	map = (char **)malloc(sizeof(char *) * line_count);
	return (map);
}
