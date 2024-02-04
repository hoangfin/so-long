/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:30:33 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_strrchr() function returns a pointer to the last occurrence of the
 * character c in the string s.
 *
 * @param	{char*}	s	The string to scan for int c.
 * @param	{int}	c	The look-up integer c.
 *
 * @returns	{char*}		A pointer to the matched character or NULL if the
 * 						character is not found. The terminating null byte
 * 						is considered part of the string, so that if c is
 * 						specified as '\0',this function returns a pointer
 * 						to the terminator.
*/
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)s + i);
	while (i != 0)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	if (*((unsigned char *)s + i) == (unsigned char)c)
		return ((char *)s + i);
	return (NULL);
}
