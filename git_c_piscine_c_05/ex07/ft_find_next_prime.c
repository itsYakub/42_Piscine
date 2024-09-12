/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:04:56 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 14:09:57 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 0 || nb == 1)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	next_prime;

	next_prime = nb;
	while (!ft_is_prime(next_prime))
		next_prime++;
	return (next_prime);
}

// #include <stdio.h>

// int main() {
// 	int test_cases[] = {
// 		rand() % 2147483647,
// 		rand() % 2147483647,
// 		42,
// 		43,
// 		128,
// 		2137,
// 		2,
// 		1,
// 	};

// 	for(int i = 0; i < sizeof(test_cases) / sizeof(int); i++) {
// 		printf(
// 			"> Current number: %i | Next prime: %i\n", 
// 			test_cases[i], 
// 			ft_find_next_prime(test_cases[i])
// 		);
// 	}
// }