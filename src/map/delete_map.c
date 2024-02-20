/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:33:11 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/20 15:36:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	delete_map(char ***map)
{
	int	i;

	if (*map == NULL)
		return ;
	i = 0;
	while ((*map)[i] != NULL)
		free((*map)[i++]);
	free(*map);
	*map = NULL;
}
