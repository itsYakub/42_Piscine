/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:34:04 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 14:54:28 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (result);
	while (nb)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

// #include <stdio.h>
// int main() {
// 	printf("%i\n", ft_iterative_factorial(5));
// 	printf("%i\n", ft_iterative_factorial(10));
// 	printf("%i\n", ft_iterative_factorial(1));
// 	printf("%i\n", ft_iterative_factorial(0));
// 	printf("%i\n", ft_iterative_factorial(-5));
// }