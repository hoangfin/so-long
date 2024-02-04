/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:04:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/20 20:33:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include "../common/libft_common.h"

typedef struct s_node
{
	void			*data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	size_t	length;
	int		is_circular;
}	t_list;

t_node	*ft_list_node(void *data);
t_list	*ft_list(int is_circular);
size_t	ft_list_push(t_list *list, t_node *node);
t_node	*ft_list_shift(t_list *list);
size_t	ft_list_unshift(t_list *list, t_node *node);
void	ft_list_foreach(t_list *list, void (*fn)(void *, size_t));
void	*ft_list_reduce(
			t_list *list,
			void *(*fn)(void *, void *, size_t, t_list *),
			void *initial_value
			);
t_bool	ft_list_every(t_list *list, t_bool (*pred)(void *, size_t, t_list *));
t_bool	ft_list_some(t_list *list, t_bool (*pred)(void *, size_t, t_list *));
t_list	*ft_list_map(t_list *list, void *(*fn)(void *), void (*delete)(void *));
void	ft_list_clear(t_list **list, void (*delete)(void *));

#endif
