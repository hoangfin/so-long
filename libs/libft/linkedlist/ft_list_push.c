/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:25:17 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:39:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

static size_t	ft_circular_list_push(t_list *list, t_node *node)
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
	list->tail->next = node;
	node->prev = list->tail;
	node->next = list->head;
	list->head->prev = node;
	list->tail = node;
	list->length++;
	return (list->length);
}

static size_t	ft_linear_list_push(t_list *list, t_node *node)
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
	list->tail->next = node;
	node->prev = list->tail;
	list->tail = node;
	list->length++;
	return (list->length);
}

size_t	ft_list_push(t_list *list, t_node *node)
{
	if (list->is_circular)
		return (ft_circular_list_push(list, node));
	return (ft_linear_list_push(list, node));
}
