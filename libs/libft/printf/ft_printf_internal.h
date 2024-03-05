/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:30:10 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/05 17:05:04 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_INTERNAL_H
# define FT_PRINTF_INTERNAL_H
# define SUP_FLAGS "# +-0"
# define SUP_CONVERSIONS "cspdiuxX%"

# include <stdarg.h>
# include "../common/libft_common.h"

typedef enum e_print_flag
{
	FT_PRINTF_FLAG_HASH = 1 << 0,
	FT_PRINTF_FLAG_SPACE = 1 << 1,
	FT_PRINTF_FLAG_PLUS = 1 << 2,
	FT_PRINTF_FLAG_MINUS = 1 << 3,
	FT_PRINTF_FLAG_ZERO = 1 << 4,
	FT_PRINTF_FLAG_COUNT = 5
}	t_print_flag;

typedef struct s_print_format
{
	t_print_flag	flag;
	int				width;
	char			has_period;
	int				precision;
	char			conversion;
	char			is_malformed;
}	t_print_format;

typedef int	(*t_print_service)(t_print_format, va_list);

t_print_flag	get_printf_flag(char c);
void			parse(const char *format, t_print_format *pf, va_list args);
int				is_flag(char c);
int				is_conversion(char c);
int				print_c(t_print_format pf, va_list args);
int				print_s(t_print_format pf, va_list args);
int				print_p(t_print_format pf, va_list args);
int				print_percent(t_print_format pf, va_list args);
int				print_d(t_print_format pf, va_list args);
int				print_u(t_print_format pf, va_list args);
int				print_x(t_print_format pf, va_list args);
int				ft_printf(const char *format, ...);

#endif
