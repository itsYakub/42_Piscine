/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleksia <joleksia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 13:54:44 by joleksia          #+#    #+#             */
/*   Updated: 2024/09/03 14:56:15 by joleksia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	n;

	if (nb <= 0)
		return (0);
	n = 1;
	while (n * n <= nb)
	{
		if (n * n == nb)
			return (n);
		n++;
	}
	return (0);
}

#include <stdio.h>
int main() {
	for(int i = -1; i <= 16; i++) {
		printf("%i\n", ft_sqrt(i));
	}
}
