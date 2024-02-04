/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_some.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 01:29:54 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:35:36 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"

t_bool	ft_some(t_array *array, t_bool (*pred)(void *, size_t, t_array *))
{
	size_t	i;
	char	*element;

	i = 0;
	if (pred == NULL)
		return (false);
	element = array->elements;
	while (i < array->length)
	{
		if (pred(element, i, array) == true)
			return (true);
		element += array->e_size;
		i++;
	}
	return (false);
}
