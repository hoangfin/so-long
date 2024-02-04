/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:54:27 by hoatran           #+#    #+#             */
/*   Updated: 2024/01/19 00:37:57 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_common.h"

static size_t	count_tokens(char const *s, char c)
{
	size_t		count;
	char const	*prev;

	if (c == '\0')
		return (1);
	count = 0;
	prev = NULL;
	while (*s != '\0')
	{
		if (*s != c)
		{
			if (prev == NULL || *prev == c)
				count++;
		}
		prev = s;
		s++;
	}
	return (count);
}

static char	*get_next_token(char const **s, char c, int *error)
{
	size_t		token_size;
	char const	*temp;
	char		*token;

	*error = 0;
	token_size = 0;
	while (**s == c && **s != '\0')
		*s = *s + 1;
	temp = *s;
	while (*temp != c && *temp != '\0')
	{
		temp++;
		token_size++;
	}
	if (token_size == 0)
		return (NULL);
	token = (char *)malloc((token_size + 1) * sizeof(char));
	if (token == NULL)
	{
		*error = 1;
		return (NULL);
	}
	ft_strlcpy(token, *s, token_size + 1);
	*s = temp;
	return (token);
}

static int	init(char **tokens, char const *s, char c, size_t tokens_length)
{
	size_t	i;
	int		error;

	i = 0;
	while (i < tokens_length)
	{
		tokens[i] = get_next_token(&s, c, &error);
		if (tokens[i] == NULL && error)
		{
			while (i != 0)
			{
				if (tokens[i] != NULL)
					free(tokens[i]);
				i--;
			}
			if (tokens[i] != NULL)
				free(tokens[i]);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**tokens;

	if (s == NULL)
		return (NULL);
	count = count_tokens(s, c);
	tokens = (char **)malloc((count + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	if (!init(tokens, s, c, count + 1))
	{
		free(tokens);
		tokens = NULL;
	}
	return (tokens);
}
