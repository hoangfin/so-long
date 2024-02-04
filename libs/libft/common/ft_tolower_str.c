/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:17:45 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_tolower_str function converts all uppercase alphabet characters in
 * string s to lowercase.
 *
 * @param	{char*}	s	The string for conversion
 * @returns	{void}
*/
void	ft_tolower_str(char *s)
{
	while (*s != '\0')
	{
		if (*s >= 'A' && *s <= 'Z')
			*s += 32;
		s++;
	}
}
