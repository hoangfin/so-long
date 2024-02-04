/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:31:46 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/23 16:33:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_isprint function checks whether c is an ASCII printable character.
 *
 * @param	{int}	c		Integer value to check
 * @returns	{int}	0		means c is not an ASCII printable character.
 * 					1		means c is an ASCII printable character.
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
