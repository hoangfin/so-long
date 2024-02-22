/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_valid_pec_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:10:51 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/22 17:09:11 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	if (p > 2 || e > 2)
		return (ft_putendl_fd("Error\nDuplicate chars (exit/start)", 2), false);
	if (c < 1)
		return (ft_putendl_fd("Error\nNo collectible found", 2), false);
	return (true);
}
