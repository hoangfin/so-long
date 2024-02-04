/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:18:59 by hoatran           #+#    #+#             */
/*   Updated: 2023/10/23 16:29:19 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_tolower function returns lowercase equivalent of integer c
 * if c is an uppercase letter.
 *
 * @param	{int}	c	Integer value to check
 * @returns	{int}
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
