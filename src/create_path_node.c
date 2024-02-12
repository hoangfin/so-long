/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:52:13 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/12 14:55:15 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_path_node	*create_path_node(t_path_node *parent, int32_t x, int32_t y)
{
	t_path_node	*node;

	node = (t_path_node *)malloc(sizeof(t_path_node));
	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->x = x;
	node->y = y;
}
