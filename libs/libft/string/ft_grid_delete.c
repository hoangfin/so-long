/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:17:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/18 10:29:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

void	ft_grid_delete(char ***grid)
{
	char	**temp;

	if (grid == NULL)
		return ;
	temp = *grid;
	while (*temp != NULL)
	{
		free(*temp);
		temp++;
	}
	free(*grid);
	*grid = NULL;
}
