/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:40:20 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 17:03:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static int	print_null(t_print_format pf)
{
	const char	*null_str = "0x0";
	int			count;

	if (pf.flag & FT_PRINTF_FLAG_MINUS)
	{
		if (write(1, null_str, 3) < 0)
			return (-1);
		count = 3;
		if (pf.width < count)
			return (count);
		if (ft_putstrchr_fd(' ', pf.width - count, 1) < 0)
			return (-1);
		return (pf.width);
	}
	count = 3;
	if (pf.width > count)
	{
		if (ft_putstrchr_fd(' ', pf.width - count, 1) < 0)
			return (-1);
		count = pf.width;
	}
	if (write(1, null_str, 3) < 0)
		return (-1);
	return (count);
}

static int	print_left(const char *buf, int buf_len, t_print_format pf)
{
	const char	*prefix = "0x";
	int			count;

	if (write(1, prefix, 2) < 0)
		return (-1);
	count = 2;
	if (write(1, buf, buf_len) < 0)
		return (-1);
	count += buf_len;
	if (pf.width < count)
		return (count);
	if (ft_putstrchr_fd(' ', pf.width - count, 1) < 0)
		return (-1);
	return (pf.width);
}

static int	print(const char *buf, int buf_len, t_print_format pf)
{
	const char	*prefix = "0x";
	int			count;

	count = 2;
	if (pf.width > count + buf_len)
	{
		if (ft_putstrchr_fd(' ', pf.width - count - buf_len, 1) < 0)
			return (-1);
		count = pf.width - buf_len;
	}
	if (write(1, prefix, 2) < 0)
		return (-1);
	if (write(1, buf, buf_len) < 0)
		return (-1);
	count += buf_len;
	return (count);
}

int	print_p(t_print_format pf, va_list args)
{
	char		buffer[sizeof(long) * 8 + 1];
	void		*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (print_null(pf));
	ft_ultoa((unsigned long)ptr, buffer, 16);
	if (pf.flag & FT_PRINTF_FLAG_MINUS)
		return (print_left(buffer, (int)ft_strlen(buffer), pf));
	return (print(buffer, (int)ft_strlen(buffer), pf));
}
