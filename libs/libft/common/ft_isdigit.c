/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:24:03 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/23 16:27:50 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_isdigit function checks whether the integer c is a digit character.
 *
 * @param	{int}	c		Integer value to check for being a digit.
 * @returns	{int}	0		means it's not a digit character.
 * 					1		means it's a digit character.
*/
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
