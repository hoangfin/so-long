/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:12:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/09 18:25:00 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
