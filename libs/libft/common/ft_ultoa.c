/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:01:00 by hoatran           #+#    #+#             */
/*   Updated: 2024/03/14 12:03:37 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

static void	convert(unsigned long n, char *buffer, int radix)
{
	const char	*hex_values = "0123456789abcdef";
	int			i;

	i = 0;
	while (n != 0)
	{
		if (radix == 16)
			buffer[i++] = hex_values[n % radix];
		else
			buffer[i++] = n % radix + '0';
		n /= radix;
	}
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

char	*ft_ultoa(unsigned long number, char *buffer, int radix)
{
	if (radix != 8 && radix != 10 && radix != 16)
		return (NULL);
	if (number == 0)
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		return (buffer);
	}
	convert(number, buffer, radix);
	reverse(buffer);
	return (buffer);
}
