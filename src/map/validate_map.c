/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoatran <hoatran@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:07:16 by hoatran           #+#    #+#             */
/*   Updated: 2024/04/18 19:17:03 by hoatran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	validate_map(char **map)
{
	size_t	row_count;
	size_t	col_count;

	row_count = ft_matrix_count_rows(map);
	col_count = ft_strlen(map[0]);
	if (is_rectangular(map) == false)
		return (false);
	if (has_valid_chars(map) == false)
		return (false);
	if (is_enclosed(map, row_count, col_count) == false)
		return (false);
	if (has_valid_pec(map, 0, 0, 0) == false)
		return (false);
	if (has_valid_path(map, row_count, col_count) == false)
		return (false);
	return (true);
}
