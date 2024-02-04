/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_every.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:52:35 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:35:36 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"

t_bool	ft_every(t_array *array, t_bool (*pred)(void *, size_t, t_array *))
{
	size_t	i;
	char	*element;

	i = 0;
	if (array->length == 0 || pred == NULL)
		return (false);
	element = array->elements;
	while (i < array->length)
	{
		if (pred(element, i, array) == false)
			return (false);
		element += array->e_size;
		i++;
	}
	return (true);
}
