/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:46:06 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:39:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

static int	map(t_list *l, t_list *nl, void *(*f)(void *), void (*d)(void *))
{
	t_node	*current_node;
	t_node	*new_node;
	void	*data;
	size_t	i;

	current_node = l->head;
	i = 0;
	while (i < l->length)
	{
		data = f(current_node->data);
		new_node = ft_list_node(data);
		if (new_node == NULL)
		{
			if (data != current_node->data)
				d(data);
			return (0);
		}
		ft_list_push(nl, new_node);
		current_node = current_node->next;
		i++;
	}
	return (1);
}

t_list	*ft_list_map(t_list *list, void *(*fn)(void *), void (*delete)(void *))
{
	t_list	*new_list;

	if (list->length == 0)
		return (NULL);
	new_list = ft_list(list->is_circular);
	if (new_list == NULL)
		return (NULL);
	if (map(list, new_list, fn, delete))
		return (new_list);
	ft_list_clear(&new_list, delete);
	return (NULL);
}
