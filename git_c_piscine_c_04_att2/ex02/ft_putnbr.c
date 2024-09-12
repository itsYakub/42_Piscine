/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:16:53 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 10:51:31 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_number_length(int nb)
{
	int	result;

	result = 0;
	while (nb != 0)
	{
		result++;
		nb /= 10;
	}
	return (result);
}

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

void	ft_putnbr(int nb)
{
	char	result[10];

	if (nb == 0)
		write(1, "0", 1);
	else
	{
		if (nb < 0)
		{
			if (nb == -2147483648)
			{
				write(1, "-2147483648", 11);
				return ;
			}
			write(1, "-", 1);
			nb *= -1;
		}
		result[ft_number_length(nb)] = '\0';
		while (ft_number_length(nb))
		{
			result[ft_number_length(nb) - 1] = nb % 10 + '0';
			nb /= 10;
		}
		write(1, result, ft_strlen(result));
	}
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <time.h>

// int main() {
// 	srand(time(0));
// 	int test_cases[] = { 
//		rand() % 2147483647 * (rand() % 2 ? -1 : 1), 
//		rand() % 2147483647 * (rand() % 2 ? -1 : 1), 
//		rand() % 2147483647 * (rand() % 2 ? -1 : 1), 
//		2147483647, 
//		-2147483648, 
//		42, 
//		-42, 
//		128, 
//		-128, 
//		0, 1, 2, 3 
//	};

// 	for(int i = 0; i < sizeof(test_cases) / sizeof(int); i++) {
// 		printf("Original: %i\n", test_cases[i]);
// 		ft_putnbr(test_cases[i]);
// 		write(1, "\n", 1);
// 		sleep(1);
// 	}
// }