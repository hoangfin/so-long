/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 23:02:41 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:39:31 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	*ft_list(int is_circular)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list != NULL)
	{
		list->head = NULL;
		list->tail = NULL;
		list->length = 0;
		list->is_circular = is_circular;
	}
	return (list);
}
