/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:09:26 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 17:03:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	print_left(char *prefix, char *buf, int buf_len, t_print_format pf)
{
	int	count;

	count = 0;
	if (pf.flag & FT_PRINTF_FLAG_HASH && *buf != '0' && *buf != '\0')
	{
		if (write(1, prefix, 2) < 0)
			return (-1);
		count += 2;
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

static int	print_zero_pad(char *pre, char *buf, int buf_len, t_print_format pf)
{
	int	count;

	count = 0;
	if (pf.flag & FT_PRINTF_FLAG_HASH && *buf != '0')
	{
		if (write(1, pre, 2) < 0)
			return (-1);
		count = 2;
	}
	if (pf.width > count + pf.precision)
	{
		if (ft_putstrchr_fd('0', pf.width - count - pf.precision, 1) < 0)
			return (-1);
		count = pf.width - pf.precision;
	}
	if (ft_putstrchr_fd('0', pf.precision - buf_len, 1) < 0)
		return (-1);
	count += pf.precision - buf_len;
	if (write(1, buf, buf_len) < 0)
		return (-1);
	count += buf_len;
	return (count);
}

static int	print(char *prefix, char *buf, int buf_len, t_print_format pf)
{
	int	count;

	count = 0;
	if (pf.flag & FT_PRINTF_FLAG_HASH && *buf != '0' && *buf != '\0')
		count = 2;
	if (pf.width > count + pf.precision)
	{
		if (ft_putstrchr_fd(' ', pf.width - count - pf.precision, 1) < 0)
			return (-1);
		count = pf.width - pf.precision;
	}
	if (pf.flag & FT_PRINTF_FLAG_HASH && *buf != '0' && *buf != '\0')
	{
		if (write(1, prefix, 2) < 0)
			return (-1);
	}
	if (ft_putstrchr_fd('0', pf.precision - buf_len, 1) < 0)
		return (-1);
	count += pf.precision - buf_len;
	if (write(1, buf, buf_len) < 0)
		return (-1);
	count += buf_len;
	return (count);
}

int	print_x(t_print_format pf, va_list args)
{
	char		arg_buf[sizeof(int) * 8 + 1];
	char		*buffer;
	char		*hex_prefix;
	int			buf_len;

	ft_utoa(va_arg(args, unsigned int), arg_buf, 16);
	buffer = arg_buf;
	hex_prefix = "0x";
	if (pf.conversion == 'X')
	{
		ft_toupper_str(buffer);
		hex_prefix = "0X";
	}
	if (*buffer == '0' && pf.precision == 0)
		buffer = "";
	if (*buffer == '0' && pf.has_period && pf.precision == -1)
		buffer = "";
	buf_len = (int)ft_strlen(buffer);
	if (pf.precision == -1 || pf.precision < buf_len)
		pf.precision = buf_len;
	if (pf.flag & FT_PRINTF_FLAG_MINUS)
		return (print_left(hex_prefix, buffer, buf_len, pf));
	if (pf.flag & FT_PRINTF_FLAG_ZERO && !pf.has_period)
		return (print_zero_pad(hex_prefix, buffer, buf_len, pf));
	return (print(hex_prefix, buffer, buf_len, pf));
}
