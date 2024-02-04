/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrchr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:17:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

static int	update(int bytes_written, int *counter)
{
	if (bytes_written < 0)
		return (-1);
	*counter += bytes_written;
	return (bytes_written);
}

/**
 * Outputs a series of char c to the file descriptor fd.
 *
 * @param	{int}	c	The character to output.
 * @param	{int}	n	The number of bytes to print.
 * @param	{int}		fd	The file descriptor.
 *
 * @returns {int}
*/
int	ft_putstrchr_fd(int c, int n, int fd)
{
	char	buffer[128];
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < n)
	{
		buffer[i % 128] = (char)c;
		if (i % 128 == 127)
		{
			if (update(write(fd, buffer, 128), &count) < 0)
				return (-1);
		}
		i++;
	}
	if (count < i)
	{
		if (update(write(fd, buffer, i % 128), &count) < 0)
			return (-1);
	}
	return (count);
}
