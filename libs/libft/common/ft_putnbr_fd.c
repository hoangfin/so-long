/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:15:04 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_putnbr_fd function outputs the integer n to the file descriptor fd.
 *
 * @param	{int}	n	The integer to output.
 * @param	{int}	fd	The file descriptor.
 *
 * @returns	{int}		The number of bytes written
*/
int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	long	positive_num;

	count = 0;
	positive_num = n;
	if (n < 0)
	{
		positive_num = -positive_num;
		count += ft_putchar_fd('-', fd);
	}
	if (positive_num / 10 == 0)
	{
		count += ft_putchar_fd(positive_num % 10 + '0', fd);
		return (count);
	}
	count += ft_putnbr_fd(positive_num / 10, fd);
	count += ft_putchar_fd(positive_num % 10 + '0', fd);
	return (count);
}
