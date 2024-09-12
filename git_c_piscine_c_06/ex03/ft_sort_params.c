/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:54:40 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 14:42:57 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort(char **argv, int size)
{
	char	*temp;
	int		i;
	int		j;

	i = 1;
	temp = 0;
	while (i < size)
	{
		j = 1;
		while (j < size - i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				temp = argv[j];
				argv[j] = argv[j + 1];
				argv[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		arg;

	if (argc > 1)
	{
		ft_sort(argv, argc);
		arg = 1;
		while (arg < argc)
		{
			while (*argv[arg] != '\0')
			{
				write(1, argv[arg], 1);
				(argv[arg])++;
			}
			write(1, "\n", 1);
			arg++;
		}
	}
}
