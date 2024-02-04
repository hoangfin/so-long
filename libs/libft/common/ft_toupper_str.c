/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:28:21 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_toupper_str() function converts all lowercase alphabet characters in
 * string s to uppercase.
 *
 * @param	{char*}	s	The string for conversion
 * @returns	{void}
*/
void	ft_toupper_str(char *s)
{
	while (*s != '\0')
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
}
