/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:49:23 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_strjoin function allocates and returns a new string, which is the
 * result of the concatenation of 's1' and 's2'.
 *
 * @param	{char*}	s1	The prefix string.
 * @param	{char*}	s2	The suffix string.
 *
 * @returns	{char*}		The new string which is the result of the concatenation
 * 						of 's1' and 's2', or NULL is returned if memory
 * 						allocation failed.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*joined_str;

	size = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
	joined_str = (char *)malloc(size);
	if (joined_str != NULL)
	{
		ft_memcpy(joined_str, s1, ft_strlen(s1));
		ft_memcpy(joined_str + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	}
	return (joined_str);
}
