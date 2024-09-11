/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:40:26 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 14:54:08 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;
	int	i;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	i = 1;
	result = nb;
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

// #include <stdio.h>
// int main() {
// 	printf("%i\n", ft_iterative_power(5, 2));
// 	printf("%i\n", ft_iterative_power(10, 2));
// 	printf("%i\n", ft_iterative_power(-5, 0));
// }