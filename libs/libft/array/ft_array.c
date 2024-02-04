/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:22:41 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:35:36 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"

t_array	*ft_array(size_t e_size)
{
	t_array	*array;

	array = (t_array *)malloc(sizeof(t_array));
	if (array == NULL)
		return (NULL);
	array->capacity = 10;
	array->elements = ft_calloc(array->capacity, e_size);
	if (array->elements == NULL)
	{
		free(array);
		return (NULL);
	}
	array->length = 0;
	array->e_size = e_size;
	return (array);
}
