/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:41:40 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 17:03:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	print_left(char *buf, int buf_len, t_print_format pf)
{
	int	count;

	count = 0;
	if (ft_putstrchr_fd('0', pf.precision - buf_len, 1) < 0)
		return (-1);
	count += pf.precision - buf_len;
	if (write(1, buf, buf_len) < 0)
		return (-1);
	count += buf_len;
	if (count > pf.width)
		return (count);
	if (ft_putstrchr_fd(' ', pf.width - count, 1) < 0)
		return (-1);
	return (pf.width);
}

static int	print(char *data, int d_len, t_print_format pf)
{
	int	count;

	count = 0;
	if (pf.width > pf.precision)
	{
		if (pf.flag & FT_PRINTF_FLAG_ZERO)
		{
			if (ft_putstrchr_fd('0', pf.width - pf.precision, 1) < 0)
				return (-1);
		}
		else
		{
			if (ft_putstrchr_fd(' ', pf.width - pf.precision, 1) < 0)
				return (-1);
		}
		count += pf.width - pf.precision;
	}
	if (ft_putstrchr_fd('0', pf.precision - d_len, 1) < 0)
		return (-1);
	count += pf.precision - d_len;
	if (write(1, data, d_len) < 0)
		return (-1);
	count += d_len;
	return (count);
}

int	print_u(t_print_format pf, va_list args)
{
	char	arg_buf[sizeof(int) * 8 + 1];
	char	*buffer;
	int		buf_len;

	ft_utoa(va_arg(args, unsigned int), arg_buf, 10);
	buffer = arg_buf;
	if (*buffer == '0' && pf.precision == 0)
		buffer = "";
	if (*buffer == '0' && pf.has_period && pf.precision == -1)
		buffer = "";
	buf_len = (int)ft_strlen(buffer);
	if (pf.has_period)
		pf.flag &= ~FT_PRINTF_FLAG_ZERO;
	if (pf.precision == -1 || pf.precision < buf_len)
		pf.precision = buf_len;
	if (pf.flag & FT_PRINTF_FLAG_MINUS)
		return (print_left(buffer, buf_len, pf));
	return (print(buffer, buf_len, pf));
}
