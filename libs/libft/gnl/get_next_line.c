/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:10:59 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/08 14:50:10 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	shift_line(char **cache, char **line)
{
	char	*cur_pos;
	char	temp;

	if (*cache == NULL)
		return (0);
	cur_pos = ft_strchr(*cache, '\n');
	if (cur_pos == NULL)
		return (0);
	cur_pos++;
	temp = *cur_pos;
	*cur_pos = '\0';
	*line = ft_strdup(*cache);
	if (*line == NULL)
		return (-1);
	*cur_pos = temp;
	cur_pos = ft_strdup(cur_pos);
	if (cur_pos == NULL)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	free(*cache);
	*cache = cur_pos;
	return (1);
}

static ssize_t	flush(char *buffer, char **cache)
{
	char	*temp;

	if (*cache == NULL)
		temp = ft_strdup(buffer);
	else
		temp = ft_strjoin(*cache, buffer);
	if (temp == NULL)
		return (-1);
	free(*cache);
	*cache = temp;
	return (ft_strlen(buffer));
}

static ssize_t	update_cache_optimized(int fd, char **cache)
{
	char	buffer[256];
	ssize_t	i;
	ssize_t	bytes_read;

	i = 0;
	bytes_read = read(fd, buffer + i, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read + i] = '\0';
		if (ft_strchr(buffer + i, '\n') != NULL)
			return (flush(buffer, cache));
		i += bytes_read;
		if (i >= 255 - BUFFER_SIZE)
		{
			if (flush(buffer, cache) < 0)
				return (-1);
			i = 0;
		}
		bytes_read = read(fd, buffer + i, BUFFER_SIZE);
	}
	if (bytes_read == 0 && i > 0)
		if (flush(buffer, cache) < 0)
			return (-1);
	return (bytes_read);
}

static ssize_t	update_cache(int fd, char **cache)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (flush(buffer, cache) == -1)
		{
			free(buffer);
			return (-1);
		}
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (bytes_read);
}

/**
 * The get_next_line() function returns a line read from a file descriptor.
 *
 * @param	{int}	fd	The file descriptor.
 *
 * @returns	{char*}		Return a line read or NULL if there is nothing else
 * 						to read, or an error occurred.
*/
char	*get_next_line(int fd)
{
	static char	*caches[2048] = {NULL};
	char		*line;
	ssize_t		status;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 2047)
		return (NULL);
	if (BUFFER_SIZE < 256)
		status = update_cache_optimized(fd, &caches[fd]);
	else
		status = update_cache(fd, &caches[fd]);
	if (status < 0 || shift_line(&caches[fd], &line) == -1)
	{
		free(caches[fd]);
		caches[fd] = NULL;
		return (NULL);
	}
	if (line)
		return (line);
	if (caches[fd] && *(caches[fd]) != '\0')
		line = ft_strdup(caches[fd]);
	free(caches[fd]);
	caches[fd] = NULL;
	return (line);
}
