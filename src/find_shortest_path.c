/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:14:13 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/12 23:45:07 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*construct_path(t_path_node *node)
{
	t_list	*path;
	t_node	*list_node;

	path = ft_list(0);
	if (path == NULL)
		return (NULL);
	while (node != NULL)
	{
		list_node = ft_list_node(node);
		if (list_node == NULL)
		{
			ft_list_clear(&path, free);
			return (NULL);
		}
		ft_list_unshift(path, list_node);
		node = node->parent;
	}
	return (path);
}

t_array	*get_neighbors(t_map *map, t_path_node *node)
{
	t_array	*neighbors;

}

t_list	*find_shortest_path(t_map *map, int32_t end_x, int32_t end_y)
{
	t_list		*queue;
	t_path_node	*current;
	t_array		*neighbors;

	queue = ft_list(0);
	// ft_list_push(queue, ft_list_node());
	while (queue->length > 0)
	{
		current = (t_path_node *)ft_list_shift(queue)->data;
		if (current->x == end_x && current->y == end_y)
			return (construct_path(current));
		neighbors = get_neighbors(map, current);
		if (neighbors != NULL)
		{

		}
		free(current);
	}

}
