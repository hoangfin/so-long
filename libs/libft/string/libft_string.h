/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:37:34 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:40:12 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

# include "../common/libft_common.h"

typedef struct s_string
{
	char	*content;
	size_t	length;
}	t_string;

t_string	*ft_string(char *str);

#endif
