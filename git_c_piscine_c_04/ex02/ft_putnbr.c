/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:16:53 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/30 09:09:29 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define INT_MIN -2147483648
#define INT_MAX 2147483647

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

int	ft_pow(int a, unsigned int b)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (++i < (int) b && b != 0)
		result *= a;
	return (result);
}

int	ft_get_base_index(int nbr, int n)
{
	while (n-- > 0)
		nbr /= 10;
	return (nbr % 10);
}

void	ft_putnbr(int nb)
{
	const char	base_case[] = "0123456789";
	int			digit_count;
	int			i;

	if (nb <= INT_MIN || nb >= INT_MAX)
	{
		if (nb <= INT_MIN)
			write(1, "-2147483648", 12);
		else if (nb >= INT_MAX)
			write(1, "2147483647", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	digit_count = ft_number_length(nb);
	i = -1;
	while (++i < digit_count)
		write(1, &base_case[ft_get_base_index(nb, digit_count - 1 - i)], 1);
}

// #include <stdlib.h>
// 
// int main() {
// 	for(int i = 0; i < 5; i++) {
// 		int random = rand() % 65536 * (rand() % 2 ? -1 : 1);
// 		
// 		ft_putnbr(random);
// 		write(1, "\n", 1);
// 	}
// 	
// 	ft_putnbr(2147483647);
// 	write(1, "\n", 1);
// 
// 	ft_putnbr(-2147483648);
// 	write(1, "\n", 1);
// }