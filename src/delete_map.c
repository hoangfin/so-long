/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:33:11 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/12 22:01:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_map(t_map *map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map->matrix[i] != NULL)
		free(map->matrix[i++]);
	free(map->matrix);
	free(map);
}