/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:09:30 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 17:03:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	is_flag(char c)
{
	const char	*flag = SUP_FLAGS;

	while (*flag != '\0')
	{
		if (*flag == c)
			return (1);
		flag++;
	}
	return (0);
}
