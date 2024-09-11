/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:12:43 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/04 16:12:46 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_strlen(char *str)
{
	int	result;

	result = 0;
	while (str[result])
	{
		result++;
	}
	return (result);
}

int	main(int argc, const char *argv[])
{
	char	buffer[65536];
	int		file_descriptor;

	if (argc > 1)
	{
		if (argc != 2)
		{
			write(2, "Too many arguments.\n", 20);
			return (1);
		}
		file_descriptor = open(argv[1], O_RDONLY);
		if (file_descriptor < 1)
		{
			write(2, "Cannot read file.\n", 18);
			return (1);
		}
		read(file_descriptor, buffer, 65536);
		write(1, buffer, ft_strlen(buffer));
		close(file_descriptor);
		return (0);
	}
	write(2, "File name missing.\n", 19);
	return (1);
}
