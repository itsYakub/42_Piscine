/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:56:01 by agarbacz          #+#    #+#             */
/*   Updated: 2024/09/11 12:49:43 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

// REQUIRED TESTING FOR ALL

// counting and comparing columns to the provided value
int	count_cols(char *file_str, t_map *map)
{
	int	i;
	int	no_cols;

	no_cols = 0;
	i = ft_first_line(map, file_str);
	while (file_str[i] != '\0')
	{
		if (file_str[i] == '\n')
			no_cols++;
		i++;
	}
	if (no_cols != (int)map->h)
		return (0);
	return (no_cols);
}

int	comp_line_lens(char *file_str, int n_col, t_map *map)
{
	int	len;
	int	current_col;
	int	next_len;
	int	i;

	i = 0;
	i += ft_first_line(map, file_str);
	current_col = 1;
	while (current_col < n_col)
	{
		len = get_line_len(file_str, i);
		i += len + 1;
		next_len = get_line_len(file_str, i);
		if (len != next_len)
			return (0);
		current_col++;
	}
	return (1);
}

// checking for any different chars than provided
int	check_placed_chars(char *file_str, int i, t_map *map)
{
	int	current_col;

	current_col = 1;
	while (current_col <= (int)map->h)
	{
		if (file_str[i] != map->char_empty && file_str[i] != map->char_fill
			&& file_str[i] != map->char_obst)
		{
			if (file_str[i] != '\n')
				return (0);
			current_col++;
		}
		i++;
	}
	return (1);
}

// checking if map is, at least 2 lines long
int	box_check(char *file_str, t_map *map)
{
	int	cols;
	int	line_len;
	int	i;

	i = 0;
	i += ft_first_line(map, file_str);
	line_len = get_line_len(file_str, i);
	cols = count_cols(file_str, map);
	if (cols < 1 || line_len < 1)
		return (0);
	return (1);
}

int	validate_mape(char *file_str, t_map *map)
{
	int	cols;
	int	i;

	i = 0;
	i += ft_first_line(map, file_str);
	cols = count_cols(file_str, map);
	if (!cols)
		return (0);
	if (!comp_line_lens(file_str, cols, map))
		return (0);
	if (!check_placed_chars(file_str, i, map))
		return (0);
	if (!box_check(file_str, map))
		return (0);
	return (1);
}
