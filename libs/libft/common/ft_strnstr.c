/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:23:08 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_strnstr() function locates the first occurrence of the null-terminated
 * string s2 in the string s1, where not more than n characters are searched.
 * Characters that appear after a `\0' character are not searched.
 *
 * @param	{char*}		s1	The string pointed to by s1.
 * @param	{char*}		s2	The string pointed to by s2.
 * @param	{size_t}	n	The number of searching bytes.
 *
 * @returns	{char*}			If s2 is an empty string, returns s1.
 * 							If s2 occurs nowhere in s1, returns NULL.
 * 							Otherwise a pointer to the first
 * 							character of the first occurrence of s2
 * 							is returned.
*/
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1_length;
	size_t	s2_length;

	if (*s2 == '\0')
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	i = 0;
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	if (s1_length < s2_length)
		return (NULL);
	while (i < n)
	{
		if (s2_length > n - i)
			return (NULL);
		if (ft_strncmp(s1 + i, s2, s2_length) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
