/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:02:09 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_memcmp() function compares the first n bytes (each interpreted as
 * unsigned char) of the memory areas s1 and s2.
 *
 * @param	{void*}		s1		The memory area pointed to by s1.
 * @param	{void*}		s2		The memory area pointed to by s2.
 * @param	{size_t}	n		The number of bytes to compare.
 *
 * @returns	{int}		diff	n = 0: diff = 0.
 * 								n ≠ 0: diff can be equal to, less than or
 * 								or greater than 0 if the first n bytes of
 * 								s1 is found, respectively, to be less than,
 * 								to match, or be greater than the first
 * 								n bytes of s2. For a nonzero return value,
 * 								the sign is determined by the sign of the
 * 								difference between the first pair of bytes
 * 								(interpreted as unsigned char) that differ
 * 								in s1 and s2.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		diff;

	if (n == 0)
		return (0);
	i = 1;
	diff = *((unsigned char *)s1) - *((unsigned char *)s2);
	while (i < n && diff == 0)
	{
		diff = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		i++;
	}
	return (diff);
}
