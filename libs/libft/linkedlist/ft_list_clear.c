/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:20:25 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:39:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

/**
 * The ft_list_clear() function deletes and frees the given element and every
 * successor of that element, using the function 'del' and free(3).
 *
 * @param	{t_list*}	list	The adress of a pointer to an element.
 * @param	{function}	delete	A function pointer used to delete the content
 * 								of the element.
 *
 * @returns	{void}
*/
void	ft_list_clear(t_list **list, void (*delete)(void *))
{
	t_node	*node;
	t_node	*temp;
	size_t	i;

	if ((*list)->length == 0)
		return ;
	node = (*list)->head;
	i = 0;
	while (i < (*list)->length)
	{
		if (delete != NULL)
			delete(node->data);
		temp = node->next;
		free(node);
		node = temp;
		i++;
	}
	free(*list);
	*list = NULL;
}
