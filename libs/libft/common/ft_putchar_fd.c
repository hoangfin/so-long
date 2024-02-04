/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:28:42 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_putchar_fd function outputs the char c to the file descriptor fd.
 *
 * @param	{char}	c	The character to output.
 * @param	{int}	fd	The file descriptor.
 *
 * @returns {int}		The number of bytes written
*/
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
