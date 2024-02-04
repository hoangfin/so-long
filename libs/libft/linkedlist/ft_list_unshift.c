/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_unshift.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 22:29:05 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:39:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"


static size_t	ft_circular_list_unshift(t_list *list, t_node *node)
{
	if (node == NULL)
		return (list->length);
	if (list->length == 0)
	{
		node->next = node;
		node->prev = node;
		list->head = node;
		list->tail = node;
		list->length++;
		return (list->length);
	}
	node->next = list->head;
	node->prev = list->tail;
	list->head->prev = node;
	list->tail->next = node;
	list->head = node;
	list->length++;
	return (list->length);
}

static size_t	ft_linear_list_unshift(t_list *list, t_node *node)
{
	if (node == NULL)
		return (list->length);
	if (list->length == 0)
	{
		list->head = node;
		list->tail = node;
		list->length++;
		return (list->length);
	}
	node->next = list->head;
	list->head->prev = node;
	list->head = node;
	list->length++;
	return (list->length);
}

/**
 * Add the specified linked node to the beginning of a linked list and return
 * the new length of the linked list.
 *
 * @returns {size_t} length
*/
size_t	ft_list_unshift(t_list *list, t_node *node)
{
	if (list->is_circular)
		return (ft_circular_list_unshift(list, node));
	return (ft_linear_list_unshift(list, node));
}
