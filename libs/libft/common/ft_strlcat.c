/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:17:53 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_strlcat() function appends the NULL-terminated
 * string src to the end of dest. It will append at most
 * size - strlen(dest) - 1 bytes, NULL-terminating the result.
 *
 * @param	{char*}		dest	The buffer storing copied string.
 * @param	{char*}		src		The source string to copy from.
 * @param	{size_t}	size	The size of entire buffer dest.
 *
 * @returns	{size_t}	length	The total length of dest and src.
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	if (*dest == '\0')
		return (ft_strlcpy(dest, src, size));
	i = 0;
	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	while (dest[i] != '\0')
		i++;
	while (i < size - 1 && *src != '\0')
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(src));
}
