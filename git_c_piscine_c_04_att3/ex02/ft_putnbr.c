/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:16:53 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 11:13:29 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_recursive_putnbr(unsigned int nb)
{
	char	c;

	if (nb / 10 > 0)
		ft_recursive_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	nb_abs;

	nb_abs = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb_abs *= -1;
	}
	ft_recursive_putnbr(nb_abs);
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <time.h>

// int main() {
// 	srand(time(0));
// 	int test_cases[] = { 
// 		rand() % 2147483647 * (rand() % 2 ? -1 : 1), 
// 		2147483647, 
// 		-2147483648, 
// 		42, 
// 		-42, 
// 		128, 
// 		-128, 
// 		0, 1, 2, 3 
// 	};

// 	for(int i = 0; i < sizeof(test_cases) / sizeof(int); i++) {
// 		printf("Original: %i\n", test_cases[i]);
// 		ft_putnbr(test_cases[i]);
// 		write(1, "\n", 1);
// 		sleep(1);
// 	}
// }
