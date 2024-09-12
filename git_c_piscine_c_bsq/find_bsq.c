/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:33:14 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/10 15:43:19 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static t_bsq_data	ft_check_bsq(t_map *map, int x, int y);
static int			ft_rect_iterate(t_map *map, int x, int y, int len);
static int			ft_compare_bsq(t_bsq_data *largest_square,
						t_bsq_data *current_square);

t_bsq_data	ft_find_bsq(t_map *map)
{
	t_bsq_data	result;
	t_bsq_data	current_bsq_data;
	int			y;
	int			x;

	result = (t_bsq_data){0};
	current_bsq_data = (t_bsq_data){0};
	y = -1;
	while (++y < (int)map->h)
	{
		x = -1;
		while (++x < (int)map->w)
		{
			if (map->data[y][x] != map->char_empty)
				continue ;
			current_bsq_data = ft_check_bsq(map, x, y);
			ft_compare_bsq(&result, &current_bsq_data);
		}
	}
	return (result);
}

static t_bsq_data	ft_check_bsq(t_map *map, int x, int y)
{
	t_bsq_data	result;

	result.x = x;
	result.y = y;
	result.size = 1;
	while (x + result.size < (int)map->w && y + result.size < (int)map->h)
	{
		if (ft_rect_iterate(map, x, y, result.size))
			break ;
		result.size++;
	}
	return (result);
}

static int	ft_rect_iterate(t_map *map, int x, int y, int len)
{
	int	rect_sides;
	int	index;
	int	dir_x;
	int	dir_y;

	dir_x = 1;
	dir_y = 0;
	rect_sides = -1;
	while (++rect_sides < 4)
	{
		index = -1;
		while (++index < len)
		{
			if (map->data[y][x] == map->char_obst)
				return (1);
			x += dir_x;
			y += dir_y;
		}
		ft_swap(&dir_x, &dir_y);
	}
	return (0);
}

static int	ft_compare_bsq(t_bsq_data *largest_square,
		t_bsq_data *current_square)
{
	int	largest_square_s;
	int	current_square_s;

	if (!largest_square || !current_square)
		return (0);
	largest_square_s = largest_square->size;
	current_square_s = current_square->size;
	if (largest_square_s > current_square_s)
		return (1);
	else if (largest_square_s == current_square_s)
		return (1);
	else
	{
		largest_square->x = current_square->x;
		largest_square->y = current_square->y;
		largest_square->size = current_square->size;
	}
	return (1);
}
