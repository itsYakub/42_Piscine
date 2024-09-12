/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:44:22 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 10:52:59 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_recursive_putnbr(unsigned int nbr, char *base, unsigned int radix)
{
	if (nbr / radix > 0)
		ft_recursive_putnbr(nbr / radix, base, radix);
	write(1, &base[nbr % radix], 1);
}

void	ft_putnbr(int nbr, char *base, unsigned int radix)
{
	unsigned int	nbr_abs;

	nbr_abs = nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_abs *= -1;
	}
	ft_recursive_putnbr(nbr_abs, base, radix);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_strcmp(base, "01") == 0)
		ft_putnbr(nbr, base, 2);
	else if (ft_strcmp(base, "poneyvif") == 0)
		ft_putnbr(nbr, base, 8);
	else if (ft_strcmp(base, "0123456789") == 0)
		ft_putnbr(nbr, base, 10);
	else if (ft_strcmp(base, "0123456789ABCDEF") == 0)
		ft_putnbr(nbr, base, 16);
	return ;
}

// #include <stdlib.h>
// #include <stdio.h>
// #include <time.h>

// int main() {
// 	srand(time(0));
// 	int test_cases[] = { 2147483647, -2147483648, 42, -128, 0, rand() % 16 };

// 	for(int i = 0; i < sizeof(test_cases) / sizeof(int); i++) {
// 		printf("Random value: %i\n", test_cases[i]);
// 		sleep(1);

// 		write(1, "> Binary: ", 11);
// 		ft_putnbr_base(test_cases[i], "01");			
// 		write(1, "\n", 1);

// 		write(1, "> Octal: ", 10);
// 		ft_putnbr_base(test_cases[i], "poneyvif");			
// 		write(1, "\n", 1);

// 		write(1, "> Decimal: ", 12);
// 		ft_putnbr_base(test_cases[i], "0123456789");		
// 		write(1, "\n", 1);

// 		write(1, "> Hex: ", 8);
// 		ft_putnbr_base(test_cases[i], "0123456789ABCDEF");	
// 		write(1, "\n", 2);
// 		sleep(1);
// 	}
// }