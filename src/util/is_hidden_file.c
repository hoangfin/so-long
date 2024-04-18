/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_hidden_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 18:00:20 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	is_hidden_file(char *pathname)
{
	char	*basename;

	basename = pathname;
	while (*pathname != '\0')
	{
		if (*pathname == '/')
			basename = pathname + 1;
		pathname++;
	}
	if (ft_starts_with(basename, "."))
		return (true);
	return (false);
}
