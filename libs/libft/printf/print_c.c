/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:41:58 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 17:03:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

int	print_c(t_print_format pf, va_list args)
{
	if (pf.width <= 1)
		return (ft_putchar_fd(va_arg(args, int), 1));
	if (pf.flag & FT_PRINTF_FLAG_MINUS)
	{
		if (ft_putchar_fd(va_arg(args, int), 1) < 0)
			return (-1);
		if (ft_putstrchr_fd(' ', pf.width - 1, 1) < 0)
			return (-1);
		return (pf.width);
	}
	if (ft_putstrchr_fd(' ', pf.width - 1, 1) < 0)
		return (-1);
	if (ft_putchar_fd(va_arg(args, int), 1) < 0)
		return (-1);
	return (pf.width);
}
