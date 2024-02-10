/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:22:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/10 17:52:58 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	is_surrounded_by_walls(t_map *map)
{
	int32_t	i;

	i = 0;
	while (i < map->row)
	{
		if (map->matrix[i][0] != '1' || map->matrix[i][map->col - 1] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->col)
	{
		if (map->matrix[0][i] != '1' || map->matrix[map->row - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_map(t_map *map)
{
	if (!is_surrounded_by_walls(map))
		return (false);
	return (true);
}
