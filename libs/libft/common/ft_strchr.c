/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:25:49 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_strchr() function returns a pointer to the first occurrence of the
 * character c in the string s.
 *
 * @param	{char*}	s			The string to scan for int c.
 * @param	{int}	c			The look-up integer c.
 *
 * @returns	{char*}	char_ptr	A pointer to the matched character.
 * 								The terminating null byte is considered part
 * 								of the string, so that if c is specified as
 * 								'\0', this function returns a pointer to the
 * 								terminator.
 * 					NULL		is returned if the character c hasn't been
 * 								found in the string s.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*((unsigned char *)s) == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
