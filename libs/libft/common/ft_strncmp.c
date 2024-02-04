/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:30:57 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

/**
 * The ft_strncmp() function compares the NULL-terminated strings s1 and s2.
 * It will compare not more than n characters, characters that appear after a
 * `\0' character are not compared.
 *
 * @param	{char*}		s1	The string pointed to by s1.
 * @param	{char*}		s2	The string pointed to by s2.
 * @param	{size_t}	n	The number of comparing characters.
 *
 * @returns	{int}			An integer greater than, equal to, or less than
 * 							0, according as the string s1 is greater than,
 * 							equal to, or less than the string s2.
 * 							The comparison is done using unsigned characters,
 * 							so that `\200' is greater than `\0'.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	diff = 0;
	while (i < n)
	{
		diff = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		if (diff != 0 || s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (diff);
}
