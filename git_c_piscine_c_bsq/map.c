/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:21:27 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/11 12:50:38 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_create_map(t_map *map, char *file_str)
{
	int	i;
	int	j;
	int	k;

	map->data = (char **)malloc(map->h * sizeof(char *));
	map->w = ft_strlen(file_str) / map->h;
	j = -1;
	i = 0;
	while (++j < (int)map->h)
	{
		map->data[j] = (char *)malloc((map->w) * sizeof(char));
		k = -1;
		while (++k < (int)map->w)
			map->data[j][k] = file_str[i++];
	}
	return (1);
}

int	ft_print_map(t_map *map)
{
	int	i;
	int	j;

	if (!map)
		return (0);
	i = 0;
	while (i < (int)map->h)
	{
		j = 0;
		while (j < (int)map->w)
		{
			write(1, &map->data[i][j], 1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_unload_map(t_map *map)
{
	if (!map)
		return (0);
	free(map->data);
	return (1);
}

int	ft_map_fill(t_map *map, t_bsq_data *bsq_data)
{
	int	y;
	int	x;

	if (!map || !bsq_data)
		return (0);
	y = bsq_data->y;
	while (y < bsq_data->y + bsq_data->size)
	{
		x = bsq_data->x;
		while (x < bsq_data->x + bsq_data->size)
		{
			map->data[y][x] = map->char_fill;
			x++;
		}
		y++;
	}
	return (1);
}
