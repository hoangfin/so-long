/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:12:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/09 21:18:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/libft_common.h"

char	*ft_strdup_chr(char *source, char delimiter)
{
	size_t	length;
	char	*dup;

	length = 0;
	while (source[length] != '\0' && source[length] != delimiter)
		length++;
	dup = (char *)malloc((length + 1) * sizeof(char));
	length = 0;
	while (source[length] != '\0' && source[length] != delimiter)
	{
		dup[length] = source[length];
		length++;
	}
	dup[length] = '\0';
	return (dup);
}
