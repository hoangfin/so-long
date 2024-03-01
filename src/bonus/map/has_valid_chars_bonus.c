/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_chars_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:58:22 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/01 10:51:24 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
