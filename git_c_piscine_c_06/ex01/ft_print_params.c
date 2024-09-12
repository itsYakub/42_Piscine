/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:45:28 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 11:51:41 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, const char *argv[])
{
	int	arg;

	if (argc > 1)
	{
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
