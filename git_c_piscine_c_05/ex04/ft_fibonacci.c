/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:47:27 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 14:54:42 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// #include <stdio.h>
// int main() {
// 	printf("%i\n", ft_fibonacci(2));
// 	printf("%i\n", ft_fibonacci(5));
// 	printf("%i\n", ft_fibonacci(-1));
// 	printf("%i\n", ft_fibonacci(3));
// 	printf("%i\n", ft_fibonacci(6));
// 	printf("%i\n", ft_fibonacci(9));
// }