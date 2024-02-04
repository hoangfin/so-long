/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:58:40 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_substr() function allocates and returns a substring from the string
 * 's'. The substring begins at index 'start' and is of maximum size 'len'.
 *
 * @param	{char*}		s		The string from which to create the substring.
 * @param	{int}		start	The start index in the string 's'.
 * @param	{size_t}	len		The maximum length of the substring.
 *
 * @returns	{char*}				The substring or NULL if the allocation fails.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	substr_len;
	size_t	s_len;
	char	*substr;

	if (start >= ft_strlen(s))
	{
		substr = (char *)malloc(sizeof(char));
		if (substr != NULL)
			*substr = '\0';
		return (substr);
	}
	s_len = ft_strlen(s + start);
	if (len > s_len)
		substr_len = s_len;
	else
		substr_len = len;
	substr = (char *)malloc((substr_len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, (substr_len + 1));
	return (substr);
}
