/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:37:45 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 14:56:37 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

// #include <stdio.h>
// int main() {
// 	printf("%i\n", ft_recursive_factorial(5));
// 	printf("%i\n", ft_recursive_factorial(10));
// 	printf("%i\n", ft_recursive_factorial(-5));
// }