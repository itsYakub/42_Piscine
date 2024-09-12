/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarbacz <agarbacz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 09:51:19 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/11 14:41:34 by agarbacz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>

static void	map_execute(t_map *map)
{
	t_bsq_data	bsq_data;

	bsq_data = ft_find_bsq(map);
	ft_map_fill(map, &bsq_data);
	ft_print_map(map);
	ft_unload_map(map);
}

static void	map_process(int fd, t_map *map, int argc, char *fpath)
{
	char	*file_str;
	char	*file_str_mod;

	if (!ft_file_parse(fd, fpath, &file_str, argc))
	{
		free(file_str);
		ft_logerr("map error\n");
		return ;
	}
	file_str_mod = file_str;
	file_str_mod += ft_first_line(map, file_str_mod);
	if (!ft_create_map(map, file_str_mod) || !validate_mape(file_str, map))
	{
		free(file_str);
		ft_logerr("map error\n");
		return ;
	}
	map_execute(map);
	free(file_str);
}

int	main(int argc, const char *argv[])
{
	t_map	map;
	int		arg;

	arg = 0;
	if (argc < 2)
	{
		map_process(STDIN_FILENO, &map, argc, NULL);
	}
	while (++arg < argc)
	{
		map_process(open(argv[arg], O_RDONLY),&map, argc, (char *) argv[arg]);
	}
	return (0);
}
