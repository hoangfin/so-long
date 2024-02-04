/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_shift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:35:11 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:39:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

/**
 * The ft_linkedlist_shift() function removes the first node from a linked list
 * and returns that removed node.
 *
 * This function changes the length of the linked list.
 *
 * @returns {t_node} node The node that has been removed from the linked list.
*/

static t_node	*ft_circular_list_shift(t_list *list)
{
	t_node	*detached_node;
	t_node	*new_head_node;

	if (list->length == 0)
		return (NULL);
	detached_node = list->head;
	new_head_node = list->head->next;
	detached_node->next = NULL;
	detached_node->prev = NULL;
	if (list->length == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		new_head_node->prev = list->tail;
		list->tail->next = new_head_node;
		list->head = new_head_node;
	}
	list->length--;
	return (detached_node);
}

static t_node	*ft_linear_list_shift(t_list *list)
{
	t_node	*detached_node;
	t_node	*new_head_node;

	if (list->length == 0)
		return (NULL);
	detached_node = list->head;
	new_head_node = list->head->next;
	detached_node->next = NULL;
	detached_node->prev = NULL;
	if (list->length == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		new_head_node->prev = NULL;
		list->head = new_head_node;
	}
	list->length--;
	return (detached_node);
}

t_node	*ft_list_shift(t_list *list)
{
	if (list->is_circular)
		return (ft_circular_list_shift(list));
	return (ft_linear_list_shift(list));
}
