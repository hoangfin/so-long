/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_some.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:04:13 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:39:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_bool	ft_list_some(t_list *list, t_bool (*pred)(void *, size_t, t_list *))
{
	size_t	i;
	t_node	*node;

	i = 0;
	node = list->head;
	while (i < list->length)
	{
		if (pred(node->data, i, list) == true)
			return (true);
		node = node->next;
		i++;
	}
	return (false);
}
