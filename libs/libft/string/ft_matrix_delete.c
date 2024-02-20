/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:17:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/20 17:45:41 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

void	ft_matrix_delete(char ***matrix)
{
	int	i;

	if (*matrix == NULL)
		return ;
	i = 0;
	while ((*matrix)[i] != NULL)
		free((*matrix)[i++]);
	free(*matrix);
	*matrix = NULL;
}
