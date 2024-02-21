/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 01:26:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/21 21:08:39 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	**ft_matrix(size_t row_count, size_t col_count, int c)
{
	char	**matrix;
	size_t	i;

	matrix = (char **)ft_calloc(row_count + 1, sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	i = 0;
	while (i < row_count)
	{
		matrix[i] = (char *)ft_calloc(col_count + 1, sizeof(char));
		if (matrix[i] == NULL)
		{
			while (i > 0)
				free(matrix[i--]);
			free(matrix[i]);
			free(matrix);
			return (NULL);
		}
		ft_memset(matrix[i], c, col_count);
		i++;
	}
	return (matrix);
}
