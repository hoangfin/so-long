/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:22:27 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_bzero() function erases the data in the n bytes of the memory
 * starting at the location pointed to by s, by writing zeros (bytes
 * containing '\0') to that area.
 *
 * @param	{void *}	s	The memory area pointed to by s.
 * @param	{size_t}	n	The number of bytes starting at
 * 							the location pointed to by s.
 *
 * @returns	{void}
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
