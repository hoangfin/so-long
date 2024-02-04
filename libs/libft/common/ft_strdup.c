/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:20:11 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_strdup() function returns a pointer to a new string which
 * is a duplicate of the string s. Memory for the new string is
 * obtained with malloc(), and can be freed with free().
 *
 * @param	{char*}		s		The string to be duplicated.
 *
 * @returns	{char*}		dup		A pointer to the duplicated string.
 * 						NULL	Failed to allocate memory.
 *
*/
char	*ft_strdup(const char *s)
{
	char	*dup;

	dup = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (dup != NULL)
		ft_strlcpy(dup, s, (ft_strlen(s) + 1) * sizeof(char));
	return (dup);
}
