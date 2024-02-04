/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:30:19 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * Outputs the string s to the file descriptor fd.
 *
 * @param	{string}	s	The string to output.
 * @param	{int}		fd	The file descriptor.
 *
 * @returns {int}
*/
int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count += ft_putchar_fd(*s, fd);
		s++;
	}
	return (count);
}
