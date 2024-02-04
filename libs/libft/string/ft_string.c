/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:40:34 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:40:28 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

t_string	*ft_string(char *str)
{
	t_string	*string;

	string = (t_string *)malloc(sizeof(t_string));
	if (string != NULL)
	{
		string->content = str;
		string->length = ft_strlen(str);
	}
	return (string);
}
