/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:08:53 by agarbacz          #+#    #+#             */
/*   Updated: 2024/09/11 13:51:04 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>

int	ft_file_parse(int fd, char *fpath, char **str, int argc)
{
	int	flen;

	(void) argc;
	if (fd <= 0)
	{
		*str = ft_scanff();
		return (1);
	}
	flen = ft_flen(fpath);
	*str = (char *)malloc(flen * sizeof(char));
	if (!(*str))
		return (0);
	if (read(fd, *str, flen) == 1)
		return (0);
	close(fd);
	(*str)[flen] = '\0';
	return (1);
}

// potential TODO: what if empty is a num?
int	move_ptr(char *str, t_map *map)
{
	int	nlen;
	int	i;

	nlen = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		i++;
		nlen++;
	}
	map->h = ft_atoi(str);
	map->char_empty = str[i++];
	map->char_obst = str[i++];
	map->char_fill = str[i++];
	i++;
	return (i);
}

int	ft_first_line(t_map *map, char *str)
{
	int		res;
	int		i;
	char	*ncol;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	res = i + 1;
	map->char_fill = str[--i];
	map->char_obst = str[--i];
	map->char_empty = str[--i];
	ncol = (char *)malloc(i + 1);
	ncol[i + 1] = '\0';
	while (i--)
		ncol[i] = str[i];
	map->h = ft_atoi(ncol);
	free(ncol);
	return (res);
}

int	ft_flen(char *filepath)
{
	int 	res;
	int		fd;
	char	c;

	res = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (0);
	while (read(fd, &c, 1) > 0)
		res++;
	close(fd);
	return (res + 1);
}
