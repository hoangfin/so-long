/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:17:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/18 11:20:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

void	ft_grid_delete(t_grid **grid)
{
	char	**temp;

	if (*grid == NULL)
		return ;
	temp = (*grid)->matrix;
	while (*temp != NULL)
	{
		free(*temp);
		temp++;
	}
	free((*grid)->matrix);
	free(*grid);
	*grid = NULL;
}
