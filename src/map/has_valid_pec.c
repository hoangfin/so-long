/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_pec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:10:51 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	has_valid_pec(char **map, int p, int e, int c)
{
	int	row;
	int	col;

	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'P')
				p++;
			if (map[row][col] == 'C')
				c++;
			if (map[row][col++] == 'E')
				e++;
		}
		row++;
	}
	if (p < 1 || e < 1)
		return (ft_putendl_fd("Error\nPlayer or exit not found", 2), false);
	if (p >= 2 || e >= 2)
		return (ft_putendl_fd("Error\nDuplicate chars (exit/start)", 2), false);
	if (c < 1)
		return (ft_putendl_fd("Error\nNo collectible found", 2), false);
	return (true);
}
