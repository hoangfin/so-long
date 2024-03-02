/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_collectibles_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:59:36 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/02 17:02:08 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

uint32_t	count_collectibles(char **map)
{
	int32_t		row;
	int32_t		col;
	uint32_t	count;

	row = 0;
	count = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == 'C')
				count++;
			col++;
		}
		row++;
	}
	return (count);
}
