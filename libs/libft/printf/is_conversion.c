/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:14:12 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 17:03:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	is_conversion(char c)
{
	const char	*conversion = SUP_CONVERSIONS;

	while (*conversion != '\0')
	{
		if (*conversion == c)
			return (1);
		conversion++;
	}
	return (0);
}
