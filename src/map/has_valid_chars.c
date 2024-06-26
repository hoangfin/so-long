/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:58:22 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	has_valid_chars(char **map)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (
				map[row][col] != '0' && map[row][col] != '1'
				&& map[row][col] != 'C' && map[row][col] != 'E'
				&& map[row][col] != 'P' && map[row][col] != 'X'
			)
			{
				ft_putendl_fd("Error\nMap contains invalid characters", 2);
				return (false);
			}
			col++;
		}
		row++;
	}
	return (true);
}
