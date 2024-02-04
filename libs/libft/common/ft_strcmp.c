/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:12:06 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/17 11:27:59 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*str1 = (unsigned char *)s1;
	const unsigned char	*str2 = (unsigned char *)s2;
	int					diff;

	diff = *str1 - *str2;
	while (*str1 != '\0' && *str2 != '\0')
	{
		diff = *str1 - *str2;
		if (diff != 0)
			break ;
		str1++;
		str2++;
	}
	return (diff);
}
