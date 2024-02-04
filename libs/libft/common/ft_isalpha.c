/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:34:38 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/23 16:36:06 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_isalpha function checks whether the integer c is an alphabet character
 * in the standard "C" locale.
 *
 * @param	{int}	c		Integer value to check for alphabet
 * @returns	{int}	0		means c is not an alphabet character.
 * 					1		means c is an alphabet character.
*/
int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
