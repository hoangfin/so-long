/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reduce.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:03:24 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/20 20:30:32 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	*ft_list_reduce(
	t_list *list,
	void *(*fn)(void *, void *, size_t, t_list *),
	void *initial_value
)
{
	size_t	i;
	void	*result;
	t_node	*node;

	i = 0;
	result = initial_value;
	node = list->head;
	while (i < list->length)
	{
		result = fn(result, node->data, i, list);
		node = node->next;
		i++;
	}
	return (result);
}
