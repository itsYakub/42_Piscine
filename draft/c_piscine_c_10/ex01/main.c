/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:22:12 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/05 08:22:13 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

#define FTCAT_FBUF_SIZE 30720

int	ft_print_file_content(const char *filepath)
{
	char	fbuf[FTCAT_FBUF_SIZE];
	int		fd;
	int		flen;

	if (!filepath)
		return (0);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (0);
	flen = read(fd, fbuf, FTCAT_FBUF_SIZE);
	write(1, fbuf, flen);
	close(fd);
	return (1);
}

int	main(int argc, const char *argv[])
{
	int			arg;

	if (argc > 1)
	{
		arg = 0;
		while (++arg < argc)
		{
			if (!ft_print_file_content(argv[arg]))
			{
				printf("%s\n", strerror(errno));
				return (1);
			}
		}
	}
	return (0);
}
