/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:37:34 by hoatran           #+#    #+#             */
/*   Updated: 2024/02/21 12:20:14 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

# include "../common/libft_common.h"

typedef struct s_string
{
	char	*content;
	size_t	length;
}	t_string;

typedef struct s_grid
{
	char	**matrix;
	size_t	row_count;
	size_t	col_count;
}	t_grid;

t_string	*ft_string(char *str);
t_bool		ft_ends_with(const char *string, const char *search_string);
char		*ft_strdup_chr(char *source, char delimiter);
char		**ft_matrix(size_t row_count, size_t col_count, int c);
size_t		ft_matrix_count_rows(char **matrix);
void		ft_matrix_delete(char ***matrix);
void		ft_matrix_print(char **matrix);

#endif
