/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:00:33 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:11:08 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_ARRAY_H
# define LIBFT_ARRAY_H

# include "../common/libft_common.h"

typedef struct s_array
{
	void	*elements;
	size_t	length;
	size_t	e_size;
	size_t	capacity;
}	t_array;

t_array	*ft_array(size_t e_size);
t_array	*ft_array_from(void *src_array, size_t length, size_t e_size);
void	ft_foreach(t_array *array, void (*fn)(void *, size_t, t_array *));
t_bool	ft_some(t_array *array, t_bool (*pred)(void *, size_t, t_array *));
t_bool	ft_every(t_array *array, t_bool (*pred)(void *, size_t, t_array *));

#endif