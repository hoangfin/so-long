/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 01:42:56 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:35:36 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_array.h"

void	ft_foreach(t_array *array, void (*fn)(void *, size_t, t_array *))
{
	size_t	i;
	char	*element;

	i = 0;
	if (array->length == 0 || fn == NULL)
		return ;
	element = array->elements;
	while (i < array->length)
	{
		fn(element, i, array);
		element += array->e_size;
		i++;
	}
}
