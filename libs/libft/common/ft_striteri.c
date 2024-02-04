/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:16:53 by hoatran           #+#    #+#             */
/*   Updated: 2023/11/01 15:22:46 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The ft_striteri() function applies the function 'f' on each character of the
 * string passed as argument, passing its index as first argument. Each
 * character is passed by address to 'f' to be modified if necessary.
 *
 * @param {char*}		s	The string on which to iterate.
 * @param {function}	f	The function to apply to each character.
 *
 * @return {void}
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
