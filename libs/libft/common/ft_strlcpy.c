/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:38:47 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_strlcpy() function copies the string pointed to by src.
 * If the destination buffer, limited by its size, isn't large
 * enough to hold the copy, the resulting string is truncated
 * (but it is guaranteed to be null-terminated).
 *
 * @param	{char*}		dest	The buffer storing copied string.
 * @param	{char*}		src		The source string to copy from.
 * @param	{size_t}	size	The size of entire buffer dest.
 *
 * @returns	{size_t}	length	The length of src.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (*src == '\0')
		*dest = '\0';
	else
	{
		if (size > 0)
		{
			while (i < size - 1 && src[i] != '\0')
			{
				dest[i] = src[i];
				i++;
			}
			dest[i] = '\0';
		}
	}
	return (ft_strlen(src));
}
