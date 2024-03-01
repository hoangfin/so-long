/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_enemies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:33:48 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/01 12:35:01 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

uint32_t	count_enemies(char **map)
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
			if (map[row][col] == 'X')
				count++;
			col++;
		}
		row++;
	}
	return (count);
}
