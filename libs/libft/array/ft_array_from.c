/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_from.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:00:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:35:36 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"

t_array	*ft_array_from(void *src_array, size_t length, size_t e_size)
{
	t_array	*array;

	array = ft_array(e_size);
	if (array == NULL)
		return (NULL);
	array->capacity = length;
	array->elements = src_array;
	array->length = length;
	array->e_size = e_size;
	return (array);
}
