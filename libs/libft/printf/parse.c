/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:15:42 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 17:03:02 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_internal.h"

static void	parse_flag(const char **format, t_print_format *pf)
{
	while (is_flag(**format))
	{
		pf->flag = pf->flag | get_printf_flag(**format);
		(*format)++;
	}
	if (
		!ft_isdigit(**format)
		&& **format != '*'
		&& **format != '.'
		&& !is_conversion(**format)
	)
		pf->is_malformed = 1;
}

static void	parse_width(const char **format, t_print_format *pf, va_list args)
{
	if (**format == '*')
	{
		pf->width = va_arg(args, int);
		(*format)++;
		return ;
	}
	while (ft_isdigit(**format))
	{
		pf->width = pf->width * 10 + **format - '0';
		(*format)++;
	}
	if (**format != '.' && !is_conversion(**format))
		pf->is_malformed = 1;
}

static void	parse_prec(const char **format, t_print_format *pf, va_list args)
{
	if (**format != '.')
		return ;
	(*format)++;
	pf->has_period = 1;
	if (**format == '*')
	{
		pf->precision = va_arg(args, int);
		(*format)++;
		if (!is_conversion(**format))
			pf->is_malformed = 1;
		return ;
	}
	if (!ft_isdigit(**format) && !is_conversion(**format))
	{
		pf->is_malformed = 1;
		return ;
	}
	while (ft_isdigit(**format))
	{
		if (pf->precision == -1)
			pf->precision = 0;
		pf->precision = pf->precision * 10 + *((*format)++) - '0';
	}
	if (!is_conversion(**format))
		pf->is_malformed = 1;
}

void	parse(const char *format, t_print_format *pf, va_list args)
{
	pf->flag = 0;
	pf->width = 0;
	pf->has_period = 0;
	pf->precision = -1;
	pf->is_malformed = 0;
	parse_flag(&format, pf);
	if (pf->is_malformed)
		return ;
	parse_width(&format, pf, args);
	if (pf->is_malformed)
		return ;
	parse_prec(&format, pf, args);
	if (pf->is_malformed)
		return ;
}
