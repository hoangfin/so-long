/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:27:55 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_memmove() function copies n bytes from memory area src to memory area
 * dest. The memory areas may overlap: copying takes place as though the bytes
 * in src are first copied into a temporary array that does not overlap src or
 * dest, and the bytes are then copied from the temporary array to dest.
 *
 * @param	{void *}	dest	The memory area pointed to by dest.
 * @param	{void *}	src		The memory area pointed to by src.
 * @param	{size_t}	n		The number of bytes from src.
 *
 * @returns	{void *}	dest	The memory area pointed to by dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0)
		return (dest);
	if (src >= dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (--n > 0)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	return (dest);
}
