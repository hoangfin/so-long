/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:07:20 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/25 13:07:53 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_pos(char **map, int *row, int *col)
{
	*row = 0;
	while (map[*row] != NULL)
	{
		*col = 0;
		while (map[*row][*col] != '\0')
		{
			if (map[*row][*col] == 'P')
				return ;
			(*col)++;
		}
		(*row)++;
	}
	*row = -1;
	*col = -1;
}
