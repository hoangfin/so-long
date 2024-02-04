/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:36:25 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

static size_t	get_total_length(const char **strings, const char *delim)
{
	size_t	i;
	size_t	total_length;
	size_t	delim_length;

	i = 0;
	total_length = 0;
	delim_length = ft_strlen(delim);
	while (strings[i] != NULL)
	{
		total_length += ft_strlen(strings[i]);
		if (strings[i + 1] != NULL)
			total_length += delim_length;
		i++;
	}
	return (total_length);
}

char	*ft_join_string(const char **strings, const char *delim)
{
	size_t	total_length;
	char	*joined_str;

	if (*strings == NULL)
		return (NULL);
	total_length = get_total_length(strings, delim);
	joined_str = (char *)ft_calloc(total_length + 1, sizeof(char));
	if (joined_str == NULL)
		return (NULL);
	while (*strings != NULL)
	{
		ft_strlcat(joined_str, *strings, total_length + 1);
		if (*(strings + 1) != NULL)
			ft_strlcat(joined_str, delim, total_length + 1);
		strings++;
	}
	return (joined_str);
}
