/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_printf_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:27:34 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 17:03:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

t_print_flag	get_printf_flag(char c)
{
	if (c == '#')
		return (FT_PRINTF_FLAG_HASH);
	else if (c == ' ')
		return (FT_PRINTF_FLAG_SPACE);
	else if (c == '+')
		return (FT_PRINTF_FLAG_PLUS);
	else if (c == '-')
		return (FT_PRINTF_FLAG_MINUS);
	else if (c == '0')
		return (FT_PRINTF_FLAG_ZERO);
	else
		return (0);
}
