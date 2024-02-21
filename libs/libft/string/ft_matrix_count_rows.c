/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_count_rows.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:17:45 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/21 12:19:51 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

size_t	ft_matrix_count_rows(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i);
}
