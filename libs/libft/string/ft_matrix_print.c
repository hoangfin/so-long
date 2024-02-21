/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:53:09 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/21 11:56:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

void	ft_matrix_print(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		ft_putendl_fd(matrix[i++], 1);
}
