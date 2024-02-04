/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:07:03 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The memchr() function scans the initial n bytes of the memory area
 * pointed to by s for the first instance of c. Both c and the bytes
 * of the memory area pointed to by s are interpreted as unsigned char.
 *
 * @param	{void*}		s	The memory area pointed to by s.
 * @param	{int}		c	The byte used for scanning.
 * @param	{size_t}	n	The number of bytes from s.
 *
 * @returns {void*}			The pointer to the matching byte or NULL if the
 * 							character does not occur in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((void *)((unsigned char *)s + i));
		i++;
	}
	return (NULL);
}
