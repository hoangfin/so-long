/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:33:11 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/16 16:38:34 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_map(t_map *map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map->grid[i] != NULL)
		free(map->grid[i++]);
	free(map->grid);
	free(map);
}