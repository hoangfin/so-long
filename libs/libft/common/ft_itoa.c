/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:35 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

static void	convert(int n, char *buffer, int radix)
{
	const char	*hex_values = "0123456789abcdef";
	int			i;
	char		is_negative;

	i = 0;
	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	while (n != 0)
	{
		if (radix == 16)
			buffer[i++] = hex_values[n % radix];
		else
			buffer[i++] = n % radix + '0';
		n /= radix;
	}
	if (is_negative)
		buffer[i++] = '-';
	buffer[i] = '\0';
}

static void	reverse(char *buffer)
{
	size_t	i;
	size_t	mid;
	size_t	length;
	char	temp;

	i = 0;
	length = ft_strlen(buffer);
	mid = i + (length - 1 - i) / 2;
	if (length < 2)
		return ;
	while (i <= mid)
	{
		temp = buffer[i];
		buffer[i] = buffer[length - 1 - i];
		buffer[length - 1 - i] = temp;
		i++;
	}
}

/**
 * The ft_itoa() function returns a string representing the integer
 * received as an argument. Negative numbers must be handled.
 *
 * @param	{int}	n		The integer to convert.
 *
 * @returns	{char*}			The string representing the integer.
 * 							NULL is returned if the allocation fails.
*/
char	*ft_itoa(int n, char *buffer, int radix)
{
	if (radix != 8 && radix != 10 && radix != 16)
		return (NULL);
	if (n == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
	if (n == -2147483648)
	{
		ft_strlcpy(buffer, "-2147483648", 12);
		return (buffer);
	}
	convert(n, buffer, radix);
	reverse(buffer);
	return (buffer);
}
