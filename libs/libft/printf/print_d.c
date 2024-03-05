/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:16:35 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 17:03:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	print_left(char sign, char *buf, int buf_len, t_print_format pf)
{
	int	count;

	count = 0;
	if (sign)
	{
		if (ft_putchar_fd(sign, 1) < 0)
			return (-1);
		count++;
	}
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

static int	print_zero_pad(char sign, char *data, int d_len, t_print_format pf)
{
	int	count;

	count = 0;
	if (sign)
	{
		if (ft_putchar_fd(sign, 1) < 0)
			return (-1);
		count++;
	}
	if (pf.width > count + pf.precision)
	{
		if (ft_putstrchr_fd('0', pf.width - count - pf.precision, 1) < 0)
			return (-1);
		count = pf.width - pf.precision;
	}
	if (ft_putstrchr_fd('0', pf.precision - d_len, 1) < 0)
		return (-1);
	count += pf.precision - d_len;
	if (write(1, data, d_len) < 0)
		return (-1);
	count += d_len;
	return (count);
}

static int	print(char sign, char *data, int d_len, t_print_format pf)
{
	int	count;

	if ((pf.flag & FT_PRINTF_FLAG_ZERO) && !pf.has_period)
		return (print_zero_pad(sign, data, d_len, pf));
	count = 0;
	if (sign)
		count++;
	if (pf.width > count + pf.precision)
	{
		if (ft_putstrchr_fd(' ', pf.width - count - pf.precision, 1) < 0)
			return (-1);
		count = pf.width - pf.precision;
	}
	if (sign)
	{
		if (ft_putchar_fd(sign, 1) < 0)
			return (-1);
	}
	if (ft_putstrchr_fd('0', pf.precision - d_len, 1) < 0)
		return (-1);
	count += pf.precision - d_len;
	if (write(1, data, d_len) < 0)
		return (-1);
	count += d_len;
	return (count);
}

int	print_d(t_print_format pf, va_list args)
{
	char	arg_buf[sizeof(int) * 8 + 1];
	char	*buffer;
	char	sign;
	int		buf_len;

	ft_itoa(va_arg(args, int), arg_buf, 10);
	buffer = arg_buf;
	sign = 0;
	if (pf.flag & FT_PRINTF_FLAG_SPACE)
		sign = ' ';
	if (pf.flag & FT_PRINTF_FLAG_PLUS)
		sign = '+';
	if (*buffer == '-')
		sign = *(buffer++);
	if (*buffer == '0' && pf.precision == 0)
		buffer = "";
	if (*buffer == '0' && pf.has_period && pf.precision == -1)
		buffer = "";
	buf_len = (int)ft_strlen(buffer);
	if (pf.precision == -1 || pf.precision < buf_len)
		pf.precision = buf_len;
	if (pf.flag & FT_PRINTF_FLAG_MINUS)
		return (print_left(sign, buffer, buf_len, pf));
	return (print(sign, buffer, buf_len, pf));
}
