/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:44:22 by joleksia          #+#    #+#             */
/*   Updated: 2024/08/29 15:00:03 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BASE_TWO "01"
#define BASE_OCTAL "poneyvif"
#define BASE_DECIMAL "0123456789"
#define BASE_HEXADECIMAL "0123456789ABCDEF"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (result == 0)
	{
		if (s1[i] > s2[i])
			result = s1[i] - s2[i];
		else if (s2[i] > s1[i])
			result = s1[i] - s2[i];
		else if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (result);
}

int	ft_get_digit_count(int nbr, unsigned int radix)
{
	int	result;

	result = 0;
	while (nbr != 0)
	{
		result++;
		nbr /= radix;
	}
	return (result);
}

int	ft_get_base_index(int nbr, int n, int divider)
{
	while (n-- > 0)
		nbr /= divider;
	return (nbr % divider);
}

void	ft_putnbr(int nbr, char *base, unsigned int radix)
{
	int	digit_count;
	int	i;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	digit_count = ft_get_digit_count(nbr, radix);
	i = -1;
	while (++i < digit_count)
		write(1, &base[ft_get_base_index(nbr, digit_count - 1 - i, radix)], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_strcmp(base, BASE_TWO) == 0)
		ft_putnbr(nbr, base, 2);
	else if (ft_strcmp(base, BASE_OCTAL) == 0)
		ft_putnbr(nbr, base, 8);
	else if (ft_strcmp(base, BASE_DECIMAL) == 0)
		ft_putnbr(nbr, base, 10);
	else if (ft_strcmp(base, BASE_HEXADECIMAL) == 0)
		ft_putnbr(nbr, base, 16);
	return ;
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <time.h>
// 
// int main() {
// 	srand(time(0));
// 
// 	for(int i = 0; i < 5; i++) {
// 		int random = rand() % 65536 * (rand() % 2 ? -1 : 1);
// 
// 		printf("Random value: %i\n", random);
// 
// 		ft_putnbr_base(random, BASE_TWO);			
// 		write(1, "\n", 1);
// 		ft_putnbr_base(random, BASE_OCTAL);			
// 		write(1, "\n", 1);
// 		ft_putnbr_base(random, BASE_DECIMAL);		
// 		write(1, "\n", 1);
// 		ft_putnbr_base(random, BASE_HEXADECIMAL);	
// 		write(1, "\n\n", 2);
// 	}
// }