/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:44:23 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 14:55:31 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	result = nb;
	return (result * ft_recursive_power(nb, power - 1));
}

// #include <stdio.h>
// int main() {
// 	printf("%i\n", ft_recursive_power(5, 2));
// 	printf("%i\n", ft_recursive_power(10, 2));
// 	printf("%i\n", ft_recursive_power(-5, 0));
// }