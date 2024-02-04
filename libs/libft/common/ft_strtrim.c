/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:04:23 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

static int	contain(char const *set, char c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static const char	*seek_left(const char *str, const char *set)
{
	while (*str != '\0')
	{
		if (!contain(set, *str))
			return (str);
		str++;
	}
	return (str);
}

static const char	*seek_right(const char *left, const char *set)
{
	const char	*right;

	if (*left == '\0')
		return (left);
	right = left;
	while (*(right + 1) != '\0')
		right++;
	while (right != left)
	{
		if (!contain(set, *right))
			return (right);
		right--;
	}
	return (right);
}

/**
 * The ft_strtrim() function allocates and returns a copy of 's1' with the
 * characters specified in 'set' removed from the beginning and the end of the
 * string.
 *
 * @param	{char*}	s1	The string to be trimmed.
 * @param	{char*}	set	The reference set of characters to trim.
 *
 * @returns	{char*}		The trimmed string or NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		length;
	char		*trim_str;
	const char	*left;
	const char	*right;
	const char	*temp;

	if (*s1 == '\0' || *set == '\0')
		return (ft_strdup(s1));
	length = 0;
	left = seek_left(s1, set);
	right = seek_right(left, set);
	temp = left;
	while (temp <= right)
	{
		length++;
		temp++;
	}
	trim_str = (char *)malloc((length + 1) * sizeof(char));
	if (trim_str != NULL)
		ft_strlcpy(trim_str, left, length + 1);
	return (trim_str);
}
