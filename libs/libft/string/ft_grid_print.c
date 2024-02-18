/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:12:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/18 16:16:47 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

void	ft_grid_print(t_grid *grid)
{
	size_t	row;

	row = 0;
	while (row < grid->row_count)
		ft_putendl_fd(grid->matrix[row++], 1);
}
