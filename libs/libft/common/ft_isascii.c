/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:37:10 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/23 16:44:09 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_isascii function checks whether c is a 7-bit unsigned char value that
 * fits into the ASCII character set.
 *
 * @param	{int}	c		Integer value to check
 * @returns	{int}	0		means c is not a 7-bit ASCII character.
 * 					1		means c is a 7-bit ASCII character.
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
